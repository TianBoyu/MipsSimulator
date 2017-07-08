#include<iostream>
#include"handle.h"
#include"read.h"
#include"manage.h"
#include <cstdio>
using namespace std;

int main()
{
	freopen("builtin-5140519064-youyurong.in", "r", stdin);
	Read a;
	Manage b;
	Handle c;
	a.ReadText();
	b.ManageText();
	c.HandleAll();
	return 0;
}
