#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 31000;
int n, m;
int p[N], s[N], d[N];
int find(int x)
{
    if (x != p[x]){
        int root=find(p[x]);
        d[x]+=d[p[x]];
        p[x]=root;
    }
    return p[x];
}
int main(int argc, char const *argv[])
{
    scanf("%d", &m);
    for (int i = 0; i < N; i++)
        p[i] = i, s[i] = 1;
    int a, b;
    char op[2];
    while (m--)
    {
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M')
        {
            int pa = find(a), pb = find(b);
            d[pa] = s[pb];
            s[pb] += s[pa];
            p[pa] = pb;
        }
        else
        {
            int pa = find(a), pb = find(b);
            if (pa != pb)
                puts("-1");
            else
                printf("%d\n", max(abs(d[a] - d[b]) - 1, 0));
        }
    }
    return 0;
}