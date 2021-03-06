//⭐⭐

//题目连接：(http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1186)

//由于青蛙可以跳出桥即可，终点是不确定的，但是我们知道起点是0
//所以我们可以从后面往前面跳，只要最后一步跳到0这个位置就可以了
//在跳的步数【s,t】区间取最小的石头数目，dp【】状态数组记录最小的石头数量，当跳到0时候，踩到的石头一定是最小的

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

const int inf=0x3f3f3f;//定义无穷大
const int N=52;//石头数量
const int L=1e5+15;//桥的长度

int dp[L],a[N];

int main()
{
    int l,s,t,n,i,j;
    while(scanf("%d%d%d%d",&l,&s,&t,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            int k;
            scanf("%d",&k);
            dp[k]=1;//根据题目，铺好石头
        }
        for(i=l; i>=0; --i)//从后往前跳，到起始点0
        {
            int m=inf;
            for(j=s; j<=t; ++j)
            {
                m=min(m,dp[i+j]);//找从起点i跳到 i+s -- i+t 最小石头数
            }
            dp[i]+=m;//加上跳到i点最小的石头数量，代表i到桥末的最少石头数量
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}

