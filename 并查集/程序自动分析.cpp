#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;
const int inf = 0x3f3f3f3f, N = 2000010;
int n, m;
int p[N];
unordered_map<int, int> S;
struct node
{
    int x, y, type; //两个下标和,类型
} q[N];

//保序离散化
int get(int x)
{
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    int x, y, e;

    while (T--)
    {
        S.clear();
        n = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &e);
            q[i] = {get(x), get(y), e};
        }
        for (int i = 1; i <= n; i++)
            p[i] = i;

        for (int i = 0; i < m; i++)
        {
            if (q[i].type == 1)
            {
                x = find(q[i].x);
                y = find(q[i].y);
                p[x] = y;
            }
        }
        bool has = 0;
        for (int i = 0; i < m; i++)
        {
            if (!q[i].type)
            {
                x = find(q[i].x), y = find(q[i].y);
                if (x == y)
                {
                    has = 1;
                    break;
                }
            }
        }
        if (has)puts("NO");
        else puts("YES");
    }

    return 0;
}