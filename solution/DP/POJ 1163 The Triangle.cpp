
/*
方法一：
记忆化搜索解决：DP+搜索
保存每次的结果，避免重复计算
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int maxSum[105][105];   //保存每次的结果
int f[105][105];        //原数据
int n;

int Search(int i,int j)
{
    if(maxSum[i][j]!=-1)return maxSum[i][j];    //解决了重复计算问题
    if(i==n)maxSum[i][j]=f[i][j];
    else
    {
        int x=Search(i+1,j);                    //左下值
        int y=Search(i+1,j+1);                  //右下值
        maxSum[i][j]=max(x,y)+f[i][j];          //取最大，加上并且保存
    }
    //for(int i=1;i<=n;i++)cout << maxSum[n][i] << endl;
    return maxSum[i][j];                        //返回
}


int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            cin >> f[i][j];
            maxSum[i][j]=-1;
        }

    cout << Search(1,1) << endl;
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
