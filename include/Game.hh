#ifndef __GAME_HH__
#define __GAME_HH__

#include <SFML/Graphics.hpp>
#include <map>
#include <list>
#include "Perso.hh"
#include "Mob.hh"
#include "Macro.hh"
#include "Physics.hh"

class Game
{
 public:
  ~Game();
  
  static Game	&instance();
  void		run();
  void		draw();
  void		catchevent();
  void		update();
  
 private:
  Game();
  bool				_col;
  float				_test;
  sf::RenderWindow		_window;
  sf::Event			_event;
  std::map<std::string, bool>	_key;
  std::list<Objet *>		_listobj;
  Physics			_phys;
};


#endif
