#include<cstdio>

#include<iostream>

#include<vector>

#include<cstring>

#include<queue>

#include<cmath>

using namespace std;

int m,n,knight,counter[11][11],moves[101][11][11];

char board[11][11];

int fx[10]={1,-1,1,-1,2,2,-2,-2};

int fy[10]={2,2,-2,-2,1,-1,1,-1};

void bfs(int x,int y,int z){

    queue< pair<int,int> >q;

    int visited[11][11],dist[11][11];

    memset(visited,0,sizeof(visited));

    memset(dist,0,sizeof(dist));

    q.push(make_pair(x,y));

    visited[x][y]=1;

    dist[x][y]=0;

    moves[knight][x][y]=0;;

    counter[x][y]++;

    while(!q.empty()){

        pair<int,int>u=q.front();

        q.pop();

        for(int i=0;i<8;i++){

            int tx=u.first+fx[i];

            int ty=u.second+fy[i];

            if(!visited[tx][ty] && tx>=0 && tx<m && ty>=0 && ty<n){

                visited[tx][ty]=1;

                dist[tx][ty]=dist[u.first][u.second]+1;

                counter[tx][ty]++;

                double ppp=(double)dist[tx][ty]/z;

                int l=ceil(ppp);

                moves[knight][tx][ty]=l;

                q.push(make_pair(tx,ty));

            }

        }

    }

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&m,&n);

        for(int j=0;j<m;j++){

            for(int k=0;k<n;k++){

                scanf("%c",&board[j][k]);

                if(board[j][k]==' ' || board[j][k]=='\n'){

                    k--;

                    continue;

                }

            }

        }

        memset(counter,0,sizeof(counter));

        knight=0;

        for(int j=0;j<m;j++){

            for(int k=0;k<n;k++){

                if(board[j][k]>='1' && board[j][k]<='9'){

                    int z=board[j][k]-'0';

                    knight++;

                    bfs(j,k,z);

                }

            }

        }

        int mx=100000000;

        for(int j=0;j<m;j++){

            for(int k=0;k<n;k++){

                if(counter[j][k]==knight){

                    int sum=0;

                    bool flag=false;

                    for(int l=1;l<=knight;l++){

                        flag=true;

                        sum+=moves[l][j][k];

                    }

                    if(sum<mx && flag==true) mx=sum;

                }

            }

        }

        if(mx==100000000) printf("Case %d: -1\n",i+1);

        else printf("Case %d: %d\n",i+1,mx);

    }

    return 0;

}