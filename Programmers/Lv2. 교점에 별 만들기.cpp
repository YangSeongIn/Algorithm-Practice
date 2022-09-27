#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long maxX = -1000000000000000;
long long maxY = -1000000000000000;
long long minX = 1000000000000000;
long long minY = 1000000000000000;
vector<pair<long long, long long>> sets;

void getRoot(vector<int>& a, vector<int>& b)
{
    long long det = (long long)a[0] * b[1] - (long long)a[1] * b[0];
    if (det == 0) return;
    long long x = (long long)a[1] * b[2] - (long long)a[2] * b[1];
    long long y = (long long)a[2] * b[0] - (long long)a[0] * b[2];
    if (x % det != 0 || y % det != 0) return;
    x /= det;
    y /= det;
    maxX = max(maxX, x);
    maxY = max(maxY, y);
    minX = min(minX, x);
    minY = min(minY, y);
    sets.push_back(make_pair(x, y));
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    for (int i = 0; i < line.size() - 1; i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            getRoot(line[i], line[j]);
        }
    }
    long long row = maxY - minY + 1;
    long long col = maxX - minX + 1;
    string tmp(col, '.');
    answer.assign(row, tmp);
    for (int i = 0; i < sets.size(); i++)
    {
        long long tx = sets[i].first;
        long long ty = sets[i].second;
        answer[maxY - ty][tx - minX] = '*';
    }
    return answer;
}
