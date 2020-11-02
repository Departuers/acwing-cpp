#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int N=51000,M=2e5+19;
int source[6],dis[6][N],h[N],e[M],ne[M],w[M],st[N];
int idx=1,n,m;
typedef pair<int,int> PII;
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dij(int s,int *dis){
    memset(st,0,sizeof st);
    priority_queue<PII> q;
    q.push({0,s});
    dis[s]=0;
    while(q.size()){
        int u=q.top().second;q.pop();
        if(st[u])continue;
        st[u]=1;
        for(int i=h[u];i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[u]+w[i]){
                dis[j]=dis[u]+w[i];
                q.push({-dis[j],j});
            }
        }
    }
}
int dfs(int u,int start,int dist){
    if(u==6)return dist;
    int res=1e9;
    for(int i=1;i<=5;i++){
        if(!st[i]){
            st[i]=1;
            int next=source[i];
            res=min(res,dfs(u+1,i,dist+dis[start][next]));
            st[i]=0;
        }
    }
    return res;
}
int main(){
    source[0]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=5;i++)scanf("%d",&source[i]);
    int a,b,c;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    memset(dis,63,sizeof dis);
    for(int i=0;i<6;i++){
        dij(source[i],dis[i]);
    }
    memset(st,0,sizeof st);
    cout<<dfs(1,0,0)<<endl;
    return 0;
}