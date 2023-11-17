#include "TileMap.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "TileMap.h"



TileMap::TileMap()
{
    // Initialization of the member array
    for (int i = 0; i < TILEMAP_WIDTH * TILEMAP_HEIGHT; ++i) {
        tile_map_[i] = 0;
    }
}
