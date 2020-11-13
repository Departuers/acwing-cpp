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
int n, m,a[110],ans=20,len;
typedef pair<int, int> PII;
vector<int> group[20];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
bool check(int k,int t){
    for(int w:group[t]){
        if(gcd(w,k)>1)return false;
    }
    return 1;
}
void dfs(int u){
    if(len>=ans)return;
    if (u==n)
    {
        ans=len;
        return;
    }
    for(int i=0;i<len;i++){
        if(check(a[u],i)){
            group[i].push_back(a[u]);
            dfs(u+1);
            group[i].pop_back();
        }
    }
    group[len++].push_back(a[u]);
    dfs(u+1);
    group[--len].pop_back();
}
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(0);
    cout<<ans<<endl;
    return 0;
}