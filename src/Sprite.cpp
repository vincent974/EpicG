#include "Sprite.hh"
#include <stdio.h>
#include "Macro.hh"

Sprite::Sprite(std::string path)
{
  _textureplayer.loadFromFile(path);
  _spriteplayer.setTexture(_textureplayer);
  _spriteplayer.setTextureRect(sf::IntRect(0, 0, XSPRITE, YSPRITE));
  _spriteplayer.setOrigin(XSPRITE/2, YSPRITE);
  _etat = STAND;
  _x = 0;
  _decal = 1;
  _flip = -1;
}

Sprite::~Sprite()
{  
}

sf::Vector2f Sprite::getPosition()
{
  return (_spriteplayer.getPosition());
}

void	Sprite::setPosition(sf::Vector2f pos)
{
  _spriteplayer.setPosition(pos);
}

void	Sprite::draw(sf::RenderWindow &win)
{
  win.draw(_spriteplayer);
}

void	Sprite::run()
{
  _etat = RUN;
}

void	Sprite::punch()
{
  _etat = PUNCH;
}

void	Sprite::kick()
{
  _etat = KICK;
}

void	Sprite::stop()
{
  _etat = STAND;
}

void	Sprite::jump()
{
  _etat = JUMP;
}

void	Sprite::flip()
{
  _flip *= -1;
  _spriteplayer.setScale(-1 *_flip, 1);
}

void	Sprite::animate()
{
  if (_clock.getElapsedTime().asMilliseconds() >= 150)
    {
      _clock.restart();
      _spriteplayer.setTextureRect(sf::IntRect(XSPRITE * _x, YSPRITE * _etat, XSPRITE, YSPRITE));
      _x += _decal;
      _decal *= -1;
    }
}
