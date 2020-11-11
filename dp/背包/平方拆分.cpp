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
int v[1010], f[3000];
//把2019拆分成不同的平方数有多少方案
int main(int argc, char const *argv[])
{
    for (int i = 1; i < 45; i++)
    {
        v[i] = i * i;
    }
    f[0] = 1;
    for (int i = 1; i < 45; i++)           //物品
    {                                     
        for (int j = 2019; j >= v[i]; j--) //体积
        {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[2019] << endl;
    return 0;
}