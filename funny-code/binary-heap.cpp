/*
 * Implement a binary minimum heap.
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 1000;
int tree[MAX];
int heapSize;

void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getSmallest(int n)
{
    int index = n;
    if(n*2 <= heapSize)
    {
        if(tree[index] > tree[n*2])
            index = n*2;
    }
    if(n*2+1 <= heapSize)
    {
        if(tree[index] > tree[n*2+1])
            index = n*2+1;
    }
    return index;
}

void heapify(int n)
{
    int temp = getSmallest(n);
    if(temp == n)
        return ;
    mySwap(tree[n], tree[temp]);
    heapify(temp);
}

void buildHeap(int n)
{
    for(int i=n/2; i>=1; --i)
        heapify(i);
}

void heapSort(int n)
{
    cout << "buildHeap ing..." << endl;
    buildHeap(n);
    printf("buildHeap done...\n");
    for(int i=1; i<n; ++i)
    {
        mySwap(tree[1], tree[heapSize]);
        cout << tree[heapSize] << endl;
        --heapSize;
        heapify(1);

    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        heapSize = n;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &tree[i]);
        }
        heapSort(n);
        cout << n << endl;
        for(int i=1; i<=n; ++i)
        {
            printf("%d ", tree[i]);
        }
        printf("\n");
    }
    return 0;
}

