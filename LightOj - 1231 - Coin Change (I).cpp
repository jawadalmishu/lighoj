#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

#define mod 100000007

int n,k,a[55],c[55],taken[55],dp[51][1001][21];

int f(int i,int make,int t){

    if(i==n){

        if(make==k){

            return 1;

        }

        else return 0;

    }

    if(dp[i][make][t] != -1) return dp[i][make][t];

    int ret1=0,ret2=0;

    if(t+1<=c[i] && a[i]+make<=k){

        ret1=f(i,make+a[i],t+1);

    }

    ret2=f(i+1,make,0);

    return dp[i][make][t]=((ret1%mod)+(ret2%mod))%mod;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&k);

        for(int j=0;j<n;j++)

            scanf("%d",&a[j]);

        for(int j=0;j<n;j++)

            scanf ("%d",&c[j]);

        for(int j=0;j<=n;j++)

            for(int k=0;k<=1000;k++)

                for(int l=0;l<=20;l++)

                  dp[j][k][l]=-1;

        printf("Case %d: %d\n",i+1,f(0,0,0));

    }

    return 0;

}