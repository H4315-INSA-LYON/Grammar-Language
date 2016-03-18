#include "lutin.h"

#ifndef __SPECIAL_SYMBOLS_CLASSES_
#define __SPECIAL_SYMBOLS_CLASSES_
#endif

namespace lutinCompiler
{
	class EqualSymbol : public Symbol
	{
	public:
		EqualSymbol() : Symbol(EQ_TOKEN)
		{}

		void print()
		{
			cout << "=" << endl;
		}

	
	};

	class CommaSymbol : public Symbol
	{
	public:
		CommaSymbol() : Symbol(COM_TOKEN)
		{}

		void print()
		{
			cout << "," << endl;
		}

		
	};

	class SemicolonSymbol : public Symbol
	{
	public:
		SemicolonSymbol() : Symbol(SEM_TOKEN)
		{}

		void print()
		{
			cout << ";" << endl;
		}

		
	};

	class OpeningParenthesisSymbol : public Symbol
	{
	public:
		OpeningParenthesisSymbol() : Symbol(OP_TOKEN)
		{}

		void print()
		{
			cout << "(" << endl;
		}

		
	};

	class ClosingParenthesisSymbol : public Symbol
	{
	public:
		ClosingParenthesisSymbol() : Symbol(CP_TOKEN)
		{}

		void print()
		{
			cout << ")" << endl;
		}

		
	};

	class EOFSymbol : public Symbol
	{
	public:
		EOFSymbol() : Symbol(EOF_TOKEN)
		{}

		void print()
		{
			cout << "EOF" << endl;
		}

	
	};
}