#include<iostream>

#include<cstdio>

#include<vector>

#include<queue>

#include<cstring>

using namespace std;

vector<int>graph[1009];

int sum,coun,visited[1009],arr[1009];

int dfs(int v){

    for(int i=0;i<graph[v].size();i++){

        int p=graph[v][i];

        if(!visited[p]){

            visited[p]=1;

            sum+=arr[p];

            coun++;

            dfs(p);

        }

    }

}

int main()

{

    int test,n,m,u,v,prev1,prev2;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&m);

        for(int j=1;j<=n;j++)

            scanf("%d",&arr[j]);

        for(int j=0;j<m;j++){

            scanf("%d %d",&u,&v);

            graph[u].push_back(v);

            graph[v].push_back(u);

        }

        memset(visited,0,sizeof(visited));

        bool b=false,q=false;

        for(int j=1;j<=n;j++){

            sum=0;

            if(!visited[j]){

                sum=sum+arr[j];

                coun=1;

                visited[j]=1;

                dfs(j);

                if(sum%coun!=0){

                    q=true;

                    printf("Case %d: No\n",i+1);

                    break;

                }

                else{

                    if(b==false){

                        b=true;

                        prev1=sum/coun;

                        prev2=prev1;

                    }

                    else{

                        prev2=sum/coun;

                        if(prev2!=prev1){

                            printf("Case %d: No\n",i+1);

                            break;

                        }

                    }

                }

            }

        }

        if(prev1==prev2 && q==false) printf("Case %d: Yes\n",i+1);

        for(int j=0;j<n;j++) graph[j].clear();

    }

    return 0;

}