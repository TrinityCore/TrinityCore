# Installing and updating
This page will help you get a cMaNGOS and a TrinityCore source with Eluna.

If you are looking to get MaNGOS source with Eluna head over to [MaNGOS forum](http://getmangos.eu/) for the installation and updating instructions - however read this page also as it contains important information.

If you are having trouble with the installation or updating the core source, head over to our [support forum](../README.md#documentation).  
If you are looking for a way to merge eluna with a fork of the official repositories see [merging](MERGING.md).

### Requirements and dependencies:
**Eluna uses `C++11` so you need a compiler that supports it.**  
**Eluna can use ACE or BOOST for filesystem library.**  
Additionally see you desired core's documentation and installation instructions for it's requirements and dependencies.

### Installation
1. Open [git bash](http://git-scm.com/) and navigate to where you want the core source
2. Choose the git address of your desired core and patch below and clone the core with `git clone <address>`.  
For example `git clone https://github.com/ElunaLuaEngine/ElunaTrinityWotlk.git`
   * TrinityCore WoTLK: `https://github.com/ElunaLuaEngine/ElunaTrinityWotlk.git`
   * cMaNGOS Classic: `https://github.com/ElunaLuaEngine/ElunaMangosClassic.git`
   * cMaNGOS TBC: `https://github.com/ElunaLuaEngine/ElunaMangosTbc.git`
   * cMaNGOS WoTLK: `https://github.com/ElunaLuaEngine/ElunaMangosWotlk.git`
3. Navigate to the newly created source folder with `git bash`
4. Use the git command `git submodule init` followed by `git submodule update`
   * If you really do not get how to use git bash (and do try!) you can navigate to the `LuaEngine` folder and clone the [eluna repository](https://github.com/ElunaLuaEngine/Eluna) there. This is not recommended though.
4. Continue compiling the core normally using the official instructions
   * [TrinityCore](http://collab.kpsn.org/display/tc/Installation+Guide)
   * [cMaNGOS](https://github.com/cmangos/issues/wiki/Installation-Instructions)

__Important!__ After compiling use the new configuration files. They contain Eluna settings and without them Eluna may not function correctly. For example you do not get any error messages or error log.

After installing Eluna you should check out these:
- [Eluna getting started](USAGE.md)
- [Eluna features](IMPL_DETAILS.md)

### Updating
Updating is essentially handled in the same manner as you would normally update the core and database.  
To get the newest core source code open `git bash` and navigate to your local source folder.
Then execute use `git pull` followed by `git submodule init` and `git submodule update`.  
After updating the source you need to recompile the core normally. Simply use `CMake` if needed and compile.  
To update the databases refer to the core's or database's official updating documents:
  *  [TrinityCore](http://collab.kpsn.org/display/tc/Databases+Installation)
  *  [cMaNGOS](https://github.com/cmangos/issues/wiki/Installation-Instructions)
