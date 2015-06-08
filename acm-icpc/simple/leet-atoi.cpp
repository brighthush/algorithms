#include <iostream>
#include <climits>

using namespace std;

typedef long long LL;

class Solution {
public:
    int myAtoi(string str) {
        str = getStr(str);
        //cout << str << endl;
        if(str.size() == 0) return 0;

        if(!checkValid(str)) return 0;
        
        string sstr;
        if(str[0] == '-' || str[0] == '+') sstr = str.substr(1, str.size()-1);
        else sstr = str;

        int ans = 0;
        for(int i=0; i<sstr.size(); ++i) {
            if(str[0]=='-') {
                int temp = '0' - sstr[i];
                if(ans < ((INT_MIN-temp)/10)) return INT_MIN;
                ans = ans * 10 + ('0' - sstr[i]);
                
                if(ans > 0) return INT_MIN;
            }
            else {
                int temp = sstr[i] - '0';
                if(ans > ((INT_MAX - temp) / 10)) return INT_MAX;
                ans = ans * 10 + (sstr[i] - '0');
            }
            //ans = ans * 10 + (sstr[i] - '0');
            //if(str[0]=='-') { if(0-ans < (LL)INT_MIN) return INT_MIN; }
            //else { if(ans > (LL)INT_MAX) return INT_MAX; }
        }
        return ans;
    }

    string getStr(const string &str)
    {
        int i = 0;
        while(i < str.size() && str[i] == ' ') {
            i++;
        }
        if(i == str.size())
            return string("");
        int j = i;
        if(str[i]=='+' || str[i]=='-' || (str[i]>='0' && str[i]<='9'))
            ++i;
        else
            return str.substr(j, i-j);
        while(i<str.size() && (str[i]>='0' && str[i]<='9')) {
            i++;
        }
        return str.substr(j, i-j);
    }

    bool checkValid(const string &str) {
        int beg = 0;
        if(str[beg] == '+' || str[beg] == '-' || (str[beg]>='0' && str[beg]<='9')) beg++;
        else return false;
        while(beg < str.size()) { 
            if(str[beg]>='0' && str[beg]<='9') { ++beg; continue; }
            else return false;
        }
        return true;
    }

};

int main()
{
    Solution s;
    cout << s.myAtoi("-2147483648") << endl;
    cout << s.myAtoi("  -0012a42") << endl;
    cout << s.myAtoi("    10522545459") << endl;
    return 0;
}
