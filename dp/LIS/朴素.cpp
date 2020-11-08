#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int a[1110], f[1110];
int main(int argc, char const *argv[])
{
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                f[i] = max(f[j] + 1, f[i]);
        }
        res = max(f[i], res);
    }
    cout<<res<<endl;
    return 0;
}