// 답은 맞지만 효율성에서 합격 못한 
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

set<string> s;
map<string, bool> m;
int figures;
int minF = 100003;
pair<int, int> p;
bool b = false;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    for (int i = 0; i < gems.size(); i++)
    {
        s.insert(gems[i]);
    }
    figures = s.size();
    int idx = 0;
    while (true)
    {
        for (int i = idx; i < gems.size(); i++)
        {
            if (!m[gems[i]])
            {
                m[gems[i]] = true;
                if (m.size() == figures)
                {
                    if (i - idx < minF)
                    {
                        minF = i - idx;
                        p = make_pair(idx + 1, i + 1);
                        idx++;
                        b = true;
                        m.clear();
                        break;
                    }
                }
            }
        }
        if (!b)
        {
            idx++;
        }
        else
        {
            b = false;
        }
        if (idx == gems.size() - 1) break;
    }
    answer.push_back(p.first);
    answer.push_back(p.second);

    return answer;
}

// 효율성까지 통과한 코드 (투 포인터)
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int left = 0; 
int right;
unordered_map<string, int> m;
int mini;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s(gems.begin(), gems.end());
    for (int i = 0; i < gems.size(); i++)
    {
        m[gems[i]]++;
        if (m.size() == s.size()) break;
        right = i + 1;
    }
    mini = right - left;
    answer[0] = left + 1;
    answer[1] = right + 1;
    while (right < gems.size())
    {
        string tmp = gems[left];
        m[tmp]--;
        left++;
        if (m[tmp] == 0)
        {
            right++;
            for (; right < gems.size(); right++)
            {
                m[gems[right]]++;
                if (tmp == gems[right])
                {
                    break;
                }
            }
        }
        if (right - left < mini)
        {
            mini = right - left;
            answer[0] = left + 1;
            answer[1] = right + 1;
        }
    }

    return answer;
}
