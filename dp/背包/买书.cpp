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
const int inf = 0x3f3f3f3f;
int n, m;
int v[] = {0, 10, 20, 50, 100};
int f[1010];
int main(int argc, char const *argv[])
{
    cin >> n;
    f[0]=1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = v[i]; j <=n ; j++)
        {
            f[j]+=f[j-v[i]];
        }
    }
    cout<<f[n]<<endl;
    return 0;
}