#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int n,m;
int coins[55];
lli memo[255][55];

void input(){
    memset(memo,-1,sizeof(memo));
    scanf(" %d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf(" %d",&coins[i]);
    }
    sort(coins,coins+m);
}

lli doit(int amount, int pos){
    if(amount<0||pos>=m){
        return 0;
    }
    if(amount==0){
        return 1;
    }
    if(memo[amount][pos]>=0){
        return memo[amount][pos];
    }
    return memo[amount][pos]=doit(amount,pos+1)+doit(amount-coins[pos],pos);
}

lli result(){
    return doit(n,0);
}

int main() {  
    input();
    lli res = result();
    printf("%lld\n",res);
    return 0;
}
