#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <map>
#include <deque>
#include "struct_declare.hpp"
#include <cstring>
using namespace std;
#define LL long long
const int MaxSize = 10500000;

class Simulator
{
public:
	my_register zero; my_register at;
	my_register v0; my_register v1;
	my_register a0; my_register a1; my_register a2; my_register a3;
	my_register t0; my_register t1; my_register t2; my_register t3; my_register t4; my_register t5; my_register t6; my_register t7;
	my_register s0; my_register s1; my_register s2; my_register s3; my_register s4; my_register s5; my_register s6; my_register s7;
	my_register t8; my_register t9;
	my_register k0; my_register k1;
	my_register gp; my_register sp; my_register s8; my_register ra;
	my_register hi; my_register lo;

	my_register PC;
	my_register storage_pos;
public:
	char * data_zone;
	deque<string> text;
	deque<line> paper;
	program_status status;
	pipeline_status now_pipe;
	map<string, my_register*> register_map;
	map<string, int> register_number_map;
	map<string, int> label_map;
	map<string, int> label_storage_map;
private:
	Simulator() 
	{
		data_zone = (char*)operator new[](MaxSize);
		memset(data_zone, '\0', MaxSize);
		my_register* body[33] = { 
			&zero, &at,
			&v0, &v1,
			&a0, &a1, &a2, &a3,
			&t0, &t1, &t2, &t3, &t4, &t5, &t6, &t7,
			&s0, &s1, &s2, &s3, &s4, &s5, &s6, &s7,
			&t8, &t9, &k0, &k1,
			&gp, &sp, &s8, &ra };
		string name[33] = { "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
			"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
			"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
			"$t8", "$t9", "$k0", "$k1",
			"$gp", "$sp", "$fp", "$ra" };
		string name_number[33] = { "$0", "$1", "$2", "$3", "$4", "$5", "$6", "$7", "$8",
			"$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16",
			"$17", "$18", "$19", "$20", "$21", "$22", "$23", "$24",
			"$25", "$26", "$27", "$28", "$29", "$30", "$31" };
		for (int i = 0; i < 32; ++i)
		{
			register_map.insert(pair<string, my_register*>(name[i], body[i]));
			register_map.insert(pair<string, my_register*>(name_number[i], body[i]));
			register_number_map.insert(pair<string, int>(name[i], i));
			register_number_map.insert(pair<string, int>(name_number[i], i));
		}
		register_map.insert(pair<string, my_register*>("$s8", &s8));
		register_number_map.insert(pair<string, int>("$s8", 30));
		sp.data = 10000000;
	}
	Simulator(const Simulator & x) = delete;
	Simulator(Simulator && x) = delete;
public:
	static Simulator & GetSimulator()
	{
		static Simulator instance;
		return instance;
	}

};




#endif
