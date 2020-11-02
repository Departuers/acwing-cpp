#include<iostream>
#include<sstream>
#include<queue>
#include<cstring>
using namespace std;

const int N=510;
int n,m;
bool g[N][N];
int dis[N],stop[N];
void bfs(){
    memset(dis, 63,sizeof dis);
    queue<int> q;
    dis[1]=0;
    q.push(1);
    while(q.size()){
        int v=q.front();q.pop();
        for(int i=1;i<=n;i++){
            if(g[v][i]&&dis[i]>dis[v]+1){
                dis[i]=dis[v]+1;
                q.push(i);
            }
        }
    }
}
int main(){
    string line;
    cin>>m>>n;
    getline(cin,line);
    while(m--){
        int cnt=0,p;
        getline(cin,line);
        stringstream ssin(line);
        while(ssin>>p)stop[cnt++]=p;
        for(int j=0;j<cnt;j++){
            for(int k=j+1;k<cnt;k++){
                g[stop[j]][stop[k]]=1;
            }
        }
    }
    bfs();
    if(dis[n]==0x3f3f3f3f){
        puts("NO");
    }else cout<<max(dis[n]-1,0)<<endl;
    return 0;
}