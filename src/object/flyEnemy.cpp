#include "flyEnemy.h"
static const int maxFlyEnemies = 3;

void CreateFlyEnemy(FLYENEMY& flyEnemy)
{
	flyEnemy.x = 0;
	flyEnemy.y = GetPercentageScreenHeight(20);

	flyEnemy.width = GetPercentageScreenWidth(10);
	flyEnemy.height = GetPercentageScreenHeight(10);

    flyEnemy.speed.x = 100;
    flyEnemy.speed.y = 200;

    flyEnemy.isAlive = true;
    flyEnemy.isGoingDown = false;

}

void FlyEnemyMove(FLYENEMY flyEnemy[])
{
	float topLimit = 0;
	float botLimit = GetPercentageScreenHeight(25);

    for (int i = 0; i < maxFlyEnemies; i++)
    {
        if (flyEnemy[i].isAlive == true)
        {
            flyEnemy[i].x += flyEnemy[i].speed.x * GetFrameTime();

            if (flyEnemy[i].isGoingDown == false)
            {
                flyEnemy[i].y += flyEnemy[i].speed.y * GetFrameTime();

                if (flyEnemy[i].y > botLimit)
                {
                    flyEnemy[i].isGoingDown = true;
                }
            }
            else if (flyEnemy[i].isGoingDown == true)
            {
                flyEnemy[i].y -= flyEnemy[i].speed.y * GetFrameTime();

                if (flyEnemy[i].y < topLimit)
                {
                    flyEnemy[i].isGoingDown = false;
                }
            }
        }
        else
        {
            flyEnemy[i].x = topLimit - flyEnemy[i].width;
            if (GetRandomValue(0, 1000) == 50)
            {
                flyEnemy[i].isAlive = true;
            }
        }

        if (flyEnemy[i].x > GetScreenWidth())
        {
            flyEnemy[i].x = 0 - flyEnemy[i].width;
        }
    }
}