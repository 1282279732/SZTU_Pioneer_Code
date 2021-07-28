/*
记忆化搜索解决：DP+搜索
保存每次的结果，避免重复计算
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int maxSum[105][105];   //保存每次的结果
int f[105][105];        //原数据
int n;

int Search(int i,int j)
{
    if(maxSum[i][j]!=-1)return maxSum[i][j];    //解决了重复计算问题
    if(i==n)maxSum[i][j]=f[i][j];
    else
    {
        int x=Search(i+1,j);                    //左下值
        int y=Search(i+1,j+1);                  //右下值
        maxSum[i][j]=max(x,y)+f[i][j];          //取最大，加上并且保存
    }
    //for(int i=1;i<=n;i++)cout << maxSum[n][i] << endl;
    return maxSum[i][j];                        //返回
}


int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            cin >> f[i][j];
            maxSum[i][j]=-1;
        }

    cout << Search(1,1) << endl;
    return 0;
}
