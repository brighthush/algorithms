/*************************************************************************
	> File Name: sample_word.cpp
	> Author: bright
	> Mail: brighthush at sina dot com
	> Created Time: Wed 14 Jan 2015 09:51:54 PM CST
description: If you have get words' distribution from statistics. You want
to sample a word from these words according its probability distribution.
This code shows you a method that can quickly sample one word from these 
words just by initialize one sampleTable. This technique can be used in 
algorithm which may need words sampling.
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// generate a distribution of words
void generateWordsProb(double *words, const int wordCount)
{
    srand(1234);
    double sum = 0;
    for(int i=0; i<wordCount; ++i)
    {
        words[i] = rand();
        sum += words[i];
    }
    for(int i=0; i<wordCount; ++i) words[i] /= sum;
}

#define MAX_TABLE 10000
int sampleTable[MAX_TABLE];
void initTable(double *words, const int wordCount)
{
    double sum = words[0];
    int curWord = 0;
    for(int i=0; i<MAX_TABLE; ++i)
    {
        double p = i / (double)MAX_TABLE;
        if(p > sum)
        {
            ++curWord;
            if(curWord < wordCount) sum += words[curWord];
            else --curWord;
        }
        sampleTable[i] = curWord;
    }
}

// uniform random one number from interval [a, b]
int randomInterval(int a, int b)
{
    double val = rand() / (double)RAND_MAX;     //[0, 1]
    val *= (b - a + 1);                         //[0, b-a+1]
    val += a;                                   //[a, b+1]
    int r = (int)val;
    return r;
}

int main()
{
    printf("%d\n", RAND_MAX);
    double *words;
    int wordCount = 5;
    words = (double *)malloc(sizeof(double) * wordCount);
    if(words == NULL) { printf("allocate memory for words faild.\n"); exit(-1); }
    generateWordsProb(words, wordCount);       // generate random word distribution
    initTable(words, wordCount);              // init table, so that each element in sampleTable 
                                              // corresponding to one word which obey the distribution
                                              // of their probability
    printf("words' distribution:\n");
    for(int i=0; i<wordCount; ++i)
        printf("\t word %d : %.08lf\n", i, words[i]);
    int *check = (int *)malloc(sizeof(int) * wordCount);
    if(check == NULL) exit(-1);
    memset(check, 0, sizeof(int)*wordCount);
    
    double sum = 0;
    // then randomly generate one number in interval [0, MAX_TABLE-1], you can get word sample accroding
    // words' distribution
    for(int i=0; i<10000; ++i)
    {
        int point = randomInterval(0, MAX_TABLE-1);
        int word = sampleTable[point];
        //printf("word %d\n", word);
        ++check[word];
        sum += 1;
    }

    for(int i=0; i<wordCount; ++i)
    {
        double p = (double)check[i] / sum;
        printf("word %d : prob %.08lf, sample_prob %.08lf, diff %.08lf\n", \
                i, words[i], p, p - words[i]);
    }
    return 0;
}

