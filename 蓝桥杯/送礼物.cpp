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
int n, m, w[50], k;
vector<int> weight;
typedef pair<int, int> PII;
void dfs1(int u,int sum){
    
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w, w + n);
    reverse(w, w + n);
    k = n / 2 + 2;
    dfs1(0, 0);
    sort(weight.begin(),weight.end(),less<int>());
    return 0;
}