#include "Game.hh"
#include "Mob1.hh"
#include "Mob2.hh"
#include <iostream>
#include "Macro.hh"

Game::Game() : _window(sf::VideoMode(1920, 1080), "Xproject")
{
  _col = false;
  _listobj.push_back(new Mob1(sf::Vector2f(1500,200)));
  _listobj.push_back(new Mob1(sf::Vector2f(1000,500)));
  _listobj.push_back(new Mob2(sf::Vector2f(3000,300)));
}

Game::~Game()
{
}

Game     &Game::instance()
{
  static Game _game;
  return (_game);
}

void	Game::catchevent()
{
  while (_window.pollEvent(_event))
    {
      if (_event.type == sf::Event::Closed)
        _window.close();
      _key["LEFT"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
      _key["RIGHT"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
      _key["SPACE"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
      _key["EXIT"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

    }
  if (_key["LEFT"])
    Perso::instance().moveleft();
  if (_key["RIGHT"])
    Perso::instance().moveright();
  if (_key["SPACE"])
    Perso::instance().jump();
  if (_key["EXIT"])
    exit(0);
}

void	Game::update()
{
  Perso::instance().update();
  _phys.update();
  for (std::list<Objet *>::iterator i = _listobj.begin(); i != _listobj.end(); i ++)
    {
      (*i)->update();
      if ((*i)->testcol(Perso::instance().gethitbox()) == true)
	{
	  (*i)->effect();
	}
    }

}

void	Game::draw()
{ 
  Map::instance().draw(_window);
  Perso::instance().draw(_window);
  for (std::list<Objet *>::iterator i = _listobj.begin(); i != _listobj.end(); i ++)
    {
      (*i)->draw(_window);
    }

}

void	Game::run()
{
  while (_window.isOpen() == true)
    {
      _window.clear();
      catchevent();
      update();
      draw();
      _window.display();
    }
}
