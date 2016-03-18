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
        return automat.shift(s, new State7("Etat 7"));
    break;
    default:
        errorDiagnostic(automat);
		// Supposant que on a détécté la régle VAR	
		//return automat.reduce(new NoTerminalSymbolVar(), 1);
    }
    return false;
}

void State4::errorDiagnostic(Automat &a)
{
	Error::syntaxError(IDF_EXPECTED);

	/*a.ignoreSymbolsTo(SEM_TOKEN);

	this->transition(a, new IdentificatorSymbol("id0"));*/
}

//implementation of the State7 class methods
State7::State7(const char* name) : State(name)
{
}

void State7::print()
{
	State::print();
}

bool State7::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case TOKEN_VAR_D:
        return automat.shift(s, new State27("Etat 27"));
    break;        
    case COM_TOKEN:
        return automat.reduce(new NoTerminalSymbolVarDec(), 0);
    break;
    case SEM_TOKEN:
        return automat.reduce(new NoTerminalSymbolVarDec(), 0);
    break;
	default:
		errorDiagnostic(automat);
	}

    return false;
}

void State7::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
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
        return automat.shift(s, new State29("Etat 29"));
    break;

    case SEM_TOKEN:
        return automat.shift(s, new State28("Etat 28"));
    break; 
    default:
        errorDiagnostic(automat);
    }
    return false;
}

void State27::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
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
        return automat.shift(s, new State4("State 4"));
    break;
    case CONST_TOKEN:
        return automat.shift(s, new State5("State 5"));
    break;
    case WRITE_TOKEN:
        return automat.reduce(new NoTerminalSymbolDec(), 0);
    break;
    case READ_TOKEN:
        return automat.reduce(new NoTerminalSymbolDec(), 0);
    break;
    case ID_TOKEN:
        return automat.reduce(new NoTerminalSymbolDec(), 0);
    break;
    case EOF_TOKEN:
        return automat.reduce(new NoTerminalSymbolDec(), 0);
    break; 
    case TOKEN_DEC:
        return automat.shift(s, new State48("State 48"));
    break;
    case TOKEN_VAR:
        return automat.shift(s, new State2("State 2"));
    break;   
    case TOKEN_CONST:
        return automat.shift(s, new State3("State 3"));
    break;            
    default:
        errorDiagnostic(automat);
    }  
    return false;
}


void State28::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INST_DEC_EXPECTED);
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
        return automat.shift(s, new State30("State 30"));
    break;
    default:
        errorDiagnostic(automat);
    }
    return false;
}

void State29::errorDiagnostic(Automat &a)
{
	Error::syntaxError(IDF_EXPECTED);
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
        return automat.reduce(new NoTerminalSymbolVarDec(), 3);
    break;
    case SEM_TOKEN:
        return automat.reduce(new NoTerminalSymbolVarDec(), 3);
    break;
    default:
        errorDiagnostic(automat);
    }
    return false;
}

void State30::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_COM_EXPECTED);
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
        return automat.reduce(new NoTerminalSymbolVar(), 5);
    break;
    case READ_TOKEN:
        return automat.reduce(new NoTerminalSymbolVar(), 5);
    break;
    case ID_TOKEN:
        return automat.reduce(new NoTerminalSymbolVar(), 5);
    break; 
    case EOF_TOKEN:
        return automat.reduce(new NoTerminalSymbolVar(), 5);
    break;   
    default:
        errorDiagnostic(automat);
    }
    return false;
}

void State48::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INSTRUCTION_EXPECTED);
}
