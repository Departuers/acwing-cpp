#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f,N=110;
int n, m, k;
bool g[N][N];
int st[N][N];
typedef pair<int,int> PII;
PII match[N][N];
int dir[8][2]={{}};
bool find(int x,int y,int tag){
    if(st[x][y]==tag)return 0;
    st[x][y]=tag;
    for (int i = 0; i < 8; i++)
    {
        int a=x+dir[i][0],b=y+dir[i][1];
        if(a<1||a>n||b<1||b>m)continue;
        if(st[a][b]||g[a][b])continue;
        PII t=match[a][b];
        if(!t.x||find(t.x,t.y,tag)){
            match[a][b]={x,y};
            return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x,y;
        g[x][y]=1;
    }
    int res=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if ((i+j)%2||!g[i][j])
            {
                if(find(i,j,i*10+j))res++;
            }
        }
    }
    cout<<n*m-k-res<<endl;
    return 0;
}