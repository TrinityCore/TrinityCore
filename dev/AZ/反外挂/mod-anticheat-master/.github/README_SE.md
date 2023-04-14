# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

[English](README.md) | [Español](README_ES.md) | [Svenska](README_SE.md)

## Anticheat Module

- Latest build status with AzerothCore: [![Build Status](https://github.com/azerothcore/mod-anticheat/workflows/core-build/badge.svg?branch=master&event=push)](https://github.com/azerothcore/mod-anticheat)

Den här modulen är baserad på PassiveAnticheat Script från lordpsyan's repo till [AzerothCore](http://www.azerothcore.org)

## Wiki

https://github.com/azerothcore/mod-anticheat/wiki

## Observera

Du behöver version [825db0f](https://github.com/azerothcore/azerothcore-wotlk/commit/825db0f8c1fb6d938d0cec88df0447fe7ee5b3b2) eller nyare för modulen.

## Installations guide

### 1) Placera modulen i `modules` mappen i din AzerothCore mapp.

Du kan klona det under azerothcore/modules mappen:

`cd path/to/azerothcore/modules`

`git clone https://github.com/azerothcore/mod-anticheat.git`

eller så [laddar du ner](https://github.com/azerothcore/mod-anticheat/archive/master.zip), unzip och placera det i `azerothcore/modules` mappen.

### 2) Kör om CMake och starta en ren build av AzerothCore

### 3) Kör filen `\sql\characters\base\charactersdb_anticheat.sql` i din Character databas och kör  `\sql\world\Acore_strings.sql` i din world databas. Det skapar tabellerna som behövs för att använda modulen.

**Det är allt.**

### (Frivilligt) Ändra modulens konfigurationsinställningar

Om du behöver ändra konfigurationen går du till serverns config mapp. Kopiera `Anticheat.conf.dist` till `Anticheat.conf` och ändra inställningarna som du vill.

# Kända problem och TODO-lista:

- [ ] Localize

# Språk som stöds i Acore_Strings
- [x] LOCALE_enUS = 0
- [ ] LOCALE_koKR = 1
- [ ] LOCALE_frFR = 2
- [ ] LOCALE_deDE = 3
- [ ] LOCALE_zhCN = 4
- [ ] LOCALE_zhTW = 5
- [x] LOCALE_esES = 6
- [x] LOCALE_esMX = 7
- [ ] LOCALE_ruRU = 8
