#pragma once
#ifndef ENGINE_COLORS_CLASS_HEADER_H_
#define ENGINE_COLORS_CLASS_HEADER_H_

#include "Allegro.h"

//19 July 2018

struct _COLORS {
	static const ALLEGRO_COLOR PINK;
	static const ALLEGRO_COLOR MAGENTA;
	static const ALLEGRO_COLOR RED;
	static const ALLEGRO_COLOR BROWN;
	static const ALLEGRO_COLOR MAROON;
	static const ALLEGRO_COLOR YELLOW;
	static const ALLEGRO_COLOR DARK_YELLOW;
	static const ALLEGRO_COLOR LIGHT_YELLOW;
	static const ALLEGRO_COLOR ORANGE;
	static const ALLEGRO_COLOR GREEN;
	static const ALLEGRO_COLOR DARK_GREEN;
	static const ALLEGRO_COLOR LIGHT_GREEN;
	static const ALLEGRO_COLOR BLUE;
	static const ALLEGRO_COLOR DARK_BLUE;
	static const ALLEGRO_COLOR LIGHT_BLUE;
	static const ALLEGRO_COLOR PURPLE;
	static const ALLEGRO_COLOR VIOLET;
	static const ALLEGRO_COLOR GRAY;
	static const ALLEGRO_COLOR DARK_GRAY;
	static const ALLEGRO_COLOR LIGHT_GRAY;
	static const ALLEGRO_COLOR WHITE;
	static const ALLEGRO_COLOR BLACK;
	static const ALLEGRO_COLOR INVISIBLE;
	ALLEGRO_COLOR getRandom() const;
	ALLEGRO_COLOR getCustom(int, int, int, int) const;
};

_COLORS Color;

const ALLEGRO_COLOR _COLORS::RED = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR _COLORS::BLACK = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR _COLORS::GREEN = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR _COLORS::BLUE = al_map_rgb(0, 0, 255);
const ALLEGRO_COLOR _COLORS::PINK = al_map_rgb(255, 192, 203);
const ALLEGRO_COLOR _COLORS::MAGENTA = al_map_rgb(255, 0, 255);
const ALLEGRO_COLOR _COLORS::BROWN = al_map_rgb(128, 64, 64);
const ALLEGRO_COLOR _COLORS::MAROON = al_map_rgb(128, 0, 0);
const ALLEGRO_COLOR _COLORS::YELLOW = al_map_rgb(255, 255, 0);
const ALLEGRO_COLOR _COLORS::LIGHT_YELLOW = al_map_rgb(255, 255, 128);
const ALLEGRO_COLOR _COLORS::DARK_YELLOW = al_map_rgb(128, 128, 0);
const ALLEGRO_COLOR _COLORS::ORANGE = al_map_rgb(255, 128, 0);
const ALLEGRO_COLOR _COLORS::LIGHT_GREEN = al_map_rgb(128, 255, 0);
const ALLEGRO_COLOR _COLORS::DARK_GREEN = al_map_rgb(0, 128, 0);
const ALLEGRO_COLOR _COLORS::LIGHT_BLUE = al_map_rgb(0, 255, 255);
const ALLEGRO_COLOR _COLORS::DARK_BLUE = al_map_rgb(0, 0, 128);
const ALLEGRO_COLOR _COLORS::PURPLE = al_map_rgb(128, 128, 255);
const ALLEGRO_COLOR _COLORS::VIOLET = al_map_rgb(128, 0, 128);
const ALLEGRO_COLOR _COLORS::GRAY = al_map_rgb(192, 192, 192);
const ALLEGRO_COLOR _COLORS::LIGHT_GRAY = al_map_rgb(224, 224, 224);
const ALLEGRO_COLOR _COLORS::DARK_GRAY = al_map_rgb(128, 128, 128);
const ALLEGRO_COLOR _COLORS::WHITE = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR _COLORS::INVISIBLE = al_map_rgba(0, 0, 0, 0);

ALLEGRO_COLOR _COLORS::getRandom() const {
	return al_map_rgb((rand() % 256), (rand() % 256), (rand() % 256));
}

ALLEGRO_COLOR _COLORS::getCustom(int r, int g, int b, int a = 255) const {
	if (r < 0) r = 0; if (r > 255) r = 255;
	if (g < 0) g = 0; if (g > 255) g = 255;
	if (b < 0) b = 0; if (b > 255) b = 255;
	if (a < 0) a = 0; if (a > 255) a = 255;
	return al_map_rgba(r, g, b, a);
}

bool operator==(const ALLEGRO_COLOR &Clr1, const ALLEGRO_COLOR &Clr2)
{
	return	Clr1.r == Clr2.r &&
		Clr1.g == Clr2.g &&
		Clr1.b == Clr2.b &&
		Clr1.a == Clr2.a;
}
bool operator!=(const ALLEGRO_COLOR &Clr1, const ALLEGRO_COLOR &Clr2) { return !(Clr1 == Clr2); }


#endif 