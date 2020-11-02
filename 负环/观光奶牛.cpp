#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010, M = 5100;
int n, m;
int wf[N], h[N], e[M], w[M], ne[M], idx = 1;
double dis[N];
int cnt[N], st[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool check(double mid)
{
    memset(cnt, 0, sizeof cnt);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = 1;
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; i; i = ne[i])
        {
            int j = e[i];
            if (dis[j] < dis[t] + wf[t] - mid * w[i])
            {
                dis[j] = dis[t] + wf[t] - mid * w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return 1;
                if (!st[j])
                {
                    st[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> wf[i];
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    double l = 0, r = 1001;
    while (r - l > 1e-4)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.2lf\n", r);
    return 0;
}