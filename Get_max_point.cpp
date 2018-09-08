#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(pair<int,int> &a,pair<int,int> &b){
    return a.second>b.second;
}
int main(){
    int n;
    while(scanf("%d",&n)){
        vector< pair<int,int> > buffer,result;
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
    }
    return 0;
}