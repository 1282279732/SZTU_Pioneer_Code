//⭐⭐⭐

/*
题意：
上方块中点数之和记为S1，下方块中点数之和记为S2，它们的差为|S1-S2|。每个多米诺骨牌可以上下旋转换位。 编程用最少的旋转次数使多米诺骨牌上下2行点数之差达到最小。

思路：
DP+背包，面对每个多米诺骨牌，我们选择翻或者不翻，很容易联想到min(dp[i],dp[i-1]+1);表意是前i个数字翻转的最小次数
但是一维肯定是不够用的，我们还没把上和下和的绝对差值给考虑进去，然后我就开了dp[N][6*N]，前N个数字和为6*N翻转的最小次数
前面N好确定，一开始就给了，后面6*N，我们可以把上下之和全部加起来，这样我们就有超大“背包”，这样dp[N][6*N]包揽全部状态
这样我们就很容易写出
for(int i=1;i<=n;i++)
    for(int j=sum;j>=f[i]||j>=g[i];j--)
    {
        //模拟翻转还是不翻转
        if(j-f[i]>=0)dp[i][j]=min(dp[i][j],dp[i-1][j-f[i]]+1);
        if(j-g[i]>=0)dp[i][j]=min(dp[i][j],dp[i-1][j-g[i]]+1);
    }
卡住我的就是不知道怎么求最小次数了,看了一下题解,主要是通过遍历1~sum，找最小绝对值差，更新最小差绝对值minD和最少次数minT
以下为代码，附有注释

*/

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
const int inf=0x3f3f3f;

int dp[N][6*N];                                     //dp[N][6*N]代表前N个数字sum为6*N最少次数
int f[N],g[N];                                      //记录前N个多米诺骨牌对应的上下数字
int main()
{
    int n,sum=0;
    cin >> n;
    for(int i=1,a,b; i<=n; i++)
    {
        cin >> a >> b;
        f[i]=a,g[i]=b;
        sum+=a+b;                                           //确定和的上限
    }
    memset(dp,inf,sizeof(dp));                              //初始化正无穷

    dp[1][f[1]]=0,dp[1][g[1]]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=sum;j>=f[i]||j>=g[i];j--)
        {
            //模拟翻转还是不翻转
            if(j-f[i]>=0){
                dp[i][j]=min(dp[i][j],dp[i-1][j-f[i]]);
            }
            if(j-g[i]>=0){
                dp[i][j]=min(dp[i][j],dp[i-1][j-g[i]]+1);
            }
        }
    }

    int minT=inf,minD=inf;
    for(int i=0;i<=sum;i++)
    {
        if(dp[n][i]!=inf)
        {
            //假设i代表上方的总和，那么sum-i就是下方的总和，如果绝对值差小于minD，更新最小值差minD和最少次数minT
            if (abs(i-(sum-i)) < minD){
                minD = abs(i-(sum-i)); minT = dp[n][i];
            }
            //如果绝对值差和==minD，我们只需要更新minT最少次数即可
            else if (abs(i-(sum-i)) == minD) minT = min(minT, dp[n][i]);
        }
    }
    cout << minT << endl;
    return 0;
}
