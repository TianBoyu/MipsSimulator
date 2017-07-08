#ifndef TOOLS_H
#define TOOLS_H
#include <string>
using namespace std;
#define LL long long
class Tools
{
private:
	Tools() {}
	Tools(const Tools & x) = delete;
	Tools(Tools && x) = delete;
public:
	inline LL toInt(string now)
	{
		LL ans = 0; bool minus = 0;
		if (now[0] == '-') minus = 1;
		for (int i = 0; i < now.length(); ++i)
		{
			if (minus && i == 0) continue;
			ans = 10 * ans + now[i] - '0';
		}
		if (minus) ans = 0 - ans;
		return ans;
	}
	inline string toString(LL now)
	{
		string ans; char a;
		LL tmp = now; bool minus = 0;
		if (tmp < 0)
		{
			minus = 1;
			tmp = 0 - tmp;
			ans.push_back('-');
		}
		while (tmp > 10)
		{
			a = (char)tmp % 10 + '0';
			ans.push_back(a);
			tmp /= 10;
		}
		return ans;
	}
public:
	static Tools & GetTools()
	{
		static Tools instance;
		return instance;
	}
};

#endif
