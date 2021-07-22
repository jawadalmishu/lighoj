#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

char str[100005];

int m,p,tree[300015];

void update(int n,int b,int e,int i,int j){

    if(b>j || e<i) return;

    if(i<=b && e<=j){

        tree[n]++;

        return;

    }

    int mid=(b+e)/2;

    int l=2*n;

    int r=(2*n)+1;

    update(l,b,mid,i,j);

    update(r,mid+1,e,i,j);

}

void query(int n,int b,int e,int i,int carry){

    if(b>i || e<i) return;

    if(i==b && e==i){

        p=1;

        m=carry+tree[n];

        return;

    }

    int mid=(b+e)/2;

    int left=2*n;

    int right=(2*n)+1;

    if(p==1) return;

    query(left,b,mid,i,carry+tree[n]);

    if(p==1) return;

    query(right,mid+1,e,i,carry+tree[n]);

}

/*void build(int n,int b,int e){

    if(b==e)

    {

        tree[n].x=str[b-1]-'0';

        return;

    }

    int left=2*n;

    int right=(2*n)+1;

    int mid=(b+e)/2;

    build(left,b,mid);

    build(right,mid+1,e);

}*/

int main()

{

    int test,q,a,b;

    char ch;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        memset(tree,0,sizeof(tree));

        scanf("%s",str);

        int length=strlen(str);

        scanf("%d",&q);

        printf("Case %d:\n",i+1);

        for(int j=0;j<q;j++){

            scanf("%c",&ch);

            if(ch==' ' || ch=='\n'){

                j--;

                continue;

            }

            if(ch=='I'){

                scanf("%d %d",&a,&b);

                update(1,1,length,a,b);

            }

            else if(ch=='Q'){

                scanf("%d",&a);

                p=0;

                query(1,1,length,a,0);

                if(m%2){

                    if(str[a-1]=='1') printf("0\n");

                    else printf("1\n");

                }

                else printf("%c\n",str[a-1]);

            }

        }

    }

    return 0;

}