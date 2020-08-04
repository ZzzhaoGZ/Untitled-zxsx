//
// Created by zg on 2020/8/2.
//

#ifndef UNTITLED_串_H
#define UNTITLED_串_H

#include <iostream>

#define maxSize 100
/*typedef struct
{
    char str[maxSize+1];
    int length;
}Str;*/

typedef struct
{
    char *ch;
    int length;
}Str;

int strassign(Str& str,char* ch)
{
    if (str.ch)
        free(str.ch);
    int len=0;
    char *c=ch;
    while (*c)
    {
        ++len;
        ++c;
    }
    if (len==0)
    {
        str.ch=NULL;
        str.length=0;
        return 1;
    } else{
        str.ch=(char *)malloc(sizeof(char)*(len+1));
        if (str.ch==NULL)
            return 0;
        else
        {
            c=ch;
            for (int i = 0; i <= len; ++i,++c)
                str.ch[i]=*c;
                str.length=len;
                return 1;
        }
    }
}

int strlength(Str str)
{
    return str.length;
}

int strcompare(Str s1, Str s2){
    for (int i = 0; i < s1.length && i < s2.length; ++i) {
        if (s1.ch[i]!=s2.ch[i])
            return s1.ch[i] - s2.ch[i];
        return s1.length - s2.length;
    }
}
#endif //UNTITLED_串_H
