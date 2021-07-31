
/*
方法一：
记忆化搜索解决：DP+DAG+记忆化搜索
保存每次的结果，避免重复计算
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

#define inf 0x3f3f3f3f
typedef long long ll;
const int maxn = 1000 + 10;
int n,m;
int dp[maxn][maxn];                                      //dp[][]表示从(x,y)开始向下搜索求最大权值之和
int mp[maxn][maxn];                                      //mp[][]用于建图

int  Dp(int x,int y)                                    //记忆化搜索的核心代码在于记录数值
{
    if(dp[x][y]!=inf)return dp[x][y];                   //如果计算过则直接返回，避免重复计算
    if(x==n){                                           //如果是最下方的数值，则直接返回并且保存
        dp[x][y]=mp[x][y];
        return dp[x][y];
    }

    dp[x][y]=mp[x][y]+max(Dp(x+1,y),Dp(x+1,y+1));       //找到下方和右下方最大值，保存并且记录

    return dp[x][y];
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&mp[i][j]);                      //建图
    memset(dp,inf,sizeof(dp));                          //初始化

    printf("%d\n",Dp(1,1));
    
    return 0;
}

/*
方法二：
动态规划
二维数组也可以做，该题解采用一维数组减小空间复杂度，时间复杂度是相似的
递推关系显而易见，dp[j]=dp[j]+dp[j+1],表示在左小值和右下值取最优，dp[]表示从底往上逆推的最优解
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int dp[105];
int f[105][105];
int n;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            cin >> f[i][j];
            if(i==n)dp[j]=f[i][j];           //保存最后一行的值，通过倒推反复取fdp[j]和dp[j+1]最小值覆盖，从而实现状态转移且最优
        }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[j]=max(dp[j],dp[j+1])+f[i][j];//一维数组储存第i行的值，在dp[j]和dp[j+1]取最大 + f[i][j]重新覆盖这一行的值。
        }
    }
    cout << dp[1] << endl;
    return 0;
}
