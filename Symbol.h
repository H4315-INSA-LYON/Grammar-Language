#include "lutin.h"

#ifndef __SYMBOL_CLASS_
#define __SYMBOL_CLASS_

namespace lutinCompiler
{
	class Symbol
	{
	public:
		Symbol(TOKEN token)
		{
			this->token = token;
		}

		virtual ~Symbol(){}

		virtual void print() = 0;
		//virtual Symbol* construct() = 0;

		operator int() const
		{
			return token;
		}

	protected:
		TOKEN token;
	};
}

// Les symboles fils
#include "HeaderSymbols.h"
#include "ExpressionsSymbols.h"
#include "OperatorSymbols.h"
#include "SpecialSymbols.h"
#include "NoTerminalSymbols.h"

#endif