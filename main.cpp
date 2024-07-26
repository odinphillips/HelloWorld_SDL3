#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static int Create() {
    auto ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) {
        SDL_Log("SDL_Init() Error: %s", SDL_GetError());
        return -1;
    }
    // TODO: finish this off
    return 0;
}

static void Destroy() {
    // TODO: finish this off
    SDL_Quit();
}

static void Start() {
    // TODO: add simple SDL example
}

int main(int argc, char* argv[]) {
    auto ret = Create();
    if (ret == 0) {    
        Start();
    }
    Destroy();
    return ret;
}
