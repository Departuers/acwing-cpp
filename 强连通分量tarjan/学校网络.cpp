#include<iostream>

using namespace std;
int n;
const int N=10190;
int h[N],e[N],ne[N],idx=1,dfn[N],low[N],instk[N],stk[N];
int din[N],dout[N],timee,top,scc=0,id[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++timee;
    stk[++top]=u;
    instk[u]=1;
    for(int i=h[u];i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }else if(instk[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }
    if(dfn[u]==low[u]){
        int y;
        ++scc;
        do{
            y=stk[top--];
            id[y]=scc;
            instk[y]=0;
        }while(y!=u);
    }
}
int main(){
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        while(cin>>x,x){
            add(i,x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    int a,b;
    for(int i=1;i<=n;i++){
        for(int j=h[i];j;j=ne[j]){
            int k=e[j];
            a=id[i];
            b=id[k];
            if(a!=b){
                din[b]++;
                dout[a]++;
            }
        }
    }
    a=b=0;
    for(int i=1;i<=scc;i++){
        if(!din[i])a++;
        if(!dout[i])b++;
    }
    cout<<a<<endl;
    if(scc==1)cout<<0<<endl;
    else cout<<max(a,b);
    return 0;
}