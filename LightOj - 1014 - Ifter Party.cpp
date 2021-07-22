#include<iostream>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<cmath>

using namespace std;

typedef long long ll;

int main()

{

    int test;

    ll l,p,ttl;

    vector<ll>vc;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%lld %lld",&p,&l);

        ttl=p-l;

        printf("Case %d:",i+1);

        if(ttl<=l){

            printf(" impossible\n");

            continue;

        }

        ll j=1;

        while(j<=(ttl/j)){

            if(ttl%j==0){

                vc.push_back(j);

                if(j==ttl) break;

                if(j==(ttl/j)){

                    j++;

                    continue;

                }

                vc.push_back(ttl/j);

            }

            j++;

        }

        sort(vc.begin(),vc.end());

        for(int k=0;k<vc.size();k++){

            if(vc[k]>l)

            printf(" %lld",vc[k]);

        }

        printf("\n");

        vc.clear();

    }

    return 0;

}