#ifndef __MOB1_HH__
#define __MOB1_HH__

#include <SFML/Graphics.hpp>
#include "Mob.hh"

class Mob1 : public Mob
{
public:

  Mob1(const sf::Vector2f &pos);
  ~Mob1();

  virtual void	effect();
  virtual void	update();
  void	IA();

private:
  sf::Clock	_clock;
};


#endif
