# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

[English](README.md) | [Español](README_ES.md) | [Svenska](README_SE.md) |  [Portuguese](README_pt_BR.md)

## Anticheat Module

- Último status de compilação com AzerothCore:[![Build Status](https://github.com/azerothcore/mod-anticheat/workflows/core-build/badge.svg?branch=master&event=push)](https://github.com/azerothcore/mod-anticheat)

Esta é uma script PassiveAnticheat baseada no repositório de lordpsyan para [AzerothCore](http://www.azerothcore.org)

## Wiki

https://github.com/azerothcore/mod-anticheat/wiki

## Aviso

Requer revisão [825db0f](https://github.com/azerothcore/azerothcore-wotlk/commit/825db0f8c1fb6d938d0cec88df0447fe7ee5b3b2) ou mais recente.

## Como instalar

### 1) Basta colocar o módulo na pasta `modules` da pasta de origem do AzerothCore.

Você pode cloná-lo via git no diretório azerothcore/modules:

`cd path/to/azerothcore/modules`

`git clone https://github.com/azerothcore/mod-anticheat.git`

ou você pode manualmente [download the module](https://github.com/azerothcore/mod-anticheat/archive/master.zip), descompacte e coloque-o sob o `azerothcore/modules` diretório.

### 2) Execute novamente o cmake e inicie uma compilação limpa do AzerothCore

### 3) Execute o incluído `\sql\characters\base\charactersdb_anticheat.sql` arquivo em seu banco de dados de personagens e execute `\sql\world\Acore_strings.sql` em seu banco de dados world. Isso cria as tabelas necessárias para este módulo.

**É ISSO!!.**

### (Opcional) Editar a configuração do módulo

Se você precisar alterar a configuração do módulo, vá para a pasta de configuração do seu servidor (por exemplo, **etc**), copie `Anticheat.conf.dist` para `Anticheat.conf` e edite-o como preferir.

# Problemas conhecidos e lista de TODO:

- [ ] Localize

# Localize Acore_Strings
- [x] LOCALE_enUS = 0
- [ ] LOCALE_koKR = 1
- [ ] LOCALE_frFR = 2
- [ ] LOCALE_deDE = 3
- [ ] LOCALE_zhCN = 4
- [ ] LOCALE_zhTW = 5
- [x] LOCALE_esES = 6
- [x] LOCALE_esMX = 7
- [ ] LOCALE_ruRU = 8
