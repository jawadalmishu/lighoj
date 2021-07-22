#include<cstdio>

#include<iostream>

#include<cstring>

#include<map>

using namespace std;

int n,arr[100009];

int binary1(int num){

    int low=0,high=n-1;

    while(low<=high){

        int mid=(high+low)/2;

        if(arr[mid]==num) return mid;

        if(high==low){

            if(arr[high]<num){

                if(high+1<n) return high+1;

                else return high;

            }

            else return high;

        }

        if(arr[mid]>num) high=mid-1;

        else low=mid+1;

        if(low>high) return low;

    }

}

int binary2(int num){

    int low=0,high=n-1;

    while(low<=high){

        int mid=(high+low)/2;

        if(arr[mid]==num) return mid;

        if(high==low){

            if(arr[high]>num){

                if(high-1>=0) return high-1;

                else return high;

            }

            else return high;

        }

        if(arr[mid]>num) high=mid-1;

        else low=mid+1;

        if(low>high) return high;

    }

}

int main()

{

    int test,o,p,q;

    map<int,int>c;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&q);

        c.clear();

        for(int j=0;j<n;j++){

            scanf("%d",&arr[j]);

            c[arr[j]]=1;

        }

        printf("Case %d:\n",i+1);

        for(int j=0;j<q;j++){

            scanf("%d %d",&o,&p);

            if(o>arr[n-1]){

                printf("0\n");

                continue;

            }

            if(o==p){

                if(c[p]==1) printf("1\n");

                else printf("0\n");

                continue;

            }

            int mm=binary2(p);

            int nn=binary1(o);

            if(mm<nn){

                printf("0\n");

                continue;

            }

            if(mm==nn){

                printf("1\n");

                continue;

            }

            printf("%d\n",mm-nn+1);

        }

    }

    return 0;

}

/*

1

5 10

1 4 6 8 10

*/