#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

// declare everything
typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;
BYTE buffer[BLOCK_SIZE];

int main(int argc, char *argv[])
{
    // stop program if move than 1 command line argument
    if (argc != 2)
    {
        printf("./recover input.raw\n");
        return 1;
    }

    // open the memory card and stop the program if there is a problem
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("1: File cannot be opened");
        return 1;
    }

    int i = 0;
    char *filename = malloc(8 * sizeof(int));
    sprintf(filename, "%03i.jpg", i);
    FILE *img = fopen(filename, "w");
    if (!img)
    {
        printf("2: not enough memory to open a new JPEG");
        return 2;
    }

    // loop through each block of memory on the card
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE) // loop until all blocks in the file are read
    {
        // if block is a JPEG, start writing it to a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // do this for the first JPEG
            if (i == 0)
            {
                // start writing to the first file
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                i++;
            }
            else // this is where I close the first img file and open the next
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                if (!img)
                {
                    printf("2: not enough memory to open a new JPEG");
                    return 2;
                }
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                i++;
            }
        }

        //if block is not the start of a new JPEG, either move on to next block (if no JPEGs) or keep writing in current file
        else
        {
            // if we've already started writing to a JPEG, i will be > 0 and we will keep writing, otherwise the loop will continue
            if (i > 0)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            }
        }
    }
    fclose(img);
    fclose(file);
    free(filename);
}