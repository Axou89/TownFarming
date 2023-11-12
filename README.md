# TownFarming

## Libraries required
- SDL2
- SDL2 Image
- SDL2 Mixer
- SDL2 TTF

## How to compile
```bash
g++ -O2 src/*.cpp -o bin/release/TownFarming -IC:/SDL2/include -Iinclude -LC:/SDL2/lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -mwindows
```