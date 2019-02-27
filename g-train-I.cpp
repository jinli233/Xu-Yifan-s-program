#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
    int u,d;
    bool operator <(const node& rhs) const{return d>rhs.d;}
};

struct Edge{
    int u,v,w;
    Edge(int ui,int vi,int wi):u(ui),v(vi),w(wi){}
};



int T,n,m,s,t,kase=0,done[20005],d[20005];
priority_queue<node> q;
vector<Edge> e;

int main(){
    scanf("%d",&T);
    while(T--){
        int a,b,wei;
        scanf("%d%d%d%d",&n,&m,&s,&t);
        e.clear();
        d[s]=0;
        memset(done,0,sizeof(done));
        memset(d,-1,sizeof(d));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&wei);
            e.push_back(Edge(a,b,wei));
        }
        struct node first;
        first.u=s;
        first.d=0;
        q.push(first);
        while(!q.empty()){
            struct node x=q.top();q.pop();
            if(done[x.u]) continue;
            done[x.u]=1;
            for(int i=0;i<m;i++){
                if(e[i].u==x.u&&(d[e[i].v]==-1||d[e[i].v]>x.d+e[i].w)){
                    struct node newnode=x;
                    newnode.u=e[i].v;
                    newnode.d+=e[i].w;
                    d[e[i].v]=newnode.d;
                    q.push(newnode);
                }
                else if(e[i].v==x.u&&(d[e[i].u]==-1||d[e[i].u]>x.d+e[i].w)){
                    struct node newnode=x;
                    newnode.u=e[i].u;
                    newnode.d+=e[i].w;
                    d[e[i].u]=newnode.d;
                    q.push(newnode);
                }
            }
        }
        printf("Case #%d: ",++kase);
        if(d[t]>0) printf("%d\n",d[t]);
        else printf("unreachable\n");
    }
}
