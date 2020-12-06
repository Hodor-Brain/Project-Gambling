#include "Header.h"

bool isQuit = false;
int Money = 1000;

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << "Hello" << std::endl;
	
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	while (!isQuit)
	{
		PlayDiceThrower();

		std::cout << std::endl;

		system("cls");
	}

	/*PrintNum(0, 10);
	/*PrintNum(7, 24);
	PrintNum(7, 38);
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;*/
}