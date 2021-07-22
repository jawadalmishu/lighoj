#include<iostream>

#include<cstdio>

#include<vector>

#include<cstring>

#include<queue>

using namespace std;

int fx[]={0,0,1,-1};

int fy[]={1,-1,0,0};

int r,c,x1,y1,x2,y2,x3,y3;

char ch[21][21];

struct node{

    int p;

    int q;

};

int bfs(int x,int y){

    int level[21][21],visited[21][21];

    memset(visited,0,sizeof(visited));

    queue<node>qq;

    node tp;

    tp.p=x;

    tp.q=y;

    qq.push(tp);

    level[x][y]=0;

    visited[x][y]=1;

    int qp=0,coun=0;

    while(!qq.empty()){

        tp=qq.front();

        qq.pop();

        for(int i=0;i<4;i++){

            int tx=tp.p+fx[i];

            int ty=tp.q+fy[i];

            //cout<<"tx="<<tx<<" "<<"ty="<<ty<<endl;

            if(tx>=0 && tx<r && ty>=0 && ty<c && ch[tx][ty]!='m' && ch[tx][ty]!='#' &&                 visited[tx][ty]==0){

                visited[tx][ty]=1;

                level[tx][ty]=level[tp.p][tp.q]+1;

                if(ch[tx][ty]=='a' || ch[tx][ty]=='b' || ch[tx][ty]=='c'){

                    coun++;

                    qp=max(qp,level[tx][ty]);

                    if(coun==3) break;

                }

                node pt;

                pt.p=tx;

                pt.q=ty;

                qq.push(pt);

            }

        }

        if(coun==3) break;

    }

    while(!qq.empty())

        qq.pop();

    return qp;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&r,&c);

        for(int j=0;j<r;j++){

            for(int k=0;k<c;k++){

                scanf("%c",&ch[j][k]);

                if(ch[j][k]==' ' ||  ch[j][k]=='\n'){

                    k--;

                    continue;

                }

                else if(ch[j][k]=='h'){

                    x1=j;

                    y1=k;

                }

            }

        }

        int pp;

        pp=bfs(x1,y1);

        printf("Case %d: %d\n",i+1,pp);

    }

    return 0;

}