#include "Mob.hh"
#include <string>
#include "Macro.hh"
#include <iostream>

Mob::Mob(const sf::Vector2f &pos, std::string spritemob) : APerso(spritemob)
{
  _life = 10;
  _pos.x = pos.x;
  _pos.y = pos.y;
  _sol = true;
  _move = 0;
  _jump = false;
  _direction = true;
  _myDirection = APerso::WAIT;
  _font.loadFromFile("fonthud.ttf");
  _barlife.setFont(_font);
  _barlife.setCharacterSize(30);
  _barlife.setColor(sf::Color::Red);
}

Mob::~Mob()
{
}

void    Mob::draw(sf::RenderWindow &window)
{
  sf::Vector2f	tmp = _spriteplayer.getPosition();

  tmp.x -= Map::instance().getMove() - _move;
  _barlife.setPosition(tmp.x - 50, _pos.y - 180);
  _spriteplayer.setPosition(tmp);
  _spriteplayer.draw(window);
  tmp.x += Map::instance().getMove() + _move;
  _spriteplayer.setPosition(tmp);
  window.draw(_barlife);
}

void    Mob::moveleft()
{
  int   yless;

  _spriteplayer.run();
  yless = Map::instance().checkleft(_move + _pos.x, _pos.y, SPEEDMOB);
  if (yless != -1 && Map::instance().checkleftall(_move + _pos.x, _pos.y, SPEEDMOB) == 0)
    {
      _pos.y -= yless;
      _move -= SPEEDMOB;
    }
  if (_direction == false)
    {
      _spriteplayer.flip();
      _direction = true;
    }
}

void    Mob::moveright()
{
  int   yless;

  _spriteplayer.run();
  yless = Map::instance().checkright(_move + _pos.x, _pos.y, SPEEDMOB);
  if (yless != -1 && Map::instance().checkrightall(_move + _pos.x, _pos.y, SPEEDMOB) == 0)
    {
      _pos.y -= yless;
      _move += SPEEDMOB;
    }
  if (_direction == true)
    {
      _spriteplayer.flip();
      _direction = false;
    }
}

void    Mob::gravity()
{
  if (Map::instance().checkbot(_move + _pos.x, _pos.y) == 0 && _jump == false)
    _pos.y += 10;
  else
    _sol = true;
}

void    Mob::jump()
{
  if (_jump == false
      &&  _sol == true
      && Map::instance().checktop(_move + _pos.x, _pos.y) == 0)
    {
      _sol = false;
      _spriteplayer.jump();
      _jump = true;
      _clock.restart();
    }
}

void    Mob::jumpupdate()
{
  if (_jump == true)
    {
      if (_clock.getElapsedTime().asMilliseconds() <=300)
        _pos.y -= 10;
      if (_clock.getElapsedTime().asMilliseconds() >=300
          || Map::instance().checktop(_move + _pos.x, _pos.y)== -1)
        {
          _sol = false;
          _jump = false;
          _spriteplayer.stop();
        }
    }
}

void	Mob::gerelife(int _life)
{

}

std::string     Mob::setbar(int len)
{
  std::string   bar;
  float         i;
  i = 0;
  while (i < len)
    {
      bar += "|";
      i += 1;
    }
  return (bar);
}


void	Mob::update()
{
  _hitbox.left = _move + _pos.x - XSPRITE/2;
  _hitbox.top = _pos.y - YSPRITE;
  _hitbox.width = XSPRITE;
  _hitbox.height = YSPRITE;
  _barlife.setString(setbar(_life));
  APerso::update();
}
