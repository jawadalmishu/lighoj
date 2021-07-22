#include<iostream>

#include<cstdio>

#include<cstring>

#include<queue>

using namespace std;

int fx[]={0,0,1,-1};

int fy[]={1,-1,0,0};

char ch[502][502];

int m,n,visited[502][502],vis[502][502],c;

int bfs(int x,int y){

    vis[x][y]=1;

    queue< pair<int,int> >q;

    q.push(make_pair(x,y));

    visited[x][y]=c;

    pair<int,int>p;

    int sum=0;

    if(ch[x][y]=='C') sum++;

    while(!q.empty()){

        p=q.front();

        q.pop();

        for(int i=0;i<4;i++){

            int tx=p.first+fx[i];

            int ty=p.second+fy[i];

            if(tx>=0 && tx<m && ty>=0 && ty<n && ch[tx][ty]!='#' && visited[tx]                       [ty]!=c){

                vis[tx][ty]=1;

                visited[tx][ty]=c;

                if(ch[tx][ty]=='C') sum++;

                q.push(make_pair(tx,ty));

            }

        }

    }

    return sum;

}

int main()

{

    int test,q,x,y,arr[502];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d %d",&m,&n,&q);

        for(int j=0;j<m;j++){

            for(int k=0;k<n;k++){

                scanf("%c",&ch[j][k]);

                    if(ch[j][k]==' ' || ch[j][k]=='\n'){

                        k--;

                        continue;

                    }

            }

        }

        c=0;

        printf("Case %d:\n",i+1);

        for(int j=0;j<q;j++){

            scanf("%d %d",&x,&y);

            if(vis[x-1][y-1]==1){

                printf("%d\n",arr[visited[x-1][y-1]]);

            }

            else{

                c++;

                int sum=bfs(x-1,y-1);

                printf("%d\n",sum);

                arr[c]=sum;

            }

        }

        memset(visited,0,sizeof(visited));

        memset(vis,0,sizeof(vis));

    }

    return 0;

}