#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=500,M=19000;
int n,m,p[M];
struct edge{
    int a,b,w;
    bool operator< (const edge &W)const {
        return w<W.w;
    }
}e[M];

int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[i]={a,b,c};
    }
    for(int i=0;i<n+10;i++){
        p[i]=i;        
    }
    int ans=0;
    sort(e,e+m);
    for(int i=0;i<m;i++){
        int a=e[i].a,b=e[i].b;
        a=find(a),b=find(b);
        if(a!=b){
            p[a]=b;
            ans=e[i].w;
        }
    }
    cout<<n-1<<" "<<ans;
    return 0;
}