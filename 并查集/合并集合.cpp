#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f,N=1e6;
int n, m;
int p[N];
int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}
int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=1e5;i++)p[i]=i;
    int a,b;
    char op[2];
    while(m--){
        scanf("%s%d%d",op,&a,&b);
        if(*op=='M'){
            a=find(a),b=find(b);
            if(a!=b)p[a]=b;
        }else{
            a=find(a),b=find(b);
            if(a!=b)
            printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}