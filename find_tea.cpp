#include<vector>
#include<stdio.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    bool flag = false;
    int n,tea;
    scanf("%d",&n);
    vector<int> buffer(n);
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        scanf("%d",&buffer[i]);
        map[buffer[i]]=1;
    }
    scanf("%d",&tea);
    sort(buffer.begin(),buffer.end());
    for(int i=0;i<n&&buffer[i]<(tea+1)/2;i++){
        if(map.find(tea-buffer[i])!=map.end()){
            printf("%d %d\n",buffer[i],tea-buffer[i]);
            flag = true;
        }
    }
    if(!flag)
        printf("x⑨\n");
    return 0;
}