#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 101010, M = N << 3;
int n, m, idx = 1;
int h[N], e[M], ne[M], st[M], match[M];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs(int u, int tag)
{
    if (st[u] == tag)
        return 0;
    st[u] = tag;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (match[j] == 0 || dfs(match[j],tag))
        {
            match[j] = u;
            return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);//只能加单向边
    }
    int res = 0;
    for (int i = 1; i <= n1; i++)
    {
        if (dfs(i, i))
            res++;
    }
    cout << res << endl;

    return 0;
}
