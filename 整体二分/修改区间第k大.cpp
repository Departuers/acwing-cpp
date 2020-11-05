#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 100100, M = N * 2;
int n, m, idx;
struct node
{
    int op; //操作类型1是修改,2是查询
    int x, y, k;
    int id;
};
typedef long long ll;
node q[M], lq[M], rq[M];
int tr[N], ans[N], now[N];
void add(int x, int v)
{
    for (; x <= n; x += (x & -x))
        tr[x] += v;
}
ll ask(int x)
{
    long r = 0;
    for (; x; x -= (x & -x))
        r += tr[x];
    return r;
}
void solve(int vl, int vr, int ql, int qr)
{
    if (ql > qr)
        return;
    if (vl == vr)
    {
        for (int i = ql; i <= qr; i++)
            if (q[i].op == 2)
                ans[q[i].id] = vl;
        return;
    }
    int mid = vl + vr >> 1, l = 0, r = 0;
    for (int i = ql; i <= qr; i++)
    {
        if (q[i].op == 1)
        {
            if (q[i].y <= mid)
            {

                lq[++l] = q[i];
            }
            else
                add(q[i].x, q[i].k),
                    rq[++r] = q[i];
        }
        else
        {
            ll tem = ask(q[i].y) - ask(q[i].x - 1);
            if (q[i].k <= tem)
                rq[++r] = q[i];
            else
                q[i].k -= tem,
                    lq[++l] = q[i];
        }
    }
    for (int i = ql; i <= qr; i++)
        if (q[i].op == 1 && q[i].y > mid)
            add(q[i].x, -q[i].k);

    for (int i = 1; i <= l; i++)
        q[ql + i - 1] = lq[i];
    for (int i = 1; i <= r; i++)
        q[ql + l + i - 1] = rq[i];
    solve(vl, mid, ql, ql + l - 1), solve(mid + 1, vr, ql + l, qr);
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int x, y, z;
    char op[2];
    for (int i = 1; i <= m; i++)
    {
        ans[i] = -1;
        scanf("%s", op);
        scanf("%d%d", &x, &y);
        if (*op == 'C')
        {
            if (now[x] != 0)
            {
                q[++idx] = {1, x, now[x], -1, -3};
                q[++idx] = {1, x, y, 1, -3};
                now[x] = y;
            }
            else
            {
                q[++idx] = {1, x, y, 1, -3};
                now[x] = y;
            }
        }
        else
        {
            q[++idx] = {2, x, y, 8, i};
        }
    }
    solve(0, 1e9 + 11, 1, idx);

    for (int i = 1; i <= m; i++)
    {
        if (ans[i] != -1)
            printf("%d\n", ans[i]);
    }
    return 0;
}