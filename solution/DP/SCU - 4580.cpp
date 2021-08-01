// difficulty：2
// 01 背包
/*
题目地址：https://vjudge.net/problem/SCU-4580
SCU - 4580 动态规划之01背包问题

注意：
样例给的有点问题
Sample Output
12 3
2 5
*/

#include<iostream>
#include<string.h>

using namespace std;

const int N=1e3+5;          //泥土的种类
const int V=1e3+5;          //泥土占用最大体积
const int W=1e6+5;          //最大泥土质量
int dp[N][V],w[V],v[V];     //dp[N][V]：前一个[N]表示泥土种类，后一个[V]表示体积为v的时的状态，dp[N][V]表示前N中泥土，背包体积为V时候能装的最大泥土质量

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,vv;
        cin >> n >> vv;
        for(int i=1; i<=n; i++)
            scanf("%d",&w[i]);          //第i个泥土质量
        for(int i=1; i<=n; i++)
            scanf("%d",&v[i]);          //第i个泥土占用体积

        memset(dp,0,sizeof(dp));        //初始化
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=vv;j++)
            {
                if(j<v[i]){
                    //显然，当前背包体积不够装泥土，此时背包泥土质量等于i-1的质量
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    //面对这n种泥土，只有两种选择，装还是不装
                    //①不装，那么有dp[i][j]=dp[i-1][j]
                    //②装，dp[i-1][j-v[i]]+w[i]
                    //怎么理解？对于不装的情况，显然此时的最大质量等于i-1项，
                    //装的话，可能有一种或者多种装法，由于最优先性原则，dp[i-1][j-v[i]]肯定是最优解，
                    //在当前选择时，只需要比较装和不装的情况即可
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
                }
            }
        }
        int count=vv;           //记录装载最大泥土质量的体积，假设为题目给的背包体积vv
        for(int i=vv-1;i>=0;i--)//找到能装载最大泥土质量的体积
        {
            //有一段数据是背包体积增大，最大泥土质量不变，回溯找到第一个数据即是找到能装载最大泥土质量的体积
            if(dp[n][vv]==dp[n][i])
            {
                count--;//重复数据减一
            }
            else break;//找到第一个个直接退出
        }
        printf("%d %d\n",dp[n][vv],count);
    }
    return 0;
}
