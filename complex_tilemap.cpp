#include "complex_tilemap.hpp"
#include "draw.hpp"

void drawTilemap(SDL_Renderer*& renderer, Tilemap& tilemap, Player& player, SDL_Texture** tilemapTextures)
{
    int shiftX = (player.player.pos.x-350)/TILE_SIZE, shiftY = (player.player.pos.y-250)/TILE_SIZE;
    for(int x = 0;x <= 800/TILE_SIZE && x+shiftX < tilemap.sizeX;x++)
    {
        for(int y = 0;y <= 600/TILE_SIZE && y+shiftY < tilemap.sizeY;y++)
        {
            if(x+shiftX > 0 && y+shiftY > 0)
                if(tilemap.tiles[x+shiftX][y+shiftY] > 0)
                {
                    SDL_Rect drawRect = rectToSDL_Rect(shiftFromPlayer(tileToRect(x+shiftX,y+shiftY),player));
                    drawTexture(renderer,tilemapTextures[tilemap.tiles[x+shiftX][y+shiftY]-1],&drawRect);
                }
        }
    }
}
