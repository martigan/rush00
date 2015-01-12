#include "AEntity.hpp"
#include <iostream>
AEntity::AEntity(){
}
int AEntity::getX() {
	return this->x;
}
int AEntity::getY() {
	return this->y;
}
void AEntity::move(int frame) {
	if (frame - this->lastFrameX > this->speedX) {
		this->x--;
		this->lastFrameX = frame;
	}
}
AEntity::~AEntity(){
}
