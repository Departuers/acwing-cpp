#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int f[1010][1010];
/**
 * f[i,j]定义为从(1,1)到(i,j)所摘到花生最多数量
 * 属性max
 * 划分依据,上一步从上面过来,还是从左边过来
 * 则f[i,j]=max(f[i-1][j],f[i][j-1])+w[i][j]
 * */
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>f[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j]+=max(f[i-1][j],f[i][j-1]);
        cout<<f[n][m]<<endl;
    }
    return 0;
}