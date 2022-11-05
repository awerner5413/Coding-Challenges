#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            int new = round(avg);
            image[i][j].rgbtBlue = new;
            image[i][j].rgbtGreen = new;
            image[i][j].rgbtRed = new;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // swap the left most pixel with the right most pixel
        for (int j = 0, k = width - 1; j < width; j++, k--)
        {
            RGBTRIPLE temp = image[i][k];
            image[i][k] = image[i][j];
            image[i][j] = temp;

            // break the loop once swaps meet in the middle
            if (j == k || j == k - 1)
            {
                break;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // calculate new blurred image
    for (int i = 0; i < height; i++) // loop each row of image
    {
        for (int j = 0; j < width; j++) // loop each column of image
        {

            // run the calculation on each valid pixel (stop if looking at pixel outside image array)
            int n = 0;
            int r[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            int g[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int k = i - 1; k < i + 2; k++) // loop each row of pixel grid
            {
                // shift grid if outside image array
                if (k < 0)
                    k++;
                if (k == height)
                    break;
                for (int l = j - 1; l < j + 2; l++) // loop each column of pixel grid
                {
                    if (l < 0)
                        l++;
                    if (l == width)
                        break;
                    // store pixel data
                    r[n] = copy[k][l].rgbtRed;
                    g[n] = copy[k][l].rgbtGreen;
                    b[n] = copy[k][l].rgbtBlue;
                    n++;
                }
            }

            // calculate new pixel color
            // sum all color values
            int newR = 0;
            int newG = 0;
            int newB = 0;
            for (int c = 0; c < 9; c++)
            {
                newR = newR + r[c];
                newG = newG + g[c];
                newB = newB + b[c];
            }
            // round the values and assign to image
            image[i][j].rgbtRed = round(newR / (n * 1.0));
            image[i][j].rgbtGreen = round(newG / (n * 1.0));
            image[i][j].rgbtBlue = round(newB / (n * 1.0));
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // calculate new Sobel image
    // find target pixel
    for (int i = 0; i < height; i++) // loop each row of image
    {
        for (int j = 0; j < width; j++) // loop each column of image
        {

            // Gather pixel values in 3x3 grid surrounding each target pixel
            int n = 0;
            int r[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            int g[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int k = i - 1; k < i + 2; k++) // loop each row of pixel grid
            {
                for (int l = j - 1; l < j + 2; l++) // loop each column of pixel grid
                {
                    // adjust pixel values outside the image array
                    if (k < 0 || k > height - 1 || l < 0 || l > width - 1)
                    {
                        r[n] = 0;
                        g[n] = 0;
                        b[n] = 0;
                    }
                    else
                    {
                        r[n] = copy[k][l].rgbtRed;
                        g[n] = copy[k][l].rgbtGreen;
                        b[n] = copy[k][l].rgbtBlue;
                    }
                    n++;
                }
            }
            // calculate new target pixel values
            int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
            int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
            long newR = 0; float GxR = 0; float GyR = 0;
            long newG = 0; float GxG = 0; float GyG = 0;
            long newB = 0; float GxB = 0; float GyB = 0;
            // Get Gx and Gy values
            for (int c = 0; c < 9; c++)
            {
                GxR = GxR + (Gx[c] * r[c]); GyR = GyR + (Gy[c] * r[c]);
                GxG = GxG + (Gx[c] * g[c]); GyG = GyG + (Gy[c] * g[c]);
                GxB = GxB + (Gx[c] * b[c]); GyB = GyB + (Gy[c] * b[c]);
            }
            // Calculate new pixel value using Sobel formula, make value 255 if higher
            newR = round((double) sqrt(((long) pow(GxR, 2)) + ((long) pow(GyR, 2))));
            newG = round((double) sqrt(((long) pow(GxG, 2)) + ((long) pow(GyG, 2))));
            newB = round((double) sqrt(((long) pow(GxB, 2)) + ((long) pow(GyB, 2))));
            if (newR > 255)
                newR = 255;
            if (newG > 255)
                newG = 255;
            if (newB > 255)
                newB = 255;
            // assign new values to target pixel
            image[i][j].rgbtRed = newR;
            image[i][j].rgbtGreen = newG;
            image[i][j].rgbtBlue = newB;
        }
    }
    return;
}
