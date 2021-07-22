#include<iostream>

#include<cstdio>

#include<queue>

#include<map>

using namespace std;

char arr[24][24];

int w,h;

int fx[]={1,-1,0,0};

int fy[]={0,0,1,-1};

int bfs(int x,int y){

    queue< pair<int,int> >q;

    pair<int,int>p;

    map<int,map<int,int> >visited;

    int counter=0;

    q.push(make_pair(x,y));

    visited[x][y]=1;

    while(!q.empty()){

        p=q.front(); q.pop();

        for(int i=0;i<4;i++){

            int tx=p.first+fx[i];

            int ty=p.second+fy[i];

            if(!visited[tx][ty] && tx>=0 && tx<w && ty>=0 && ty<h && arr[ty][tx]=='.')

            {

                q.push(make_pair(tx,ty));

                visited[tx][ty]=1;

                counter++;

            }

        }

    }

    return counter;

}

int main()

{

    int test,counter,x,y;

    char ch;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&w,&h);

        for(int j=0;j<h;j++){

            for(int k=0;k<w;k++){

                scanf("%c",&ch);

                if(ch==' ' || ch=='\n') { k--; continue; }

                arr[j][k]=ch;

                if(arr[j][k]=='@'){

                    x=k; y=j;

                }

            }

        }

        counter=bfs(x,y);

        printf("Case %d: %d\n",i+1,counter+1);

    }

    return 0;

}