#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int g[410][451];
int main(){
    cin>>n>>m;
    memset(g,63,sizeof g);
    for(int i=0;i<=n;i++)g[i][i]=0;
    int a,b,c;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(g[1][i]==0x3f3f3f3f){
            res=-1;
            break;
        }else res=max(res,g[1][i]);
    }
    cout<<res<<endl;
    return 0;
}