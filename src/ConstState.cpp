#include "lutin.h"

using namespace lutinCompiler;

//implementation of the State5 class methods
State5 :: State5(const char* name) : State(name)
{
}

void State5 ::print()
{
	State::print();
}

bool State5 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case ID_TOKEN: return automat.shift(s,new State8("Etat 8"));
					   break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State5::errorDiagnostic(Automat &a)
{
	Error::syntaxError(IDF_EXPECTED);
}

//implementation of the State8 class methods
State8 :: State8(const char* name) : State(name)
{
}

void State8 ::print()
{
	State::print();
}


bool State8 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case EQ_TOKEN: return automat.shift(s,new State9("Etat 9"));
				   break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State8::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EQ_EXPECTED);
}

//implementation of the State9 class methods
State9 :: State9(const char* name) : State(name)
{
}

void State9 ::print()
{
	State::print();
}

bool State9 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case NUM_TOKEN: return automat.shift(s,new State20("Etat 20"));
				       break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State9::errorDiagnostic(Automat &a)
{
	Error::syntaxError(NUM_EXPECTED);
}

//implementation of the State20 class methods
State20 :: State20(const char* name) : State(name)
{
}

void State20 ::print()
{
	State::print();
}


bool State20 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolConstDec(),0);
				   break;
		case COM_TOKEN: return automat.reduce(new NoTerminalSymbolConstDec(),0);
				   break;
		case TOKEN_CONST_D:
			return automat.shift(s, new State21("Etat 21"));
		break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State20::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_COM_EXPECTED);
}

//implementation of the State21 class methods
State21 :: State21(const char* name) : State(name)
{
}

void State21 ::print()
{
	State::print();
}


bool State21 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case SEM_TOKEN: return automat.shift(s,new State22("Etat 22"));
				       break;
		case COM_TOKEN: return automat.shift(s,new State49("Etat 49"));
				       break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State21::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_COM_EXPECTED);
}

//implementation of the State22 class methods
State22 :: State22(const char* name) : State(name)
{
}

void State22 ::print()
{
	State::print();
}

bool State22 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case VAR_TOKEN: return automat.shift(s,new State4("Etat 4"));
				       break;
		case CONST_TOKEN: return automat.shift(s,new State5("Etat 5"));
				       break;
		case WRITE_TOKEN: return automat.reduce(new NoTerminalSymbolDec(),0);
				       break;
		case READ_TOKEN: return automat.reduce(new NoTerminalSymbolDec(),0);
				       break;
		case ID_TOKEN: return automat.reduce(new NoTerminalSymbolDec(),0);
				       break;
		case EOF_TOKEN: return automat.reduce(new NoTerminalSymbolDec(),0);
				       break;
		case TOKEN_DEC: return automat.shift(s,new State23("Etat 23"));
				       break;
		case TOKEN_VAR: return automat.shift(s,new State2("Etat 2"));
				       break;
		case TOKEN_CONST: return automat.shift(s,new State3("Etat 3"));
				       break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State22::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INST_DEC_EXPECTED);
}

//implementation of the State23 class methods
State23 :: State23(const char* name) : State(name)
{
}

void State23 ::print()
{
	State::print();
}

bool State23 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case WRITE_TOKEN: return automat.reduce(new NoTerminalSymbolConst(),7);
				       break;
		case READ_TOKEN: return automat.reduce(new NoTerminalSymbolConst(),7);
				       break;
		case ID_TOKEN: return automat.reduce(new NoTerminalSymbolConst(),7);
				       break;
		case EOF_TOKEN: return automat.reduce(new NoTerminalSymbolConst(),7);
				       break;
		default		 : errorDiagnostic(automat);

    }
    return false;
}

void State23::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INSTRUCTION_EXPECTED);
}

//implementation of the State24 class methods
State24 :: State24(const char* name) : State(name)
{
}

void State24 ::print()
{
	State::print();
}


bool State24 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case EQ_TOKEN: return automat.shift(s,new State25("Etat 25"));
				   break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State24::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EQ_EXPECTED);
}

//implementation of the State25 class methods
State25 :: State25(const char* name) : State(name)
{
}

void State25 ::print()
{
	State::print();
}


bool State25 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case NUM_TOKEN: return automat.shift(s,new State26("Etat 26"));
					   break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State25::errorDiagnostic(Automat &a)
{
	Error::syntaxError(NUM_EXPECTED);
}

//implementation of the State26 class methods
State26 :: State26(const char* name) : State(name)
{
}

void State26 ::print()
{
	State::print();
}


bool State26 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case COM_TOKEN: return automat.reduce(new NoTerminalSymbolConstDec(),5);
					   break;
		case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolConstDec(),5);
					   break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State26::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_COM_EXPECTED);
}

//implementation of the State26 class methods
State49 :: State49(const char* name) : State(name)
{
}

void State49 ::print()
{
	State::print();
}


bool State49 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
		case ID_TOKEN: return automat.shift(s,new State24("Etat24"));
					   break;
		default		 : errorDiagnostic(automat);
    }
    return false;
}

void State49::errorDiagnostic(Automat &a)
{
	Error::syntaxError(IDF_EXPECTED);
}