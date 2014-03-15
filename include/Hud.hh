#ifndef __HUD_HH__
#define __HUD_HH__

#include <SFML/Graphics.hpp>

class Hud
{
public:

  Hud();
  ~Hud();
  
  std::string	setbar(float len);
  void	update(float lifem, float lifec, float manam, float manac);
  void	draw(sf::RenderWindow &window);


private:
  sf::Font      _font;
  sf::Text      _currentlife;
  sf::Text      _maxlife;
  sf::Text      _currentmana;
  sf::Text      _maxmana;
  std::string	_stringcl;
  std::string	_stringml;
  std::string	_stringcm;
  std::string	_stringmm;
  sf::Texture	_ticone;
  sf::Sprite	_sicone;

};


#endif

