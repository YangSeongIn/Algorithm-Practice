#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long q1Sum = 0;
    long q2Sum = 0;
    int qSize = queue1.size();

    for (int& i : queue1)
    {
        q1Sum += i;
    }
    for (int& i : queue2)
    {
        q2Sum += i;
    }
    int pointer1{ 0 }, pointer2{ 0 };
    while (answer < 2 * qSize + 2)
    {
        if (q1Sum == q2Sum)
            return answer;
        else if (q1Sum > q2Sum)
        {
            int tmp = queue1[pointer1];
            q1Sum -= tmp;
            pointer1++;

            queue2.push_back(tmp);
            q2Sum += tmp;
        }
        else if (q1Sum < q2Sum)
        {
            int tmp = queue2[pointer2];
            q2Sum -= tmp;
            pointer2++;

            queue1.push_back(tmp);
            q1Sum += tmp;
        }
        answer++;
    }

    return -1;
}
