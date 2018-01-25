#include "SDL_2DManager.h"

namespace GE_View {

	SDL_2DManager::SDL_2DManager() {}

	SDL_2DManager::SDL_2DManager(SDL_Renderer* renderer) {
		_renderer = renderer;
	}

	void SDL_2DManager::Renderer(SDL_Renderer* renderer) {
		_renderer = renderer;
	}

	void SDL_2DManager::drawAll() {
		for (std::vector<ReprPtr>::iterator it = List().begin(); it != List().end(); it++) {
			(*it)->draw();
		}
		SDL_RenderPresent(_renderer);
	}
}