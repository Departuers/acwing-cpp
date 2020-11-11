#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f, N = 1541;
int n, m, idx, h[N], e[N], ne[N], f[N][2], st[N];
typedef pair<int, int> PII;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
    f[u][0] = 0, f[u][1] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][1], f[j][0]);
    }
}
int main(int argc, char const *argv[])
{
    int cnt, a, b;
    while (scanf("%d", &n) == 1)
    {
        idx = 0;
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++)
        {
            scanf("%d:(%d)", &a, &cnt);
            while (cnt--)
            {
                scanf("%d", &b);
                add(a, b);
                st[b] = 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (!st[i])
            {
                dfs(i);
                cout << min(f[i][1], f[i][0]) << endl;
                break;
            }
        }
    }

    return 0;
}