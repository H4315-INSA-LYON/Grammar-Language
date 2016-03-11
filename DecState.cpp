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
	cerr << "Erreur (" << LINE_NUMBER << ":" << CARACTER_NUMBER << "): var ou const attendu" << endl;
}

//implementation of the State1 class methods
State1 :: State1(const char* name) : State(name)
{
}

void State1::print()
{
	
}

void State1::errorDiagnostic(Symbol *s)
{

}

bool State1::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {

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

    }
    return false;
}

void State2::errorDiagnostic(Symbol *s)
{

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

    }
    return false;
}

void State3::errorDiagnostic(Symbol *s)
{

}
