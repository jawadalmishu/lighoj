#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

#define inf 1<<28

int r,c=3,mat[20][3],dp[21][4],n;

int mat1(int i,int j){

    if(i>=0 && i<r && j>=0 &&j<3){

        if(dp[i][j]!=-1) return dp[i][j];

        int ret=inf;

        ret=min(ret,mat1(i+1,j+1)+mat[i][j]);

        ret=min(ret,mat1(i+1,j+2)+mat[i][j]);

        ret=min(ret,mat1(i+1,j-1)+mat[i][j]);

        ret=min(ret,mat1(i+1,j-2)+mat[i][j]);

        return dp[i][j]=ret;

    }

    else if(i==n) return 0;

    else return 100000;

}

int main()

{

    int test,ret;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        ret=inf;

        memset(dp,-1,sizeof(dp));

        scanf("\n%d",&n);

        r=n;

        for(int j=0;j<n;j++)

         for(int k=0;k<3;k++)

        scanf("%d",&mat[j][k]);

        ret=min(ret,mat1(0,0));

        ret=min(ret,mat1(0,1));

        ret=min(ret,mat1(0,2));

        printf("Case %d: %d\n",i+1,ret);

    }

    return 0;

}