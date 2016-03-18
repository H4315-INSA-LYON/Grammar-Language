#include "lutin.h"

#ifndef __NO_TERMINAL_SYMBOLS_CLASSES_
#define __NO_TERMINAL_SYMBOLS_CLASSES_

namespace lutinCompiler
{

	// Définir une liste de symboles
	typedef array<Symbol*,7> SymbolList;

	class NoTerminalSymbol : public Symbol
	{
	public:
		NoTerminalSymbol(TOKEN token) : Symbol(token)
		{}

		virtual Symbol* construct(SymbolList &) = 0;
	};

	class NoTerminalSymbolP : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolP() : NoTerminalSymbol(TOKEN_P)
		{
			dec = insts = nullptr;
		}

		void print()
		{
			if (dec)
				dec->print();

			if (insts)
				insts->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire P" << endl;

			dec = list[1];
			insts = list[0];

			return nullptr;
		}

	private:
		Symbol *dec;
		Symbol *insts;
	};

	class NoTerminalSymbolDec : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolDec() : NoTerminalSymbol(TOKEN_DEC)
		{
			dec = nullptr;
		}

		void print()
		{
			if (dec)
				dec->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire DEC" << endl;

			dec = list[0];

			return nullptr;
		}

	private:
		Symbol *dec;
	};

	class NoTerminalSymbolVarDec : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolVarDec() : NoTerminalSymbol(TOKEN_VAR_D)
		{
			id = varDec = nullptr;
		}

		void print()
		{
			if (varDec)
				varDec->print();

			cout << ", ";
			id->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire VAR_DEC" << endl;

			varDec = list[2];
			id = list[0];

			return nullptr;
		}

	private:
		Symbol* id;
		Symbol* varDec;
	};

	class NoTerminalSymbolConstDec : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolConstDec() : NoTerminalSymbol(TOKEN_CONST_D)
		{
			constDec = value = id = nullptr;
		}

		void print()
		{
			if (constDec)
				constDec->print();

			cout << ", ";
			id->print();
			cout << " = ";
			value->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire CONST_DEC" << endl;

			constDec = list[4];
			value = list[0];
			id = list[2];

			return nullptr;
		}

	private:
		Symbol* id;
		Symbol* value;
		Symbol* constDec;
	};

	class NoTerminalSymbolVar : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolVar() : NoTerminalSymbol(TOKEN_VAR)
		{
			dec = varDec = id = nullptr;
		}

		void print()
		{
			cout << "var ";
			id->print();
			
			if (varDec)
				varDec->print();

			cout << ";" << endl;

			if (dec)
				dec->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire VAR" << endl;

			dec = list[0];
			varDec = list[2];
			id = list[3];

			return nullptr;
		}

	private:
		Symbol* id;
		Symbol* varDec;
		Symbol* dec;
	};

	class NoTerminalSymbolConst : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolConst() : NoTerminalSymbol(TOKEN_CONST)
		{
			dec = constDec = id = value = nullptr;
		}

		void print()
		{
			cout << "const ";
			id->print();
			cout << " = ";
			value->print();

			if (constDec)
				constDec->print();

			cout << ";" << endl;

			if (dec)
				dec->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire CONST" << endl;

			dec = list[0];
			constDec = list[2];
			value = list[3];
			id = list[5];

			return nullptr;
		}

	private:
		Symbol* id;
		Symbol* value;
		Symbol* constDec;
		Symbol* dec;
	};

	class NoTerminalSymbolInsts : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolInsts() : NoTerminalSymbol(TOKEN_INSTS)
		{
			inst = insts = nullptr;
		}

		void print()
		{
			if (insts)
				insts->print();

			inst->print();

			cout << ";" << endl;
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire INSTS" << endl;
			
			inst = list[1];
			insts = list[2];

			return nullptr;
		}

	private:
		Symbol *inst;
		Symbol *insts;
	};

	class NoTerminalSymbolInst : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolInst() : NoTerminalSymbol(TOKEN_INST)
		{
			inst = nullptr;
		}

		void print()
		{
			inst->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire INST" << endl;
			
			return inst = list[0];
		}

	private:
		Symbol *inst;

	};

	class NoTerminalSymbolAff : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolAff() : NoTerminalSymbol(TOKEN_AFF)
		{
			id = expr = nullptr;
		}

		void print()
		{
			id->print();
			cout << " := ";
			expr->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire AFF" << endl;
			
			id = list[2];
			expr = list[0];

			return nullptr;
		}

	private:
		Symbol *id;
		Symbol *expr;
	};

	class NoTerminalSymbolWrite : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolWrite() : NoTerminalSymbol(TOKEN_WRITE)
		{
			expr = nullptr;
		}

		void print()
		{
			cout << "ecrire ";
			expr->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire ECRIRE" << endl;
			
			return expr = list[0];
		}

	private:
		Symbol *expr;
	};

	class NoTerminalSymbolRead : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolRead() : NoTerminalSymbol(TOKEN_READ)
		{
			id = nullptr;
		}

		void print()
		{
			cout << "lire ";
			id->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire LIRE" << endl;
			
			return id = list[0];
		}

	private:
		Symbol *id;
	};

	class NoTerminalSymbolExpr : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolExpr() : NoTerminalSymbol(TOKEN_EXPR)
		{
			expr = term = add = nullptr;
		}

		void print()
		{
			if (expr)
			{
				expr->print();
				add->print();
			}

			term->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire EXPR : " << list.size() << endl;

			term = list[0];

			if (list.size() == 3)
			{
				add = list[1];
				expr = list[2];
			}

			return nullptr;
		}

	private:
		Symbol *expr;
		Symbol *add;
		Symbol *term;
	};

	class NoTerminalSymbolTerm : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolTerm() : NoTerminalSymbol(TOKEN_TERM)
		{
			term = mul = fact = nullptr;
		}

		void print()
		{
			if (term)
			{
				term->print();
				mul->print();
			}

			fact->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire TERM" << endl;
			
			fact = list[0];

			if (list.size() == 3)
			{
				mul = list[1];
				term = list[2];
			}

			return nullptr;
		}

	private:
		Symbol *term;
		Symbol *mul;
		Symbol *fact;
	};

	class NoTerminalSymbolFact : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolFact() : NoTerminalSymbol(TOKEN_FACT)
		{
			fact = nullptr;
		}

		void print()
		{
			fact->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire FACT" << endl;

			int i = (list.size() == 3 ? 1 : 0);

			return fact = list[i];
		}

	private:
		Symbol* fact;
	};

	class NoTerminalSymbolAddOp : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolAddOp() : NoTerminalSymbol(TOKEN_ADDOP)
		{
			op = nullptr;
		}

		void print()
		{
			op->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire ADDOP" << endl;

			return op = list[0];
		}

	private:
		Symbol *op;

	};

	class NoTerminalSymbolMulOp : public NoTerminalSymbol
	{
	public:
		NoTerminalSymbolMulOp() : NoTerminalSymbol(TOKEN_MULOP)
		{
			op = nullptr;
		}

		void print()
		{
			op->print();
		}

		Symbol* construct(SymbolList &list)
		{
			cout << "Construire MULOP" << endl;

			return op = list[0];
		}

	private:
		Symbol *op;
	};
}

#endif