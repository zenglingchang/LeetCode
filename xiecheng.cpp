#include<stdio.h>
#include<vector>
using namespace std;
vector<int> Ar_m,Ar_v1,Ar_v2,flag;
vector<vector<node>> buffer;
struct node{
    node(int y,int time):t(time),next(y){}
    int t;
    int next;
}

void function(int cur,int happy_value,int happy_value2, int &count, int &sum,int &sum2, int k){
    happy_value += Ar_v1[cur];
    happy_value2 += Ar_v2[cur];
    flag[cur]=1;
    bool f=false;
    for(int i=0;i<buffer[cur].size();i++){
        if(flag[buffer[cur].next]==0 && buffer[cur].t+Ar_m[cur]<k){
            function(buffer[cur].next.happy_value,happy_value2,count,sum,sum2,k-buffer[cur].t-Ar_m[cur]);
            f=true;
        }
    }
    flag[cur] = 0;
    if(!f){
        count++;
        sum += happy_value;
        sum2 += happy_value2;
    }
}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    Ar_m.resize(n);
    Ar_v1.resize(n);
    Ar_v2.resize(n);
    buffer.resize(n);
    flag.resize(n,0);
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&Ar_m[i],&Ar_v1[i],&Ar_v2[i]);
    int temp_x,temp_y,temp_t;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&temp_x,&temp_y,&temp_t);
        buffer[temp_x].push_back(temp_y,temp_t);
        buffer[temp_y].push_back(temp_x,temp_t);
    }
    return 0;
}
