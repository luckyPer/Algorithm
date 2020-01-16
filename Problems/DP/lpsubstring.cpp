#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*

banana   return: anana (len : 5)

*/

int getlpsubstringlen(string str1)
{
    vector<char> v;
    for (int i = 0; i < str1.size(); i++)
    {
        v.push_back(str1[i]);
    }

    int len = v.size();
    int dp[len][len];
    int length = 0, last = 0;
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len -1)
        {      
            dp[i][i + 1] = (v[i] == v[i + 1] ? 1 : 0);
            length = 2;
        }
    }
    for (int l = 3; l <= len; l++)
    {
        for (int i = 0; i + l - 1 < len; i++)
        {
            int j = l + i - 1;
            if (v[i] == v[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                length = l;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return length;
}

int main(int argc, char const *argv[])
{

    cout << getlpsubstringlen("bansna");
    system("pause");
    return 0;
}
