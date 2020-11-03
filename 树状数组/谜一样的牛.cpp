#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 1e5 + 11;
int n, m, ans[N], tr[N], h[N];
void add(int x,int v){
    for(;x<=n;x+=(x&-x))tr[x]+=v;
}
int ask(int x){
    int r=0;
    for(;x;x-=(x&-x))r+=tr[x];
    return r;
}
int main(int argc, char const *argv[])
{   
    scanf("%d",&n);
    for (int i = 2; i <=n; i++)scanf("%d",&h[i]);
    for (int i = 1; i <=n; i++)add(i,1);
    for (int i = n; i>=1 ; i--)
    {
        int l=0,r=n,k=h[i]+1;
        while (l<r)
        {
            int mid=l+r>>1;
            if(ask(mid)>=k)r=mid;
            else l=mid+1;
        }        
        ans[i]=l;
        add(l,-1);
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}