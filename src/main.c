#include "DateString.h"

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

    //getStringsFromInput(&Strings);
    getDateStringsReg(&str,&pResStrings);
    //FreeStrings(&str);
    FreeTestStrings(&str);
    FreeStrings(&pResStrings);

    return 0;
}
