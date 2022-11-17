#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // reverse matrix with algorithm library
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[0].size(); j++)
            {
                // swap only once when column index is bigger or equal than row index.
                // That is, transpose matrix
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
