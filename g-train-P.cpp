#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF=1<<30;
struct node{
    int from,to,flow,cap,cost;
    node(int u,int v,int f,int ca,int co):from(u),to(v),flow(f),cap(ca),cost(co){}
};

vector<node>edge;
vector<int>g[105];
int a[105];
int p[105];
int inq[105];
int d[105];

void addedge(int from,int to,int flow,int cap,int cost){
    edge.push_back(node(from,to,flow,cap,cost));
    edge.push_back(node(to,from,0,0,-cost));
    int m=edge.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int main(){
    int n,m,u,v,c;
    while(scanf("%d",&n)==1&&n){
        for(int i=0;i<=1+n;i++) g[i].clear();
        edge.clear();
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&c);
            addedge(u,v,0,1,c);
            addedge(v,u,0,1,c);
        }
        addedge(0,1,0,2,0);
        addedge(n,n+1,0,2,0);
        int maxflow=0,mincost=0;
        while(1){
            for(int i=0;i<=n+1;i++) d[i]=INF;
            memset(inq,0,sizeof(inq));
            d[0]=0;inq[0]=1;p[0]=0;a[0]=INF;

            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int u=q.front();q.pop();
                inq[u]=0;
                for(int i=0;i<g[u].size();i++){
                    node& e=edge[g[u][i]];
                     if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                        d[e.to]=d[u]+e.cost;
                        p[e.to]=g[u][i];
                        a[e.to]=min(a[u],e.cap-e.flow);
                        if(!inq[e.to]) {q.push(e.to);inq[e.to]=1;}
                    }
                }
            }
            if(d[n+1]==INF) break;
            maxflow+=a[n+1];
            mincost+=d[n+1];
            for(int u=n+1;u!=0;u=edge[p[u]].from){
                edge[p[u]].flow+=a[n+1];
                edge[p[u]^1].flow-=a[n+1];
            }
        }
        if(maxflow==2) printf("%d\n",mincost);
        else printf("Back to jail\n");
    }
}
