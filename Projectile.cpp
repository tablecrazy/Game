#pragma once
#include "Projectile.h"
#include "game.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite proj(new Surface("assets/ball.png"), 1);
	Projectile::Projectile() {}

	Projectile::Projectile(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Projectile::Update(Surface* s,float speed)
	{
		Move(speed);
		Draw(s);
		//printf("%d\n", (int)projPos.x);
		////printf("%d\n", side);
		//printf("Bounces Left: %d\n", bouncesLeft);
	}

	void Projectile::Move(float speed)
	{
		
		switch (side) {
		case Side::LEFT:
			projPos.x -= speed;
			break;
		case Side::RIGHT:
			projPos.x += speed;
			break;
		}
		Bounce();
	}

	void Projectile::Draw(Surface* screen)
	{
		proj.Draw(screen, projPos.x, projPos.y);
	}

	void Projectile::Bounce()
	{
		if (bouncesLeft > 0)
		{
			if (projPos.x < (0))
			{
				projPos.x = 0;
				bouncesLeft--;
				printf("RIGHT");
				side = Side::RIGHT;

			}
			if (projPos.x >= (750))
			{
				projPos.x = 750;
				bouncesLeft--;
				printf("LEFT");
				side = Side::LEFT;

			}
		}
		
	}

}