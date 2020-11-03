#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;
const int N = 20010, M = N * 2;
typedef pair<int, int> PII;
vector<PII> query[N];
int h[N], e[M], ne[M], w[M], idx = 1, st[N], dis[N], res[N], p[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx]=c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void dfs(int u, int fa)
{
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if(j==fa)continue;
        dis[j] = dis[u] + w[i];
        dfs(j, u);
    }
}
void tarjan(int u)
{
    st[u] = 1;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            tarjan(j);
            int ra = find(j), rb = find(u);
            if (ra != rb)
            {
                p[ra] = rb;
            }
        }
    }
    for (PII q : query[u])
    {
        int y = q.x, id = q.y;
        if (st[y] == 2)
        {
            int anc = find(y);
            res[id] = dis[u] + dis[y] - dis[anc] * 2;
        }
    }
    st[u] = 2;
} 
int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
        p[i] = i;

    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a != b)
        {
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    }
    dfs(1, -1);
    tarjan(1);
    for (int i = 0; i < m; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
