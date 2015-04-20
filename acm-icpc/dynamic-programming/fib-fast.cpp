// Using matrix fast pow algorithm to solve fib problem.
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MOD 19999997

using namespace std;

typedef long long LL;

class Matrix
{
private:
    int row, col;
    LL* values;

public:
    Matrix()
    {
        row = 0;
        col = 0;
        values = NULL;
    }

    Matrix(int row, int col, LL* values)
    {
        this->row = row;
        this->col = col;
        int n = row * col;
        this->values = (LL*)malloc(sizeof(LL) * n);
        memcpy(this->values, values, n*sizeof(LL));
    }

    Matrix& operator*(Matrix &matrix)
    {
        int n = row * col;
        LL* temp = (LL*) malloc(sizeof(LL) * n);
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; j++)
            {
                temp[i*col + j] = 0;
                for(int k=0; k<col; k++)
                {
                    temp[i*col + j] = (temp[i*col + j] + (values[i*col+k] * matrix.values[k*col + j])%MOD) % MOD;
                }

            }
        }
        memcpy(values, temp, n*sizeof(LL));
        return (*this);
    }

    Matrix& operator=(Matrix &matrix)
    {
        if(values == matrix.values)
            return (*this);
        free(values);
        row = matrix.row;
        col = matrix.col;
        int n = row * col;
        values = (LL*)malloc(sizeof(LL) * (row*col));
        memcpy(values, matrix.values, n*sizeof(LL));
        return (*this);
    }

    Matrix& pow(LL x)
    {
        Matrix* temp = new Matrix();
        (*temp) = (*this);
        int n = row * col;
        if(x==0)
        {
            for(int i=0; i<n; ++i)
                (*temp).values[i] = 1;
            return (*temp);
        }
        if(x == 1)
        {
            return (*temp);
        }
        Matrix t;
        t = *temp;
        for(int i=0; i<t.row; ++i)
        {
            for(int j=0; j<t.col; ++j)
                if(i==j)
                    t.values[i*col + j] = 1;
                else
                    t.values[i*col + j] = 0;
        }
        int cnt = 1;
        while(x>0)
        {
            if(x&1)
                t = t * (*temp);
            (*temp) = (*temp) * (*temp);
            x = x>>1;
        }
        (*temp) = t;
        return (*temp);
    }

    LL getValue(int i, int j)
    {
        return values[i*col + j];
    }

    virtual ~Matrix()
    {
        if(values != NULL)
            free(values);
    }
};

int main()
{
    LL values[4] = {1LL, 1LL, 1LL, 0LL};
    Matrix matrix(2, 2, values);
    Matrix temp;
    LL n;
    while(scanf("%lld", &n) != EOF)
    {
        if(n==0)    printf("0\n");
        else if(n==1)   printf("1\n");
        else
        {
            temp = matrix.pow(n+1);
            printf("%lld\n", temp.getValue(0, 1));
        }
    }
    return 0;
}

