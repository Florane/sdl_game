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
``[`Tilemap`](api/Rect.md#structTilemap)` `[`ground`](#structLevel_1a144f165554a1661884bedba63a294047) | 
``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`platforms`](#structLevel_1a1ff993cd54fac87819ae33d705197582) | 

## Члены  

#### ``[`Tilemap`](api/Rect.md#structTilemap)` `[`ground`](#structLevel_1a144f165554a1661884bedba63a294047) 

#### ``[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` `[`platforms`](#structLevel_1a1ff993cd54fac87819ae33d705197582) 

