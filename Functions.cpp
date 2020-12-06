#include "Header.h"

int key_bet = 0;
std::string First_bet = "Even number wins (1.5x)";
std::string Second_bet = "Odd number wins (1.5x)";

void SetColor(int text, int background = 0)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

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

void DrawCash()
{
	gotoxy(70, 0);
	std::cout << "Your cash : " << Money;
	gotoxy(0, 0);
}

void PrintIsRolling()
{
	system("cls");

	std::cout << "Dices are rolling..." << std::endl << std::endl;

	Sleep(2000);

	system("cls");
}

void PrintFirstBet()
{
	if (key_bet == 0)
	{
		SetColor(7);
	}

	std::cout << First_bet << '\t';

	SetColor(6);
}

void PrintSecondBet()
{
	if (key_bet == 1)
	{
		SetColor(7);
	}

	std::cout << Second_bet << std::endl;

	SetColor(6);
}

void DrawBetScreen(int time)
{
	std::cout << "Game starts in " << time / 8 << "..." << std::endl << std::endl << std::endl;

	PrintFirstBet();
	PrintSecondBet();
}

void DrawScreen(int time)
{
	std::cout << "Game starts in " << time / 8 << "..." << std::endl << std::endl << std::endl;

	std::cout << "Press :\tB - make bet\tEsc - Quit" << std::endl;
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

void Play(std::vector<Bet>& bets)
{
	std::pair<int, int> pair = ThrowDices();

	PrintIsRolling();

	std::cout << pair.first << " & " << pair.second << std::endl;

	int sum = pair.first + pair.second;

	PrintNum(sum / 10, 10);
	PrintNum(sum % 10, 24);

	for (int i = 0; i < bets.size(); i++)
	{
		if (bets[i].KeyofBet() == 0)
		{
			if (sum % 2 == 0)
			{
				Money += bets[i].GetMoney() * 3 / 2;
			}
		}
		if (bets[i].KeyofBet() == 1)
		{
			if (sum % 2 == 1)
			{
				Money += bets[i].GetMoney() * 3 / 2;
			}
		}
	}

	Sleep(4000);
}

void CheckOnBetInteraction(int& time, std::vector<Bet>& bets)
{
	if (_kbhit())
	{
		char a = _getch();

		Bet bet(100, key_bet);

		switch (a)
		{
		case KB_ESCAPE:
			isQuit = true;
			break;
		case KB_RIGHT:
			key_bet++;

			if (key_bet > 1)
				key_bet = 1;

			break;
		case KB_LEFT:
			key_bet--;

			if (key_bet < 0)
				key_bet = 0;

			break;
		case KB_ENTER:
			Money -= 100;

			bets.push_back(bet);

			system("cls");
			std::cout << "You have successfully made bet!" << std::endl;
			isQuit = true;

			Sleep(2000);
			time -= 16;
		default:
			break;
		}
	}
}

void MakingBetMenu(int& time, std::vector<Bet>& bets)
{
	while (time >= 0)
	{
		system("cls");

		DrawCash();

		DrawBetScreen(time);

		CheckOnBetInteraction(time, bets);

		if (isQuit)
		{
			isQuit = false;
			return;
		}

		Sleep(100);
		time--;
	}
}


void CheckOnInteraction(int &time, std::vector<Bet>& bets)
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

			MakingBetMenu(time, bets);

			system("cls");
			break;
		default:
			break;
		}
	}
}

void PlayDiceThrower()
{
	int time = 127;

	std::vector<Bet> bets;

	while (time >= 0)
	{
		system("cls");

		DrawCash();

		DrawScreen(time);

		CheckOnInteraction(time, bets);

		if (isQuit)
			return;

		Sleep(100);
		time--;
	}

	Play(bets);

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