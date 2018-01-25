#pragma once

#include <SDL.h>
#include <string>
#include "utility.h"
#include "Representation.h"

namespace GE_View {

	class SDL_2DRepresentation : public Representation {
	private:
		SDL_Texture* _texture;
		SDL_Renderer* _renderer;

	public:
		SDL_2DRepresentation();
		SDL_2DRepresentation(std::string filename, SDL_Renderer* renderer, GE_Model::Rect rect);

		void loadSprite(std::string filename);

		virtual void draw();
	};
}

