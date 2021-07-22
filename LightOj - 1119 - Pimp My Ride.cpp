#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

int num,dp[33000],w[16][16];

bool check(int n,int pos) { return n= n & (1<<pos) ;}

int set(int n,int pos) { return n= n | (1<<pos) ;}

int bitmask(int mask){

    if((1<<num)-1==mask) return 0;

    if(dp[mask]!=-1) return dp[mask];

    int ret=1<<28;

    for(int i=0;i<num;i++){

        if(check(mask,i)==0){

            int price=w[i][i];

            for(int j=0;j<num;j++){

                if(i!=j && check(mask,j)!=0){

                    price=price+w[i][j];

                }

            }

            int ans=price+bitmask(set(mask,i));

            ret=min(ret,ans);

        }

    }

    return dp[mask]=ret;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        memset(dp,-1,sizeof(dp));

        scanf("%d",&num);

        for(int j=0;j<num;j++)

        for(int k=0;k<num;k++)

            scanf("%d",&w[j][k]);

        int ret=bitmask(0);

        printf("Case %d: %d\n",i+1,ret);

    }

    return 0;

}