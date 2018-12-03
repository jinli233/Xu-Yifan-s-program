#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF=1<<30;
int dv[51][201],trans[51][200][2];

int main()
{
    int kase=0;
    int n,T,m1,m2,t[51],d1[51],d2[51];
    while(scanf("%d",&n)==1&&n)
    {
        memset(trans,0,sizeof(trans));
        scanf("%d",&T);
        for(int i=1;i<n;i++) dv[i][T]=INF;
        dv[n][T]=0;
        for(int i=1;i<n;i++) scanf("%d",t+i);
        scanf("%d",&m1);
        for(int i=0;i<m1;i++) scanf("%d",d1+i);
        scanf("%d",&m2);
        for(int i=0;i<m2;i++) scanf("%d",d2+i);
        for(int i=0;i<m1;i++)
        {
            int ans=d1[i];
            trans[1][ans][0]=1;
            for(int j=2;j<=n;j++)
            {
                ans+=t[j-1];
                trans[j][ans][0]=1;
            }
        }
        for(int i=0;i<m2;i++)
        {
            int ans=d2[i];
            trans[n][ans][1]=1;
            for(int j=n-1;j>=1;j--)
            {
                ans+=t[j];
                trans[j][ans][1]=1;
            }
        }
        for(int i=T-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                dv[j][i]=dv[j][i+1]+1;
                if(j<n&&trans[j][i][0]&&i+t[j]<=T)
                    dv[j][i]=min(dv[j][i],dv[j+1][i+t[j]]);
                if(j>1&&trans[j][i][1]&&i+t[j-1]<=T)
                    dv[j][i]=min(dv[j][i],dv[j-1][i+t[j-1]]);
            }
        }
        printf("Case Number %d: ",++kase);
        if(dv[1][0]>=INF) printf("impossible\n");
        else printf("%d\n",dv[1][0]);
    }
    return 0;
}
