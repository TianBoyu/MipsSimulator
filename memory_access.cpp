#ifndef MEMORY_ACCESS_CPP
#define MEMORY_ACCESS_CPP
#include "struct_declare.hpp"
#include "simulator.h"
#include "instruct.h"
#include "tools.h"

memory_acc InstructADD::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructMUL::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructNEG::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructLI::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructJAL::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructBEQ::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructBEQZ::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructLA::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	my_mem.ans1 = my_mem.address;
	return my_mem;
}
memory_acc InstructSB::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	return my_mem;
}
memory_acc InstructMFHI::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	return my_mem;
}
memory_acc InstructNOP::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.option == "syscall" && Simulator::GetSimulator().status.end_run_ == 1)
		Simulator::GetSimulator().status.end_run = 1;
	return my_mem;
}

memory_acc lb_::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	my_mem.ans1 = *((char*)(Simulator::GetSimulator().data_zone + my_mem.address));
	return my_mem;
}
memory_acc lh_::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	my_mem.ans1 = *((short*)(Simulator::GetSimulator().data_zone + my_mem.address));
	return my_mem;
}
memory_acc lw_::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	my_mem.ans1 = *((int*)(Simulator::GetSimulator().data_zone + my_mem.address));
	return my_mem;
}
memory_acc sb_::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	new(Simulator::GetSimulator().data_zone + my_mem.address) char(my_mem.ans1);
	return my_mem;
}
memory_acc sh_::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	new(Simulator::GetSimulator().data_zone + my_mem.address) short(my_mem.ans1);
	return my_mem;
}
memory_acc sw_::MemoryAccess(answer_get my_ans)
{
	memory_acc my_mem(my_ans);
	if (my_mem.the_line.order[2][0] == '-' || (my_mem.the_line.order[2][0] >= '0' && my_mem.the_line.order[2][0] <= '9'))
		my_mem.address = Tools::GetTools().toInt(my_mem.the_line.order[2]) + Simulator::GetSimulator().register_map[my_mem.the_line.order[3]]->data;
	else my_mem.address = Simulator::GetSimulator().label_storage_map[my_mem.the_line.order[2]];
	new(Simulator::GetSimulator().data_zone + my_mem.address) int(my_mem.ans1);
	return my_mem;
}

#endif