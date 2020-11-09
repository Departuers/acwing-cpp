#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 510, M = 1e5;
int n, m;
int p[N];
int h[N], ed[M], ne[M], w[M], idx = 1;
typedef long long ll;
struct Edge
{
    int a, b, c;
    bool flag;
    bool operator<(const Edge &ed)
    {
        return c < ed.c;
    }
} e[M];
int m1[N][N], m2[N][N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void add(int a, int b, int c)
{
    w[idx] = c;
    ed[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u, int fa, int r1, int r2, int *s1, int *s2)
{
    s1[u] = r1, s2[u] = r2;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = ed[i];
        if (fa != j)
        {
            int t1 = t1, t2 = r2;
            if (w[i] > t1)
                t2 = t1, t1 = w[i];
            else if (w[i] > t2 && w[i] != t1)
                t2 = w[i];
            dfs(j, u, t1, t2, s1, s2);
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        e[i] = {a, b, w, false};
    }
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(e, e + m);

    ll sum = 0, res = 1e9;
    for (int i = 0; i < m; i++)
    {
        a = find(e[i].a), b = find(e[i].b);
        if (a != b)
        {
            p[a] = b;
            e[i].flag = 1;
            sum += e[i].c;
            add(e[i].a, e[i].b, e[i].c);//要求树上任意两点的路径最大值和次大值
            add(e[i].b, e[i].a, e[i].c);
        }
    }
    for (int i = 1; i <= n; i++)
        dfs(i, -1, -1, -1, m1[i], m2[i]);
    
    return 0;
}
