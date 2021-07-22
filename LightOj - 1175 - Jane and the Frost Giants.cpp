#include<cstdio>

#include<iostream>

#include<vector>

#include<cstring>

#include<queue>

using namespace std;

char board[209][209];

int r,c;

int fx[]={1,0,-1,0};

int fy[]={0,1,0,-1};

queue< pair<int,int> >q2;

int bfs(int x,int y){

    queue< pair<int,int> >q1;

    q1.push(make_pair(x,y));

    int visited[202][202],dist[202][202];

    memset(visited,0,sizeof(visited));

    memset(dist,0,sizeof(dist));

    visited[x][y]=1;

    for(int i=0;i<c;i++){

        dist[0][i]=-1;

        dist[r-1][i]=-1;

    }

    for(int i=0;i<r;i++){

        dist[i][0]=-1;

        dist[i][c-1]=-1;

    }

    dist[x][y]=0;

    bool flag=false;

    int tx,ty;

    while(!q1.empty()){

        int ppp=q2.size();

        while(ppp){

            pair<int,int>p2=q2.front();

            q2.pop();

            for(int i=0;i<4;i++){

                 tx=p2.first+fx[i];

                 ty=p2.second+fy[i];

                if(tx>=0 && tx<r && ty>=0 && ty<c && board[tx][ty]!='#' && board[tx]                      [ty]!='F'){

                    board[tx][ty]='F';

                    q2.push(make_pair(tx,ty));

                }

            }

            ppp--;

        }

        int qqq=q1.size();

        while(qqq){

            pair<int,int>p1=q1.front();

            q1.pop();

            for(int i=0;i<4;i++){

                 tx=p1.first+fx[i];

                 ty=p1.second+fy[i];

                if(!visited[tx][ty] && tx>=0 && tx<r && ty>=0 && ty<c && board[tx]                        [ty]!='#' && board[tx][ty]!='F'){

                    visited[tx][ty]=1;

                    dist[tx][ty]=dist[p1.first][p1.second]+1;

                    if(tx==0 || tx==r-1 || ty==0 || ty==c-1){

                        flag=true;

                        break;

                    }

                    q1.push(make_pair(tx,ty));

                }

            }

            if(flag==true) break;

            qqq--;

        }

        if(flag==true) break;

    }

    while(!q1.empty()) q1.pop();

    while(!q2.empty()) q2.pop();

    if(flag==true) return dist[tx][ty];

    return -1;

}

int main()

{

    int test,u,v;

    bool flag;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&r,&c);

        flag=false;

        for(int j=0;j<r;j++){

            for(int k=0;k<c;k++){

                scanf("%c",&board[j][k]);

                if(board[j][k]==' ' || board[j][k]=='\n'){

                    k--;

                    continue;

                }

                if(board[j][k]=='J') {  u=j; v=k; }

                if(board[j][k]=='F') { q2.push(make_pair(j,k)); }

            }

        }

        if(u==0 || u==r-1 || v==0 || v==c-1){

            printf("Case %d: 1\n",i+1);

        }

        else{

            int qq=bfs(u,v);

            if(qq==-1) printf("Case %d: IMPOSSIBLE\n",i+1);

            else printf("Case %d: %d\n",i+1,qq+1);

        }

        while(!q2.empty()) q2.pop();

    }

    return 0;

}