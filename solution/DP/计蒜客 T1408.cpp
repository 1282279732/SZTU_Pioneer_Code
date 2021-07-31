//⭐⭐

/*
题意：
给出n个矩形，矩形(a,b)和矩形（c,d）9满足a<b，c<d或者a<d，b<c即可嵌套。输出嵌套矩形的最大数量。

思路：
经典DP+DAG，对比每个矩形，画出有向图，再进行记忆化搜索，最后找出最大嵌套矩形数量。

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

#define inf 0x3f3f3f3f
const int maxn = 1000 + 10;
int n,m;
int dp[maxn];                   //记录第i个矩形能嵌套的最大矩形数量
int mp[maxn][maxn];             //建图

struct rectangle
{
    int x,y;
    rectangle():x(0),y(0){}
};

int Dp(int x)
{
    if(dp[x]!=-1)return dp[x];//记忆化搜索
    int ans=1;
    for(int i=0;i<n;i++)
    {
        //有向边存在
        if(mp[x][i]!=-1){
            ans=max(ans,Dp(i)+1);//继续往里搜
        }
    }
    dp[x]=ans;//记录结果
    return dp[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        //初始化
        memset(dp,-1,sizeof(dp));
        memset(mp,-1,sizeof(mp));

        scanf("%d",&n);
        rectangle r[n];
        for(int i=0,a,b;i<n;i++)
        {
            //保证左小于右，a<b
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            r[i].x=a;r[i].y=b;
        }

        //建立有向图
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(r[i].x>r[j].x&&r[i].y>r[j].y)
                    mp[i][j]=1;

        //从每个点出发，找到最大的ans
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,Dp(i));
        }
        printf("%d\n",ans);
    }

    return 0;
}
