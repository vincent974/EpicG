#include "Mob2.hh"
#include <iostream>
#include "Perso.hh"

Mob2::Mob2(const sf::Vector2f &pos) : Mob(pos, "sprite1.png")
{
  _life = 5;
  _clock.restart();
  _clockgrav.restart();
}

Mob2::~Mob2()
{
}

void    Mob2::IA()
{
  if (_clock.getElapsedTime().asMilliseconds() <= 1500)
    moveright();
  if (_clock.getElapsedTime().asMilliseconds() >= 1500)
    moveleft();
  if (_clock.getElapsedTime().asMilliseconds() >= 3000)
    _clock.restart();
  if (_clockgrav.getElapsedTime().asMilliseconds() <= 300)
    jump();
  if (_clockgrav.getElapsedTime().asMilliseconds() >= 625)
    _clockgrav.restart();
}

void    Mob2::gravity()
{
  if (Map::instance().checkbot(_move + _pos.x, _pos.y) == 0 && _jump == false)
    _pos.y += 4;
}

void	Mob2::effect()
{
  Perso::instance().lostlife(1);
}

void    Mob2::jump()
{
  if (_jump == false)
    {
      _spriteplayer.jump();
      _jump = true;
      _clockfly.restart();
    }
}

void    Mob2::jumpupdate()
{
  if (_jump == true)
    {
      if (_clockfly.getElapsedTime().asMilliseconds() <=300)
        _pos.y -= 4;
      if (_clockfly.getElapsedTime().asMilliseconds() >=300)
        {
          _jump = false;
          _spriteplayer.stop();
        }
    }
}

void    Mob2::update()
{
  IA();
  Mob::update();
}

