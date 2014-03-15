#include "Mob1.hh"
#include "Perso.hh"


Mob1::Mob1(const sf::Vector2f &pos) : Mob(pos, "sprite1.png")
{
  _life = 10;
  _clock.restart();
}

Mob1::~Mob1()
{
}

void	Mob1::effect()
{
  Perso::instance().lostlife(3);
}

void	Mob1::IA()
{
  if (_clock.getElapsedTime().asMilliseconds() <=500)
    moveright();
  if (_clock.getElapsedTime().asMilliseconds() >=1000
      && _clock.getElapsedTime().asMilliseconds() <=1600)
    jump();
  if (_clock.getElapsedTime().asMilliseconds() >=1600
      && _clock.getElapsedTime().asMilliseconds() <=2100)
    moveleft();
  if (_clock.getElapsedTime().asMilliseconds() >=2100)
    _clock.restart();
}

void	Mob1::update()
{
  IA();
  Mob::update();
}
