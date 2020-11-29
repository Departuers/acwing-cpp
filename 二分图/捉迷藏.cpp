#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int main(int argc, char const *argv[])
{
    int res = 0;
    for (int i = 1; i <= 100; i++)
    {
        res += i;
    }
    cout << res << endl;
    return 0;
}