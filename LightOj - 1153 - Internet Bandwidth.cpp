#include<iostream>

#include<cstdio>

#include<vector>

#include<queue>

#include<cstring>

using namespace std;

vector<int>graph[104];

int v,par[102],cf[103][103];

bool bfs(int s,int t){

    queue<int>q;

    q.push(s);

    int vis[102]={0};

    vis[s]=1;

    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(int i=0;i<graph[u].size();i++){

            int v=graph[u][i];

            if(vis[v]==0 && cf[u][v]>0){

                vis[v]=1;

                par[v]=u;

                if(v==t) return true;

                q.push(v);

            }

        }

    }

    return false;

}

int main()

{

    int u,w,k,l,mn,test,nodes,s,c,t;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        int max_flow=0;

        memset(cf,0,sizeof(cf));

        scanf("%d",&nodes);

        scanf("%d %d %d",&s,&t,&c);

        for(int j=0;j<c;j++){

            scanf("%d %d %d",&u,&v,&w);

            graph[u].push_back(v);

            graph[v].push_back(u);

            cf[u][v]+=w;

            cf[v][u]=cf[u][v];

        }

        while(1){

            bool g=bfs(s,t);

            if(g==false) break;

            k=t,mn=100000000;

            while(k!=s){

                l=k;

                k=par[k];

                mn=min(mn,cf[k][l]);

            }

            k=t;

            while(k!=s){

                l=k;

                k=par[k];

                cf[k][l]-=mn;

                cf[l][k]+=mn;

            }

            max_flow+=mn;

        }

        printf("Case %d: %d\n",i+1,max_flow);

        for(int j=0;j<=101;j++) graph[j].clear();

    }

    return 0;

}