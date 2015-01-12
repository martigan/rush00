#ifndef BULLET_HPP
# define BULLET_HPP
#include "AEntity.hpp"

class Bullet : public AEntity {
	private:
		std::string sprite[2];
		int dir;
		int color;
		Bullet();
		AEntity *shoot(int frame);
	public:
		~Bullet();
		Bullet(int, int, int, int);
		void display(Screen &);
		std::string *getHitBox();
		void move(int frame);
};

#endif
