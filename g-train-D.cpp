#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double w[1000000];
int u[1000000],v[1000000],r[1000000],p[800];

int cmp(const int i,const int j) {return w[i]<w[j];}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

int main(){
    int n,k,x[800],y[800];
    while(scanf("%d",&n)!=EOF){
        int pos=0;
        double ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",x+i,y+i);
            p[i]=i;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
                r[pos]=pos;
                u[pos]=i;
                v[pos]=j;
                w[pos]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                pos++;
        }
        scanf("%d",&k);
        int a,b;
        for(int i=1;i<=k;i++){
            scanf("%d%d",&a,&b);
            int x=find(a);
            int y=find(b);
            if(x!=y){
                p[x]=y;
            }
        }
        sort(r,r+pos,cmp);
        for(int i=0;i<pos;i++){
            int e=r[i];
            a=find(u[e]);
            b=find(v[e]);
            if(a!=b){
                ans+=w[e];
                p[a]=b;
            }
        }
        printf("%.2f\n",ans);
    }
}
