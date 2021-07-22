#include<cstdio>

#include<iostream>

#include<cstring>

#include<vector>

using namespace std;

char str1[35],str2[35],str3[35];

int dp[35][35],st;

typedef long long ll;

ll dp2[61][35][35];

int lcs(int i,int j){

    if(str1[i]=='\0' || str2[j]=='\0') return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans;

    if(str1[i]==str2[j]) ans=1+lcs(i+1,j+1);

    else ans=max(lcs(i+1,j),lcs(i,j+1));

    return dp[i][j]=ans;

}

ll unq(int l,int i,int j){

    if(l==st){

        if(str1[i]=='\0' && str2[j]=='\0') return 1;

        return 0;

    }

    if(dp2[l][i][j]!=-1) return dp2[l][i][j];

    ll ans=0;

    if(str1[i]==str2[j]) ans+=unq(l+1,i+1,j+1);

    else{

        if(str1[i]!='\0' && str2[j]!='\0'){

             ans+=unq(l+1,i,j+1);

             ans+=unq(l+1,i+1,j);

        }

        else{

            if(str1[i]=='\0') ans+=unq(l+1,i,j+1);

            else ans+=unq(l+1,i+1,j);

        }

    }

    return dp2[l][i][j]=ans;

}

int main()

{

    int test;

    char ch;

    scanf("%d",&test);

    scanf("%c",&ch);

    for(int i=0;i<test;i++){

        fgets(str1,35,stdin);

        str1[strlen(str1)-1]='\0';

        fgets(str2,35,stdin);

        str2[strlen(str2)-1]='\0';

        int l1=strlen(str1);

        int l2=strlen(str2);

        if(l1==0 && l2==0){

            printf("Case %d: 0 0\n",i+1);

            continue;

        }

        if(l1==0 || l2==0){

            int l=l1+l2;

            printf("Case %d: %d %d\n",i+1,l,l);

            continue;

        }

        memset(dp,-1,sizeof(dp));

        st=l1+l2-lcs(0,0);

        for(int j=0;j<=st;j++)

            for(int k=0;k<=31;k++)

             for(int m=0;m<=31;m++)

              dp2[j][k][m]=-1;

        ll q=unq(0,0,0);

        printf("Case %d: %d %lld\n",i+1,st,q);

    }

    return 0;

}