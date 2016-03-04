#ifndef CONSTSTATE_H
#define CONSTSTATE_H
#include "State.h"

namespace lutinCompiler
{
    class State5 : public State
    {
        State5 (string name);
        ~State5();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
    class State8: public State
    {
        State8 (string name);
        ~State8();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
    class State9: public State
    {
        State9 (string name);
        ~State9();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
    class State20: public State
    {
        State20 (string name);
        ~State20();
        void print();
        bool transition (Automate & automate, Symbole * s) = 0;
    };
}

#endif // CONSTSTATE_H
