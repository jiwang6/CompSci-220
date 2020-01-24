/** PEX1.c
 * ===========================================================
 * Name: CS220, Spring 2020
 *
 * Purpose:  Code provided for PEX 1 - Debugging a word cloud
 * ===========================================================
 */

// edit: added '_CRT_SECURE_NO_WARNINGS' to preprocessor definitions

#include "PEX1.h"
#include "WordCloud.h" // edit: added WordCloud.h


/** -------------------------------------------------------------------
 * Counts the unique words in a file.
 * @param argFileName text file to count words in
 * @return number of total words in the file
  -------------------------------------------------------------------*/
int CountWordsInFile(STRING argFileName)
{
    // open the file
    FILE *filePtr = NULL;

    filePtr = fopen(argFileName, "r");

    if (filePtr == NULL) // edit: added exit
        return 0;

    int wordCount = 0;

    if (filePtr != NULL)
    {
        // read in one word at at time and
        char charBuffer[MAX_WORD_LENGTH];

        while (fscanf(filePtr, "%"MAX_WORD_LENGTH_STRING"s", charBuffer) == 1) // pedit: !=EOF
        {
            // increment the counter
            wordCount++;
        }
    }

        fclose(filePtr);

    return wordCount;
}

/** -------------------------------------------------------------------
 * Counts the unique words in a file.
 * @param argWordCount - word count to be deleted
  -------------------------------------------------------------------*/
void DeleteWordCount(WordCount* argWordCount)
{
    for(int i = 0; i < NumUniqueWords(argWordCount); i++)
    {
        free(argWordCount[i].word); // break here
    }

    free(argWordCount);
}

/** -------------------------------------------------------------------
 * Removes non alphas from the input word and makes it all uppercase
 * @param argWord - word to convert
 *
  -------------------------------------------------------------------*/
void RemovePunctuationMakeUpperCase(STRING argWord)
{
    STRING src = argWord;
    STRING dst = argWord;

    while (*src)
    {
        if (!isalpha((unsigned char)*src))
        {
            /* Skip this character */
            src++;
        } else if (islower((unsigned char)*src))
        {
            /* Make it lowercase */ // make it uppercase?
            *dst++ = toupper((unsigned char)*src);
            src++;
        } else if (src == dst)
        {
            /* Increment both pointers without copying */
            src++;
            dst++;
        } else
        {
            /* Copy character */
            *dst++ = *src++;
        }
    }

    *dst = 0;
}

/** -------------------------------------------------------------------
 * Prints the words and their frequencies
 * @param argWordCounts - array of word frequencies
 * @param argWords - array of words
   -------------------------------------------------------------------*/
void PrintWordsToConsole(WordCount* argWordCount)
{
    // print out each word and it's frequency
    for (int index = 0; argWordCount[index].word !=NULL; index++)
    {
        printf("%5d %s\n", argWordCount[index].count, argWordCount[index].word);
    }
}

int NumUniqueWords(WordCount* argWordCount)
{
    int i = 0; // edit: changed from 'int i;'
    while(argWordCount[i].word	!= NULL)
    {
        i += 1; // edit: changed from '= 1'
    }

    return i;
}

/** -------------------------------------------------------------------
 * Allocates memory for the word list array.
 * @param argNumberOfWords number of words in the file.
 * @return array of WordCounts.
  -------------------------------------------------------------------*/
WordCount* CreateWordCountArray(int argNumberOfWords)
{
    WordCount *retWordCount;
    retWordCount = malloc((argNumberOfWords + 1) * sizeof(WordCount)); // edit: changed from 'sizeof(int)'

    for (int i = 0; i < argNumberOfWords + 1; i++)
    {
        retWordCount[i].word = NULL; // err 2   changed from .word
    }

    return retWordCount;
}

/** -------------------------------------------------------------------
 * Reads a file of words to exclude from the word cloud.
 * @param argFileName - text file to get exclude words from
 * @return Array containing words to exclude
   -------------------------------------------------------------------*/
WordCount* ReadExclusionFile(STRING argFileName)
{
    // get the count of words
    int numWords = CountWordsInFile(argFileName) + 1;

    // if there are no words then return NULL
    if (numWords <= 0)
    {
        return NULL;
    } else
    {
        // open the file
        FILE *filePtr = NULL;

        filePtr = fopen(argFileName, "r");

        if (!filePtr)
            return NULL;

        // create a buffer
        char charBuffer[MAX_WORD_LENGTH];

        // initialize an array of structs with the proper number of words
        WordCount* returnWordCount = CreateWordCountArray(numWords);

        // read in each word and add it to the array if it isn't already there
        while (fscanf(filePtr, "%"MAX_WORD_LENGTH_STRING"s", charBuffer) == 1)
        {
            RemovePunctuationMakeUpperCase(charBuffer);
            if(!WordExistsInWordCount(returnWordCount, charBuffer)) {
                UpdateWordCount(returnWordCount, charBuffer);
            }
        }

        // close the file and return
        fclose(filePtr);
        return returnWordCount;
    }

}

/** -------------------------------------------------------------------
 * Reads a file of words from story to build the word cloud.
 * @param argFileName - text file build word cloud from
 * @param argExclusionList - WordCount array with words to exclude
 * @return Map containing words and counts from story
   -------------------------------------------------------------------*/
WordCount* ReadStoryFile(STRING argFileName, WordCount* argExclusionList)
{
    // get the count of words
    int numWords = CountWordsInFile(argFileName);

    // if there are no words then return NULL
    if(numWords <= 0)
    {
        return NULL;
    } else
    {
        // open the file
        FILE *filePtr = NULL; // edit: changed from 'FILE filePtr'

        filePtr = fopen(argFileName, "r");

        if (!filePtr)
            return NULL;

        // create a buffer
        char charBuffer[MAX_WORD_LENGTH];

        // dynamically allocate memory for an array of structs with the proper number of words
        WordCount* returnWordCount = CreateWordCountArray(numWords);

        // read in each word and add it to the counted map if it isn't already there or update it's frequency
        while (fscanf(filePtr, "%"MAX_WORD_LENGTH_STRING"s", charBuffer) == 1)
        {
            RemovePunctuationMakeUpperCase(charBuffer);
            if(!WordExistsInWordCount(argExclusionList, charBuffer)) {
                UpdateWordCount(returnWordCount, charBuffer);
            }
        }

        // close the file and return
        fclose(filePtr);
        return returnWordCount;
    }

}

/** -------------------------------------------------------------------
 * Checks if a word is already stored in an existing WordCount
 * @param argWordCount - array to search in
 * @param argBuffer - word to look for
 * @return bool returns true/false for word existing in argWordCount
   -------------------------------------------------------------------*/
bool WordExistsInWordCount(WordCount* argWordCount, STRING argBuffer)
{
    int i = 0;
    while(argWordCount[i].word != NULL)
    {
        if(strcmp(argWordCount[i].word, argBuffer) == 0)
        {
            return true;
        }

        i++;
    }

    return false; // edit: added 'return false'

}

/** -------------------------------------------------------------------
 * Updates count of unique words and adds word to array (argWordCount)
 * @param argWordCount - array to search in
 * @param argBuffer - word to look for
   -------------------------------------------------------------------*/
void UpdateWordCount(WordCount* argWordCount, STRING argBuffer)
{
    int i = 0;



    while(argWordCount[i].word != NULL) 
    {



        if(strcmp(argWordCount[i].word, argBuffer) == 0) // if same word
        {
            argWordCount[i].count++;
            // return;
        }

        i++;
    }
    argWordCount[i].word = malloc(MAX_WORD_LENGTH * sizeof(char)); // edit: moved 3 lines
    strcpy(argWordCount[i].word, argBuffer); // edit: changed from 'argWordCount[i].word = argBuffer;'
    argWordCount[i].count = 0;


}

/** -------------------------------------------------------------------
 * Partitions the arrays into upper and lower portions around a pivot
 * @param argWordCounts - array of word frequencies
 * @param argWords - array of words
 * @param argLow - low index into arrays
 * @param argHigh - high index into arrays
 * @return pivot index
   -------------------------------------------------------------------*/
int QuickSortPartition(WordCount* argWordCount, int argLow, int argHigh)
{
    int midpoint = 0;
    int pivot = 0;

    int done = 0;

    // calc midpoint and pivot
    midpoint = argLow + (argHigh - argLow) / 2;
    pivot = argWordCount[midpoint].count;

    while (!done)
    {
        // move the high pointer
        while (argWordCount[argHigh].count < pivot)
        {
            argHigh--;
        }

        // move the low pointer
        while (pivot < argWordCount[argLow].count)
        {
            argLow++;
        }

        // check if the pointers have crossed
        if (argLow >= argHigh)
        {
            done = 1;
        } else
        {
            // swap frequency and word
            WordCount tempWordCount;

            tempWordCount = argWordCount[argLow];
            argWordCount[argLow] = argWordCount[argHigh];
            argWordCount[argHigh] = tempWordCount;

            // move pointers
            argLow++;
            argHigh--;
        }
    }

    // return the location of the pivot point
    return argHigh;
}

/** -------------------------------------------------------------------
 * Quicksorts the arrays
 * @param argWordCounts - array of word frequencies
 * @param argWords - array of words
 * @param argLow - low index into arrays
 * @param argHigh - high index into arrays
   -------------------------------------------------------------------*/
void QuickSortWords(WordCount* argWordCount, int argLow, int argHigh)
{
    // if the points haven't crossed
    if (argLow < argHigh)
    {
        // partition the arrays
        int pivot = QuickSortPartition(argWordCount, argLow, argHigh);

        // sort the partitions
        QuickSortWords(argWordCount, argLow, pivot);
        QuickSortWords(argWordCount, pivot + 1, argHigh);
    }
}

int main(int argc, char** argv)
{
    // check that an argument was provided
    if (argc <= 1)
    {
        printf("Please provide a story file to read, an optional exclusion word list, and an ");
        printf("optional filename to create.\n\n");
        printf("USAGE:  PEX4.exe storyFile [exclusionWordFile] [outputFileName]\n");
        return 0;
    }

    // create excluded words map and fill it in if the argument is provided
    WordCount* excludedWords = NULL;


    excludedWords = ReadExclusionFile(argv[2]);

    // create and fill in the story word map
    WordCount* storyWordMap = ReadStoryFile(argv[1], excludedWords);


    // dump the map into the parallel arrays
    int numUniqueWords = NumUniqueWords(storyWordMap);

    // if an output file is provided build the html word cloud
    if (argc > 3)
        BuildWordCloud(storyWordMap, argv[3], numUniqueWords);

    // sort the words by frequency, highest at the top
    QuickSortWords(storyWordMap, 0, numUniqueWords);

    // print the words
    PrintWordsToConsole(storyWordMap);

    // release memory
    DeleteWordCount(excludedWords);
    DeleteWordCount(storyWordMap);

    return 1;
}