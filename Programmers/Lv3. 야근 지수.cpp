#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    
    while (n > 0)
    {
        if (pq.top() <= 0) break;
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp - 1);
        n--;
    }
    
    while (!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();
        answer += pow(tmp, 2);
    }
    return answer;
}
