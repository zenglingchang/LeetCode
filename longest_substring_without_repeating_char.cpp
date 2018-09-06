/* Given a string, find the length of the longest substring without repeating characters. */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

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
    int i=0;
    string s="abcabccbb";
    Solution solute;
    cout<<solute.lengthOfLongestSubstring(s);
    return 0;
}