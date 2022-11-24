#include <string>

using namespace std;

class Solution
{
public:
    // palindrome check
    bool isPalindrome(const string &s)
    {
        for (int i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s)
    {
        int count = s.length();

        int subLength = 2;
        // iterate until substring length is same with the length of original string
        while (subLength <= s.length())
        {
            for (int i = 0; i < (s.length() - subLength + 1); i++)
            {
                bool result = isPalindrome(s.substr(i, subLength));
                if (result == true)
                {
                    count += 1;
                }
            }
            subLength++;
        }

        return count;
    }
};