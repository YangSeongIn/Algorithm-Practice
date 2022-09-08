#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string tmpS = "";
map<int, int> m;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;

    for (int i = 2; i < s.length() - 1; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            tmpS += s[i];
        }
        if (s[i] == ',')
        {
            if (tmpS.length() != 0)
            {
                m[stoi(tmpS)]++;
                tmpS = "";
            }
        }
        else if (s[i] == '}')
        {
            m[stoi(tmpS)]++;
            tmpS = "";
        }
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for (auto i : v)
    {
        answer.push_back(i.first);
    }

    return answer;
}
