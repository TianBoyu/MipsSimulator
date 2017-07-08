#include<iostream>
#include"handle.h"
#include"read.h"
#include"manage.h"
#include <cstdio>
using namespace std;


int main(int argc, char * argv[])
{
	//freopen("string_test-huyuncong.in", "r", stdin);
	Read a;
	Manage b;
	Handle c;
	a.ReadText(argv[1]);
	b.ManageText();
	c.HandleAll();
	return 0;
}
