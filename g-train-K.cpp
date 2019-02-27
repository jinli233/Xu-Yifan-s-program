#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int u,v,w;
    void init(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
}e[105];

int d[105],n,m;

bool bf(){
    memset(d,0,sizeof(d));
    for(int k=0;k<n;k++){
        for(int i=0;i<m;i++){
            if(d[e[i].u]+e[i].w<d[e[i].v]){
                d[e[i].v]=d[e[i].u]+e[i].w;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(d[e[i].u]+e[i].w<d[e[i].v]) return false;
    }
    return true;
}

int main(){
    while(scanf("%d",&n)&&n){
        scanf("%d",&m);
        int si,ni,ki;
        char str[5];
        for(int i=0;i<m;i++){
            scanf("%d%d%s%d",&si,&ni,str,&ki);
            if(str[0]=='g')
                e[i].init(si+ni,si-1,-ki-1);
            else
                e[i].init(si-1,si+ni,ki-1);
        }
        if(bf()) printf("lamentable kingdom\n");
        else printf("successful conspiracy\n");
    }
}
