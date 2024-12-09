#include <SDL.h>
#include <stdio.h>



void dummy_sdl_call()
{

    printf("About to call SDL_init\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
        fprintf(stderr, "Error: %s\n", SDL_GetError());

    printf("About to call SDL_SetHint\n");
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
    printf("After SDL_SetHint\n");

}


#include <nanobind/nanobind.h>


NB_MODULE(daft_lib, m) {
    m.def("dummy_sdl_call", &dummy_sdl_call);
}
