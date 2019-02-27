#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dv[30][3],g[30][3][30][3],n;
struct re
{
    int l;
    int r;
    int h;
}v[30][3];

int dp(int i,int j)
{
    int& ans=dv[i][j];
    if(ans>0) return ans;
    for(int x=0;x<n;x++) for(int y=0;y<3;y++) if(g[i][j][x][y]) ans=max(ans,dp(x,y)+v[i][j].h);
    if(ans==0) ans+=v[i][j].h;
    return ans;
}


int main()
{
    int a,b,c,ans,kase=0;
    while(scanf("%d",&n)==1&&n)
    {
        ans=0;
        memset(dv,0,sizeof(dv));
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            v[i][0].l=a;v[i][0].r=b;v[i][0].h=c;
            v[i][1].l=c;v[i][1].r=a;v[i][1].h=b;
            v[i][2].l=c;v[i][2].r=b;v[i][2].h=a;
        }
        for(int i=0;i<n;i++) for(int j=0;j<3;j++)
        {
            for(int x=0;x<n;x++) for(int y=0;y<3;y++)
            {
                if(v[i][j].l>v[x][y].l&&v[i][j].r>v[x][y].r||v[i][j].l>v[x][y].r&&v[i][j].r>v[x][y].l) g[i][j][x][y]=1;
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<3;j++) ans=max(ans,dp(i,j));
        printf("Case %d: maximum height = %d\n",++kase,ans);
    }
}
