#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> v;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == 0) continue;
        int idx = i;
        int cnt = 0;
        while (true) {
            if (cards[idx] != 0) {
                cnt++;
                int tmpI = cards[idx];
                cards[idx] = 0;
                idx = tmpI - 1; 
            }
            else {
                break;
            }
        }
        v.push_back(cnt);
    }
    if (v.size() == 1) return 0;
    sort(v.rbegin(), v.rend());
    answer = v[0] * v[1];
    return answer;
}
