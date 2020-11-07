#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 10010, M = 201000;
int n, m, s, t;
int h[N], e[M], f[M], ne[M], idx = 2;
int d[N], cur[N];
void add(int a, int b, int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool bfs()
{
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(s);
    d[s] = 0;
    cur[s] = h[s];
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1 && f[i])
            {
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if (j == t)
                    return 1;
                q.push(j);
            }
        }
    }
    return 0;
}
int find(int u, int limit)
{
    if (u == t)
        return limit;
    int flow = 0;
    for (int i = cur[u]; i && flow < limit; i++)
    {
        cur[u] = i;
        int j = e[i];
        if (d[j] = d[u] + 1 && f[i])
        {
            int t = find(j, min(f[i], limit));
            if (!t)
                d[j] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}
int dinic()
{
    int r = 0, flow;
    while (bfs())
    {
        while (flow = find(s, inf))
        {
            r += flow;
        }
    }
    return flow;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, 0);
    }
    printf("%d\n", dinic());
    return 0;
}