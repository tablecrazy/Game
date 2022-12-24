#pragma once
#include "template.h"
#include "surface.h"
namespace Tmpl8 {

	enum class Side
	{
		LEFT,
		RIGHT
	};

	class Projectile
	{
	public:
		Projectile();
		Projectile(Surface* screen);
		virtual ~Projectile();
		void Update(Surface* s, float speed);
		void Draw(Surface* screen);
	private:

		/*VARIABLES*/
		Surface* m_screen;
		Side side{ Side::LEFT };
		vec2 projPos{ 0, 0 };
		float speed;
		int bouncesLeft = 5;
		//optional float damage;


		/*METHODS*/

		void Move(float speed);
		void Bounce();
		void BounceSpan();
		void DealDamage();
	};

}
