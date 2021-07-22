#include<cstdio>

#include<iostream>

#include<cstring>

#include<vector>

#include<map>

#include<queue>

using namespace std;

map<char, map<char, map<char,int> > > visited;

char start[5],finish[5];

struct node{

    char a;

    char b;

    char c;

};

int bfs(){

    queue<node>q;

    node n;

    n.a=start[0]; n.b=start[1]; n.c=start[2];

    q.push(n);

    map<char, map<char, map<char,int> > > dist;

    dist.clear();

    dist[n.a][n.b][n.c]=0;

    visited[n.a][n.b][n.c]=1;

    dist[finish[0]][finish[1]][finish[2]]=-1;

    node u,v;

    while(!q.empty()){

        u=q.front();

        q.pop();

        for(int i=0;i<6;i++){

            if(i==0){

                if(u.a=='z') v.a='a';

                else v.a=u.a+1;

                v.b=u.b;

                v.c=u.c;

            }

            else if(i==1){

                if(u.b=='z') v.b='a';

                else v.b=u.b+1;

                v.a=u.a;

                v.c=u.c;

            }

            else if(i==2){

                if(u.c=='z') v.c='a';

                else v.c=u.c+1;

                v.a=u.a;

                v.b=u.b;

            }

            else if(i==3){

                if(u.a=='a') v.a='z';

                else v.a=u.a-1;

                v.b=u.b;

                v.c=u.c;

            }

            else if(i==4){

                if(u.b=='a') v.b='z';

                else v.b=u.b-1;

                v.a=u.a;

                v.c=u.c;

            }

            else if(i==5){

                if(u.c=='a') v.c='z';

                else v.c=u.c-1;

                v.a=u.a;

                v.b=u.b;

            }

            if(!visited[v.a][v.b][v.c]){

                visited[v.a][v.b][v.c]=1;

                dist[v.a][v.b][v.c]=dist[u.a][u.b][u.c]+1;

                if(v.a==finish[0] && v.b==finish[1] && v.c==finish[2]) break;

                q.push(v);

            }

        }

        if(v.a==finish[0] && v.b==finish[1] && v.c==finish[2]) break;

    }

    while(!q.empty()) q.pop();

    return dist[v.a][v.b][v.c];

}

int main()

{

    int test,n;

    char str1[30],str2[30],str3[30];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%s",&start);

        scanf("%s",&finish);

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            scanf("%s %s %s",&str1,&str2,&str3);

            int l1=strlen(str1),l2=strlen(str2),l3=strlen(str3);

            for(int k=0;k<l1;k++){

                for(int l=0;l<l2;l++){

                    for(int m=0;m<l3;m++){

                        visited[str1[k]][str2[l]][str3[m]]=1;

                    }

                }

            }

        }

        if(visited[start[0]][start[1]][start[2]]==1 || visited[finish[0]][finish[1]]              [finish[2]]==1){

            printf("Case %d: -1\n",i+1);

        }

        else if(start[0]==finish[0] && start[1]==finish[1] && start[2]==finish[2]){

            printf("Case %d: 0\n",i+1);

        }

        else{

            int qq=bfs();

            printf("Case %d: %d\n",i+1,qq);

        }

        visited.clear();

    }

    return 0;

}