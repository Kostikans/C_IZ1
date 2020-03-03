#include "DateString.h"

void print(char ** strings,int count) {
    size_t c = 0;
    while (c < count) {
        char *p = strings[c];
        size_t i = 0;
        while (p[i] != '\0') {
            printf("%c", p[i]);
            ++i;
        }
        printf("%c", '\n');
        ++c;
    }
}

size_t getDateStringsReg(StringData *pStrings, StringData *pResStrings) {
    size_t size = 8;
    pResStrings->data = (char**)malloc(size * sizeof(char *));
    if(pResStrings->data == NULL)
        return NULL;
    size_t c = 0;
    int resCount = 0;
    regex_t regex;
    int err = regcomp(&regex, PATTERN, REG_EXTENDED);
    if(err == -1)
        return -1;
    while ( c < pStrings->size) {
        char *p = pStrings->data[c];
        regmatch_t  pm;
        int flag = regexec(&regex, p, 0, &pm, 0);
        if(flag == 0){
            if(size == resCount)
            {
                size *= 2;
                pResStrings->data = (char**)realloc(pResStrings->data,size * sizeof(char*));
                if(pResStrings->data == NULL)
                    return NULL;
            }
            int i = 0 ;
            size_t lineSize = 128;
            pResStrings->data[resCount] = (char*)calloc(sizeof(char),lineSize);
            if(pResStrings->data[resCount] == NULL)
                return NULL;
            while(p[i] != '\0'){
                if(i == lineSize) {
                    lineSize *= 2;
                    pResStrings->data[resCount] = (char *) realloc(pResStrings->data[resCount], lineSize * sizeof(char ));
                }
                if( pResStrings->data[resCount]  == NULL)
                    return NULL;
                pResStrings->data[resCount][i] = pStrings->data[c][i];
                ++i;
            }
            ++resCount;
        }
        ++c;
    }
    regfree(&regex);
    pResStrings->size = resCount;
    print(pResStrings->data,pResStrings->size);
    return resCount;
}

size_t getStringsFromInput(StringData *pStrings)
{
    size_t size = 4;
    pStrings->data = (char **) malloc(size * sizeof(char*));
    if(pStrings->data == NULL)
        return NULL;
    char *line = NULL;
    size_t len = 0;
    size_t count = 0;

    while(getline(&line, &len, stdin) != EOF){
        if(count == size){
            size *= 2;
            pStrings->data = (char**)realloc(pStrings->data, size * sizeof(char*));
            if(pStrings->data == NULL)
                return NULL;
        }
        size_t i = 0;
        pStrings->data[count] = (char *) malloc(len * sizeof(char));
        if(pStrings->data[count] == NULL)
            return NULL;
        while(line[i] != '\n'){
            pStrings->data[count][i] = line[i];
            ++i;
        }
        ++count;
        if(count == 5)
            break;
    }
    pStrings->size = count;
    print(pStrings->data, pStrings->size);
}

void FreeStrings(StringData *pStrings)
{
    if(pStrings->size == 0)
        return;
    for(size_t i = 0; i < pStrings->size; ++i){
        free(pStrings->data[i]);
    }
    free(pStrings->data);
}

void FreeTestStrings(StringData *pStrings)
{
    free(pStrings->data);
}