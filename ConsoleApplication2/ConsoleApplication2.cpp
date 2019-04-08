
#include "pch.h"
#include <iostream>

bool GetWord(char* string, char* word, int& wordOffset);

int main()
{
	const int bufferSize = 255;
	char buffer[bufferSize + 1];
	char word[bufferSize + 1];
	int wordOffset = 0;

	std::cout << "Enter a string: ";
	std::cin.getline(buffer, bufferSize);

	while (GetWord(buffer, word, wordOffset))
	{
		std::cout << "Got this word: " << word << std::endl;;
	}
}


bool GetWord(char * string, char * word, int & wordOffset)
{
	if (!string[wordOffset])
		return false;

	char * p1, * p2;

	p1 = p2 = string + wordOffset;

	
//	std::cout << p1 << '\n';
//	std::cout << p2 << '\n';


//	std::cout << (int)strlen(p1) << '\n';
//	std::cout << !isalnum(p1[0]) << '\n';



	for (int i = 0; i < (int)strlen(p1) && !isalnum(p1[0]); i++)
		p1++;

	if (!isalnum(p1[0]))
		return false;

	p2 = p1;

	std::cout << p1 << '\n';
	std::cout << p2 << '\n';

	//Срезаем символы из p2 до тех пор, пока у нас число или буква Верхнего или нижнего регистра
	while (isalnum(p2[0]))
		p2++;

	int len = int(p2 - p1);

	std::cout << "After len: " << len << '\n';
	std::cout << "After p1: " << p1 << '\n';
	std::cout << "After p2: " << p2 << '\n';

	strncpy(word, p1, len);
//	std::cout << word << '\n';

	word[len] = '\0';
//	std::cout << word << '\n';

//	std::cout << p2-string << '\n';

	for (int i = int(p2 - string); i < (int)strlen(string) && !isalnum(p2[0]); i++)
		p2++;

	wordOffset = int(p2 - string);

	return true;
}
