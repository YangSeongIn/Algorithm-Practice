#include <string>
#include <vector>

using namespace std;

long long factorial(long long n)
{
    long long result = n;
    for (int i = 1; i < n - 1; i++)
    {
        result *= n - i;
    }
    return result;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numList;
    for (int i = 1; i <= n; i++)
    {
        numList.push_back(i);
    }
    if (k == 1) return numList;
    k -= 1;
    long long lln = (long long)n;
    long long tmp = factorial(lln);
    while (numList.size() > 1)
    {
        tmp /= n--;
        int a = k / tmp;
        answer.push_back(numList[a]);
        numList.erase(numList.begin() + a);
        k %= tmp;
    }
    answer.push_back(numList[0]);
    return answer;
}
