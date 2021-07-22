#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

typedef unsigned long long int ull;

ull dp[31][31];

ull ncr(ull n,ull r){

    if(n==r) return 1;

    if(r==1) return n;

    if(dp[n][r]!=-1) return dp[n][r];

    return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);

}

int main()

{

    ull test;

    ull n,k,m,result,npr,f,fact[31];

    scanf("%llu",&test);

    for(ull i=0;i<test;i++){

        memset(dp,-1,sizeof(dp));

        scanf("%llu %llu",&n,&k);

        if(k==0){

            printf("Case %llu: 1\n",i+1);

            continue;

        }

        if(k>n){

            printf("Case %llu: 0\n",i+1);

            continue;

        }

        fact[0] = 1;

        for (ull j = 1; j <= k; j++){

            fact[j] = j * fact[j - 1];

        }

        f=ncr(n,k);

        npr=fact[k]*f;

        result=npr*f;

        printf("Case %llu: %llu\n",i+1,result);

    }

    return 0;

}