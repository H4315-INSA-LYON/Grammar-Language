#include "lutin.h"

using namespace lutinCompile ;

//implementation of the State0 class methods
State0::State0(const char *name) : State(name)
{
}

void State0::print()
{
	State::print();
}

bool State0::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	// Transitions sur les symbols terminaux
	case VAR_TOKEN:
		return automat.shift(s, new State4("Etat 4"));
	break;
	case CONST_TOKEN:
		return automat.shift(s, new State5("Etat 5"));
	break;
	case WRITE_TOKEN: 
	case READ_TOKEN: 
	case EOF_TOKEN:
		return automat.reduce(new NoTerminalSymbolDec(), 0);
	break;
	// Transitions sur les symboles non terminaux
	case TOKEN_DEC:
		return automat.shift(s, new State1("Etat 1"));
	break;
	case TOKEN_VAR:
		return automat.shift(s, new State2("Etat 2"));
	break;
	case TOKEN_CONST:
		return automat.shift(s, new State3("Etat 3"));
	break;
	default:

		errorDiagnostic(automat);
    }

	return false;
}

void State0::errorDiagnostic(Automat &a)
{
	Error::syntaxError(VAR_CONST_EXPECTED);
}

//implementation of the State1 class methods
State1 :: State1(const char* name) : State(name)
{
}

void State1::print()
{
	State::print();	
}

void State1::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INSTRUCTION_EXPECTED);
}

bool State1::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN:
	case READ_TOKEN:
	case WRITE_TOKEN:
	case EOF_TOKEN:
		return automat.reduce(new NoTerminalSymbolInsts(), 0);
	break;
	case TOKEN_INSTS:
		return automat.shift(s, new State6("Etat 6"));
		break;
	default:
		errorDiagnostic(automat);
    }
    return false;
}

//implementation of the State2 class methods
State2::State2(const char* name) : State(name)
{
}

void State2::print()
{
	State::print();
}


bool State2::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case WRITE_TOKEN:
	case EOF_TOKEN:
	case ID_TOKEN:
	case READ_TOKEN:
		return automat.reduce(new NoTerminalSymbolDec(), 1);
	break;
	default:
		errorDiagnostic(automat);
		return false;
    }
    return false;
}

void State2::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INST_DEC_EXPECTED);
}

//implementation of the State3 class methods
State3::State3(const char* name) : State(name)
{
}

void State3::print()
{
	State::print();
}


bool State3::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case WRITE_TOKEN:
	case EOF_TOKEN:
	case ID_TOKEN:
	case READ_TOKEN:
		return automat.reduce(new NoTerminalSymbolDec(), 1);
	break;
	default:
		errorDiagnostic(automat);
    }
    return false;
}

void State3::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INST_DEC_EXPECTED);
}