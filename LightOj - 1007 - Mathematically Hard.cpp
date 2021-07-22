#include<cstdio>

#include<iostream>

#include<cmath>

using namespace std;

bool check(int N,int pos) { return (bool) (N & (1<<pos)) ; }

int sets(int N,int pos) { return N=N|(1<<pos);}

unsigned long long phi[5000009];

int phi2[5000009];

int status[157000];

/*

Formula: phi(n)=n*(1-1/p1)*(1-1/p2)*......infinity

               =n*(p1-1)/p1*(p2-1)/p2*....infinity

calculating phi, its enough to produce prime up to sqrt (5 * 10 ^ 6)

we need to produce phi value for every number up to 5 * 10 ^ 6

in this case, you are looping from 2 to 5 * 10 ^ 6

Example:

    for ( k = 2; k <= 5000000; k++ ) {

        for ( i = 0; prime [i] < sqrt (k); i++ ) {

            // ...

        }

    }

    complexity: n * sqrt (n)

this complexity confirms a TLE



you can compute the phi value of every number, while generating prime numbers



phi (n) = n * ( 1 - 1/p1 ) ( 1 - 1/p2 ) * ( 1 - 1/p3 ) ....

or, phi (n) = n * ((p1 - 1)/p1) * ((p2 - 1)/p2) * ((p3 - 1)/p3) ...



when you find that 2 is a prime then

complete the calculation of phi for every number which is a multiple of 2



for example

    Example:

    if (i is a prime) {

    for ( j = i; j <= 5000000; j += i ) {

        phi [j] *= (i - 1);//see the formula on the top

        phi [j] /= i;

    }

}



*/

void is_prime(){

    int n=sqrt(5000000);

    for(int i=2;i<=5000000;i=i+2){

        phi[i]=phi[i]-phi[i]/2;

        while(phi2[i]%2==0)

            phi2[i]=phi2[i]/2;

    }

    for(int i=3;i<=n;i+=2){

        if(check(status[i/32],i%32)==0){

            for(int j=i;j<=5000000;j=j+i){

                if(phi2[j]%i==0){

                    phi[j]=phi[j]-phi[j]/i;

                    while(phi2[j]%i==0)

                        phi2[j]=phi2[j]/i;

                }

                status[j/32]=sets(status[j/32],j%32);

            }

        }

    }

}

/*void phi_function()

{

    phi[2]=1;

    phi[3]=2;

    for(int i=4;i<=5000000;i++)

    {

        if(i%2!=0 && check(status[i/32],i%32)==1)

        {

            phi[i]=i-1;

            continue;

        }

        int result=i;

        int n=i;

        if(result%2==0)

        {

            result=result-result/2;

            while(n%2==0)

                n=n/2;

        }

        int q=3;

        while(n%q==0 && q*q<=n)

        {

            result=result-result/q;

            while(n%q==0)

                n=n/q;

            q=q+2;

        }

        if(n>1) result=result-result/n;

        phi[i]=result;

    }

}*/

int main()

{

    for(int i=2;i<=5000000;i++){

        phi[i]=i;

        phi2[i]=i;

    }

    is_prime();

    phi[1]=0;

    for(int i=2;i<=5000000;i++){

        if(phi2[i]>1) phi[i]=phi[i]-phi[i]/phi2[i];

        phi[i]=phi[i]*phi[i];

        phi[i]=phi[i]+phi[i-1];

    }

    //phi_function();

    int test,a,b;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&a,&b);

        /*for(int j=a;j<=b;j++){

            ttl=ttl+phi[j]*phi[j];

        }*/

        printf("Case %d: %llu\n",i+1,phi[b]-phi[a-1]);

    }

    return 0;

}