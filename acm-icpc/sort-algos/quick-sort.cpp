#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void mySwap(int &a, int &b)
{ int temp = a; a = b; b = temp; }

int randIndex(int beg, int end)
{
    int cnt = end - beg;
    return (rand() % cnt) + beg;
}

int partition(int *array, int beg, int end)
{
    if(beg >= end) return -1;
    int randi = randIndex(beg, end); // to solve the problem that the list is sorted
    mySwap(array[beg], array[randi]);
    int piv = array[beg];
    int cur = beg;
    for(int i=beg; i<end; ++i)
    {
        if(array[i] < piv) { mySwap(array[i], array[cur]); ++cur; }
    }
    return cur;
}

void qsort(int *array, int beg, int end)
{
    if(beg >= end) return ;
    if(end - beg == 1) return ;
    if(end - beg == 2)
    {
        if(array[beg] > array[beg+1]) mySwap(array[beg], array[beg+1]);
        return ;
    }
    int mid = partition(array, beg, end);
    if(mid == beg) // to solve the sub-list has all the same value problem
    {
        bool flag = true;
        for(int i=beg; i< end; ++i) if(array[i] != array[beg]) flag = false;
        if(flag) return ;
    }
    qsort(array, beg, mid);
    qsort(array, mid, end);
}

int main()
{
    int a[100], n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0; i<n; ++i) scanf("%d", &a[i]);
        qsort(a, 0, n);
        for(int i=0; i<n; ++i) printf("%d%c", a[i], i==n-1?'\n':' ');
    }
    return 0;
}

