#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 500010, M = N << 2;
int ans[N], st[N];
int n, m, root, p[N], h[N], rh[N], e[M], ne[M], id[M], idx = 1;
void add(int h[], int a, int b, int c)
{
    e[idx] = b;
    id[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int find(int a)
{
    if (p[a] != a)
        p[a] = find(p[a]);
    return p[a];
}
void tarjan(int u, int fa)
{
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            tarjan(j, u);
            st[j] = 1;
            int ra = find(j), rb = find(u);
            if (ra != rb)
                p[ra] = rb;
        }
    }
    for (int i = rh[u]; i; i = ne[i])
    {
        int j = e[i];
        if (st[j])
        {
            ans[id[i]] = find(j);
        }
    }
}
int main(int argc, char const *argv[])
{
    for (int i = 1; i < N; i++)
        p[i] = i;
    cin >> n >> m >> root;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        add(h, a, b, -1);
        add(h, b, a, -1);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        add(rh, a, b, i);
        add(rh, b, a, i);
    }
    tarjan(root, -1);
    for (int i = 0; i < m; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
