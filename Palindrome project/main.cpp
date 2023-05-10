#include <string>
#include <iostream>

//variables
std::string input;

bool isPalindrome;

bool isChecking = true;

std::string answer;

//main function
int main()
{
	while (isChecking)
	{
		//starting message
		std::cout << "Welcome! Input a word and we'll determine if it's a palindrome or not! Press enter to exit!" << std::endl;

		//getting the input
		std::getline(std::cin, input);

		//Check if enter key is pressed. If it is pressed, exit the loop.
		if (input.length() == 0)
		{
			isChecking = false;

			std::cout << "Bye!" << std::endl;
		}

		else
		{
			//makes the word be lower case and then checks if it is a palindrome.
			for (int i=0; i < input.length(); i++) {

				input.at(i) = tolower(input.at(i));

				if (input[i] == input[input.length()-i-1])
				{
					isPalindrome = true;
				}

				else
				{
					isPalindrome = false;
				}

			}

			//if palindrome say that it is a palindrome, if not, its not a palindrome. Clears cin afterwards to not have problems with infinite loop
			if (isPalindrome)
			{
				std::cout << "The word that you input is a palindrome! \n" << std::endl;
				std::cin.clear();
			}

			else
			{
				std::cout << "The word that you input is NOT a palindrome! \n" << std::endl;
				std::cin.clear();
			}
		}
	}

	return 0;
}