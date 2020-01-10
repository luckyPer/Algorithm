#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*

输入7;  拿 i = 3;

        3左边的二叉排序树个数, 与3右边的二叉排序树个数 的笛卡尔积


        动态转移方程: G(i) = ∑ f(j-1)  * f(i-j)

*/

int numTrees(int n)
{
    int G[n+1];
    for (int i = 0; i <= n; ++i)
    {    
        G[i] = 0;
    }
    G[0] = 1;
    G[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}

int main(int argc, char const *argv[])
{

    cout << numTrees(5);
    system("pause");
    return 0;
}
