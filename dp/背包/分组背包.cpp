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
const int inf = 0x3f3f3f3f, N = 1010, M = 110;
int n, m, v[M][M], w[M][N], f[N], s[N];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < s[i]; k++)
            {
                if (j >= v[i][k])
                {
                    f[j]=max(f[j-v[i][k]]+w[i][k],f[j]);
                }
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}