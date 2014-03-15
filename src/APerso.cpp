#include "APerso.hh"
#include <iostream>

APerso::APerso(std::string sprite) : _spriteplayer(sprite)
{  
}

bool    APerso::testcol(sf::Rect<float>  hitboxplayer)
{
  return _hitbox.intersects(hitboxplayer);
}

APerso::~APerso()
{
}

sf::Rect<float>	APerso::gethitbox()
{
  return (_hitbox);
}

void    APerso::moveleft()
{
  int   yless;

  _spriteplayer.run();
  yless = Map::instance().checkleft(_move + 810, _pos.y, SPEED);
  if (yless != -1 && Map::instance().checkleftall(_move + 810, _pos.y, SPEED) == 0)
    {
      _pos.y -= yless;
      _move -= SPEED;
    }
  if (_direction == false)
    {
      _spriteplayer.flip();
      _direction = true;
    }
}

void    APerso::moveright()
{
  int   yless;

  _spriteplayer.run();
  yless = Map::instance().checkright(_move + 810, _pos.y, SPEED);
  if (yless != -1 && Map::instance().checkrightall(_move + 810, _pos.y, SPEED) == 0)
    {
      _pos.y -= yless;
      _move += SPEED;
    }
  if (_direction == true)
    {
      _spriteplayer.flip();
      _direction = false;
    }
}


void    APerso::stop()
{
  _myDirection = APerso::WAIT;
  _spriteplayer.stop();
}



void	APerso::draw(sf::RenderWindow &window)
{
  _spriteplayer.draw(window);
}

void    APerso::gravity()
{
  if (Map::instance().checkbot(_move + 810, _pos.y) == 0 && _jump == false)
    _pos.y += 10;
  else
    _sol = true;
}

void    APerso::jump()
{
  if (_jump == false
      &&  _sol == true
      && Map::instance().checktop(_move + 810, _pos.y) == 0)
    {
      _sol = false;
      _spriteplayer.jump();
      _jump = true;
      _clock.restart();
    }
}

void    APerso::jumpupdate()
{
  if (_jump == true)
    {
      if (_clock.getElapsedTime().asMilliseconds() <=300)
        _pos.y -= 10;
      if (_clock.getElapsedTime().asMilliseconds() >=300
          || Map::instance().checktop(_move + 810, _pos.y)== -1)
        {
          _sol = false;
          _jump = false;
          _spriteplayer.stop();
        }
    }
}

void    APerso::update()
{
  gravity();
  jumpupdate();
  _spriteplayer.animate();
  _spriteplayer.stop();
  _spriteplayer.setPosition(_pos);
}
