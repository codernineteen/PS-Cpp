//problem : https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

//solution
#include <vector>
using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> result;
    k %= a.size();
    
    for (int i = a.size() - k; i < a.size(); i++) 
    {
        result.push_back(a[i]);
    }

    for (int i = 0; i < a.size()-k; i++)
    {
        result.push_back(a[i]);

    }
    
    vector<int> returnVector;
    for(int i : queries) {
        if(i < result.size() && i > -1) {
            returnVector.push_back(result[i]);
        }
    }

    return returnVector;
}

int main() {
    circularArrayRotation({3,4,5}, 2, {1,2}); // [5,3];
}