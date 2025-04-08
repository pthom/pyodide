/*
This file can also be compiled as a standalone emscripten app with the following command:

 emcc daft_lib.cpp -o daft_lib.html \
  -sUSE_SDL=2 \
  -sMAX_WEBGL_VERSION=2  \
  -D BUILD_EMS_APP \
  --shell-file ${EMSDK}/upstream/emscripten/src/shell_minimal.html


*/

#include <SDL.h>
#include <stdio.h>

void dummy_sdl_call()
{
    printf("About to call SDL_Init\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return;
    }

    printf("Calling SDL_SetHint\n");
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");

    printf("About to call SDL_CreateWindow\n");
    int window_flags = SDL_WINDOW_OPENGL;
    SDL_Window* window = SDL_CreateWindow(
        "Dummy Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        window_flags
    );
    printf("SDL_CreateWindow called\n");

    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    } else {
        printf("SDL_CreateWindow succeeded\n");
        SDL_DestroyWindow(window);
    }

    printf("About to call SDL_Quit\n");
    SDL_Quit();
    printf("SDL_Quit called\n");
}

#ifndef BUILD_EMS_APP
#include <nanobind/nanobind.h>
NB_MODULE(daft_lib, m) {
    m.def("dummy_sdl_call", &dummy_sdl_call);
}
#else

int main(int argc, char* argv[])
{
    dummy_sdl_call();
    return 0;
}

#endif
