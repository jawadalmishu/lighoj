#include<iostream>

#include<cstdio>

#include<vector>

#include<cstring>

#include<queue>

#include<cmath>

using namespace std;

vector<int>graph[1009];

bool check(int N,int pos) { return (bool)(N & (1<<pos)) ;}

int sets(int N,int pos) { return N = (N | (1<<pos)) ; }

int src,dest,status[50];

void is_prime(){

    memset(status,0,sizeof(status));

    int srt=sqrt(1002);

    for(int i=3;i<=srt;i+=2){

        if(check(status[i/32],i%32)==0){

            for(int j=i*2;j<=1002;j+=i)

                status[j/32]=sets(status[j/32],j%32);

        }

    }

}

void prm_factor(){

   for(int i=4;i<=1000;i++){

       if(check(status[i/32],i%32)==1 || i%2==0){

           int n=i;

           bool p=false;

           while(n%2==0){

             n=n/2;

             p=true;

           }

           if(p==true) graph[i].push_back(2);

           for(int j=3;j<=i/2 && j<=n;j+=2){

               if(check(status[j/32],j%32)==0){

                   p=false;

                   while(n%j==0){

                       p=true;

                       n=n/j;

                   }

                   if(p==true) graph[i].push_back(j);

               }

           }

           if(n>1) graph[i].push_back(n);

       }

   }

}

int bfs(){

    queue<int>q;

    q.push(src);

    int visited[1009],level[1009];

    memset(visited,0,sizeof(visited));

    memset(level,0,sizeof(level));

    visited[src]=1;

    level[src]=0;

    while(!q.empty()){

        int u=q.front();

        int v;

        q.pop();

        bool p=false;

        for(int i=0;i<graph[u].size();i++){

            v=graph[u][i]+u;

            if(!visited[v] && v<=dest){

                p=true;

                level[v]=level[u]+1;

                if(v==dest) break;

                visited[v]=1;

                q.push(v);

            }

        }

        if(v==dest) break;

    }

    while(!q.empty()) q.pop();

    return level[dest];

}

int main()

{

    is_prime();

    prm_factor();

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&src,&dest);

        if(src==dest){

            printf("Case %d: 0\n",i+1);

            continue;

        }

        else if(src>dest || src==1 || src==2 || src==3 ||                 (check(status[src/32],src%32)==0 && src%2!=0)){

            printf("Case %d: -1\n",i+1);

            continue;

        }

        else{

            int q=bfs();

            if(q==0) printf("Case %d: -1\n",i+1);

            else printf("Case %d: %d\n",i+1,q);

        }

    }

    return 0;

}