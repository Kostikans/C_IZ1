#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define PATTERN "([0-1][0-9]|[2][0-3]):[0-5][0-9]:[0-5][0-9]"

typedef struct StringData
{
    char **data;
    size_t size;
} StringData;

void print(char ** strings,int count);
size_t getDateStringsReg(StringData *pStrings, StringData *pResStrings);
size_t getStringsFromInput(StringData *pStrings);
void FreeStrings(StringData *pStrings);
void FreeTestStrings(StringData *pStrings);