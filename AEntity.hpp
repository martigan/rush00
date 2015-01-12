#ifndef AENTITY_HPP
#define AENTITY_HPP
#include <string>
#include "Screen.hpp"
class AEntity {
	protected:
		int x;
		int y;
		int lastFrameX;
		int speedX;

	public:
		virtual ~AEntity();
		AEntity();
		int getX();
		int getY();
		virtual std::string *getHitBox() = 0;
		virtual void move(int frame);
		virtual void display(Screen &) = 0;
		virtual AEntity *shoot(int frame) = 0;
		//static bool checkHit(AEntity v1, AEntity v2);
};

#endif
