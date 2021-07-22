#include<iostream>

#include<cstdio>

#include<vector>

using namespace std;

vector<int>graph[30009],cost[30009];

int p,q;

long long mx;

void dfs(int cur,int prev,int sum){

    for(int i=0;i<graph[cur].size();i++){

        if(graph[cur][i]!=prev){

            long long v=sum+cost[cur][i];

            if(v>mx){

                mx=v;

                p=cur;

                q=i;

            }

            dfs(graph[cur][i],cur,sum+cost[cur][i]);

        }

    }



}

int main()

{

    int test,n,u,v,w;

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

        mx=-10;

        dfs(0,-1,0);

        mx=-10;

        dfs(graph[p][q],-1,0);

        printf("Case %d: %lld\n",i+1,mx);

        for(int j=0;j<=n;j++){

            graph[j].clear();

            cost[j].clear();

        }

    }

    return 0;

}