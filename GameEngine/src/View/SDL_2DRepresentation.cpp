#include "SDL_2DRepresentation.h"

namespace GE_View {

	SDL_2DRepresentation::SDL_2DRepresentation() : Representation() {}

	SDL_2DRepresentation::SDL_2DRepresentation(std::string filename, SDL_Renderer* renderer, GE_Model::Rect rect) {
		setRect(rect);
		_renderer = renderer;
		loadSprite(filename);
	}

	void SDL_2DRepresentation::loadSprite(std::string filename) {
		SDL_Surface *load = SDL_LoadBMP(filename.c_str());
		if (!load) {
			utility::logSDLError(std::cout, "LoadBMP");
		}
		else {
			SDL_BlendMode oldBlendMode;
			SDL_Surface* surface = SDL_CreateRGBSurface(load->flags, getRect().getWidth(), getRect().getHeigth(),
				load->format->BitsPerPixel, load->format->Rmask,
				load->format->Gmask, load->format->Bmask, load->format->Amask);
			SDL_GetSurfaceBlendMode(load, &oldBlendMode);
			SDL_SetSurfaceBlendMode(load, SDL_BLENDMODE_NONE);
			SDL_Rect rescale = { 0, 0, getRect().getWidth(), getRect().getHeigth() };
			SDL_BlitScaled(load, NULL, surface, &rescale);
			SDL_FreeSurface(load);
			SDL_SetSurfaceBlendMode(surface, oldBlendMode);

			if (!surface) {
				utility::logSDLError(std::cout, "BlitScaled");
			}
			_texture = SDL_CreateTextureFromSurface(_renderer, surface);
			SDL_FreeSurface(surface);
			if (!_texture) {
				utility::logSDLError(std::cout, "CreateTextureFromSurface");
			}
		}
	}

	void SDL_2DRepresentation::draw() {
		SDL_Rect sdl_rect = { getRect().getX(), getRect().getY(), getRect().getWidth(), getRect().getHeigth() };
		SDL_RenderCopy(_renderer, _texture, NULL, &sdl_rect);
	}
}