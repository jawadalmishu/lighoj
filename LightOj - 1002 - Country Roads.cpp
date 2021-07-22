#include<cstdio>

#include<iostream>

#include<vector>

#include<queue>

#include<cstring>

using namespace std;

vector<int>graph[509];

int cost[502][502];

int t,c2[509];

struct node{

    int u,w;

    node(int a,int b) {u=a; w=b;}

    bool operator < (const node & p) const { return w > p.w ; }

};

void dijkstra(int src){

    priority_queue<node>q;

    q.push(node(src,0));

    int visited[509],mx=21000,k,parent[509];

    memset(c2,0,sizeof(c2));

    memset(visited,0,sizeof(visited));

    memset(parent,-1,sizeof(parent));

    visited[src]=1;

    while(!q.empty()){

        node tp=q.top();

        q.pop();

        int u=tp.u;

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(v==src || v==parent[u]) continue;

                if(visited[v]==1){

                    k=max(cost[u][v],c2[u]);

                    if(k<c2[v]){

                        c2[v]=k;

                        q.push(node(v,c2[v]));

                    }

                    continue;

                }

                visited[v]=1;

                k=max(cost[u][v],c2[u]);

                parent[v]=u;

                if(k>c2[v]){

                    c2[v]=k;

                    q.push(node(v,c2[v]));

                }

        }

    }

}

int main()

{

    int test,n,m,u,v,w,visit[502][502];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        memset(visit,0,sizeof(visit));

        scanf("%d %d",&n,&m);

        for(int j=0;j<m;j++){

            scanf("%d %d %d",&u,&v,&w);

            if(visit[u][v]==0){

                graph[u].push_back(v);

                graph[v].push_back(u);

                cost[u][v]=w;

                cost[v][u]=w;

                visit[u][v]=1;

                visit[v][u]=1;

            }

            else{

                cost[u][v]=min(cost[u][v],w);

                cost[v][u]=cost[u][v];

            }

        }

        scanf("%d",&t);

        dijkstra(t);

        printf("Case %d:\n",i+1);

        for(int j=0;j<n;j++){

            if(j==t){

                printf("0\n");

                continue;

            }

            if(m==0){

                printf("Impossible\n");

                continue;

            }

            if(c2[j]==0)

                printf("Impossible\n");

            else

                printf("%d\n",c2[j]);

        }

        for(int j=0;j<=500;j++){

            graph[j].clear();

        }

    }

    return 0;

}