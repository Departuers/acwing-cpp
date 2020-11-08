#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
/**
 * f[i,j]定义为从(1,1)到(i,j)最小花费
 * 属性min
 * 划分依据,上一步从上面过来,还是从左边过来
 * 则f[i,j]=min(f[i-1][j],f[i][j-1])+w[i][j]
 * 
 * 初始化问题
 * 由于f数组默认初值是0，
 * 所以求第一行状态时只能从左边转移过来而不能从上边转移过来，
 * 否则求最小值会发生错误；
 * 同样求第一列状态时只能从上边的状态转移过来而不能从左边的状态转移过来。
 * */
int f[110][110];
int a[110][110];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1){
                f[i][j]=a[1][1];
                continue;
            }
            f[i][j] = 1e9;
            if (i > 1)
                f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j]);
            if (j > 1)
                f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
        }
    cout << f[n][n] << endl;
    return 0;
}