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
    flyEnemy.IsGoingDown = false;

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

            if (flyEnemy[i].IsGoingDown == false)
            {
                flyEnemy[i].y += flyEnemy[i].speed.y * GetFrameTime();

                if (flyEnemy[i].y > botLimit)
                {
                    flyEnemy[i].IsGoingDown = true;
                }
            }
            else if (flyEnemy[i].IsGoingDown == true)
            {
                flyEnemy[i].y -= flyEnemy[i].speed.y * GetFrameTime();

                if (flyEnemy[i].y < topLimit)
                {
                    flyEnemy[i].IsGoingDown = false;
                }
            }
        }

        if (flyEnemy[i].x > GetScreenWidth())
        {
            flyEnemy[i].x = 0;
        }
    }
}