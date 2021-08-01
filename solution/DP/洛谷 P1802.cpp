//⭐⭐

/*
题意：
现在有 n 个好友，给定失败时可获得的经验、胜利时可获得的经验，打败他至少需要的药量。要求求出最大经验 s，输出 5*s。

思路：
变形01背包题，经典背包题目拿了才加上value，不拿就没有，而此题假设成背包，不拿的话也有value，拿不动也有value，那题目解就差不多了。
*/
#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
const int maxn=1e3+5;

long long dp[maxn];                                 //有i瓶药所能得到的最高分数
int v1[maxn],v2[maxn],w[maxn];                      //分别表示lose得分 win得分 以及 use打一场所需药量
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&v1[i],&v2[i],&w[i]);

    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=w[i];j--)
        {
            dp[j]=max(dp[j]+v1[i],dp[j-w[i]]+v2[i]); //药量足够的，打就加win分并损失药量，不打加lose分
        }
        for(int j=w[i]-1;j>=0;j--)
        {
            dp[j]+=v1[i];                             //药量不够的，直接加lose分即可
        }
    }
    printf("%lld\n",5*dp[x]);                          //最后输出5倍分数，根据数据范围，要使用long long，不然只有90分
    return 0;
}
