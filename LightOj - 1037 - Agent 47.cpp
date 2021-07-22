#include<cstdio>

#include<iostream>

using namespace std;

typedef int ll;

bool check(int N,int pos) { return N & (1<<pos) ; }

int sets(int N,int pos) { return N = N | (1<<pos) ; }

int resets(int N,int pos) { return N = N & ~(1<<pos) ; }

int c=0,n,life[20],damages[20][20],damages_2[20][20],vis[16][32770];

ll  dp[16][32770];

ll f(int i,int num){

    if(num==(1<<n)-1) return 0;

    if(vis[i][num]==c) return dp[i][num];

    ll sum,mx=16000009;

    for(int j=0;j<n;j++){

        if(i!=j && damages[i][j]>0 && check(num,j)==0){

            int x=life[j]%damages[i][j];

            int y=life[j]/damages[i][j];

            if(x>0) y++;

            for(int k=0;k<n;k++)

                if(damages[i][k]>damages[j][k]) damages[j][k]=damages[i][k];

            sum=y+f(j,sets(num,j));

            for(int k=0;k<n;k++)

                damages[j][k]=damages_2[j][k];

            mx=min(sum,mx);

        }

    }

    vis[i][num]=c;

    return dp[i][num]=mx;

}

int main()

{

    int test,num;

    ll  sum,mx;

    char str[25];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=0;j<n;j++)

            scanf("%d",&life[j]);

        for(int j=0;j<n;j++){

            scanf("%s",&str);

            for(int k=0;k<n;k++){

                damages[j][k]=str[k]-'0';

                if(damages[j][k]==0) damages[j][k]=1;

                damages_2[j][k]=damages[j][k];

            }

        }

        num=0;

        mx=16000009;

        --c;

        for(int j=0;j<n;j++){

            sum=life[j]+f(j,sets(num,j));

            mx=min(mx,sum);

        }

        printf("Case %d: %d\n",i+1,mx);

    }

    return 0;

}