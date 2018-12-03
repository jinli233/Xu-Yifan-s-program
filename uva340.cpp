#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int n,kase=0;
    int a[1000],b[1000];
    while(scanf("%d",&n)==1&&n)
    {
        int c[10]={0};
        for(int i=0;i<n;i++) {scanf("%d",a+i);c[a[i]]+=1;}
        printf("Game %d:\n",++kase);
        while(1)
        {
            int ans[10]={0},A=0,sum=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",b+i);
                if(b[i]==a[i]) A++;
                ans[b[i]]+=1;
            }
            if(b[0]==0) break;
            for(int i=1;i<=9;i++)
            {
                sum+=min(c[i],ans[i]);
            }
            printf("    (%d,%d)\n",A,sum-A);
        }
    }
}
