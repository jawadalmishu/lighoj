#include<cstdio>

#include<iostream>

#include<cmath>

#include<vector>

using namespace std;

bool check(int N,int pos) { return (bool) (N & (1<<pos)) ; }

int sets(int N,int pos) { return N = N | (1<<pos) ; }

int status[2000];

vector<int>pr;

int f(int a,int b){

    int arr[100009];

    for(int i=0;i<=100006;i++) arr[i]=0;

    int coun=0,k,l=pr.size();

    long long m;

    for(int i=0;i<l;i++){

        if(pr[i]>b) break;

        m=(a/pr[i])*pr[i];

        if(m==0) m=m+2*pr[i];

        if(m==pr[i] || m<a) m=m+pr[i];

        if(m>b) break;

        for(long long j=m;j<=b;j=j+pr[i]){

            arr[j-a]=1;

        }

    }

    if(a%2==0) k=a+1;

    else if(a==1) k=3;

    else k=a;

    for(long long i=k;i<=b;i+=2){

        if(arr[i-a]==0) coun++;

    }

    if(a<=2 && b>=2) coun++;

    return coun;

}

void p(){

    int srt=sqrt(2147483648);

    int srt2=sqrt(srt);

    for(int i=3;i<=srt2;i+=2){

        if(check(status[i/32],i%32)==0){

            for(int j=i*i;j<=srt;j=j+i){

                status[j/32]=sets(status[j/32],j%32);

            }

        }

    }

    for(int i=3;i<=srt;i+=2)

        if(check(status[i/32],i%32)==0)

          pr.push_back(i);

}

int main()

{

    int test,a,b;

    p();

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&a,&b);

        printf("Case %d: %d\n",i+1,f(a,b));

    }

    return 0;

}