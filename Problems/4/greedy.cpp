#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*简单贪心*/

/*
 *@description: 月饼问题
 求出月饼的单价, 按照单价降序排列. 
 如果需求小于 库存, 最高利益+=就为 单价 乘以 需求
 若需求大于 库存, 最高利益+=总价
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-30 22:10:58
*/
struct mooncake
{
    double money;  //总价
    double weight; //库存量
    double price;  //单价
} cake[10];

//按单价排序
bool comp(mooncake a, mooncake b)
{
    return a.price > b.price;
}

mooncake *permoneyCake(int count)
{
    for (int i = 0; i < count; i++)
    {
        cin >> cake[i].weight >> cake[i].money;
        cake[i].price = cake[i].money / cake[i].weight;
    }
    sort(cake, cake + count, comp);

    return cake;
}

void getHighBenefit(double demand, int count)
{
    mooncake *permoney = permoneyCake(count);
    int i = 0;
    double highBenefit = 0.0;
    while (demand > 0)
    {
        if (permoney[i].weight > demand)
        {
            highBenefit += permoney[i].price * demand;
            demand = 0;
        }
        else
        {
            highBenefit += permoney[i].money;
            demand -= permoney[i].weight;
        }
        i++;
    }
    cout << highBenefit;
}

// int main()
// {
//     int count = 3;
//     int demand = 20;
//     getHighBenefit(demand, count);
//     system("pause");
//     return 0;
// }

/*
 *@description: 组个最小数 <数字0-9 , 组成任意小的数字, 但首位不能是0. 输入数字中必包含至少一个非零数字>
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-31 14:02:32
*/
int num[10] = {
    2, 2, 0, 0, 0, 3, 0, 0, 1, 0};
void getSmallestNum()
{
    for (int i = 1; i < 10; i++)
    {
        if (num[i] != 0)
        {
            num[i] -= 1;
            cout << i;
            break;
        }
    }
    int i = 0;
    while (i < 10)
    {
        if (num[i] == 0)
        {
            i++;
        }
        else
        {
            cout << i;
            num[i] -= 1;
        }
    }
}

/*   区间贪心   */
// 区间不相交问题, 尽可能多的选择开区间

//1. I2包含I1区间, 则选择 I1区间
//2. 所有区间左端点 从小到大排序, 选择结束区间最早的(y)
/*
 *@description: 
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-31 14:40:00
*/

#define max 4
struct intevel
{
    int x, y; //区间左右端点
} I[max];

bool cop(intevel a, intevel b)
{
    return a.y < b.y;
}
// 优先选择 右端点最小的区间
void arrange()
{
    for (int i = 0; i < max; i++)
    {
        cin >> I[i].x >> I[i].y;
    }
    sort(I, I + max, cop);
    int i = 0;
    int last = I[0].y;
    while (i < max)
    {
        if (I[i].x < last)
        {
            last = I[i].y;
            cout << "(" << I[i].x << "," << I[i].y << ")\n";
        }
        i++;
    }
}

// 区间选点问题: 求最少需要确定多少个点, 才能使每个闭区间都至少存在一个点

//十分相似于前一问, 选择的点为 最早结束的右区间

//贪心 算法: 由局部最优策略来推得全局最优结果,且无后效性
