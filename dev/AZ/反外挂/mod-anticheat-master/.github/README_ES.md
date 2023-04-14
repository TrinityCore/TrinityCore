# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

[English](README.md) | [Español](README_ES.md) | [Svenska](README_SE.md)

## Módulo Antitrampas

- Último estado de compilación con AzerothCore: [![Build Status](https://github.com/azerothcore/mod-anticheat/workflows/core-build/badge.svg?branch=master&event=push)](https://github.com/azerothcore/mod-anticheat)

Este es una puertada del PassiveAnticheat Script del repositorio de lordpsyan's a [AzerothCore](http://www.azerothcore.org)

## Wiki

https://github.com/azerothcore/mod-anticheat/wiki

## Aviso

Requiere revisión [825db0f](https://github.com/azerothcore/azerothcore-wotlk/commit/825db0f8c1fb6d938d0cec88df0447fe7ee5b3b2) o posterior.

## Cómo instalar

### 1) Simplemente coloque el módulo en la carpeta `modules` de su carpeta de origen de AzerothCore.

Puede clonarlo a través de git en el directorio azerothcore/modules:

`cd path/to/azerothcore/modules`

`git clone https://github.com/azerothcore/mod-anticheat.git`

o puede [descargar manualmente el módulo](https://github.com/azerothcore/mod-anticheat/archive/master.zip), descomprimirlo y colocarlo en el directorio `azerothcore/modules`.

### 2) Vuelva a ejecutar cmake e inicie una compilación limpia de AzerothCore

### 3) Ejecute el archivo `\sql\characters\base\charactersdb_anticheat.sql` incluido en su base de datos de personajes y ejecute `\sql\world\Acore_strings.sql` en su base de datos world. Esto crea las tablas necesarias para este módulo.

**Eso es todo.**

### (Opcional) Editar configuración del módulo

Si necesita cambiar la configuración del módulo, vaya a la carpeta de configuración de su servidor (p.ej. **etc**. ), copie `Anticheat.conf.dist` a `Anticheat.conf` y edítelo como prefiera.

# Problemas conocidos y lista de TODO:

- [ ] Localizar

# Localizar Acore_Strings
- [x] LOCALE_enUS = 0
- [ ] LOCALE_koKR = 1
- [ ] LOCALE_frFR = 2
- [ ] LOCALE_deDE = 3
- [ ] LOCALE_zhCN = 4
- [ ] LOCALE_zhTW = 5
- [x] LOCALE_esES = 6
- [x] LOCALE_esMX = 7
- [ ] LOCALE_ruRU = 8
