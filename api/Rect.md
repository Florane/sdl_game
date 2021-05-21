# Файл `Rect` 

Простые прямоугольники

Описание всех основных вычислений и понятий для параллельных осям прямоугольников

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`double `[`_abs`](#group__Rect__1ga135a12b7b7998efd52ab8bf86cb89bb0)`(const double & a)`            | Модуль числа
``[`Vector`](api/Rect.md#structVector)` `[`addVectors`](#group__Rect__1gac9f7258591a63811a82420c50b9a7696)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const `[`Vector`](api/Rect.md#structVector)` & v2)`            | Сложить 2 вектора
``[`Vector`](api/Rect.md#structVector)` `[`subVectors`](#group__Rect__1ga380a2edcfd0db15df3ac34b2586d5aed)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const `[`Vector`](api/Rect.md#structVector)` & v2)`            | Вычесть 2 вектора
``[`Vector`](api/Rect.md#structVector)` `[`multVectors`](#group__Rect__1ga9e39d63a508d7411440773f61df53869)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const `[`Vector`](api/Rect.md#structVector)` & v2)`            | Перемножить координаты 2 векторов
``[`Vector`](api/Rect.md#structVector)` `[`addVectorNumber`](#group__Rect__1ga55d4fb62909f5e42c6c64cb871aed0c5)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const double & v2)`            | Добавляет число к координатам вектора
``[`Vector`](api/Rect.md#structVector)` `[`subVectorNumber`](#group__Rect__1ga4968265af852d621ca413da8371bbb2a)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const double & v2)`            | Вычитает число из координат вектора
``[`Vector`](api/Rect.md#structVector)` `[`multVectorNumber`](#group__Rect__1ga8e6e4be3126c4f9bf94ee40e7d2dbb9e)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const double & v2)`            | Умножает координаты вектора на число
`bool `[`collideRectRect`](#group__Rect__1ga741a7a3965b40209810b7dee5eb4c961)`(const `[`Rect`](api/Rect.md#structRect)` * r1,const `[`Rect`](api/Rect.md#structRect)` * r2)`            | Проверить пересечение двух прямоугольников
`bool `[`collideRayRect`](#group__Rect__1ga14528e2d609de08aeaf75a1a60e90b8d)`(const `[`Vector`](api/Rect.md#structVector)` & origin,const `[`Vector`](api/Rect.md#structVector)` & direction,const `[`Rect`](api/Rect.md#structRect)` & target,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & nearTime)`            | Проверить пересечение отрезка и прямоугольника
`void `[`initTilemap`](#group__Rect__1gac548f55c877325a954c4fdfd873b0e1a)`(`[`Tilemap`](api/Rect.md#structTilemap)` & tiles)`            | Инициализация тайловой карты
`void `[`freeTilemap`](#group__Rect__1ga5c272d06c8fe135f52a65d514501b6d5)`(`[`Tilemap`](api/Rect.md#structTilemap)` & tiles)`            | Освободить память тайловой карты
`void `[`loadTilemap`](#group__Rect__1gac6207aee6fa4f9c223618739676639f9)`(const char * name,`[`Tilemap`](api/Rect.md#structTilemap)` & tiles)`            | Загрузить карту из файла
``[`Rect`](api/Rect.md#structRect)` `[`tileToRect`](#group__Rect__1gac0a9bc4adcbc9ff9ed6bcc75d0546bac)`(int x,int y)`            | Возвращает видимый прямоугольник тайла
`struct `[`Vector`](#structVector) | Вектор
`struct `[`Rect`](#structRect) | Прямоугольник
`struct `[`Tilemap`](#structTilemap) | Тайловая карта

## Члены  

#### `double `[`_abs`](#group__Rect__1ga135a12b7b7998efd52ab8bf86cb89bb0)`(const double & a)` 

Модуль числа

#### Параметры
* `a` Число 

#### Возвращает
double Модуль

#### ``[`Vector`](api/Rect.md#structVector)` `[`addVectors`](#group__Rect__1gac9f7258591a63811a82420c50b9a7696)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const `[`Vector`](api/Rect.md#structVector)` & v2)` 

Сложить 2 вектора

#### Параметры
* `v1` Вектор 

* `v2` Вектор 

#### Возвращает
[Vector](api/Rect.md#structVector) Вектор - сумма

#### ``[`Vector`](api/Rect.md#structVector)` `[`subVectors`](#group__Rect__1ga380a2edcfd0db15df3ac34b2586d5aed)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const `[`Vector`](api/Rect.md#structVector)` & v2)` 

Вычесть 2 вектора

#### Параметры
* `v1` Вектор 

* `v2` Вектор 

#### Возвращает
[Vector](api/Rect.md#structVector) Вектор - сумма

#### ``[`Vector`](api/Rect.md#structVector)` `[`multVectors`](#group__Rect__1ga9e39d63a508d7411440773f61df53869)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const `[`Vector`](api/Rect.md#structVector)` & v2)` 

Перемножить координаты 2 векторов

#### Параметры
* `v1` Вектор 

* `v2` Вектор 

#### Возвращает
[Vector](api/Rect.md#structVector) Вектор с произведениями

#### ``[`Vector`](api/Rect.md#structVector)` `[`addVectorNumber`](#group__Rect__1ga55d4fb62909f5e42c6c64cb871aed0c5)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const double & v2)` 

Добавляет число к координатам вектора

#### Параметры
* `v1` Вектор 

* `v2` Число 

#### Возвращает
[Vector](api/Rect.md#structVector) Вектор - результат

#### ``[`Vector`](api/Rect.md#structVector)` `[`subVectorNumber`](#group__Rect__1ga4968265af852d621ca413da8371bbb2a)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const double & v2)` 

Вычитает число из координат вектора

#### Параметры
* `v1` Вектор 

* `v2` Число 

#### Возвращает
[Vector](api/Rect.md#structVector) Вектор - результат

#### ``[`Vector`](api/Rect.md#structVector)` `[`multVectorNumber`](#group__Rect__1ga8e6e4be3126c4f9bf94ee40e7d2dbb9e)`(const `[`Vector`](api/Rect.md#structVector)` & v1,const double & v2)` 

Умножает координаты вектора на число

#### Параметры
* `v1` Вектор 

* `v2` Число 

#### Возвращает
[Vector](api/Rect.md#structVector) Вектор - результат

#### `bool `[`collideRectRect`](#group__Rect__1ga741a7a3965b40209810b7dee5eb4c961)`(const `[`Rect`](api/Rect.md#structRect)` * r1,const `[`Rect`](api/Rect.md#structRect)` * r2)` 

Проверить пересечение двух прямоугольников

#### Параметры
* `r1` указатель на прямоугольник 

* `r2` указатель на прямоугольник 

#### Возвращает
bool Пересекаются-ли прямоугольники

#### `bool `[`collideRayRect`](#group__Rect__1ga14528e2d609de08aeaf75a1a60e90b8d)`(const `[`Vector`](api/Rect.md#structVector)` & origin,const `[`Vector`](api/Rect.md#structVector)` & direction,const `[`Rect`](api/Rect.md#structRect)` & target,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & nearTime)` 

Проверить пересечение отрезка и прямоугольника

#### Параметры
* `origin` Начало отрезка 

* `direction` Направление отрезка 

* `target` Объект пересечения 

* `contact` Точка пересечения 

* `normal` Перпендикуляр к плоскости пересечения 

* `nearTime` Позиция точки пересечения на отрезке от 0.0 до 1.0 

#### Возвращает
bool Пересекаются-ли отрезок и прямоугольник

#### `void `[`initTilemap`](#group__Rect__1gac548f55c877325a954c4fdfd873b0e1a)`(`[`Tilemap`](api/Rect.md#structTilemap)` & tiles)` 

Инициализация тайловой карты

#### Параметры
* `tiles` Тайловая карта

#### `void `[`freeTilemap`](#group__Rect__1ga5c272d06c8fe135f52a65d514501b6d5)`(`[`Tilemap`](api/Rect.md#structTilemap)` & tiles)` 

Освободить память тайловой карты

#### Параметры
* `tiles` Тайловая карта

#### `void `[`loadTilemap`](#group__Rect__1gac6207aee6fa4f9c223618739676639f9)`(const char * name,`[`Tilemap`](api/Rect.md#structTilemap)` & tiles)` 

Загрузить карту из файла

#### Параметры
* `name` Имя файла 

* `tiles` Тайловая карта

#### ``[`Rect`](api/Rect.md#structRect)` `[`tileToRect`](#group__Rect__1gac0a9bc4adcbc9ff9ed6bcc75d0546bac)`(int x,int y)` 

Возвращает видимый прямоугольник тайла

#### Параметры
* `x` `y` 

#### Возвращает
[Rect](api/Rect.md#structRect) Видимый прямоугольник тайла

# struct `Vector` 

Вектор

Вектор с началом в точке 0,0 
#### Параметры
* `x` `y` Направление

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`double `[`x`](#structVector_1a133722e00601091cb2075219da5da6e4) | 
`double `[`y`](#structVector_1a09a21a140718f234eea348d5058cee0b) | 

## Члены  

#### `double `[`x`](#structVector_1a133722e00601091cb2075219da5da6e4) 

#### `double `[`y`](#structVector_1a09a21a140718f234eea348d5058cee0b) 

# struct `Rect` 

Прямоугольник

#### Параметры
* `pos` Позиция 

* `size` Размер

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Vector`](api/Rect.md#structVector)` `[`pos`](#structRect_1a1bdf49ddea8efa3faa482ef4822b2ee5) | 
``[`Vector`](api/Rect.md#structVector)` `[`size`](#structRect_1a2a9e3f2d32070b3eac1165a1c4aa0db9) | 

## Члены  

#### ``[`Vector`](api/Rect.md#structVector)` `[`pos`](#structRect_1a1bdf49ddea8efa3faa482ef4822b2ee5) 

#### ``[`Vector`](api/Rect.md#structVector)` `[`size`](#structRect_1a2a9e3f2d32070b3eac1165a1c4aa0db9) 

# struct `Tilemap` 

Тайловая карта

#### Параметры
* `sizeX` `sizeY` Размер тайловой карты 

* `tiles` Двумерный массив тайлов

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`int `[`sizeX`](#structTilemap_1ae294fbaeb17cdf8b3ce21d4e4862f725) | 
`int `[`sizeY`](#structTilemap_1acee00c90160900eb0a3c3305485d124f) | 
`char ** `[`tiles`](#structTilemap_1a849c94ef6a1a190439bf853a3a701e8a) | 

## Члены  

#### `int `[`sizeX`](#structTilemap_1ae294fbaeb17cdf8b3ce21d4e4862f725) 

#### `int `[`sizeY`](#structTilemap_1acee00c90160900eb0a3c3305485d124f) 

#### `char ** `[`tiles`](#structTilemap_1a849c94ef6a1a190439bf853a3a701e8a) 

