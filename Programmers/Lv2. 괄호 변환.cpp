#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string s) {
    stack<char> stk;
    int idx = 0;
    do {
        if (s[idx] == '(') {
            stk.push(s[idx]);
        }
        else {
            if (stk.size() > 0 && stk.top() == '(') {
                stk.pop();
            }
            else {
                stk.push(s[idx]);
            }
        }
        idx++;
    } while (idx != s.length());
    if (stk.empty()) return true;
    return false;
}

string recursive(string p) {
    // 1
    if (p == "") return "";
    // 2
    int cnt = 0;
    int idx = 0;
    string u = "";
    string v = "";
    do {
        p[idx] == '(' ? cnt++ : cnt--;
        u += p[idx];
        idx++;
    } while (idx != p.length() && cnt != 0);
    for (int i = idx; i < p.length(); i++) {
        v += p[i];
    }
    // 3
    if (check(u)) {
        return u + recursive(v);
    }
    // 4
    else {
        // 4-1 ~ 4-3
        string emptyStr = '(' + recursive(v) + ')';
        // 4-4
        string tmpU = u.substr(1, u.length() - 2);
        for (int i = 0; i < tmpU.length(); i++) {
            if (tmpU[i] == '(') tmpU[i] = ')';
            else tmpU[i] = '(';
        }
        emptyStr += tmpU;
        return emptyStr;
    }
}

string solution(string p) {
    if (check(p)) return p;
    return recursive(p);
}
