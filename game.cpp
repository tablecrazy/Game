#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <array>
#include <iostream>
#include <string>

using namespace std;

namespace Tmpl8
{
	
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	//Object obj;
	Object obj[3];
	Projectile proj;
	bool objBool[3];

	int objVal;

	void Game::Init()
	{
		this->ninja = new Ninja(screen);
		this->projectile = new Projectile(screen);
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
		
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		deltaTime /= 1000;

		screen->Clear(0);
		ninja->Update();
		//projectile->Update(5);
		obj[0].Spawn(screen, 500, 200, 75, 75, ninja, Type::RECTANGLE);
		obj[1].Spawn(screen, 200, 200, 75, 75, ninja, Type::RECTANGLE);
		proj.Update(screen, 5);

		time += deltaTime;
		DifficultyProgression();
		//printf("%d\n", diffLevel);
		
	}

	void Game::DifficultyProgression()
	{

		if (time >= 5 && time<= 10)
		{
			diffLevel = DifficultyLevel::NORMAL;
		}
		else if (time >= 10 && time <= 15)
		{
			diffLevel = DifficultyLevel::HARD;
		}
		else if (time >= 15)
		{
			diffLevel = DifficultyLevel::BALLIN;
		}

		switch (diffLevel) {
		case DifficultyLevel::EASY:
			//default difficulty defining variables
			screen->Print("Just bounced", 10, 40, 0x96FF00);
			break;
		case DifficultyLevel::NORMAL:
			//increase spawn rate, projectile speed, dmg(only if character has health)
			screen->Print("Bouncer", 10, 40, 0xFDC526);
			break;
		case DifficultyLevel::HARD:
			//increase spawn rate, projectile speed, dmg(only if character has health)
			screen->Print("Bounce me plenty", 10, 40, 0xFDC526);
			break;
		case DifficultyLevel::BALLIN:
			//increase spawn rate, projectile speed, dmg(only if character has health), spawn projectiles everywhere(in other difficulties the spawn will be a safe place)
			screen->Print("BALLIN!!!", 10, 40, 0xF12F25);
			break;
		}

		
	}
};