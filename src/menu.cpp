#include "menu.h"
#include "game.h"
#include "score.h"

static const int totButtons = 5;
static bool closeGame = false;

Texture2D backgroundMenu;

void Menu()
{
	closeGame = false;

	optionsButtons buttons[5];
	CreateOptions(buttons);

	loadTexturesGame();

	while (closeGame == false && !WindowShouldClose())
	{
		DrawMenu(buttons);

		switch (InputReader(buttons))
		{
		case 0:
			Activate1Player();
			closeGame = true;
			Game(closeGame);
			break;

		case 1:
			Activate2Players();
			closeGame = true;
			Game(closeGame);
			break;

		case 2:
			do
			{
				DrawTexture(backgroundMenu, 0, 0, WHITE);
				Credits();
			} while (!IsExitPressed());
			break;

		case 3:
			closeGame = true;
			break;

		case 4:
			
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
	//DrawLinesScreen();

	for (int i = 0; i < totButtons; i++)
	{
		DrawRectangle(
			static_cast<int>(buttons[i].option.x),
			static_cast<int>(buttons[i].option.y),
			static_cast<int>(buttons[i].option.width),
			static_cast<int>(buttons[i].option.height),
			Color{ 0, 228, 48, 100 });
	}

	DrawText("Play", static_cast<int>(buttons[0].option.x), static_cast<int>(buttons[0].option.y), 20, BLACK);
	DrawText("2 Players", static_cast<int>(buttons[1].option.x), static_cast<int>(buttons[1].option.y), 20, BLACK);
	DrawText("Credits", static_cast<int>(buttons[2].option.x), static_cast<int>(buttons[2].option.y), 20, BLACK);
	DrawText("Exit", static_cast<int>(buttons[3].option.x), static_cast<int>(buttons[3].option.y), 20, BLACK);
	DrawText("How to Play", static_cast<int>(buttons[4].option.x), static_cast<int>(buttons[4].option.y), 20, BLACK);
	DrawText("version 1.0", 0, 0, 20, BLACK);
	
	DrawMaxScore();
	

	EndDrawing();
}

void CreateOptions(optionsButtons buttons[])
{
	for (int i = 0; i < totButtons - 1; i++)
	{
		buttons[i].option.height = GetPercentageScreenHeight(7);
		buttons[i].option.width = GetPercentageScreenWidth(15);
	}

	for (int i = 0; i < totButtons - 1; i++)
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

	buttons[4].option.height = GetPercentageScreenHeight(7);
	buttons[4].option.width = GetPercentageScreenWidth(15);
	buttons[4].option.x = GetPercentageScreenWidth(75);
	buttons[4].option.y = GetPercentageScreenHeight(50);
}

void loadTexturesGame()
{
	backgroundMenu = LoadTexture("res/textures/menu.png");
	farBackground = LoadTexture("res/textures/farBackGround.png");
	nearBackgound1 = LoadTexture("res/textures/nearBackGround_1.png");
	nearBackgound2 = LoadTexture("res/textures/nearBackGround_2.png");
	floorBackground = LoadTexture("res/textures/floor.png");
	enemy = LoadTexture("res/textures/enemy.png");
	pauseButton = LoadTexture("res/textures/enemy.png");
	dron1 = LoadTexture("res/textures/flyEnemy_1.png");
	bullet = LoadTexture("res/textures/bullet.png");
	playerimg = LoadTexture("res/textures/playerimg.png");

	playerimg.height = 200;
	playerimg.width = 130;

	pauseButton.width = enemy.width * 6;
	pauseButton.height = enemy.height * 6;

}

int InputReader(optionsButtons buttons[])
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), buttons[0].option))
		{
			return 0;
		}
		else if (CheckCollisionPointRec(GetMousePosition(), buttons[1].option))
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
		else if (CheckCollisionPointRec(GetMousePosition(), buttons[4].option))
		{
			return 4;
		}
	}

	return 5;
}

bool IsExitPressed()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if ((GetMouseX() > (GetScreenWidth() - 100)) && (GetMouseY() < 55))
		{
			return true;
		}
	}
	return false;
}
