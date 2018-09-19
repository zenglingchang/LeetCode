#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
 

vector<int> getnext(string W){
	int i=0,j=-1;
	vector<int> next(W.size(),-1);
	while(i<W.size()) {
		if(j==-1||W[i]==W[j]) {
			next[++i]=++j;
		}
		else j=next[j];
	}
    return next;
}

 

int kmp(string T, string W){
	int i=0,j=0,ans=0;
    vector<int> next = getnext(W);
	while(i<T.size()) {
		if(T[i]==W[j]||j==-1) ++i,++j;
		else j=next[j];
		if(j==W.size()) {
			ans++;
			j=next[j-1];
			i--;
		}
	}
	return ans;
}

int main(){
    unordered_map<string,int> sub_string;
    int k,result=0;
    string A,B;
    cin>>k;
    cin>>A;
    cin>>B;
    for(int i=0;i+k<=A.size();i++){
        sub_string[A.substr(i,k)] = 1;
    }
    for(auto p:sub_string)
        result+=kmp(B,p.first);
    cout<<result;
    return 0;
}