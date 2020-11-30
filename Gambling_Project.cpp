#include "Header.h"

bool isQuit = false;

int main()
{
	while (!isQuit)
	{
		PlayDiceThrower();

		std::cout << std::endl;

		system("cls");
	}

	/*PrintNum(7, 10);
	PrintNum(7, 24);*/
	//PrintNum(7, 38);
	//std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
}