#include<cstdio>

#include<vector>

#include<cstring>

#include<queue>

#include<iostream>

using namespace std;

bool visited[10009];

int n,times,parent[10009],disc[10009],low[10009];

struct node{

    int x,y;

    node(int a,int b){

        x=a;

        y=b;

    }

    bool operator < (const node & p) const{

        if(x==p.x) return y>p.y;

        else return x>p.x;

    }

};

priority_queue<node>q;

vector<int>graph[10009];

void bridgeutil(int u){

    visited[u]=true;

    low[u]=disc[u]=++times;

    for(int i=0;i<graph[u].size();i++){

        int v=graph[u][i];

        if(!visited[v]){

            parent[v]=u;

            bridgeutil(v);

            low[u]=min(low[u],low[v]);

            int mm=u;

            int nn=v;

            if(low[v]>disc[u]){

                if(u>v)

                    swap(mm,nn);

                q.push(node(mm,nn));

            }

        }

        else if(v!=parent[u])

            low[u]=min(low[u],disc[v]);

    }

}

void bridge(){

    for(int i=0;i<=n;i++){

        parent[i]=-1;

        visited[i]=false;

    }

    for(int i=0;i<n;i++){

        if(!visited[i])

            bridgeutil(i);

    }

}

int main()

{

    int test,u,k,v;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            scanf("%d (%d)",&u,&k);

            for(int l=0;l<k;l++){

                scanf("%d",&v);

                graph[u].push_back(v);

            }

        }

        times=0;

        bridge();

        printf("Case %d:\n",i+1);

        printf("%d critical links\n",q.size());

        while(!q.empty()){

            node top=q.top();

            q.pop();

            printf("%d - %d\n",top.x,top.y);

        }

        for(int j=0;j<=n+1;j++){

            graph[j].clear();

        }

    }

    return 0;

}

