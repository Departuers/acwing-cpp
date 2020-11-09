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
const int inf = 0x3f3f3f3f, N = 10100;
int n, m, k, f[N][N], v[N], w[N], h[N];
int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> h[i] >> w[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            for (int s = k; s >= h[i]; s--)
            {
                f[j][s] = max(f[j - v[i]][s - h[i]]+w[i], f[j][s]);
            }
        }
    }
    cout << f[m][k] << endl;
    return 0;
}