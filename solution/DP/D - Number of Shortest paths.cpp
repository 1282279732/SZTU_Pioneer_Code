//⭐⭐⭐
//AtCoder Beginner Contest 211
/*
题意：
从点1到点n最短路径有多少条

思路：
BFS+DP
DP[i]表示从点1到i最短路径有多少条
BFS一个点一个点搜索，维护dp[]

*/

#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
const int mod=1e9+7;
vector<int>e[N];
int dp[N],dist[N];


int main()
{
    //作用：让std :: cin和std :: cout不再经过缓冲区，iostream的性能就会提高了很多倍。
    cin.tie(nullptr)->sync_with_stdio(false);
    //初始化-1表示i到j没有路径
    memset(dist,-1,sizeof(dist));
    int n,m,i,j,a,b;
    cin >> n >> m;
    //e[i]表示i->j 之间有一条路径
    for(i=1;i<=m;i++)
    {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    queue<int>q;
    dist[1]=0,dp[1]=1,q.push(1);
    while(!q.empty())//从1开始出发，开始BFS
    {
        int u=q.front();q.pop();
        //c++11的新特性
        //例如：vector<int> v={1,2,3,4};
        //for(auto i:v)
        //cout<<i;
        //结果就是1234

        for(int v:e[u])                     //遍历容器vector<int>e[u]
        {
            if(dist[v]==-1)                 //如果找到一条没有走过的路口
            {
                dp[v]=dp[u];                //维护最短路的数量
                dist[v]=dist[u]+1;          //添加一条边，长度加+1
                q.push(v);                  //放入队列中，继续重复之前的操作
            }
            //反之走过，如果从u可以走到v，dp[v]=(dp[v]+dp[u])%mod;
            //怎么理解呢？BFS每次选取未踩过的点，所以从u->v的u点是之前没有走过
            //所以，此时dp[v]最短路数量路径是不包括u点的，根据加法原理，dp[u]+dp[v]不会有重复路径
            else if(dist[u]+1==dist[v])     
                dp[v]=(dp[v]+dp[u])%mod;
        }
    }
   
    cout << dp[n] << endl;
    return 0;
}
