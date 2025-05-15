#include <stdio.h>

int a[100];
int min;
int max;
void maxmin(int l, int r);
void maxmin(int l, int r) {
 if(l==r)
 {
    min=a[l];max=a[l];
    return;

 }
 if(r==l+1)
 {
    if(a[l]>a[r])
    {
        max=a[l];
        min=a[r];
    }
    else{
        min=a[l];
        max=a[r];
    }
    return;
 }
 int mid=(l+r)/2;

 maxmin(l,mid);
 int maxi=max;
 int mini=min;
 maxmin(mid+1,r);
 if(maxi>max)
 {
    max=maxi;
 }
 if(mini<min)
 {
    min=mini;
 }

}

int main() {
    int n, minVal, maxVal;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    maxmin(0,n-1);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}
