# Файл `Level` 

Уровень

Хранилище для всех данных, необходимых для загрузки и отрисовки уровня

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initLevel`](#group__Level__1ga7e4a56d60c085e76a1aebe958e595455)`(`[`Level`](api/Level.md#structLevel)` & level)`            | Инициализация уровня
`void `[`freeLevel`](#group__Level__1ga09fb76049d1190af2d0f43758ac7e21c)`(`[`Level`](api/Level.md#structLevel)` & level)`            | Очистка памяти уровня
`void `[`loadLevel`](#group__Level__1gabe7b191cec72ce5dfd0a0a40c954fce2)`(const char * name,`[`Level`](api/Level.md#structLevel)` & level)`            | Загрузка уровня из директории
`struct `[`Level`](#structLevel) | Уровень

## Члены  

#### `void `[`initLevel`](#group__Level__1ga7e4a56d60c085e76a1aebe958e595455)`(`[`Level`](api/Level.md#structLevel)` & level)` 

Инициализация уровня

#### Параметры
* `level` Уровень

#### `void `[`freeLevel`](#group__Level__1ga09fb76049d1190af2d0f43758ac7e21c)`(`[`Level`](api/Level.md#structLevel)` & level)` 

Очистка памяти уровня

#### Параметры
* `level` Уровень

#### `void `[`loadLevel`](#group__Level__1gabe7b191cec72ce5dfd0a0a40c954fce2)`(const char * name,`[`Level`](api/Level.md#structLevel)` & level)` 

Загрузка уровня из директории

#### Параметры
* `name` Имя директории с файлами уровня 

* `level` Уровень

# struct `Level` 

Уровень

#### Параметры
* `ground` Тайловая карта уровня 

* `platforms` Список платформ

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`int `[`id`](#structLevel_1acd7d99360a99ebbe89a9410c1741ae4b) | 
``[`Player`](api/Player.md#structPlayer)` `[`player`](#structLevel_1aae2f48ac36bd08832036e4ec37eb5b79) | 
``[`Tilemap`](api/Rect.md#structTilemap)` `[`ground`](#structLevel_1a144f165554a1661884bedba63a294047) | 
``[`Tilemap`](api/Rect.md#structTilemap)` `[`spikes`](#structLevel_1a667f1cbd16a6723da21d50125597def0) | 
``[`Tilemap`](api/Rect.md#structTilemap)` `[`coins`](#structLevel_1a2a75ce2c78deb967de2ffbd63d0bbe69) | 
``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`platforms`](#structLevel_1a1ff993cd54fac87819ae33d705197582) | 
``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`exit`](#structLevel_1a977af390db7f3432b9ec0da0fde6c129) | 
``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`enemies`](#structLevel_1a0f89997f8c58d600a4aa0a8b329753bc) | 

## Члены  

#### `int `[`id`](#structLevel_1acd7d99360a99ebbe89a9410c1741ae4b) 

#### ``[`Player`](api/Player.md#structPlayer)` `[`player`](#structLevel_1aae2f48ac36bd08832036e4ec37eb5b79) 

#### ``[`Tilemap`](api/Rect.md#structTilemap)` `[`ground`](#structLevel_1a144f165554a1661884bedba63a294047) 

#### ``[`Tilemap`](api/Rect.md#structTilemap)` `[`spikes`](#structLevel_1a667f1cbd16a6723da21d50125597def0) 

#### ``[`Tilemap`](api/Rect.md#structTilemap)` `[`coins`](#structLevel_1a2a75ce2c78deb967de2ffbd63d0bbe69) 

#### ``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`platforms`](#structLevel_1a1ff993cd54fac87819ae33d705197582) 

#### ``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`exit`](#structLevel_1a977af390db7f3432b9ec0da0fde6c129) 

#### ``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`enemies`](#structLevel_1a0f89997f8c58d600a4aa0a8b329753bc) 

