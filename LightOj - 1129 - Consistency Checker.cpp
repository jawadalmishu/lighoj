#include<cstdio>

#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

int pt;

struct node{

    bool endmark;

    node *next[15];

    node(){

        endmark=false;

        for(int i=0;i<=10;i++)

            next[i]=NULL;

    }

}*root;

void inserts(string str){

    node *curr=root;

    int len=str.length();

    for(int i=0;i<len;i++){

        int id=str[i]-48;

        if(curr->endmark==true){

            pt=1;

            break;

        }

        if(curr->next[id]==NULL)

            curr->next[id]=new node();

        curr=curr->next[id];

    }

    curr->endmark=true;

}

bool cmp(string a,string b){

    return a.length()<b.length();

}

void del(node *curr){

    for(int i=0;i<=9;i++)

        if(curr->next[i])

          del(curr->next[i]);

    delete(curr);

}

int main()

{

    int test,n;

    string str;

    vector<string>vc;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        pt=0;

        root=new node();

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            cin>>str;

            vc.push_back(str);

        }

        sort(vc.begin(),vc.end(),cmp);

        for(int j=0;j<vc.size();j++){

            if(pt==0)

              inserts(vc[j]);

            else break;

        }

        if(pt==0)  printf("Case %d: YES\n",i+1);

        else printf("Case %d: NO\n",i+1);

        del(root);

        vc.clear();

    }

    return 0;

}