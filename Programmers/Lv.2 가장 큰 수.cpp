#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int& a, const int& b)
{
    string a_str = to_string(a);
    string b_str = to_string(b);
    return stoi(a_str + b_str) > stoi(b_str + a_str);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for (int& i : numbers)
    {
        answer += to_string(i);
    }
    
    if (answer[0] == '0')
        answer = '0';
    return answer;
}
