# Файл `Menu` 

Меню

Меню - хранилище кнопок с дополнительными функциями для возможности выбора кнопок

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initButtons`](#group__Menu_1ga17cfc6bf63c9277a5ae03644fe587bcf)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)`            | Инициализация меню
`void `[`loadButtons`](#group__Menu_1ga1b85ef999267b5b12e7d213bae5e8d9c)`(const char * name,`[`Buttons`](api/Menu.md#structButtons)` * buttons)`            | Загрузить кнопки из файла
`void `[`cleanSelect`](#group__Menu_1ga1d4f029a951435535c51eb0844fe9fa4)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)`            | Выбор кнопки с проверкой границ
`void `[`up`](#group__Menu_1ga44ba69660153d260a2e77cb4e68c80a3)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)`            | Выбрать кнопку выше по списку
`void `[`down`](#group__Menu_1ga626f811897aa7ea772ec29c2bb6fe97e)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)`            | Выбрать кнопку ниже по списку
`struct `[`Buttons`](#structButtons) | #### Параметры

## Члены  

#### `void `[`initButtons`](#group__Menu_1ga17cfc6bf63c9277a5ae03644fe587bcf)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)` 

Инициализация меню

#### Параметры
* `buttons` Указатель на меню

#### `void `[`loadButtons`](#group__Menu_1ga1b85ef999267b5b12e7d213bae5e8d9c)`(const char * name,`[`Buttons`](api/Menu.md#structButtons)` * buttons)` 

Загрузить кнопки из файла

#### Параметры
* `name` Имя файла 

* `buttons` Указатель на меню

#### `void `[`cleanSelect`](#group__Menu_1ga1d4f029a951435535c51eb0844fe9fa4)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)` 

Выбор кнопки с проверкой границ

#### Параметры
* `buttons` Указатель на меню

#### `void `[`up`](#group__Menu_1ga44ba69660153d260a2e77cb4e68c80a3)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)` 

Выбрать кнопку выше по списку

#### Параметры
* `buttons` Указатель на меню

#### `void `[`down`](#group__Menu_1ga626f811897aa7ea772ec29c2bb6fe97e)`(`[`Buttons`](api/Menu.md#structButtons)` * buttons)` 

Выбрать кнопку ниже по списку

#### Параметры
* `buttons` Указатель на меню

# struct `Buttons` 

#### Параметры
* `buttons` 

* `amount` 

* `selected`

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Rect`](api/Rect.md#structRect)` * `[`buttons`](#structButtons_1a896b6915389d1424446c151ac940bd8a) | 
`int `[`amount`](#structButtons_1aee92a40a713c866b4ec5dc8307c7e178) | 
`int `[`selected`](#structButtons_1ac10dba466f8e39bb5aef0da9f8029b16) | 

## Члены  

#### ``[`Rect`](api/Rect.md#structRect)` * `[`buttons`](#structButtons_1a896b6915389d1424446c151ac940bd8a) 

#### `int `[`amount`](#structButtons_1aee92a40a713c866b4ec5dc8307c7e178) 

#### `int `[`selected`](#structButtons_1ac10dba466f8e39bb5aef0da9f8029b16) 

