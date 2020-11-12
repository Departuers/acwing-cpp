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
const int inf = 0x3f3f3f3f,N=9;
int n, m;
typedef pair<int, int> PII;
int f[N][10];
/**
 * f[i,j]表示只有i位,且最高位是j,不包含4或者62的集合
 * 属性count
 * 划分找到一个分界点,最高位为j次高位可以填,j,j+1,j+2...9
 * 
 * */
void init(){
    //一共有1位,最高位为i
    for(int i=0;i<=9;i++){
        if(i!=4)f[1][i]=1;
    }
    for(int i=2;i<N;i++){//位数
        for(int j=0;j<=9;j++){//最高位
            if(j!=4){//不能有4
                for(int k=0;k<=9;k++){//枚举次高位
                    if(k==4||(j==6&&k==2))continue;
                    f[i][j]+=f[i-1][k];//只用填i-1位,最高位填k
                }
            }
        }
    }
}
int dp(int n){
    if(n==0)return 1;
    vector<int> num;
    while (n)
    {
        num.push_back(n%10);
        n/=10;
    }
    int res=0,last=0;//last记录前一位是几
    for(int i=num.size()-1;i>=0;i--){
        int x=num[i];
        for(int j=0;j<x;j++){//枚举0~x
            if(j==4||(last==6&&j==2))continue;
            res+=f[i+1][j];//由于下标从0开始,所有i+1才是真实数字位数
        }
        if(x==4||(last==6&&x==2))break;
        last=x;
        if(i==0)res++;//枚举这个数本身
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int l,r;
    init();
    cin>>l>>r;
    cout<<dp(r)-dp(l-1)<<endl;
    return 0;
}