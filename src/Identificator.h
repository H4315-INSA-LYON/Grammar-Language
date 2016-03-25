#include "lutin.h"

#ifndef __IDENTIFICATOR_CLASS_
#define __IDENTIFICATOR_CLASS_
#endif

namespace lutinCompiler
{
	class Identificator
	{
	public:
		Identificator(string name)
		{
			this->name = name;
			used = false;
		}

		virtual void print() = 0;

		string getName()
		{
			return name;
		}

		bool &use()
		{
			return used;
		}

	protected:
		bool used;
		string name;
	};

	class Constant : public Identificator
	{
	public:
		Constant(const char *name, int v) : Identificator(name)
		{
			value = v;
		}

		void print()
		{
			cout << name;
		}

		int getValue()
		{
			return value;
		}

	private:
		int value;
	};

	class Variable : public Identificator
	{
	public:
		Variable(const char *name) : Identificator(name)
		{
			affected = false;
		}

		int getAddress()
		{
			return address;
		}

		bool &affect()
		{
			return affected;
		}

		void print()
		{
			cout << name;
		}

	private:
		bool affected;
		int address;
	};
}