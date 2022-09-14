#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1);

    for (int i = begin; i <= end; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0 && i / j <= 10000000)
            {
                answer[i - begin] = i / j;
                break;
            }
        }
        if (i != 1 && answer[i - begin] == 0)
            answer[i - begin] = 1;

    }
    return answer;
}
