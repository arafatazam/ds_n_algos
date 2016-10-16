#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int graph[405][405];
void init_graph(){
    memset(graph,1,sizeof(graph));
    for(int i = 1;i<=n;i++){
        graph[i][i]=0;
    }
}

void set_edge(int x, int y, int r){
    graph[x][y]=r;
}

int query(int u, int v){
    if(graph[u][v]>16000){ // 400*350+1000
        return -1;
    }
    return graph[u][v];
}

void print_g(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",query(i,j));
        }
        printf("\n");
    }
    printf("-------------------------------------------------------\n");
}

void floyed(){
    int detour;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                detour = graph[i][k]+graph[k][j]; 
                if(graph[i][j]>detour){
                    graph[i][j]=detour;
                }
            }
        }
    }
}

int main() {
    int m,x,y,r,q;
    scanf(" %d %d",&n,&m);
    init_graph();
    for(int i=0;i<m;i++){
        scanf(" %d %d %d",&x,&y,&r);
        set_edge(x,y,r);
    }
    floyed();
    scanf(" %d",&q);
    for(int i=0;i<q;i++){
        scanf(" %d %d",&x,&y);
        r = query(x,y);
        printf("%d\n",r);
    }
    return 0;
}