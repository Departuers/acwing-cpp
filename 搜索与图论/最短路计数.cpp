#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include<cstdio>
using namespace std;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f, N = 1000010, M = 4000010, mod = 100003;
int n, m, idx = 1;
int h[N], e[M], ne[M], dis[N], cnt[N], st[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dij()
{
    memset(dis, 63, sizeof dis);
    dis[1] = 0;
    cnt[1] = 1;
    priority_queue<PII> q;
    q.push({0, 1});
    while (q.size())
    {
        int t = q.top().second;
        q.pop();
        if (st[t])
            continue;
        st[t] = 1;
        for (int i = h[t]; i; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + 1)
            {
                dis[j] = dis[t] + 1;
                cnt[j] = cnt[t];
                q.push({-dis[j],j});
            }
            else if (dis[j] == dis[t] + 1)
            {
                cnt[j] = (cnt[j]+cnt[t])%mod;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", cnt[i]);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    int a,b;
    while (m--)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dij();
    return 0;
}