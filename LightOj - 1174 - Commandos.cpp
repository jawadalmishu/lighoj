#include<cstdio>

#include<vector>

#include<iostream>

#include<cstring>

#include<queue>

using namespace std;

vector<int>graph[105];

int qq,start,finl,distances1[109],distances2[109];

void bfs(int src){

    int visited[109];

    queue<int>q;

    memset(visited,0,sizeof(visited));

    q.push(src);

    visited[src]=1;

    if(qq==1)distances1[src]=0;

    else distances2[src]=0;



    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(!visited[v]){

                visited[v]=1;

                if(qq==1) distances1[v]=distances1[u]+1;

                else distances2[v]=distances2[u]+1;

                q.push(v);

            }

        }

    }

}

int main()

{

    int test,m,n,x,y,start,finl;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        qq=0;

        scanf("%d",&n);

        scanf("%d",&m);

        for(int j=0;j<m;j++){

            scanf("%d %d",&x,&y);

            graph[x].push_back(y);

            graph[y].push_back(x);

        }

        scanf("%d",&start);

        scanf("%d",&finl);

        memset(distances1,0,sizeof(distances1));

        memset(distances2,0,sizeof(distances2));

        qq++;

        bfs(start);

        qq++;

        bfs(finl);

        int times=0;

        for(int j=0;j<n;j++)

            if(distances1[j]+distances2[j]>times)

                times=distances1[j]+distances2[j];

        printf("Case %d: %d\n",i+1,times);

        for(int j=0;j<=n;j++) graph[j].clear();

    }

    return 0;

}