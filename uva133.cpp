#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[21];

int go(int  pos,int b,int f,int n)
{
    for(int i=0;i<b;i++)
    {
        do{pos=(pos+f+n-1)%n+1;} while(a[pos]);
    }
    return pos;
}

int main()
{
    int n,k,m,R,L;
    while(cin>>n>>k>>m&&n)
    {
        memset(a,0,sizeof(a));
        L=0;
        R=n+1;
        for(int i=n;i>0;)
        {
            if(i!=n) printf(",");
            L=go(L,k,1,n);
            R=go(R,m,-1,n);
            if(R==L) {printf("%3d",R);i-=1;a[R]=1;}
            else {printf("%3d%3d",L,R);i-=2;a[L]=a[R]=1;}
        }
        printf("\n");
    }
    return 0;
}
