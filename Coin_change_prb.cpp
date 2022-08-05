#include<bits/stdc++.h>
using namespace std;
#define lli long long int




// just practicing  
vector<int>dp(1e4+7,-1);
int dp2[300][10020];
int min_coin_req(int amt ,vector<int>&vp){
    if(amt==0){
        return 0;
    }
    if(dp[amt]!=-1)
    {
        return dp[amt];
    }
    int ans=INT16_MAX;
    for(int i=0;i<vp.size();i++){
        if(amt-vp[i]>=0)
        {
            ans=min(ans+0LL,min_coin_req(amt-vp[i],vp)+1LL);
        }
    }
    return dp[amt]=ans;
}

int comb_coins(int idx,vector<int>&vp,int amt){
    if(amt==0)return 1;
    if(idx<0)return 0;
    if(dp2[idx][amt]!=-1)return dp2[idx][amt];
    int way=0;
    for(int coin_amt=0;coin_amt<=amt;coin_amt+=vp[idx]){
        way+=comb_coins(idx-1,vp,amt-coin_amt);
    }
    return dp2[idx][amt]= way;
}

int main()
{
    vector<int>vp={1,2,5};

    int am= 11;
    int aa=min_coin_req(am,vp);
    
    memset(dp2,-1,sizeof(dp2));

    int comaa=comb_coins(vp.size()-1,vp,am);
    // if(aa==INT16_MAX){
        // cout<<-1<<"\n";
    // }
    // else cout<<aa<<"\n";

    cout<<"The combinations are "<<comaa<<"\n";
    return 0;
}