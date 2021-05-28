# Файл `ComplexCollision` 

Дополнительные функции для выисления столкновений

Функции для оптимизации и проверки столкновений между множеством объектов

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`tilemapToStack`](#group__ComplexCollision_1gae33a3ca871552d46b7ec86dc7b30ed56)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`Tilemap`](api/Rect.md#structTilemap)` & tilemap,`[`ObjectStack`](api/Collision.md#structObjectStack)` & stack)`            | Добавить все тайлы, с которыми возможно столкновение, в список объектов
`void `[`platformsToStack`](#group__ComplexCollision_1ga97d1528ea4a224ceac1d8036669ea8de)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & platforms,`[`ObjectStack`](api/Collision.md#structObjectStack)` & stack)`            | Добавить все платформы, с которыми возможно столкновение, в список объектов

## Члены  

#### `void `[`tilemapToStack`](#group__ComplexCollision_1gae33a3ca871552d46b7ec86dc7b30ed56)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`Tilemap`](api/Rect.md#structTilemap)` & tilemap,`[`ObjectStack`](api/Collision.md#structObjectStack)` & stack)` 

Добавить все тайлы, с которыми возможно столкновение, в список объектов

#### Параметры
* `parent` Динамический объект 

* `tilemap` Тайловая карта 

* `stack` Список объектов

#### `void `[`platformsToStack`](#group__ComplexCollision_1ga97d1528ea4a224ceac1d8036669ea8de)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & platforms,`[`ObjectStack`](api/Collision.md#structObjectStack)` & stack)` 

Добавить все платформы, с которыми возможно столкновение, в список объектов

#### Параметры
* `parent` Динамический объект 

* `platforms` Список полатформ 

* `stack` Список объектов

