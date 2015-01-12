#include <stddef.h>
#include "Pixel.hpp"

Pixel::Pixel(){
    this->_char = CHAR_DEF;
    this->_color = COLOR_DEF;
}

Pixel::Pixel(wchar_t c, int color){
    this->_char = c;
    this->_color = color;
}

Pixel::~Pixel(){
}

Pixel::Pixel(Pixel const &cpy)
{
    *this = cpy;
}

Pixel &Pixel::operator=(Pixel const & pix)
{
    this->_color = pix.getColor();
    this->_char = pix.getChar();   
    return *this;
}

int        Pixel::getColor(void) const{
    return this->_color;   
}

wchar_t   Pixel::getChar(void) const{
    return this->_char;   
}

void       Pixel::setColor(int color)
{
    this->_color = color;
}

void       Pixel::setChar(wchar_t char_in)
{
    this->_char = char_in;
}

void       Pixel::reset(void)
{
    this->_char = COLOR_DEF;
    this->_color = CHAR_DEF;
}