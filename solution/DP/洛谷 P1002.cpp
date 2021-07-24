//题目地址：https://www.luogu.com.cn/problem/P1002
/*
题意：计算从左上角到右下角有多少条路径
思路：
观察可知，从到某一点等于左点和上点路径之和，根据`加法原理`，计算得出的数肯定不漏不多，**dp[i][j]=dp[i-1][j]+dp[i][j-1]**注意不要越界就行啦
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

long long karte[25][25];//地图，全局变量，都是0
int vis[25][25];        //全局变量，都是0
int dx[]={0,-2,-2,-1,-1,1,1,2,2}; //走马步
int dy[]={0,1,-1,2,-2,2,-2,1,-1}; //走马步


int main()
{
    int x,y,a,b,i,j;
    cin >> x >> y >> a >> b;    //（x，y）是B坐标   （a，b）是马坐标

    for(int i=0;i<=8;i++)
    {
        int tx=dx[i]+a;
        int ty=dy[i]+b;
        if(tx>=0&&tx<=x&&ty>=0&&ty<=y){ //点在地图内，防止数组越界
            vis[tx][ty]=1;              //把马拦住的点都设为1，用vis储存，遍历时跳过
        }
    }

    //边界条件，x=0||y=0时候只有 1 条路径，边缘处某点被马拦住，后面点路径都为0
    i=0;
    while(!vis[i][0]&&i<=x)karte[i++][0]=1;
    i=0;
    while(!vis[0][i]&&i<=y)karte[0][i++]=1;

    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            //如果该点可访问，则到达此点的路径数目=左边的点路径数+上面的点路径数
            //注意！不用考虑左边的点或者上面的点是否能访问，因为初始化为0，不影响该点的最终结果
            if(!vis[i][j])  
                karte[i][j]=karte[i-1][j]+karte[i][j-1];
        }
    }
    cout << karte[x][y] << endl;    //直接输出即可
    return 0;
}

