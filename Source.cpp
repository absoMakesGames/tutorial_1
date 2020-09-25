#include <SDL.h>
#include <iostream>
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[]) {

	bool isRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) != NULL) {
		cout << "Failed to initialize SDL! ::" << SDL_GetError() << endl;
	}

	window = SDL_CreateWindow("SDL WINDOW!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		cout << "Failed to create window! ::" << SDL_GetError() << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while (isRunning) {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}


	// Cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}