#include "lutin.h"

#ifndef __HEADER_SYMBOLS_CLASSES_
#define __HEADER_SYMBOLS_CLASSES_
#endif

namespace lutinCompiler
{
	class VarSymbol : public Symbol
	{
	public:
		VarSymbol() : Symbol(VAR_TOKEN)
		{}

		void print() 
		{
			cout << "var" << endl;
		}

		Symbol *construct()
		{
			return nullptr;
		}
	};

	class ConstSymbol : public Symbol
	{
	public:
		ConstSymbol() : Symbol(CONST_TOKEN)
		{}

		void print() 
		{
			cout << "const" << endl;
		}

		Symbol *construct()
		{
			return nullptr;
		}
	};

	class IdentificatorSymbol : public Symbol
	{
	public:
		IdentificatorSymbol(string name) : Symbol(ID_TOKEN)
		{
			this->name = name;
		}

		void print()
		{
			cout << name;
		}

		string getName()
		{
			return name;
		}

	private:
		string name;
	};

	class NumberSymbol : public Symbol
	{
	public:
		NumberSymbol(int number) : Symbol(NUM_TOKEN)
		{
			this->number = number;
		}

		void print()
		{
			cout << number;
		}

		int getNumber()
		{
			return number;
		}

	private:
		int number;
	};
}