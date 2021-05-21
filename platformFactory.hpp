#pragma once
#include "platform.hpp"

/**
\defgroup PlatformFactory_idiot
@{
\brief Список существующих платформ

Список платформ и функции для загрузки и хранения платформ.
*/

///Список платформ
/**
\param platforms Массив платформ
\param size Размер массива
*/
struct PlatformFactory
{
    Platform* platforms;
    int size;
};

///Инициализация списка платформ
/**
\param factory Список платформ
*/
void initPlatformFactory(PlatformFactory& factory);

///Освобождение памяти под список
/**
\param factory Список платформ
*/
void freePlatformFactory(PlatformFactory& factory);

///Загрузка списка платформ из файла
/**
\param name Имя файла
\param factory Список платформ
*/
void loadPlatforms(const char* name, PlatformFactory& factory);

///@}
