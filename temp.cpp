#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#include <set>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int, int> PII;

int main(int argc, char const *argv[])
{
    int res=0;
    for (int i = 1; i <=100; i++)
    {
        res+=i;
    }
    cout<<res<<endl;
    return 0;
}