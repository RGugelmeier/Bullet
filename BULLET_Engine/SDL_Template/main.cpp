#include "SDL.h"
#include "Timer.h"
#include "Game.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Game* game = new Game;

	game->OnCreate("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,600,400,false);
	//game->handleEvents();
	game->update();

	//SDL_Init(SDL_INIT_EVERYTHING); //Initialize SDL
	//SDL_Window* window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN); //Create window
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); //Create renderer

	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);

	//SDL_Delay(3000);

	return 0;
}