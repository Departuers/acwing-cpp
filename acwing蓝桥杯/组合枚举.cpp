#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
vector<int> q;
void dfs(int u){
    if(q.size()>m||q.size()+n-u+1<m)return ;
    if(u==n+1){
        for(int i=0;i<m;i++)
        cout<<q[i]<<" ";
        cout<<endl;
        return ;
    }
    q.push_back(u);
    dfs(u+1);
    q.pop_back();
    dfs(u+1);
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    dfs(1);
    return 0;
}