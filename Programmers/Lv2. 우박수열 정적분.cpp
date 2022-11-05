#include <string>
#include <vector>
#include <iostream>

using namespace std;

double calArea(double a, double b) {
    return (a + b) / 2;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> values;
    while (true) {
        int tmp = k;
        if (k == 1) {
            break;
        }
        if (k % 2 == 0) {
            k /= 2;
        } 
        else {
            k = 3 * k + 1;
        }
        values.push_back(calArea(tmp, k));
    }
    int vsize = values.size();
    for (int i = 0; i < ranges.size(); i++) {
        double result = 0;
        if (ranges[i][0] > vsize + ranges[i][1]) {
            result = -1;
        }
        else {
            for (int j = ranges[i][0]; j < vsize + ranges[i][1]; j++) {
                result += values[j];
            }
        }
        answer.push_back(result);
    }
    return answer;
}
