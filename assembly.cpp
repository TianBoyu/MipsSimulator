#ifndef ASSEMBLY_H
#define ASSEMBLY_H
#include "simulator.h"
#include "assembly.h"
#include "tools.h"

void align_::Configure(line the_line)
{
	int a = Tools::GetTools().toInt(the_line.order[1]);
	int move = 1;
	for (int i = 0; i < a; ++i)
	{
		move *= 2;
	}
	int j = 1;
	for (j = 1; move * j < Simulator::GetSimulator().storage_pos.data; ++j) {}
	Simulator::GetSimulator().storage_pos.data = move * j;
}
void ascii_::Configure(line the_line)
{
	string a = the_line.order[1];
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == '\\')
		{
			switch (a[i + 1])
			{
			case 'n': a[++i] = '\n'; break;
			case '0': a[++i] = '\0'; break;
			case 't': a[++i] = '\t'; break;
			case '"': a[++i] = '\"'; break;
			case '?': a[++i] = '\?'; break;
			}
		}
		new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().storage_pos.data++) char(a[i]);
	}
}
void asciiz_::Configure(line the_line)
{
	string a = the_line.order[1];
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == '\\')
		{
			switch (a[i + 1])
			{
			case 'n': a[++i] = '\n'; break;
			case '0': a[++i] = '\0'; break;
			case 't': a[++i] = '\t'; break;
			case '"': a[++i] = '\"'; break;
			case '?': a[++i] = '\?'; break;
			}
		}
		new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().storage_pos.data++) char(a[i]);
	}
	new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().storage_pos.data++) char('\0');
}
void byte_::Configure(line the_line)
{
	for (int i = 1; the_line.order[i] != "EndOfLine"; ++i)
	{
		if (the_line.order[i][1] == '\\')
		{
			switch (the_line.order[i][2])
			{
			case 'n': the_line.order[i][1] = '\n'; break;
			case '0': the_line.order[i][1] = '\0'; break;
			case 't': the_line.order[i][1] = '\t'; break;
			case '"': the_line.order[i][1] = '\"'; break;
			case '?': the_line.order[i][1] = '\?'; break;
			}
		}
		new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().storage_pos.data) char(the_line.order[i][1]);
		Simulator::GetSimulator().storage_pos.data++;
	}
}
void half_::Configure(line the_line)
{
	for (int i = 1; the_line.order[i] != "EndOfLine"; ++i)
	{
		new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().storage_pos.data) short(Tools::GetTools().toInt(the_line.order[i]));
		Simulator::GetSimulator().storage_pos.data += 2;
	}
}
void word_::Configure(line the_line)
{
	for (int i = 1; the_line.order[i] != "EndOfLine"; ++i)
	{
		new(Simulator::GetSimulator().data_zone + Simulator::GetSimulator().storage_pos.data) int(Tools::GetTools().toInt(the_line.order[i]));
		Simulator::GetSimulator().storage_pos.data += 4;
	}
}
void space_::Configure(line the_line)
{
	Simulator::GetSimulator().storage_pos.data += Tools::GetTools().toInt(the_line.order[1]);
}
void data_::Configure(line the_line)
{
	return;
}
void text_::Configure(line the_line)
{
	return;
}

#endif // !ASSEMBLY_H
