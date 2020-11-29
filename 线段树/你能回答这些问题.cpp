#include <iostream>
#include<cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int n, m;
/**
 * 单点修改pushup
 * 查询区间最大连续子段和
 * 需要横跨左右区间的最大前后缀
 * 左区间的最大后缀和,右区间的最大前缀和
 */
struct node
{
    int l,r;
    int tmax;//最大连续字段和
    int lmax;//最大前缀和
    int rmax;//最大后缀和
    int sum; //区间和
};
 
int main(int argc, char const *argv[])
{
    return 0;
}