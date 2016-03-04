#include "Symbol.h"

Symbol :: Symbol(TOKEN token)
{
    this->token=token;
}
Symbol :: ~Symbol()
{

}
void Symbol :: print()
{

}

int  Symbol :: operator int() const
{
    return token;
}
