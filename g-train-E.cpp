#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int t,x[505],y[505],u[260000],v[260000],r[260000],p[505];
double w[260000];

int cmp(int i,int j){return w[i]<w[j];}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

int main(){
    scanf("%d",&t);
    while(t--){
        int s,P,pos=0;
        scanf("%d%d",&s,&P);
        for(int i=1;i<=P;i++) {scanf("%d%d",x+i,y+i);p[i]=i;}
        for(int i=1;i<=P;i++) for(int j=1;j<=P;j++){
            if(i!=j){
                w[pos]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                u[pos]=i;
                v[pos]=j;
                r[pos]=pos;
                pos++;
            }
        }
        sort(r,r+pos,cmp);
        P-=1;
        if(s!=1){
            P-=s-1;
        }
        for(int i=0;i<pos;i++){
            int e=r[i];
            int x=find(u[e]);
            int y=find(v[e]);
            if(x!=y){
                if(--P==0){
                    printf("%.2f\n",w[e]);
                    break;
                }
                p[x]=y;
            }
        }
    }
}
