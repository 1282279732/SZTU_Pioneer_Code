//⭐

//题目1星，套模板就可以AC了

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

const int MAXN=3500;
const int MAXV=2e4;

int dp[MAXV];//开一位数组储存，dp[V]表示V能获取的最大价值，V表示背包体积
int value[MAXN],weight[MAXN];//value表示物品价值，vol表示体积

int main()
{
    int n,v,i,j;
    cin >> n >> v;

    for(i=0;i<n;i++)
        cin >> weight[i] >> value[i];

    for(i=0; i<n; i++)
    {
        for(j=v; j>=weight[i]; j--)//从后往前遍历
        {
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);//转移方程
        }
    }
    cout << dp[v] << endl;
    return 0;
}
