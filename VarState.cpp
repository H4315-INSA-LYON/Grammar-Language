#include "lutin.h"
#include "VarState.h"
//4,7,,27,28,29,30,48
using namespace lutinCompiler;

//implementation of the State4 class methods
State4::State4(const char* name) : State(name)
{
}

void State4::print()
{
	State::print();
}

bool State4 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case ID_TOKEN:
        automat.shift(s, new State7("Etat 7"));
    break;
    default:
        errorDiagnostic(s);
    }
    return false;
}

void State4::errorDiagnostic(Symbol *s)
{

}

//implementation of the State7 class methods
State7::State7(const char* name) : State(name)
{
}

void State7::print()
{
	State::print();
}

bool State7 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case TOKEN_VAR_D:
        automat.shift(s, new State27("Etat 27"));
    break;        
    case COM_TOKEN:
        automat.reduce(new NoTerminalSymbolVarDec(), 0);
    break;
    case SEM_TOKEN:
        automat.reduce(new NoTerminalSymbolVarDec(), 0);
    break;
    }
    return false;
}

void State7::errorDiagnostic(Symbol *s)
{

}


State27::State27(const char* name) : State(name)
{
}

void State27::print()
{
	State::print();
}


bool State27::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {

    case COM_TOKEN:
        automat.shift(s, new State29("Etat 29"));
    break;

    case SEM_TOKEN:
        automat.shift(s, new State28("Etat 28"));
    break; 
    default:
        errorDiagnostic(s);
    }
    return false;
}

void State27::errorDiagnostic(Symbol *s)
{

}

//implementation of the State28 class methods
State28::State28(const char* name) : State(name)
{
    
}

void State28 ::print()
{
	State::print();
}

bool State28::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case VAR_TOKEN:
        automat.shift(s, new State4("State 4"));
    break;
    case CONST_TOKEN:
        automat.shift(s, new State5("State 5"));
    break;
    case WRITE_TOKEN:
        automat.reduce(new NoTerminalSymbolDec(), 0);
    break;
    case READ_TOKEN:
        automat.reduce(new NoTerminalSymbolDec(), 0);
    break;
    case ID_TOKEN:
        automat.reduce(new NoTerminalSymbolDec(), 0);
    break;
    case EOF_TOKEN:
        automat.reduce(new NoTerminalSymbolDec(), 0);
    break; 
    case TOKEN_DEC:
        //automat.shift(s, new State48("State 48"));
    break;
    case TOKEN_VAR:
        automat.shift(s, new State2("State 2"));
    break;   
    case TOKEN_CONST:
        automat.shift(s, new State3("State 3"));
    break;            
    default:
        errorDiagnostic(s);
    }  
    return false;
}


void State28::errorDiagnostic(Symbol *s)
{

}

//implementation of the State29 class methods
State29::State29(const char* name) : State(name)
{
}

void State29 ::print()
{
	State::print();
}

bool State29::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case ID_TOKEN:
        automat.shift(s, new State30("State 30"));
    break;
    default:
        errorDiagnostic(s);
    }
    return false;
}

void State29::errorDiagnostic(Symbol *s)
{

}

//implementation of the State30 class methods
State30::State30(const char* name) : State(name)
{
    
}

void State30::print()
{
	State::print();
}

bool State30::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case COM_TOKEN:
        automat.reduce(new NoTerminalSymbolVarDec(), 3);
    break;
    case SEM_TOKEN:
        automat.reduce(new NoTerminalSymbolVarDec(), 3);
    break;
    default:
        errorDiagnostic(s);
    }
    return false;
}

void State30::errorDiagnostic(Symbol *s)
{

}

//implementation of the State48 class methods
State48::State48(const char* name) : State(name)
{
    
}

void State48::print()
{
	State::print();
}

bool State48::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case WRITE_TOKEN:
        automat.reduce(new NoTerminalSymbolVar(), 6);
    break;
    case READ_TOKEN:
        automat.reduce(new NoTerminalSymbolVar(), 6);
    break;
    case ID_TOKEN:
        automat.reduce(new NoTerminalSymbolVar(), 6);
    break; 
    case EOF_TOKEN:
        automat.reduce(new NoTerminalSymbolVar(), 6);
    break;   
    default:
        errorDiagnostic(s);
    }
    return false;
}

void State48::errorDiagnostic(Symbol *s)
{

}
