#include <iostream>

using namespace std;

int main()
{
    int matrix[2][3] = { {0, 1, 2}, {3, 4,5} };
    int *p[2]; // array of pointer
    for(int i=0; i<2; ++i) p[i] = matrix[i];
    for(int i=0; i<2; ++i) for(int j=0; j<3; ++j) cout << p[i][j] << endl;

    int (*p)[3]; // pointer to array


    return 0;
}
