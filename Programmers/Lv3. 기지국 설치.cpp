// 내가 작성한 코드
// 작성하면서 간단한 방법이 있을 줄 알고 있었지만 최대한 빨리 풀자가 목표여서 생각나는대로 작성했다.
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = w * 2 + 1;
    // 처음 구간
    if (stations[0] - w - 1 >= 0)
    {
        int k = (stations[0] - w - 1) / range;
        if ((stations[0] - w - 1) % range == 0)
            answer += k;
        else
            answer += k + 1;
    }
    // 앞, 마지막 제외 중간 구간
    for (int i = 0; i < stations.size() - 1; i++)
    {
        if (stations[i + 1] - w - (stations[i] + w) - 1 > 0)
        {
            int k = (stations[i + 1] - w - (stations[i] + w) - 1) / range;
            if ((stations[i + 1] - w - (stations[i] + w) - 1) % range == 0)
                answer += k;
            else
                answer += k + 1;
        }
    }
    // 마지막 구간
    if (stations[stations.size() - 1] + w < n)
    {
        int k = (n - (stations[stations.size() - 1] + w)) / range;
        if ((n - (stations[stations.size() - 1] + w)) % range == 0)
            answer += k;
        else
            answer += k + 1;
    }

    return answer;
}

// 간단한 코드
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int idx = 0;
    double range = w * 2 + 1;
    for (int station : stations)
    {
        double a = station - w - 1 - idx;
        int b = (int)ceil(a / range);
        answer += max(0, b);
        idx = station + w;
    }
    answer += (int)ceil((double)(n - idx) / range);

    return answer;
}
