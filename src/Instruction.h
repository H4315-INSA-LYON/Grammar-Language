#include "lutin.h"

#ifndef __INSTRUCTION_CLASS_
#define __INSTRUCTION_CLASS_

namespace lutinCompiler
{
	class Instruction;
	// Définir l'arbre des instructions
	typedef vector<lutinCompiler::Instruction*> AbstractTree;

	class Instruction
	{
	public:
		virtual void generate() = 0;
		virtual void print() = 0;
	};

	class Expression : public Instruction
 	{
	public:
		virtual void generate() = 0;
		virtual void print() = 0;
	};

	class VarDeclaration : public Instruction
	{
	public:
		VarDeclaration(Variable *v)
		{
			variable = v;
		}

		void generate()
		{

		}

		void print()
		{
			cout << "var ";
			variable->print();
			cout << ";" << endl;
		}

	private:
		Variable *variable;
	};

	class ConstDeclaration : public Instruction
	{
	public:
		ConstDeclaration(Constant *c)
		{
			constant = c;
		}

		void generate()
		{

		}

		void print()
		{
			cout << "const ";
			constant->print();
			cout << " = " << constant->getValue() << ";" << endl;
		}

	private:
		Constant *constant;
	};
	
	class WriteNode : public Instruction
	{
	public:
		WriteNode(Expression *exp)
		{
			expression = exp;
		}

		void print()
		{
			cout << "ecrire ";
			expression->print();
			cout << ";" << endl;
		}

		void generate()
		{

		}

	private:
		Expression *expression;
	};

	class ReadNode : public Instruction
	{
	public:
		ReadNode(IdentificatorNode *idf)
		{
			identificator = idf;
		}

		void print()
		{
			cout << "lire ";
			identificator->print();
			cout << ";" << endl;
		}

		void generate()
		{

		}

	private:
		IdentificatorNode *identificator;
	};

	class AffectationNode : public Instruction
	{
	public:
		AffectationNode(IdentificatorNode *var, Expression *exp)
		{
			variable = var;
			expression = exp;
		}

		void print()
		{
			variable->print();
			cout << " := ";
			expression->print();
			cout << ";" << endl;
		}

		void generate()
		{

		}

	private:
		IdentificatorNode *variable;
		Expression *expression;
	};

	// Expression
	class ExpressionNode : public Expression
 	{
	public:
		ExpressionNode(Expression *left, Expression *right, Operator *op)
		{
			leftExpression = left;
			rightExpression = right;
			opt = op;
		}

		void generate()
		{

		}

		void print()
		{
			leftExpression->print();
			opt->print();
			rightExpression->print();
		}

	private:
		Expression *leftExpression;
		Expression *rightExpression;
		Operator *opt;
	};

	class IdentificatorNode : public Expression
	{
	public: 
		IdentificatorNode(string name)
		{
			this->name = name;
		}

		void generate()
		{

		}

		void print()
		{
			cout << name;
		}
	
	private:
		string name;
	};

	class ValueExpression : public Expression
	{
	public: 
		ValueExpression(int v)
		{
			value = v;
		}

		void print()
		{
			cout << value;
		}

		void generate()
		{

		}

	private:
		int value;
	};

	class Operator : public Expression
	{
	public:
		Operator(char o)
		{
			opt = o;
		}

		void print()
		{
			cout << opt;
		}

		void generate()
		{

		}

	private:
		char opt;
	};
}

#endif