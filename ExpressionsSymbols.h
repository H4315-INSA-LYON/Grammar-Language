#include "lutin.h"

#ifndef __EXPRESSIONS_SYMBOLS_CLASSES_
#define __EXPRESSIONS_SYMBOLS_CLASSES_
#endif

namespace lutinCompiler
{
	class WriteSymbol : public Symbol
	{
	public:
		WriteSymbol() : Symbol(WRITE_TOKEN)
		{}

		void print()
		{
			cout << "ecrire" << endl;
		}
	};

	class ReadSymbol : public Symbol
	{
	public:
		ReadSymbol() : Symbol(READ_TOKEN)
		{}

		void print()
		{
			cout << "lire" << endl;
		}
	};

	class AffectationSymbol : public Symbol
	{
	public:
		AffectationSymbol() : Symbol(AFF_TOKEN)
		{}

		void print()
		{
			cout << ":=" << endl;
		}
	};
}