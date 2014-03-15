#ifndef __QUADTREE_HH__
#define __QUADTREE_HH__
#define MAXOBJ 4
#define MAXDEPTH 4

#include <SFML/Graphics.hpp>
#include <list>

class Quadtree
{
public:

  Quadtree();
  ~Quadtree();

  void  clear();
  void	insert(Objet *);

private:
  std::list<Objet *>	_listobj;
  Quadtree		*_node[4];
  
};


#endif
