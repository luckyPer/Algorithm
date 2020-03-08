#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int cost;
    int u, v;
} E[1000];

int father[1000];
int findfather(int x)
{
    while (x != father[x])
    {
        x = father[x];
    }
    return x;
}

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

int kruskal(int n, int m)
{
    int ans = 0;
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        father[i] = i;
    }
    sort(E, E + n, cmp);
    for (int i = 0; i < n; i++)
    {
        int u = E[i].u;
        int v = E[i].v;
        int fu = findfather(u);
        int fv = findfather(v);
        if (fu != fv)
        {
            father[fu] = fv;
            num++;
            ans += E[i].cost;
            if (num == m - 1)
                break;
        }
    }
    if (num != m - 1)
    {
        return -1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{

    return 0;
}
