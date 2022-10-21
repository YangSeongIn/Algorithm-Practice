#include <string>
#include <vector>

using namespace std;

int cnt = 0;
vector<bool> visited;

void dfs(int n, int sum, vector<int> numbers, int target) {
    if (n == numbers.size()) {
        if (target == sum) {
            cnt++;
        }
        return;
    } 
    dfs(n + 1, sum + numbers[n], numbers, target);
    dfs(n + 1, sum - numbers[n], numbers, target);
}

int solution(vector<int> numbers, int target) {
    visited.resize(numbers.size());
    dfs(0, 0, numbers, target);
    return cnt;
}
