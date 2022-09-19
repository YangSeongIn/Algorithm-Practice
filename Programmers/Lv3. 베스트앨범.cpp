#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;
vector<vector<int>> vec;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] != b[0]) return a[0] > b[0];
    if (a[1] != b[1]) return a[1] > b[1];
    return a[2] < b[2];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];   
    }
    for (int i = 0; i < genres.size(); i++)
    {
       vec.push_back({m[genres[i]], plays[i], i});
    }
    stable_sort(vec.begin(), vec.end(), cmp);
    int tmp = -1;
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (tmp != vec[i][0])
        {
            tmp = vec[i][0];
            cnt = 0;
        }
        cnt++;
        if (cnt <= 2)
            answer.push_back(vec[i][2]);
    }
    return answer;
}
