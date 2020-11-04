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
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j>0; j--)
        {
            cout<<(char)((i+j)%26+'A')<<endl;
        }
        
    }
            
    return 0;
}