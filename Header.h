#pragma once

#define KB_ESCAPE 27

#include <iostream>
#include <windows.h>
#include <random>
#include <conio.h>

extern bool isQuit;

void PrintNum(int number, int x_start);

std::pair<int, int> ThrowDices();

void DrawScreen(int time);

void PlayDiceThrower();

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