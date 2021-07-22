#include<cstdio>

#include<iostream>

#include<algorithm>

using namespace std;

typedef long long ll;

ll sum;

int arr[2009];

int b_search(int low,int high){

    while(low<=high){

        if((high-low)==1){

            if(arr[high]<sum) return high;

            else return low;

        }

        if(low==high) return low;

        int mid=(low+high)/2;

        if(arr[mid]>=sum) high=mid-1;

        else low=mid;

    }

}

int main()

{

    int test,n;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            scanf("%d",&arr[j]);

        }

        sort(arr,arr+n);

        ll coun=0;

        for(int j=0;j<n-2;j++){

            for(int k=j+1;k<n-1;k++){

                sum=arr[j]+arr[k];

                int g=b_search(k+1,n-1);

                if(arr[g]<sum){

                    coun+=g-k;

                }

            }

        }

        printf("Case %d: %lld\n",i+1,coun);

    }

    return 0;

}