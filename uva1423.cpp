#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<algorithm>
using namespace std;

int p[100];
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

int main(){
    int t,n,in[100],w[100][100],fa[100],b[100];
    char s[1000];
    scanf("%d",&t);
    while(t--){
        memset(in,0,sizeof(in));
        memset(fa,-1,sizeof(fa));
        memset(w,0,sizeof(w));
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<=n;i++) p[i]=i;
        int pos=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[pos]=='0'){
                    int x=find(j);
                    int y=find(i-1);
                    if(x!=y) p[j]=y;
                }
                pos++;
            }
        }
        pos=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[pos]=='-'){
                    in[p[j]]+=1;
                    w[p[i-1]][p[j]]+=1;
                }
                else if(s[pos]=='+'){
                    in[p[i-1]]+=1;
                    w[p[j]][p[i-1]]+=1;
                }
                pos++;
            }
        }


        pos=0;
        for(int i=0;i<=n;i++){
            int ok=1;
            for(int j=0;j<pos;j++){
                if(fa[j]==p[i]) {ok=0;break;}
            }
            if(ok) fa[pos++]=p[i];
        }

        stack<int> q;
        while(1){
            int ok=1;
            for(int i=0;i<pos;i++){
                if(fa[i]==-1) continue;
                if(in[fa[i]]==0){
                    q.push(fa[i]);
                    for(int j=0;j<pos;j++){
                        if(w[fa[i]][fa[j]]) in[fa[j]]-=w[fa[i]][fa[j]];
                    }
                    ok=0;
                    fa[i]=-1;
                }
            }
            if(ok) break;
        }
        int ans=0;
        while(!q.empty()){
            int x=q.top();q.pop();
            for(int i=0;i<=n;i++){
                if(p[i]==x) {
                    b[i]=ans;
                }
            }
            ans++;
        }
        for(int i=1;i<n;i++) printf("%d ",b[i]-b[i-1]);
        printf("%d\n",b[n]-b[n-1]);
    }

}
