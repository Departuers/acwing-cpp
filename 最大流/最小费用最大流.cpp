#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 1010, M = 20010;
int n, m, s, t, idx = 2, mincost = 0, maxflow = 0;

int h[N], e[M], ne[M], w[M], cos[M], dis[N], st[N], pre[M], cost[N];
void add(int a, int b, int c, int d)
{
    e[idx] = b;
    w[idx] = c;
    cos[idx] = d;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    memset(st, 0, sizeof st);
    memset(cost, 63, sizeof cost);
    q.push(s);
    dis[s] = inf;
    cost[s] = 0;
    while (q.size())
    {
        int v = q.front();
        q.pop();
        st[v] = 0;
        for (int i = h[v]; i; i = ne[i])
        {
            int j = e[i];
            if (cost[j] > cost[v] + cos[i] && w[i])
            {
                pre[j] = i;
                cost[j] = cost[v] + cos[i];
                dis[j] = min(dis[v], w[i]);
                if (!st[j])
                {
                    st[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    return cost[t] != inf;
}
void minflow()
{
    while (spfa())
    {
        for (int i = t; i != s; i = e[pre[i] ^ 1])
        {
            w[pre[i]] -= dis[t];
            w[pre[i] ^ 1] += dis[t];
        }
        maxflow += dis[t];
        mincost += dis[t] * cost[t];
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m >> s >> t;
    int a, b, c, d;
    while (m--)
    {
        cin >> a >> b >> c >> d;
        add(a, b, c, d), add(b, a, 0, -d);
    }
    minflow();
    cout << maxflow << " " << mincost << endl;
    return 0;
}