#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

/*  二分问题  */

// 二分查找
int BinarySearch(int arr[], int low, int high, int key)
{
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// 计算根号二 的近似值, 精确到1*10^-5
double fun(double x)
{
    return x * x;
}

double calculate()
{
    double eps = 1e-5;
    double low = 1,
           high = 2,
           mid = 0;
    while (low - high > eps)
    {
        mid = (low + high) / 2;
        if (fun(mid) > 2)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return mid;
}

//装水问题, 侧面积为半圆形
const double PI = acos(-1);

//计算面积比值 下水面 -- 半圆形
double farea(double R, double h)
{
    double s1, s2;
    double alpha = acos((R - h) / R);

    s2 = PI * R * R;
    s1 = R * R * alpha / 2 - sqrt(R * R - (R - h) * (R - h)) * (R - h) / 2;
    return s1 / s2;
}

/*
 *@description: 
 *@params1: 半径
 *@params2: 下圆面积 与 半圆的比值
 *@return: 
 *@date: 2019-12-31 20:02:07
*/
double solve(double R, double r)
{
    double eps = 1e-5;
    double low = 0,
           high = R,
           mid;
    while (low - high > eps)
    {
        mid = (low + high) / 2;
        if (farea(R, mid) > r)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
}

//快速幂
//递归思想 求 a^b % m
typedef long int li;
li QuickPow(li a, li b, li m)
{
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 0)
    {
        li m1 = QuickPow(a, b / 2, m);
        return m1 * m1 % m;
    }
    else
    {
        return a * QuickPow(a, b - 1, m) % m;
    }
}

//迭代快速幂
li QuickBinaryPow(li a, li b, li m)
{
    li res = 0;
    while (b > 0)
    {
        if (b & 1) //是否为奇数
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >> 1;
    }
    return res;
}