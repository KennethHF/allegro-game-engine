#pragma once
#ifndef ENGINE_ALLEGRO_INITIALIZATION_CLASS_HEADER_H_
#define ENGINE_ALLEGRO_INITIALIZATION_CLASS_HEADER_H_

//11 July 2018
//allegro-5.0.10-monolith-md-debug.lib

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_windows.h>

bool initializeAllegro5() {
	try {

		if (!al_init()) throw ("Allegro failed to initialize.");
		al_init_font_addon();
		if (!al_init_ttf_addon()) throw ("Failed to initialize TTF font file support.");
		if (!al_init_primitives_addon()) throw ("Failed to initialize allegro primitives support.");
		if (!al_install_keyboard()) throw ("Failed to initialize allegro keyboard support");
		if (!al_install_mouse()) throw ("Failed to initialize allegro mouse support.");
		if (!al_init_image_addon()) throw ("Failed to initialize allegro image support.");

	}
	catch (const char* e) {
		std::cerr << e << std::endl;
		return false;

	}
	catch (const std::exception& e) {
		std::cerr << "Unexpected Allegro 5 initialization error: " << e.what() << std::endl;
		return false;

	}
	return true;
}


const static bool INITIALIZE_ALLEGRO = initializeAllegro5();


#endif
