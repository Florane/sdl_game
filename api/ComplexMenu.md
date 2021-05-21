# Файл `ComplexMenu` 

Декоратор для меню

Дополнительные функции для использования с меню

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`drawButtons`](#group__ComplexMenu_1gacada2cc96de222491074a2f6cc8e74c8)`(SDL_Renderer * renderer,`[`Buttons`](api/Menu.md#structButtons)` * buttons,SDL_Texture ** buttonTextures)`            | Отрисовать кнопки на экран
`int `[`selectButton`](#group__ComplexMenu_1ga22cfec42c60f159eeb214a6aa2537459)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons,const `[`Vector`](api/Rect.md#structVector)` * point)`            | Возвращает кнопку, выделенную курсором

## Члены  

#### `void `[`drawButtons`](#group__ComplexMenu_1gacada2cc96de222491074a2f6cc8e74c8)`(SDL_Renderer * renderer,`[`Buttons`](api/Menu.md#structButtons)` * buttons,SDL_Texture ** buttonTextures)` 

Отрисовать кнопки на экран

#### Параметры
* `renderer` Рендерер 

* `buttons` Меню с кнопками 

* `buttonTextures` Массив текстур кнопок по порядку

#### `int `[`selectButton`](#group__ComplexMenu_1ga22cfec42c60f159eeb214a6aa2537459)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons,const `[`Vector`](api/Rect.md#structVector)` * point)` 

Возвращает кнопку, выделенную курсором

#### Параметры
* `buttons` Меню с кнопками 

* `point` Курсор мышки 

#### Возвращает
ID выбранной кнопки

