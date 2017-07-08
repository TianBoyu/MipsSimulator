#ifndef INSTRUCT_HPP
#define INSTRUCT_HPP
#include "simulator.h"
#include "instruct.h"
#include "tools.h"
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;
void add_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') 
		data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 + data2;
	store_register->data = ans;
}
void addu_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 + data2;
	store_register->data = ans;
}
void addiu_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 + data2;
	store_register->data = ans;
}
void sub_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 - data2;
	store_register->data = ans;
}
void subu_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 - data2;
	store_register->data = ans;
}
void mul_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 * data2;
	store_register->data = ans;
}
void mulu_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = (unsigned)Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 * data2;
	store_register->data = ans;
}
void muld_::Execution(line the_line)
{
	LL ans, data1, data2;
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	ans = data1 * data2;
	int a = ans, b = ans >> 32;
	Simulator::GetSimulator().lo.data = a; Simulator::GetSimulator().hi.data = b;
}
void mulud_::Execution(line the_line)
{
	LL ans, data1, data2;
	data1 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = (unsigned)Tools::GetTools().toInt(the_line.order[2]);
	ans = data1 * data2;
	int a = ans, b = ans >> 32;
	Simulator::GetSimulator().lo.data = a; Simulator::GetSimulator().hi.data = b;
}
void div_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 / data2;
	store_register->data = ans;
}
void divu_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = (unsigned)Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 / data2;
	store_register->data = ans;
}
void divd_::Execution(line the_line)
{
	LL a, b, data1, data2;
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') 
		data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	a = data1 / data2; b = data1 % data2;
	Simulator::GetSimulator().lo.data = a; Simulator::GetSimulator().hi.data = b;
}
void divud_::Execution(line the_line)
{
	LL a, b, data1, data2;
	data1 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = (unsigned)Tools::GetTools().toInt(the_line.order[2]);
	a = data1 / data2; b = data1 % data2;
	Simulator::GetSimulator().lo.data = a; Simulator::GetSimulator().hi.data = b;
}
void xor_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 ^ data2;
	store_register->data = ans;
}
void xoru_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = (unsigned)Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 ^ data2;
	store_register->data = ans;
}
void neg_::Execution(line the_line)
{
	LL ans;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	ans = 0 - Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	store_register->data = ans;
}
void negu_::Execution(line the_line)
{
	LL ans;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	ans = 0 - Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	store_register->data = ans;
}
void rem_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 % data2;
	store_register->data = ans;
}
void remu_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = (unsigned)Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = (unsigned)Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 % data2;
	store_register->data = ans;
}
void li_::Execution(line the_line)
{
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	store_register->data = Tools::GetTools().toInt(the_line.order[2]);
}
void seq_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 == data2;
	store_register->data = ans;
}
void sge_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 >= data2;
	store_register->data = ans;
}
void sgt_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') 
		data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 > data2;
	store_register->data = ans;
}
void sle_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 <= data2;
	store_register->data = ans;
}
void slt_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 < data2;
	store_register->data = ans;
}
void sne_::Execution(line the_line)
{
	LL ans, data1, data2;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	if (the_line.order[3][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[3]);
	ans = data1 != data2;
	store_register->data = ans;
}
void b_::Execution(line the_line)
{
	int address = Simulator::GetSimulator().label_map[the_line.order[1]];
	Simulator::GetSimulator().PC.data = address;
}
void beq_::Execution(line the_line)
{
	LL data1, data2;
	int address = Simulator::GetSimulator().label_map[the_line.order[3]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	if (data1 == data2) Simulator::GetSimulator().PC.data = address;
}
void bne_::Execution(line the_line)
{
	LL data1, data2;
	int address = Simulator::GetSimulator().label_map[the_line.order[3]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') 
		data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	if (data1 != data2) Simulator::GetSimulator().PC.data = address;
}
void bge_::Execution(line the_line)
{
	LL data1, data2;
	int address = Simulator::GetSimulator().label_map[the_line.order[3]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	if (data1 >= data2) Simulator::GetSimulator().PC.data = address;
}
void ble_::Execution(line the_line)
{
	LL data1, data2;
	int address = Simulator::GetSimulator().label_map[the_line.order[3]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	if (data1 <= data2) Simulator::GetSimulator().PC.data = address;
}
void bgt_::Execution(line the_line)
{
	LL data1, data2;
	int address = Simulator::GetSimulator().label_map[the_line.order[3]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	if (data1 > data2) Simulator::GetSimulator().PC.data = address;
}
void blt_::Execution(line the_line)
{
	LL data1, data2;
	int address = Simulator::GetSimulator().label_map[the_line.order[3]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (the_line.order[2][0] == '$') data2 = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	else data2 = Tools::GetTools().toInt(the_line.order[2]);
	if (data1 < data2) Simulator::GetSimulator().PC.data = address;
}
void beqz_::Execution(line the_line)
{
	LL data1;
	int address = Simulator::GetSimulator().label_map[the_line.order[2]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (data1 == 0) Simulator::GetSimulator().PC.data = address;
}
void bnez_::Execution(line the_line)
{
	LL data1;
	int address = Simulator::GetSimulator().label_map[the_line.order[2]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (data1 != 0) Simulator::GetSimulator().PC.data = address;
}
void blez_::Execution(line the_line)
{
	LL data1;
	int address = Simulator::GetSimulator().label_map[the_line.order[2]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (data1 <= 0) Simulator::GetSimulator().PC.data = address;
}
void bgez_::Execution(line the_line)
{
	LL data1;
	int address = Simulator::GetSimulator().label_map[the_line.order[2]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (data1 >= 0) Simulator::GetSimulator().PC.data = address;
}
void bgtz_::Execution(line the_line)
{
	LL data1;
	int address = Simulator::GetSimulator().label_map[the_line.order[2]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (data1 > 0) Simulator::GetSimulator().PC.data = address;
}
void bltz_::Execution(line the_line)
{
	LL data1;
	int address = Simulator::GetSimulator().label_map[the_line.order[2]];
	data1 = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	if (data1 < 0) Simulator::GetSimulator().PC.data = address;
}
void j_::Execution(line the_line)
{
	int address = Simulator::GetSimulator().label_map[the_line.order[1]];
	Simulator::GetSimulator().PC.data = address;
}
void jr_::Execution(line the_line)
{
	int address = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	Simulator::GetSimulator().PC.data = address;
}
void jal_::Execution(line the_line)
{
	int address = Simulator::GetSimulator().label_map[the_line.order[1]];
	Simulator::GetSimulator().ra.data = Simulator::GetSimulator().PC.data + 1;
	Simulator::GetSimulator().PC.data = address;
}
void jalr_::Execution(line the_line)
{
	int address = Simulator::GetSimulator().register_map[the_line.order[1]]->data;
	Simulator::GetSimulator().ra.data = Simulator::GetSimulator().PC.data + 1;
	Simulator::GetSimulator().PC.data = address;
}
void la_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	store_register->data = address;
}
void lb_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	store_register->data = *((char*)(Simulator::GetSimulator().data_zone + address));
}
void lh_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	store_register->data = *((short*)(Simulator::GetSimulator().data_zone + address));
}
void lw_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	store_register->data = *((int*)(Simulator::GetSimulator().data_zone + address));
}
void sb_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	new(Simulator::GetSimulator().data_zone + address) char(store_register->data);
}
void sh_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	new(Simulator::GetSimulator().data_zone + address) short(store_register->data);
}
void sw_::Execution(line the_line)
{
	int address;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	if (the_line.order[2][0] == '-' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
		address = Tools::GetTools().toInt(the_line.order[2]) + Simulator::GetSimulator().register_map[the_line.order[3]]->data;
	else address = Simulator::GetSimulator().label_storage_map[the_line.order[2]];
	new(Simulator::GetSimulator().data_zone + address) int(store_register->data);
}
void move_::Execution(line the_line)
{
	LL ans;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	ans = Simulator::GetSimulator().register_map[the_line.order[2]]->data;
	store_register->data = ans;
}
void mfhi_::Execution(line the_line)
{
	LL ans;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	store_register->data = Simulator::GetSimulator().hi.data;
}
void mflo_::Execution(line the_line)
{
	LL ans;
	my_register * store_register = Simulator::GetSimulator().register_map[the_line.order[1]];
	store_register->data = Simulator::GetSimulator().lo.data;
}
void nop_::Execution(line the_line)
{
	return;
}
void syscall_::Execution(line the_line)
{
	ifstream input;
	switch (Simulator::GetSimulator().v0.data)
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
		Simulator::GetSimulator().v0.data = number;
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
		Simulator::GetSimulator().v0.data = Simulator::GetSimulator().storage_pos.data;
		Simulator::GetSimulator().storage_pos.data += space; break;
	}
	case 10: Simulator::GetSimulator().status.begin_run = 0; break;
	case 17: Simulator::GetSimulator().status.begin_run = 0; break;
	}
}

#endif // !INSTRUCT_HPP
