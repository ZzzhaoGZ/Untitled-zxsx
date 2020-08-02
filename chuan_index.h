//
// Created by zg on 2020/8/2.
//

#ifndef UNTITLED_CHUAN_INDEX_H
#define UNTITLED_CHUAN_INDEX_H


int Index(String S, String T, int pos)
{
    int n,m,i;
    String sub;
    if (pos>0)
    {
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while (i<=n-m+1)
        {
            SubString(sub,S,i,m);
            if (StrCompare(sub,T)!=0)
                ++i;
            else
                return i;
        }
    }
    return 0;
}
#endif //UNTITLED_CHUAN_INDEX_H
