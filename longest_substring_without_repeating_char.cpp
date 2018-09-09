/* Given a string, find the length of the longest substring without repeating characters. */
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

/* static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}(); */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> location(256,-1);
        int result = 0,head=-1;
        for(int i=0;i<s.length();i++){
            if(location[s[i]] >= head)
                head = location[s[i]];
            result = max(result, i-head);
            location[s[i]] = i;
        }
        return result;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solute;
    std::ios::sync_with_stdio(false);
    cout<<solute.lengthOfLongestSubstring(s)<<endl;
    return 0;
}