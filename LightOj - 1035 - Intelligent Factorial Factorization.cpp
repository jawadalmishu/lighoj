#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

using namespace std;

struct node{

    int a[100];

    /*node()

    {

        memset(a,0,sizeof(a));

    }*/

};

int main(){

    struct node e[105];

    for(int i=2;i<=100;i++)

        for(int j=2;j<=97;j++)

            e[i].a[j]=0;

    int prime[7]={2,3,5,7,11},k,counts,on,test,n;

    for(int i=2;i<=100;i++){

        k=i;

        for(int j=0;j<=4;j++){

            counts=0;

            if(k%prime[j]==0){

                while(k%prime[j]==0){

                    k=k/prime[j];

                    counts++;

                }

                e[i].a[prime[j]]=counts;

            }

        }

        if(k>1) e[i].a[k]++;

    }

    for(int i=3;i<=100;i++){

        for(int j=2;j<=98;j++){

            e[i].a[j]=e[i].a[j]+e[i-1].a[j];

        }

    }

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        on=0;

        printf("Case %d: %d = ",i+1,n);

        for(int j=2;j<=97;j++){

            if(on==0 && e[n].a[j]>0){

                on=1;

                printf("%d (%d)",j,e[n].a[j]);

            }

            else if(on==1 && e[n].a[j]>0){

                printf(" * %d (%d)",j,e[n].a[j]);

            }

        }

        printf("\n");

    }

    return 0;

}