#pragma once
#include <string>

#include "game.h"
#include "credits.h"
#include "howToPlay.h"

#include "score.h"

extern Texture2D farBackground;
extern Texture2D nearBackgound1;
extern Texture2D nearBackgound2;
extern Texture2D floorBackground;
extern Texture2D enemy;
extern Texture2D pauseButton;
extern Texture2D dron1;
extern Texture2D bullet;
extern Texture2D playerimg;

struct optionsButtons
{
	Rectangle option;
};

void Menu();

void DrawMenu(optionsButtons buttons[]);

void LoadTexturesGame();

void CreateOptions(optionsButtons buttons[]);

int InputReader(optionsButtons buttons[]);

bool IsExitPressed();

bool IsExitWindow();
