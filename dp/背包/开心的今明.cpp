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
const int inf = 0x3f3f3f3f, N = 30010;
int n, m;
typedef pair<int, int> PII;
/**
 * 01背包简单应用
 * 
 * */
int f[N];
int main(int argc, char const *argv[])
{
    cin >> m>> n;
    int v,w;
    for (int i = 1; i <= n; i++)
    {
        cin>>v>>w;
        w*=v;
        for (int j = m; j >= v; j--)
        {
            f[j]=max(f[j],f[j-v]+w);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}