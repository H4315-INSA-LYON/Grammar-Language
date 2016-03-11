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
	};

	class IdentificatorSymbol : public Symbol
	{
	public:
		IdentificatorSymbol(const char* name) : Symbol(ID_TOKEN)
		{
			strcpy(this->name, name);
		}

		void print()
		{
			cout << "identificateur : " << name << endl;
		}

		char* getName()
		{
			return name;
		}

	private:
		char name[IDF_LENGTH];	
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
			cout << "numéro : " << number << endl;
		}

		int getNumber()
		{
			return number;
		}

	private:
		int number;
	};
}