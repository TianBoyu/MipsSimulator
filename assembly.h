#ifndef ASSEMBLY_HPP
#define ASSEMBLY_HPP

class Assembly
{
public:
	virtual void Configure(line the_line) { throw; }
};
class align_ : public Assembly
{
	void Configure(line the_line);
};
class ascii_ : public Assembly
{
	void Configure(line the_line);
};
class asciiz_ : public Assembly
{
	void Configure(line the_line);
};
class byte_ : public Assembly
{
	void Configure(line the_line);
};
class half_ : public Assembly
{
	void Configure(line the_line);
};
class word_ : public Assembly
{
	void Configure(line the_line);
};
class space_ : public Assembly
{
	void Configure(line the_line);
};
class data_ : public Assembly
{
	void Configure(line the_line);
};
class text_ : public Assembly
{
	void Configure(line the_line);
};

#endif