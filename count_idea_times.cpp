#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


struct idea{
    int pm;
    int time;
    int level;
    int cost;
}
bool compare(idea &a,idea &b){
    return (a.)
}
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int program[m];
    vector<idea> ideas(p);
    pair<int,int> temp;
    for(int i=0;i<n;i++){
        scanf("%d %d",&temp.first,&temp.second);
        buffer.push_back(temp);
    }
    sort(&buffer[0],&buffer[buffer.size()],compare);
    int max_x=-1;
    for(int i=0;i<buffer.size();i++)
        if(max_x<buffer[i].first){
            max_x = buffer[i].first;
            printf("%d %d\n",buffer[i].first,buffer[i].second);
        }
    return 0;
}