# Файл `PlatformFactory` 

Список существующих платформ

Список платформ и функции для загрузки и хранения платформ.

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
`void `[`initPlatformFactory`](#group__PlatformFactory__1ga9a3e673eafdfc0cc3ccaa818d7477674)`(`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & factory)`            | Инициализация списка платформ
`void `[`freePlatformFactory`](#group__PlatformFactory__1ga48b97d48d516412cfc8c50efeab15c0e)`(`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & factory)`            | Освобождение памяти под список
`void `[`loadPlatforms`](#group__PlatformFactory__1ga53cb9f2f982097fcfef3dc8e7c8ae394)`(const char * name,`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & factory)`            | Загрузка списка платформ из файла
`struct `[`PlatformFactory`](#structPlatformFactory) | Список платформ

## Члены  

#### `void `[`initPlatformFactory`](#group__PlatformFactory__1ga9a3e673eafdfc0cc3ccaa818d7477674)`(`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & factory)` 

Инициализация списка платформ

#### Параметры
* `factory` Список платформ

#### `void `[`freePlatformFactory`](#group__PlatformFactory__1ga48b97d48d516412cfc8c50efeab15c0e)`(`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & factory)` 

Освобождение памяти под список

#### Параметры
* `factory` Список платформ

#### `void `[`loadPlatforms`](#group__PlatformFactory__1ga53cb9f2f982097fcfef3dc8e7c8ae394)`(const char * name,`[`PlatformFactory`](api/PlatformFactory.md#structPlatformFactory)` & factory)` 

Загрузка списка платформ из файла

#### Параметры
* `name` Имя файла 

* `factory` Список платформ

# struct `PlatformFactory` 

Список платформ

#### Параметры
* `platforms` Массив платформ 

* `size` Размер массива

## Сводка

 Члены                          | Описание                                    
--------------------------------|---------------------------------------------
``[`Platform`](api/Platform.md#structPlatform)` * `[`platforms`](#structPlatformFactory_1a8431bb4b2dffa7b36e9fcfe6ac7a3f6a) | 
`int `[`size`](#structPlatformFactory_1aef49b749e1cb603046f9803f300cd7ef) | 

## Члены  

#### ``[`Platform`](api/Platform.md#structPlatform)` * `[`platforms`](#structPlatformFactory_1a8431bb4b2dffa7b36e9fcfe6ac7a3f6a) 

#### `int `[`size`](#structPlatformFactory_1aef49b749e1cb603046f9803f300cd7ef) 

