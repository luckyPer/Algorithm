#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>


using namespace std;

map<string,int> m;
//  key , val
map<vector<int>, set<string> > m2;

/*
1. 访问
        m['key']
    迭代访问
        map<string, int>::iterator it = m.begin();
            it->first;  //key的内容
            it->seconde;    //val 的内容

2. it = m.find('key');  //返回为key 的映射的迭代器 

3. m.erase(it);     参数为迭代器
    m.erase('key')

4. m.size()

map 的键和值是唯一的



*/

