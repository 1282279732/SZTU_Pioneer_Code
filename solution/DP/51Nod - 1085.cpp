//⭐

/*题目地址：https://vjudge.net/problem/51Nod-1085
51Nod - 1085 背包问题

非常简单的题，重在思想

未优化版本
*/
#include<iostream>
#include<string.h>

using namespace std;

const int W=1e4+5;
const int P=1e4+5;
const int N=105;
int dp[N][W];
int w[W],p[P];
int main()
{
    int n,ww;
    cin >> n >> ww;
    for(int i=1;i<=n;i++)
    {
        cin >>w[i]>> p[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=ww;j++)
        {
            if(j<w[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
            }
        }
    }
    cout << dp[n][ww] << endl;
    return 0;
}

/*
优化版
（1）把遍历第i个物体和遍历第i-1个物体时的最大价值存在一个单元里。更新前f[j]存i-1的价值，更新后f[j]存i的价值。因为用不到i-2及以前的数据所以不需要存。因为以后不会再用到i-1的价值所以被覆盖了没问题
（2）j从背包容量V开始遍历，即从大到小遍历，保证了当前f[j]和f[j - w[i]]里面存的是i-1的数据，即等价于f([i])[j] = max(f([i - 1])[j], f([i - 1])[j - w[i]] + v[i])，从而和优化空间复杂度前状态转移方程的原理一致。
（3）j从背包容量V开始遍历，如果与当前的v<w[i]不用继续比较，直接跳出循环
*/
#include<iostream>
#include<string.h>

using namespace std;

const int W=1e4+5;
const int P=1e4+5;
const int N=105;
int dp[W]; //一维数组储存，降低空间复杂度
int w[W],p[P];
int main()
{
    int n,ww;
    cin >> n >> ww;
    for(int i=1;i<=n;i++)
    {
        cin >>w[i]>> p[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=ww;j>=w[i];j--)// j<w[i]无法装包，直接跳出循环
        {
            dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
        }
    }
    cout << dp[ww] <<endl;
    return 0;
}

/*
参考：
https://blog.csdn.net/Iseno_V/article/details/100001133?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162677862016780264072981%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=162677862016780264072981&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-100001133.first_rank_v2_pc_rank_v29&utm_term=01%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98&spm=1018.2226.3001.4187
*/
