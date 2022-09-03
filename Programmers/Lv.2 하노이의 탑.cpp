#include <string>
#include <vector>

using namespace std;

vector<vector<int>> tmp;

void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        tmp.push_back({a, c});   
        return;
    }
    hanoi(n - 1, a, c, b);
    tmp.push_back(vector<int>({a, c}));
    hanoi(n - 1, b, a, c);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return tmp;
}
