#ifndef CLASS_PIXEL_HPP
#define CLASS_PIXEL_HPP

# define COLOR_DEF 0
# define CHAR_DEF 20

class Pixel {
public:
    Pixel();
    Pixel(wchar_t, int);
    ~Pixel();
    Pixel(Pixel const&);

    Pixel      &operator=(Pixel const &);

    int        getColor(void) const;
    wchar_t    getChar(void) const;

    void       setColor(int);
    void       setChar(wchar_t);
    void       reset(void);
private:
    wchar_t    _char;
    int        _color;
};

#endif