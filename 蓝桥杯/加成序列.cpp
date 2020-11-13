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
typedef pair<int, int> PII;

int n, m,path[110],st[110];
bool dfs(int u,int depth){
    if(u>depth)return 0;
    if(path[u-1]==n)return 1;
    memset(st,0,sizeof st);
    for(int i=u-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            int s=path[i]+path[j];
            if(s>n||s<path[u-1]||st[s])continue;
            st[s]=1;
            path[u]=s;
            if(dfs(u+1,depth))return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    path[0]=1;
    while (cin>>n,n)
    {
        int depth=1;
        while(!dfs(1,depth)){
            depth++;
        }
        for(int i=0;i<depth;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}