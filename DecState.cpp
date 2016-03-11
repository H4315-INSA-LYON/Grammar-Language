#include "lutin.h"

using namespace lutinCompiler;

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
		automat.shift(s, new State4("Etat 4"));
	break;
	case CONST_TOKEN:
		automat.shift(s, new State5("Etat 5"));
	break;
	// Transitions sur les symboles non terminaux
	case TOKEN_DEC:
		automat.shift(s, new State1("Etat 1"));
	break;
	case TOKEN_VAR:
		automat.shift(s, new State2("Etat 2"));
	break;
	case TOKEN_CONST:
		automat.shift(s, new State3("Etat 3"));
	break;
	default:

		errorDiagnostic(s);

    }
    return false;
}

void State0::errorDiagnostic(Symbol *s)
{
	cerr << "ERROR (" << LINE_NUMBER << ":" << CARACTER_NUMBER << "): var or const symbol expected" << endl;
}

//implementation of the State1 class methods
State1 :: State1(const char* name) : State(name)
{
}

void State1::print()
{
	State::print();	
}

void State1::errorDiagnostic(Symbol *s)
{
	cerr << "ERROR (" << LINE_NUMBER << ":" << CARACTER_NUMBER << "): write, read, id, eof or INSTS token expected" << endl;
}

bool State1::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    	case WRITE_TOKEN:
			automat.reduce(TOKEN_INSTS, 0);
			break;
		case READ_TOKEN:
			automat.reduce(TOKEN_INSTS, 0);
			break;
		case ID_TOKEN:
			automat.reduce(TOKEN_INSTS, 0);
			break;
		case EOF_TOKEN:
			automat.reduce(WRITE_TOKEN, 0);
			break;
		case TOKEN_INSTS:
			automat.shift(s, new State6("Etat 6"));
			break;
		default:
			errorDiagnostic(s);
    }
    return false;
}

//implementation of the State2 class methods
State2::State2(const char* name) : State(name)
{
}

void State2::print()
{

}


bool State2::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    	case ECRIRE_TOKEN:
			automat.reduce(TOKEN_DEC, 1);
			break;
		case WRITE_TOKEN:
			automat.reduce(TOKEN_DEC, 1);
			break;
		case ID_TOKEN:
			automat.reduce(TOKEN_DEC, 1);
			break;
		case EOF_TOKEN:
			automat.reduce(TOKEN_DEC, 1);
			break;	
		default:
			errorDiagnostic(s);
    }
    return false;
}

void State2::errorDiagnostic(Symbol *s)
{
	cerr << "ERROR (" << LINE_NUMBER << ":" << CARACTER_NUMBER << "): write, read, id or eof token expected" << endl;
}

//implementation of the State3 class methods
State3::State3(const char* name) : State(name)
{
}

void State3::print()
{

}


bool State3::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    	case WRITE_TOKEN:
			automat.reduce(TOKEN_DEC, 0);
			break;
		case READ_TOKEN:
			automat.reduce(TOKEN_DEC, 0);
			break;
		case ID_TOKEN:
			automat.reduce(TOKEN_DEC, 0);
			break;
		case ID_TOKEN:
			automat.reduce(TOKEN_DEC, 0);
			break;
		default:
			errorDiagnostic();
    }
    return false;
}

void State3::errorDiagnostic(Symbol *s)
{
	cerr << "ERROR (" << LINE_NUMBER << ":" << CARACTER_NUMBER << "): write, read, id or eof token expected" << endl;
}