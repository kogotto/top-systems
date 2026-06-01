#include <SDL3/SDL.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

#include <defs.hpp>
#include <FiguresCollection.hpp>
#include <generate.hpp>

namespace {
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

FiguresCollection figures;
}

SDL_AppResult SDL_AppInit(void** appState, int argc, char** argv) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(
                "figures",
                SCREEN_WIDTH, SCREEN_HEIGHT,
                0,
                &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(
            renderer,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_LOGICAL_PRESENTATION_LETTERBOX);

    generate(figures, 10);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appState, SDL_Event* event) {
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_UP:
        switch (event->key.scancode) {
        case SDL_SCANCODE_ESCAPE:
            return SDL_APP_SUCCESS;
        default:
            return SDL_APP_CONTINUE;
        }
    default:
        return SDL_APP_CONTINUE;
    }
}

SDL_AppResult SDL_AppIterate(void* appState) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (const auto& figure : figures.getAll()) {
        figure->draw(renderer);
    }

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appState, SDL_AppResult result) {
}
