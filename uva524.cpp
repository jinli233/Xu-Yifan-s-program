#include<stdio.h>
#include<string.h>
int v[32];

void find(int n,int *A,int cur)
{
    if(cur==n&&v[A[0]+A[n-1]])
    {
        int kase=0;
        for(int i=0;i<n;i++)
        {
            if(kase++) printf(" ");
            printf("%d",A[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i=2;i<=n;i++)
        {
            int ok=1;
            for(int j=0;j<cur;j++)
            {
                if(A[j]==i) ok=0;
            }
            if(ok&&v[A[cur-1]+i]) {A[cur]=i;find(n,A,cur+1);}
        }
    }
}

int main()
{
    int n,A[17],kase=0;
    for(int i=3;i<=31;i++)
    {
        int ok=1;
        for(int j=2;j<i;j++)
        {
            if(i%j==0) ok=0;
        }
       v[i]=ok;
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(kase > 0) printf("\n");
        printf("Case %d:\n", ++kase);
        memset(A,0,sizeof(A));
        A[0]=1;
        find(n,A,1);
    }
    return 0;
}
