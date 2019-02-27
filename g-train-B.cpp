#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int t,n,p[105],v[100500],u[100500],r[100500];
double x[105],y[105],dis[105][105],w[100500];

int cmp(const int i,const int j){return w[i]<w[j];}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++) {scanf("%lf%lf",x+i,y+i);p[i]=i;}
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            if(i!=j){
                r[ans]=ans;
                w[ans]=dis[i][j];
                u[ans]=i;
                v[ans]=j;
                ans++;
            }
        }
        sort(r,r+ans,cmp);
        double re=0;
        for(int i=0;i<ans;i++){
            int e=r[i];
            int x=find(u[e]);
            int y=find(v[e]);
            if(x!=y){
                re+=w[e];
                p[x]=y;
            }
        }
        printf("%.2lf\n",re);
        if(t) printf("\n");
    }
    return 0;
}
