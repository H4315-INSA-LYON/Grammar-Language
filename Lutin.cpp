// Lutin.cpp�: d�finit le point d'entr�e pour l'application console.
//


#include "stdafx.h"

using namespace lutinCompiler;

int main(int argc, char* argv[])
{
	Automat a;
	try
	{
		a.analyse("test/correct.lt");
	}
	catch (SCANNER_ERROR num)
	{
		Error::ScannerError(num);
	}
	char c;
	cin >> c;
	return 0;
}

