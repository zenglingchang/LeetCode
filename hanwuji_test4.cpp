#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,k,sum;
    scanf("%d %d",&n,&k);
    vector<int> buffer(n),buffer1(max(k,n-k)),buffer2(min(k,n-k));
    for(int i=0;i<n;i++){
        scanf("%d",&buffer[i]);
    }
    sort(buffer.begin(),buffer.end());
    int count = 0;
    for(int i=0;i<buffer1.size();i++){
        if(i%2)
            buffer1[i]=buffer[count++];
        else
            buffer1[i]=buffer[n-count];
    }
    for(int i=0;i<buffer2.size();i++){
        if(i%2)
            buffer2[i]=buffer[count++];
        else
            buffer2[i]=buffer[n-count];
    } 
    for(int i=0;i<buffer1.size();i++){
        for(int j=0;j<buffer2.size();j++)
            sum+=abs(buffer1[i]-buffer2[j]);
    }
    printf("%d\n",sum);
    return 0;
}
