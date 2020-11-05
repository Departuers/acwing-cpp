#include<cstring>
#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],cnt[N],n,m;
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>m;
    string op;
    int a,b;
    for(int i=0;i<N;i++)p[i]=i,cnt[i]=1;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=="C"){
            cin>>a>>b;
            a=find(a),b=find(b);
            if(a!=b)p[a]=b,cnt[b]+=cnt[a];
        }else if(op=="Q1"){
            cin>>a>>b;
            a=find(a),b=find(b);
            if(a==b){
                printf("Yes\n");
            }else printf("No\n");
        }else {
            cin>>a;
            a=find(a);
            printf("%d\n",cnt[a]);
        }
    }
    return 0;
}