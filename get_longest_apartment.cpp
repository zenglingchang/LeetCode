#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int X[]={0,0,1,-1};
int Y[]={1,-1,0,0};


void bfs_set_zero(int &i, int &j, vector< vector<int> > &buffer){
    if(i>=0&&i<buffer.size()&&j>=0&&j<buffer.size()&&buffer[i][j] == 1){
        buffer[i][j] = 0;
        int x,y;
        for(int k=0;k<4;k++){
            x = X[k]+i, y = Y[k]+j;
            bfs_set_zero(x, y, buffer);
        }
    }
}

int main(){
    int m;
    scanf("%d",&m);
    vector< vector<int> > buffer(m);
    for(int i=0;i<m;i++)
        buffer[i].resize(m);
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&buffer[i][j]);
    int sum = 0;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            if (buffer[i][j] == 1){
                sum += 1;
                bfs_set_zero(i, j, buffer);
            }
    printf("%d",sum);
    return 0;
}