#include "lutin.h"

#ifndef __CONSTSTATE_H_
#define __CONSTSTATE_H_

namespace lutinCompiler
{
    class State5 : public State
    {
	public:
        State5 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State8: public State
    {
	public:
        State8 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State9: public State
    {
	public:
        State9 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State20: public State
    {
	public:
        State20 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State21: public State
    {
	public:
        State21 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State22: public State
    {
	public:
        State22 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State23: public State
    {
	public:
        State23 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State24: public State
    {
	public:
        State24 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };
    class State25: public State
    {
	public:
        State25 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

    class State26: public State
    {
	public:
        State26 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };
	class State49: public State
    {
	public:
        State49 (const char* name);
        void print();
        bool transition (Automat & automat, Symbol * s);
		void errorDiagnostic(Symbol*);
    };

}

#endif // CONSTSTATE_H
