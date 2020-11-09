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
const int inf = 0x3f3f3f3f, N = 1010;
int n, m, root;
int h[N], idx = 1, e[N], ne[N], v[N], w[N], f[N][N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
    for (int i = h[u]; i; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        for (int j = m - v[u]; j >= 0; j--)
        {
            for (int k = 0; k <= j; k++)
            {
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
            }
        }
    }
    for (int i = m; i >= v[u]; i--)
        f[u][i] = f[u][i - v[u]] + w[u];
    for (int i = 0; i < v[u]; i++)
        f[u][i] = 0;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int c;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i] >> c;
        if (c == -1)
            root = i;
        else
            add(c, i);
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}