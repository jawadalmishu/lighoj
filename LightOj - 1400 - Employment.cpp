#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

int preference[205][105],company[105],n;

bool pref(int m,int m1,int comp){

    for(int j=1;j<=n;j++){

        if(preference[comp][j]==m)

            return false;

        if(preference[comp][j]==m1)

            return true;

    }

}

void stable_marriage(){

    bool candidate[105];

    memset(company,-1,sizeof(company));

    memset(candidate,false,sizeof(candidate));

    int freecandidate=n;

    while(freecandidate>=1){

        int m;

        for(m=1;m<=n;m++)

            if(candidate[m]==false)

                break;

        for(int j=1;j<=n && candidate[m]==false;j++){

            int comp=preference[m][j];

            if(company[comp-n]==-1){

                company[comp-n]=m;

                candidate[m]=true;

                freecandidate--;

            }

            else{

                int m1=company[comp-n];

                if(pref(m,m1,comp)==false){

                    company[comp-n]=m;

                    candidate[m]=true;

                    candidate[m1]=false;

                }

            }

        }

    }

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=1;j<=2*n;j++)

            for(int k=1;k<=n;k++)

            scanf("%d",&preference[j][k]);

        stable_marriage();

        printf("Case %d:",i+1);

        for(int j=1;j<=n;j++)

            printf(" (%d %d)",company[j],j+n);

        printf("\n");

    }

    return 0;

}