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
int n, m, f[N], v[N], w[N];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }
    cout << f[m] << endl;
    return 0;
}