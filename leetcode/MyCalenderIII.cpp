#include <map>

using namespace std;

class MyCalendarThree {
public:
    
    map<int, int> calMap;
    
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        int count = 0, res = 0;
        calMap[start]++;
        calMap[end]--;
        for(auto& [_, value] : calMap) {
            count += value;
            res = max(res, count);
        }
        return res;
    }
};


int main() {

}