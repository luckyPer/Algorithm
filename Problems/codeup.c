#include <stdio.h>
#include <stdlib.h>

#define maxsize 100000

int main(int argc, char const *argv[])
{

    //printf(" result : %d ", getCallatz(3));
    //setSchoolInfor_B1032(2);
    drawSquare(10, 'a');
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
 *@description: codeup 1928 日期差值
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-12-27 19:11:49
*/

