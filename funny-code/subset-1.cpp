// Given an unsorted set, how to enumerate all the subsets of this set.
// The algorithm is simple, get all subset of a fixed size, than enumerate the size.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector< vector<int> > ans;
        vector<int> line;
        ans.push_back(vector<int>());
        for(int i=1; i<=S.size(); ++i)
            dfs(ans, line, i, 0, S.size(), S);
        //int n = ans.size();
        //printf("%d\n", n);
        //for(int i=0; i<n; ++i)
        //{
        //    int m = ans[i].size();
        //    for(int j=0; j<m; ++j)
        //        printf("%d ", ans[i][j]);
        //    printf("\n");
        //}
        return ans;
    }

    void dfs(vector< vector<int> > &ans, vector<int> &line, const int &len, \
            int cur, const int &n, vector<int> &array) {
        if(line.size() == len) {
            vector<int> l(line);
            ans.push_back(l);
            return ;
        }
        if(cur == n) return;

        int val = array[cur];
        line.push_back(val);
        dfs(ans, line, len, cur+1, n, array);
        line.pop_back();
        dfs(ans, line, len, cur+1, n, array);
    }

};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3), v.push_back(2), v.push_back(1);
    s.subsets(v);
    return 0;
}

