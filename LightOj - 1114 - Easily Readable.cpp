#include<cstdio>

#include<iostream>

#include<map>

#include<vector>

#include<algorithm>

#include<cstring>

using namespace std;

int main()

{

    int test,m,n,prev,cp,pt;

    long long result;

    string str2,str3;

    vector<char>vc;

    map<string,int>mp;

    char str[105],np[10009],ff[10];

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d",&n);

        for(int j=0;j<n;j++){

            scanf("%s",str);

            int l=strlen(str);

            if(l<=3) mp[str]++;

            else{

                for(int i=1;i<l-1;i++){

                    vc.push_back(str[i]);

                }

                sort(vc.begin(),vc.end());

                str2+=str[0];

                for(int i=0;i<vc.size();i++)  str2+=vc[i];

                str2+=str[l-1];

                mp[str2]++;

                vc.clear();

                str2.clear();

            }

        }

        str2.clear();

        vc.clear();

        scanf("%d",&m);

        gets(ff);

        printf("Case %d:\n",i+1);

        for(int j=0;j<m;j++){

            gets(np);

            int l=strlen(np);

            prev=0;

            result=1;

            cp=0;

            pt=0;

            for(int p=0;p<l;p++){

                if(np[p]==' ' && pt==0)  continue;

                else if(np[p]==' ' && pt==1){

                    pt=0;

                    cp=0;

                    int ll=str2.length();

                    for(int i=1;i<ll-1;i++){

                        vc.push_back(str2[i]);

                    }

                    sort(vc.begin(),vc.end());

                    str3+=str2[0];

                    for(int i=0;i<vc.size();i++)  str3+=vc[i];

                    if(ll>1) str3+=str2[ll-1];

                    result=result*mp[str3];

                    vc.clear();

                    str2.clear();

                    str3.clear();

                }

                else{

                    pt=1;

                    str2+=np[p];

                    if(cp==0){

                        cp=1;

                        prev=p;

                    }

                    if(p==l-1){

                        int ll=str2.length();

                        for(int i=1;i<ll-1;i++){

                            vc.push_back(str2[i]);

                        }

                        sort(vc.begin(),vc.end());

                        str3+=str2[0];

                        for(int i=0;i<vc.size();i++)  str3+=vc[i];

                        if(ll>1) str3+=str2[ll-1];

                        result=result*mp[str3];

                        vc.clear();

                        str2.clear();

                        str3.clear();

                    }

                }

            }

            if(n==0 && l!=0) printf("0\n");

            else if(l==0) printf("1\n");

            else printf("%ld\n",result);

        }

        mp.clear();

    }

    return 0;

}