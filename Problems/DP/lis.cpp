#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getLIS()
{
    vector<int> numBersArr({1,5,-1,3});
    int len = numBersArr.size();

    int dparr[len];
    int maxN = 1;
    for (int i = 0; i < len; i++)
    {
        dparr[i] = 1;   
        for (int j = 0; j < i ; j++)
        {
            if (numBersArr[j] <= numBersArr[i] && dparr[j] + 1 > dparr[i])
            {
                dparr[i] = dparr[j] + 1;
            }
            
        }
        maxN  = max(maxN, dparr[i]);
    }

    return maxN;
}

int main(int argc, char const *argv[])
{
    cout << getLIS();
    
    system("pause");
    return 0;
}
