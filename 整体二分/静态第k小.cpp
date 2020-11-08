#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f,N=101000,M=N*2;
int n, m;
struct no
{
    int op,x,y,k,id;
};
no q[M],lq[M],rq[M];
int ans[N],tr[N],idx;
typedef long long ll;
ll ask(int x){
    ll r=0;
    for(;x;x-=(x&-x))r+=tr[x];
    return r;
}
void add(int x,int v){
    for(;x<=n;x+=(x&-x))tr[x]+=v;
}
void solve(int vl,int vr,int ql,int qr){
    if(ql>qr)return;
    if(vl==vr){
        for(int i=ql;i<=qr;i++){
            if(q[i].op==2)
                ans[q[i].id]=vl;
        }return;
    }
    int mid=vl+vr>>1,l=0,r=0;
    for(int i=ql;i<=qr;i++){
        if(q[i].op==1){
            if(q[i].y<=mid){
                add(q[i].x,q[i].k);
                lq[++l]=q[i];
            }else{
                rq[++r]=q[i];
            }
        }else
        {
            ll tem=ask(q[i].y)-ask(q[i].x-1);
            if(q[i].k<=tem){
                lq[++l]=q[i];
            }else
            {   q[i].k-=tem;
                rq[++r]=q[i];
            }
        }
    }
    for(int i=ql;i<=qr;i++)
    if(q[i].op==1&&q[i].y<=mid)
        add(q[i].x,-q[i].k);
    for(int i=1;i<=l;i++)
        q[ql+i-1]=lq[i];
    for(int i=1;i<=r;i++)
        q[ql+l+i-1]=rq[i];
    solve(vl,mid,ql,ql+l-1),solve(mid+1,vr,ql+l,qr);
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    int x,y,k;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        q[++idx]={1,i,x,1};
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&k);
        q[++idx]={2,x,y,k,i};
    }
    solve(-1e9,1e9,1,idx);
    for(int i=1;i<=m;i++)printf("%d\n",&ans[i]);
    return 0;
}