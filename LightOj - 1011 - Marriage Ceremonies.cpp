#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

bool check(int n,int pos) { return (bool)(n = n & (1<<pos)); }

int set(int n,int pos) { return n = n | (1<<pos); }

int m[17][17],dp[17][65600],n;

int f(int level,int mask){

    if(level==n) return 0;

    if(mask>=((1<<n)-1)) return 0;

    if(dp[level][mask]!=-1) return dp[level][mask];

    int ans=-(1<<28),ret=0;

    for(int i=0;i<n;i++){

        if(i>level-1 && i<level+1){

            for(int j=0;j<n;j++){

                if(check(mask,j)==0){

                    ret=m[i][j]+f(level+1,set(mask,j));

                }

                ans=max(ret,ans);

            }

        }

    }

    return dp[level][mask]=ans;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        memset(dp,-1,sizeof(dp));

        scanf("%d",&n);

        for(int j=0;j<n;j++)

        for(int k=0;k<n;k++)

        scanf("%d",&m[j][k]);

        int g=f(0,0);

        printf("Case %d: %d\n",i+1,g);

    }

    return 0;

}

