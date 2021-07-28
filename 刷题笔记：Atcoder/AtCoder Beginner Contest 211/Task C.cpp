/*
题意：
给出一个字符串，问有多少个字串能构成 chokudai

思路：
简单dp，只要计算某个位置对构成 chokudai 的贡献值即可
if s[i]==ts[j] 
    dp[j]=(dp[j]+dp[j−1])%mod 
f[0]=1

*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

const int mod=1e9+7;    //取模计算
int dp[9];              //“chokudai”每个字符对凑成该字符串的贡献值，只需要加上前一个即可

string ts={" chokudai"};

int main()
{
    string ms;
    cin >> ms;
    int i,j,len=ms.length();
    dp[0]=1;
    for(i=0;i<len;i++)
        for(j=1;j<=8;j++)
            if(ms[i]==ts[j])
                dp[j]=(dp[j]+dp[j-1])%mod;

    cout << dp[8]%mod << endl;
    return 0;
}
