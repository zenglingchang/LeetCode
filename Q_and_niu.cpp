#include<iostream>
#include<string>
#include<math.h>
using namespace std;
 
int main(){
    long long int a,b,temp,count=0;
    cin>>a>>b;
    temp=(int)(sqrt((a+b)*2));
    cout<<"temp:"<<temp<<endl;
    if(temp*(temp+1)/2==(a+b)){
        for(long long int j=temp;j>0&&a>0;j--)
            if(a-j>=0){
                a -= j;
                count+=1;
            }
            else{
                count+=1;
                break;
            }
        cout<<count;
    }
    else
        cout<<-1;
    return 0;
}