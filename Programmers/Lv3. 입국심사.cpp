#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s = 1;
    long long e = (long long)times[times.size() - 1] * n;
    sort(times.begin(), times.end());
    while (s <= e)
    {
        long long tmp = 0;
        long long m = (s + e) / 2;
        for (int i = 0; i < times.size(); i++)
        {
            tmp += m / times[i];
        }
        if (tmp >= n)
        {
            answer = m;
            e = m - 1; 
        }
        else
        {
            s = m + 1;
        }
    }
    return answer;
}
