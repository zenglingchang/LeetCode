#include<iostream>
#include<math.h>
using namespace std;
 
int main(){
    int X,Y,Z,count=0;
    cin>>X>>Y>>Z;
    for(int i=1;i<X;i++){
        for(int j=1;j<Y&&j<i+1;j++)
            count = (count+2*j-1)%1000000007;
    }
    cout<<count;
    return 0;
}
