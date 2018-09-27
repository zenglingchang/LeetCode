#include<vector>
#include<stdio.h>
using namespace std;
bool boolArray[100000]={0};
int main(){
    int n,count = 0;
    vector<int> buffer1,buffer2;
    scanf("%d",&n);
    buffer1.resize(n);
    buffer2.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&buffer1[i],&buffer2[i]);
    boolArray[0]=true;
    for(int i=0;i<n;i++){
        if((!boolArray[0])&&buffer1[i]==2){
            boolArray[buffer2[i]-1]=true;
        }
    }
    for(int i=0;i<n;i++)
        if(boolArray[i])
            count++;
    printf("0 %d\n",count);
    
}