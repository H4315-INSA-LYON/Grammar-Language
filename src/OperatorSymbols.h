#include "lutin.h"

#ifndef __OPERATOR_SYMBOLS_CLASSES_
#define __OPERATOR_SYMBOLS_CLASSES_
#endif

namespace lutinCompiler
{
	class PlusSymbol : public Symbol
	{
	public:
		PlusSymbol() : Symbol(PLUS_TOKEN)
		{}

		void print()
		{
			cout << "+";
		}

		
	};

	class MinusSymbol : public Symbol
	{
	public:
		MinusSymbol() : Symbol(MINUS_TOKEN)
		{}

		void print()
		{
			cout << "-";
		}

		
	};

	class MuliplicationSymbol : public Symbol
	{
	public:
		MuliplicationSymbol() : Symbol(MUL_TOKEN)
		{}

		void print()
		{
			cout << "*";
		}

		
	};

	class DivisionSymbol : public Symbol
	{
	public:
		DivisionSymbol() : Symbol(DIV_TOKEN)
		{}

		void print()
		{
			cout << "/";
		}

	
	};
}