#include<iostream>

#include<cstdio>

#include<vector>

#include<cstring>

#include<queue>

#include<cmath>

using namespace std;

long long cost1[30009],cost2[30009];

vector<int>graph[30009],cost[30009];

int bfs(int src){

    queue<int>q;

    q.push(src);

    int visited[30009];

    memset(visited,0,sizeof(visited));

    visited[src]=1;

    cost1[src]=0;

    int u,qq=src,mx=-1;

    while(!q.empty()){

        u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(!visited[v]){

                visited[v]=1;

                cost1[v]=cost1[u]+cost[u][i];

                if(cost1[v]>mx){

                    mx=cost1[v];

                    qq=v;

                }

                q.push(v);

            }

        }

    }

    cost1[src]=mx;

    return qq;

}

int bfs1(int src){

    queue<int>q;

    q.push(src);

    int visited[30009];

    memset(visited,0,sizeof(visited));

    visited[src]=1;

    cost1[src]=0;

    int u,qq=src,mx=-1;

    while(!q.empty()){

        u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(!visited[v]){

                visited[v]=1;

                cost1[v]=cost1[u]+cost[u][i];

                if(cost1[v]>mx){

                    mx=cost1[v];

                    qq=v;

                }

                q.push(v);

            }

        }

    }

    cost1[src]=mx;

    return qq;

}

void bfs2(int src){

    queue<int>q;

    q.push(src);

    int visited[30009];

    memset(visited,0,sizeof(visited));

    visited[src]=1;

    cost2[src]=0;

    int mx=-1;

    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(!visited[v]){

                visited[v]=1;

                cost2[v]=cost2[u]+cost[u][i];

                if(cost2[v]>mx)

                    mx=cost2[v];

                q.push(v);

            }

        }

    }

    cost2[src]=mx;

}

int main()

{

    int test,u,v,w,n;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=0;j<n-1;j++){

            scanf("%d %d %d",&u,&v,&w);

            graph[u].push_back(v);

            graph[v].push_back(u);

            cost[u].push_back(w);

            cost[v].push_back(w);

        }

        int q1=bfs(0);

        q1=bfs1(q1);

        bfs2(q1);

        printf("Case %d:\n",i+1);

        for(int j=0;j<n;j++){

            if(cost1[j]>cost2[j]) printf("%lld\n",cost1[j]);

            else printf("%lld\n",cost2[j]);

        }

        for(int j=0;j<n;j++){

            graph[j].clear();

            cost[j].clear();

        }

    }

    return 0;

}