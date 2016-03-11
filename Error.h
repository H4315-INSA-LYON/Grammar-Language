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

	class Error final : public exception
	{
	public:

		static void ScannerError(SCANNER_ERROR error)
		{
			cerr << "Erreur-" << error << " � la ligne (" << LINE_NUMBER << ":" << CARACTER_NUMBER << "): ";

			switch (error)
			{
			case FILE_NOT_EXIST:
				cerr << "Le fichier sp�cifi� n'existe pas!";
				exit(EXIT_FAILURE);
			break;
			case IDF_LENGTH:
				cerr << "La taille d'identificateur est trop large, le nombre maximal des caract�res " << IDF_LENGTH;
			break;
			case UNDIFINED_CARACTER:
				cerr << "Ce type de caract�re n'est pas autoris�";
			break;
			case EMPTY_FILE:
				cerr << "Le fichier sp�cifi� est vide!";
				exit(EXIT_FAILURE);
			break;
			case NUMBER_LENGTH:
				cerr << "Le nombre est trop grand, le nombre maximal des chiffres est " << NUMBER_LENGTH;
			break;
			case COMMENT_NOT_CLOSED:
				cerr << "Un commentaire qui n'�tait pas ferm�";
			}
		}
	};

}