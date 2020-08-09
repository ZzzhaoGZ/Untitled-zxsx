//
// Created by zg on 2020/8/9.
//

#ifndef UNTITLED_排序_H
#define UNTITLED_排序_H

void insertsort(int arr[],int n)
{
    int temp,i,j;
    for(i=1;i<n;++i)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0&&temp<arr[j])
        {
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1] = temp;
    }
}

#endif //UNTITLED_排序_H
