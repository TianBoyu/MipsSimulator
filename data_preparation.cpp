#ifndef DATA_PREPARATION_CPP
#define DATA_PREPARATION_CPP
#include "struct_declare.hpp"
#include "simulator.h"
#include "instruct.h"
#include "tools.h"

data_pre InstructADD::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if (Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[2]]] > 0 ||
		((the_line.order[3][0] == '$') &&
		(Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[3]]] > 0)))
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	++Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]];
	my_data.store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	my_data.data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$')
	{
		my_data.data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	}
	else my_data.data2 = Tools::GetTools().toInt(the_line.order[3]);
	return my_data;
}
data_pre InstructMUL::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if (Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]] > 0 ||
		(the_line.order[2][0] == '$' && Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[2]]] > 0))
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	++Simulator::GetSimulator().now_pipe.visit_reg[32];
	++Simulator::GetSimulator().now_pipe.visit_reg[33];
	my_data.data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$')
	{
		my_data.data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	}
	else my_data.data2 = Tools::GetTools().toInt(the_line.order[2]);
	return my_data;
}
data_pre InstructNEG::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if (Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[2]]] > 0)
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	++Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]];
	my_data.store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	my_data.data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	return my_data;
}
data_pre InstructLI::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	++Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]];
	my_data.store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	my_data.data1 = Tools::GetTools().toInt(the_line.order[2]);
	return my_data;
}
data_pre InstructJAL::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if (the_line.order[1][0] == '$' &&
		Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]] > 0)
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	if (the_line.order[1][0] == '$')
	{
		my_data.address = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	}
	else my_data.address = Simulator::GetSimulator().label_map[the_line.order[1]];
	return my_data;
}
data_pre InstructBEQ::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	my_data.address = Simulator::GetSimulator().label_map[the_line.order[3]];
	if (Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]] > 0
		|| (the_line.order[2][0] == '$' && Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[2]]] > 0))
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	my_data.data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$')
	{
		my_data.data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	}
	else my_data.data2 = Tools::GetTools().toInt(the_line.order[2]);
	return my_data;
}
data_pre InstructBEQZ::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if (Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]] > 0)
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	my_data.address = Simulator::GetSimulator().label_map[the_line.order[2]];
	my_data.data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	return my_data;
}
data_pre InstructLA::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if ((the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		&& Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[3]]] > 0)
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	my_data.store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	++Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]];
	return my_data;
}
data_pre InstructSB::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if (Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]] > 0)
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	my_data.data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	return my_data;
}
data_pre InstructMFHI::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	if ((the_line.option == "mflo" && Simulator::GetSimulator().now_pipe.visit_reg[32] > 0)
		|| (the_line.option == "mfhi" && Simulator::GetSimulator().now_pipe.visit_reg[33] > 0))
	{
		Simulator::GetSimulator().now_pipe.data_hazard = 1; return my_data;
	}
	my_data.store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	++Simulator::GetSimulator().now_pipe.visit_reg[Simulator::GetSimulator().register_number_map[the_line.order[1]]];
	if (the_line.option == "mflo")
	{
		my_data.data1 = Simulator::GetSimulator().lo.data;
	}
	else
	{
		my_data.data2 = Simulator::GetSimulator().hi.data;
	}
	return my_data;
}
data_pre InstructNOP::DataPreparetion(line the_line)
{
	data_pre my_data(the_line);
	my_data.data1 = Simulator::GetSimulator().v0.data;
	if (the_line.option == "syscall")
	{
		if (Simulator::GetSimulator().now_pipe.visit_reg[2] > 0)
		{
			Simulator::GetSimulator().now_pipe.data_hazard = 1;
			return my_data;
		}
		if ((my_data.data1 == 1 || my_data.data1 == 4 || my_data.data1 == 8 || my_data.data1 == 9) && (Simulator::GetSimulator().now_pipe.visit_reg[4] > 0))
		{
			Simulator::GetSimulator().now_pipe.data_hazard = 1;
			return my_data;
		}
		if (my_data.data1 == 10 || my_data.data1 == 17)
			Simulator::GetSimulator().now_pipe.fet_enable = 0;
		if (my_data.data1 == 5 || my_data.data1 == 9)
			++Simulator::GetSimulator().now_pipe.visit_reg[2];
	}
	return my_data;
}



#endif