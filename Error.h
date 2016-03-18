#include "lutin.h"

namespace lutinCompiler
{
	// Les erreurs lexicals
	static enum SCANNER_ERROR
	{
		FILE_NOT_EXIST, 
		IDF_VERY_LARGE, 
		UNDIFINED_CARACTER,  
		EMPTY_FILE, 
		NUMBER_VERY_LONG, 
		COMMENT_NOT_CLOSED
	};

	// Les erreurs syntaxiques
	static enum ANALYSER_ERROR
	{
		VAR_CONST_EXPECTED,
		INSTRUCTION_EXPECTED,
		INST_DEC_EXPECTED,
		IDF_EXPECTED,
		SEM_EXPECTED,
		SEM_COM_EXPECTED,
		EQ_EXPECTED,
		NUM_EXPECTED,
		AFF_EXPECTED,
		EXPR_EXPECTED,
		DELETE_TOKEN,
		CP_OP_EXPECTED
	};

	// Les erreurs sémantiques
	static enum SEMANTIC_ERROR
	{
		IDF_ALEARDY_EXIST,
		IDF_NOT_DECLARED
	};

	class Error final : public exception
	{
	public:

		static void ScannerError(SCANNER_ERROR error)
		{
			cerr << "Erreur(" << Scanner::LINE_NUMBER << ":" << Scanner::CARACTER_NUMBER << ") ";

			switch (error)
			{
			case FILE_NOT_EXIST:
				cerr << "Le fichier spécifié n'existe pas!";
				exit(EXIT_FAILURE);
			break;
			case IDF_LENGTH:
				cerr << "La taille d'identificateur est trop large, le nombre maximal des caractères " << IDF_LENGTH;
			break;
			case UNDIFINED_CARACTER:
				cerr << "Ce type de caractère n'est pas autorisé";
			break;
			case EMPTY_FILE:
				cerr << "Le fichier spécifié est vide!";
				exit(EXIT_FAILURE);
			break;
			case NUMBER_LENGTH:
				cerr << "Le nombre est trop grand, le nombre maximal des chiffres est " << NUMBER_LENGTH;
			break;
			case COMMENT_NOT_CLOSED:
				cerr << "Un commentaire qui n'était pas fermé";
			}

			cerr << endl;
		}

		static void syntaxError(ANALYSER_ERROR error)
		{
			cerr << "Erreur(" << Scanner::LINE_NUMBER << ":" << Scanner::CARACTER_NUMBER << ") ";
		
			switch(error)
			{
			case VAR_CONST_EXPECTED:
				cerr << "mots-clé 'var' ou 'const' attendu.";
			break;
			case INSTRUCTION_EXPECTED:
				cerr << "instruction attendu.";
			break;
			case INST_DEC_EXPECTED:
				cerr << "instruction ou déclaration attendu.";
			break;
			case IDF_EXPECTED:
				cerr << "identificateur attendu.";
			break;
			case SEM_EXPECTED:
				cerr << "';' attendu.";
			break;
			case SEM_COM_EXPECTED:
				cerr << "';' ou ',' attendu.";
			break;
			case EQ_EXPECTED:
				cerr << "'=' attendu.";
			break;
			case NUM_EXPECTED:
				cerr << "valeur attendu.";
			break;
			case AFF_EXPECTED:
				cerr << "':=' attendu.";
			break;
			case EXPR_EXPECTED:
				cerr << "expression attendu.";
			break;
			case DELETE_TOKEN:
				cerr << "symbole inattendu.";
			break;
			case CP_OP_EXPECTED:
				cerr << "')' ou opérateur attendu.";
			break;
			}

			cerr << endl;
		}

		static void semanticError(SEMANTIC_ERROR error, string name)
		{
			cerr << "Erreur(" << Scanner::LINE_NUMBER << ":" << Scanner::CARACTER_NUMBER << ") ";
		
			switch(error)
			{
			case IDF_ALEARDY_EXIST:
				cerr << "l'identificateur \"" << name << "\" est redéclaré";
			break;
			case IDF_NOT_DECLARED:
				cerr << "l'identificateur \"" << name << "\" non déclaré";
			break;
			}

			cerr << endl;
		}
	};

}