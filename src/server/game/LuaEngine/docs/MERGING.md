# Merging Eluna
Eluna can be added to various sources by applying the core changes required for Eluna to function.  
Below you find the guides for merging Eluna with each core or a fork of it.  
If you choose to merge you should be able to maintain and update yourself - we do not maintain your core. View Unofficial Merging below.
We also do not fix any merging errors you may have, but you are free to ask about them on the [support forum](../README.md#documentation) and we may assist.

We recommend using the [installation guide](INSTALL.md) especially if you are not familiar with git and updating the code.  
It allows you to simply use `git pull` followed by `git submodule update` to update your source and we will handle the merging and maintenance with the official core source. Naturally you still need to handle updating the database as instructed by the core's wiki or instructions.

### Merging Eluna with MaNGOS
Eluna is merged with [official MaNGOS](http://getmangos.eu/) by default.

### Merging Eluna with cMaNGOS
```
git clone https://github.com/cmangos/mangos-wotlk.git
cd mangos-wotlk
git pull --recurse-submodules https://github.com/ElunaLuaEngine/ElunaMangosWotlk.git
```
Steps explained:
1. clone the core or fork source or get the it by other means
2. navigate to the source folder
3. pull the Eluna fork. This will fetch the repository and merge it with your source.
  * `--recurse-submodules` will automatically pull the submodules (Eluna repository). You may need to use `git submodule init` followed by `git submodule update` if your Eluna folder is empty
  * it is important that you choose the correct Eluna fork for your core andpatch:
    * [Eluna cMaNGOS Classic](https://github.com/ElunaLuaEngine/ElunaMangosClassic)
    * [Eluna cMaNGOS TBC](https://github.com/ElunaLuaEngine/ElunaMangosTbc)
    * [Eluna cMaNGOS WotLK](https://github.com/ElunaLuaEngine/ElunaMangosWotlk)

### Merging Eluna with TrinityCore
```
git clone https://github.com/TrinityCore/TrinityCore.git -b3.3.5
cd TrinityCore
git pull --recurse-submodules https://github.com/ElunaLuaEngine/ElunaTrinityWotlk.git
```
Steps explained:
1. clone the core or fork source or get the it by other means
2. navigate to the source folder
3. pull the Eluna fork. This will fetch the repository and merge it with your source.
  * `--recurse-submodules` will automatically pull the submodules (Eluna repository). You may need to use `git submodule init` followed by `git submodule update` if your Eluna folder is empty
  * it is important that you choose the correct Eluna fork for your core and patch:
    * [Eluna TrinityCore WotLK](https://github.com/ElunaLuaEngine/ElunaTrinityWotlk)
    * [Eluna TrinityCore Cataclysm](https://github.com/ElunaLuaEngine/ElunaTrinityCata)
