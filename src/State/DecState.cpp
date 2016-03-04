#include "lutin.h"
#include "DecState.h"

using namespace lutinCompiler;

//implementation of the State5 class methods
State0 :: State0(string name) : State(name)
{
}

void State0 ::print()
{
    cout<<name;
}

State0 ::~State()
{

}

bool State0 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {

    }
    return false;
}

//implementation of the State8 class methods
State1 :: State1(string name) : State(name)
{
}

void State1 ::print()
{
    cout<<name;
}

State8 ::~State()
{

}

bool State2 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {

    }
    return false;
}

//implementation of the State9 class methods
State3 :: State9(string name) : State(name)
{
}

void State3 ::print()
{
    cout<<name;
}

State3 ::~State()
{

}

bool State3 ::transition(Automat &automat, Symbol *s)
{
    switch(*s)
    {

    }
    return false;
}


