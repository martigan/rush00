#ifndef GLADIUS_HPP
# define GLADIUS_HPP
#include "AEntity.hpp"

class Gladius : public AEntity {
	private:
		std::string sprite[2];
		int lastFrameY;
		int speedY;
		int lastFrameShoot;
		int speedShoot;

	public:
		~Gladius();
		Gladius();
		void display(Screen &);
		std::string *getHitBox();
		AEntity *shoot(int frame);
		void moveUp(int frame);
		void moveDown(int frame);
		void moveLeft(int frame);
		void moveRight(int frame);
};


#endif
