# Файл `Collision` 

Коллизия

Функции для оптимизации и проверки столкновений между множеством объектов

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initObject`](#group__Collision_1ga757bdef5bae0aec181d0de4fb7b047de)`(`[`Object`](api/Collision.md#structObject)` & object,`[`Rect`](api/Rect.md#structRect)` position,`[`Vector`](api/Rect.md#structVector)` movement)`            | Инициализация объекта
`void `[`initObject`](#group__Collision_1ga8f144cb45a65ba6a5ca0f1fd1e91ac98)`(`[`Object`](api/Collision.md#structObject)` & object,`[`Rect`](api/Rect.md#structRect)` position)`            | 
`void `[`initObject`](#group__Collision_1ga7f8afb930d45a4ea3dc780cba3bb0500)`(`[`Object`](api/Collision.md#structObject)` & object)`            | 
`bool `[`collideObjects`](#group__Collision_1gacc07b3510b36c3a72dadbd098f2872e4)`(`[`Object`](api/Collision.md#structObject)` & object1,`[`Object`](api/Collision.md#structObject)` & object2,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & time)`            | Проверка столкновения динамического и постоянного объекта
`bool `[`resolveObjects`](#group__Collision_1gaf79680d6be4d46a99f2313f4712cac27)`(`[`Object`](api/Collision.md#structObject)` & object1,`[`Object`](api/Collision.md#structObject)` & object2,`[`Vector`](api/Rect.md#structVector)` & contact,`[`Vector`](api/Rect.md#structVector)` & normal,double & time)`            | Разрешение столкновения
`void `[`initObjectStack`](#group__Collision_1ga614b1fb4dcd4694d92b3dbf57c4d9922)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack,int size)`            | Инициализация списка объектов
`double `[`getDistance`](#group__Collision_1ga8e850f15e87fcf2336d43a1a5d65cc67)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`Object`](api/Collision.md#structObject)` & object)`            | Расстояние между двумя объектами
`void `[`setObject`](#group__Collision_1ga4e7d21f10189aee59db4e7786acf1566)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack,`[`Object`](api/Collision.md#structObject)` & object)`            | Добавить объект в конец списка
`void `[`sortObjectStack`](#group__Collision_1ga8ac2d7768536c29747f461f930282ff1)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)`            | Отсортировать список
`int `[`resolveObjectStack`](#group__Collision_1ga8b631ac4e5f836945b8b650ed06df7cb)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)`            | Разрешение столкновения со всеми объектами списка
`struct `[`Object`](#structObject) | Физический объект
`struct `[`Dist`](#structDist) | Техническое. Расстояние до объекта position.
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

#### `void `[`initObjectStack`](#group__Collision_1ga614b1fb4dcd4694d92b3dbf57c4d9922)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack,int size)` 

Инициализация списка объектов

#### Параметры
* `objectStack` Список объектов 

* `size` Размер списка

#### `double `[`getDistance`](#group__Collision_1ga8e850f15e87fcf2336d43a1a5d65cc67)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`Object`](api/Collision.md#structObject)` & object)` 

Расстояние между двумя объектами

#### Параметры
* `parent` Динамический объект 

* `object` Статический объект 

#### Возвращает
double Расстояние до точки касания со статическим объектом

#### `void `[`setObject`](#group__Collision_1ga4e7d21f10189aee59db4e7786acf1566)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack,`[`Object`](api/Collision.md#structObject)` & object)` 

Добавить объект в конец списка

#### Параметры
* `parent` Динамический объект 

* `objectStack` Список объектов 

* `object` Статический объект

#### `void `[`sortObjectStack`](#group__Collision_1ga8ac2d7768536c29747f461f930282ff1)`(`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)` 

Отсортировать список

#### Параметры
* `objectStack` Список объектов

#### `int `[`resolveObjectStack`](#group__Collision_1ga8b631ac4e5f836945b8b650ed06df7cb)`(`[`Object`](api/Collision.md#structObject)` & parent,`[`ObjectStack`](api/Collision.md#structObjectStack)` & objectStack)` 

Разрешение столкновения со всеми объектами списка

#### Параметры
* `parent` Динамический объект 

* `objectStack` Список статических объектов 

#### Возвращает
int Битовая маска

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

# struct `Dist` 

Техническое. Расстояние до объекта position.

#### Параметры
* `distance` Расстояние до объекта 

* `position` ID объекта

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`double `[`distance`](#structDist_1a9ba74dbc444fc368db01591ca782bd21) | 
`int `[`position`](#structDist_1ab7677964e350b6f77489e2c80835d972) | 

## Члены  

#### `double `[`distance`](#structDist_1a9ba74dbc444fc368db01591ca782bd21) 

#### `int `[`position`](#structDist_1ab7677964e350b6f77489e2c80835d972) 

# struct `ObjectStack` 

Список объектов

#### Параметры
* `objects` Массив объектов 

* `size` Максимальный размер списка 

* `iter` Последний доступный элемент списка 

* `distances` Массив расстояний до объектов

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Object`](api/Collision.md#structObject)` * `[`objects`](#structObjectStack_1a26c9d3759b7545b6880f7fca2eb8b31f) | 
`int `[`size`](#structObjectStack_1a52715498da06397aa2df4ffccbef79b3) | 
`int `[`iter`](#structObjectStack_1ae5101cab86d4de732df9281a7c73834d) | 
``[`Dist`](api/Collision.md#structDist)` * `[`distances`](#structObjectStack_1a06a3143c5be4e3a87d2728b362afa4cc) | 

## Члены  

#### ``[`Object`](api/Collision.md#structObject)` * `[`objects`](#structObjectStack_1a26c9d3759b7545b6880f7fca2eb8b31f) 

#### `int `[`size`](#structObjectStack_1a52715498da06397aa2df4ffccbef79b3) 

#### `int `[`iter`](#structObjectStack_1ae5101cab86d4de732df9281a7c73834d) 

#### ``[`Dist`](api/Collision.md#structDist)` * `[`distances`](#structObjectStack_1a06a3143c5be4e3a87d2728b362afa4cc) 

