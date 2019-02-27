#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

char s[10050],x[150];

struct bignum{
    int a[105];
    int len;
    struct bignum operator +(const struct bignum rhs) const{
        struct bignum temp=*this;
        for(int i=0;i<rhs.len;i++){
            temp.a[i]+=rhs.a[i];
            if(temp.a[i]>=10){
                temp.a[i+1]+=temp.a[i]/10;;
                temp.a[i]%=10;
            }
        }
        while(temp.a[temp.len]) temp.len++;
        return temp;
    }
    void print(){
        if(len==0) printf("0");
        for(int i=len-1;i>=0;i--) printf("%d",a[i]);
    }
}d[10050][150];

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        int len1=0,len2=0;
        char ch;
        while((ch=getchar())!='\n'&&ch!=EOF){
            s[len1++]=ch;
        }
        while((ch=getchar())!='\n'&&ch!=EOF){
            x[len2++]=ch;
        }
        for(int i=0;i<len1;i++) for(int j=0;j<len2;j++) {d[i][j].len=0;memset(d[i][j].a,0,sizeof(d[i][j].a));}
        for(int i=len2-1;i>=0;i--){
            for(int j=len1-1;j>=0;j--){
                if(i==len2-1&&s[j]==x[i]){
                    d[j][i].a[0]=1;
                    d[j][i].len=1;
                    if(j!=len1-1) d[j][i]=d[j+1][i]+d[j][i];
                }
                else if(j==len1-1) continue;
                else if(s[j]==x[i]) d[j][i]=d[j+1][i+1]+d[j+1][i];
                else d[j][i]=d[j+1][i];
            }
        }
        if(len1==0||len2==0) printf("0");
        else d[0][0].print();
        if(t) printf("\n");
    }
    return 0;
}
