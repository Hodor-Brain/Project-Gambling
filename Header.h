#pragma once

#define KB_UP 72

#define KB_DOWN 80

#define KB_LEFT 75

#define KB_RIGHT 77

#define KB_ESCAPE 27

#define KB_ENTER 13

#include <iostream>
#include <windows.h>
#include <random>
#include <conio.h>
#include <vector>
#include <string>

extern bool isQuit;
extern int Money;

class Bet
{
private:

	int Money;
	int BetKey;

public:

	Bet()
	{
		Money = 0;
		BetKey = 0;
	}
	Bet(int money, int key)
	{
		Money = money;
		BetKey = key;
	}
	~Bet()
	{}

	int GetMoney()
	{
		return Money;
	}
	int KeyofBet()
	{
		return BetKey;
	}
};

void PrintNum(int number, int x_start);

void PrintIsRolling();

std::pair<int, int> ThrowDices();

void Play(std::vector<Bet> &bets);

void DrawScreen(int time);

void PlayDiceThrower();

void CheckOnInteraction(int& time, std::vector<Bet>& bets);

void MakingBetMenu(int& time, std::vector<Bet>& bets);

void gotoxy(int x, int y);

void PrintZero(int x_start);
void PrintOne(int x_start);
void PrintTwo(int x_start);
void PrintThree(int x_start);
void PrintFour(int x_start);
void PrintFive(int x_start);
void PrintSix(int x_start);
void PrintSeven(int x_start);
void PrintEight(int x_start);
void PrintNine(int x_start);