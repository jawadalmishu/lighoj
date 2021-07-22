#include<cstdio>

#include<iostream>

#include<cstring>

#include<cmath>

using namespace std;

int mx;

struct node{

    node *next[4];

    int q;

    node(){

        for(int i=0;i<4;i++){

            q=0;

            next[i]=NULL;

        }

    }

}*root;

void inserts(char *str){

    node *curr=root;

    int l=strlen(str);

    for(int i=0;i<l;i++){

        int id;

        if(str[i]=='A') id=0;

        else if(str[i]=='C') id=1;

        else if(str[i]=='G') id=2;

        else if(str[i]=='T') id=3;

        if(curr->next[id]==NULL)

            curr->next[id]=new node();

        curr=curr->next[id];

        curr->q++;

        int k=curr->q;

        if(k*(i+1)>mx)

            mx=k*(i+1);

    }

}

void del(node *curr){

    for(int i=0;i<4;i++)

    if(curr->next[i])

        del(curr->next[i]);

    delete(curr);

}

int main()

{

    int test,n;

    char str[60];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        root=new node();

        scanf("%d",&n);

        mx=0;

        for(int j=0;j<n;j++){

            scanf("%s",&str);

            int l=strlen(str);

            mx=max(mx,l);

            inserts(str);

        }

        printf("Case %d: %d\n",i+1,mx);

        del(root);

    }

    return 0;

}