#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*简单贪心*/


/*
 *@description: 月饼问题
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-30 22:10:58
*/
double *permoneyCake(int count)
{
    double money[count],
            weight[count];
    double *permoney = new double;
    for (int i = 0; i < count; i++)
    {
        //cin >> weight[i]  >>money[i];
        weight[i] = 4;
        money[i] = 2;
        permoney[i] = weight[i]/money[i];
    }
    sort(permoney, permoney + count);    
    return permoney;
}

int main()
{
    double *permoney = permoneyCake(1);
    for (int i = 0; i < 1; i++)
    {
        cout << *(permoney + i) << "\n";
    }
    system("pause");
    return 0;
}


