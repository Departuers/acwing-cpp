#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200100;
int n,m,p;
struct node{
    int l,r;
    int v;
}tr[N*4];
void build(int k,int l,int r){
    tr[k]={l,r};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}
void pushup(int k){
    tr[k].v=max(tr[k<<1].v,tr[k<<1|1].v);
}
void update(int k,int x,int v){
    if(tr[k].l==x&&tr[k].r==x){
        tr[k].v=v;
    }else {
        int mid=tr[k].l+tr[k].r>>1;
        if(x<=mid)update(k<<1,x,v);
        else update(k<<1|1,x,v);
        pushup(k);
    }
}
int query(int k,int l,int r){
    if(tr[k].l>=l&&tr[k].r<=r){
        return tr[k].v;
    }
    int mid=tr[k].l+tr[k].r>>1;
    int res=0;
    if(l<=mid)res=max(query(k<<1,l,r),res);
    if(r>mid)res=max(query(k<<1|1,l,r),res);
    return res;
}
int main(){
    scanf("%d%d",&m,&p);
    int last=0;
    build(1,1,m);
    char op[2];
    int x;
    while(m--){
        scanf("%s%d",op,&x);
        if(*op=='Q'){
            last=query(1,n-x+1,n);
            printf("%d\n",last);
        }else{
            update(1,n+1,(last+x)%p);
            n++;
        }
    }
    return 0;
}