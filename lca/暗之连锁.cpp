#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f,N=101001,M=N*2;
int n, m,idx=1,ans;
int h[N],e[M],ne[M],w[M],depth[N],up[N][17],d[M];//差分数组
typedef pair<int, int> PII;
void bfs(){
    queue<int> q;
    memset(depth,63,sizeof depth);
    depth[0]=0;
    depth[1]=1;
    q.push(1);
    while (q.size())
    {
        int t=q.front();q.pop();
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            if(depth[j]>depth[t]+1){
                depth[j]=depth[t]+1;
                q.push(j);
                up[j][0]=t;
                for(int k=1;k<=16;k++)
                    up[j][k]=up[up[j][k-1]][k-1];
            }
        }
    }
}
/**
 * 
 * lca+树上差分
 * */
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int lca(int a,int b){
    if(depth[a]<depth[b])swap(a,b);
    for(int i=16;i>=0;i--){
        if(depth[up[a][i]]>=depth[b])
            a=up[a][i];
    }
    if(a==b)return a;
    for(int i=16;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
//d数组语义,以u为根的所有子树的和
int  dfs(int u,int fa){
    int res=d[u];
    for(int i=h[u];i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        int s=dfs(j,u);
        if(s==0)ans+=m;
        else if(s==1)ans++;
        res+=s;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    bfs();
    for(int i=0;i<m;i++){
        cin>>a>>b;
        c=lca(a,b);
        d[a]++;
        d[b]++;
        d[c]-=2;
    }
    dfs(1,-1);
    cout<<ans<<endl;
    return 0;
}