#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void solution(int head, vector<int> &buffer, int numbers, int &count,vector<int> &location){
    if(numbers == 0){
        int sum=0;
        for(int k=head;k<buffer.size();k++){
            sum = sum*10+buffer[k];
        }
        if(sum<256){
            count+=1;
            int temp=2;
            for(int i=0;i<buffer.size();i++){
                cout<<buffer[i];
                if(i==location[temp]){
                    cout<<".";
                    temp--;
                }
            }
            cout<<endl;
        }
    }
    else{
        for(int i=head+1;i<buffer.size();i++){
            int sum=0;
            for(int k=head;k<i;k++){
                sum = sum*10+buffer[k];
            }
            if(sum>255)
                break;
            location[numbers-1]=i-1;
            if(buffer[i]!=0)
                solution(i,buffer,numbers-1,count,location);
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<int> buffer,location(3);
    for(int i=0;i<s.size();i++)
        buffer.push_back(s[i]-'0');
    int count=0,head=0;
    solution(0,buffer,3,count,location);
    cout<<count<<endl;
    return 0;
}