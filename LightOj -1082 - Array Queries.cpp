#include<iostream>

#include<cstdio>

using namespace std;

int arr[100020];

int tree[300060];

void init(int node,int b,int e){

    if(b==e){

        tree[node]=arr[b];

        return;

    }

    int mid=(b+e)/2;

    int left=node*2;

    int right=node*2+1;

    init(left,b,mid);

    init(right,mid+1,e);

    tree[node]=min(tree[left],tree[right]);

}

int query(int node,int b,int e,int i,int j){

    if(i>e || j<b) return 1000000000;

    if(i<=b && e<=j) return tree[node];

    int mid=(b+e)/2;

    int left=node*2;

    int right=node*2+1;

    int l=query(left,b,mid,i,j);

    int r=query(right,mid+1,e,i,j);

    return min(l,r);

}

int main()

{

    int test,n,q,q1,q2;

    scanf("%d\n",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&q);

        for(int j=1;j<=n;j++) scanf("%d",&arr[j]);

        init(1,1,n);

        printf("Case %d:\n",i+1);

        for(int j=0;j<q;j++){

            scanf("%d %d",&q1,&q2);

            int mn=query(1,1,n,q1,q2);

            printf("%d\n",mn);

        }

    }

    return 0;

}