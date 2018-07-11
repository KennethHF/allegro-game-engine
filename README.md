# allegro-game-engine
A graphics and game engine built in C++ around the Allegro 5 Library

Outline / Notes:

[Point.h/.cpp]
  (Private)
  double _x, _y
  (Public)
  double x() const
  double y() const
  double slope(const Point&) const
  double distance(const Point&) const
  Point increment(const Point&, double) const
  
[Bounds.h/.cpp]
  (Private)
  int _width, _height
  Point _point
  (Public)
  void move(const Point&)
  void resize(int, int)
  void copy(const Bounds&)
  Point at() const
  int width() const
  int height() const
  Point upperLeftAt() const
  Point upperRightAt() const
  Point bottomLeftAt() const
  Point bottomRightAt() const
  Point centerAt() const

