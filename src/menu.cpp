#include "menu.h"

static const int totButtons = 4;

Texture2D backgroundMenu;

void Menu()
{
	bool closeGame;
	closeGame = false;

	optionsButtons buttons[4];
	CreateOptions(buttons);

	loadTexturesGame();

	while (closeGame == false && !WindowShouldClose())
	{
		DrawMenu(buttons);

		switch (InputReader(buttons))
		{
		case 0:
			closeGame = true;
			Game(closeGame);
			break;

		case 1:

			break;

		case 2:

			break;

		case 3:
			closeGame = true;
			break;

		default:
			break;
		}

	}

	CloseWindow();
}

void DrawMenu(optionsButtons buttons[])
{
	BeginDrawing();
	ClearBackground(WHITE);

	DrawTexture(backgroundMenu, 0, 0, WHITE);
	DrawLinesScreen();

	for (int i = 0; i < totButtons; i++)
	{
		DrawRectangle(
			static_cast<int>(buttons[i].option.x), 
			static_cast<int>(buttons[i].option.y), 
			static_cast<int>(buttons[i].option.width),
				static_cast<int>(buttons[i].option.height),
			Color{ 0, 228, 48, 100 });
	}
	
	DrawText("play", static_cast<int>(buttons[0].option.x), static_cast<int>(buttons[0].option.y), 20, BLACK  );
	DrawText("options", static_cast<int>(buttons[1].option.x), static_cast<int>(buttons[1].option.y), 20, BLACK);
	DrawText("credits", static_cast<int>(buttons[2].option.x), static_cast<int>(buttons[2].option.y), 20, BLACK);
	DrawText("exit", static_cast<int>(buttons[3].option.x), static_cast<int>(buttons[3].option.y), 20, BLACK);

	EndDrawing();
}

void CreateOptions(optionsButtons buttons[])
{
	for (int i = 0; i < totButtons-1; i++)
	{
		buttons[i].option.height = GetPercentageScreenHeight(7);
		buttons[i].option.width = GetPercentageScreenWidth(15);
	}

	for (int i = 0; i < totButtons-1; i++)
	{
		buttons[i].option.x = GetPercentageScreenWidth(16);
	}

	buttons[0].option.y = GetPercentageScreenHeight(50);
	buttons[1].option.y = GetPercentageScreenHeight(64);
	buttons[2].option.y = GetPercentageScreenHeight(79);

	buttons[3].option.height = GetPercentageScreenHeight(18);
	buttons[3].option.width = GetPercentageScreenWidth(10);
	buttons[3].option.x = GetPercentageScreenWidth(49);
	buttons[3].option.y = GetPercentageScreenHeight(75);
}

void loadTexturesGame()
{
	backgroundMenu = LoadTexture("res/textures/menu.png");
}

int InputReader(optionsButtons buttons[])
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), buttons[0].option))
		{
			return 0;
		}
		else if(CheckCollisionPointRec(GetMousePosition(), buttons[1].option))
		{
			return 1;
		}
		else if (CheckCollisionPointRec(GetMousePosition(), buttons[2].option))
		{
			return 2;
		}
		else if (CheckCollisionPointRec(GetMousePosition(), buttons[3].option))
		{
			return 3;
		}

		return 4;
	}

	return 4;
}