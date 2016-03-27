#include "lutin.h"

using namespace lutinCompiler;

//implementation of the State6 class methods
State6 :: State6(const char* name) : State(name)
{
}

void State6 ::print()
{
	State::print();
}

bool State6 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case WRITE_TOKEN: return automat.shift(s,new State15("Etat 15"));
		break;
	case READ_TOKEN:  return automat.shift(s,new State16("Etat 16"));
		break;
	case ID_TOKEN: return automat.shift(s,new State14("Etat 14"));
		break;
	case EOF_TOKEN: 
		return automat.reduce(new NoTerminalSymbolP(),2);
		break;
	case TOKEN_INST: return automat.shift(s,new State10("Etat 10"));
		break;
	case TOKEN_AFF: return automat.shift(s,new State11("Etat 11"));
		break;
	case TOKEN_WRITE: return automat.shift(s,new State12("Etat 12"));
		break;
	case TOKEN_READ: return automat.shift(s,new State13("Etat 13"));
		break;
	default    :errorDiagnostic(automat);
	}
    return false;
}

void State6::errorDiagnostic(Automat &a)
{
	Error::syntaxError(INSTRUCTION_EXPECTED);
}

//implementation of the State10 class methods
State10 :: State10(const char* name) : State(name)
{
}

void State10 ::print()
{
	State::print();
}

bool State10 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.shift(s,new State18("Etat 18"));
		break;
	default   :errorDiagnostic(automat);

    }
    return false;
}

void State10::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NoTerminalSymbolInst());
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInsts(), 3);
	default:
		break;
	}
}
//implementation of the State11 class methods
State11 :: State11(const char* name) : State(name)
{
}

void State11 ::print()
{
	State::print();
}

bool State11 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolInst(),1);
		break;
	default    :errorDiagnostic(automat);
    }
    return false;
}

void State11::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInst(),2);
	default:
		break;
	}
}

//implementation of the State12 class methods
State12 :: State12(const char* name) : State(name)
{
}

void State12 ::print()
{
	State::print();
}

bool State12 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
    case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolInst(),1);
		break;
	default    :errorDiagnostic(automat);
    }
    return false;
}

void State12::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInst(), 2);
	default:
		break;
	}
}

//implementation of the State13 class methods
State13 :: State13(const char* name) : State(name)
{
}

void State13 ::print()
{
	State::print();
}

bool State13 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolInst(),1);
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State13::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst()){
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInst(), 2);

	default:
		break;
	}
}
//implementation of the State14 class methods
State14 :: State14(const char* name) : State(name)
{
}

void State14 ::print()
{
	State::print();
}

bool State14 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case AFF_TOKEN: return automat.shift(s,new State19("Etat 19"));
		break;
	default   :errorDiagnostic(automat);
    }
    return false;
}

void State14::errorDiagnostic(Automat &a)
{
	Error::syntaxError(AFF_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NoTerminalSymbolAff());
		a.pushSymbol(new IdentificatorSymbol("id"));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInst(),4);
		default:
			break;
	}
}
//implementation of the State15 class methods
State15 :: State15(const char* name) : State(name)
{
}

void State15 ::print()
{
	State::print();
}

bool State15 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.shift(s,new State39("Etat 39"));
		break;
	case NUM_TOKEN: return automat.shift(s,new State40("Etat 40"));
		break;
	case OP_TOKEN:  return automat.shift(s,new State41("Etat 41"));
		break;
	case TOKEN_EXPR: return automat.shift(s,new State31("Etat 31"));
		break;
	case TOKEN_TERM: return automat.shift(s,new State34("Etat 34"));
		break;
	case TOKEN_FACT: return automat.shift(s,new State42("Etat 42"));
		break;
	default   :errorDiagnostic(automat);
    }
    return false;
}

void State15::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch(*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new IdentificatorSymbol("id"));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInst(), 3);
	default:
		break;
	}
}
//implementation of the State16 class methods
State16 :: State16(const char* name) : State(name)
{
}

void State16 ::print()
{
	State::print();
}

bool State16 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.shift(s,new State17("Etat 17"));
		break;
	default   :errorDiagnostic(automat);
    }
    return false;
}

void State16::errorDiagnostic(Automat &a)
{
	Error::syntaxError(IDF_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new IdentificatorSymbol("id"));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolRead(), 3);
	default:
		break;
	}
}

//implementation of the State17 class methods
State17 :: State17(const char* name) : State(name)
{
}

void State17 ::print()
{
	State::print();
}

bool State17 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolRead(),2);
		break;
	default   :errorDiagnostic(automat);

    }
    return false;
}

void State17::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToDec())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolRead(), 3);
		default:
			break;
	}
}
//implementation of the State18 class methods
State18 :: State18(const char* name) : State(name)
{
}

void State18 ::print()
{
	State::print();
}

bool State18::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case WRITE_TOKEN: return automat.reduce(new NoTerminalSymbolInsts(),3);
		break;
	case READ_TOKEN: return automat.reduce(new NoTerminalSymbolInsts(),3);
		break;
	case ID_TOKEN:  return automat.reduce(new NoTerminalSymbolInsts(),3);
		break;
	case EOF_TOKEN:  return automat.reduce(new NoTerminalSymbolInsts(),3);
		break;
	 default    :errorDiagnostic(automat);
    }
    return false;
}

void State18::errorDiagnostic(Automat &a)
{
	Error::syntaxError(DELETE_TOKEN);
	switch (*a.ignoreSymbolsToDec())
	{
		a.pushSymbol(new EOFSymbol());
		a.reduce(new NoTerminalSymbolInsts(), 3);
		default:
			break;
	}
}

//implementation of the State19 class methods
State19 :: State19(const char* name) : State(name)
{
}

void State19 ::print()
{
	State::print();
}

bool State19 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.shift(s,new State39("Etat 39"));
		break;
	case NUM_TOKEN: return automat.shift(s,new State40("Etat 40"));
		break;
	case OP_TOKEN: return automat.shift(s,new State41("Etat 41"));
		break;
	case TOKEN_EXPR: return automat.shift(s,new State45("Etat 45"));
		break;
	case TOKEN_TERM: return automat.shift(s,new State34("Etat 34"));
		break;
	case TOKEN_FACT: return automat.shift(s,new State42("Etat 42"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State19::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())

	{
		a.pushSymbol(new IdentificatorSymbol("id"));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolInst(), 4);
	default:
		break;
	}
}

//implementation of the State31 class methods
State31 :: State31(const char* name) : State(name)
{
}

void State31 ::print()
{
	State::print();
}

bool State31 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case PLUS_TOKEN: return automat.shift(s,new State32("Etat 32"));
		break;
	case MINUS_TOKEN: return automat.shift(s,new State33("Etat 33"));
		break;
	case TOKEN_ADDOP: return automat.shift(s,new State37("Etat 37"));
		break;
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolWrite(),2);
		break;
	default   :errorDiagnostic(automat);
    }
    return false;
}

void State31::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolWrite(), 3);
	default:
		break;
	}
}

//implementation of the State32 class methods
State32 :: State32(const char* name) : State(name)
{
}

void State32 ::print()
{
	State::print();
}

bool State32 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.reduce(new NoTerminalSymbolAddOp(),1);
		break;
	case NUM_TOKEN: return automat.reduce(new NoTerminalSymbolAddOp(),1);
		break;
	case OP_TOKEN: return automat.reduce(new NoTerminalSymbolAddOp(),1);
		break;
	default    :errorDiagnostic(automat);
    }
    return false;
}

void State32::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(0));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAddOp(), 5);
	default:
		break;
	}
}
//implementation of the State33 class methods
State33 :: State33(const char* name) : State(name)
{
}

void State33 ::print()
{
	State::print();
}

bool State33 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.reduce(new NoTerminalSymbolAddOp(),1);
		break;
	case NUM_TOKEN: return automat.reduce(new NoTerminalSymbolAddOp(),1);
		break;
	case OP_TOKEN: return automat.reduce(new NoTerminalSymbolAddOp(),1);
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State33::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(0));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAddOp(), 5);
	default:
		break;
	}
}
//implementation of the State34 class methods
State34 :: State34(const char* name) : State(name)
{
}

void State34 ::print()
{
	State::print();
}

bool State34 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolExpr(),1);
		break;
	case CP_TOKEN: return automat.reduce(new NoTerminalSymbolExpr(),1);
		break;
	case PLUS_TOKEN: return automat.reduce(new NoTerminalSymbolExpr(),1);
		break;
	case MINUS_TOKEN: return automat.reduce(new NoTerminalSymbolExpr(),1);
		break;
	case MUL_TOKEN: return automat.shift(s,new State35("Etat 35"));
		break;
	case DIV_TOKEN: return automat.shift(s,new State36("Etat 36"));
		break;
	case TOKEN_MULOP: return automat.shift(s,new State38("Etat 38"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State34::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
}
//implementation of the State35 class methods
State35 :: State35(const char* name) : State(name)
{
}

void State35 ::print()
{
	State::print();
}

bool State35 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.reduce(new NoTerminalSymbolMulOp(),1);
		break;
	case NUM_TOKEN: return automat.reduce(new NoTerminalSymbolMulOp(),1);
		break;
	case OP_TOKEN: return automat.reduce(new NoTerminalSymbolMulOp(),1);
		break;
	default    :errorDiagnostic(automat);
    }
    return false;
}

void State35::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(1));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolMulOp(), 7);
	default:
		break;
	}
}
//implementation of the State36 class methods
State36 :: State36(const char* name) : State(name)
{
}

void State36 ::print()
{
	State::print();
}

bool State36 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.reduce(new NoTerminalSymbolMulOp(),1);
		break;
	case NUM_TOKEN: return automat.reduce(new NoTerminalSymbolMulOp(),1);
		break;
	case OP_TOKEN: return automat.reduce(new NoTerminalSymbolMulOp(),1);
		break;
	default    :errorDiagnostic(automat);
    }
    return false;
}

void State36::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(1));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolMulOp(), 7);
	default:
		break;
	}
}
//implementation of the State37 class methods
State37 :: State37(const char* name) : State(name)
{
}

void State37 ::print()
{
	State::print();
}

bool State37 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.shift(s,new State39("Etat 39"));
		break;
	case NUM_TOKEN: return automat.shift(s,new State40("Etat 40"));
		break;
	case OP_TOKEN: return automat.shift(s,new State41("Etat 41"));
		break;
	case TOKEN_TERM: return automat.shift(s,new State43("Etat 43"));
		break;
	case TOKEN_FACT: return automat.shift(s,new State42("Etat 42"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State37::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(0));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAddOp(), 5);
	default:
		break;
	}
}
//implementation of the State38 class methods
State38 :: State38(const char* name) : State(name)
{
}

void State38 ::print()
{
	State::print();
}

bool State38 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.shift(s,new State39("Etat 39"));
		break;
    case NUM_TOKEN: return automat.shift(s,new State40("Etat 40"));
		break;
	case OP_TOKEN: return automat.shift(s,new State41("Etat 41"));
		break;
	case TOKEN_FACT: return automat.shift(s,new State44("Etat 44"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State38::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(1));
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolMulOp(), 7);
	default:
		break;
	}
}
//implementation of the State39 class methods
State39 :: State39(const char* name) : State(name)
{
}

void State39 ::print()
{
	State::print();
}

bool State39 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN: return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case CP_TOKEN: return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case PLUS_TOKEN: return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case MINUS_TOKEN: return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case MUL_TOKEN: return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case DIV_TOKEN: return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	default    :errorDiagnostic(automat);
    }
    return false;
}

void State39::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAddOp(), 5);
	default:
		break;
	}
}
//implementation of the State40 class methods
State40 :: State40(const char* name) : State(name)
{
}

void State40 ::print()
{
	State::print();
}

bool State40 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN:     return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case CP_TOKEN:      return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case PLUS_TOKEN:    return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case MINUS_TOKEN:   return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case MUL_TOKEN:     return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	case DIV_TOKEN:     return automat.reduce(new NoTerminalSymbolFact(),1);
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State40::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAddOp(), 5);
	default:
		break;
	}
}
//implementation of the State41 class methods
State41 :: State41(const char* name) : State(name)
{
}

void State41 ::print()
{
	State::print();
}

bool State41 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case ID_TOKEN: return automat.shift(s,new State39("Etat 39"));
		break;
    case NUM_TOKEN: return automat.shift(s,new State40("Etat 40"));
		break;
	case OP_TOKEN: return automat.shift(s,new State41("Etat 41"));
		break;
	case TOKEN_EXPR: return automat.shift(s,new State46("Etat 46"));
		break;
	case TOKEN_TERM: return automat.shift(s,new State34("Etat 34"));
		break;
    case TOKEN_FACT: return automat.shift(s,new State42("Etat 42"));
		break;
	default    :errorDiagnostic(automat);
	
    }
    return false;
}

void State41::errorDiagnostic(Automat &a)
{
	Error::syntaxError(EXPR_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new NumberSymbol(0));
		a.pushSymbol(new ClosingParenthesisSymbol());
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAddOp(), 8);
	default:
		break;
	}
}
//implementation of the State42 class methods
State42 :: State42(const char* name) : State(name)
{
}

void State42 ::print()
{
	State::print();
}

bool State42 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN:     return automat.reduce(new NoTerminalSymbolTerm(),1);
		break;
	case CP_TOKEN:      return automat.reduce(new NoTerminalSymbolTerm(),1);
		break;
	case PLUS_TOKEN:    return automat.reduce(new NoTerminalSymbolTerm(),1);
		break;
	case MINUS_TOKEN:   return automat.reduce(new NoTerminalSymbolTerm(),1);
		break;
	case MUL_TOKEN:     return automat.reduce(new NoTerminalSymbolTerm(),1);
		break;
	case DIV_TOKEN:     return automat.reduce(new NoTerminalSymbolTerm(),1);
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State42::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
}
//implementation of the State43 class methods
State43 :: State43(const char* name) : State(name)
{
}

void State43 ::print()
{
	State::print();
}

bool State43 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN:     return automat.reduce(new NoTerminalSymbolExpr(),3);
		break;
	case CP_TOKEN:      return automat.reduce(new NoTerminalSymbolExpr(),3);
		break;
	case PLUS_TOKEN:    return automat.reduce(new NoTerminalSymbolExpr(),3);
		break;
	case MINUS_TOKEN:   return automat.reduce(new NoTerminalSymbolExpr(),3);
		break;
	case MUL_TOKEN: return automat.shift(s,new State35("Etat 35"));
		break;
	case DIV_TOKEN: return automat.shift(s,new State36("Etat 36"));
		break;
	case TOKEN_MULOP: return automat.shift(s,new State38("Etat 38"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State43::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolMulOp(), 6);
	default:
		break;
	}
}
//implementation of the State44 class methods
State44 :: State44(const char* name) : State(name)
{
}

void State44 ::print()
{
	State::print();
}

bool State44 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN:     return automat.reduce(new NoTerminalSymbolTerm(),3);
		break;
	case CP_TOKEN:      return automat.reduce(new NoTerminalSymbolTerm(),3);
		break;
	case PLUS_TOKEN:    return automat.reduce(new NoTerminalSymbolTerm(),3);
		break;
	case MINUS_TOKEN:   return automat.reduce(new NoTerminalSymbolTerm(),3);
		break;
	case MUL_TOKEN:     return automat.reduce(new NoTerminalSymbolTerm(),3);
		break;
	case DIV_TOKEN:     return automat.reduce(new NoTerminalSymbolTerm(),3);
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State44::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
}
//implementation of the State45 class methods
State45 :: State45(const char* name) : State(name)
{
}

void State45 ::print()
{
	State::print();
}

bool State45 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN:     return automat.reduce(new NoTerminalSymbolAff(),3);
		break;
	case PLUS_TOKEN: return automat.shift(s,new State32("Etat 32"));
		break;
	case MINUS_TOKEN: return automat.shift(s,new State33("Etat 33"));
		break;
	case TOKEN_ADDOP: return automat.shift(s,new State37("Etat 37"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State45::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
	switch (*a.ignoreSymbolsToInst())
	{
		a.pushSymbol(new SemicolonSymbol());
		a.reduce(new NoTerminalSymbolAff(), 4);
	default:
		break;
	}
}
//implementation of the State46 class methods
State46 :: State46(const char* name) : State(name)
{
}

void State46 ::print()
{
	State::print();
}

bool State46 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case CP_TOKEN: return automat.shift(s,new State47("Etat 47"));
		break;
	case PLUS_TOKEN: return automat.shift(s,new State32("Etat 32"));
		break;
	case MINUS_TOKEN: return automat.shift(s,new State33("Etat 33"));
		break;
	case TOKEN_ADDOP: return automat.shift(s,new State37("Etat 37"));
		break;
	default    :errorDiagnostic(automat);

    }
    return false;
}

void State46::errorDiagnostic(Automat &a)
{
	Error::syntaxError(CP_OP_EXPECTED);
}
//implementation of the State47 class methods
State47 :: State47(const char* name) : State(name)
{
}

void State47 ::print()
{
	State::print();
}

bool State47 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {
	case SEM_TOKEN:     return automat.reduce(new NoTerminalSymbolFact(),3);
		break;
	case CP_TOKEN:      return automat.reduce(new NoTerminalSymbolFact(),3);
		break;
	case PLUS_TOKEN:    return automat.reduce(new NoTerminalSymbolFact(),3);
		break;
	case MINUS_TOKEN:   return automat.reduce(new NoTerminalSymbolFact(),3);
		break;
	case MUL_TOKEN:     return automat.reduce(new NoTerminalSymbolFact(),3);
		break;
	case DIV_TOKEN:     return automat.reduce(new NoTerminalSymbolFact(),3);
		break;
	default    :errorDiagnostic(automat);


    }
    return false;
}

void State47::errorDiagnostic(Automat &a)
{
	Error::syntaxError(SEM_EXPECTED);
}
