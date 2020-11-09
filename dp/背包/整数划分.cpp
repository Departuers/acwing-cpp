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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, f[1010];
/**
 * 一个正整数n可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中n1≥n2≥…≥nk,k≥1
 * 本题要求我们对整数进行划分，且次序不重要，
 * 也就是说1 2 3与3 2 1被视为一种划分方案。
 * 正整数n，可以划分为若干个1，若干个2，...。
 * f[i,j]表示前i个数任意选,总体积恰好是j的方案数
 * 划分依据,完全背包,第i个物品选几个
 * 可以选0~k个
 * f[i,j]=f[i-1,j]+f[i-1,j-i]+...+f[i-1,j-ki] j>=ki
 * f[i,j-i]=f[i - 1][j - i] + f[i-1][j-2i] + ... + f[i-1][j-ki]
 * 替换得到
 * f[i,j]=f[i-1,j]+f[i,j-i]
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)     //枚举物品
    {                                //第i个物品体积为i
    
        for (int j = i; j <= n; j++) //完全背包,体积到n为止
        {
            f[j] += f[j - i];
        }
    }
    return 0;
}