#include <vector>
#include <iostream>

using namespace std;

vector<int> v({3, 34, 4, 12, 5, 2});

bool rec_subset(int res, int i)
{
    if (res == 0)
    {
        return true;
    }
    if (i == 0)
    {
        return res == v[i];
    }
    else if (v[i] > res)
    {
        return rec_subset(res, i - 1);
    }
    else
    {
        return rec_subset(res - v[i], i - 1) || rec_subset(res, i - 1);
    }
}

bool dp_subset(int res)
{
    int a, b = 0;
    int n = v.size();
    int m = res + 1;
    int subset[n][m];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i] > res)
            {
                subset[i][j] = subset[i-1][j]; 
            }
            else
            {
                subset[i][j] = subset[i-1][j] || subset[i-1][j-v[i]];
            }            
        }
    }
    return subset[n-1][m-1];
}

int main(int argc, char const *argv[])
{
    cout << dp_subset(9);
    system("pause");
    return 0;
}