#include <iostream>
#include <vector>

using namespace std;
// Warn : If we don't set pre-defined size of a vector,
// Insertion a value into vector can cause an segmentation fault error
vector<int> permutationEquation(vector<int> p)
{
    vector<int> yVec;

    for (int i = 0; i < p.size(); i++)
    {
        int index;
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == (i + 1))
            {
                index = j;
                break;
            }
        }

        for (int k = 0; k < p.size(); k++)
        {
            if (p[k] == index + 1)
            {
                yVec.push_back(k + 1);
            }
        }
    }

    return yVec;
}

int main()
{
    vector<int> input;
    input.push_back(5);
    input.push_back(2);
    input.push_back(1);
    input.push_back(3);
    input.push_back(4);
    permutationEquation(input);
}