#include "lutin.h"

#ifndef __SCANNER_CLASS_
#define __SCANNER_CLASS_
#endif

// Les mots cl�
#define WORDS_NUM 38

namespace lutinCompiler
{
	// Le num�ro de la ligne en cours d'analyse
	static int LINE_NUMBER = 0;
	// Le num�ro du caract�re en cours d'analyse
	static int CARACTER_NUMBER = 0;

	// Les mots cl�s du langage
	const char key_word[WORDS_NUM][IDF_LENGTH] = {  "var", "const", "ecrire", "lire" };

	class Scanner
	{
	public:
		/*
		 * Constructeur 
		 */
		Scanner();

		/*
		 * D�structeur : femeture du fichier
		 */
		~Scanner();

		/*
		 * Methode qui charger le fichier
		 * @param: const char* le nom du fichier
		 * @access: private
		 * @exception: ERROR::FILE_NOT_EXIST, ERROR::EMPTY_FILE
		 */
		void load(const char*);

	   /*
		* Methode Lire le symbole suivant 
		* @access: public
		* @return: Symbole*
		*/
		Symbol* nextSymbol();

		/*
		 * Methode qui cr�e le symbole correspant aux mots cl�s en fonction du token pass� en param�tre
		 * @param: TOKEN
		 * @access: private
		 * @return: void
		 */
	     static Symbol* createSymbol(TOKEN);

	private:
		/*
		 * Methode qui lit les mots cl�s Mot cl� [var, const, ecrire, lire]
		 * Si le mot qui �tait lu n'appartient pas � la liste des mots cl�s donc c'est un identificateur user 
		 * @access: private
		 * @return: Symbol*
		 */
		Symbol* readWords();

		/*
		 * Methode qui lit une suite de chiffre pour obtenir un nombre
		 * @access: private
		 * @return: Symbol*
		 */
		Symbol* readNumber();

		/*
		 * Methode qui lit et ignore les commentaires
		 * @access: private
		 * @return: void
		 */
		void readComments();

		/*
		 * Methode qui lit et ignore les caract�res d'espacements
		 * @access: private
		 * @return: void
		 */
		void readSpaces();

		/*
		 * Methode qui lit le caract�re suivant dans le flux de donn�es
		 * @access: private
		 * @return: boolean [true: si la fin du fichier, false: le flux contient encore des caract�res]
		 */
		bool nextCaracter();

		/*
		 * Methode qui charger le fichier
		 * @param: const char* le nom du fichier
		 * @access: private
		 * @return: bool [true: le fichier est bien charg�, false: erreur d'ouverture du fichier]
		 */
		//bool load(const char*);

		// Fichier
		FILE * fileStream;

		// Caract�re courrant
		char currentCaracter;
	};

};