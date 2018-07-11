#include "Bounds.h"

//Constructors are private; this is a base class
Bounds::Bounds() :_point(0, 0), _width(0), _height(0) {};
Bounds::Bounds(const Point& p, int w, int h) {
	move(p);
	resize(w, h);
}

void Bounds::move(const Point& p) { _point = p; }

//New size cannot be negative values
void Bounds::resize(int w, int h) {
	if (w < 0) w = 0;
	if (h < 0) h = 0;
	_width = w;
	_height = h;
}

//Copies the argument bounds into this instance
void Bounds::copy(const Bounds& b) {
	_point = b.at();
	_width = b.width();
	_height = b.height();
}

//Getters
Point Bounds::at() const { return _point; }
int Bounds::width() const { return _width; }
int Bounds::height() const { return _height; }

//Returns the point at each corner & center of the bounds instance

Point Bounds::upperLeftAt() const {
	return at();
}

Point Bounds::upperRightAt() const {
	double x = (at().x() + _width) - 1;
	return Point(x, at().y());
}

Point Bounds::bottomLeftAt() const {
	double y = (at().y() + _height) - 1;
	return Point(at().x(), y);
}

Point Bounds::bottomRightAt() const {
	double x = (at().x() + _width) - 1;
	double y = (at().y() + _height) - 1;
	return Point(x, y);
}

Point Bounds::centerAt() const {
	double x = at().x() + (_width / 2);
	double y = at().y() + (_height / 2);
	return Point(x, y);
}


std::ostream& operator<<(std::ostream& os, const Bounds b) {
	os << b.at() << ": " << b.width() << "W " << b.height() << "H";
	return os;
}