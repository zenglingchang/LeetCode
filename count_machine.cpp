#include<iostream>
using namespace std;

int main(){
    long long int n,temp,i=1;
    cin>>n;
    temp = n/3+1;
    while(i<=temp){
        i=i<<1;
    }
    if(n==3*((i>>1)-1))
        cout<<1<<endl;
    else{
        i=3*(i-1);
        cout<<i-n+1<<endl;
    }
    return 0;
}