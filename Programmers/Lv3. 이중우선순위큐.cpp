#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> d;
greater<int> cmp;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
        char c = operations[i][0];
        int n = stoi(operations[i].substr(2, operations[i].length() - 2));
        if (c == 'I')
        {
            d.push_back(n);
            sort(d.begin(), d.end(), cmp);
        }
        else
        {
            if (d.size() > 0)
            {
                if (n == 1)
                {
                    d.pop_front();
                }
                else
                {
                    
                    d.pop_back();
                }
            }
        }
    }
    if (d.size() == 0)
    {
        answer = vector<int>({ 0, 0 });
    }
    else
    {
        answer = vector<int>({ d[0], d[d.size() - 1] });
    }
    return answer;
}
