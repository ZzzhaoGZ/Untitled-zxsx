//
// Created by zg on 2020/8/1.
//

#ifndef UNTITLED_FBI_H
#define UNTITLED_FBI_H
#include <iostream>
int Fbi(int i)
{
    if (i<2)
        return i == 0 ? 0 : 1;
    return Fbi(i-1) + Fbi(i-2);
}
#endif //UNTITLED_FBI_H
