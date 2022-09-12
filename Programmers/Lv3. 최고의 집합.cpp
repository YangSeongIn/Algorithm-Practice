#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s < n) return vector<int>({-1});
    while (n > 1)
    {
        int k = s / n;
        s -= k;
        answer.push_back(k);
        n--;
    }
    answer.push_back(s);
    return answer;
}
