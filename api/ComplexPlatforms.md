# Файл `ComplexPlatforms` 

Декоратор для платформ

Дополнительные функции для использования со списками платформ

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`drawPlatforms`](#group__ComplexPlatforms_1ga579654e9dcac990ef2981d67524c6af6)`(SDL_Renderer *& renderer,`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & platforms,`[`Player`](api/Player.md#structPlayer)` & player,SDL_Texture * platformTexture)`            | Отрисовать все платформы на экране платформы относительно игрока
`void `[`stepPlatforms`](#group__ComplexPlatforms_1ga0317d57361e2bea83cd1502983f021ab)`(`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & platforms)`            | Передвинуть все платформы на 1 кадр

## Члены  

#### `void `[`drawPlatforms`](#group__ComplexPlatforms_1ga579654e9dcac990ef2981d67524c6af6)`(SDL_Renderer *& renderer,`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & platforms,`[`Player`](api/Player.md#structPlayer)` & player,SDL_Texture * platformTexture)` 

Отрисовать все платформы на экране платформы относительно игрока

#### Параметры
* `renderer` Рендерер 

* `platforms` Список платформ 

* `player` Игрок 

* `platformTexture` Текстура платформы

#### `void `[`stepPlatforms`](#group__ComplexPlatforms_1ga0317d57361e2bea83cd1502983f021ab)`(`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & platforms)` 

Передвинуть все платформы на 1 кадр

#### Параметры
* `platforms` Список платформ

