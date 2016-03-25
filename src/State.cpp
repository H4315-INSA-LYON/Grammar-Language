#include "lutin.h"

using namespace lutinCompiler;

State::State(const char* name)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

State::~State()
{
	delete name;
}

void State::print()
{
	cout << name << endl;
}