#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
using namespace std;
const int inf = 0x3f3f3f3f, N = 10100;
int n, m, v[N], w[N], f[N];
int main(int argc, char const *argv[])
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}