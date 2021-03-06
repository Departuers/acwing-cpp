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
/**
 * f[i]表示只考虑前i个数,并且以第i个数结尾的最长上升子序列
 * 属性max
 * 状态划分,枚举以a[i]结尾的倒数第二个数是什么
 * f[i]=max{ f[j]+1,0<j<i }
 * O(n^2)
 * */
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
                f[i] = max(f[i], f[j] + 1);
        }
    }
    cout << res << endl;
    return 0;
}