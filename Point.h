#pragma once
#ifndef ENGINE_POINT_CLASS_HEADER_H_
#define ENGINE_POINT_CLASS_HEADER_H_

//7 July 2018 (v 1.0)

#include <iostream>

class Point {
	public:
		Point();
		Point(double, double);
		
		double x() const;
		double y() const;
		double slope(const Point&) const;
		double distance(const Point&) const;
		Point increment(const Point&, double) const;

		Point operator+=(Point p);
		Point operator+(Point p);
		Point operator-=(Point p);
		Point operator-(Point p);
		Point operator*=(Point p);
		Point operator*(Point p);
		Point operator/=(Point p);
		Point operator/(Point p);

	private:
		double _x, _y;
};

std::ostream& operator<<(std::ostream& os, const Point p);

#endif


