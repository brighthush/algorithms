#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef long long LL;

class Solution {
public:
    int divide(LL dividend, LL divisor) {
        if(dividend==0) return 0;
        bool negFlag = false;
        if(dividend<0 && divisor>0) {
            negFlag = true;
            dividend = -dividend;
        }
        else if(dividend>0 && divisor<0) {
            divisor = -divisor;
            negFlag = true;
        }
        else if(dividend<0 && divisor<0) {
            dividend = -dividend;
            divisor = -divisor;
        }
        LL ans = calculate(dividend, divisor);
        if(negFlag) {
            if(-ans < INT_MIN) return INT_MIN;
            else return -ans;
        }
        else {
            if(ans > INT_MAX) return INT_MAX;
            else return ans;
        }
    }

    LL calculate(LL a, LL b) {
        //cout << a << " " << b << endl;
        if(a < b) return 0;
        if(a == b) return 1;
        LL ans = 0;
        while(a >= b) {
            if(a == b) {
                ans += 1;
                a -= b;
                continue;
            }
            LL atemp = a;
            LL btemp = b;
            LL cnt = 1;
            while(atemp > btemp) {
                btemp = btemp<<1;
                cnt = cnt<<1;
            }
            if(atemp == btemp) {
                a -= btemp;
                ans += cnt;
            }
            else if(atemp < btemp) {
                btemp = btemp >> 1;
                cnt = cnt >> 1;
                a -= btemp;
                ans += cnt;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int a, b;
    while(scanf("%d, %d", &a, &b) != EOF) {
        cout << s.divide(a, b) << endl;
    }
    return 0;
}

