#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;            // result vector
        vector<string> sortedStrs = strs;      // vector after sorting given strs
        map<string, vector<int>> indexMap;     // map for memorizing indices of anagram set
        map<string, vector<int>>::iterator it; // iterator for index map

        int idx = 0; // index for given input
        for (auto &word : sortedStrs)
        {
            sort(word.begin(), word.end());
            // if the word is not matched with any key in current map
            if (indexMap.find(word) == indexMap.end())
            {
                vector<int> indexVec = {idx};
                indexMap.insert(make_pair(word, indexVec));
            }
            // if not
            else
            {
                indexMap[word].push_back(idx); // push current index to value of key
            }
            idx++; // increment index
        }

        // generate result vector after generating complete index map
        for (it = indexMap.begin(); it != indexMap.end(); it++)
        {
            vector<string> tempVec;
            for (auto index : it->second)
            {
                tempVec.push_back(strs[index]);
            }
            res.push_back(tempVec);
        }

        return res;
    }
};