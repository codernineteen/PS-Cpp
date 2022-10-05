#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c, int k)
{
    int energy = 100;

    int cycle = c.size();
    if (c.size() % k != 0)
    {
        cycle *= k;
    }

    for (int i = 0; i < cycle; i += k)
    {
        int index = i % c.size();
        if (c[index] == 1)
        {
            energy -= 3;
        }
        else
        {
            energy -= 1;
        }
    }

    return energy;
}

int main()
{
    vector<int> input = {0, 0, 1, 1, 0, 1, 0, 0};
    jumpingOnClouds(input, 2);
}