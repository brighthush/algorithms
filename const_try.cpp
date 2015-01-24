#include <iostream>

using namespace std;

// const T * and T const * with the same meaning
// T * const, this means a pointer is a const variable
template <typename T>
T const& max_value(T const *l, unsigned sz)
{
    T const *mv(l);
    for(int i=1; i<sz; ++i) if(l[i] > (*mv)) mv = &l[i];
    return *mv;
}

int main()
{
 int a[] = {4, 2, 10, 6};
 int mv = max_value(a, 4);
 cout << mv << endl;

 int ix = 10;
 int iy = 20;
 const int *px = &ix; // the pointer to a const value
 px = &iy;
 cout << *px << endl;

 int* const py = &ix;
 cout << *py << endl;
 *py = 30;
 cout << *py << endl;

 return 0;
}
