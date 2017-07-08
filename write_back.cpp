#ifndef WRITE_BACK_CPP
#define WRITE_BACK_CPP
#include "struct_declare.hpp"
#include "simulator.h"
#include "instruct.h"

void InstructADD::WriteBack(memory_acc my_mem)
{
	my_mem.store_register->data = my_mem.ans1;
	--Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[my_mem.the_line.order[1]]];
	return;
}
void InstructMUL::WriteBack(memory_acc my_mem)
{
	Simulator::GetSimulator().lo.data = my_mem.ans1;
	Simulator::GetSimulator().hi.data = my_mem.ans2;
	--Simulator::GetSimulator().now_pipe.visit_reg[32];
	--Simulator::GetSimulator().now_pipe.visit_reg[33];
	return;
}
void InstructNEG::WriteBack(memory_acc my_mem)
{
	my_mem.store_register->data = my_mem.ans1;
	--Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[my_mem.the_line.order[1]]];
	return;
}
void InstructLI::WriteBack(memory_acc my_mem)
{
	my_mem.store_register->data = my_mem.ans1;
	--Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[my_mem.the_line.order[1]]];
	return;
}
void InstructJAL::WriteBack(memory_acc my_mem)
{
	if (my_mem.change_ra)
		Simulator::GetSimulator().ra.data = Simulator::GetSimulator().PC.data + 1;
	if (my_mem.jump)
		Simulator::GetSimulator().PC.data = my_mem.address;
	else ++Simulator::GetSimulator().PC.data;
	if (Simulator::GetSimulator().now_pipe.control_hazard)
	{
		Simulator::GetSimulator().now_pipe.control_hazard = 0;
		Simulator::GetSimulator().now_pipe.fet_enable = 1;
	}
	return;
}
void InstructBEQ::WriteBack(memory_acc my_mem)
{
	if (my_mem.jump)
		Simulator::GetSimulator().PC.data = my_mem.address;
	else ++Simulator::GetSimulator().PC.data;
	if (Simulator::GetSimulator().now_pipe.control_hazard)
	{
		Simulator::GetSimulator().now_pipe.control_hazard = 0;
		Simulator::GetSimulator().now_pipe.fet_enable = 1;
	}
	return;
}
void InstructBEQZ::WriteBack(memory_acc my_mem)
{
	if (my_mem.jump)
		Simulator::GetSimulator().PC.data = my_mem.address;
	else ++Simulator::GetSimulator().PC.data;
	if (Simulator::GetSimulator().now_pipe.control_hazard)
	{
		Simulator::GetSimulator().now_pipe.control_hazard = 0;
		Simulator::GetSimulator().now_pipe.fet_enable = 1;
	}
	return;
}
void InstructLA::WriteBack(memory_acc my_mem)
{
	my_mem.store_register->data = my_mem.ans1;
    --Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[my_mem.the_line.order[1]]];
	return;
}
void InstructSB::WriteBack(memory_acc my_mem)
{
	return;
}
void InstructMFHI::WriteBack(memory_acc my_mem)
{
	my_mem.store_register->data = my_mem.ans1;
	--Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[my_mem.the_line.order[1]]];
	return;
}
void InstructNOP::WriteBack(memory_acc my_mem)
{
	if (Simulator::GetSimulator().status.end_run == 1)
		Simulator::GetSimulator().status.begin_run = 0;
    if (my_mem.the_line.option == "syscall" && (my_mem.ans2 == -233 || my_mem.ans2 == -234))
	{
		Simulator::GetSimulator().v0.data = my_mem.ans1;
		--Simulator::GetSimulator().now_pipe.visit_reg[2];
	}
	return;
}

#endif
