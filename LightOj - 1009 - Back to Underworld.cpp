#include<cstdio>

#include<iostream>

#include<vector>

#include<cstring>

#include<map>

#include<cmath>

#include<algorithm>

#include<queue>

using namespace std;

int color[20009],cl[5],vis[20009];

vector<int>graph[20009];

void bipartite_bfs(int a){

    int visited[20009];

    for(int i=0;i<=20009;i++)

        visited[i]=0;

    queue<int>q;

    q.push(a);

    cl[0]=0;

    cl[1]=0;

    color[a]=1;

    cl[1]++;

    visited[a]=1;

    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(!visited[v]){

                visited[v]=1;

                vis[v]=1;

                color[v]=1-color[u];

                cl[color[v]]++;

                q.push(v);

            }

        }

    }

}

int main()

{

    int test,a,b,n,sum;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            scanf("%d %d",&a,&b);

            graph[a].push_back(b);

            graph[b].push_back(a);

        }

        for(int j=0;j<=20002;j++)

            vis[j]=0;

        sum=0;

        for(int j=0;j<=20000;j++){

            if(graph[j].size()>0){

                if(vis[j]==0){

                    vis[j]=1;

                    bipartite_bfs(j);

                    sum=sum+max(cl[0],cl[1]);

                }

            }

        }

        printf("Case %d: %d\n",i+1,sum);

        for(int j=0;j<=20002;j++)

            graph[j].clear();

    }

    return 0;

}