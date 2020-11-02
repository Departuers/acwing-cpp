#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
int n,m,k,idx=1;
const int N=1010,M=20010;
int h[N],e[M],ne[M],w[M],dis[N],st[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a],h[a]=idx++;
}
bool check(int mid){
    memset(st,0,sizeof st);
    memset(dis,63,sizeof dis);
    dis[1]=0;
    deque<int> q;
    q.push_back(1);
    while(q.size()){
        int t=q.front();q.pop_front();
        if(st[t])continue;
        st[t]=1;
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            int v=w[i]>mid;
            if(dis[j]>dis[t]+v){
                dis[j]=dis[t]+v;
                if(v)q.push_back(j);
                else q.push_front(j);
            }
        }
    }
    return dis[n]<=k;
}
int main(){
    cin>>n>>m>>k;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int l=0,r=1e6+1;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    if(r==1e6+1)r=-1;
    cout<<r<<endl;
    return 0;
}