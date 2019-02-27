#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;


//拆点，把一个点拆成左点和右点
const int INF=1<<30;
int a[205];
int p[205];
struct node{
    int u,v,f,c;
    node(int from,int to,int flow,int cap):u(from),v(to),f(flow),c(cap){}
};
vector<node>e;
vector<int>g[205];

void addedge(int from,int to,int flow,int cap){
    e.push_back(node(from,to,0,cap));
    e.push_back(node(to,from,0,0));
    int m=e.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int main(){
   int n,m,b,d,from,to,cap;
   while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=2*n+1;i++) g[i].clear();
        e.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&cap);
            addedge(2*i-1,2*i,0,cap);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&from,&to,&cap);
            addedge(2*from,2*to-1,0,cap);
        }
        scanf("%d %d",&d,&b);
        for(int i=0;i<d;i++){
            scanf("%d",&to);
            addedge(0,2*to-1,0,INF);
        }
        for(int i=0;i<b;i++){
            scanf("%d",&from);
            addedge(2*from,2*n+1,0,INF);
        }
        int maxflow=0;
        while(1){
            memset(a,0,sizeof(a));
            queue<int>q;
            q.push(0);
            a[0]=INF;
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int i=0;i<g[x].size();i++){
                     node &edge=e[g[x][i]];
                     if(!a[edge.v]&&edge.c>edge.f){
                        a[edge.v]=min(a[x],edge.c-edge.f);
                        p[edge.v]=g[x][i];
                        q.push(edge.v);
                     }
                }
                if(a[2*n+1]) break;
            }
            if(!a[2*n+1])break;
            for(int k=2*n+1;k!=0;k=e[p[k]].u
            ){
                e[p[k]].f+=a[2*n+1];
                e[p[k]^1].f-=a[2*n+1];
            }
            maxflow+=a[2*n+1];
        }
        printf("%d\n",maxflow);
   }
}
