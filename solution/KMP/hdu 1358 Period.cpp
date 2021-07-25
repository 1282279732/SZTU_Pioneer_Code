/*
定理：假设S的长度为len，则S存在最小循环节，循环节的长度L为len-next[len]，子串为S[0…len-next[len]-1]。
（1）如果len可以被len - next[len]整除，则表明字符串S可以完全由循环节循环组成，循环周期T=len/L。
（2）如果不能，说明还需要再添加几个字母才能补全。需要补的个数是循环个数L-len%L=L-(len-L)%L=L-next[len]%L，L=len-next[len]。
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
char s[N];
int Next[N];

void Builtnext()
{
    Next[0]=-1;
    for(int i=0,j=-1;s[i];)
    {
        if(j==-1||s[i]==s[j])
            Next[++i]=++j;
        else j=Next[j];
    }
}

int main()
{
    int n,k=1;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%s",s);
        memset(Next,0,sizeof(Next));
        Builtnext();
        printf("Test case #%d\n",k++);
        for(int i=2;i<=n;i++)
        {
            if(i%(i-Next[i])==0&&i/(i-Next[i])>1)
            {
                printf("%d %d\n",i,i/(i-Next[i]));
            }
        }
        printf("\n");
    }

    return 0;
}
