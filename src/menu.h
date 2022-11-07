#pragma once
#include <string>
#include "game.h"
#include "credits.h"

struct optionsButtons
{
	Rectangle option;
};

void Menu();

void DrawMenu(optionsButtons buttons[]);

void loadTexturesGame();

void CreateOptions(optionsButtons buttons[]);

int InputReader(optionsButtons buttons[]);
