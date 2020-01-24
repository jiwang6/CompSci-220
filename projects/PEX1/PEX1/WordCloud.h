/** WordCloud.h
 * ===========================================================
 * Name: CS220, Spring 2020
 *
 * Purpose:  Produces a word cloud given a word list and their
 * 			 frequency.
 * ===========================================================*/

#ifndef WORDCLOUD_H
#define WORDCLOUD_H

#include "PEX1.h"

int BuildWordCloud(WordCount* argWordCount, STRING argFileName, int argNumWords);


#endif // !WORDCLOUD_H