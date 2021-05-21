# Файл `Platform` 

Платформа

Внутриигровая платформа и её основные функции

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initPlatform`](#group__Platform__1ga36703df20283cb5c2d241323a44008e6)`(`[`Platform`](api/Platform.md#structPlatform)` & platform,`[`Rect`](api/Rect.md#structRect)` position,`[`Rect`](api/Rect.md#structRect)` movement,double speed,char mainDiagonal)`            | Инициализация и установка платформы
`void `[`stepPlatform`](#group__Platform__1ga602a98e6e879f6831aa768f2942814bc)`(`[`Platform`](api/Platform.md#structPlatform)` & platform)`            | Передвинуть платформу на 1 кадр
`struct `[`Platform`](#structPlatform) | Платформа

## Члены  

#### `void `[`initPlatform`](#group__Platform__1ga36703df20283cb5c2d241323a44008e6)`(`[`Platform`](api/Platform.md#structPlatform)` & platform,`[`Rect`](api/Rect.md#structRect)` position,`[`Rect`](api/Rect.md#structRect)` movement,double speed,char mainDiagonal)` 

Инициализация и установка платформы

#### Параметры
* `platform` Платформа 

* `position` Позиция и раазмер платформы 

* `movement` Границы разрешенного движения для платформы 

* `speed` Скорость платформы 

* `mainDiagonal` По какой диагонали movement движется платформа. 1 - главная, -1 - дополнительная

#### `void `[`stepPlatform`](#group__Platform__1ga602a98e6e879f6831aa768f2942814bc)`(`[`Platform`](api/Platform.md#structPlatform)` & platform)` 

Передвинуть платформу на 1 кадр

#### Параметры
* `platform` Платформа

# struct `Platform` 

Платформа

#### Параметры
* `position` Позиция и раазмер платформы 

* `movement` Границы разрешенного движения для платформы 

* `speed` Скорость платформы 

* `mainDiagonal` Техническое. Проверять ли выход за границы movement

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Rect`](api/Rect.md#structRect)` `[`position`](#structPlatform_1a17db40ade5442f3b9f3ed84e313e5d7f) | 
``[`Rect`](api/Rect.md#structRect)` `[`movement`](#structPlatform_1ac26cef8561ccdcc810f3f1390c4a1016) | 
``[`Vector`](api/Rect.md#structVector)` `[`speed`](#structPlatform_1ac7b7737be484fd3dab65c41b152e03cb) | 
`bool `[`checkBoundary`](#structPlatform_1a701d5486811412d826275228a939f4bf) | 

## Члены  

#### ``[`Rect`](api/Rect.md#structRect)` `[`position`](#structPlatform_1a17db40ade5442f3b9f3ed84e313e5d7f) 

#### ``[`Rect`](api/Rect.md#structRect)` `[`movement`](#structPlatform_1ac26cef8561ccdcc810f3f1390c4a1016) 

#### ``[`Vector`](api/Rect.md#structVector)` `[`speed`](#structPlatform_1ac7b7737be484fd3dab65c41b152e03cb) 

#### `bool `[`checkBoundary`](#structPlatform_1a701d5486811412d826275228a939f4bf) 

