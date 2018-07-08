#include "Point.h"

Point Point::operator+=(Point p) { this->_x += p.x(); this->_y += p.y(); return *this; }
Point Point::operator+(Point p) { return Point(this->_x + p.x(), this->_y + p.y()); }
Point Point::operator-=(Point p) { this->_x -= p.x(); this->_y -= p.y(); return *this; }
Point Point::operator-(Point p) { return Point(this->_x - p.x(), this->_y - p.y()); }
Point Point::operator*=(Point p) { this->_x *= p.x(); this->_y *= p.y(); return *this; }
Point Point::operator*(Point p) { return Point(this->_x * p.x(), this->_y * p.y()); }
Point Point::operator/=(Point p) { this->_x /= p.x(); this->_y /= p.y(); return *this; }
Point Point::operator/(Point p) { return Point(this->_x / p.x(), this->_y / p.y()); }


const bool operator==(Point a, Point b) { return a.x() == b.x() && a.y() == b.y(); }
const bool operator!=(Point a, Point b) { return !(a == b); }


Point::Point() : _x(0.0), _y(0.0) {};
Point::Point(double x, double y) : _x(x), _y(y) {};

double Point::x() const { return _x; }
double Point::y() const { return _y; }


//Returns the slope of a line (two points)
double Point::slope(const Point& p) const {
	if (_x == p.x()) return NULL;
	return ((p.y() - _y) / (p.x() - _x));
}


//Return the pixel distance between two points
double Point::distance(const Point& p) const {
	double d = ((p.x() - _x) * (p.x() - _x)) +
		((p.y() - _y) * (p.y() - _y));
	return sqrt(d);
}


//Increments a specified distance along a line between two points
Point Point::increment(const Point& p, double dist) const {

	//Do not return a point greater than the limits of the line
	if (distance(p) <= dist) return p;

	if (_x != p.x()) {

		double m = slope(p);

		double newX = (dist / (sqrt((m*m) + 1)));
		newX = ((_x < p.x()) ? (_x + newX) : (_x - newX));

		double newY = ((m * dist) / (sqrt((m*m) + 1)));
		if (m >= 0.0) newY = ((_y < p.y()) ? (_y + newY) : (_y - newY));
		if (m < 0.0) newY = ((_y < p.y()) ? (_y - newY) : (_y + newY));

		return Point(newX, newY);

	}
	else {

		//If x's are equal, x coordinate doesn't change
		double newY = ((_y < p.y()) ? (_y + dist) : (_y - dist));
		return Point(_x, newY);
	}
}

std::ostream& operator<<(std::ostream& os, const Point p) {
	os << "(" << p.x() << "," << p.y() << ")";
	return os;
}