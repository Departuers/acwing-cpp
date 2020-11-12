#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f,N=12;
int n, m;
typedef pair<int, int> PII;
int f[N][10];
void init(){
    for(int i=0;i<=9;i++)
        f[1][i]=1;
    for(int i=2;i<N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                //两个数相差大于等于2
                if(abs(j-k)>=2)f[i][j]+=f[i-1][j];
            }
        }
    }
}
int dp(int n){
    if(n==0)return 0;
    vector<int> num;
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    int res=0,last=-3;
    for(int i=num.size()-1;i>=0;i--){
        int x=num[i];
        for(int j=(i==num.size()-1);j<x;j++){
            if(abs(j-last)>=2)
                res+=f[i+1][j];
        }
        if(abs(x-last)>=2)last=x;
        else break;
        if(!i)res++;//没有被break说明合法
    }
    for(int i=1;i<num.size();i++){
        for(int j=1;j<=9;j++)
            res+=f[i][j];
    }
    return res;
}
int main(int argc, char const *argv[])
{
    init();
    int l,r;
    cin>>l>>r;
    cout<<dp(r)-dp(l-1)<<endl;
    return 0;
}