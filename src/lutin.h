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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

// La taille d'un identificateur
#define IDF_LENGTH 50
// Le nombre max de chiffres dans un nombre
#define NUMBER_LENGTH 20

// Les unités lexicals
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

//*************************** Les bibliothèques ********************//
#include "Identificator.h"
//#include "Instruction.h"
//#include "Expression.h"
#include "Symbol.h"
#include "State.h"
// Les symboles fils
#include "DecState.h"
#include "VarState.h"
#include "ConstState.h"
#include "InstState.h"
// L'analyseur lexical
#include "Scanner.h"
#include "Error.h"

// Définir la pile des symboles 
typedef stack<lutinCompiler::Symbol*> StackSymbol;
// Définir la pile des états
typedef stack<lutinCompiler::State*> StackState;
// Définir la table des identificateurs
typedef map<string, lutinCompiler::Identificator*> IdentificatorList;
typedef map<string, lutinCompiler::Identificator*>::iterator IteratorIdf;


namespace lutinCompiler
{
	class Automat 
	{
	public:
		/*
		 * Constrcuteur: on empile l'état initiale dans la pile des états
		 */
		Automat()
		{
			stats.push(new State0("Etat Initiale"));
		}

		/*
		 * Méthode qui démarre l'analyse 
		 * @param: const char* le nom du fichier
		 * @return: void
		 * @exception: ERROR
		 */
		void analyse(const char * filename)
		{
			scanner.load(filename);

			Symbol * s = scanner.getCurrentSymbol();

			if (stats.top()->transition(*this, s))
			{
				symbols.top()->print();

				cout << endl << "Ok! Votre code est correcte :)...";
			}
		}


		/*
		 * Méthode qui décale vers une autre état 
		 * @return: void
		 * @exception: ERROR
		 */
		bool shift(Symbol * s, State *state)
		{
			stats.push(state);

			if (*s <= 16)
			{
				symbols.push(s);
				s = scanner.nextSymbol();
			}
			else

				s = scanner.getCurrentSymbol();

			return stats.top()->transition(*this, s);
		}

		/*
		 * Méthode qui fait la réduction d'une régle
		 * @return: void
		 * @exception: ERROR
		 */
		bool reduce(NoTerminalSymbol *s, int popNumber)
		{
			// Une liste temporaire des symbols destinés pour la construction de l'arbre abstrait
			SymbolList * listSymbols = new SymbolList();

			// dépiler popNumber symboles et états
			for (int i=0; i < popNumber; i++)
			{
				(*listSymbols)[i] = symbols.top();

				stats.pop();
				symbols.pop();
			}

			

			// Construction de l'arbre abstrait en ignorant les epsilons construction
			if (popNumber > 0)
			{
				// Empiler le symbole
				symbols.push(s);

				s->construct(*listSymbols);
				getchar();
				
				delete listSymbols;

				listSymbols = new SymbolList();
			}
			else

				symbols.push(nullptr);

			// Faire la transition de l'etat en sommet de la pile avec le SYMBOLE non terminal s
			if (*s != TOKEN_P)
			
				return stats.top()->transition(*this, s);
			
			else
				// Arrêter l'analyse avec succé
				return true;
		}

		/** 
		  Méthode qui va ignorer les symbols jusqu'à le symbole passé en paramètre
		  @param: TOKEN token
		  @return: bool [true] si le symbole est token [false] sinon
		  @access: public
		 */
		bool ignoreSymbolsTo(TOKEN token)
		{
			while (*scanner.nextSymbol() != token && *scanner.nextSymbol() != EOF_TOKEN);

			return *scanner.getCurrentSymbol() == token;
		}

		/**
		 Méthode qui ajout un identificateur à la table
		 @param: Identificator* idf
		 @return: bool
		 */
		bool addIdentificator(Identificator *idf)
		{
			// Si l'identificateur existe déjà dans la liste afficher l'erreur correspant
			if (identificators.find(idf->getName()) != identificators.end())
			{
				Error::semanticError(IDF_ALEARDY_EXIST, idf->getName());
				return false;
			}
			// Ajouter l'identificateur dans la liste
			else
			{
				identificators[idf->getName()] = idf;
				return true;
			}
		}

		/**
		 Méthode qui vérifier si un identificateur est déjà déclaré
		 @param: Identificator* idf
		 @return: bool
		 */
		bool verifyIdentificator(Identificator *idf)
		{
			// Si l'identificateur n'existe déjà dans la liste afficher l'erreur correspant
			if (identificators.find(idf->getName()) == identificators.end())
			{
				Error::semanticError(IDF_NOT_DECLARED, idf->getName());
				return false;
			}
			else
				return true;
		}


	private:
		StackState stats;
		StackSymbol symbols;
		IdentificatorList identificators;
//		AbstractTree tree;
		Scanner scanner;
	};

}