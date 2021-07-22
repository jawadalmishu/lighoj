#include<cstdio>

#include<iostream>

using namespace std;

typedef long long ll;

ll n;

ll f(ll q){

    ll c=0;

    while(q>=5){

        c=c+q/5;

        q=q/5;

    }

    return c;

}

ll b(){

    ll q,low=0,high=10000000000;

    while(low<=high){

        if(high==low){

            q=f(high);

            if(q==n) return high;

            return -1;

        }

        ll mid=(low+high)/2;

        q=f(mid);

        if(q==n){

            high=mid;

        }

        else if(q>n) high=mid-1;

        else low=mid+1;

    }

    return -1;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%lld",&n);

        ll l=b();

        if(l != -1) printf("Case %d: %lld\n",i+1,l);

        else printf("Case %d: impossible\n",i+1);

    }

    return 0;

}