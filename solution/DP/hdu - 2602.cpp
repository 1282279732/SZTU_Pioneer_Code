//⭐

//题目地址：https://acm.hdu.edu.cn/showproblem.php?pid=2602

#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

const int MAXN=1e3+5;    //骨头bone（物品）的最大数量
const int MAXV=1e3+5;    //收集器（背包）最大体积

int dp[MAXV];//开一位数组储存，dp[V]表示V能获取的最大价值，V表示背包体积
int value[MAXN],vol[MAXN];//value表示骨头价值，vol表示骨头体积

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,v,i,j;
        cin >> n >> v;

        memset(dp,0,sizeof(dp));//多组数据，初始化，否则WA
        for(i=0;i<n;i++)
            cin >> value[i];
        for(i=0;i<n;i++)
            cin >> vol[i];

        for(i=0;i<n;i++)
        {
            for(j=v;j>=vol[i];j--)   //从后往前枚举
            {
                dp[j]=max(dp[j],dp[j-vol[i]]+value[i]);//转移方程
            }
        }
        cout << dp[v] << endl;
    }
    return 0;
}
