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
    while(!q.empty())
    {
        int u=q.front();q.pop();
        //c++11的新特性
        //例如：vector<int> v={1,2,3,4};
        //for(auto i:v)
        //cout<<i;
        //结果就是1234
        for(int v:e[u])//遍历容器vector<int>e[u]
        {
            if(dist[v]==-1)
            {
                dp[v]=dp[u];
                dist[v]=dist[u]+1;
                q.push(v);
            }
            else if(dist[u]+1==dist[v])dp[v]=(dp[v]+dp[u])%mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
