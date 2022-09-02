#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<int> d;
    for (int i = 0; i < priorities.size(); i++)
    {
        d.push_back(priorities[i]);
    }
    int max = *max_element(d.begin(), d.end());
    int idx = 1;
    while(true)
    {
        if (d.front() < max)
        {
            int tmp = d.front();
            d.pop_front();
            d.push_back(tmp);
            if (location == 0)
                location += d.size();
        }
        else
        {
            if (location == 0)
                return idx;
            d.pop_front();
            idx++;
            max = *max_element(d.begin(), d.end());
        }
        location--;
    }
    
    return answer;
}
