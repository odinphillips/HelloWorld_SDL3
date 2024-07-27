#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static int Init() {
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) {
        SDL_Log("SDL_Init() Error: %s", SDL_GetError());
        return -1;
    }
    
    window = SDL_CreateWindow("HelloWorld SDL3", 640, 480, 0);
    if (!window) {
        SDL_Log("SDL_CreateWindow() Error: ", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer() Error: ", SDL_GetError());
        return -1;
    }

    return 0;
}

static void Term() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

static void Start() {
    SDL_Event event;
    SDL_bool running = SDL_TRUE;

    SDL_FRect mouseRect;
    mouseRect.x = mouseRect.y = -1000; // ensure it's offscreen at startup
    mouseRect.w = mouseRect.h = 50;

    // main loop
    while (running) {
        // go through all pending events until there are no more
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: // triggered on window close
                    running = SDL_FALSE;
                    break;
                case SDL_EVENT_KEY_DOWN: // triggered when user presses ESC key
                    if (event.key.key == SDLK_ESCAPE) {
                        running = SDL_FALSE;
                    }
                case SDL_EVENT_MOUSE_MOTION:
                    mouseRect.x = event.motion.x - (mouseRect.w / 2.0f);
                    mouseRect.y = event.motion.y - (mouseRect.h / 2.0f);
                    break;
            }
        }

        // sine wave with 3 second period
        float sineWave = SDL_sinf((((float)(SDL_GetTicks() % 3000)) / 3000.0f) * 2.0f * SDL_PI_F);
        // multiply amplitude by 127 and shift by +127 to get 0..254 color range
        Uint8 r = (Uint8)(sineWave * 127.0f) + 127;
        // set shade of red
        SDL_SetRenderDrawColor(renderer, r, 0, 0, 255); // for SDL_RenderClear()

        // clear the window to red fade color
        SDL_RenderClear(renderer);

        // set draw color to white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // for SDL_RenderFillRect()

        // draw mouse rectangle
        SDL_RenderFillRect(renderer, &mouseRect);

        // draw everything to screen
        SDL_RenderPresent(renderer);
    }
}

int main(int argc, char* argv[]) {
    int ret = Init();
    if (ret == 0) {    
        Start();
    }
    Term();
    return ret;
}
