#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 100000

int main(int argc, char const *argv[])
{

    //printf(" result : %d ", getCallatz(3));
    //setSchoolInfor_B1032(2);
    //drawSquare(10, 'a');
    printf("%d", getDifference(20181214, 20191214));
    system("pause");
    return 0;
}

/*
 *@description: 卡拉兹猜想 
 *@return: step
 *@date: 2019-12-27 15:31:26
*/
int getCallatz(int n)
{
    int step = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = (3 * n + 1) / 2;
        }
        step++;
    }
    return step;
}

/*
 *@description: B1032 统计学校数据
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-27 18:08:11
*/
void setSchoolInfor_B1032(int n)
{
    int school[maxsize] = {0};
    int num, score;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &num, &score);
        school[num] += score;
    }
    int k = 0;
    int maxScore = -1;
    for (int i = 0; i < n; i++)
    {
        if (school[i] > maxScore)
        {
            maxScore = school[i];
            k = i;
        }
    }
    printf("%d  : %d ", k, maxScore);
}

/*
 *@description: codeup 1934 find X
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-27 18:28:13
*/
int findEle(int n, int key)
{
    int array[n];
    int i = 0;
    while (array[i] != key)
    {
        i++;
    }
    if (i >= n)
    {
        return -1;
    }
    return i;
}

/*
 *@description: PAT B1036 正方形
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-27 18:47:21
*/
void drawSquare(int n, char a)
{
    int row = n / 2;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == row - 1 || j == 0 || j == n - 1)
            {
                printf("%c", a);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/*
 *@description: codeup 1928 日期差值  时间格式   YYYY MM DD
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-27 19:11:49
*/
bool isLeap(int date)
{
    int year = getYear(date);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    return false;
}

int month[13][2] = {
    //平闰年
    {0, 1},
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
};
int getYear(int date)
{
    return date / 10000;
}

int getMonth(int date)
{
    return date % 10000 / 100;
}

int getDay(int date)
{
    return date % 100;
}

int getDifference(int date1, int date2)
{
    int Difference = 0;

    int d1 = getDay(date1);
    int d2 = getDay(date2);
    int m1 = getMonth(date1);
    int m2 = getMonth(date2);
    int y1 = getYear(date1);
    int y2 = getYear(date2);
    while (d1 < d2 || m1 < m2 || y1 < y2)   //让小的日期的天数自增, 直到等于对应month[m1] 的天数, 在让m1自增, d1置为1; 当m1等于13的时候
    //y1 自增, m1 置为1
    {
        d1++;
        if (d1 == month[m1][isLeap(y1)] + 1)
        {
            m1++;
            d1 = 1;
        }
        if (m1 == 13)
        {
            y1++;
            m1 = 1;
        }

        Difference++;
    }
    return Difference;
}