#include<cstdio>

#include<iostream>

#include<queue>

#include<vector>

#include<algorithm>

#include<cstring>

using namespace std;

int fx[]={0,0,1,-1};

int fy[]={1,-1,0,0};

int jk,n;

char ch[12][12];

struct node{

    int a;

    int x;

    int y;

    bool operator<(const node & p) const{

        return a<p.a;

    }

};

vector<node>vc;

int bfs(int x,int y){

    char cc=ch[x][y]+1;

    int visited[12][12],level[12][12];

    queue< pair<int,int> >q;

    while(!q.empty()) q.pop();

    pair<int,int>p;

    q.push(make_pair(x,y));

    memset(visited,0,sizeof(visited));

    memset(level,0,sizeof(level));

    visited[x][y]=1;

    level[x][y]=0;

    while(!q.empty()){

        p=q.front();

        q.pop();

        for(int i=0;i<4;i++){

            int tx=p.first+fx[i];

            int ty=p.second+fy[i];

            if(tx>=0 && tx<n && ty>=0 && ty<n && ch[tx][ty]!='#' && visited[tx]                       [ty]==0){

                if(ch[tx][ty]<=cc){

                    visited[tx][ty]=1;

                    level[tx][ty]=level[p.first][p.second]+1;

                    if(ch[tx][ty]==cc) return level[tx][ty];

                    q.push(make_pair(tx,ty));

                }

            }

        }

    }

    return -1;

}

int main()

{

    int test,coun,sum,ll;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        coun=0;

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                scanf("%c",&ch[j][k]);

                if(ch[j][k]==' ' || ch[j][k]=='\n'){

                    k--;

                    continue;

                }

                if(ch[j][k]!='.' && ch[j][k]!='#'){

                    int nn=ch[j][k]-'A';

                    node e;

                    e.a=nn; e.x=j; e.y=k;

                    vc.push_back(e);

                    coun++;

                }

            }

        }

        sort(vc.begin(),vc.end());

        sum=0;

        for(jk=0;jk<coun-1;jk++){

            ll=bfs(vc[jk].x,vc[jk].y);

            if(ll==-1) break;

            sum=sum+ll;

        }

        if(coun==1) printf("Case %d: 0\n",i+1);

        else if(ll==-1) printf("Case %d: Impossible\n",i+1);

        else printf("Case %d: %d\n",i+1,sum);

        vc.clear();

    }

    return 0;

}