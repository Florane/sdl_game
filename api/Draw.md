# Файл `Draw` 

Функции отрисовки

Основные функции для отрисовки сложных объектов

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`loadTexture`](#group__Draw_1ga6491cca63889c804b2beb6eb3cef9dd5)`(const char * name,SDL_Renderer * renderer,SDL_Texture ** texture)`            | Загрузить текстуру из файла BMP.
`void `[`drawTexture`](#group__Draw_1gac1606a9cafaf8ef821a785ca929025d0)`(SDL_Renderer * renderer,SDL_Texture * texture,const SDL_Rect * rect)`            | Нарисовать текстуру
`SDL_Rect `[`rectToSDL_Rect`](#group__Draw_1gafa1dabc67176ec516c7aa7295791d5b9)`(`[`Rect`](api/Rect.md#structRect)` rect)`            | Конвертировать прямоугольник [Rect](api/Rect.md#structRect) в SDL_Rect.
`void `[`drawText`](#group__Draw_1ga4cbe95b7e8bce536f7dd9f8fbb520e74)`(SDL_Renderer *& renderer,TTF_Font *& my_font,char *& text,int x,int y,int size)`            | Нарисовать текст на экране

## Члены  

#### `void `[`loadTexture`](#group__Draw_1ga6491cca63889c804b2beb6eb3cef9dd5)`(const char * name,SDL_Renderer * renderer,SDL_Texture ** texture)` 

Загрузить текстуру из файла BMP.

#### Параметры
* `name` Имя файла 

* `renderer` Рендерер 

* `texture` Указатель на текстуру

#### `void `[`drawTexture`](#group__Draw_1gac1606a9cafaf8ef821a785ca929025d0)`(SDL_Renderer * renderer,SDL_Texture * texture,const SDL_Rect * rect)` 

Нарисовать текстуру

#### Параметры
* `renderer` Рендерер 

* `texture` Текстура 

* `rect` Указатель на границы текстуры

#### `SDL_Rect `[`rectToSDL_Rect`](#group__Draw_1gafa1dabc67176ec516c7aa7295791d5b9)`(`[`Rect`](api/Rect.md#structRect)` rect)` 

Конвертировать прямоугольник [Rect](api/Rect.md#structRect) в SDL_Rect.

#### Параметры
* `rect` Простой прямоугольник 

#### Возвращает
`SDL_Rect` Прямоугольник с теми же координатами

#### `void `[`drawText`](#group__Draw_1ga4cbe95b7e8bce536f7dd9f8fbb520e74)`(SDL_Renderer *& renderer,TTF_Font *& my_font,char *& text,int x,int y,int size)` 

Нарисовать текст на экране

#### Параметры
* `renderer` Рендерер 

* `my_font` Шрифт 

* `text` Текст для вывода 

* `x` `y` Позиция на экране 

* `size` Высота символа

