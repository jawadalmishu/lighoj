#include<iostream>

#include<cstdio>

using namespace std;

struct info{

    long long sum;

    long long prop;

}tree[300027];

void update(long long node,long long b,long long e,long long i,long long j,long long x){

    if(i>e || j<b) return;

    if(i<=b && e<=j){

        tree[node].sum=tree[node].sum+(e-b+1)*x;

        tree[node].prop=tree[node].prop+x;

        return;

    }

    long long left=(node<<1);

    long long right=(node<<1)+1;

    long long mid=(b+e)>>1;

    update(left,b,mid,i,j,x);

    update(right,mid+1,e,i,j,x);

    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;

}

long long query(long long node,long long b,long long e,long long i,long long j,long long carry){

    if(i>e || j<b) return 0;

    if(i<=b && e<=j){

        return tree[node].sum+carry*(e-b+1);

    }

    long long left=(node<<1);

    long long right=(node<<1)+1;

    long long mid=(b+e)>>1;

    long long q1=query(left,b,mid,i,j,carry+tree[node].prop);

    long long q2=query(right,mid+1,e,i,j,carry+tree[node].prop);

    return q1+q2;

}

int main()

{

    long long test,n,q,a,x,y,val;

    scanf("%lld",&test);

    for(int i=0;i<test;i++){

        for(int k=0;k<=300027;k++){

            tree[k].sum=0;

            tree[k].prop=0;

        }

        scanf("%lld %lld",&n,&q);

        printf("Case %d:\n",i+1);

        for(int j=0;j<q;j++){

            scanf("%lld",&a);

            if(a==0){

                scanf("%lld %lld %lld",&x,&y,&val);

                update(1,1,n,x+1,y+1,val);

            }

            else if(a==1){

                scanf("%lld %lld",&x,&y);

                long long f=query(1,1,n,x+1,y+1,0);

                printf("%lld\n",f);

            }

        }

    }

    return 0;

}