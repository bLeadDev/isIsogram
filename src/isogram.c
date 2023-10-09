#define UNITY_OUTPUT_COLOR

#define ISOGRAM_UNIQUE_LETTERS_MAX      255
#define usr_assert(x) ((void)0U)

#include "isogram.h"
#include <string.h>
#include <stdio.h>

typedef struct
{
    int cnt;
    char c;
    /* data */
}isogram_data_t;


bool is_isogram(const char phrase[]){
    //printf("Phrase: %s\t\t", ph);

    if(!(*phrase))
    {
        return true;
    }

    isogram_data_t isogramData[ISOGRAM_UNIQUE_LETTERS_MAX] = { 0 };
    
    int uniqueCnt = 0;
    isogramData[uniqueCnt].c = *phrase;
    isogramData[uniqueCnt].cnt = 1;
    uniqueCnt++;
    phrase++;
    while(*phrase)
    {
        //search for new letter
        for(int i = 0; i < uniqueCnt; i++)
        {
            if(isogramData[i].c != *phrase)
            {//new letter found
                isogramData[i].c = *phrase;
                isogramData[i].cnt++; 
                uniqueCnt++;
            }else if(isogramData[i].c == *phrase)
            {//existing letter found
                isogramData[i].cnt++;
            }else
            {// should never be executed
                usr_assert("Error in is_isogram");
            }
        }
        phrase++;
    }

    for(int  i = 0; i < uniqueCnt; i++)
    {
        printf("char: %c \tcnt: %d\t\n", isogramData[i].c, isogramData[i].cnt);
    }

    int countForIsogram = isogramData[0].cnt;
    for(int i = 1; i < uniqueCnt; i++)
    {
        if(isogramData[i].cnt != countForIsogram)
            return false;
    }
    return true;
}
