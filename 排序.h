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
{//简单选择排序
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

void bublesort(int arr[],int n)
{//冒泡排序
    int temp,i,j,flag;
    for(i=n-1;i>=1;i--)
    {
        flag=0;
        for(j=1;j<=i;j++)
            if(arr[j-1]>arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;

                flag=1;
            }
        if (flag==0)
            return;
    }
}//sgjj

void shellsort(int arr[],int n)
{//希尔排序
    int temp;
    int j;
    for(int gap = n/2; gap > 0; gap/=2)
    {
        for(int i = gap;i<n;i++)
        {
            temp = arr[i];
            for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
            {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}

void quickSort(int arr[],int low,int high)
{//快速排序
    int temp;
    int i=low,j=high;
    if(low<high)
    {
        temp=arr[low];
        while (i<j)
        {
            while (j>i&&arr[j]>=temp) --j;
            if(i<j)
            {
                arr[i] = arr[j];
                ++i;
            }
            while (j>i&&arr[i]<temp) ++i;
            if(i<j)
            {
                arr[j] = arr[i];
                --j;
            }
        }
        arr[i]=temp;
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
}

void sift(int arr[],int low,int high)
{//堆排序所需的函数
    int i=low,j=2*i+1;
    int temp=arr[i];
    while (j<=high)
    {
        if(j<high&&arr[j]<arr[j+1])
            ++j;
        if(temp<arr[j])
        {
            arr[i] = arr[j];
            i=j;
            j=2*i+1;
        } else break;
    }
    arr[i]=temp;
}

void heapSort(int arr[],int n)
{//堆排序
    int i;
    int temp;
    for(i=n/2-1;i>=0;--i)
        sift(arr,i,n-1);
    for(i=n-1;i>0;--i)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        sift(arr,0,i-1);
    }
}

#endif //UNTITLED_排序_H

















