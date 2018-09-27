#include<vector>
#include<stdio.h>
using namespace std;

int main(){
    int n,sum = 0,max=-1000001,max_index;
    vector<int> buffer,count_map;
    scanf("%d",&n);
    max_index = n;
    buffer.resize(n,0);
    count_map.resize(n,0);
    for(int i=0;i<n;i++){
        scanf("%d",&buffer[i]);
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(buffer[j]<buffer[i])
                count_map[i]++;
        }
        if (count_map[i]-i>=max){
            max_index = i;
            max = count_map[i]-i;
        }
        sum+=count_map[i];
    }
    printf("%d %d\n",sum-max,max_index+1);
    return 0;
}