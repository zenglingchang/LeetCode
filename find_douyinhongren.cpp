#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int n,m,a;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&m);
    vector<vector<int> > buffer(n);
    for(int i=0;i<n;i++){
        buffer[i].resize(n,0);
        buffer[i][i]=1;
    }
    int temp1,temp2;
    for(int i=0;i<m;i++){
        scanf("%d,%d",&temp1,&temp2);
        buffer[temp1][temp2] = 1;
        buffer[temp2][temp1] = 1;
    }
    for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                buffer[a][j]=buffer[a][j]||(buffer[a][k]&&buffer[k][j]);
    int count=-1;
	for(int i=0;i<n;i++)
        count+=buffer[a][i];
    printf("%d\n",count);
    return 0;
}