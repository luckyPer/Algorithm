#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
longest common subsequence

子序列可以不连续

动态转移方程:   dp[i][j] = dp[i-1][j-1] + 1  s1[i] == s2[j]
               dp[i][j] = max(dp[i-1][j], dp[i][j-1])  s1[i] != s2[j]
*/

int getLCS(vector<string> s1, vector<string> s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int dp[len1][len2];

    for (int i = 0; i < len1; i++)
    {
        dp[i][0] = (s1[i] == s2[0]);
    }

    for (int i = 0; i < len2; i++)
    {
        dp[0][i] = (s1[0] == s2[i]);
    }
    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[len1 - 1][len2 - 1];
}

int main(int argc, char const *argv[])
{
    vector<string> s1({"s", "a", "d", "s", "t", "o", "r", "y"});
    vector<string> s2({"a", "d", "m", "i", "n", "s", "o", "r", "r", "y"});

    // vector<string> s1({"s", "a", "d", "s", "t"});
    // vector<string> s2({"a", "d", "m", "i"});
    cout << getLCS(s1, s2);
    system("pause");
    return 0;
}
