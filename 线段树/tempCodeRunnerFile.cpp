#include <iostream>
using namespace std;
const int N = 1e5 + 2;
int n, m, a[N];
struct no
{
    int l, r, sum, lazy;
} tr[N << 2];
typedef long long ll;
void push(int k){
    tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void build(int k, int l, int r)
{
    if (l == r)
    {
        tr[k]={l,r,a[l]};
    }
    else
    {
        int mid = l + r >> 1;
        build(k << 1, l, mid), build(k << 1 | 1, mid + 1, r);
        push(k);
    }
}
void down(int k){
    if(tr[k].lazy){
        tr[k<<1].sum+=(tr[k<<1].r-tr[k<<1].l+1)*tr[k].lazy;
        tr[k<<1|1].sum+=(tr[k<<1|1].r-tr[k<<1|1].l+1)*tr[k].lazy;
        tr[k<<1].lazy+=tr[k].lazy;
        tr[k<<1|1].lazy+=tr[k].lazy;
        tr[k].lazy=0;
    }
}
void up(int k,int l,int r,int v){
    if(tr[k].l>=l&&tr[k].r<=r){
        tr[k].sum+=(tr[k].r-tr[k].l+1)*v;
        tr[k].lazy+=v;
    }else {
        down(k);
        int mid=tr[k].l+tr[k].r>>1;
        if(l<=mid)up(k<<1,l,r,v);
        if(r>mid)up(k<<1|1,l,r,v);
        push(k);
    }
}
ll query(int k,int l,int r){
    if(tr[k].l>=l&&tr[k].r<=r)return tr[k].sum;
    down(k);
    ll mid=(tr[k].l+tr[k].r)>>1,ans=0;
    if(l<=mid)ans+=query(k<<1,l,r);
    if(r>mid)ans+=query(k<<1|1,l,r);
    return ans;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    char op[2];
    build(1,1,n);
    int l,r,d;
    while(m--){
        scanf("%s",op);
        if(*op=='C'){
            scanf("%d%d%d",&l,&r,&d);
            up(1,l,r,d);
        }else {
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,l,r));
        }
    }
    return 0;
}
