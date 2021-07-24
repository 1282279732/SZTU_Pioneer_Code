//⭐

//### 硬币找零
//题目链接：https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T1781

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

const int inf=1061109567;//定义无穷大——其实只要大于M即可
const int N=52;//硬币最大数
const int M=1e5+5;//找零最大数

int dp[M];//下标0~M是找零的总数，储存每次找零的最优解
int mony[N];//储存各种硬币

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);//n是硬币系统中不同硬币数，m是需要用硬币找零的总数。
    memset(dp,inf,sizeof(dp));//初始化为正无穷，代表不存在用这些硬币可以找零
    for(i=0;i<n;i++)
    {
        scanf("%d",&mony[i]);//储存各种硬币
        dp[mony[i]]=1;//每种硬币下dp[]肯定是1，一步到位嘛
    }

    dp[0]=0;//dp[0]无法计算，初始化为0

    for(i=0;i<=m;i++)
        for(j=0;j<n;j++)
    {
        //关键点！！
        //条件①：i-mony[j]>=0 如果小于0，说明当前的硬币无法找零，跳过，找下一个硬币
        //条件②：dp[i-mony[j]]!=inf 假设拿出该硬币mony[j]，那么剩余i-mony[j]的钱，而这钱不存在找零（inf表示不存在），则跳过
        if(i-mony[j]>=0&&dp[i-mony[j]]!=inf)
            dp[i]=min(dp[i-mony[j]]+1,dp[i]);//状态转移方程：假设取出该硬币和未取出该硬币比较，取最小找零的硬币数
    }
    if(dp[m]!=inf)printf("%d\n",dp[m]);//存在输出m找零的硬币数
    else printf("-1\n");//不存在输出-1
    return 0;
}
