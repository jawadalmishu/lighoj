#include<cstdio>

#include<iostream>

#include<vector>

#include<cstring>

#include<map>

#include<cmath>

#include<algorithm>

using namespace std;

map<int,int>mp;

int prev,n,p,w,arr[110],dp[110][110][110];

bool cmp(int a,int b){

    return a<b;

}

int knapsack(int i,int prev,int moves){

    if(i==p) return 0;

    if(moves==0){

        int sum=0;

        for(int j=i;j<p;j++){

            if(abs(arr[j]-arr[prev])<=w)

                sum=sum+mp[arr[j]];

            else return sum;

        }

    }

    if(dp[i][prev][moves]!=-1) return dp[i][prev][moves];

    int profit1=0,profit2=0;

    if(abs(arr[i]-arr[prev])<=w){

        if(i==prev) profit1=mp[arr[i]]+knapsack(i+1,prev,moves-1);

        else profit1=mp[arr[i]]+knapsack(i+1,prev,moves);

    }

    else{

        profit1=mp[arr[i]]+knapsack(i+1,i,moves-1);

    }

    if(i==prev){

        profit2=knapsack(i+1,i+1,moves);

    }

    else{

        profit2=knapsack(i+1,prev,moves);

    }

    return dp[i][prev][moves]=max(profit1,profit2);

}

int main()

{

    int test,k,x,y;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        p=0;

        scanf("%d %d %d",&n,&w,&k);

        for(int j=0;j<n;j++){

            scanf("%d %d",&x,&y);

            if(mp[y]==0){

                arr[p]=y;

                p++;

            }

            mp[y]=mp[y]+1;

        }

        sort(arr,arr+p,cmp);

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",i+1,knapsack(0,0,k));

        mp.clear();

    }

    return 0;

}