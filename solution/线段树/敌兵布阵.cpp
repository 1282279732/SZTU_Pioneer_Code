//简单线段树模板


#include<iostream>
#include<queue>
#include<string>
#include<stack>
using namespace std;

#define ll long long

const int maxn = 5e4 + 5;

struct node
{
    ll sum;
    int l, r;
    int lazytage;
}tree[maxn << 2];
int input[maxn];

void push_up(int i)
{
    tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
}

//下放tree[i].lazytage;
void push_down(int i)
{
    if (!tree[i].lazytage)
    {
        tree[i << 1].lazytage += tree[i].lazytage;
        tree[i << 1 | 1].lazytage += tree[i].lazytage;
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[i << 1].sum += tree[i].lazytage * (mid - tree[i << 1].l + 1);
        tree[i << 1 | 1].sum += tree[i].lazytage * (tree[i << 1 | 1].r - mid);
        tree[i].lazytage = 0;//要清零
    }
}

void Build(int i, int l, int r)
{
    tree[i].l=l,tree[i].r=r,tree[i].lazytage=0,tree[i].sum=0;//初始化
    if (l==r) {
        tree[i].sum = input[l];
        return ;
    }
    int mid = (l + r) >> 1;
    Build(i << 1, l, mid);
    Build(i << 1 | 1, mid + 1, r);
    push_up(i);//向上传递
}

//区间求和
int Search(int i,int l,int r)
{
    if (tree[i].l >= l && tree[i].r <= r) {
        return tree[i].sum;
    }
    push_down(i);
    int s = 0;
    if (tree[i].l > r || tree[i].r < l)return 0;
    if (tree[i << 1].r >= l)s += Search(i << 1, l, r);
    if (tree[i << 1 | 1].l <= r)s += Search(i << 1 | 1, l, r);
    return s;
}


//区间修改
void Update(int i,int l,int r,int k)
{
    if (tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum += k * (tree[i].r - tree[i].l + 1);
        tree[i].lazytage += k;//记录lazytage
    }
    push_down(i);//向下传递
    if (tree[i << 1].r >= l)Update(i << 1, l, r, k);
    if (tree[i << 1 | 1].l <= r)Update(i << 1 | 1, l, r, k);
    push_up(i);
    return;
}

void pls(int i,int l,int r,int k)
{
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].sum+=k;
        return ;
    }
    if(tree[i<<1].r>=l)pls(i<<1,l,r,k);
    if(tree[i<<1|1].l<=r)pls(i<<1|1,l,r,k);
    push_up(i);
}

int main()
{
    int t,Case=0;
    scanf("%d", &t);
    int i=2;
    while (t--)
    {
        printf("Case %d:\n", ++Case);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &input[i]);
        Build(1, 1, n);
        string s;
        while (cin >> s)
        {
            int k, l, r,dis;
            if (s == "Query")
            {
                scanf("%d%d", &l, &r);
                printf("%d\n", Search(1, l, r));
            }
            if (s == "Add")
            {
                scanf("%d%d", &dis, &k);
                pls(1, dis, dis, k);
            }
            if (s == "Sub")
            {
                scanf("%d%d", &dis, &k);
                pls(1, dis, dis, -k);
            }
            if (s == "End")
            {
                break;
            }
        }
    }
}
