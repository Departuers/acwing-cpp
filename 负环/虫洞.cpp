#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=510,M=5210;
int n,m,t;
int h[N],e[M],ne[M],w[M],idx=0;
int dis[N],st[N],cnt[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool spfa(){
    queue<int> q;
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        q.push(i);
        st[i]=1;
    }
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n)return 1;
                if(!st[j]){
                    st[j]=1;
                    q.push(j);
                }
            }
        }
    }
    return 0;
}
int main(){
    cin>>t;
    int m1,m2,a,b,c;
    while(t--){
        memset(h,-1,sizeof h);
        idx=0;
        cin>>n>>m1>>m2;
        while(m1--){
            cin>>a>>b>>c;
            add(a,b,c);
            add(b,a,c);
        }
        while(m2--){
            cin>>a>>b>>c;
            add(a,b,-c);
        }
        if(spfa())puts("YES");
        else puts("NO");
    }
    return 0;
}