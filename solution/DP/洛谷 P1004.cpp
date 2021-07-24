/*题目地址：https://www.luogu.com.cn/problem/P1004
P1004 [NOIP2000 提高组] - 方格取数

### 题目大意：
从左上角到右下角，走过的格子变为0，找两条路径使得和最大。

### 思路：
①首先，找求和最大值可以采用dfs或者dp。
②对于单个路径，用二位dp可以求得，我们在此可以用思维dp模拟两个人走路，那么得建立**四维dp**数组去模拟，**时间复杂度为9^4**显然是很小的。两个人一共有四种选择，左左、上左、左上、上上。因此我们可以直接写出转移方程，**dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+map[i][j]+map[k][l]**如果两个人都是从同一个点出发（即i==k&&l==j）我们还要减去map[i][j]，避免重复计算。

### 心得：
在时间复杂度允许的条件下，学会用四维dp模拟，思想与二维dp一样
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int map[10][10];
long dp[10][10][10][10];

int main()
{
    int n,x,y,a;
    cin >> n;

    while(cin >> x >> y >> a)
    {
        if(!a&&!x&&!y)break;
        map[x][y]=a;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                for(int l=1; l<=n; l++)
                {
                    //用四维dp模拟两个走路
                    //共有四种情况：①左左                 ②左上                ③上左                ④上上
                    //对应转移方程：①dp[i-1][j][k-1][l]   ②dp[i-1][j][k][l-1]  ③dp[i][j-1][k-1][l]  ④dp[i][j-1][k][l-1]
                    //然后加上map[i][j]和map[k][l]表示拿走当前这个数字
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+map[i][j]+map[k][l];
                    if(i==k&&l==j)dp[i][j][k][l]-=map[i][j];
                }

    cout << dp[n][n][n][n] <<endl;

    return 0;
}

