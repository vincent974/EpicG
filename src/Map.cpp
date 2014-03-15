#include "Map.hh"
#include "Macro.hh"

Map::Map()
{
  _bcmap.loadFromFile("m2.png");
  _texturemap.loadFromFile("m1.png");
  _spritemap.setTexture(_texturemap);
  _spritemap.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
}

Map::~Map()
{
}

Map	&Map::instance()
{
  static Map _map;
  return (_map);
}

int	Map::checkright(float x, float y, int speed)
{
  int	i = 0;
  while (i != 16)
    {
      if (sf::Color::Black == _bcmap.getPixel(x+speed, y-i))
	i += 1;
      else
	return (i);
    }
  return (-1);
}

int     Map::checkrightall(float x, float y, int speed)
{
  if (sf::Color::Black == _bcmap.getPixel(x+speed, y-YSPRITE)
      ||sf::Color::Black == _bcmap.getPixel(x+speed, y-(YSPRITE/2)))
    return (-1);
  return (0);
}

int	Map::checkleft(float x, float y, int speed)
{
  int	i = 0;
  while (i != 16)
    {
      if (sf::Color::Black == _bcmap.getPixel(x-speed, y-i))
	i += 1;
      else
	return (i);
    }
  return (-1);
}

int     Map::checkleftall(float x, float y, int speed)
{
  if (sf::Color::Black == _bcmap.getPixel(x-speed, y-YSPRITE)
      ||sf::Color::Black == _bcmap.getPixel(x-speed, y-(YSPRITE/2)))
    return (-1);
  return (0);
}

int	Map::checktop(float x, float y)
{
  if (sf::Color::Black == _bcmap.getPixel(x, y-(YSPRITE+10)))
    return (-1);
  return (0);
}

int	Map::checkbot(float x, float y)
{
  if (sf::Color::Black == _bcmap.getPixel(x, y+5))
    return (1);
  return (0);
}

void	Map::setMove(float x)
{
  _move = x;
}

float	Map::getMove() const
{
  return (_move);
}

void	Map::update(float x)
{
  _spritemap.setTextureRect(sf::IntRect(x, 0, 1920+x, 1080));
}

void	Map::draw(sf::RenderWindow &window)
{
  window.draw(_spritemap);
}
