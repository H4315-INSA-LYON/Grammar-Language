#include "lutin.h"

using namespace lutinCompiler;

int Scanner::LINE_NUMBER, Scanner::CARACTER_NUMBER;

/*
 * Constructeur 
 */
Scanner::Scanner()
{
	LINE_NUMBER = 1;
	CARACTER_NUMBER = -1;
	fileStream = nullptr;
	currentSymbol = nullptr;
}

/*
 * Déstructeur : femeture du fichier
 */
Scanner::~Scanner()
{
	fclose(fileStream);
}

/*
 * Methode qui crée le symbole correspant aux mots clés en fonction du token passé en paramètre
 * @param: TOKEN
 * @access: private
 * @return: void
 */
Symbol* Scanner::createSymbol(TOKEN num)
{
	switch (num)
	{
	case VAR_TOKEN: return new VarSymbol(); break;
	case CONST_TOKEN: return new ConstSymbol(); break;
	case WRITE_TOKEN: return new WriteSymbol(); break;
	case READ_TOKEN: return new ReadSymbol(); break;
	}

	return nullptr;
}

/*
 * Methode Lire le symbole suivant 
 * @access: public
 * @return: Symbole*
 */
Symbol* Scanner::nextSymbol()
{
	// Ignorer les espacements
	readSpaces();

	// Ignorer les commentaires
	if (currentCaracter == '{')
					
		readComments();

	// Lire un mots
	// Identificateur: expr~ [A-Z|a-z][A-Z|a-Z|0-9|_]*
	if (isalpha(currentCaracter))
	
		return readWords();

       
	// Lire un nombre
	// Nombre: expr~ [0-9]+
	if (isdigit(currentCaracter))
	
		return readNumber();
    
	// Les caractére spéciaux
	switch(currentCaracter)
	{
		// Addition
		case '+': 
					nextCaracter();
					currentSymbol = new PlusSymbol();
		break; 
		// Soustraction
		case '-': 
					nextCaracter();
					currentSymbol = new MinusSymbol();
		break; 
		// Multiplication
		case '*': 
					nextCaracter();
					currentSymbol = new MuliplicationSymbol();
		break; 
		// Division
		case '/': 
					nextCaracter();
					currentSymbol = new DivisionSymbol();
		break; 
		// Point virgule
		case ';': 
					nextCaracter(); 
					currentSymbol = new SemicolonSymbol();
		break;
		// Virgule
		case ',': 
					nextCaracter();
					currentSymbol = new CommaSymbol();
		break;
		// Affectation pour les constantes
		case '=': 
					nextCaracter();
					currentSymbol = new EqualSymbol();
		break;
		// Affectation pour les identificateurs
		case ':':
					nextCaracter();
            
					if (currentCaracter == '=')
					{
						nextCaracter();
						currentSymbol = new  AffectationSymbol();
					}	
		break;
		// Prenthése ouvrante
		case '(': 
					nextCaracter();
					currentSymbol = new  OpeningParenthesisSymbol();
		break;  
		// Parenthése fermante
		case ')': 
					nextCaracter();
					currentSymbol = new  ClosingParenthesisSymbol();
		break;
		// Fin du flux
		case EOF: 
					currentSymbol = new  EOFSymbol();
		break;
		// Caractère inacceptable
		default: 
					throw UNDIFINED_CARACTER;   
	}
	return currentSymbol;
}

/*
 * Methode qui lit les mots clés Mot clé [var, const, ecrire, lire]
 * Si le mot qui était lu n'appartient pas à la liste des mots clés donc c'est un identificateur user 
 * @access: private
 * @return: Symbol*
 */
Symbol* Scanner::readWords()
{
	char strname[IDF_LENGTH];
	int i=0;
    
	strname[i++] = currentCaracter;
	nextCaracter();
    
	while (isalnum(currentCaracter) || currentCaracter == '_')
	{
		strname[i++] = currentCaracter;
		nextCaracter();
	}
    
	if (i >= IDF_LENGTH)
    
		throw IDF_VERY_LARGE;
          
	strname[i] = '\0';
	i = 0;
    
	while (i < WORDS_NUM)
       
		if (!stricmp(strname, key_word[i]))
		{
			currentSymbol = createSymbol((TOKEN)i);
			return currentSymbol;
		}
		else
          
			i++;
           
	currentSymbol = new IdentificatorSymbol(strname);

	return currentSymbol;
}

/*
 * Methode qui lit une suite de chiffre pour obtenir un nombre
 * @access: private
 * @return: Symbol*
 */
Symbol* Scanner::readNumber()
{
	char strname[IDF_LENGTH];
	int i=0;
         
	do
	{
		strname[i++] = currentCaracter;
		nextCaracter();      
	}
	while (isdigit(currentCaracter));

	if (i >= NUMBER_LENGTH)
		 
		throw NUMBER_VERY_LONG;

	strname[i] = '\0';

	// Affecation des tokens
	currentSymbol = new NumberSymbol(atoi(strname));

	return currentSymbol;
}

/*
 * Methode qui lit et ignore les commentaires
 * @access: private
 * @return: void
 */
void Scanner::readComments()
{
	nextCaracter();

	if (currentCaracter == '*')

		nextCaracter();

	do
	{
		while (currentCaracter != '*' && currentCaracter != EOF)
		{
			nextCaracter();
			if (currentCaracter == '\n') LINE_NUMBER++;
		}

		nextCaracter();
		if (currentCaracter == '\n') LINE_NUMBER++;

	}
	while (currentCaracter != '}' && currentCaracter != EOF);

	if (currentCaracter == EOF)

		throw COMMENT_NOT_CLOSED;

	nextCaracter();

	// Ignorer les espacements
	readSpaces();
}

/*
 * Methode qui lit et ignore les caractères d'espacements
 * @access: private
 * @return: void
 */
void Scanner::readSpaces()
{
	if (currentCaracter == '\n') 
	{
		++LINE_NUMBER;
		CARACTER_NUMBER = -1;
	}

	// ignorer les espacement
	while (isspace(currentCaracter))
	{
		nextCaracter();
		if (currentCaracter == '\n')
		{
			++LINE_NUMBER;
			CARACTER_NUMBER = -1;
		}
	}
}

/*
 * Methode qui lit le caractère suivant dans le flux de données
 * @access: private
 * @return: boolean [true: si la fin du fichier, false: le flux contient encore des caractères]
 */
bool Scanner::nextCaracter()
{
	// lire le caractère dans le flux de données
	currentCaracter = fgetc(fileStream);
	++CARACTER_NUMBER;

	return currentCaracter != EOF;
}

/*
 * Methode qui charger le fichier
 * @param: const char* le nom du fichier
 * @access: private
 * @exception: ERROR::FILE_NOT_EXIST, ERROR::EMPTY_FILE
 */
void Scanner::load(const char* filename)
{
	// ouvrire le fichier à analyser 
	this->fileStream = fopen(filename, "r");
	
	if (fileStream == nullptr)
		
		throw FILE_NOT_EXIST;

	else
	{
		nextCaracter();

		if (*nextSymbol() == EOF_TOKEN)

			throw EMPTY_FILE;
	}
}

/*
 * Getteur de symbole courrant
 * @access: public
 * @return: Symbole*
 */
Symbol* Scanner::getCurrentSymbol()
{
	return currentSymbol;
}