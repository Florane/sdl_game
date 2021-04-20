#include "menu.hpp"

void initButtons(Buttons* buttons, int sizeX, int sizeY)
{
    double actualSizeY = sizeY/(AMOUNT*2.0-1);
    for(int i = 0;i < AMOUNT;i++)
    {
        buttons->buttons[i] = {0,actualSizeY*(i*2),sizeX,actualSizeY};
    }
    buttons->selected = 1;
}
