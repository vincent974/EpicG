#ifndef __PERSO_HH__
#define __PERSO_HH__

#include <SFML/Graphics.hpp>
#include "Sprite.hh"
#include "Map.hh"
#include "APerso.hh"
#include "Hud.hh"

class Perso : public APerso
{
public:

  ~Perso();
  static Perso	&instance();
  void		punch();
  void		kick();
  void		regenlife();
  void		regenmana();
  void		lostlife(int dmg);
  virtual void	effect() {}
  virtual void	update();
  virtual void  moveleft();
  virtual void  moveright();
  virtual void  draw(sf::RenderWindow &window);
  
  
private:
  Perso();
  Hud		_hud;
  float		_maxlife;
  float		_currentlife;
  float		_maxmana;
  float		_currentmana;
  sf::Clock	_lifeclock;
  sf::Clock	_manaclock;
  sf::Clock	_dmg;
};


#endif
