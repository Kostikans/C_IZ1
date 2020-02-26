#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define PATTERN "([0-1]?[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]"

void print(char ** strings,int count){
    int c = 0;
    while ( c < count) {
        char *p = strings[c];
        int i = 0;
        while(p[i] != '\0')
        {
            printf("%c" , p[i]);
            ++i;
        }
        printf("%c",'\n');
        ++c;
    }
}

char** getDateStringsReg(char ** pStrings, int count, char **pResStrings) {
    pResStrings = (char**)malloc(4 * sizeof(char *));
    int c = 0;
    int resCount = 0;
    regex_t regex;
    int err = regcomp(&regex, PATTERN, REG_EXTENDED);
    while ( c < count) {
        char *p = pStrings[c];
        regmatch_t  pm;
        int flag = regexec(&regex, p, 0, &pm, 0);
        if(flag == 0){
            pResStrings[resCount] = pStrings[c];
            ++resCount;
        }
        ++c;
    }
    print(pResStrings,resCount);
}

char** getStringsFromInput()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline (&line, &len, stdin);
    int a = 5;
}
int main() {
    char **strings = (char **) malloc(5 * sizeof(char *));
    strings[2] = "rewklrewkl";
    strings[1] = "g 23:50:40 tkrekt";
    strings[0] = "4534 23:65:1 r";
    strings[3] = "23:50:40";
    strings[4] = "tr23:2:43t";


    char **resStrings;
    //getDateStrings(strings, 4, resStrings);

    getDateStringsReg(strings, 5 , resStrings);
    getStringsFromInput();


    return 0;
}
