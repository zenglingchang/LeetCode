#include<iostream>
using namespace std;
int location_of_zero = 6;
void swap_with_zero(int* array, int len, int n){
    swap(array[n],array[location_of_zero]);
    location_of_zero = n;
}

class Solution {
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int* array, int len) {
        for(int i=0;i<len;i++){
            int max = len-i-1;
            for(int j=i;j<len;j++){
                if (array[j] == max && j!=i){
                    swap_with_zero(array,len,i);
                    swap_with_zero(array,len,j);
                    break;
                }
            }
        }
    }
};

int main(){
    int array[] = {6,2,1,4,3,5,0};
    Solution solute;
    solute.sort(array,7);
    for(int i=0;i<7;i++)
        cout<<" "<<array[i];
    return 0;
}