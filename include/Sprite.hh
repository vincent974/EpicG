#ifndef __SPRITE_HH__
#define __SPRITE_HH__

#include <SFML/Graphics.hpp>

enum	Etat
  {
    STAND,
    RUN,
    JUMP,
    KICK,
    PUNCH
  };

class Sprite 
{
public :
  
  Sprite(std::string path);
  ~Sprite();

  void	animate();
  void	draw(sf::RenderWindow &);
  void	run();
  void	stop();
  void	flip();
  void	jump();
  void	punch();
  void	kick();
  sf::Vector2f	getPosition();
  void	setPosition(sf::Vector2f pos);

private :
  sf::Texture   _textureplayer;
  sf::Sprite    _spriteplayer;
  sf::Clock	_clock;
  int		_x;
  int		_decal;
  Etat		_etat;
  int		_flip;
};

#endif
