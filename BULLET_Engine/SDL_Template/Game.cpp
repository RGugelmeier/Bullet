#include "Game.h"
#include "Timer.h"
#include "SceneManager.h"

SDL_Texture* playerTexture;
SDL_Rect srcRec, destRec;

Game::Game()
{
	timer = nullptr;
}

Game::~Game()
{

}

void Game::OnCreate(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
{
	int flags = 0;
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		timer = new Timer();

		/*renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}*/

		//currentScene = new Scene0(window);

		isRunning = true;
	}
	else
	{
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		isRunning = false;
	}

	//playerTexture = TextureManager::loadTexture("C:/GameDev/GameProductionsAssignment/Assets/Images/shyGuy.png", renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_p:
			if (timer->isPaused() == false)
			{
			timer->Pause();
			}
			else if (timer->isPaused() == true)
			{
				timer->Unpause();
			}
			break;
		}
	}
}

void Game::update()
{
	timer->Start();
	while (isRunning)
	{
		Uint32 currentTicks = timer->GetTicks();

		std::cout << currentTicks << "\n";

		handleEvents();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, playerTexture, NULL, &destRec);

	SDL_RenderPresent(renderer);
}

/*void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	IMG_Quit();
	std::cout << "Game cleaned." << std::endl;
}*/