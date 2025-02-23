#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <string>
#include "Source.h"

using namespace std;

string prov(string s);

int main()
{
	//int b = a;
	// 5 6
	string s;
	getline(cin, s);
	string x = prov(s);
	cout << x;
	return 0;
}


string prov(string s) {
	int dots = 0;
	bool numbers = 0, letters = 0, symbols = 0, def = 0;
	//cout << s << '\n';
	while (s.size() > 0 && s[0] == ' ')	s.erase(s.begin());
	while (s.size() > 0 && s[s.size() - 1] == ' ')	s.erase(s.begin() + s.size() - 1);
	if (s.size() == 0) {
		return "It's just a bunch of characters";
	}
	if (s[0] == '.' || s[s.size() - 1] == '.') {
		return "It's just a bunch of characters";
	}
	//cout << s << '\n';
	for (int i = 0;i < s.size(); i++) {
		if (s[i] == '.') {
			dots++;
		}
		else if (s[i] == '-')
		{
			def = 1;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			numbers = 1;
		}
		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			letters = 1;
		}
		else {
			symbols = 1;
		}
	}

	if (dots == 1 && !letters && !symbols && numbers && !def)		return "this is a double type";
	else if (!letters && !dots && numbers && !symbols && !def)		return "this is a integer type";
	else if (!dots  && !symbols && !numbers && !dots && s[s.size() - 1]!='-')		return "this is a string type";
	else													return "It's just a bunch of characters";
}