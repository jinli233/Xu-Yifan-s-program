#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int from,to,flow,cap;
    double cost;
    node(int u,int v,int f,double co,int ca):from(u),to(v),flow(f),cost(co),cap(ca){}
};
vector<node>edge;
vector<int>g[50];
int p[50];
int a[50];
int inq[50];
double d[50];

void addedge(int from,int to,double cost){
    edge.push_back(node(from,to,0,cost,1));
    edge.push_back(node(to,from,0,-cost,0));
    int m=edge.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int main(){
    int n,m;
    double x;
    while(scanf("%d%d",&n,&m)==2&&n){
        for(int i=0;i<=m+n+1;i++) g[i].clear();
        edge.clear();
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            addedge(i,n+m+1,0);
            for(int j=1;j<=m;j++){
                scanf("%lf",&x);
                addedge(j+n,i,x);
            }
        }
        for(int i=1;i<=m;i++){
            addedge(0,n+i,0);
        }

        double mincost=0;
        while(1){
            for(int i=0;i<=n+m+1;i++) {d[i]=1000000000.0;}
            memset(inq,0,sizeof(inq));
            a[0]=1E9;inq[0]=1;p[0]=0;d[0]=0;
            int t=n+m+1;
            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int u=q.front();q.pop();
                inq[u]=0;
                for(int i=0;i<g[u].size();i++){
                    node &e=edge[g[u][i]];
                    if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                        d[e.to]=d[u]+e.cost;
                        p[e.to]=g[u][i];
                        a[e.to]=min(a[u],e.cap-e.flow);
                        if(!inq[e.to]){q.push(e.to);inq[e.to]=1;}
                    }
                }
            }
            if(d[t]>999999999.0) break;
            mincost+=d[t];
            for(int u=t;u!=0;u=edge[p[u]].from){
                edge[p[u]].flow+=a[t];
                edge[p[u]^1].flow-=a[t];
            }
        }
        printf("%.2f\n",mincost/n+0.001);
    }
}
