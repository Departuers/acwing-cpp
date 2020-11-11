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
const int inf = 0x3f3f3f3f;
int n, m;
typedef pair<int, int> PII;
/**
 * 司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用”H” 表示），也可能是平原（用”P”表示），如下图。
在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：
如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。
图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。
输入格式
第一行包含两个由空格分割开的正整数，分别表示N和M；
接下来的N行，每一行含有连续的M个字符(‘P’或者’H’)，中间没有空格。按顺序表示地图中每一行的数据。
输出格式
仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
数据范围
N≤100,M≤10
输入样例：
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
输出样例：
6
炮兵可以十字形攻击,求最多能放多少个
f[i,j,k]表示只考虑前i行,第i行状态为j,第i-1行状态是k的所有方案集合
二进制枚举一行的所有状态
考虑一行的状态,两个炮兵之间最少隔着两个空位
state & (state >> 1) == state & (state >> 2) ==0;
如此判断

考虑第i行状态是a,第i-1行状态是b,第i-2行状态是c
(a&b)|(b&c)|(c&a)==0
(g[i-1]&b)==0
(g[i]&a)==0
 * */
const int N = 102, M = 1 << 10;
vector<int> state, head[M], cnt;
int f[2][N][M]; //使用滚动数组
int g[N];
int count(int t)
{
    int r = 0;
    while (t)
    {
        t -= (t & -t);
        r++;
    }
    return r;
}
bool check(int state)
{
    int a = state & (state >> 1), b = state & (state >> 2);
    return a == b && b == 0;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == 'H')
                g[i] += 1 << j;
        }
    }
    for (int i = 0; i < 1 << m; i++)
    {
        if (check(i))
            state.push_back(i), cnt.push_back(count(i));
    }
    for (int i = 1; i <=n+2; i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            for (int k = 0; k < state.size(); k++)
            {
                for (int u = 0; u < state.size(); u++)
                {
                    int a=state[j];//第i行
                    int b=state[k];//i-1行
                    int c=state[u];//i-2行
                    if((a&b)||(b&c)||(a&c))continue;//互相攻击到
                    if(g[i-1]&b||g[i]&a)continue;//不能放炮兵
                    f[i&1][j][k]=max(f[i&1][j][k],f[i-1&1][k][u]+cnt[j]);
                }
            }
        }
    }
    cout<<f[n+2&1][0][0]<<endl;
    return 0;
}