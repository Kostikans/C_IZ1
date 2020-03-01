//
// Created by kostikan on 01.03.2020.
//

#include "gtest/gtest.h"
extern "C" {
#include "DateString.h"
}

TEST(string,str1)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "rewklrewkl";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
}

TEST(string,str2)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "g 23:50:40 tkrekt";
    ASSERT_EQ(getDateStringsReg(&str,&temp),1);
}

TEST(string,str3)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "4534 23:65:1 r";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
}

TEST(string,str4)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "00:50:40";
    ASSERT_EQ(getDateStringsReg(&str,&temp),1);
}

TEST(string,str5)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "rtr 23:20:43 t";
    ASSERT_EQ(getDateStringsReg(&str,&temp),1);
}

TEST(string,str6)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "r 01:10:20 t";
    ASSERT_EQ(getDateStringsReg(&str,&temp),1);
}

TEST(string,str7)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "rewklrewkl";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
}

TEST(string,str8)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "rewklrewkl";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
}

TEST(string,str9)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "rewklrewkl";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
}

TEST(string,str10)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = "rewklrewkl";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
}
