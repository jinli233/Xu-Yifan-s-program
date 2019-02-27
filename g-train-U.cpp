#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const long long INF=100000000000000000;
struct edge{
    int from,to,flow,cap;
    long long cost;
    edge(int u,int v,int f,int ca,long long co):from(u),to(v),flow(f),cap(ca),cost(co){}
};
vector<edge>edges;
vector<int>g[105];
int a[105];
int p[105];
long long d[105];
int inq[105];

void addedge(int from,int to,int cap,long long cost){
    edges.push_back(edge(from,to,0,cap,cost));
    edges.push_back(edge(to,from,0,0,-cost));
    int m=edges.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int main(){
    int n,m,k,flow,u[5005],v[5005];
    long long w[5005];
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&m);
        for(int i=0;i<=n+1;i++) a[i]=0;
        for(int i=0;i<=n+1;i++) g[i].clear();
        edges.clear();
        for(int i=0;i<m;i++){
            scanf("%d %d %lld",u+i,v+i,w+i);
        }
        scanf("%d%d",&flow,&k);
        for(int i=0;i<m;i++){
            addedge(u[i],v[i],k,w[i]);
            addedge(v[i],u[i],k,w[i]);
        }
        addedge(0,1,flow,0);
        addedge(n,n+1,flow,0);
        int t=n+1;

        int maxflow=0;
        long long mincost=0;
        while(1){
            queue<int>q;
            memset(inq,0,sizeof(inq));
            for(int i=0;i<=n+1;i++) d[i]=INF;
            a[0]=1e9;d[0]=0;inq[0]=1;p[0]=0;
            q.push(0);
            while(!q.empty()){
                int x=q.front();q.pop();
                inq[x]=0;
                for(int i=0;i<g[x].size();i++){
                    edge& e=edges[g[x][i]];
                    if(e.cap>e.flow&&d[e.to]>d[x]+e.cost){
                        d[e.to]=d[x]+e.cost;
                        a[e.to]=min(a[x],e.cap-e.flow);
                        p[e.to]=g[x][i];
                        if(!inq[e.to]){
                            q.push(e.to);
                            inq[e.to]=1;
                        }
                    }
                }
            }
            if(d[t]==INF) break;
            maxflow+=a[t];
            mincost+=a[t]*d[t];
            for(int i=t;i;i=edges[p[i]].from){
                edges[p[i]].flow+=a[t];
                edges[p[i]^1].flow-=a[t];
            }
        }
        if(maxflow==flow) printf("%lld\n",mincost);
        else printf("Impossible.\n");
    }
}
