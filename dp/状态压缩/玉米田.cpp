#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 13;
int n, m;
int g[N];
/**
 * https://blog.csdn.net/qq_30277239/article/details/104206827
 * 农夫约翰的土地由M*N个小方格组成，现在他要在土地里种植玉米。
非常遗憾，部分土地是不育的，无法种植。
而且，相邻的土地不能同时种植玉米，也就是说种植玉米的所有方格之间都不会有公共边缘。
现在给定土地的大小，请你求出共有多少种种植方法。
土地上什么都不种也算一种方法。
输入格式
第1行包含两个整数M和N。
第2..M+1行：每行包含N个整数0或1，用来描述整个土地的状况，1表示该块土地肥沃，0表示该块土地不育。
输出格式
输出总种植方法对100000000取模后的值。
数据范围
1≤M,N≤12
输入样例：
2 3
1 1 1
0 1 0
输出样例：
9
最多有12行,12列,二进制枚举一行的状态
首先相邻的格子无法种植玉米,用st&(st>>1)是否为0来判断
f[i,k]表示只考虑前i行,且第i行状态为k的所有方案
划分依据,倒数第二行,考虑i-1行状态是什么,当前行状态为k,可以预处理与k不冲突的状态
当前行状态是k
设当前行是a,上一行b
首先一行内不能有相邻的,也就是a,b的二进制表示皆不能有相邻的1
同时不能上下相邻也就是a&b==0
 * */
const int M = 1 << 12, mod = 100000000;
vector<int> state, head[M];
int f[N][M];
bool check(int st)
{
    return (st & (st >> 1)) == 0;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> t,
                g[i] += !t << j;
    }
    for (int i = 0; i < 1 << m; i++)
        if (check(i))
            state.push_back(i);
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0)
                head[a].push_back(b);
        }

    f[0][0] = 1;
    for (int i = 1; i <= n+1; i++) //枚举行数
        for (int j = 0; j < state.size(); j++)
        {
            t = state[j];
            for (int b : head[t])
            {
                if (g[i] & t)
                    continue; //玉米种在了不能种的位置
                f[i][t] += f[i - 1][b];
                f[i][t]%=mod;
            }
        }
    cout<<f[n+1][0]<<endl;
    return 0;
}
