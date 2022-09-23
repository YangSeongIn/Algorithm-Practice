#include <string>
#include <vector>
#include <numeric>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    deque<int> dq1(queue1.begin(), queue1.end());
    deque<int> dq2(queue2.begin(), queue2.end());
    long a = accumulate(dq1.begin(), dq1.end(), 0);
    long b = accumulate(dq2.begin(), dq2.end(), 0);
    int maxSize = queue1.size();
    while (a != b)
    {
        if (a > b)
        {
            int dq1Front = dq1.front();
            a -= dq1Front;
            dq2.push_back(dq1Front);
            b += dq1Front;
            dq1.pop_front();
        }
        else if (a < b)
        {
            int dq2Front = dq2.front();
            dq1.push_back(dq2Front);
            b -= dq2Front;
            dq2.pop_front();
            a += dq2Front;
        }
        answer++;
        if (answer > maxSize * 3) 
        {
            return -1;
        }
    }
    
    return answer;
}
