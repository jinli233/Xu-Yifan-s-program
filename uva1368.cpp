#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char s[50][1001];
    scanf("%d",&t);
    while(t--)
    {
        int sum[50]={0};
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int Count=0;
                for(int index=0;index<m;index++)
                {
                    if(s[i][index]!=s[j][index]) Count++;
                }
                sum[i]+=Count;
                sum[j]+=Count;
            }
        }
        int mi=sum[0],pos=0;
        for(int i=1;i<n;i++)
        {
            if(sum[i]<mi)
            {
                mi=sum[i];
                pos=i;
            }
            if(sum[i]==mi)
            {
                if(strcmp(s[i],s[pos])<0)
                {
                    mi=sum[i];
                    pos=i;
                }
            }
        }
        printf("%s\n%d\n",s[pos],mi);
    }
}
