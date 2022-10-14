#include <string>
#include <set>
#include <vector>

using namespace std;

set<vector<pair<int, int>>> s;

int solution(string dirs) {
    int answer = 0;
    pair<int, int> curPoint(make_pair(0, 0));
    for (int i = 0; i < dirs.length(); i++) {
        if (dirs[i] == 'U' && curPoint.second + 1 <= 5) {
            pair<int, int> nextPoint = make_pair(curPoint.first, curPoint.second + 1);
            s.insert(vector<pair<int, int>>({ curPoint, nextPoint }));
            s.insert(vector<pair<int, int>>({ nextPoint, curPoint }));
            curPoint = nextPoint;
        }
        else if (dirs[i] == 'D' && curPoint.second - 1 >= -5) {
            pair<int, int> nextPoint = make_pair(curPoint.first, curPoint.second - 1);
            s.insert(vector<pair<int, int>>({curPoint, nextPoint }));
            s.insert(vector<pair<int, int>>({nextPoint, curPoint }));
            curPoint = nextPoint;
        }
        else if (dirs[i] == 'R' && curPoint.first + 1 <= 5) {
            pair<int, int> nextPoint = make_pair(curPoint.first + 1, curPoint.second);
            s.insert(vector<pair<int, int>>({ curPoint, nextPoint }));
            s.insert(vector<pair<int, int>>({ nextPoint, curPoint }));
            curPoint = nextPoint;
        }
        else if (dirs[i] == 'L' && curPoint.first - 1 >= -5) {
            pair<int, int> nextPoint = make_pair(curPoint.first - 1, curPoint.second);
            s.insert(vector<pair<int, int>>({ curPoint, nextPoint }));
            s.insert(vector<pair<int, int>>({ nextPoint, curPoint }));
            curPoint = nextPoint;
        }
    }
    answer = s.size() / 2;
    return answer;
}
