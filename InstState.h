#include "lutin.h"

#ifndef __INSTSTATE_H_
#define __INSTSTATE_H_

namespace lutinCompiler
{

	class State6: public State
	{
	public:
		 State6 (const char* name);
		 void print();
		 bool transition(Automat & automat, Symbol * s);
		 void errorDiagnostic(Symbol*);
	};

	class State10: public State
	{
	public:
		 State10 (const char* name);
		 void print();
		 bool transition(Automat & automat, Symbol * s);
		 void errorDiagnostic(Symbol*);
	};

	class State11: public State
	{
	public:
		 State11 (const char* name);
		 void print();
		 bool transition(Automat & automat, Symbol * s);
		 void errorDiagnostic(Symbol*);
	};

	class State12: public State
	{
	public:
		 State12 (const char* name);
		 void print();
		 bool transition(Automat & automat, Symbol * s);
		 void errorDiagnostic(Symbol*);
	};

	class State13: public State
	{
	public:
		 State13 (const char* name);
		 void print();
		 bool transition(Automat & automat, Symbol * s);
		 void errorDiagnostic(Symbol*);
	};

	class State18: public State
	{
	public:
		 State18 (const char* name);
		 void print();
		 bool transition(Automat & automat, Symbol * s);
		 void errorDiagnostic(Symbol*);
	};

}

#endif // __INSTSTATE_H_
