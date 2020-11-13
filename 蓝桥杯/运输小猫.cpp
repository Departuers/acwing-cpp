#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m,w[20],ans,sum[20];
typedef pair<int, int> PII;
void dfs(int u,int k){
    if(k>=ans)return;
    if(u==n){
        ans=k;
        return;
    }
    for(int i=0;i<k;i++){
        if(sum[i]+w[u]<=m){
            sum[i]+=w[u];
            dfs(u+1,k);
            sum[i]-=w[u];
        }
    }
    sum[k]=w[u];
    dfs(u+1,k+1);
    sum[k]=w[u];
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    sort(w,w+n);
    reverse(w,w+n);
    ans=20;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}