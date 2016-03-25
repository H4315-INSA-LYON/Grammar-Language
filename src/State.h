#include "lutin.h"

#ifndef __STATE_CLASS_
#define __STATE_CLASS_

namespace lutinCompiler
{
	class Automat;

	class State
	{
	public:
		State(const char* name);
		~State();

		virtual void print();
		virtual void errorDiagnostic(Automat &) = 0;
		virtual bool transition(Automat &, Symbol *) = 0;

	protected:
		char* name;
	};

}

#endif 