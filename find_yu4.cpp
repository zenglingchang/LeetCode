#include<stdio.h>
#include<vector>
using namespace std;

int main(){
    int n,k,count=0,temp;
    scanf("%d %d",&n,&k);
    vector<int> map(k,0);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        map[temp%k]++;
    }
/*     for(int i=0;i<k;i++)
        printf("map[%d] = %d\n",i,map[i]); */
    int len = k/2+(k%2?0:1);
    for(int i=1;i<=len;i++){
        count += max(map[i],map[k-i]);
    }
    if(k%2==0&&map[k/2]>0)
        count++;
    printf("%d\n",count);
    return 0;
}