#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    int map[256]={0};
    
    char cur = ' ';
    for(int i=0;i<s.size();i++){
        if(map[s[i]]==0)
            cur = s[i];
        map[s[i]]++;
    }
    if(map[cur]==1)
        cout<<cur;
    return 0;
}