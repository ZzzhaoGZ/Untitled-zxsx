//
// Created by zg on 2020/8/9.
//

#ifndef UNTITLED_排序_H
#define UNTITLED_排序_H

void insertsort(int arr[],int n)
{//直接插入排序
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

void selectsort(int arr[],int n)
{
    int i,j,k;
    int temp;
    for(i=0;i<n;++i)
    {
        k=i;
        for(j=i+1;j<n;++j)
            if(arr[k]>arr[j])
                k=j;
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
}
#endif //UNTITLED_排序_H
