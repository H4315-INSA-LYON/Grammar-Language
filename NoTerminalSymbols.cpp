#include "lutin.h"

#ifndef __NO_TERMINAL_SYMBOLS_CLASSES_
#define __NO_TERMINAL_SYMBOLS_CLASSES_
#endif

namespace lutinCompiler
{
	class NoTerminalSymbolP : public Symbol
	{
	public:
		NoTerminalSymbolP() : Symbol(TOKEN_P)
		{}

		void print()
		{
			cout << "P" << endl;
		}
	};

	class NoTerminalSymbolDec : public Symbol
	{
	public:
		NoTerminalSymbolDec() : Symbol(TOKEN_DEC)
		{}

		void print()
		{
			cout << "DEC" << endl;
		}
	};

	class NoTerminalSymbolVarDec : public Symbol
	{
	public:
		NoTerminalSymbolVarDec() : Symbol(TOKEN_VAR_D)
		{}

		void print()
		{
			cout << "VAR_DEC" << endl;
		}
	};

	class NoTerminalSymbolConstDec : public Symbol
	{
	public:
		NoTerminalSymbolConstDec() : Symbol(TOKEN_CONST_D)
		{}

		void print()
		{
			cout << "CONST_DEC" << endl;
		}
	};

	class NoTerminalSymbolVar : public Symbol
	{
	public:
		NoTerminalSymbolVar() : Symbol(TOKEN_VAR)
		{}

		void print()
		{
			cout << "VAR" << endl;
		}
	};

	class NoTerminalSymbolConst : public Symbol
	{
	public:
		NoTerminalSymbolConst() : Symbol(TOKEN_CONST)
		{}

		void print()
		{
			cout << "CONST" << endl;
		}
	};

	class NoTerminalSymbolInsts : public Symbol
	{
	public:
		NoTerminalSymbolInsts() : Symbol(TOKEN_INSTS)
		{}

		void print()
		{
			cout << "INSTS" << endl;
		}
	};

	class NoTerminalSymbolInst : public Symbol
	{
	public:
		NoTerminalSymbolInst() : Symbol(TOKEN_INST)
		{}

		void print()
		{
			cout << "INST" << endl;
		}
	};

	class NoTerminalSymbolAff : public Symbol
	{
	public:
		NoTerminalSymbolAff() : Symbol(TOKEN_AFF)
		{}

		void print()
		{
			cout << "AFF" << endl;
		}
	};

	class NoTerminalSymbolWrite : public Symbol
	{
	public:
		NoTerminalSymbolWrite() : Symbol(TOKEN_WRITE)
		{}

		void print()
		{
			cout << "ECRIRE" << endl;
		}
	};

	class NoTerminalSymbolRead : public Symbol
	{
	public:
		NoTerminalSymbolRead() : Symbol(TOKEN_READ)
		{}

		void print()
		{
			cout << "LIRE" << endl;
		}
	};

	class NoTerminalSymbolExpr : public Symbol
	{
	public:
		NoTerminalSymbolExpr() : Symbol(TOKEN_EXPR)
		{}

		void print()
		{
			cout << "EXPR" << endl;
		}
	};

	class NoTerminalSymbolTerm : public Symbol
	{
	public:
		NoTerminalSymbolTerm() : Symbol(TOKEN_TERM)
		{}

		void print()
		{
			cout << "TERM" << endl;
		}
	};

	class NoTerminalSymbolFact : public Symbol
	{
	public:
		NoTerminalSymbolFact() : Symbol(TOKEN_FACT)
		{}

		void print()
		{
			cout << "FACT" << endl;
		}
	};

	class NoTerminalSymbolAddOp : public Symbol
	{
	public:
		NoTerminalSymbolAddOp() : Symbol(TOKEN_ADDOP)
		{}

		void print()
		{
			cout << "ADDOP" << endl;
		}
	};

	class NoTerminalSymbolMulOp : public Symbol
	{
	public:
		NoTerminalSymbolMulOp() : Symbol(TOKEN_MULOP)
		{}

		void print()
		{
			cout << "MULOP" << endl;
		}
	};
}