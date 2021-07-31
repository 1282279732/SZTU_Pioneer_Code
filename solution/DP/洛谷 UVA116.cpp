//⭐⭐⭐

/*
题意：
给一个m行n列（m≤10，n≤100）的整数矩阵，从第一列任何一个位置出发每次往右、右上、右下走一格，最终到达最后一列。要求经过的整数之和最小。
整个矩阵是环形的，即第一行的上一行是最后一行，最后一行的下一行是第一行。输出路径上每列的行号。多解时输出字典序最小的。

思路：
与数字三角形相似，关键是模拟上中下移动以及路径的记录，我们用二维dp[maxn][maxn]维护最短路，Next[maxn][maxn]记录路径，mp[maxn][maxn]建图，再利用记忆化搜索减少重复计算
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

#define inf 0x3f3f3f3f
const int maxn = 100 + 10;
int n,m;
int dp[maxn][maxn],mp[maxn][maxn],Next[maxn][maxn];

struct node{
    int x,y;
};

bool cmd(node a,node b)
{
    return a.x<b.x;
}

int Dp(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];  //记忆化搜索，避免重复计算
    if(y==n-1)
    {
        dp[x][y]=mp[x][y];             //更新dp值，类比数字三角形，数字三角形从‘左下’和‘右下’取min，从后往前决策，递推到第0列的时候结束
        Next[x][y]=x;                  //第x行该走哪一步有最短路？记录下来
        return dp[x][y];               //返回dp（x，y）最短路值
    }
    
    //模拟下一步上中下三步
    node a[3];
    a[0].x=x;
    a[1].x=(x+1)%m;             //防止越界
    a[2].x=(x-1+m)%m;           //防止越界
    a[0].y=a[1].y=a[2].y=y+1;
    stable_sort(a,a+3,cmd);    //排序，相同元素不交换（sort对于相同元素可能会交换位置）

    int ans=inf,index=-1;
    for(int i=0;i<3;i++)       //试探摸清三点找最小值
    {
        if(Dp(a[i].x,a[i].y)<ans)
        {
            ans=Dp(a[i].x,a[i].y);
            index=i;
        }
    }
    dp[x][y]=ans+mp[x][y];     //ans为（x,y+1）（x-1,y+1）（x+1,y+1）最小值，mp[x][y]为当前点的值，赋值给dp[x][y]这样就确定y+1后面的最短路的值，接下来只要重复操作即可。
    Next[x][y]=a[index].x;     //记录下一步y+1走的是哪一行x
    return dp[x][y];           //返回从x行y行出发最短路值
}

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(Next,-1,sizeof(Next));           //初始化
        memset(dp,-1,sizeof(dp));               //初始化
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp[i][j]);          //建图


        int ans=inf,index=-1;
        for(int i=0;i<m;i++)                    //DP，0—m各行开始考虑所有情况
        {
            if(Dp(i,0)<ans){                    
                ans=Dp(i,0);                    //记录最短路
                index=i;                        //记录最短路的起始点
            }
        }
        printf("%d",index+1);                   //输出起始点，保证输出格式正确
        index=Next[index+1][0];                 //指向下一个点
        int y=1;
        for(;y<n;index=Next[index][y++])        //因为已经记录过最短路每一列的x行，遍历输出即可
        {
            printf(" %d",index+1);
        }
        printf("\n%d\n",ans);                   //输出最短路长度
    }
    return 0;
}
