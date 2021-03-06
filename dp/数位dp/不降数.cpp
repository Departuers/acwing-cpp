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
int f[N][N];
void init(){
    //只有1位,最高位填i,就只有1位
    for(int i=0;i<=9;i++)
        f[1][i]=1;
    for(int i=2;i<N;i++){//枚举位数
        for(int j=0;j<=9;j++){//枚举最高位
            for(int k=j;k<=9;k++){//枚举次高位
                f[i][j]+=f[i-1][k];
                //最高位填j,枚举次高位,只有i-1位要填
            }
        }
    }
}
int dp(int n){
    if(!n)return 1;
    vector<int> num;
    while (n)
    {
        num.push_back(n%10);
        n/=10;
    }
    int res=0,last=0;//每一个数字比前一个数字大,存的是上一个数字的值
    for(int i=num.size()-1;i>=0;i--){
        int x=num[i];
        for(int j=last;j<x;j++){
            res+=f[i+1][j];
        }
        if(x<last)break;
        last=x;
        if(i==0)res++;
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