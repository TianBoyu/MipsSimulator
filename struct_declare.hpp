#ifndef STRUCT_DECLARE_HPP
#define STRUCT_DECLARE_HPP
#include <string>
#include <cstring>
#define LL long long
using namespace std;
enum kind { label, assembly, instruct, neverdefine };
struct my_register
{
	LL data;
	my_register() : data(0) {}
	my_register(LL a) : data(a) {}
};
struct program_status
{
	bool begin_run;
	bool end_run_;
	bool end_run;
	int storage_pos;
	program_status() : begin_run(0), end_run_(0), end_run(0), storage_pos(0) {}
};
struct pipeline_status
{
	bool fet_enable;
	bool pre_enable;
	bool ans_enable;
	bool mem_enable;
	bool wri_enable;
	int visit_reg[34];
	bool data_hazard;
	bool control_hazard;
	pipeline_status() : fet_enable(1), pre_enable(1), ans_enable(1), mem_enable(1), wri_enable(1), data_hazard(0), control_hazard(0)
	{
		memset(visit_reg, 0, 34);
	} 
};
struct data_hazard
{
	bool IF;
	bool ID;
	bool EX;
	bool MA;
	bool WB;
	data_hazard() : IF(0), ID(0), EX(0), MA(0), WB(0) {}
};

struct line
{
	kind mykind;
	string option;
	string order[100];
	line() : mykind(neverdefine) {}
};

struct data_pre
{
	line the_line;
	my_register * store_register;
	LL data1;
	LL data2;
	int address;
	data_pre(line tmp) : the_line(tmp){}
};
struct answer_get
{
	line the_line;
	my_register * store_register;
	LL ans1;
	LL ans2;
	int address;
	bool jump;
	bool change_ra;
	answer_get() : jump(0) {}
	answer_get(data_pre data) : the_line(data.the_line), store_register(data.store_register), address(data.address), jump(0), change_ra(0) {}
};
struct memory_acc
{
	line the_line;
	my_register * store_register;
	LL ans1;
	LL ans2;
	int address;
	bool jump;
	bool change_ra;
	memory_acc() {}
	memory_acc(answer_get ans) : the_line(ans.the_line), store_register(ans.store_register), ans1(ans.ans1), ans2(ans.ans2), address(ans.address), jump(ans.jump), change_ra(ans.change_ra) {}
};
#endif
