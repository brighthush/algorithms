/*
 * Author: brighthush at sina dot com
 * Des: Using binary search to find the minimum abstract value of a sorted array.
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

int binarySearch(int *arr, int n)
{
    if(arr[n-1] < 0) return arr[n-1];
    int l = 0, r = n-1;
    int mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(arr[mid] == 0) return arr[mid];
        else if(arr[mid] > 0) r = mid - 1;
        else l = mid + 1;
    }
    if(l > 0 && (-arr[l-1] < arr[l])) return -arr[l-1];
    else return arr[l];
}

int main()
{
    int n;
    int arr[100];
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0; i<n; ++i) scanf("%d", &arr[i]);
        printf("%d\n", binarySearch(arr, n));
    }
    return 0;
}

