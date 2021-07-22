#include<iostream>

#include<cstdio>

#include<vector>

#include<cmath>



using namespace std;

typedef long long ll;



bool check(int N,int pos) { return (bool) (N & (1<<pos)) ; }

int sets(int N,int pos) { return N = N | (1<<pos) ; }

int status[31300];

vector<int>prime;



void is_prime(){

    int sq=sqrt(1000009);

    for(int i=3;i<=sq;i+=2){

        if(check(status[i/32],i%32)==0){

            for(int j=i*i;j<=1000009;j+=2*i){

                status[j/32]=sets(status[j/32],j%32);

            }

        }

    }

    prime.push_back(2);

    for(int i=3;i<=1000009;i+=2)

        if(check(status[i/32],i%32)==0)

            prime.push_back(i);

}

int main()

{

    is_prime();

    ll n,counts,ttl;

    int test,q;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%lld",&n);

        q=0;

        ttl=1;

        while(prime[q]<=(n/prime[q])){

            if(n%prime[q]==0){

                counts=0;

                while(n%prime[q]==0){

                    n=n/prime[q];

                    counts++;

                }

                ttl=ttl*(counts+1);

            }

            q++;

        }

        if(n>1) ttl=ttl*2;

        ttl--;

        printf("Case %d: %lld\n",i+1,ttl);

    }

    return 0;

}