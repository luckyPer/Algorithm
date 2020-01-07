#include <vector>
#include <iostream>

using namespace std;

int data1[5][5] = {
    {9, 0, 0, 0, 0},
    {12, 15, 0, 0, 0},
    {10, 6, 8, 0, 0},
    {2, 18, 9, 5, 0},
    {19, 7, 10, 4, 16}};
int dp_number_tower(int n)
{
    int dp[n][n];
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = data1[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n - 1; j++)
        {
            dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]) + data1[i][j];
        }
    }
    return dp[0][0];
}

int main(int argc, char const *argv[])
{
    cout << dp_number_tower(5);
    system("pause");
    return 0;
}