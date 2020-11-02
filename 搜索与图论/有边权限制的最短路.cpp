#include <iostream>
#include <cstring>
using namespace std;
const int M = 10010, N = 541;
int n, m, k;
struct edge
{
    int a, b, w;
} e[M];
int dis[N], back[N];
int blm()
{
    memset(dis, 63, sizeof dis);
    dis[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(back, dis, sizeof dis);
        for (int j = 0; j < m; j++)
        {
            int a = e[j].a, b = e[j].b, c = e[j].w;
            dis[b] = min(dis[b], back[a] + c);
        }
    }
    return dis[n];
}
int main()
{
    cin >> n >> m >> k;
    int b, c, a;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    int t = blm();
    if (t > 0x3f3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}