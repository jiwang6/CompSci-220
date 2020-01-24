#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define STRING char*
#define MAX_WORD_LENGTH 20 // edit: changed from 'MAX_WORD_LENGTH 5'
#define MAX_WORD_LENGTH_STRING "19" // edit: changed from '5' to account for null byte


typedef struct {
    STRING word;
    int count;
} WordCount;

int CountWordsInFile(STRING argFileName);
void RemovePunctuationMakeUpperCase(STRING argWord);
void PrintWordsToConsole(WordCount* argWordCount);
int NumUniqueWords(WordCount* argWordCount);

WordCount* CreateWordCountArray(int argNumberOfWords);
void DeleteWordCount(WordCount* argWordCount);
WordCount* ReadExclusionFile(STRING argFileName);
WordCount* ReadStoryFile(STRING argFileName, WordCount* argExclusionList);
bool WordExistsInWordCount(WordCount* argWordCount, STRING argBuffer);
void UpdateWordCount(WordCount* argWordCount, STRING argBuffer);

void QuickSortWords(WordCount* argWordCount, int argLow, int argHigh);
int QuickSortPartition(WordCount* argWordCount, int argLow, int argHigh);