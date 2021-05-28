# Файл `Player` 

Игрок

Хранение данных и логика для игрока

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initPlayer`](#group__Player__1gaa88321e40a5c1289e1ac1ee071bd6c26)`(`[`Player`](api/Player.md#structPlayer)` & player)`            | Инициализация игрока
`void `[`loadPlayer`](#group__Player__1ga9fc767b327b377971a03517583f82deb)`(const char * name,`[`Player`](api/Player.md#structPlayer)` & player)`            | Загрузить позицию игрока из файла
`void `[`stepPlayer`](#group__Player__1ga8eacf65dd6a9d2f194df0b6943b1f0e8)`(`[`Player`](api/Player.md#structPlayer)` & player)`            | Сделать шаг, переместив игрока на вектор скорости
``[`Rect`](api/Rect.md#structRect)` `[`shiftFromPlayer`](#group__Player__1ga1bde9968cde20acbfd517a4556825e1f)`(const `[`Rect`](api/Rect.md#structRect)` & rect,const `[`Player`](api/Player.md#structPlayer)` & player)`            | Переместить прямоугольник для отрисовки относительно игрока
`void `[`movePlayer_floaty`](#group__Player__1ga7faa502fa75bea27628dffc3bb6c522a)`(`[`Player`](api/Player.md#structPlayer)` & player,char * keys)`            | Перемещать игрока, игнорируя физику
`void `[`movePlayer_actually`](#group__Player__1gaf5e504afdbcb319ef32ec2fbfd610ee0)`(`[`Player`](api/Player.md#structPlayer)` & player,char * keys)`            | Перемещать игрока с гравитацией
`struct `[`Player`](#structPlayer) | Данные игрока

## Члены  

#### `void `[`initPlayer`](#group__Player__1gaa88321e40a5c1289e1ac1ee071bd6c26)`(`[`Player`](api/Player.md#structPlayer)` & player)` 

Инициализация игрока

#### Параметры
* `player` Игрок

#### `void `[`loadPlayer`](#group__Player__1ga9fc767b327b377971a03517583f82deb)`(const char * name,`[`Player`](api/Player.md#structPlayer)` & player)` 

Загрузить позицию игрока из файла

#### Параметры
* `name` Имя файла 

* `player` Игрок

#### `void `[`stepPlayer`](#group__Player__1ga8eacf65dd6a9d2f194df0b6943b1f0e8)`(`[`Player`](api/Player.md#structPlayer)` & player)` 

Сделать шаг, переместив игрока на вектор скорости

#### Параметры
* `player` Указатель на игрока

#### ``[`Rect`](api/Rect.md#structRect)` `[`shiftFromPlayer`](#group__Player__1ga1bde9968cde20acbfd517a4556825e1f)`(const `[`Rect`](api/Rect.md#structRect)` & rect,const `[`Player`](api/Player.md#structPlayer)` & player)` 

Переместить прямоугольник для отрисовки относительно игрока

#### Параметры
* `rect` Рисуемый прямоугольник 

* `player` Игрок 

#### Возвращает
[Rect](api/Rect.md#structRect) Смещенный прямоугольник

#### `void `[`movePlayer_floaty`](#group__Player__1ga7faa502fa75bea27628dffc3bb6c522a)`(`[`Player`](api/Player.md#structPlayer)` & player,char * keys)` 

Перемещать игрока, игнорируя физику

#### Параметры
* `player` Игрок 

* `keys` Нажатые клавиши

#### `void `[`movePlayer_actually`](#group__Player__1gaf5e504afdbcb319ef32ec2fbfd610ee0)`(`[`Player`](api/Player.md#structPlayer)` & player,char * keys)` 

Перемещать игрока с гравитацией

#### Параметры
* `player` Игрок 

* `keys` Нажатые клавиши

# struct `Player` 

Данные игрока

#### Параметры
* `player` Позиция и размеры игрока 

* `movement` Скорость игрока 

* `isOnGround` Техническое - стоит ли игрок на земле

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Rect`](api/Rect.md#structRect)` `[`player`](#structPlayer_1a9a0a30489d205ce5590e033993b9d741) | 
``[`Vector`](api/Rect.md#structVector)` `[`movement`](#structPlayer_1a0383c32a86073c3ea11637456eeac266) | 
`bool `[`isOnGround`](#structPlayer_1a6b62343db258d946aadb58447fe6bed9) | 

## Члены  

#### ``[`Rect`](api/Rect.md#structRect)` `[`player`](#structPlayer_1a9a0a30489d205ce5590e033993b9d741) 

#### ``[`Vector`](api/Rect.md#structVector)` `[`movement`](#structPlayer_1a0383c32a86073c3ea11637456eeac266) 

#### `bool `[`isOnGround`](#structPlayer_1a6b62343db258d946aadb58447fe6bed9) 

