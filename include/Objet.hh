#ifndef __OBJET_HH__
#define __OBJET_HH__

#include <SFML/Graphics.hpp>


class Objet
{
public:
  virtual void	effect() = 0;
  virtual bool	testcol(sf::Rect<float>) = 0;
  virtual sf::Rect<float> gethitbox() = 0;
  virtual ~Objet() {}
  virtual void draw(sf::RenderWindow &) = 0;
  virtual void update() = 0;
  
protected:
  sf::Rect<float>	_hitbox;
};


#endif
