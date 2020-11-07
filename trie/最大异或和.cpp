#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 100100, M = N * 31;
int n, m;
int son[M][2], idx = 1;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = idx++;
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            res = res * 2 + !u; //所有的数左移一位
        }
        else
            p = son[p][u], res = res * 2 + u;
    }
    return res;
}
//n个数任取2个,取最大异或值,trie优化,O(nlogn)
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int res = 0, f = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f);
        insert(f);
        int t = query(f);
        res = max(res, f ^ t);
    }
    cout << res << endl;
    return 0;
}