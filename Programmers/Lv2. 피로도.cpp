// next permutation
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int s;
int tmpK;

int calStress(vector<int> vec, vector<vector<int>> dungeons, int k)
{
    int cnt = 0;
    int tmpK = k;
    for (int i = 0; i < vec.size(); i++)
    {
        if (dungeons[vec[i]][0] <= tmpK)
        {
            tmpK -= dungeons[vec[i]][1];
            cnt++;
        }
        else
        {
            break;
        }
    }
    return cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    tmpK = k;
    s = dungeons.size();
    vector<int> vec;
    for (int i = 0; i < s; i++)
    {
        vec.push_back(i);
    }
    do
    {
        answer = max(answer, calStress(vec, dungeons, k));
    }
    while (next_permutation(vec.begin(), vec.end()));
    return answer;
}

// dfs
#include <string>
#include <vector>

using namespace std;

int num;
bool visited[8] = {false, };
int cnt = -1;

void dfs(int n, int k, vector<vector<int>> dungeons)
{
    for (int i = 0; i < num; i++)
    {
        if (!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(n+1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    cnt = max(cnt, n);
}

int solution(int k, vector<vector<int>> dungeons) {
    num = dungeons.size();
    dfs(0, k, dungeons);
    return cnt;
}
