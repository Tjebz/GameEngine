#include <iostream>
#include <SDL.h>

#include "Model/EntityManager.h"
#include "Model/MovableEntity.h"
#include "Controller/PlayerController.h"
#include "View/utility.h"
#include "View/SDL_2DManager.h"
#include "View/SDL_2DRepresentation.h"

using namespace GE_Model;
using namespace GE_View;
using namespace GE_Controller;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

ki::KeyInput convertSDL_EventToKeyInput(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case(SDLK_UP):
			return ki::UpPressed;
		case(SDLK_DOWN):
			return ki::DownPressed;
		case(SDLK_LEFT):
			return ki::LeftPressed;
		case(SDLK_RIGHT):
			return ki::RightPressed;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym) {
		case(SDLK_UP):
			return ki::UpReleased;
		case(SDLK_DOWN):
			return ki::DownReleased;
		case(SDLK_LEFT):
			return ki::LeftReleased;
		case(SDLK_RIGHT):
			return ki::RightReleased;
		}
	}
}

int main(int, char**) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("SpaceNinja", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		utility::logSDLError(std::cerr, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		utility::logSDLError(std::cerr, "SDL_CreateRenderer");
		utility::cleanup(window);
		SDL_Quit();
		return 1;
	}

	SDL_2DManager reprManager(renderer);
	EntityManager entityManager(&reprManager);
	MovableEntity *entity = new MovableEntity(320, 240 , 200, 200);
	entity->setRepresentation(ReprPtr(new SDL_2DRepresentation("../Resources/image.bmp", renderer, entity->getRect())));
	entity->setAcceleration(Vect(10, 10));
	entity->setMaxSpeed(20);
	EntityPtr ptr(entity);
	CtrlPtr controller(new PlayerController());
	entity->setController(controller);
	entityManager.addEntity(ptr);

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			else {
				ki::KeyInput input = convertSDL_EventToKeyInput(e);
				entityManager.resolveInput(input);
			}
		}
		entityManager.updateAll();
		SDL_RenderClear(renderer);
		reprManager.drawAll();
	}
	utility::cleanup(renderer, window);
	SDL_Quit();
	return 0;
}
