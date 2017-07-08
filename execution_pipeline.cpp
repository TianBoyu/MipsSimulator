#ifndef EXECUTION_PIPELINE_CPP
#define EXECUTION_PIPELINE_CPP
#include "struct_declare.hpp"
#include "simulator.h"
#include "instruct.h"
#include "tools.h"
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;
answer_get add_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 + my_data.data2;
	return my_ans;
}
answer_get addu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 + my_data.data2;
	return my_ans;
}
answer_get addiu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 + my_data.data2;
	return my_ans;
}
answer_get sub_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 - my_data.data2;
	return my_ans;
}
answer_get subu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 - my_data.data2;
	return my_ans;
}
answer_get mul_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 * my_data.data2;
	return my_ans;
}
answer_get mulu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (unsigned)my_data.data1 * (unsigned)my_data.data2;
	return my_ans;
}
answer_get div_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 / my_data.data2;
	return my_ans;
}
answer_get divu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (unsigned)my_data.data1 / (unsigned)my_data.data2;
	return my_ans;
}
answer_get muld_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	LL ans = my_data.data1 * my_data.data2;
	int a = ans, b = ans >> 32;
	my_ans.ans1 = a; my_ans.ans2 = b;
	return my_ans;
}
answer_get mulud_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	LL ans = (unsigned)my_data.data1 * (unsigned)my_data.data2;
	int a = ans, b = ans >> 32;
	my_ans.ans1 = a; my_ans.ans2 = b;
	return my_ans;
}
answer_get divd_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 / my_data.data2;
	my_ans.ans2 = my_data.data1 % my_data.data2;
	return my_ans;
}
answer_get divud_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (unsigned)my_data.data1 / (unsigned)my_data.data2;
	my_ans.ans2 = (unsigned)my_data.data1 % (unsigned)my_data.data2;
	return my_ans;
}
answer_get xor_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 ^ my_data.data2;
	return my_ans;
}
answer_get xoru_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (unsigned)my_data.data1 ^ (unsigned)my_data.data2;
	return my_ans;
}
answer_get neg_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = 0 - my_data.data1;
	return my_ans;
}
answer_get negu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = 0 - (unsigned)my_data.data1;
	return my_ans;
}
answer_get rem_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1 % my_data.data2;
	return my_ans;
}
answer_get remu_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (unsigned)my_data.data1 % (unsigned)my_data.data2;
	return my_ans;
}
answer_get li_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1;
	return my_ans;
}
answer_get seq_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (my_data.data1 == my_data.data2);
	return my_ans;
}
answer_get sge_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (my_data.data1 >= my_data.data2);
	return my_ans;
}
answer_get sgt_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (my_data.data1 > my_data.data2);
	return my_ans;
}
answer_get sle_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (my_data.data1 <= my_data.data2);
	return my_ans;
}
answer_get slt_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (my_data.data1 < my_data.data2);
	return my_ans;
}
answer_get sne_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = (my_data.data1 != my_data.data2);
	return my_ans;
}
answer_get b_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = 1;
	return my_ans;
}
answer_get beq_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 == my_data.data2);
	return my_ans;
}
answer_get bne_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 != my_data.data2);
	return my_ans;
}
answer_get bge_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 >= my_data.data2);
	return my_ans;
}
answer_get ble_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 <= my_data.data2);
	return my_ans;
}
answer_get bgt_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 > my_data.data2);
	return my_ans;
}
answer_get blt_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 < my_data.data2);
	return my_ans;
}
answer_get beqz_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 == 0);
	return my_ans;
}
answer_get bnez_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 != 0);
	return my_ans;
}
answer_get blez_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 <= 0);
	return my_ans;
}
answer_get bgez_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 >= 0);
	return my_ans;
}
answer_get bgtz_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 > 0);
	return my_ans;
}
answer_get bltz_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = (my_data.data1 < 0);
	return my_ans;
}
answer_get j_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = 1;
	return my_ans;
}
answer_get jr_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = 1;
	return my_ans;
}
answer_get jal_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = 1; my_ans.change_ra = 1;
	return my_ans;
}
answer_get jalr_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.jump = 1; my_ans.change_ra = 1;
	return my_ans;
}
answer_get la_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	return my_ans;
}
answer_get lb_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	return my_ans;
}
answer_get lh_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	return my_ans;
}
answer_get lw_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	return my_ans;
}
answer_get sb_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1;
	return my_ans;
}
answer_get sh_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1;
	return my_ans;
}
answer_get sw_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1;
	return my_ans;
}
answer_get move_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1;
	return my_ans;
}
answer_get mfhi_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data2;
	return my_ans;
}
answer_get mflo_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	my_ans.ans1 = my_data.data1;
	return my_ans;
}
answer_get nop_::Execution(data_pre my_data)
{
	answer_get my_ans(my_data);
	return my_ans;
}
answer_get syscall_::Execution(data_pre my_data)
{
	ifstream input;
	answer_get my_ans(my_data);
	switch (my_data.data1)
	{
	case 1:
	{
		cout << Simulator::GetSimulator().a0.data; break;
	}
	case 4:
	{
		for (int i = Simulator::GetSimulator().a0.data; Simulator::GetSimulator().data_zone[i] != '\0'; ++i)
		{
			char aa = Simulator::GetSimulator().data_zone[i];
			cout << aa;
		}
		break;
	}
	case 5:
	{
		int number;
		cin >> number;
		my_ans.ans1 = number;
		my_ans.ans2 = -233;
		break;
	}
	case 8:
	{
		string tmp;
		cin >> tmp;
		for (int i = 0; i < tmp.length(); ++i)
		{
			new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().a0.data + i) char(tmp[i]);
		}
		break;
	}
	case 9:
	{
		int space = Simulator::GetSimulator().a0.data;
		my_ans.ans1 = Simulator::GetSimulator().storage_pos.data;
		my_ans.ans2 = -233;
		Simulator::GetSimulator().storage_pos.data += space; break;
	}
	case 10: Simulator::GetSimulator().status.end_run_ = 1; break;
	case 17: Simulator::GetSimulator().status.end_run_ = 1; break;
	}
	return my_ans;
}
#endif