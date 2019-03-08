#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include <thread>
#include<windows.h>
using namespace std;

void type_text(const std::string& text)
{
	// loop through each character in the text
	for (std::size_t i = 0; i < text.size(); ++i)
	{
		// output one character
		// flush to make sure the output is not delayed
		std::cout << text[i] << std::flush;

		// sleep 60 milliseconds
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
}

int main()
{
	// Declaring my words to be scrambled, as well as the corresponding hint to go with them
	enum fields {Word, Hint, Num_Fields}; // Array containing the word, the hint, and the number of fields
	const int Num_Words = 10; // Number of words = 10
	const string Words[Num_Words][Num_Fields] = // Actual array
	{
		{"league", "Defined as 3 miles in the US"},
		{"friends", "The people you spend your free time with"},
		{"videogame", "Very large part of culture here at UAT, a form of entertainment"},
		{"university", "Education after highschool, U in UAT"},
		{"phone", "Communication device, nowadays it's a pocket computer"},
		{"hakunamatata", "Techinically two words without a space; It means no worries"},
		{"resource", "A stock or supply of material to be used"},
		{"oxygen", "Very valuable to human beings; a gas"},
		{"petrichor", "The smell after it rains"},
		{"poison", "You're often asked to pick it; toxic"}
	};

	// Picking a random word, as well as it's corresponding hint
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % Num_Words);
	int wordNum = 0;
	string theWord = Words[choice][Word];
	string theHint = Words[choice][Hint];
	char input1;

	// Jumbling the Word
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	type_text("Welcome to the Code Breaker Training Simulation.\n");
	Sleep(1000);
	type_text("You might not know where you are right now, or how you got here, but please try not to think about it.\n");
	Sleep(1000);
	type_text("You are here to train in becoming an expert CodeBreaker.\n");
	Sleep(1000);
	type_text("Please type a character and press enter to confirm you understand. \n");
	cin >> input1;
	type_text("Excellent, let's begin your training.\n");
	Sleep(1000);
	type_text("You will be provided with a jumbled word. Please try your best to unjumble it.\n");
	Sleep(1000);
	type_text("If you are stuck and in need of a hint, please type the word 'hint'.\n");
	Sleep(1000);
	type_text("Here is your jumbled word.\n");
	cout << jumble << endl;
	string guess;
	type_text("Enter your guess, or request a hint.\n");
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			type_text(theHint);
		}
		else
		{
			type_text("That is not the answer, try again.");
		}
		type_text("Enter your guess, or request a hint.\n");
			cin >> guess;
	}

	if ((guess == theWord) && wordNum != 3)
	{
		type_text("\n\nPerfect! You guessed the word.\n");
		type_text("Here is your next word.");
		wordNum++;
	}
	if ((guess == theWord) && wordNum == 3)
	{
		type_text()
	}
	system("Pause");
}