#include <string>
#include <vector>
#include <stack>

using namespace std;

int answer = 0;
stack<int> stk;
stack<int> tmpStk;
stack<int> zeroStk;

bool check() {
    int idx = 2;
    while (true) {
        if (idx == 0) {
            answer++;
            return true;
        }
        if (stk.empty()) return false;
        if (stk.top() == idx) {
            tmpStk.push(stk.top());
            stk.pop();
            idx--;
        }
        else return false;
    }
}

int solution(vector<int> ingredient) {
    for (int i = 0; i < ingredient.size(); i++) {
        if (!stk.empty() && ingredient[i] == 1 && stk.top() == 3) {
            stk.pop();
            if (!check()) {
                stk.push(3);
                while (!tmpStk.empty()) {
                    stk.push(tmpStk.top());
                    tmpStk.pop();
                }
                stk.push(1);
            } else {
                tmpStk = zeroStk;
            }
        } else {
            stk.push(ingredient[i]);
        }
    }
    return answer;
}
