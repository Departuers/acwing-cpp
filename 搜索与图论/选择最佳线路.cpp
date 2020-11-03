#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int N=1010,M=20010;
int n,m,t,f,idx=1;
int h[N],e[M],ne[M],st[N],w[M],dis[N],s[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a],h[a]=idx++;
}

void spfa(){
    queue<int> q;
    memset(dis,63,sizeof dis);
    for(int i=0;i<f;i++){
        q.push(s[i]);
        dis[s[i]]=0;
    }
    while(q.size()){
        int t=q.front();q.pop();
        st[t]=0;
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                if(!st[j]){
                    st[j]=1;
                    q.push(j);
                }
            }
        }
    }
    if(dis[t]>=0x3f3f3f3f)cout<<-1<<endl;
    else cout<<dis[t]<<endl;
}
int main(){
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        memset(h,0,sizeof h);
        idx=1;
        int a,c,b;
        while(m--){
            cin>>a>>b>>c;
            add(a,b,c);
        }
        cin>>f;
        for(int i=0;i<f;i++)scanf("%d",&s[i]);
        spfa();
    }
    
    return 0;
}