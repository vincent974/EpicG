#ifndef __APERSO_HH__
#define __APERSO_HH__

#include <SFML/Graphics.hpp>
#include "Map.hh"
#include "Sprite.hh"
#include "Macro.hh"
#include "Objet.hh"


class APerso : public Objet
{
public:
  
 enum Direction
   {
     LEFT,
     RIGHT,
      WAIT
   };


  APerso(std::string sprite);
  ~APerso();
  virtual void	effect() = 0;
  virtual bool	testcol(sf::Rect<float>  hitboxplayer);
  virtual void  moveleft();
  virtual void  moveright();
  virtual void  jump();
  virtual void  jumpupdate();
  virtual void  gravity();
  virtual void  update();
  void  stop();
  virtual sf::Rect<float>	gethitbox();
  virtual void  draw(sf::RenderWindow &);
  
protected:

  Sprite        _spriteplayer;
  sf::Vector2f  _pos;
  sf::Clock     _clock;
  bool          _direction;
  bool          _jump;
  bool          _sol;
  Direction     _myDirection;
  float         _move;
};


#endif

