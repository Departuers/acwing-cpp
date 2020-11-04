#include<iostream>
#include<vector>
using namespace std;
vector<int> q;
int st[20],n;
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++)cout<<q[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=1;
            q.push_back(i);
            dfs(u+1);
            q.pop_back();
            st[i]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}