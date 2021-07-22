#include<iostream>

#include<cstdio>

using namespace std;

int arr[100009],tree[300027];

void init(int node,int b,int e){

    if(b==e){

        tree[node]=arr[b];

        return;

    }

    int left=node*2;

    int right=node*2+1;

    int mid=(b+e)/2;

    init(left,b,mid);

    init(right,mid+1,e);

    tree[node]=tree[left]+tree[right];

}

void update(int node,int b,int e,int i,int newvalue){

    if(i>e || i<b) return;

    if(b>=i && e<=i){

        printf("%d\n",tree[node]);

        tree[node]=newvalue;

        return;

    }

    int left=node*2;

    int right=node*2+1;

    int mid=(b+e)/2;

    update(left,b,mid,i,newvalue);

    update(right,mid+1,e,i,newvalue);

    tree[node]=tree[left]+tree[right];

}

void add(int node,int b,int e,int i,int addvalue){

    if(i>e || i<b) return;

    if(b>=i && e<=i){

        tree[node]=tree[node]+addvalue;

        return;

    }

    int left=node*2;

    int right=node*2+1;

    int mid=(b+e)/2;

    add(left,b,mid,i,addvalue);

    add(right,mid+1,e,i,addvalue);

    tree[node]=tree[left]+tree[right];

}

int query(int node,int b,int e,int i,int j){

    if(i>e || j<b) return 0;

    if(i<=b && e<=j) return tree[node];

    int left=node*2;

    int right=node*2+1;

    int mid=(b+e)/2;

    int q1=query(left,b,mid,i,j);

    int q2=query(right,mid+1,e,i,j);

    return q1+q2;

}

int main()

{

    int test,n,q,a,b,c,d,f;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&q);

        for(int j=1;j<=n;j++) scanf("%d",&arr[j]);

        init(1,1,n);

        printf("Case %d:\n",i+1);

        for(int k=0;k<q;k++){

            scanf("%d",&a);

            if(a==1){

                scanf("%d",&b);

                update(1,1,n,b+1,0);

            }

            else if(a==2){

                scanf("%d %d",&c,&d);

                add(1,1,n,c+1,d);

            }

            else if(a==3){

                scanf("%d %d",&c,&d);

                f=query(1,1,n,c+1,d+1);

                printf("%d\n",f);

            }

        }

    }

    return 0;

}