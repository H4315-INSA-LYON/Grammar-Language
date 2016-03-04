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
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State8: public State
    {
        State8 (string name);
        ~State8();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State9: public State
    {
        State9 (string name);
        ~State9();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State20: public State
    {
        State20 (string name);
        ~State20();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State21: public State
    {
        State21 (string name);
        ~State21();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State22: public State
    {
        State22 (string name);
        ~State22();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State23: public State
    {
        State23 (string name);
        ~State23();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State24: public State
    {
        State24 (string name);
        ~State24();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State25: public State
    {
        State25 (string name);
        ~State25();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };
    class State26: public State
    {
        State26 (string name);
        ~State26();
        void print();
        bool transition (Automat & automat, Symbol * s) = 0;
    };

}

#endif // CONSTSTATE_H
