#include<iostream>
using namespace std;
const int N=10010,M=50010;
int n,m,timee=0,top,idx=1,scc;
int dfn[N],low[N],stk[N],instk[N],id[N],sizee[N],dout[N];
int h[N],e[M],ne[M];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void tarjan(int u){
    low[u]=dfn[u]=++timee;
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
    if(low[u]==dfn[u]){
        ++scc;
        int y;
        do{
            y=stk[top--];
            instk[y]=0;
            sizee[scc]++;
            id[y]=scc;
        }while(y!=u);
    }
}
int main(){
    int a,b;
    cin>>n>>m;
    while(m--){
        
        cin>>a>>b;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];j;j=ne[j]){
            int k=e[j];
            a=id[i];
            b=id[k];
            if(a!=b){
                dout[a]++;
            }
        }
    }
    a=b=0;
    for(int i=1;i<=scc;i++){
        if(!dout[i]){
            a++;
            b=sizee[i];
            if(a>1){
                b=0;
                break;
                
            }
        }
    }
    cout<<b<<endl;
    return 0;
}