#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Scene.h"
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	void OnCreate(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	//void clean();
	inline bool running() { return isRunning; };
	SDL_Renderer* renderer;
	class Timer* timer;

private:
	bool isRunning;
	SDL_Window* window;
	Scene* currentScene;

};

#endif // !GAME_HPP
