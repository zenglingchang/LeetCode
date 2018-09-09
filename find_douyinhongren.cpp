#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    vector<vector<int> > buffer(n);
    for(int i=0;i<n;i++){
        buffer[i].resize(n,0);
        buffer[i][i]=1;
    }
    int temp1,temp2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&temp1,&temp2);
        buffer[temp1-1][temp2-1] = 1;
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                buffer[i][j]=buffer[i][j]||(buffer[i][k]&&buffer[k][j]);
    int count=0;
    for(int i=0;i<n;i++){
        bool temp=true;
        for(int j=0;j<n;j++)
            if(buffer[j][i]==0)
                temp=false;
        if(temp)
            count+=1;
    }
    printf("%d\n",count);
    return 0;
}