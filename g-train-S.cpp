#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

const int INF=1000000000;
struct node{
    int from,to,flow,cap;
    node(int u,int v,int f,int c):from(u),to(v),flow(f),cap(c){}
};

vector<node>edge;
vector<int>g[5005];
int p[5005];
int f[5005];
int r1[4]={0,0,-1,1},r2[4]={1,-1,0,0};

void addedge(int from,int to,int cap){
    edge.push_back(node(from,to,0,cap));
    edge.push_back(node(to,from,0,0));
    int m=edge.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int main(){
    int T,a,s,b,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&s,&a,&b);
        edge.clear();
        for(int i=0;i<=2*s*a+1;i++) g[i].clear();
        for(int i=0;i<b;i++){
            scanf("%d%d",&x,&y);
            addedge(0,2*((x-1)*a+y)-1,1);
        }
        for(int i=1;i<=s;i++) for(int j=1;j<=a;j++){
            if(i==1||i==s||j==1||j==a){
                addedge(2*((i-1)*a+j),2*s*a+1,1);
            }
            addedge(2*((i-1)*a+j)-1,2*((i-1)*a+j),1);
            for(int k=0;k<4;k++){
                if(i+r1[k]>1&&i+r1[k]<s&&j+r2[k]>1&&j+r2[k]<a){
                    addedge(2*((i-1)*a+j),2*((i+r1[k]-1)*a+j+r2[k])-1,1);
                    addedge(2*((i+r1[k]-1)*a+j+r2[k]),2*((i-1)*a+j)-1,1);
                }
            }
        }



        int maxflow=0;
        int t=2*s*a+1;
        while(1){
            memset(f,0,sizeof(f));
            queue<int>q;
            f[0]=INF;
            q.push(0);
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int i=0;i<g[u].size();i++){
                    node& e=edge[g[u][i]];
                    if(!f[e.to]&&e.cap>e.flow){
                        p[e.to]=g[u][i];
                        f[e.to]=min(f[u],e.cap-e.flow);
                        q.push(e.to);
                    }
                }
                if(f[t]) break;
            }
            if(!f[t]) break;
            for(int x=t;x!=0;x=edge[p[x]].from){
                edge[p[x]].flow+=f[t];
                edge[p[x]^1].flow-=f[t];
            }
            maxflow+=f[t];
        }
        if(maxflow==b) printf("possible\n");
        else printf("not possible\n");
    }
}
