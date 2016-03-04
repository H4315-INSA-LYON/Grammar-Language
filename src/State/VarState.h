#ifndef CONSTSTATE_H
#define CONSTSTATE_H
#include "State.h"

//4,7,,27,28,29,30
namespace lutinCompiler
{
	
    class State4 : public State
    {
        State4 (string name);
        ~State4();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };

    class State7 : public State
    {
        State7 (string name);
        ~State7();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
	
	    class State27 : public State
    {
        State27 (string name);
        ~State27();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
	
	    class State28 : public State
    {
        State28 (string name);
        ~State28();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
	
	    class State29 : public State
    {
        State29 (string name);
        ~State29();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
	
	    class State30 : public State
    {
        State30 (string name);
        ~State30();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };


}