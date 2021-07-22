#include<cstdio>

#include<iostream>

#include<queue>

#include<vector>

#include<cstring>

#include<cmath>

using namespace std;

struct seat{

    int curr;

}s[22];

int main(){

    int pos1,pos2,qq,p,ttl,coun,times,test,n,m,visited[21][21];

    deque<int>dq,dq2;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        times=0;

        memset(visited,0,sizeof(visited));

        scanf("%d %d",&n,&m);

        ttl=m*n;

        coun=0;

        for(int j=1;j<=n;j++)

            dq.push_back(j);

        for(int j=0;j<22;j++)

            s[j].curr=0;

        while(1){

            for(int k=1;k<=m;k++){

                p=0;

                times+=5;

                dq2.clear();

                    for(int j=0;j<dq.size();j++){

                        if(visited[k][dq[j]]==0){

                            p=1;

                            coun++;

                            visited[k][dq[j]]=1;

                            if(s[k].curr==0){

                                s[k].curr=dq[j];

                                for(int l=j+1;l<dq.size();l++){

                                    dq2.push_back(dq[l]);

                                }

                                qq=dq.size();

                                for(int l=qq-1;l>=j;l--){

                                    dq.pop_back();

                                }

                                for(int l=0;l<dq2.size();l++){

                                    dq.push_back(dq2[l]);

                                }

                                break;

                            }

                            else{

                                dq.push_back(s[k].curr);

                                s[k].curr=dq[j];

                                for(int l=j+1;l<dq.size();l++){

                                    dq2.push_back(dq[l]);

                                }

                                qq=dq.size();

                                for(int l=qq-1;l>=j;l--){

                                    dq.pop_back();

                                }

                                for(int l=0;l<dq2.size();l++)

                                    dq.push_back(dq2[l]);

                                break;

                            }

                        }

                        dq2.clear();

                    }

                if(p==0){

                    if(s[k].curr!=0){

                        dq.push_back(s[k].curr);

                        s[k].curr=0;

                    }

                }

                if(coun==ttl) break;

            }

            if(coun==ttl) break;

        }

        times+=m*5;

        printf("Case %d: %d\n",i+1,times);

        dq2.clear();

        dq.clear();

    }

    return 0;

}