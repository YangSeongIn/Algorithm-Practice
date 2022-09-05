#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

vector<char> arr;
vector<bool> visited;
string tmp;
set<int> strSet;

bool check(string s)
{
    int n = stoi(s);
    if (n == 0 || n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void permutation(int cnt)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (visited[i]) continue;
        visited[i] = true;
        tmp += arr[i];
        if (check(tmp)) strSet.insert(stoi(tmp));
        permutation(cnt + 1);
        tmp = tmp.substr(0, tmp.length() - 1);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    for (char& c : numbers)
    {
        arr.push_back(c);
    }
    visited.resize(arr.size() + 1);

    permutation(0);
    answer = strSet.size();

    return answer;
}
