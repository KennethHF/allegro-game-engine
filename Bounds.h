#pragma once
#ifndef ENGINE_BOUNDS_CLASS_HEADER_H_
#define ENGINE_BOUNDS_CLASS_HEADER_H_

#include "Point.h"

//11 July 2018

class Bounds {
public:
	void move(const Point&);
	void resize(int, int);
	void copy(const Bounds&);

	Point at() const;
	int width() const;
	int height() const;
	
	Point upperLeftAt() const;
	Point upperRightAt() const;
	Point bottomLeftAt() const;
	Point bottomRightAt() const;
	Point centerAt() const;

private:
	Bounds();
	Bounds(const Point&, int, int);

	int _width, _height;
	Point _point;
};


#endif 
