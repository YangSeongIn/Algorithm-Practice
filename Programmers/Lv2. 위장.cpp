/* 
고등교육 과정 중 확률과 통계 부분에서 사용하던 방법을 사용. + 1 씩 한 경우를 곱해서 아무것도 착용하지 않은 경우를 빼는 식으로 하더라,, 난 순열 써서 하려고 했는디,,
좋은거 배워갑니다.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, vector<string>> m;
vector<int> num;

int solution(vector<vector<string>> clothes) {
    int cnt = 1;
    for (int i = 0; i < clothes.size(); i++)
        m[clothes[i][1]].push_back(clothes[i][0]);
    for (auto itr : m)
        cnt *= itr.second.size() + 1;
    cnt -= 1;
    return cnt;
}
