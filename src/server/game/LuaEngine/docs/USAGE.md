# Using Eluna
Eluna is a lua engine implementation for world of warcraft emulators.
It can be used to create different kind of scripts from AI to events.
This article helps you to get started with Eluna. We go through adding a simple script, where to get information from and a few language basics.

This article assumes you have already installed Eluna successfully. If you have not, see [installation](INSTALL.md).

## Basic script
Here is a simple "Hello world" example.
Create a file named `hello world.lua` that contains the following code and place the file inside the scripts folder in your server folder. By default the scripts folder is called `lua_scripts`. The server folder is the folder which contains server executables.
```lua
local PLAYER_EVENT_ON_LOGIN = 3

local function OnLogin(event, player)
    player:SendBroadcastMessage("Hello world")
end

RegisterPlayerEvent(PLAYER_EVENT_ON_LOGIN, OnLogin)
```
If you now restart your server and log in game you are greeted with "Hello world" in your chat.

### What happened
As you have witnessed here no core compiling was needed and your script runs from the file you just created.

The file is compiled and run by the lua engine when the server starts up or Eluna is reloaded.
The code in the file registers a function to be run when a player logs in and the function sends a message to the player that logged in.

## Lua basics
It is good to get to know a bit of lua to code lua scripts. In this article we do not go that much into explaining lua syntax. Here are some pointers to important sources of information and things to get to know about.

### Sources of information
- lua users wiki
    - http://lua-users.org/wiki/LuaDirectory
    - http://lua-users.org/wiki/TutorialDirectory
    - http://lua-users.org/wiki/SampleCode
- programming in lua http://www.lua.org/pil/1.html
- lua reference manual http://www.lua.org/manual/5.2/

### some highlights
- Print function outputs to server console. Very useful for simple debugging `print("anything here")`.
- control structures - especially loops:
    - http://lua-users.org/wiki/ControlStructureTutorial
    - http://www.lua.org/manual/5.2/manual.html#3.3.5
- lua string library:
    - http://lua-users.org/wiki/StringLibraryTutorial
    - http://www.wowwiki.com/Pattern_matching
- Lua tables are the only container in lua and they are essential for good code. Lua tables can be compared to arrays and hash maps.
Table functions and tutorials:
    - http://www.lua.org/manual/5.2/manual.html#6.5
    - http://www.lua.org/manual/5.2/manual.html#4.3
    - http://lua-users.org/wiki/TablesTutorial
    - http://www.lua.org/pil/2.5.html
- prefer local variables over global. While global variables may work they can create issues with other scripts that use same variable names.
All local variables outside of functions in a script are shared by everything running the same script - the variables are locally global.

## Eluna basics
It is good to know where you can find information about Eluna and Eluna's API as well as the basic elements of a script. Here are links to the main sources of information:

- Eluna features [Eluna details](IMPL_DETAILS.md)
- Eluna documentation http://elunaluaengine.github.io/

### Error messages
If Eluna is installed correctly, the default installation should make errors output to the console as well as a log file in the server folder. If you can not get your script to work, be sure to check the log file for any errors you might have missed.

Check out the configuration file for settings if you want to tweak the logging settings.

### Global functions
Global functions are functions you can run from anywhere in a script file and they do not require any object to be run.
In addition to normal global functions lua provides like `print` Eluna has it's own gobal functions. You can find them in the documentation under `global` class: [global functions](http://elunaluaengine.github.io/Global/index.html).

```lua
-- print the return value of GetLuaEngine function
print(GetLuaEngine())
```

### Member functions
Member functions, also called methods, are functions that require an userdata object to run. There are several different classes of objects that have different member functions. You can find all the member functions and their documentations from the [Eluna documentation](http://elunaluaengine.github.io/).

Classes in C++ inherit each other. In Eluna member functions are also inherited. For example objects of classes `Player` and `Creature` inherit all methods from `Unit` class.

Methods are called by using `:` notation on the object. For example to get the player name you can call the GetName methods like this: `player:GetName()`

```lua
local entry = 6
local on_combat = 1
local function OnCombat(event, creature, target)
    -- creature is of type Creature
    -- target is of type Creature or Player depending on who the creature is attacking
    print(creature:GetLevel())
    print(target:GetLevel())
end

RegisterCreatureEvent(entry, on_combat, OnCombat)
```

### Registering functions to events
Scripts register functions to events and the functions are executed when the event happens.
There are special global functions in Eluna API for registering functions for events.
You should be able to find all such functions from [Eluna documentation](http://elunaluaengine.github.io/) by searching `register`.

Functions used to register other functions for events need the ID of the event you want the hook to be registered for passed to them. You can find these ID numbers from the registering function documentation page.

Eluna passes some arguments to the functions executed. The arguments are always in same order. You can name them in any way you want. In the above script example the event `PLAYER_EVENT_ON_LOGIN` passes the event id and the player who logs in to the registered function. This is why the registered function has these parameters defined: `(event, player)`.

Some events allow the registered function to return different values. Sometimes you can return more than one value. The possibility to return is documented on the registering function's documentation page. Simply using the `return` keyword returns normally as if the function would end.

For example in this script we register the function `OnCombat` to be run on event `1`, which triggers on combat, for the creature entry `6`. All needed information can be found here: http://elunaluaengine.github.io/Global/RegisterCreatureEvent.html
```lua
local entry = 6
local on_combat = 1
local function OnCombat(event, creature, target)
    creature:SendUnitYell("Yiee, me run!", 0)
end

RegisterCreatureEvent(entry, on_combat, OnCombat)
```
