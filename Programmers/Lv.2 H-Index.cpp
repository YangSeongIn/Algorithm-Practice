#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = citations[citations.size() - 1]; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = citations.size() - 1; j >= 0; j--)
        {
            if (citations[j] >= i)
            {
                cnt++;
            }
            if (cnt == i)
            {
                return i;
            }
        }
    }
    return 0;
}
