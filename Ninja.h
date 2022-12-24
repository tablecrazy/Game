#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"

namespace Tmpl8 {

	class Ninja 
	{
	public:		
		Ninja();
		Ninja(Surface* screen);
		void Update();		
		void Draw(Surface* screen);

		vec2 playerPos{ 0 , 0 };

		int speed = 1;

		bool isGrounded = false;
		bool isColliding = false;

	private:

		/*VARIABLES*/
		Surface* m_screen;

		/*METHODS*/

		void PlayerGravity();
		void Input();
		void DrawBorders(int xMin, int xMax, int yMin, int yMax);
		void DrawCollider(Surface* s, float x, float y, float r);
		void PlayerDebug();
		
	};

};
