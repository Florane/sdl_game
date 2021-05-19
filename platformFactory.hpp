#pragma once
#include "platform.hpp"

struct PlatformFactory
{
    Platform* platforms;
    int size;
};

void initPlatformFactory(PlatformFactory& factory);
void freePlatformFactory(PlatformFactory& factory);
void loadPlatforms(const char* name, PlatformFactory& factory);
