#include <iostream>
#include <string>

using namespace std;


string str = "abcd";
    /*
    1.访问
        1) 下标访问 
                str[0];
        2)迭代访问
                string:: iterator it = str.begin();

    2. 比较符: 比较规则为字典

    3. str.length();/str.size(): 返回string的长度

    4. str.inser(i, X); i 号位插入X 元素
       str.insert(str.begin() + 3, str2.begin(), str.end());
                在str的3号位 插入 str2

    5. erase(str.begin()+2);  删除2号位
       erase(str.begin()+1, str.begin()+3);     删除1 到3号位
       erase(pos, len);     erase(3, 3);    删除从3号位的2个字符

    6. str.clear()  清空 str

    7. str.substr(pos, len);    返回从pos位开始,长度为len 的子串

    8. str.find(str2)       
        str.find(str3,  pos)
    
    9. str.replace(pos, len ,str2)
    */
   

int main(int argc, char const *argv[])
{
    str.erase(str.begin()+2);
    cout << str;
    system("pause");
    return 0;
}
