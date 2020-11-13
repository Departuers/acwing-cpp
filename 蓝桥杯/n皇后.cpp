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
int n, m,ans=0,pos[110];
typedef pair<int, int> PII;

void dfs(int u){
    if(u==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        bool f=1;
        for(int k=0;k<u;k++){
            //(k,pos[k])
            if(pos[k]==i||pos[k]+k==u+i||pos[k]-k==i-u){
                f=0;
                break;
            }
        }
        if(f){
            pos[u]=i;
            dfs(u+1);
        }
    }
}
int main(int argc, char const *argv[])
{
    n=8;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}