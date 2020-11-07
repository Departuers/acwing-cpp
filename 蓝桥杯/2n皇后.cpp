#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, ans = 0;
int a[110][110];
int posw[110], posb[110];
bool checkb(int cur, int j)
{
    posb[cur] = j;
    for (int i = 1; i < cur; i++)
    {
        if (posb[i] == posb[cur] || abs(i - cur) == abs(posb[i] - posb[cur]))
            return false;
    }
    return true;
}
bool checkw(int cur, int j)
{
    posw[cur] = j;
    for (int i = 1; i < cur; i++)
    {
        if (posw[i] == posw[cur] || abs(i - cur) == abs(posw[i] - posw[cur]))
            return false;
    }
    return true;
}
void dfs_white(int u)
{
    if (u == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (posb[u] == i)
            continue;
        if (!a[u][i])
            continue;

        if (checkw(u, i))
        {
            dfs_white(u + 1);
        }
    }
}
void dfs_black(int u)
{
    if (u == n + 1)
    {
        dfs_white(1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!a[u][i])
            continue;

        if (checkb(u, i))
            dfs_black(u + 1);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs_black(1);
    cout << ans << endl;
    return 0;
}