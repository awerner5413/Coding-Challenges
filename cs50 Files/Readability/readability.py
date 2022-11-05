from cs50 import get_string
import re

def main():

    # Get the text from the user
    text = get_string("Text: ")

    # Count letters, words, and sentences
    l = count_letters(text)
    w = count_words(text)
    s = count_sentences(text)

    # Calculate the reading level
    r = (0.0588 * (l / (w / 100))) - (0.296 * (s / (w / 100))) - 15.8
    r = round(r)

    # Print reading level based on value of r
    if (r < 1):
        print("Before Grade 1")
    elif (r > 16):
        print("Grade 16+")
    else:
        print(f"Grade {r}")

# Count the number of letters in the text
def count_letters(text):
    counter = 0

    # loop over each character in the text - if isalpha is true, add to counter and return for letter count
    for i in text:
        if (i.isalpha()):
            counter += 1
    return counter

# Count the number of words in the text
def count_words(text):
    counter = 1

    # loop over each character in the text - if isspace is true, add to counter and return for word count
    for i in text:
        if (i.isspace()):
            counter += 1
    return counter


# Count the number of sentences in the text
def count_sentences(text):
    counter = 0

    # loop over each character in the text - if fin finds a '!', '.', '?' then increase counter and return
    for i in text:
        if (i.find("!") != -1):
            counter += 1
        elif (i.find(".") != -1):
            counter += 1
        elif (i.find("?") != -1):
            counter += 1
    return counter


main()