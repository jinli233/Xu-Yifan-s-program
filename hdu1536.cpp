#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sg[10001],s[100],v[101],dv,k;

void get_sg()
{
    memset(sg,0,sizeof(sg));
    for(int i=1;i<=10000;i++)
    {
        memset(v,0,sizeof(v));
        for(int j=0;j<k;j++)
        {
            if(i<s[j]) break;
            v[sg[i-s[j]]]=1;
        }
        for(int j=0;j<=100;j++)
        {
            if(!v[j])
            {
                sg[i]=j;
                break;
            }
        }
    }
}

int main()
{
    int t;
    while(scanf("%d",&k)==1&&k)
    {
        for(int i=0;i<k;i++) scanf("%d",s+i);
        sort(s,s+k);
        get_sg();
        scanf("%d",&t);
        while(t--)
        {
            int n,x=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&dv);
                x^=sg[dv];
            }
            if(x) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}
