#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define PATTERN "([0-1][0-9]|[2][0-3]):[0-5][0-9]:[0-5][0-9]"

struct StringData
{
    char **data;
    size_t size;
};

typedef struct StringData StringData;

void print(char ** strings,int count){
    size_t c = 0;
    while ( c < count) {
        char *p = strings[c];
        size_t i = 0;
        while(p[i] != '\0')
        {
            printf("%c" , p[i]);
            ++i;
        }
        printf("%c",'\n');
        ++c;
    }
}

size_t getDateStringsReg(StringData *pStrings, StringData *pResStrings) {
    size_t size = 4;
    pResStrings->data = (char**)malloc(size * sizeof(char *));
    if(pResStrings->data == NULL)
        return NULL;
    size_t c = 0;
    int resCount = 0;
    regex_t regex;
    int err = regcomp(&regex, PATTERN, REG_EXTENDED);
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
            pResStrings->data[resCount] = pStrings->data[c];
            ++resCount;
        }
        ++c;
    }
    pResStrings->size = resCount;
    print(pResStrings->data,pResStrings->size);
    return resCount;
}

int getStringsFromInput(StringData *strings)
{
    size_t size = 5;
    strings->data = (char **) malloc(size * sizeof(char*));
    if(strings->data == NULL)
        return NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t count = 0;

    while(getline(&line, &len, stdin) != EOF){
        if(count == size){
            size *= 2;
            strings->data = (char**)realloc(strings->data,size * sizeof(char*));
            if(strings->data == NULL)
                return NULL;
        }
        size_t i = 0;
        strings->data[count] = (char *) malloc( len * sizeof(char));
        if(strings->data[count] == NULL)
            return NULL;
        while(line[i] != '\n'){
            strings->data[count][i] = line[i];
            ++i;
        }
        ++count;
        if(count == 5)
            break;
    }
    strings->size = count;
    print(strings->data,strings->size);
}

void FreeStrings(StringData *Strings)
{
    if(Strings->size == 0)
        return;
    for(size_t i = 0; i < Strings->size; ++i){
        free(Strings->data[i]);
    }
    free(Strings->data);
}
int main() {

    StringData str;
    str.size = 6;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[2] = "rewklrewkl";
    str.data[1] = "g 23:50:40 tkrekt";
    str.data[0] = "4534 23:65:1 r";
    str.data[3] = "00:50:40";
    str.data[4] = "tr 23:20:43 t";
    str.data[5] = "tr 01:10:20 t";

    StringData Strings;
    StringData pResStrings;

    getStringsFromInput(&Strings);
    getDateStringsReg(&Strings,&pResStrings);
    FreeStrings(&Strings);
    FreeStrings(&pResStrings);

    return 0;
}
