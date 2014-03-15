#ifndef __MAP_HH__
#define __MAP_HH__

#include <SFML/Graphics.hpp>

class Map
{
public :
  
  ~Map();
  static Map	&instance();
  void		update(float x);
  void		draw(sf::RenderWindow &window);
  int		checkright(float x, float y, int speed);
  int		checkrightall(float x, float y, int speed);
  int		checkleft(float x, float y, int speed);
  int		checkleftall(float x, float y, int speed);
  int		checktop(float x, float y);
  int		checkbot(float x, float y);
  float		getMove() const;
  void		setMove(float x);

private :
  Map();
  float		_move;
  sf::Texture	_texturemap;
  sf::Sprite	_spritemap;
  sf::Image	_bcmap;

};

#endif
