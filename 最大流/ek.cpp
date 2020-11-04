#include <iostream>
#include<cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f,N=1010,M=20010;
int n, m,s,t,idx=2;
int h[N],e[M],ne[M],w[M],dis[N],st[N],pre[M];
bool bfs(){
    queue<int> q;
    memset(st,0,sizeof st);
    dis[s]=inf;
    q.push(s);
    while (q.size())
    {
        int v=q.front();q.pop();
        for (int i = h[v]; i ; i=ne[i])
        {
            int j=e[i];
            if(!st[j]&&w[i]){
                dis[j]=min(dis[v],w[i]);
                st[j]=1;
                pre[j]=i;
                q.push(j);
                if(j==t)return 1;
            }
        }
    }
    return 0;
}
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int ek(){
    int r=0;
    while(bfs()){
        r+=dis[t];
        for (int i = t; i !=s; i=e[pre[i]^1])
        {
            w[pre[i]]-=dis[t];
            w[pre[i]^1]+=dis[t];
        }
    }
    return r;    
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    s=1;
    int a,b,c;
    while (m--)
    {
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,0);
    }
    cout<<ek()<<endl;
    return 0;
}