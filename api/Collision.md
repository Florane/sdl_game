# Файл `Collision` 

Декоратор для меню

Функции для оптимизации и проверки столкновений между множеством объектов

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initObject`](#group__Collision_1ga757bdef5bae0aec181d0de4fb7b047de)`(`[`Object`](api/Collision.md#structObject)` & object,`[`Rect`](api/Rect.md#structRect)` position,`[`Vector`](api/Rect.md#structVector)` movement)`            | Инициализация объекта
`void `[`initObject`](#group__Collision_1ga8f144cb45a65ba6a5ca0f1fd1e91ac98)`(`[`Object`](api/Collision.md#structObject)` & object,`[`Rect`](api/Rect.md#structRect)` position)`            | 
`void `[`initObject`](#group__Collision_1ga7f8afb930d45a4ea3dc780cba3bb0500)`(`[`Object`](api/Collision.md#structObject)` & object)`            | 
`bool `[`collideObjects`](#group__Collision_1gacc07b3510b36c3a72dadbd098f2872e4)`(`[`Object`](api/Collision.md#structObject)` & object1,`[`Object`](api/Collision.md#structObject)` & object2,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & time)`            | Проверка столкновения динамического и постоянного объекта
`bool `[`resolveObjects`](#group__Collision_1gaf79680d6be4d46a99f2313f4712cac27)`(`[`Object`](api/Collision.md#structObject)` & object1,`[`Object`](api/Collision.md#structObject)` & object2,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & time)`            | Разрешение столкновения
`void `[`initObjectStack`](#group__Collision_1ga6ea1166488f9666c5b1092e7c758df30)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)`            | Инициализация списка объектов
`void `[`setObject`](#group__Collision_1ga3600913a268b3c2235a3ff11f0f93e95)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack,`[`Object`](api/Collision.md#structObject)` & object)`            | Добавить объект в конец списка
`void `[`sortObjectList`](#group__Collision_1ga6e529cfa27917f1bc7a25c5aea3c4034)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)`            | Отсортировать список
`struct `[`Object`](#structObject) | Физический объект
`struct `[`ObjectStack`](#structObjectStack) | Список объектов

## Члены  

#### `void `[`initObject`](#group__Collision_1ga757bdef5bae0aec181d0de4fb7b047de)`(`[`Object`](api/Collision.md#structObject)` & object,`[`Rect`](api/Rect.md#structRect)` position,`[`Vector`](api/Rect.md#structVector)` movement)` 

Инициализация объекта

#### Параметры
* `object` Объект 

* `position` Позиция 

* `movement` Скорость

#### `void `[`initObject`](#group__Collision_1ga8f144cb45a65ba6a5ca0f1fd1e91ac98)`(`[`Object`](api/Collision.md#structObject)` & object,`[`Rect`](api/Rect.md#structRect)` position)` 

#### `void `[`initObject`](#group__Collision_1ga7f8afb930d45a4ea3dc780cba3bb0500)`(`[`Object`](api/Collision.md#structObject)` & object)` 

#### `bool `[`collideObjects`](#group__Collision_1gacc07b3510b36c3a72dadbd098f2872e4)`(`[`Object`](api/Collision.md#structObject)` & object1,`[`Object`](api/Collision.md#structObject)` & object2,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & time)` 

Проверка столкновения динамического и постоянного объекта

#### Параметры
* `object1` `object2` Объект 

* `contact` Точка столкновения 

* `normal` Перпендикуляр к плоскости столкновения 

* `time` Время столкновения от 0.0 до 1.0

#### `bool `[`resolveObjects`](#group__Collision_1gaf79680d6be4d46a99f2313f4712cac27)`(`[`Object`](api/Collision.md#structObject)` & object1,`[`Object`](api/Collision.md#structObject)` & object2,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & time)` 

Разрешение столкновения

#### Параметры
* `object1` Динамический объект 

* `object2` Статический объект 

* `contact` Точка столкновения 

* `normal` Перпендикуляр к плоскости столкновения 

* `time` Время столкновения от 0.0 до 1.0

#### `void `[`initObjectStack`](#group__Collision_1ga6ea1166488f9666c5b1092e7c758df30)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)` 

Инициализация списка объектов

#### Параметры
* `objectStack` Список объектов

#### `void `[`setObject`](#group__Collision_1ga3600913a268b3c2235a3ff11f0f93e95)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack,`[`Object`](api/Collision.md#structObject)` & object)` 

Добавить объект в конец списка

#### Параметры
* `objectStack` Список объектов 

* `object` Объект

#### `void `[`sortObjectList`](#group__Collision_1ga6e529cfa27917f1bc7a25c5aea3c4034)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)` 

Отсортировать список

#### Параметры
* `objectStack` Список объектов

# struct `Object` 

Физический объект

#### Параметры
* `position` Позиция объекта 

* `movement` Скорость объекта

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Rect`](api/Rect.md#structRect)` `[`position`](#structObject_1a48b1363eae3b9b89937529451db2717f) | 
``[`Vector`](api/Rect.md#structVector)` `[`movement`](#structObject_1a8445846cf133134ec8718c0de655ab51) | 

## Члены  

#### ``[`Rect`](api/Rect.md#structRect)` `[`position`](#structObject_1a48b1363eae3b9b89937529451db2717f) 

#### ``[`Vector`](api/Rect.md#structVector)` `[`movement`](#structObject_1a8445846cf133134ec8718c0de655ab51) 

# struct `ObjectStack` 

Список объектов

#### Параметры
* `objects` Массив объектов 

* `size` Максимальный размер списка 

* `iter` Последний доступный элемент списка

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Object`](api/Collision.md#structObject)` * `[`objects`](#structObjectStack_1a26c9d3759b7545b6880f7fca2eb8b31f) | 
`int `[`size`](#structObjectStack_1a52715498da06397aa2df4ffccbef79b3) | 
`int `[`iter`](#structObjectStack_1ae5101cab86d4de732df9281a7c73834d) | 

## Члены  

#### ``[`Object`](api/Collision.md#structObject)` * `[`objects`](#structObjectStack_1a26c9d3759b7545b6880f7fca2eb8b31f) 

#### `int `[`size`](#structObjectStack_1a52715498da06397aa2df4ffccbef79b3) 

#### `int `[`iter`](#structObjectStack_1ae5101cab86d4de732df9281a7c73834d) 

