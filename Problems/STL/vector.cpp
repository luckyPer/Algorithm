#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> vi;  //变长一维数组
/*
    1)下标访问
        vi[0];
    2)迭代器访问
        vector<int>::iterator it;
        for (int i = 0; i < 5; i++)
        {
            vi.push_back(i);    //在vector后面添加一个元素x
        }
        it = vi.begin();    //取vi的首地址
        for (int i = 0; i < 5; i++)
        {
            cout << it[i];
        }

        it = vi.end();  //取尾元素的下一地址

    3) 常用操作
        vi.pop_back();  //删除vector的尾元素

        vi.size();  //vector 中元素的个数
        
        vi.clear(); //清空vector中的所有元素

        vi.insert(i, x);  //vector i处插入一个元素x

        vi.erase(i);    //删除vector  i 处的元素

        vi.erase(beg, end);     //删除begin 到 end 的元素  前闭后开

*/

vector<vector<int> > vn;    //变长二维数组

int main(int argc, char const *argv[])
{
    vector<int>::iterator it;
    for (int i = 0; i < 5; i++)
    {
        vi.push_back(i);
    }
    it = vi.begin();    //取vi的首地址
    for (int i = 0; i < 5; i++)
    {
        cout << it[i];
    }
    
    system("pause");
    return 0;
}
