#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 40010;
int n, m, root;
int h[N], e[N << 1], ne[N << 1], idx = 1, depth[N], up[N][20];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void bfs(){
    memset(depth,63,sizeof depth);
    depth[root]=1;
    depth[0]=0;
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        int t=q.front();q.pop();

        for (int i = h[t]; i; i=ne[i])
        {
            int j=e[i];
            if(depth[j]>depth[t]+1){
                q.push(j);
                depth[j]=depth[t]+1;
                up[j][0]=t;

                for(int k=1;k<=17;k++)
                    up[j][k]=up[up[j][k-1]][k-1];
            }
        }
    }
}
int lca(int a,int b){
    if (depth[a]<depth[b])
        swap(a,b);
    for (int i = 17; i >=0; i--)
    {
       if(depth[up[a][i]]>=depth[b])
            a=up[a][i];
    }
    if(a==b)return a;
    for (int i =17;i>=0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
int main(int argc, char const *argv[])
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (b == -1)
            root = a;
        else
            add(a, b),add(b,a);
    }
    bfs();
    cin>>m;
    while (m--)
    {
        cin >> a >> b;
        int p = lca(a, b);
        if (p == a)
            cout << 1 << endl;
        else if (p == b)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}