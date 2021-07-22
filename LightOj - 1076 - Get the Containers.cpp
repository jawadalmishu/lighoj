#include<iostream>

#include<cstdio>

using namespace std;

typedef long long ll;

int n,m,arr[1009];

ll checking(ll mx_cap){

    ll sum=0;

    ll ans=1;

    for(int i=0;i<n;i++){

        if(sum+arr[i]<=mx_cap)

            sum+=arr[i];

        else{

            ans++;

            sum=arr[i];

        }

    }

    return ans;

}

ll bin_search(ll low,ll high)

{

    ll mid;

    while(low<=high){

        if(low==high) return low;

        mid=(high+low)/2;

        ll p=checking(mid);

        if(p==m) high=mid;

        else if(p>m) low=mid+1;

        else high=mid-1;

    }

    return mid;

}

int main()

{

    int test;

    ll mx,sum;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        mx=-1;

        sum=0;

        scanf("%d %d",&n,&m);

        for(int j=0;j<n;j++){

            scanf("%d",&arr[j]);

            if(arr[j]>mx) mx=arr[j];

            sum+=arr[j];

        }

        printf("Case %d: %lld\n",i+1,bin_search(mx,sum));

    }

    return 0;

}