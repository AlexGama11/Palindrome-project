#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

//variables for the program.
//input string.
std::string input;

//output string, this will just be an unmodified copy, so if a user input a text in upper case, it comes out as upper case.
std::string output;

//bool to see if it is a palindrome or not.
bool isPalindrome;

//bool for program loop.
bool isProgramRunning = true;

char uneededChars[] = "/,.-)($£!€^&*'@#~`[]{}¦|-\\_+=";

int main()
{
	//Set's console title.
	SetConsoleTitleW(L"Alex's Palindrome Checker!");

	while (isProgramRunning)
	{
		//ask user for input
		std::cout << "Welcome! Input a text to check if it's a palindrome or not! Press enter to exit!" << std::endl;

		//uses getline to allow for inputs like Taco Cat, which are palindromes that have a space
		std::getline(std::cin, input);

		//if input is nothing (user clicked enter) > end the program
		if (input.length() == 0)
		{
			std::cout << "Bye!" << std::endl;
			isProgramRunning = false;
		}

		//else, check if palindrome
		else
		{
			//copies input into output as is, so the program can spit it out later as the user input it, and not forced lower case.
			output = input;

			for (int i = 0; i < sizeof(uneededChars); i++)
			{
				input.erase(std::remove(input.begin(), input.end(), uneededChars[i]), input.end());
			}
			

			// forloop as long as the input's length
			for (int x = 0; x < input.length(); x++)
			{
				//forces it to be lowercase, so it can check if its a palindrome, without it Taco cat is not seen as a palindrome, but taco cat is.
				input[x] = std::tolower(input[x]);

				//if the first letter is equal to the last one -> palindrome, if not, not a palindrome. It checks all letters due to the loop. Its input.length() - x - 1 because there's an extra character at the end of every input, which must be skipped.
				if (input[x] == input[input.length() - x - 1])
				{
					isPalindrome = true;
				}

				else
				{
					isPalindrome = false;
					x = input.length();
				}
			}

			//if palindrome -> output is palindrome, else its not a palindrome. Clears cin after for no errors with while loop.
			if (isPalindrome)
			{
				std::cout << output << " is a palindrome, that's " << output.length() << " characters long!\n" << std::endl;
				std::cin.clear();
			}

			else
			{
				std::cout << output << " is NOT a palindrome, but it's " << output.length() << " characters long!\n" << std::endl;
				std::cin.clear();
			}
		}

	}
	return 0;
}
