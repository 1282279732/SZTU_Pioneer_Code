#include<stdio.h>
using namespace std;

const int inf= 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct Node
{
    int key;        //记录关键字
    int data;       //携带的数据
    int left;       //左子树地址（数组下标）
    int right;      //右子树地址（数组下标）
    int height;     //当前结点为跟的子树高度
    void Init() { data = key = right = left = height = -1; }
    void Init(int k_, int d_ = 0) { Init(); key = k_; data = d_; }
    Node() { Init(); }
    Node(int k_, int d_ = 0) { Init(k_, d_); }
};

Node tr[maxn];
int root, tp;//记录根节点的位置，tp全局节点分配下来

inline int UpdateHeight(int now)
{
    //更新 tr[now] 结点的子树高度，即tr[now].height 的值 max（取左子树高度||右子树高度）+ 1
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return tr[now].height = (lh > rh ? lh : rh) + 1;
}

inline int HeightDiff(int now)
{
    //计算 tr[now] 结点的平衡因子（左子树高度 - 右子树高度）
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return lh - rh;
}

int LL(int an)
{
    // tr[an]是old root，tr[bn]是new root，tr[dn]是new root右子树
    // tr[an].data>tr[bn].data，an接到bn右子树
    // 因为tr[dn].data>tr[bn].data且tr[dn].data<tr[an].data，dn接到an左子树
    // 最后更新，维护各个结点的数据,dn在转移过程，地位没有变（画图可知）
    int bn = tr[an].left;
    int dn = tr[bn].right;
    tr[bn].right = an;
    tr[an].left = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}

int RR(int an)
{
    int bn = tr[an].right;
    int dn = tr[bn].left;
    tr[bn].left = an;
    tr[an].right = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}

int LR(int an)
{
    tr[an].left = RR(tr[an].right);
    return LL(an);
}

int RL(int an)
{
    tr[an].right = LL(tr[an].right);
    return RR(an);
}

void Insert(int& now, int key, int data = 0)
{
    if (now == -1)
    {
        //传入空指针
        now = ++tp;
        tr[now].Init(key, data);
    }
    //判断插入哪个子树，插入数据，判断平衡因子，做正确的旋转，更新高度
    //如果小于当前关键字，往左边找
    else if (key < tr[now].key)
    {
        Insert(tr[now].left, key, data);
        if (HeightDiff(now) == 2)
        {
            now = key < tr[tr[now].left].key ?
                LL(now) : LR(now);
        }
    }
    //如果大于当前关键字，往右边找
    else if (key > tr[now].key)
    {
        Insert(tr[now].right, data, key);
        //插入后，判断平衡，并且调整
        if (HeightDiff(now) == -2)
        {
            now = key > tr[tr[now].right].key ?
                RR(now) : RL(now);
        }
    }
    //维护数据
    UpdateHeight(now);
}

void Delete(int& now, int key)
{
    if (now == -1)return;
    else if (key < tr[now].key)Delete(tr[now].left, key);
    else if (key > tr[now].key)Delete(tr[now].right, key);
    else
    {
        //删除当前结点
        if (tr[now].left == -1)now = tr[now].right;//只有右子树
        else if (tr[now].right == -1)now = tr[now].left;//只有左子树
        else//左右子树都有
        {
            int nd;
            for (nd = tr[now].left;; nd = tr[nd].right)//找到左子树的右子树来代替该点
                if (tr[nd].right == -1)break;
            tr[now].key = tr[nd].key;
            tr[now].data = tr[nd].data;
            Delete(tr[now].left, tr[nd].key);
        }
    }
    //处理树平衡（维护其它数据）
    if (now == -1)return;
    UpdateHeight(now);
    if (HeightDiff(now) == 2)
        now = HeightDiff(tr[now].left) >= 0 ?
            LL(now) : LR(now);
    else if (HeightDiff(now) == -2)
        now = HeightDiff(tr[now].right) <= 0 ?
            RR(now) : RL(now);
}

int main()
{
    int n, op, key, data;
    while (scanf("%d", &n) != EOF)
    {
        for (root = tp = -1; n--;)// 初始化根结点和“内存指针”
        {
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d", &data, &key);
                Insert(root, key, data);
            }
            
            else if (op == 2)
            {
                if(root==-1)printf("0\n");
                else
                {
                    
                }
            }
            
            else if (op == 3)
            {
                
            }
            
            else if (op == 4)
            {
                
            }
        }
        //printf("\n");
    }
    return 0;
}
