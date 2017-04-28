# Eluna features
This article contains information about features and important notes regarding Eluna.

## Settings
Eluna has some settings in the server configuration file.
It is important that you use the new configuration file that you get from compiling after adding Eluna. If the new configuration file is not used you will not receive any error log or output to console.

The configuration file includes at least the following settings:
- enable and disable Eluna
- enable and disable traceback function - this adds extra debug information if you have the default Eluna extensions.
- configure script folder location
- configure Eluna logging settings

## Reloading
To make testing easier it is good to know that Eluna scripts can be reloaded by using the command `.reload eluna`.
However this command should be used for development purposes __ONLY__. If you are having issues getting something working __restart__ the server.

It is important to know that reloading does not trigger for example the login hook for players that are already logged in when reloading.

## Script loading
Eluna loads scripts from the `lua_scripts` folder by default. You can configure the folder name and location in the server configuration file.
Any hidden folders are not loaded. All script files must have an unique name, otherwise an error is printed and only the first file found is loaded.

The loading order is not guaranteed to be alphabetic.
Any file having `.ext` extension, for example `test.ext`, is loaded before normal lua files.

Instead of the ext special feature however it is recommended to use the basic lua `require` function.
The whole script folder structure is added automatically to the lua require path so using require is as simple as providing the file name without any extension for example `require("runfirst")` to require the file `runfirst.lua`.

## Automatic conversion
In C++ level code you have types like `Unit` and `Creature` and `Player`.
When in code you have an object of type `Unit` you need to convert it to a `Creature` or a `Player` object to be able to access the methods of the subclass.

In Eluna this is automatic. All objects are automatically converted to the correct type and you will always have full access to all member functions of an object.

## Storing userdata
Storing userdata objects over time that are memory managed by C++ is a bad idea.
For example you should never save a player to a global variable and then try access it in a timed event. The reason is that the player object in C++ is a pointer to an object that C++ can delete at any time. When time passes the player may have logged out and using the pointer after player object no longer exists can be catastrophic.

To prevent users from doing this objects that are memory managed by C++ are automatically turned into nil when they are no longer safe to be accessed - this means usually after the hooked function ends.
Instead of storing the object itself you can use store guids `player:GetGUID()` and fetch the object by the guid with `map:GetWorldObject(guid)`.

Any userdata object that is memory managed by lua is safe to store over time. These objects include but are not limited to: query results, worldpackets, uint64 and int64 numbers.

## Userdata metamethods
All userdata objects in Eluna have tostring metamethod implemented.
This allows you to print the player object for example and to use `tostring(player)`.

The userdata uses metatables that contain the methods and functions it uses.
These tables are globally accessible by using the type name. For example `Player` is a global table containing all Player methods.

You can define new methods in lua for a class using these global tables.
```lua
function Player:CustomFunc(param1)
    -- self is the player the method is used on
    self:SendBroadcastMessage(param1)
end

function GameObject:CustomFunc(param1)
    -- self is the gameobject the method is used on
    print(self:GetName())
end

-- Example use:
player:CustomFunc("test")
gob:CustomFunc("test2")
```

It is recommended that in normal code these global tables and their names (variables starting with capital letters like Player, Creature, GameObject, Spell..) are avoided so they are not unintentionally edited or deleted causing other scripts possibly not to function.

## Database
Database is a great thing, but it has it's own issues.

### Querying
Database queries are slow. The whole server has to wait for the script to fetch the data from disk before continuing. Compared to reading cache or RAM reading from disk is the same as going to the moon to fetch the data (no pun intended).

Depending on what you need, prefer database Execute over Query when not selecting anything from the database. Database Executes are made asynchronously and they will not keep the server waiting.

Move all database queries possible to the script loading, server startup or similar one time event and use cache tables to manage the data in scripts.

### Types
__Database types should be followed strictly.__
Mysql does math in bigint and decimal formats which is why a simple select like `SELECT 1;` actually returns a bigint.
If you fetch a bigint or decimal using a function for a smaller type it is possible the value is read incorrectly.

For example the same code for fetching the result of `SELECT 1;` returned 1 on one machine and 0 on another. Using the correct function, in this case GetInt64, the right result was returned on both. https://github.com/ElunaLuaEngine/Eluna/issues/89#issuecomment-64121361

| base type                 | defined type | database type         |
|---------------------------|--------------|-----------------------|
| char                      | int8         | tinyint(3)            |
| short int                 | int16        | smallint(5)           |
| (long int / int)          | int32        | mediumint(8)          |
| (long int / int)          | int32        | int(10)               |
| long long int             | int64        | bigint(20)            |
| unsigned char             | uint8        | tinyint(3) unsigned   |
| unsigned short int        | uint16       | smallint(5) unsigned  |
| unsigned (long int / int) | uint32       | mediumint(8) unsigned |
| unsigned (long int / int) | uint32       | int(10) unsigned      |
| unsigned long long int    | uint64       | bigint(20) unsigned   |
| float                     | float        | float                 |
| double                    | double       | double and decimal    |
| std::string               | std::string  | any text type         |
