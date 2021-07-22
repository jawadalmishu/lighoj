#include<cstdio>

#include<cstring>

#include<vector>

using namespace std;

vector<int>graph[10009];

int n,time,parent[10009],low[10009],disc[10009];

bool visited[10009],ap[10009];

void Aputil(int u){

    int children=0;

    visited[u]=true;

    disc[u]=low[u]=++time;

    for(int i=0;i<graph[u].size();i++){

        int v=graph[u][i];

        if(!visited[v]){

            children++;

            parent[v]=u;

            Aputil(v);

            low[u]=min(low[u],low[v]);

            if(parent[u]==-1 && children>1)

                ap[u]=true;

            if(parent[u]!=-1 && low[v]>=disc[u])

                ap[u]=true;

        }

        else if(v!=parent[u])

            low[u]=min(low[u],disc[v]);

    }

}

void Ap(){

    for(int i=1;i<=n;i++){

        parent[i]=-1;

        visited[i]=false;

        ap[i]=false;

    }

    for(int i=1;i<=n;i++){

        if(!visited[i])

            Aputil(i);

    }

}

int main()

{

    int test,m,a,b,coun;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&m);

        for(int j=0;j<m;j++){

            scanf("%d %d",&a,&b);

            graph[a].push_back(b);

            graph[b].push_back(a);

        }

        time=0;

        coun=0;

        Ap();

        for(int j=1;j<=n;j++)

            if(ap[j]==true)

                coun++;

        printf("Case %d: %d\n",i+1,coun);

        for(int j=0;j<=n+1;j++)

            graph[j].clear();

    }

    return 0;

}