#include<cstdio>

#include<iostream>

#include<cmath>

using namespace std;

int main()

{

    int test,n,nominator,denominator,arr[110];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        int coun1=0,coun2=0,sum=0;

        for(int j=0;j<n;j++){

            scanf("%d",&arr[j]);

            sum=sum+abs(arr[j]);

            if(arr[j]<0)

                coun1++;

            else

                coun2++;

        }

        if(coun1==n){

            printf("Case %d: inf\n",i+1);

            continue;

        }

        nominator=sum;

        denominator=n-coun1;

        while(1){

            int kk;

            int nn=denominator;

            int dd=nominator;

            if(nn<dd){

                int tt=nn;

                nn=dd;

                dd=tt;

            }

            while(1){

                kk=nn%dd;

                if(kk==0) break;

                nn=dd;

                dd=kk;

            }

             if(dd==1) break;

            denominator=denominator/dd;

            nominator=nominator/dd;

        }

        printf("Case %d: %d/%d\n",i+1,nominator,denominator);

    }

    return 0;

}