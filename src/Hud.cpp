#include "Hud.hh"
#include <SFML/Graphics.hpp>

Hud::Hud()
{
  sf::Color _cmaxlife(25, 99, 21);
  sf::Color _cmana(46, 157, 255);
  sf::Color _cmaxmana(15, 16, 122);

  _font.loadFromFile("fonthud.ttf");

  _currentlife.setFont(_font);
  _currentlife.setCharacterSize(40);
  _currentlife.setColor(sf::Color::Green);
  
  _maxlife.setFont(_font);
  _maxlife.setCharacterSize(40);
  _maxlife.setColor(_cmaxlife);

  _font.loadFromFile("fonthud.ttf");
  _currentmana.setFont(_font);
  _currentmana.setString("|||||||||");
  _currentmana.setCharacterSize(40);
  _currentmana.setColor(_cmana);
  
  _maxmana.setFont(_font);
  _maxmana.setString("||||||||||||");
  _maxmana.setCharacterSize(40);
  _maxmana.setColor(_cmaxmana);
  
  _ticone.loadFromFile("sprite2.png");
  _sicone.setTexture(_ticone);
  _sicone.setTextureRect(sf::IntRect(0, 0, 80, 80));

  _sicone.setPosition(30, 50);
  _currentlife.setPosition(130, 50);
  _maxlife.setPosition(130, 50);
  _currentmana.setPosition(130, 90);
  _maxmana.setPosition(130, 90);
}

Hud::~Hud()
{
}

std::string	Hud::setbar(float len)
{
  std::string	bar;
  float		i;
  i = 0;
  while (i < len)
    {
      bar += "|";
      i += 1;
    }
  return (bar);
}

void	Hud::update(float lifem, float lifec, float manam, float manac)
{
  _stringcl = setbar(lifec);
  _stringml = setbar(lifem);
  _stringcm = setbar(manac);
  _stringmm = setbar(manam);
  _currentlife.setString(_stringcl);
  _maxlife.setString(_stringml);
  _currentmana.setString(_stringcm);
  _maxmana.setString(_stringmm);
}

void	Hud::draw(sf::RenderWindow &window)
{
  window.draw(_sicone);
  window.draw(_maxlife);
  window.draw(_currentlife);
  window.draw(_maxmana);
  window.draw(_currentmana);
}
