#include <vector>
#include <iostream>

using namespace std;

vector<int> nums({-2,11,-4,13,-5,-2});

int getMax()
{
    int len = nums.size();
    int dp[len];
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < len; i++)
    {
        dp[i] = max((nums[i]+dp[i-1]), nums[i]) ;
        if (dp[i] > maxSum)
        {
            maxSum = dp[i];
        }
        
    }
    
    return maxSum;
}

int main(int argc, char const *argv[])
{
    cout << getMax();
    system("pause");
    return 0;
}

