#ifndef __MOB2_HH__
#define __MOB2_HH__

#include <SFML/Graphics.hpp>
#include "Mob.hh"

class Mob2 : public Mob
{
public:

  Mob2(const sf::Vector2f &pos);
  ~Mob2();
  virtual void	effect();
  virtual void  update();
  virtual void  gravity();
  virtual void  jump();
  virtual void  jumpupdate();
  void  IA();

private:
  sf::Clock     _clock;
  sf::Clock     _clockgrav;
  sf::Clock     _clockfly;
};


#endif

