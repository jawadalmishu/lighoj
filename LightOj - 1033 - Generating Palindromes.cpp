#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

char str[110];

int c=0,length,dp[105][105],vis[105][105];

int ispalindrome(int i,int j){

    if(vis[i][j]==c) return dp[i][j];

    if(i>j) return 100000000;

    if(i==j) return 0;

    if(str[i]==str[j]){

        if(i+1==j) return 0;

        dp[i][j]=ispalindrome(i+1,j-1);

    }

    else dp[i][j]=min(ispalindrome(i+1,j),ispalindrome(i,j-1))+1;

    vis[i][j]=c;

    return dp[i][j];

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        --c;

        scanf("%s",str);

        int length=strlen(str);

        printf("Case %d: %d\n",i+1,ispalindrome(0,length-1));

    }

    return 0;

}