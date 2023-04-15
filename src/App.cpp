#include "App.h"


App::App()
{
    
}

void App::update()
{
	loop_index += 0.01;
}

void App::draw()
{
	float max_iterations = 50;
	float max_z = max_zoom*2*cos(loop_index)+0.7;
	float min_z = min_zoom*cos(loop_index);

	for (float j = 0; j < WINDOW_HEIGHT; j++) {
		for (float i = 0; i < WINDOW_WIDTH; i++)
		{
			float a = ( i*max_z/WINDOW_WIDTH ) + min_z;
			float b = ( j*max_z/WINDOW_HEIGHT ) + min_z;

			float initial_a = a;
			float initial_b = b;

			unsigned int n = 0;

			while (n < max_iterations)
			{
				float real = (a*a) - (b*b);
				float complex = 2*a*b;

				a = real + initial_a;
				b = complex + initial_b;

				if (abs(a + b) > 16)
					break;

				n++;
			}

			float bright = n*255/max_iterations;

			if (n == max_iterations) bright = 0;

			SDL_SetRenderDrawColor(renderer,
				bright,
				bright,
				bright,
				255);
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}
}

void App::run()
{
    SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);

    SDL_Event event;

    while (1)
    {
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;

		SDL_RenderClear(renderer);

		update();
		draw();

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
