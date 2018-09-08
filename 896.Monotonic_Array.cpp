#include<iostream>
#include<vector>
using namespace std;

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc=true,rec=true;
        for(int i=1;i<A.size();i++){
            inc &= (A[i]>=A[i-1]);
            rec &= (A[i]<=A[i-1]);
        }
        return inc|rec;
    }
};
int main(){
    int x[]={1,2,3,4,3,6,7,8,9};
    vector<int> A(&x[0],&x[8]);
    Solution solute;
    cout<<solute.isMonotonic(A);
}