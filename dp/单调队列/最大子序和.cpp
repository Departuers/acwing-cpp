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
const int inf = 0x3f3f3f3f, N = 301000;
int n, m;
typedef pair<int, int> PII;
int s[N], q[N];
/**
 * f[i]表示以i结尾的,并且不超过m个数的最大和
 * 设以A[k]结尾,往前枚举长度为1,2,3,...m
 * 前缀和数组为S[]
 * S[k]-S[k-j](1<=j<=m)由于是减去,所以是最小值
 * 单调队列来优化
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] += s[i - 1];
    int res = -1e9, hh = 0, tt = 0;
    //初始化队列中有一个元素0,S[0]=0,
    //考虑不足m个,让减去S[0],相当于不减
    for (int i = 1; i <= n; i++)
    {
        if (q[hh] < i - m)
            hh++; //弹出超过位置的元素
        res = max(res, s[i] - s[q[hh]]);
        while (hh <= tt && s[q[tt]] >= s[i])//由于是最小值,
            tt--;
        q[++tt] = i;
    }
    cout<<res<<endl;
    return 0;
}