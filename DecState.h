#include "lutin.h"

#ifndef __DECSTATE_H_
#define __DECSTATE_H_

namespace lutinCompiler
{
	
	class State0 : public State 
	{
	public:
		State0(const char* name);
		void print();
		bool transition(Automat & automat, Symbol *s);
		void errorDiagnostic(Symbol*);
	};

	class State1 : public State 
	{
	public:
		State1(const char* name);
		void print();
		bool transition(Automat & automat, Symbol *s);
		void errorDiagnostic(Symbol*);
	};

	class State2 : public State 
	{
	public:
		State2(const char* name);
		void print();
		bool transition(Automat & automat, Symbol *s);
		void errorDiagnostic(Symbol*);
	};

	class State3 : public State 
	{
	public:
		State3(const char* name);
		void print();
		bool transition(Automat & automat, Symbol *s);
		void errorDiagnostic(Symbol*);
	};	
}

#endif // __DECSTATE_H_
