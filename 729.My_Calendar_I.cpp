#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

static int desyncio = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = m.lower_bound(start);
        if(it!=m.end() && it->first < end) return false;
        if(it!=m.begin() && prev(it)->second > start) return false;
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
 
int main(){
    MyCalendar mycalendar;
    cout<<mycalendar.book(10, 20)<<endl; // returns true
    cout<<mycalendar.book(15, 25)<<endl; // returns false
    cout<<mycalendar.book(20, 30)<<endl; // returns true
    return 0;
}