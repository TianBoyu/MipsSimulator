#ifndef INSTRUCT_H
#define INSTRUCT_H
#include "struct_declare.hpp"
class Instruct
{
public:
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line) { throw; }
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans) { throw; }
	virtual void WriteBack(memory_acc my_mem) { throw; }
};
class InstructADD : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructMUL : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructNEG : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructLI : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructJAL : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructBEQ : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructBEQZ : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructLA : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructSB : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructMFHI : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};
class InstructNOP : public Instruct
{
	virtual void Execution(line the_line) { throw; }
	virtual data_pre DataPreparetion(line the_line);
	virtual answer_get Execution(data_pre my_data) { throw; }
	virtual memory_acc MemoryAccess(answer_get my_ans);
	virtual void WriteBack(memory_acc my_mem);
};


class add_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class addu_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class addiu_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class sub_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class subu_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class mul_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class mulu_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class muld_ : public InstructMUL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class mulud_ : public InstructMUL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class div_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class divu_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class divd_ : public InstructMUL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class divud_ : public InstructMUL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class xor_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class xoru_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class neg_ : public InstructNEG
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class negu_ : public InstructNEG
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class rem_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class remu_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class li_ : public InstructLI
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class seq_ : public InstructADD
{
	answer_get Execution(data_pre my_data);
	void Execution(line the_line);
};
class sge_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class sgt_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class sle_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class slt_ : public InstructADD
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class sne_ : public InstructADD
{
	answer_get Execution(data_pre my_data);
	void Execution(line the_line);
};
class b_ : public InstructJAL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class beq_ : public InstructBEQ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bne_ : public InstructBEQ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bge_ : public InstructBEQ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class ble_ : public InstructBEQ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bgt_ : public InstructBEQ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class blt_ : public InstructBEQ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class beqz_ : public InstructBEQZ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bnez_ : public InstructBEQZ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class blez_ : public Instruct
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bgez_ : public InstructBEQZ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bgtz_ : public InstructBEQZ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class bltz_ : public InstructBEQZ
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class j_ : public InstructJAL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class jr_ : public InstructJAL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class jal_ : public InstructJAL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class jalr_ : public InstructJAL
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};

class la_ : public InstructLA
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class lb_ : public InstructLA
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
	memory_acc MemoryAccess(answer_get my_ans);
};
class lh_ : public InstructLA
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
	memory_acc MemoryAccess(answer_get my_ans);
};
class lw_ : public InstructLA
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
	memory_acc MemoryAccess(answer_get my_ans);
};

class sb_ : public InstructSB
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
	memory_acc MemoryAccess(answer_get my_ans);
};
class sh_ : public InstructSB
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
	memory_acc MemoryAccess(answer_get my_ans);
};
class sw_ : public InstructSB
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
	memory_acc MemoryAccess(answer_get my_ans);
};

class move_ : public InstructNEG
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class mfhi_ : public InstructMFHI
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class mflo_ : public InstructMFHI
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};

class nop_ : public InstructNOP
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};
class syscall_ : public InstructNOP
{
	void Execution(line the_line);
	answer_get Execution(data_pre my_data);
};

#endif // !INSTRUCT_HPP

