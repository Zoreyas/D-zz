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
				int index1, index2;
				for (int i = 0; i < n; i++)
				{
					if (a[i] < 0)
					{
						index1 = i;
						break;
					}
				}
				for (int i = n-1; i >= 0; i--)
				{
					if (a[i] < 0)
					{
						index2 = i;
						break;
					}
				}
				
				if (index2 == index1 + 1)
				{
					std::cout << "Negative numbers are too close" << std::endl;
				}
				else
				{
					int sum = 0;
					for (int i = index1 + 1; i < index2; i++)
					{
						sum += a[i];
					}
					std::cout << "Sum = " << sum << std::endl;
				}
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
