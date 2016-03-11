#include "lutin.h"

using namespace lutinCompiler;

Symbol::operator int() const
{
	return token;
}