//⭐⭐⭐

/*
题意：
求插入的最少个数使其成为回文串

思路：
仔细观察，正序与倒序“公共”的部分就是我们回文的部分，
如果把正序与倒序公共的部分减去你就会惊奇的发现剩余的字符就是你所要添加的字符，也就是所求的正解。
题目就转换成求最长公共子序列了。
*/

#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
const int maxn=1e3+5;

int dp[maxn][maxn];                                     //第一个【】表示字符串s前i个字符，第二个【】表示字符串t前j个字符
char s[maxn],t[maxn];                                   //正字符串和逆字符串

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        t[i]=s[len-i+1];                                 //保存逆字符串
    }

    //找到最长公共子序列的长度，核心代码
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=len;j++)
        {
            if(s[i]==t[j])
                dp[i][j]=dp[i-1][j-1]+1;                //如果相同，当前dp[][]=左上方dp[][]+1
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    //如果不相同，dp[][]=左边dp和上面dp取max
        }
    }
    printf("%d\n",len-dp[len][len]);                    //最后直接减去公共子序列长度即可
    return 0;
}
