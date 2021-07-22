#include<iostream>

#include<cstdio>

#include<vector>

#include<cstring>

#include<queue>

using namespace std;

vector<int>graph[105];

vector<int>cost[105];

int d[105];

struct node{

    int x,y;

    node(int a,int b){

        x=a;

        y=b;

    }

    bool operator < (const node & p) const{

        return y > p.y;

    }

};

int dijkstra(int n){

    for(int i=0;i<=105;i++) d[i]=100000000;

    priority_queue<node>q;

    q.push(node(1,0));

    d[1]=0;

    while(!q.empty()){

        node top=q.top();

        int u=top.x; q.pop();

        if(u==n) return d[n];

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(d[v]>d[u]+cost[u][i]){

                d[v]=d[u]+cost[u][i];

                q.push(node(v,d[v]));

            }

        }

    }

    return -1;

}

int main()

{

    int test,n,m,u,v,w;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&m);

        for(int j=0;j<m;j++){

            scanf("%d %d %d",&u,&v,&w);

            graph[u].push_back(v);

            graph[v].push_back(u);

            cost[u].push_back(w);

            cost[v].push_back(w);

        }

        int g=dijkstra(n);

        if(g==-1) printf("Case %d: Impossible\n",i+1);

        else printf("Case %d: %d\n",i+1,g);

        for(int j=0;j<105;j++){

            graph[j].clear();

            cost[j].clear();

        }

    }

    return 0;

}

