#include <iostream>
using namespace std;
int n, a[1100], q[10100], g[10100];
int main()
{
    while (cin >> a[n])
        n++;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] >= a[i])
                l = mid;
            else
                r = mid - 1;
        }
        q[l + 1] = a[i];
        len = max(len, l + 1);
    }
    cout << len << endl;
    /**
     * 贪心流程:
     * 1.如果现有的子序列的结尾都小于当前数,则创建新子序列
     * 2.将当前数放到结尾大于等于它的最小的子序列后面
     * */
    len = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < len && a[i] > g[j])
            j++;
        g[j] = a[i];
        len = max(len, j + 1);
    }
    cout << len << endl;
    return 0;
}