// Problem source: https://leetcode.com/problems/generate-parentheses/submissions/
//  status : failed to solove
//  solution: brute force(This solution is from leetcode)

#include <vector>
#include <string>

using namespace std;

class Solution
{
    vector<string> res;
    string curString;

public:
    // generate all parenthesis case by using recursion technique
    void generateAll(string curString, int pos, vector<string> &result, int length)
    {
        if (pos == length)
        {
            // check if the current parenthesis is valid
            if (validParenthesis(curString))
            {
                result.push_back(curString);
            }
        }
        else
        {
            curString += "(";
            generateAll(curString, pos + 1, result, length);
            curString.pop_back();
            curString += ")";
            generateAll(curString, pos + 1, result, length);
            curString.pop_back();
        }
    }

    // validation of parenthe sis
    bool validParenthesis(string curString)
    {
        int balance = 0; // make a balance : 0
        for (auto c : curString)
        {
            if (c == '(')
                balance++;
            else
                balance--;

            // if ')' set larger than '(' set, return false
            if (balance < 0)
                return false;
        }

        // return whether balance is equal to zero
        return (balance == 0);
    }

    vector<string> generateParenthesis(int n)
    {
        generateAll(curString, 0, res, 2 * n);
        return res;
    }
};