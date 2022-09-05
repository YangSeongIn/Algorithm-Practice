#include <string>
#include <vector>

using namespace std;

int cnt = 0;

int solution(string name) {
    int nl = name.length();
    int switchCnt = nl - 1;
    for (int i = 0; i < nl; i++)
    {
        // 위, 아래
        if (name[i] - 'A' > 13)
            cnt += 26 - (name[i] - 'A');
        else
            cnt += name[i] - 'A'; 
        // 오른쪽, 왼쪽
        int idx = i + 1;
        while (idx < nl && name[idx] == 'A') 
        {
            idx++;
        }
        switchCnt = min(switchCnt, i + nl - idx + min(i, nl - idx));
    }
    cnt += switchCnt;
    return cnt;
}

/*
생각한 방식과 구현 방식은 똑같은데 나는 왼쪽 오른쪽을 하나의 식으로 하려다 보니까 막힘
위의 방식은 단순하게 구간을 나눠 더했고 난 실제 움직임을 계산해서 중간에 삑이 많이 난 것 같음
*/
