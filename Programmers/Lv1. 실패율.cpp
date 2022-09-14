#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double>& p1, const pair<int, double>& p2)
{
    return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(answer.begin(), answer.end());
    vector<pair<int, double>> v;
    map<int, double> m;

    int num = stages.size();
    for (int i = 0; i < stages.size(); i++)
    {
        m[stages[i]]++;
    }
    for (int i = 1; i <= N; i++)
    {
        int tmpMi = m[i];
        m[i] = m[i] / num;
        v.push_back(make_pair(i, m[i]));
        num -= tmpMi;
    }
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].first);
    }
    
    return answer;
}
