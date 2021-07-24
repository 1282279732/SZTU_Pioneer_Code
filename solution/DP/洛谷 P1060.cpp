//⭐

/*题目地址：https://www.luogu.com.cn/problem/P1060

题目大意：
手中有n钱，给m件物品，有价格和重要程度。问：怎么用n钱买物品，使得每件物品的价格与重要度的乘积的总和最大。

思路：
求总价值最大，每个物品只能取一次，确定为01背包问题。用一个结构体储存物品属性（两个数组也可），套用01背包基本公式即可
*/
#include <iostream>
#include <math.h>
using namespace std;

const int MAXN=3e4+5;
const int MAXM=30;

struct ob
{
    int value;
    int num;
};

int dp[MAXN];
ob f[MAXM];

int main()
{
    int n,m;
    cin >>n >> m;
    for(int i=0;i<m;i++)
        cin >> f[i].value >> f[i].num;
    for(int i=0;i<m;i++)
    {
        for(int j=n;j>=f[i].value;j--)
        {
            dp[j]=max(dp[j],dp[j-f[i].value]+f[i].value*f[i].num);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
