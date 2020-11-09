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
const int inf = 0x3f3f3f3f, N = 1010;
int n, m, v[N], w[N],f[N][N];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <=m; j++)
        {
            f[i][j]=f[i+1][j];
            if(j>=v[i]){
                f[i][j]=max(f[i+1][j-v[i]]+w[i],f[i][j]);
            }
        }
    }
    int j=m;
    for (int i = 1; i <= n; i++)
    {
        if(j>=v[i]&&f[i][j]==f[i+1][j-v[i]]+w[i]){
            cout<<i<<" ";
            j-=v[i];
        }
    }
    
    return 0;
}