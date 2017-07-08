#ifndef HANDLE_HPP
#define HANDLE_HPP
#include "simulator.h"
#include "struct_declare.hpp"
#include "instruct.h"
#include "assembly.h"
#include <map>
#include <deque>
#include <string>

using namespace std;

class Handle
{
public:
	map<string, Assembly*> assembly_map;
	map<string, Instruct*> instruct_map;
	Handle()
	{
		assembly_map["align"] = new align_();
		assembly_map["ascii"] = new ascii_();
		assembly_map["asciiz"] = new asciiz_();
		assembly_map["byte"] = new byte_();
		assembly_map["half"] = new half_();
		assembly_map["word"] = new word_();
		assembly_map["space"] = new space_();
		assembly_map["data"] = new data_();
		assembly_map["text"] = new text_();

		instruct_map["add"] = new add_();
		instruct_map["addu"] = new addu_();
		instruct_map["addiu"] = new addiu_();
		instruct_map["sub"] = new sub_();
		instruct_map["subu"] = new subu_();
		instruct_map["mul"] = new mul_();
		instruct_map["mulu"] = new mulu_();
		instruct_map["muld"] = new muld_();
		instruct_map["mulud"] = new mulud_();
		instruct_map["div"] = new div_();
		instruct_map["divu"] = new divu_();
		instruct_map["divd"] = new divd_();
		instruct_map["divud"] = new divud_();
		instruct_map["xor"] = new xor_();
		instruct_map["xoru"] = new xoru_();
		instruct_map["neg"] = new neg_();
		instruct_map["negu"] = new negu_();
		instruct_map["rem"] = new rem_();
		instruct_map["remu"] = new remu_();
		instruct_map["li"] = new li_();
		instruct_map["seq"] = new seq_();
		instruct_map["sge"] = new sge_();
		instruct_map["sgt"] = new sgt_();
		instruct_map["sle"] = new sle_();
		instruct_map["slt"] = new slt_();
		instruct_map["sne"] = new sne_();
		instruct_map["b"] = new b_();
		instruct_map["beq"] = new beq_();
		instruct_map["bne"] = new bne_();
		instruct_map["bge"] = new bge_();
		instruct_map["ble"] = new ble_();
		instruct_map["bgt"] = new bgt_();
		instruct_map["blt"] = new blt_();
		instruct_map["beqz"] = new beqz_();
		instruct_map["bnez"] = new bnez_();
		instruct_map["blez"] = new blez_();
		instruct_map["bgez"] = new bgez_();
		instruct_map["bgtz"] = new bgtz_();
		instruct_map["bltz"] = new bltz_();
		instruct_map["j"] = new j_();
		instruct_map["jr"] = new jr_();
		instruct_map["jal"] = new jal_();
		instruct_map["jalr"] = new jalr_();
		instruct_map["la"] = new la_();
		instruct_map["lb"] = new lb_();
		instruct_map["lh"] = new lh_();
		instruct_map["lw"] = new lw_();
		instruct_map["sb"] = new sb_();
		instruct_map["sh"] = new sh_();
		instruct_map["sw"] = new sw_();
		instruct_map["move"] = new move_();
		instruct_map["mfhi"] = new mfhi_();
		instruct_map["mflo"] = new mflo_();
		instruct_map["nop"] = new nop_();
		instruct_map["syscall"] = new syscall_();
	}
public:
	void PreHandleText();
	void PreHandleLine(line & the_line, int line_num);
	void HandleAll();
	void Debug(line the_line);
	void DebugModify(line the_line);

	line InstructionFetch();
	void HandleText();
	void PipeHandleText();
	void PipeLineHandleText();

	bool DataHazard();
	bool ControllHazard();
	bool NoDataHazard();
	void StopPipeline_Data();
	void StopPipeline_Ctrl();
	void StartPipeline_Data();
	void StartPipeline_Ctrl();
};


#endif
