#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> curRow;
            vector<int> prevRow;
            if (i > 1)
                prevRow = res[i - 1];

            curRow.push_back(1);
            if (i > 1)
            {
                for (int j = 0; j < i - 1; j++)
                {
                    curRow.push_back(prevRow[j] + prevRow[j + 1]);
                }
            }
            if (i > 0)
                curRow.push_back(1);

            res.push_back(curRow);
        }

        return res;
    }
};
