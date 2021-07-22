#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

int mat[200][101];

int r,c,dp[200][101];

#define inf 1<<28

long long call(int i,int j){

    if(i>=0 && i<=r-1 && j>=0 && j<c){

        if(dp[i][j]!=-1) return dp[i][j];

        long long ret=-inf;

        ret=max(ret,call(i+1,j)+mat[i][j]);

        ret=max(ret,call(i+1,j+1)+mat[i][j]);

        return dp[i][j]=ret;

    }

    else return 0;

}

int main()

{

    int test,n,ll;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        memset(dp,-1,sizeof(dp));

        scanf("%d",&n);

        c=n;r=2*n-1;

        for(int j=0;j<2*n-1;j++)

        for(int k=0;k<n;k++){

            mat[j][k]=0;

        }

        for(int j=0;j<n;j++){

            for(int k=0;k<=j;k++){

                scanf("%d",&mat[j][k]);

            }

        }

        ll=n-1;

        for(int j=n;j<2*n-1;j++){

            for(int k=n-ll;k<n;k++){

                scanf("%d",&mat[j][k]);

            }

            ll--;

        }

        printf("Case %d: %lld\n",i+1,call(0,0));

    }

    return 0;

}