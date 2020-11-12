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
const int inf = 0x3f3f3f3f, N = 200100;
int n, m;
typedef pair<int, int> PII;
/**
 * 连续m个烽火台至少有一个点燃
 * 最长不能有连续超过m不点燃的烽火台
 * f[i]表示只考虑1~i之间满足要求,且点燃第i个烽火台的所有方案
 * 要求
 * 属性min
 * 划分:找倒数第二个,可以是i-1,i-2...i-m 最远i-m枚举这个
 * f[i]=min(f[j]+w[i]) i-m<=j<i,长度为m-1的区间找最小值
 * 用单调队列优化
 * */
int w[N], f[N], q[N];
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    int hh=0,tt=0;//有一个元素为0
    for(int i=1;i<=n;i++){
        if(q[hh]<i-m)hh++;
        f[i]=f[q[hh]]+w[i];
        while(hh<=tt&&f[q[hh]]>=f[i])tt--;//求最小值
        q[++tt]=i;
    }
    int res=1e9;
    //从最后m个烽火台里选
    for(int i=n-m+1;i<=n;i++){
        res=min(res,f[i]);
    }
    cout<<res<<endl;
    return 0;
}