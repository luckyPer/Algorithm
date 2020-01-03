#include <set>
#include <iostream>

using namespace std;

/*内部自动有序 且 不包含重复元素的 容器*/
set<int> st; //一维集合

/*
    set 常用操作

        st.insert(X);   //将X 插入set 中

        it = st.find(X);    //在set中 查找元素为 X 的, 返回给迭代器

        st.erase(i);    //删除元素

        st.erase(beg, end);     //删除区间元素, 前闭后开

        st.size();  //返回set元素个数

        st.clear();     //清空set 中的所有元素
*/
set<set<int>> sn; //二维集合

int main()
{
    st.insert(1);
    st.insert(2);

    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << *it;
    }
    system("pause");
    return 0;
}
