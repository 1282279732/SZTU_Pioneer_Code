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
 /*
参考资料：
https://blog.csdn.net/weixin_40673608/article/details/84262695?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162779355816780269881100%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=162779355816780269881100&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-84262695.first_rank_v2_pc_rank_v29&utm_term=%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97&spm=1018.2226.3001.4187
*/

//方法二
//根据回文串的特点，观察首尾，判断是否插入字符

#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
const int maxn=1e3+5;

int dp[maxn][maxn];                                     //dp[j][k]表示字符串区间j-k之间需要插入的最少字符
char s[maxn];

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<len;i++)
    {
        for(int j=1;j<=len-i;j++)
        {
            int k=i+j;
            if(s[j]==s[k])                              //如果首尾相同取决与（j+1,k-1）区间最少插入字符数
                dp[j][k]=dp[j+1][j-1];
            else
                dp[j][k]=min(dp[j+1][k],dp[j][k-1])+1;  //如果首位不同，要么头进1位或者尾退1位，插入1个字符使其首尾相同（就是+1操作），头还是尾取min即可
        }
    }
    printf("%d\n",dp[1][len]);                          //最后直接输出dp【1，len】需要插入最少字符即可
    return 0;
}
