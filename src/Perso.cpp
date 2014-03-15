#include "Perso.hh"
#include "Macro.hh"


Perso::Perso() : APerso("sprite2.png")
{
  _sol = true;
  _move = 0;
  _jump = false;
  _direction = true;
  _pos.x = 810;
  _pos.y = 640;
  _myDirection = Perso::WAIT;
  _dmg.restart();
  _maxlife = 20;
  _currentlife = 15;
  _maxmana = 15;
  _currentmana = 0;
  _lifeclock.restart();
  _manaclock.restart();
}

Perso::~Perso()
{
}


Perso     &Perso::instance()
{
  static Perso _perso;
  return (_perso);
}

void	Perso::lostlife(int dmg)
{
  if (_dmg.getElapsedTime().asMilliseconds() >=1000)
    {
      _currentlife -= dmg;
      _dmg.restart();
    }
}

void	Perso::regenlife()
{
  if(_lifeclock.getElapsedTime().asMilliseconds() >= 10000)
    {
      if (_currentlife < _maxlife)
	_currentlife += 1;
      _lifeclock.restart();
    }
}

void	Perso::regenmana()
{
  if(_manaclock.getElapsedTime().asMilliseconds() >= 1000)
    {
      if (_currentmana < _maxmana)
	_currentmana += 1;
      _manaclock.restart();
    }
}

void	Perso::moveleft()
{
  APerso::moveleft();
  Map::instance().setMove(_move);
}

void	Perso::moveright()
{
  APerso::moveright();
  Map::instance().setMove(_move);
}


void	Perso::update()
{
  _hitbox.left = 810 - XSPRITE/2 + _move;
  _hitbox.top = _pos.y - YSPRITE;
  _hitbox.width = XSPRITE;
  _hitbox.height = YSPRITE;
  regenmana();
  _hud.update(_maxlife, _currentlife, _maxmana, _currentmana);
  APerso::update();
  Map::instance().update(_move);
}

void	Perso::kick()
{
  _spriteplayer.kick();
}

void	Perso::punch()
{
  _spriteplayer.punch();
}

void  Perso::draw(sf::RenderWindow &window)
{
  APerso::draw(window);
  _hud.draw(window);
}
