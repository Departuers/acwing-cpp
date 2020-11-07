#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
const int N=8e4+10,M=N*2;
int h[N],e[M],ne[M],idx=1;
int dep[N],;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void bfs(){
    memset(dep,63,sizeof dep);
}
int main(int argc, char const *argv[])
{
    return 0;
}