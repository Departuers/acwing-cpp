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
    cin >> n >> m;
    if(!n||!m)return 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            cout << (char)(j % 26 + 'A');
        }
        for (int j = 1; j < m - i; j++)
        {
            cout << (char)(j % 26 + 'A');
        }
        cout << endl;
    }
    return 0;
}