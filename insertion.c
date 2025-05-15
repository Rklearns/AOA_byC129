#include<stdio.h>
void main()
{
    int arr[]={87,43,21,1,4,6,1};
    int n=7;
    
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key)
        {
          
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}