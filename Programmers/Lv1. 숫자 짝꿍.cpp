#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<char, int> m;
    for (int i = 0; i < X.length(); i++) {
        m[X[i]]++;
    }
    for (int i = 0; i < Y.length(); i++) {
        if (m[Y[i]] > 0) {
            answer += Y[i];
            m[Y[i]]--;
        }
    }
    if (answer == "") return "-1";
    if (answer[0] == '0') return "0";
    stable_sort(answer.rbegin(), answer.rend());
    return answer;
}
