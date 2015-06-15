#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;
class Solution {
    char str[20];
public:
    string fractionToDecimal(LL numerator, LL denominator) {
        if(numerator == 0) return string("0");
        bool negFlag = false;
        if(numerator<0 && denominator<0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        else if(!(numerator>=0 && denominator>=0)) {
            negFlag = true;
            if(numerator<0) numerator = -numerator;
            if(denominator<0) denominator = -denominator;
        }
        cout << "negFlag " << negFlag << " " << numerator << " " << denominator << endl;
        vector<LL> ans;
        vector<LL> left;
        LL lefttemp = numerator % denominator;
        LL anstemp = (numerator - lefttemp) / denominator;
        //cout << "anstemp " << anstemp << " lefttemp " << lefttemp << endl;
        ans.push_back(anstemp);
        left.push_back(lefttemp);

        int repeatIndex = -1;
        LL temp;
        while(lefttemp != 0) {
            //cout << "anstemp " << anstemp << " lefttemp " << lefttemp << endl;
            lefttemp *= 10;
            temp = lefttemp;
            lefttemp = temp % denominator;
            anstemp = (temp - lefttemp) / denominator;
            //printf("\tanstemp %d lefttemp %d\n", anstemp, lefttemp);
            for(int i=0; i<left.size(); ++i) {
                if(left[i] == lefttemp) {
                    repeatIndex = i+1;
                    //if(left.size() == repeatIndex) {
                        ans.push_back(anstemp);
                        left.push_back(lefttemp);
                    //}
                    //cout << "repeatIndex " << repeatIndex << endl;
                    break;
                }
            }
            if(repeatIndex != -1) break;
            //printf("\tanstemp %d lefttemp %d\n", anstemp, lefttemp);
            ans.push_back(anstemp);
            left.push_back(lefttemp);
        }
        string strans;
        if(negFlag) strans = string("-");
        sprintf(str, "%lld", ans[0]);
        strans += string(str);
        if(ans.size() > 1) {
            strans += '.';
            for(int i=1; i<ans.size(); ++i) {
                if(i==repeatIndex) {
                    strans += '(';
                }
                sprintf(str, "%lld", ans[i]);
                strans += str;
            }
            if(repeatIndex != -1) {
                strans += ')';
            }
        }
        return strans;
    }
};

int main()
{
    Solution s;
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF) {
        cout << s.fractionToDecimal(a, b) << endl;
    }
    return 0;
}
