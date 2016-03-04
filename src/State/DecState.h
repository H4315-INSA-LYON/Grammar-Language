#ifndef DECSTATE_H
#define DECSTATE_H
#include "State.h"

namespace lutinCompiler
{
	
	class State0 : public State 
	{
		State0(string name);
		virtual ~State();
		void print();
		bool transition(Automat & automat, Symbol *s);
	};

	class State1 : public State 
	{
		State1(string name);
		virtual ~State();
		void print();
		bool transition(Automat & automat, Symbol *s);
	};

	class State2 : public State 
	{
		State2(string name);
		virtual ~State();
		void print();
		bool transition(Automat & automat, Symbol *s);
	};

	class State3 : public State 
	{
		State3(string name);
		virtual ~State();
		void print();
		bool transition(Automat & automat, Symbol *s);
	};	
}
#endif // DECSTATE_H
