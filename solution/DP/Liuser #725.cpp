// difficulty：1
// 硬币问题 DP+DAG

/*
题意：
有n种硬币，分别有对应面值，每种都有无限多。给定非负整数S，可以选用多少个硬币，使得面值之和恰好为S？输出使用硬币数目的最小值和最大值。

思路：
简单DP，从1开始决策，考虑每一种硬币，取还是不取，分别取max和min，最后直接输出即可。

*/


#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
const int maxn=1e4+5;               //最大面额
const int maxm=1e3+5;               //最大硬币数
int dp[maxn],dp1[maxn];             //dp[][]维护最少硬币数,dp1[][]维护最多硬币数
int f[maxm];                        //记录每个硬币面额
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    memset(dp,inf,sizeof(dp));      //初始化
    memset(dp1,-inf,sizeof(dp1));   //初始化
    for(int i=0; i<n; i++)
        scanf("%d",&f[i]);
    dp[0]=dp1[0]=0;;                        //0元需要0个硬币去凑
    for(int i=1; i<=s; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>=f[j])
            {
                //面对每个硬币，选择取还是不取
                dp[i]=min(dp[i],dp[i-f[j]]+1);      //核心代码
                dp1[i]=max(dp1[i],dp1[i-f[j]]+1);   //核心代码
            }
        }
    }
    printf("%d %d\n",dp[s],dp1[s]);
    return 0;
}
