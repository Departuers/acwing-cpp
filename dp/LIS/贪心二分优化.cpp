#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
using namespace std;
const int inf = 0x3f3f3f3f, N = 100100;
int n, m, q[N], a[N];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int len = 0;
    q[0] = -2e9;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {//找到小于a[i]最大的那个数
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, l + 1);
        q[l + 1] = a[i];
    }
    cout << len << endl;
    return 0;
}