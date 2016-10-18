#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int items[2003];

int memo[2003][2003];

void input(){
    memset(memo,-1,sizeof(memo));
    scanf(" %d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf(" %d",&items[i]);
    }
}

int doit(int position, int capacity){
    if(position>=n || capacity<0){
        return 0;
    }
    if(memo[position][capacity]>=0){
        return memo[position][capacity];
    }
    int taking = (capacity<items[position])?0:items[position]+doit(position,capacity-items[position]);
    int not_taking = doit(position+1,capacity);
    return memo[position][capacity]=max(taking, not_taking);
}

int result(){
    return doit(0,k);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,res;
    scanf(" %d",&t);
    while(t--){
        input();
        res = result();
        printf("%d\n",res);
    }
    return 0;
}
