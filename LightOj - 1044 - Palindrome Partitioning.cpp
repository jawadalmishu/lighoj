#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

char str[1005];

int l,c=0,dp[1002],vis[1002];

bool is_palindrome(int beg,int ends){

    for(int i=beg,j=ends;i<=j;i++,j--)

        if(str[i]!=str[j])

            return false;

    return true;

}

int f(int beg){

    if(beg==l) return 0;

    if(vis[beg]==c) return dp[beg];

    int ans=100000000;

    for(int i=beg;i<l;i++){

        if(is_palindrome(beg,i)) ans=min(ans,1+f(i+1));

    }

    vis[beg]=c;

    return dp[beg]=ans;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        --c;

        scanf("%s",&str);

        l=strlen(str);

        for(int j=0;j<l;j++){

            dp[j]=1;

        }

        printf("Case %d: %d\n",i+1,f(0));

    }

    return 0;

}