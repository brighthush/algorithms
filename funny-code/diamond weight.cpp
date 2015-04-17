/*
要求仅仅使用四个砝码和一个天平，如何称出[1, 40]区间内的任意重量？
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool check(vector<int> &weights, int bounder=40);

int cnt = 0;

void dfs(int index, vector<int> &weights, vector< vector<int> > &ans, int bounder=40)
{
    if(index == 4)
    {
        bool flag = check(weights);
        if(flag)
        {
            ans.push_back(weights);
            for(int i=0; i<weights.size(); ++i)
                cout << weights[i] << " ";
            cout << endl;
        }
        return ;
    }
    for(int i=1; i<=bounder; ++i)
    {
        weights.push_back(i);
        dfs(index+1, weights, ans);
        weights.pop_back();
    }
}

//给定任意砝码的情况，计算这些砝码能表示的重量
//这是一个动态规划问题，dp[i][j]表示前i个砝码，能否表示j的重量s
bool check(vector<int> &weights, int bounder)
{
    int n = weights.size();
    int **dp = (int **)malloc((n+1) * sizeof(int *));
    for(int i=0; i<=n; ++i)
    {
        dp[i] = (int *)malloc((bounder+1) * sizeof(int));
        memset(dp[i], 0, (bounder+1)*sizeof(int));
    }

    dp[0][0] = 1;
    for(int i=1; i<=n; ++i)
    {
        int weight = weights[i-1];
        for(int j=0; j<=bounder; ++j)
        {
            if(dp[i-1][j]==0)
                continue;
            dp[i][j] = 1;
            if(j+weight<=bounder)
                dp[i][j+weight] = 1;
            if(j-weight>=0)
                dp[i][j-weight] = 1;
        }
    }

    bool flag = true;
    for(int i=1; i<=bounder; ++i)
    {
        if(dp[n][i] == 0)
        {
            flag = false;
            break;
        }
     }


    for(int i=0; i<=n; ++i)
        free(dp[i]);
    free(dp);
    if(flag)
        return true;
    return false;
}

//return the vector in which represents the side the put
// -1 put the corresponding weight on the left side
// 0  not use this weight
// 1  put the corresponding weight on the right side
bool represent(vector<int> &weightSide, vector<int> &weights, int index, int value)
{
    if(value < 0)
        return false;
    if(index == weights.size())
    {
        if(value == 0)
        {
            return true;
        }
        return false;
    }
    for(int i=-1; i<=1; ++i)
    {
        weightSide.push_back(i);
        if(represent(weightSide, weights, index+1, value-i*weights[index]))
            return true;
        weightSide.pop_back();
    }
    return false;
}

int main()
{
    freopen("out", "w", stdout);
    int temp[] = {1,3, 9, 27};
    vector<int> weights(temp, temp+4);
    for(int i=1; i<=40; ++i)
    {
        vector<int> weightSide;
        represent(weightSide, weights, 0, i);
        cout << "value " << i << endl;
        cout << "    ";
        for(int j=0; j<weightSide.size(); ++j)
            cout << weightSide[j] << " ";
        cout << endl;
    }
    return 0;
}
