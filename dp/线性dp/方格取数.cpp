#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f,N=12;
int n, m;
int w[110][110],f[N+N][N][N];
/**
 * 方格走两次取得最大值
 * 考虑f[i1,j1,i2,j2]表示两个人分别从(1,1)(1,1)走到
 * (i1,j1),(i2,j2)收集到数字最大值,方格中数字只能取一次
 * 走的先后顺序对最优解没有影响
 * 设两个人速度一样,相同时间走过的路程长度一样
 * 即k=i1+j1=i2+j2,走到同一个格子只能取一次,而走到同一个格子的路径长度一样长的
 * 减少一维,
 * f[k,i1,i2]表示两个人从(1,1)(1,1)走到(i,k-i1)(i2,k-i2)取得的最大值
 * 状态划分,两个人能从上面,左边过来,根据乘法原理,有四种方式到达该位置
 * 分别是左左：f[k-1][i1-1][i2-1]、上上：f[k-1][i1][i2]、
 * 左上：f[k-1][i1-1][i2]、上左：f[k-1][i1][i2-1]，
 * 转移到f[k][i1][i2]时，如果i1 != i2，说明二者走到的不是同一个方格，
 * 可以取方格(i1,j1),(i2,j2)内的数，否则只能取一次。
 * 。i1 != i2时走到当前状态增加的数字t = w[i1][j1] + w[i2][j2]，
 * i1 = i2时走到当前状态增加的数字t = w[i1][j1]。
 * 状态转移方程为
 * f[k][i1][i2] = max(f[k-1][i1-1][i2-1],f[k-1][i1][i2],f[k-1][i1-1][i2],f[k-1][i1][i2-1]) + t。
 * */
int main(int argc, char const *argv[])
{
    cin>>n;
    int x,y,z;
        while(cin>>x>>y>>z,x || y || z) w[x][y] = z;

    for(int k=2;k<=n+n;k++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                int j1=k-i1,j2=k-i2;
                if(j1>0&&j1<=n&&j2>0&&j2<=n){
                    int t=w[i1][j1];
                    if(j1!=j2)t+=w[i2][j2];
                    f[k][i1][i2]=max(f[k][i1][i2],f[k-1][i1-1][i2-1]+t);
                    f[k][i1][i2]=max(f[k][i1][i2],f[k-1][i1][i2-1]+t);
                    f[k][i1][i2]=max(f[k][i1][i2],f[k-1][i1-1][i2]+t);
                    f[k][i1][i2]=max(f[k][i1][i2],f[k-1][i1][i2]+t);
                }
            }
        }
    }
    cout<<f[n+n][n][n]<<endl;
    return 0;
}