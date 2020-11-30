#include "Header.h"

void gotoxy(int x, int y) {
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(handle, coords);
}

void PrintNum(int number, int x_start)
{
	switch (number)
	{
	case 0:
		PrintZero(x_start);
		break;
	case 1 :
		PrintOne(x_start);
		break;
	case 2:
		PrintTwo(x_start);
		break;
	case 3:
		PrintThree(x_start);
		break;
	case 4:
		PrintFour(x_start);
		break;
	case 5:
		PrintFive(x_start);
		break;
	case 6:
		PrintSix(x_start);
		break;
	case 7:
		PrintSeven(x_start);
		break;
	case 8:
		PrintEight(x_start);
		break;
	case 9:
		PrintNine(x_start);
		break;
	default :
		break;
	}
}

std::pair<int, int> ThrowDices()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, 7);

	int a = (int)dist(mt);
	int b = (int)dist(mt);

	if (a == 7)
		a = 6;
	if (b == 7)
		b = 6;

	return std::make_pair(a, b);
}

void DrawScreen(int time)
{
	std::cout << "Game starts in " << time / 4 << "..." << std::endl << std::endl << std::endl;

	std::cout << "Press :\tB - make bet\tEsc - Quit" << std::endl;
}

void CheckOnInteraction()
{
	if (_kbhit())
	{
		char a = _getch();

		switch (a)
		{
		case KB_ESCAPE:
			isQuit = true;
			break;
		case 'b':
			system("cls");
			std::cout << "You have successfully made bet!" << std::endl;
			Sleep(1500);
			break;
		default:
			break;
		}
	}
}

void PlayDiceThrower()
{
	int time = 63;
	while (time != 0)
	{
		system("cls");

		DrawScreen(time);

		CheckOnInteraction();

		if (isQuit)
			return;

		Sleep(250);
		time--;
	}
	/*std::pair<int, int> pair = ThrowDices();

	std::cout << pair.first << " & " << pair.second;*/
}

void PrintZero(int x_start)
{
	using namespace std;

	for (int i = 3; i < 11; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = x_start; i < x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i < x_start + 11; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintOne(int x_start)
{
	using namespace std;

	for (int i = 3; i < 11; i++)
	{
		gotoxy(x_start + 7, i);
		cout << '*';
	}
	for (int i = x_start + 6, j = 3; i > x_start + 1; i--, j++)
	{
		gotoxy(i, j);
		cout << '*';
	}
	for (int i = x_start + 4; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintTwo(int x_start)
{
	using namespace std;

	for (int i = x_start; i < x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintThree(int x_start)
{
	using namespace std;

	for (int i = x_start; i < x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintFour(int x_start)
{
	using namespace std;

	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i <= 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}

	cout << endl << endl << endl;
}

void PrintFive(int x_start)
{
	using namespace std;

	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintSix(int x_start)
{
	using namespace std;

	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintSeven(int x_start)
{
	using namespace std;

	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = x_start + 10, j = 3; i > x_start + 1; i--, j++)
	{
		gotoxy(i, j);
		cout << '*';
	}

	cout << endl << endl << endl;
}

void PrintEight(int x_start)
{
	using namespace std;

	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}

void PrintNine(int x_start)
{
	using namespace std;

	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 3);
		cout << '*';
		i++;
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start, i);
		cout << '*';
	}
	for (int i = 3; i < 7; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 7);
		cout << '*';
		i++;
	}
	for (int i = 8; i < 11; i++)
	{
		gotoxy(x_start + 10, i);
		cout << '*';
	}
	for (int i = x_start; i <= x_start + 10; i++)
	{
		gotoxy(i, 11);
		cout << '*';
		i++;
	}

	cout << endl << endl << endl;
}