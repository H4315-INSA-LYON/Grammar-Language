#include "lutin.h"

#ifndef __VARSTATE_H_
#define __VARSTATE_H_

//4,7,,27,28,29,30
namespace lutinCompiler
{
    class State4 : public State
    {
	public:
        State4 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };

    class State7 : public State
    {
	public:
        State7 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };
	
	class State27 : public State
    {
	public:
        State27 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };
	
	class State28 : public State
    {
	public:
        State28 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };
	
	class State29 : public State
    {
	public:
        State29 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };

	class State48 : public State
    {
	public:
        State48 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };
	
	class State30 : public State
    {
	public:
        State30 (const char* name);
		void print();
        bool transition (Automat & Automat, Symbol * s);
		void errorDiagnostic(Automat&);
    };
}

#endif 