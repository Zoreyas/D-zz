#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>



int main()
{
	int a[100000], n, choise1;
	int NInput();
	bool TestForValid();

	do
	{
		std::cout << "Please enter 'n' < 100000" << std::endl;
		n = NInput();
	} while ((n < 1) || (n >= 100000));

	do {
		std::cout << "Random(1) or you want to do it yourself(2)?" << std::endl;
		choise1 = NInput();
	} while ((choise1 != 1) && (choise1 != 2));

	if (choise1 == 1)
	{
		srand(time(0));
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 101 - 50;
			std::cout << std::setw(5) << a[i] << " ";
		}
		std::cout << "- your array." << std::endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "Enter element" << std::endl;
			a[i] = NInput();
		}

		for (int i = 0; i < n; i++)
		{
			std::cout << std::setw(5) << a[i] << " ";
		}
		std::cout << "- your array." << std::endl;
	}

	int count1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			count1++;
		}
	}
	std::cout << count1 << std::endl;

	if (count1 == 0)
	{
		std::cout << "There is no negative numbers." << std::endl;
	}
	else
	{
		if (count1 == 1)
		{
			std::cout << "There is only one negative number." << std::endl;
		}
		else
		{
			if (count1 > 2)
			{
				std::cout << "There is more than two negative numbers" << std::endl;
			}
			else
			{
				std::cout << "f";
			}
		}
	}


	system("pause");
	return(0);
}

bool TestForValid()
{
	if (std::cin.good())
	{
		return true;
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return false;
	}
}

int NInput()
{
	int number;
	while (true)
	{
		std::cin >> number;
		if (TestForValid())
		{
			return number;
		}
		else
		{
			std::cout << "Error. Please verify input." << std::endl;
		}
	}
}
