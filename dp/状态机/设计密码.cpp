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
const int inf = 0x3f3f3f3f, N = 55, mod = 1e9 + 7;
int n, m;
typedef pair<int, int> PII;
/**
 * https://blog.csdn.net/qq_30277239/article/details/104189713
 * 你现在需要设计一个密码 S，S需要满足：
S的长度是 N；
S只包含小写英文字母；
S不包含子串 T；
例如：abc和 abcde 是 abcde 的子串，abd 不是 abcde的子串。
请问共有多少种不同的密码满足要求？
由于答案会非常大，请输出答案模 10^9+7的余数。
输入格式
第一行输入整数N，表示密码的长度。
第二行输入字符串T，T中只包含小写字母。
输出格式
输出一个正整数，表示总方案数模 109+7后的结果。
数据范围
1≤N≤50,
1≤|T|≤N，|T|是T的长度。
输入样例1：
2
a
输出样例1：
625
输入样例2：
4
cbc
输出样例2：
456924
如果只有前两个限制,那么答案是26^N
考虑第三个性质

 * */
char str[N];
int f[N][N];
int ne[N];
void next(){
    ne[0]=-1;
    for (int i = 1; i <=m; i++)
    {
        int t=ne[i-1];
        while(t!=-1&&str[i-1]!=str[t])t=ne[t];
        ne[i]=t+1;
    }
}
int main(int argc, char const *argv[])
{
    cin>>n>>str+1;
    m=strlen(str+1);
    
    return 0;
}