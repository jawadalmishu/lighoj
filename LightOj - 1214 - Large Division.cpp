#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

using namespace std;

typedef long long ll;

int main()

{

    int test,j,k,l;

    ll b,n,ttl,sum;

    char str[500];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        sum=0;

        scanf("%s %llu",str,&b);

        b=abs(b);

        l=strlen(str);

        if(str[0]=='-') k=1;

        else k=0;

        for(j=k;j<l;j++){

            n=str[j]-48;

            sum=n+sum*10;

            if(sum>=b)

                sum=sum%b;

        }

        if(sum==0)

            printf("Case %d: divisible\n",i+1);

        else printf("Case %d: not divisible\n",i+1);

    }

    return 0;

}