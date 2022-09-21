#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const vector<int>&a, const vector<int>&b)
    {
        return a[1] > b[1];
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx(0), curTime(0);
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (idx < jobs.size() || !pq.empty())
    {
        if (jobs.size() > idx && curTime >= jobs[idx][0])
        {
            pq.push(jobs[idx++]);
            continue;
        }
        if (!pq.empty())
        {
            curTime += pq.top()[1];
            answer += curTime - pq.top()[0];
            pq.pop();
        }
        else
        {
            curTime = jobs[idx][0];
        }
        
    }
    
    return answer / jobs.size();
}
