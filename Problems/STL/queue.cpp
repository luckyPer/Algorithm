#include <iostream>
#include <queue>

using namespace std;



void test()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i); // 0,1,2,3,4;
    }
}

int main(int argc, char const *argv[])
{
    queue<int> q;

    q.push(1); //添加一个元素
    q.front();//获得队首元素
    q.back();//获得队尾元素
    q.pop();//出队
    if(q.empty()){} //判断队列是否为空
    q.size();//len
    return 0;
}
