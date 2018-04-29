#include <iostream>
#include "Dictionary.h"

using namespace std;

/*-------------------------Function declaration-------------------------*/
string generateSentence(Dictionary &dictionary);
string generateNounPhrase(Dictionary &dictionary);
string generateVerbPhrase(Dictionary &dictionary);
string generatePrepPhrase(Dictionary &dictionary);

int main()
{
	//Title and purpose 
	cout << "Sentence Generator Machine" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "The purpose of the program is to generate random English sentences that contain specific words." << endl;
	cout << "The sentence is grammatically correct but it will not always make sense." << endl;
	cout << "---------------------------------------------" << endl;

	int answer = 0;
	do
	{
		cout << "Choose an option" << endl;
		cout << "1. Generate Random Sentence" << endl;
		cout << "2. Quit" << endl;
		cin >> answer;
		cout << endl;

		while (cin.fail() || answer < 1 || answer > 2) //Check input
		{
			cin.clear();
			cin.ignore(999, '\n');
			cout << "Enter a valid number" << endl;
			cin >> answer;
		}

		if (answer == 1)
		{
			Dictionary myDictionary("nounlist.txt", "verblist.txt", "adverblist.txt", "adjectivelist.txt", "prepositionlist.txt", "articlelist.txt");
			cout << generateSentence(myDictionary) << endl;
			cout << endl;
		}

	} while (answer == 1);

	cout << endl;
	system("pause");
	return 0;
}

/*-------------------------Function definition-------------------------*/
//Generate sentence
string generateSentence(Dictionary &dictionary)
{
	return generateNounPhrase(dictionary) + " " +generateVerbPhrase(dictionary);
}

//Generate noun phrase
string generateNounPhrase(Dictionary &dictionary)
{
	int num = rand() % 3 + 1;

	switch (num)
	{
		//Base case
		case 1:
			return dictionary.getNoun()+ " ";
			break;
		case 2:
			return dictionary.getArticle() + " " + dictionary.getNoun();
			break;
		//Recursive case
		case 3:
			return generateNounPhrase(dictionary) + " " + generatePrepPhrase(dictionary);
			break;
	}
}

//Generate verb phrase
string generateVerbPhrase(Dictionary &dictionary)
{
	int num = rand() % 4 + 1;

	switch (num)
	{
		//Base case
		case 1:
			return dictionary.getVerb()+ " ";
			break;
		//Recursive case
		case 2:
			return generateVerbPhrase(dictionary) + " " + generateNounPhrase(dictionary);
			break;
		//Recursive case
		case 3:
			return generateVerbPhrase(dictionary) + " " + dictionary.getAdjective();
			break;
		//Recursive case
		case 4:
			return generateVerbPhrase(dictionary) + " " + dictionary.getAdverb();
			break;
	}
}

//Generate preposition
string generatePrepPhrase(Dictionary &dictionary)
{
	return dictionary.getPreposition() + " " + generateNounPhrase(dictionary);
}