#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
有4个物品, 最大容量为8
物体体积: 2, 3, 4, 5
物体价值: 3, 4, 5, 6

*/

int bag()
{
    int n = 4;
    int v = 8;
    vector<int> w({2, 3, 4, 5});
    vector<int> c({3, 4, 5, 6});

    int dp[n + 1][v + 1]; //前 i件物品恰好装入容量为v的背包中所能获得的最大价值

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= v; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (w[i-1] <= j)
            {   //装的下当前物品       
                dp[i][j] = max(dp[i-1][j], c[i - 1] + dp[i-1][j - w[i - 1]]);
            }
            else
            {
                //装不下, 就是取前n-1 个物品的最佳组合
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][v];
}

int main(int argc, char const *argv[])
{

    cout << bag();
    system("pause");
    return 0;
}
