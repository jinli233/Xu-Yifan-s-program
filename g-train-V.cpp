#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int d[150][105];

int main(){
    int t,n,m,x,y,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j]=n;
        for(int i=0;i<n;i++) d[i][i]=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            d[x][y]=d[y][x]=1;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(d[i][j]<n&&d[k][j]<n){
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                    }
                }
            }
        }

        int maxlong=0;
        for(int i=0;i<n;i++){
            int ans=n;
            for(int j=i+1;j<n;j++){
                if(d[i][j]!=n){
                    ans=min(ans,d[i][j]);
                }
            }
            if(ans!=n) maxlong=max(maxlong,ans);
        }
        printf("Case #%d: %d\n",++kase,maxlong);
    }
}
