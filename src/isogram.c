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
    if(NULL == phrase)
        return true;

    if(!(*phrase))
        return true;

    isogram_data_t isogramData[ISOGRAM_UNIQUE_LETTERS_MAX] = { 0 };
    int uniqueCnt = 0;

    while(*phrase &&  uniqueCnt < ISOGRAM_UNIQUE_LETTERS_MAX)
    {
        bool letterCntIncreased = false;
        
        for(int i = 0; i < uniqueCnt; ++i)
        {//search for existing letter in list
            if(isogramData[i].c == *phrase)
            {//letter found, increase count
                isogramData[i].cnt += 1;
                letterCntIncreased = true;
                break;
            }
        }

        if(!letterCntIncreased)
        {//letter not in list, add letter
            isogramData[uniqueCnt].c = *phrase;
            isogramData[uniqueCnt].cnt += 1; 
            uniqueCnt += 1;
        }
        phrase += 1;
    }

    int countForIsogram = isogramData[0].cnt;
    for(int i = 1; i < uniqueCnt; i++)
    {
        if(isogramData[i].cnt != countForIsogram)
        {
            return false;
        }
    }
    return true;
}
