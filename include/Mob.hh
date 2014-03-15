#ifndef __MOB_HH__
#define __MOB_HH__

#include <SFML/Graphics.hpp>
#include "APerso.hh"
#include <string>

class Mob : public APerso
{
public:

  virtual void	effect() = 0;
  virtual void	gerelife(int _life);	
  virtual void  draw(sf::RenderWindow &);
  virtual void	gravity();
  virtual void	moveleft();
  virtual void	moveright();
  virtual void	jump();
  virtual void	jumpupdate();
  virtual void  update();
  std::string	setbar(int len);
  Mob(const sf::Vector2f &pos, std::string spritemob);
  ~Mob();

protected:
  int		_life;
  sf::Font	_font;
  sf::Text	_barlife;
};


#endif
