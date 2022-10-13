#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stk;
    int idx1 = 0;
    int idx2 = 0;
    
    vector<int> obj_list;
    for (int i = 1; i <= order.size(); i++) {
        obj_list.push_back(i);
    }
    
    while (idx1 < order.size() || idx2 < order.size()) {
        if (obj_list[idx1] == order[idx2]) {
            idx2++;
            idx1++;
            answer++;
        } else {
            if (!stk.empty() && stk.top() == order[idx2]) {
                stk.pop();
                idx2++;
                answer++;
            } else {
                if (!stk.empty() && stk.top() > order[idx2]) {
                    break;
                }
                stk.push(obj_list[idx1++]); 
            }
        }
    }
    
    return answer;
}
