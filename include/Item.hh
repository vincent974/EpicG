#ifndef __ITEM_HH__
#define __ITEM_HH__

#include "Objet.hh"
#include <SFML/Graphics.hpp>

class Item : public Objet
{
public:

  Item();
  ~Item();
  virtual void  draw(sf::RenderWindow &window);
  virtual void update();


protected:
  sf::Vector2f	_pos;
  sf::Texture	_textureitem;
  sf::Sprite	_spriteitem;
};

#endif
