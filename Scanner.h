#include "lutin.h"

#ifndef __SCANNER_CLASS_
#define __SCANNER_CLASS_
#endif

// Les mots clé
#define WORDS_NUM 38

namespace lutinCompiler
{
	// Le numéro de la ligne en cours d'analyse
	static int LINE_NUMBER = 0;
	// Le numéro du caractère en cours d'analyse
	static int CARACTER_NUMBER = 0;

	// Les mots clés du langage
	const char key_word[WORDS_NUM][IDF_LENGTH] = {  "var", "const", "ecrire", "lire" };

	class Scanner
	{
	public:
		/*
		 * Constructeur 
		 */
		Scanner();

		/*
		 * Déstructeur : femeture du fichier
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
		 * Methode qui crée le symbole correspant aux mots clés en fonction du token passé en paramètre
		 * @param: TOKEN
		 * @access: private
		 * @return: void
		 */
	     static Symbol* createSymbol(TOKEN);

	private:
		/*
		 * Methode qui lit les mots clés Mot clé [var, const, ecrire, lire]
		 * Si le mot qui était lu n'appartient pas à la liste des mots clés donc c'est un identificateur user 
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
		 * Methode qui lit et ignore les caractères d'espacements
		 * @access: private
		 * @return: void
		 */
		void readSpaces();

		/*
		 * Methode qui lit le caractère suivant dans le flux de données
		 * @access: private
		 * @return: boolean [true: si la fin du fichier, false: le flux contient encore des caractères]
		 */
		bool nextCaracter();

		/*
		 * Methode qui charger le fichier
		 * @param: const char* le nom du fichier
		 * @access: private
		 * @return: bool [true: le fichier est bien chargé, false: erreur d'ouverture du fichier]
		 */
		//bool load(const char*);

		// Fichier
		FILE * fileStream;

		// Caractère courrant
		char currentCaracter;
	};

};