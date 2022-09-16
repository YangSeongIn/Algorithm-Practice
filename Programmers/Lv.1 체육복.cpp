#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n + 1);
    for (int& i : reserve)
    {
        v[i] += 1;
    }
    for (int& i : lost)
    {
        v[i] -= 1;
    }
    for (int i = 1; i <= v.size(); i++)
    {
        if (v[i] == -1)
        {
            if (i - 1 > 0 && v[i - 1] == 1)
            {
                v[i - 1] = 0;
                v[i] = 0;
            }
            else if (i + 1 < v.size() && v[i + 1] == 1)
            {
                v[i + 1] = 0;
                v[i] = 0;
            }
        }
    }
     for (int& i : v)
    {
        if (i >= 0)
            answer++;
    }
    return answer - 1;
}
