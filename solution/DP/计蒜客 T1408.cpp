//⭐⭐

/*
题意：
给出n个矩形，矩形(a,b)和矩形（c,d）9满足a<b，c<d或者a<d，b<c即可嵌套。输出嵌套矩形的最大数量。

思路：
经典DP+DAG，对比每个矩形，画出有向图，再进行记忆化搜索，最后找出最大嵌套矩形数量。

总结：
一开始打算排序挨个挨个对比，发现不是拿最大的去套剩下的矩形，交了WA。如果按照之前的想法，对下面的测试样例，答案是2，实际上是3（显然）。
1 200
2 300
3 4
5 6
7 8
我想了想，第n个矩形嵌套跟前n个矩形嵌套是有关的，那么是不是可以用单调递增序列去解决？最后还是很顺利的通过了

*/

//方法一：DAG+DP
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


//方法二：DP+上升子序列
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
int n;
int dp[maxn];                                       //记录第i个矩形能嵌套的最大矩形数量

struct rectangle                                    //结构体封装每个矩形，当然也可以用两个数组，结构体方便些
{
    int x,y;
    rectangle():x(0),y(0){}
};

bool cmd(rectangle a,rectangle b)                   //重写sort里面的比较函数
{
    if(a.x!=b.x)return a.x<b.x;
    else return a.y<b.y;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        //初始化
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        rectangle r[n];
        for(int i=0,a,b;i<n;i++)
        {
            //保证左小于右，a<b
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            r[i].x=a;r[i].y=b;
        }

        sort(r,r+n,cmd);                            //关键点，一定要排序

        int ans=0;                                  //计数，找最‘长’的矩形嵌套个数
        for(int i=0;i<n;i++)
        {
            dp[i]=1;                                //每个矩形对于自身都算1个
            for(int j=0;j<i;j++)
            {
                if(r[i].x>r[j].x&&r[i].y>r[j].y)    //上升子序列关键步骤
                    dp[i]=max(dp[j]+1,dp[i]);
                if(dp[i]>ans)                       //找到大的个数，更新ans
                    ans=dp[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
