#include <string>
#include <vector>
#include <map>

using namespace std;

string li[4] = { "aya", "ye", "woo", "ma" };
map<string, bool> m;

bool check(int i, vector<string> babbling) {
    string tmp;
    for (int j = 0; j < babbling[i].length();) {
        string sub2 = babbling[i].substr(j, 2);
        if (m[sub2] && tmp != sub2) {
            tmp = sub2;
            j += 2;
            continue;
        }
        string sub3 = babbling[i].substr(j, 3);
        if (m[sub3] && tmp != sub3) {
            tmp = sub3;
            j += 3;
            continue;
        }
        return false;
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (int i = 0; i < sizeof(li) / sizeof(string); i++) {
        m[li[i]] = true;
    }
    for (int i = 0; i < babbling.size(); i++) {
        if (check(i, babbling)) {
            answer++;
        }
    }
    return answer;
}
