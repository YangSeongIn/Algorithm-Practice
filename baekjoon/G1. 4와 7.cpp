#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string getAnswer(int n)
{
	n++;
	string tmp = "";
	while (n > 0)
	{
		tmp = to_string(n % 2) + tmp;
		n /= 2;
	}
	tmp = tmp.substr(1, tmp.length() - 1);
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '0') tmp[i] = '4';
		else tmp[i] = '7';
	}
	return tmp;
}

int main()
{
	cin.tie();
	cout.tie();
	ios_base::sync_with_stdio(false);
	int N;
	string ans;
	cin >> N;
	ans = getAnswer(N);
	cout << ans;
	return 0;
}
