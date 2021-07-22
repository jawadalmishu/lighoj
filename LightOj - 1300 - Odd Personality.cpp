#include<iostream>

#include<cstdio>

#include<vector>

#include<map>

#include<queue>

using namespace std;

vector<int>graph[10009];

int n,tot,coun,times,disc[10009],low[10009],parent[10009];

bool visited[10009];

map<int,map<int,int> >mp;

void bridgeutil(int u,int from){

    visited[u]=true;

    disc[u]=low[u]=++times;

    for(int i=0;i<graph[u].size();i++){

        int v=graph[u][i];

        if(!visited[v]){

            parent[v]=u;

            bridgeutil(v,u);

            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u]){

                mp[u][v]=1;

                mp[v][u]=1;

            }

        }

        else if(v!=parent[u])

            low[u]=min(low[u],disc[v]);

    }

}

void bridge(){

    for(int j=0;j<=n;j++){

        parent[j]=-1;

        visited[j]=false;

    }

    times=0;

    for(int j=0;j<n;j++){

        if(visited[j]==false)

            bridgeutil(j,-1);

    }

}

bool bipartite(int src){

    visited[src]=true;

    queue<int>q;

    q.push(src);

    int color[10009];

    for(int i=0;i<=n;i++)

        color[i]=-1;

    color[src]=1;

    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(mp[u][v]==1) continue;

            else if(tot==1){

                if(visited[v]==true) continue;

                coun++;

                q.push(v);

                visited[v]=true;

            }

            else if(color[v]==-1){

                coun++;

                visited[v]=true;

                q.push(v);

                color[v]=1-color[u];

            }

            else if(color[u]==color[v]){

                tot=1;

            }

        }

    }

    if(tot==1) return true;

    return false;

}

int main()

{

    int test,m,u,v;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&m);

        for(int j=0;j<m;j++){

            scanf("%d %d",&u,&v);

            graph[u].push_back(v);

            graph[v].push_back(u);

        }

        bridge();

        for(int j=0;j<=n;j++)

            visited[j]=false;

        int sum=0;

        for(int j=0;j<n;j++){

            if(visited[j]==false){

                tot=-1;

                coun=0;

                if(bipartite(j))

                    sum=sum+coun+1;

            }

        }

        printf("Case %d: %d\n",i+1,sum);

        for(int j=0;j<=10006;j++)

            graph[j].clear();

        mp.clear();

    }

    return 0;

}