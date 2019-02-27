#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int INF=1000000000;
struct node{
    int from,to,flow,cap;
    node(int u,int v,int f,int c):from(u),to(v),flow(f),cap(c){}
};

vector<node>edge;
vector<int> g[2005];
char name[2005][30];
char temp[2][30];
int a[2005];
int p[2005];

void addedge(int from,int to,int cap){
    edge.push_back(node(from,to,0,cap));
    edge.push_back(node(to,from,0,0));
    int m=edge.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int main(){
    int T,n,m,k,pos=1;
    scanf("%d",&T);
    while(T--){
        edge.clear();
        for(int i=0;i<2005;i++) g[i].clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%s",name[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int ok=0;
            scanf("%s %s",name[i+n],temp[0]);
            addedge(0,n+i,1);
            for(int j=1;j<n+m+pos;j++){
                if(strcmp(temp[0],name[j])==0){
                    ok=1;
                    addedge(n+i,j,1);
                    break;
                }
            }
            if(!ok){
                strcpy(name[pos+n+m],temp[0]);
                addedge(n+i,n+m+pos,1);
                pos++;
            }
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%s %s",temp[0],temp[1]);
            int u[2];
            for(int index=0;index<2;index++){
                int ok=0;
                for(int j=1;j<n+m+pos;j++){
                    if(strcmp(temp[index],name[j])==0){
                        ok=1;
                        u[index]=j;
                        break;
                    }
                }
                if(!ok){
                    strcpy(name[pos+n+m],temp[index]);
                    u[index]=n+m+pos;
                    pos++;
                }
            }
            addedge(u[0],u[1],INF);
        }
        for(int i=1;i<=n;i++) addedge(i,pos+n+m,1);

        int maxflow=0;
         int t=n+m+pos;
        while(1){
            memset(a,0,sizeof(a));
            queue<int>q;
            a[0]=INF;
            q.push(0);
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int i=0;i<g[u].size();i++){
                    node& e=edge[g[u][i]];
                    if(!a[e.to]&&e.cap>e.flow){
                        p[e.to]=g[u][i];
                        a[e.to]=min(a[u],e.cap-e.flow);
                        q.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int x=t;x!=0;x=edge[p[x]].from){
                edge[p[x]].flow+=a[t];
                edge[p[x]^1].flow-=a[t];
            }
            maxflow+=a[t];
        }
        printf("%d\n",m-maxflow);
        if(T) printf("\n");
    }
}
