#pragma once

#include <SDL.h>

namespace Graphics {

  SDL_Texture* LoadTexture(renderer, std::string fileName ){
    SDL_Surface* s = SDL_LoadBMP(filename.c_str());
    return SDL_CreateTextureFromSurface(renderer, s);
  }
  
  
}
