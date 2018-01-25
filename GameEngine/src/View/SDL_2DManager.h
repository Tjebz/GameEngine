#pragma once

#include <SDL.h>
#include "RepresentationManager.h"

namespace GE_View {

	class SDL_2DManager : public RepresentationManager{
	private:
		SDL_Renderer* _renderer;

	public:
		SDL_2DManager();
		SDL_2DManager(SDL_Renderer* renderer);

		void Renderer(SDL_Renderer* renderer);

		virtual void drawAll();
	};
}