#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> countBits(int num)
{
    vector<int> numBersArr;
    numBersArr.push_back(0);
    numBersArr.push_back(1);
    int bitcount = 0;
    int i = 0;
    for (int j = 2; j <= num; j++)
    {
        i = j;
        bitcount = 0;
        if (i % 2 != 0)
        {
            bitcount = 1 + numBersArr[i / 2];
        }
        else
        {
            bitcount +=  numBersArr[i / 2];
        }
        numBersArr.push_back(bitcount);
    }

    return numBersArr;
}

int main(int argc, char const *argv[])
{
    vector<int> numBersArr = countBits(2);
    for (int i = 0; i < numBersArr.size(); i++)
    {
        cout << numBersArr[i] << "\n";
    }
    system("pause");
    return 0;
}
