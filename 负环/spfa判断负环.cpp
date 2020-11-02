#include<iostream>
#include<queue>

using namespace std;
int n,m,idx=1;
const int N=2010,M=10900;
int h[N],e[M],ne[M],w[M],st[N],dis[N],cnt[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
int spfa(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        st[i]=1;
        q.push(i);
    }
    while(q.size()){
        int t=q.front();q.pop();
        st[t]=0;
        for(int i=h[t];i;i=ne[i]){
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
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    if(spfa())puts("Yes");
    else puts("No");
    return 0;
}