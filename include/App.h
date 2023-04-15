#include <cmath>
#include <vector>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

class App
{
    SDL_Renderer *renderer;
    SDL_Window *window;

    float min_zoom = -2.5;
    float max_zoom = 2.5;

    float loop_index = 1;

    void update();
    void draw();
public:
    App();
    void run();
};
