#ifndef HANDLE_CPP
#define HANDLE_CPP
#include "handle.h"
#include "instruct.h"
#include "assembly.h"
#include "simulator.h"
#include "struct_declare.hpp"
#include <map>
#include <string>
#include <deque>
#include <iostream>
#include <fstream>
using namespace std;

void Handle::PreHandleLine(line & the_line, int line_num)
{
	Assembly * ass; 
	if (the_line.mykind == assembly)
	{
		ass = assembly_map[the_line.order[0]];
		ass->Configure(the_line);
	}
	else if (the_line.mykind == label)
	{
		if (the_line.order[0] == "main") 
			Simulator::GetSimulator().PC.data = line_num + 1;
		for (int i = 0; the_line.order[i] != "EndOfLine"; ++i)
			Simulator::GetSimulator().label_storage_map.insert(pair<string, int>(the_line.order[i], Simulator::GetSimulator().storage_pos.data));
	}
	else if (the_line.mykind == instruct)
	{
		the_line.option = the_line.order[0];
		if (the_line.option == "mul" || the_line.option == "mulu" || the_line.option == "div" || the_line.option == "divu")
		{
			if (the_line.order[3] == "")
			{
				the_line.order[0].push_back('d');
				the_line.option.push_back('d');
			}
		}
	}
	else { throw; }
}
void Handle::PreHandleText()
{
	for (int i = 0; i < Simulator::GetSimulator().paper.size(); ++i)
	{
		PreHandleLine(Simulator::GetSimulator().paper[i], i);
	}
}
void Handle::HandleText()
{
	Instruct * ins;
	Simulator::GetSimulator().status.begin_run = 1;
	while (Simulator::GetSimulator().status.begin_run)
	{
		int a = Simulator::GetSimulator().PC.data;
		line the_line = Simulator::GetSimulator().paper[Simulator::GetSimulator().PC.data];
		//Handle::Debug(the_line);
		if (the_line.mykind != instruct)
		{
			++Simulator::GetSimulator().PC.data; continue;
		}
		if (Simulator::GetSimulator().PC.data == 362)
			int aaa = 1;
		ins = instruct_map[the_line.option];
		ins->Execution(the_line);
		if (a == Simulator::GetSimulator().PC.data) 
			++Simulator::GetSimulator().PC.data;
	}
}
void Handle::HandleAll()
{
	Handle::PreHandleText();
	Handle::HandleText();
	//Handle::PipeHandleText();
	//Handle::PipeLineHandleText();
}
void Handle::Debug(line the_line)
{
	ofstream output("file1.out", ios::app);
	int bb = *((int*)(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().sp.data));
	int cc = *((int*)(Simulator::GetSimulator().data_zone + 10000000));
	output << Simulator::GetSimulator().PC.data << ' ' << the_line.order[0] << ' ' << the_line.order[1] << ' ' << the_line.order[2] << ' ' << the_line.order[3] << endl;
	output << "storage " << Simulator::GetSimulator().storage_pos.data << " sp value " << bb << " 10000 value " << cc << endl;
	for (int i = 0; i < 32; ++i)
	{
		output << i << '\t';
	}
	output << endl;
	output << Simulator::GetSimulator().zero.data << '\t'
		<< Simulator::GetSimulator().at.data << '\t'
		<< Simulator::GetSimulator().v0.data << '\t'
		<< Simulator::GetSimulator().v1.data << '\t'
		<< Simulator::GetSimulator().a0.data << '\t'
		<< Simulator::GetSimulator().a1.data << '\t'
		<< Simulator::GetSimulator().a2.data << '\t'
		<< Simulator::GetSimulator().a3.data << '\t'
		<< Simulator::GetSimulator().t0.data << '\t'
		<< Simulator::GetSimulator().t1.data << '\t'
		<< Simulator::GetSimulator().t2.data << '\t'
		<< Simulator::GetSimulator().t3.data << '\t'
		<< Simulator::GetSimulator().t4.data << '\t'
		<< Simulator::GetSimulator().t5.data << '\t'
		<< Simulator::GetSimulator().t6.data << '\t'
		<< Simulator::GetSimulator().t7.data << '\t'
		<< Simulator::GetSimulator().s0.data << '\t'
		<< Simulator::GetSimulator().s1.data << '\t'
		<< Simulator::GetSimulator().s2.data << '\t'
		<< Simulator::GetSimulator().s3.data << '\t'
		<< Simulator::GetSimulator().s4.data << '\t'
		<< Simulator::GetSimulator().s5.data << '\t'
		<< Simulator::GetSimulator().s6.data << '\t'
		<< Simulator::GetSimulator().s7.data << '\t'
		<< Simulator::GetSimulator().t8.data << '\t'
		<< Simulator::GetSimulator().t9.data << '\t'
		<< Simulator::GetSimulator().k0.data << '\t'
		<< Simulator::GetSimulator().k1.data << '\t'
		<< Simulator::GetSimulator().gp.data << '\t'
		<< Simulator::GetSimulator().sp.data << '\t'
		<< Simulator::GetSimulator().s8.data << '\t'
		<< Simulator::GetSimulator().ra.data << '\t';
		//<< Simulator::GetSimulator().lo.data << '\t'
		//<< Simulator::GetSimulator().hi.data << '\t';
		output << endl;
}
void Handle::PipeHandleText()
{
	Instruct * ins;
	Simulator::GetSimulator().status.begin_run = 1;
	line the_line; data_pre my_data(the_line); answer_get my_ans; memory_acc my_mem;
	while (Simulator::GetSimulator().status.begin_run)
	{
		int a = Simulator::GetSimulator().PC.data;
		the_line = Handle::InstructionFetch();
		Handle::Debug(the_line);
		if (the_line.mykind != instruct)
		{
			++Simulator::GetSimulator().PC.data; continue;
		}
		ins = instruct_map[the_line.option];
		my_data = ins->DataPreparetion(the_line);
		my_ans = ins->Execution(my_data);
		my_mem = ins->MemoryAccess(my_ans);
		ins->WriteBack(my_mem);
		if (a == Simulator::GetSimulator().PC.data)
			++Simulator::GetSimulator().PC.data;
	}
}

void Handle::PipeLineHandleText()
{
	Instruct * ins;
	Simulator::GetSimulator().status.begin_run = 1;
	line the_line; data_pre my_data(the_line); answer_get my_ans; memory_acc my_mem;
	data_hazard haz;
	while (Simulator::GetSimulator().status.begin_run)
	{
		if (Simulator::GetSimulator().now_pipe.wri_enable == 1 && haz.MA == 1)
		{
			haz.MA = 0;
			ins = instruct_map[my_mem.the_line.option];
			//Handle::Debug(my_mem.the_line);
			ins->WriteBack(my_mem);
			if (Handle::DataHazard() && Handle::NoDataHazard())
			{
				Simulator::GetSimulator().now_pipe.data_hazard = 0;
				Simulator::GetSimulator().now_pipe.fet_enable = 1;
				Simulator::GetSimulator().now_pipe.pre_enable = 1;
				haz.IF = 1;
			}
		}
		if (Simulator::GetSimulator().now_pipe.mem_enable == 1 && haz.EX == 1)
		{
			haz.EX = 0;
			ins = instruct_map[my_ans.the_line.option];
			my_mem = ins->MemoryAccess(my_ans);
			haz.MA = 1;
		}
		if (Simulator::GetSimulator().now_pipe.ans_enable == 1 && haz.ID == 1)
		{
			haz.ID = 0;
			ins = instruct_map[my_data.the_line.option];
			my_ans = ins->Execution(my_data);
			haz.EX = 1;
		}
		if (Simulator::GetSimulator().now_pipe.pre_enable == 1 && haz.IF == 1)
		{
			haz.IF = 0;
			ins = instruct_map[the_line.option]; 
			if (!Handle::ControllHazard() || (haz.ID == 0 && haz.EX == 0 && haz.MA == 0))
			{
				my_data = ins->DataPreparetion(the_line);
				if (Handle::DataHazard())
				{
					haz.ID = 0;
					StopPipeline_Data();
				}
				else haz.ID = 1;
			}
			else 
				haz.ID = 0;
		}
		if (Handle::ControllHazard() && (haz.ID == 0 && haz.EX == 0 && haz.MA == 0))
			Simulator::GetSimulator().now_pipe.fet_enable = 1;
		if (Simulator::GetSimulator().now_pipe.fet_enable == 1)
		{
			the_line = Handle::InstructionFetch();
			//if (the_line.option == "mflo")
				//cout << 1;
			if (Handle::ControllHazard())
				StopPipeline_Ctrl();

			haz.IF = 1;
		}
	}
}

line Handle::InstructionFetch()
{
	line tmp = Simulator::GetSimulator().paper[Simulator::GetSimulator().PC.data];
	string opt = tmp.option;
	if (tmp.mykind != instruct)
		Simulator::GetSimulator().now_pipe.pre_enable = 0;
	else Simulator::GetSimulator().now_pipe.pre_enable = 1;
	if (opt[0] == 'b' || opt[0] == 'j')
	{
		Simulator::GetSimulator().now_pipe.control_hazard = 1;
	}
	else
	{
		++Simulator::GetSimulator().PC.data;
	}
	return tmp;
}
bool Handle::DataHazard()
{
	return Simulator::GetSimulator().now_pipe.data_hazard;
}
bool Handle::NoDataHazard()
{
	for (int i = 0; i < 34; ++i)
	{
		if (Simulator::GetSimulator().now_pipe.visit_reg[i] != 0)
			return 0;
	}
	return 1;
}
bool Handle::ControllHazard()
{
	return Simulator::GetSimulator().now_pipe.control_hazard;
}
void Handle::StopPipeline_Data()
{
	Simulator::GetSimulator().now_pipe.fet_enable = 0;
	Simulator::GetSimulator().now_pipe.pre_enable = 0;
	return;
}
void Handle::StopPipeline_Ctrl()
{
	Simulator::GetSimulator().now_pipe.fet_enable = 0;
	return;
}
void Handle::StartPipeline_Data()
{
	Simulator::GetSimulator().now_pipe.fet_enable = 1; 
	Simulator::GetSimulator().now_pipe.pre_enable = 1;
	return;
}
void Handle::StartPipeline_Ctrl()
{

}
void Handle::DebugModify(line the_line)
{
	ofstream output("file1.out", ios::app);
	output << Simulator::GetSimulator().PC.data << ' ' << the_line.order[0] << ' ' << the_line.order[1] << ' ' << the_line.order[2] << ' ' << the_line.order[3] << endl;
	for (int i = 0; i < 34; ++i)
	{
		if (Simulator::GetSimulator().now_pipe.visit_reg[i] != 0)
			output << i << ' ' << Simulator::GetSimulator().now_pipe.visit_reg[i] << endl;
	}
}


#endif // !HANDLE_CPP
