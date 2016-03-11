#pragma once

#if defined(_MSC_VER)

	#ifndef _CRT_SECURE_NO_DEPRECATE
	#define _CRT_SECURE_NO_DEPRECATE (1)
	#endif

	#pragma warning(disable : 4996)

#endif

#ifndef __LUTIN_COMPILER_NAMESPACE_
#define __LUTIN_COMPILER_NAMESPACE_
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <stack>

using namespace std;

// La taille d'un identificateur
#define IDF_LENGTH 50
// Le nombre max de chiffres dans un nombre
#define NUMBER_LENGTH 20

// Les unit�s lexicals
enum TOKEN {    // Les symboles terminals
				VAR_TOKEN, CONST_TOKEN, 
			    WRITE_TOKEN, READ_TOKEN, 
				ID_TOKEN, NUM_TOKEN,
				AFF_TOKEN, SEM_TOKEN, COM_TOKEN, EQ_TOKEN, OP_TOKEN, CP_TOKEN, 
				PLUS_TOKEN, MINUS_TOKEN, MUL_TOKEN, DIV_TOKEN, 
				EOF_TOKEN,
				// Les symboles non-terminaux
				TOKEN_P, TOKEN_DEC, 
				TOKEN_VAR_D, TOKEN_CONST_D, TOKEN_VAR, TOKEN_CONST, 
				TOKEN_INSTS, TOKEN_INST, 
				TOKEN_AFF, TOKEN_WRITE, TOKEN_READ, TOKEN_EXPR, 
				TOKEN_TERM, TOKEN_FACT, TOKEN_ADDOP, TOKEN_MULOP
		   };

//*************************** Les biblioth�ques ********************//
#include "Symbol.h"
#include "State.h"
// Les symboles fils
#include "DecState.h"
#include "VarState.h"
#include "ConstState.h"
#include "InstState.h"

#include "Scanner.h"
#include "Error.h"

// D�finir  la pile des symboles 
typedef stack<lutinCompiler::Symbol*> StackSymbol;
// D�finir la pile des �tats
typedef stack<lutinCompiler::State*> StackState;

namespace lutinCompiler
{
	class Automat 
	{
	public:
		/*
		 * Constrcuteur: on empile l'�tat initiale dans la pile des �tats
		 */
		Automat()
		{
			//stats.push(new State0("Etat Initiale"));
		}

		/*
		 * M�thode qui d�marre l'analyse 
		 * @param: const char* le nom du fichier
		 * @return: void
		 * @exception: ERROR
		 */
		void analyse(const char * filename)
		{
			scanner.load(filename);

			Symbol * s = nullptr;

			shift(s, new State0("Etat initial"));

			/*do
			{
				s = scanner.nextSymbol();
				s->print();
			}
			while (*s != EOF_TOKEN);*/
		}


		/*
		 * M�thode qui d�cale vers une autre �tat 
		 * @return: void
		 * @exception: ERROR
		 */
		void shift(Symbol * s, State *state)
		{
			stats.push(state);

			if (s == nullptr)
			{
				s = scanner.nextSymbol();
			}
			else
			{	
				if (*s <= 16)
				{
					s = scanner.nextSymbol();
					
				}

				symbols.push(s);
			}

			// temporaire
			cout << "Transition: ";
			stats.top()->print();

			stats.top()->transition(*this, s);
		}

		/*
		 * M�thode qui fait la r�duction d'une r�gle
		 * @return: void
		 * @exception: ERROR
		 */
		void reduce(Symbol *s, int popNumber)
		{
			// d�piler popNumber symboles et �tats
			for (int i=0; i < popNumber; i++)
			{
				stats.pop();
				symbols.pop();
			}

			// Construction de l'arbre

			// Empiler le symbole
			//symbols.push(symbols.top());

			// Faire la transition de l'etat en sommet de la pile avec le SYMBOLE non terminal s
			stats.top()->transition(*this, symbols.top());
		}


	private:
		StackState stats;
		StackSymbol symbols;
		Scanner scanner;
	};

}