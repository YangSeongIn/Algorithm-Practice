#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
vector<bool> visited;
string tmp = "";

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

void combination(int idx, int n, string s, int lim)
{
    if (n == lim)
    {
        m[tmp]++;
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        tmp += s[i];
        combination(i + 1, n + 1, s, lim);
        tmp = tmp.substr(0, tmp.length() - 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < course.size(); j++)
        { 
            combination(0, 0, orders[i], course[j]);
            tmp = "";
        }
    }
    vector<pair<string, int>> p;
    for (auto& a : m)
    {
        if (a.second > 1)
        {
            p.push_back(make_pair(a.first, a.second));
        }
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < course.size(); i++)
    {
        int maximum = -1;
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j].first.length() != course[i]) continue;
            else if (maximum == -1)
            {
                answer.push_back(p[j].first);
                maximum = p[j].second;
            }
            else if (maximum == p[j].second)
            {
                answer.push_back(p[j].first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
