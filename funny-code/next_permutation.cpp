/*
 * Generate the next permutation in lexical order.
 * The algorithm is easy. from the end to the begin, find the first
 * element that you need to swap. It means when the permutation is increasing
 * from end to begin, then the first position which decrease is the element you 
 * need to swap. You choose the smallest element which larger than the element you
 * choose. After swap operation, you should sort left elments in increasing order.
 * So the algorithm is easy.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{ 
public:
    void nextPermutation(vector<int> &num) {
        int index=-1;
        int val = -1;
        int n = num.size();
        bool flag = false;
        if(n==0) return;
        for(int i=n-1; i>=0; --i) {
            if(index==-1) {
                index = i;
                val = num[i];
            } else {
                if(num[i] < val) {
                    flag = true;
                    //printf("%d %d\n", i, num[i]);
                    index = -1;
                    for(int j=i+1; j<n; ++j) {
                        if(num[j] > num[i]) {
                            if(index == -1) index = j;
                            else if(num[index] > num[j]) index = j;
                        }
                    }
                    //printf("%d %d\n", index, num[index]);
                    int temp = num[index];
                    num[index] = num[i];
                    num[i] = temp;
                    vector<int>::iterator it = num.begin();
                    for(int j=1; j<=i+1; ++j) {
                        it++;
                    }
                    sort(it, num.end());
                    break;
                } else {
                    val = num[i];
                    index = i;
                }
            }
        }
        if(!flag) sort(num.begin(), num.end());
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3); v.push_back(2); v.push_back(1);
    s.nextPermutation(v);
    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
