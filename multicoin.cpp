#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    
    int coin=99;
    long long int suum =0; 
    for (auto i = 0; i < coin; i++)
    {
        /* code */
        if((i%5==0 ||i<2) && i%3!=0 && i<=20 && i>=50)suum*=i;

    }
    cout<<suum<<"\n";
    

    return 0;
}