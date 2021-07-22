#include<cstdio>

#include<iostream>

#include<vector>

#include<queue>

#include<cstring>

using namespace std;

vector<int>graph[1009];

int counter[1009];

void bfs(int src){

    queue<int>q;

    q.push(src);

    int visited[1009];

    memset(visited,0,sizeof(visited));

    visited[src]=1;

    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(!visited[v]){

                visited[v]=1;

                counter[v]++;

                q.push(v);

            }

        }

    }

}

int main()

{

    int test,k,n,m,x,y,vis[1009];

    vector<int>u;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d %d",&k,&n,&m);

        memset(vis,0,sizeof(vis));

        for(int j=0;j<k;j++){

            scanf("%d",&x);

            if(!vis[x]){

                vis[x]=1;

                u.push_back(x);

            }

        }

        for(int j=0;j<m;j++){

            scanf("%d %d",&x,&y);

            graph[x].push_back(y);

        }

        memset(counter,0,sizeof(counter));

        for(int j=0;j<u.size();j++){

            counter[u[j]]++;

            bfs(u[j]);

        }

        int p=0;

        for(int j=0;j<=1000;j++)

            if(counter[j]==u.size()) p++;

        printf("Case %d: %d\n",i+1,p);

        for(int j=0;j<=1000;j++)

            graph[j].clear();

        u.clear();

    }

}