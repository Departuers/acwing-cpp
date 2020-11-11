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
const int inf = 0x3f3f3f3f, N = 410;
int n, m;
typedef pair<int, int> PII;
/**
将 n 堆石子绕圆形操场排放，现要将石子有序地合并成一堆。
规定每次只能选相邻的两堆合并成新的一堆，
并将新的一堆的石子数记做该次合并的得分。
请编写一个程序，读入堆数 n 及每堆的石子数，并进行如下计算：
选择一种合并石子的方案，使得做 n−1 次合并得分总和最大。
选择一种合并石子的方案，使得做 n−1次合并得分总和最小。
输入格式
第一行包含整数 n，表示共有 n 堆石子。
第二行包含 n 个整数，分别表示每堆石子的数量。
输出格式
输出共两行：
第一行为合并得分总和最小值，
第二行为合并得分总和最大值。
数据范围
1≤n≤200
输入样例：
4
4 5 9 4
输出样例：
43
54
n个点连n-1条边,枚举缺口,O(n^4)超时
把链展开,复制一份得到长度为2n的链
我们要求的n条长度为n的区间都在这条2n的链上
再用朴素石子合并的方法去做
 * */
int w[N], s[N], f[N][N], g[N][N];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i], w[i + n] = w[i];
    for (int i = 1; i <= n * 2; i++)
        s[i] = s[i - 1] + w[i];
    
    memset(f,63,sizeof f);
    memset(g,-63,sizeof g);
    for (int len = 1; len <= n; len++)//只循环到n,因为只用到长度为n的区间
    {
        for (int l = 1; l + len - 1 <= n * 2; l++)//左端点
        {
            int r = l + len - 1;//右端点
            if(len==1)f[l][r]=g[l][r]=0;
            else{
                for(int k=l;k<r;k++){
                    f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
                    g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
                }
            }
        }
    }
    int minv=1e9,maxv=-1e9;
    for(int i=1;i<=n;i++){
        minv=min(minv,f[i][i+n-1]);
        maxv=max(maxv,g[i][i+n-1]);
    }
    cout<<minv<<endl<<maxv<<endl;
    return 0;
}