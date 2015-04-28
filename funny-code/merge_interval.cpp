#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const struct Interval &a, const struct Interval &b) {
    if (a.start == b.start) return a.end > b.end;
    else return a.start < b.start;
}

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n == 0) return vector<Interval>(intervals);
        
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        return ans;
        Interval cur = intervals[0];
        for(int i=1; i<n; ++i) {
            if(intervals[i].start <= cur.end) {
                if(intervals[i].end > cur.end) {
                    cur.end = intervals[i].end;
                }
                if(i == intervals.size()-1) {
                    ans.push_back(cur);
                }
            }
            else 
                ans.push_back(cur);
                cur = intervals[i];
                if(i == n-1) ans.push_back(cur);
            }
        }
        return ans;
    }
    
};

int main()
{
    Solution s;
    vector<Interval> intervals;
    iintervals.push_back(Interval(1, 3));
    vector<Interval> ans = s.merge();
    int n = ans.size();
    for(int i=0; i<n; ++i) {
        cout << ans[i].start << " " << ans[i].end << endl;
    }
    return 0;
}

