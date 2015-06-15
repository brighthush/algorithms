#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return dfsMatch(s, p, 0, 0);
    }

    bool dfsMatch(const string &s, const string &p, int beg1, int beg2) {
        if(beg1==s.size() && beg2==p.size()) return true;
        if(beg1!=s.size() && beg2==p.size()) return false;
        if(beg1==s.size() && beg2!=p.size()) {
            if(beg2+1<p.size() && p[beg2+1]=='*') return dfsMatch(s, p, beg1, beg2+2);
            else return false;
        }

        if(beg2+1<p.size() && p[beg2+1] == '*') {
            for(int i=beg1; i<=s.size(); ++i) {
                bool flag = true;
                for(int j=beg1; j<i; ++j) {
                    if(check(s[j], p[beg2])==false) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    bool temp = dfsMatch(s, p, i, beg2+2);
                    if(temp) return true;
                }
            }
            return false;
        }
        else {
            if(check(s[beg1], p[beg2])) return dfsMatch(s, p, beg1+1, beg2+1);
            else return false;
        }
    }

    bool check(char ch1, char ch2) {
        if(ch2 == '.') return true;
        else if(ch1==ch2) return true;
        else return false;
    }
};

int main() {
    Solution s;
    string a, b;
    while((cin >> a >> b)) {
        cout << s.isMatch(a, b) << endl;
    }
    return 0;
}

