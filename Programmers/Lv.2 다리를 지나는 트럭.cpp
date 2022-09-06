#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<pair<int, int>> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
	int idx = 0;
	int cnt = 0;

	while (cnt != truck_weights.size())
	{
		if (idx < truck_weights.size() && weight >= truck_weights[idx])
		{
			q.push_back(make_pair(truck_weights[idx], 0));
			weight -= truck_weights[idx++];
		}
		for (auto itr = q.begin(); itr != q.end(); itr++)
		{
			itr->second += 1;
		}
		if (!q.empty() && q.front().second == bridge_length)
		{
			weight += q.front().first;
			q.pop_front();
			cnt++;
		}
		answer++;
	}

    return answer + 1;
}
