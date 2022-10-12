#include <string>
#include <vector>
#include <map>

using namespace std;

int discountSize = 0;

bool check(vector<string>& discount, map<string, int>& m, int idx) {
    for (int i = idx; i < 10 + idx; i++) {
        if (m[discount[i]] > 0) {
            m[discount[i]]--;
        }
        else {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    map<string, int> tmpM;
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
    tmpM = m;
    
    int idx = 0;
    discountSize = discount.size();
    while (idx < discountSize - 9) {
        if (check(discount, m, idx)) {
            answer++;
        } 
        m = tmpM;
        idx++;
    }
    
    
    return answer;
}
