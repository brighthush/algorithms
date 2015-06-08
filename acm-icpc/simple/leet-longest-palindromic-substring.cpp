#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans("");
        for(int i=0; i<s.size(); ++i) {
            string temp = checkOdd(s, i);
            if(temp.size() > ans.size()) ans = temp;
            temp = checkEven(s, i);
            if(temp.size() > ans.size()) ans = temp;
        }
        return ans;
    }

    string checkOdd(const string &s, int mid) {
        int left = mid;
        int right = mid;
        while(left>=0 && right<s.size() && s[left]==s[right]) {
            --left; ++right;
        }
        return s.substr(left+1, right-left-1);
    }

    string checkEven(const string &s, int mid) {
        int left = mid;
        int right = mid+1;
        if(! ( right < s.size() && s[left]==s[right]) ) return string("");
        while(left>=0 && right<s.size() && s[left]==s[right]) {
            --left; ++right;
        }
        return s.substr(left+1, right-left-1);
    }
};

int main()
{
    Solution s;
    string temp;
    while(cin >> temp) {
        cout << s.longestPalindrome(temp) << endl;
    }
    return 0;
}

