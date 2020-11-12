#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=500100,M=N<<1;
int n,idx=1, m,root,depth[N],h[N],e[M],ne[M],up[N][20];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void bfs(){
    memset(depth,63,sizeof depth);
    queue<int> q;
    q.push(root);
    depth[0]=0;
    depth[root]=1;
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
                for(int k=1;k<=19;k++)
                    up[j][k]=up[up[j][k-1]][k-1];
            }
        }
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b])swap(a,b);
    for(int i=19;i>=0;i--){
        if(depth[up[a][i]]>=depth[b])
            a=up[a][i];
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
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
    scanf("%d%d%d", &n, &m, &root);
    int a,b;
    for (int i = 0; i < n-1; i++)
    {
       scanf("%d%d", &a, &b);
        add(b,a);
        add(a,b);
    }
    bfs();
    while (m--)
    {
         scanf("%d%d", &a, &b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}