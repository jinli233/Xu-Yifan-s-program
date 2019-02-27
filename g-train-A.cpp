#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int g[25][25],d[25][25],v[25];

int main(){
    int n,x,kase=0;
    while(scanf("%d",&n)!=EOF){
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            g[1][x]=g[x][1]=1;
        }
        for(int i=2;i<=19;i++){
            scanf("%d",&n);
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                g[i][x]=g[x][i]=1;
            }
        }
        scanf("%d",&n);
        printf("Test Set #%d\n",++kase);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            memset(v,0,sizeof(v));
            for(int j=1;j<=20;j++) for(int k=1;k<=20;k++) d[j][k]=(j==a&&k==a)?0:1<<30;
            for(int j=1;j<=20;j++){
                int x,m=1<<30;
                for(int k=1;k<=20;k++) if(!v[k]&&d[a][k]<=m) m=d[a][x=k];
                v[x]=1;
                for(int k=1;k<=20;k++){
                    if(g[x][k]) d[a][k]=min(d[a][k],d[a][x]+1);
                }
            }
            printf("%2d to %2d: %d\n",a,b,d[a][b]);
        }
        printf("\n");
    }
}
