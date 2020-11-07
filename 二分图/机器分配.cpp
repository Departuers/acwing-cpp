#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 110, M = N * N / 2;
int n, m, idx = 1, k;
int h[N], e[M], ne[M], st[M], match[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x, int tag)
{
    if (st[x] == tag)
        return 0;
    st[x] = tag;
    for (int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];
        if (match[j] == 0 || find(match[j], tag))
        {
            match[j] = x;
            return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int t, a, b;
    while (scanf("%d", &n), n)
    {
        scanf("%d%d", &m, &k);
        memset(h, -1, sizeof h);
        idx = 0;
        memset(st, 0, sizeof st);
        memset(match, 0, sizeof match);
        while (k--)
        {
            cin >> t >> a >> b;
            if (!a || !b)
                continue;
            add(a, b);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (find(i, i))
                res++;
        }
        cout << res << endl;
    }
    return 0;
}