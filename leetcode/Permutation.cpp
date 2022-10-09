#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void helper (vector<int>& nums, int i, int n) {
            if(i == n) 
            {
                result.push_back(nums);
                return ;
            } 
            else 
            {
                for(int j=i; j < n; j++) 
                {
                    swap(nums[i], nums[j]);
                    helper(nums, i+1, n);
                    swap(nums[i], nums[j]);
                }
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        helper(nums,0,nums.size());
        
        return result;
    }
};