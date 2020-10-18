# StackTracePlus #

[![Build Status](https://travis-ci.org/ignacio/StackTracePlus.png?branch=master)](https://travis-ci.org/ignacio/StackTracePlus)

[StackTracePlus](https://github.com/ignacio/StackTracePlus) provides enhanced stack traces for [Lua 5.1, Lua 5.2][1] and [LuaJIT][2].

StackTracePlus can be used as a replacement for debug.traceback. It gives detailed information about locals, tries to guess
function names when they're not available, etc, so, instead of

    lua5.1.exe: D:\trunk_git\sources\stacktraceplus\test\test.lua:10: attempt to concatenate a nil value
    stack traceback:
	D:\trunk_git\sources\stacktraceplus\test\test.lua:10: in function <D:\trunk_git\sources\stacktraceplus\test\test.lua:7>
	(tail call): ?
	D:\trunk_git\sources\stacktraceplus\test\test.lua:15: in main chunk
	[C]: ?

you'll get

    lua5.1.exe: D:\trunk_git\sources\stacktraceplus\test\test.lua:10: attempt to concatenate a nil value
    Stack Traceback
    ===============
    (2)  C function 'function: 00A8F418'
    (3) Lua function 'g' at file 'D:\trunk_git\sources\stacktraceplus\test\test.lua:10' (best guess)
	Local variables:
	 fun = table module
	 str = string: "hey"
	 tb = table: 027DCBE0  {dummy:1, blah:true, foo:bar}
	 (*temporary) = nil
	 (*temporary) = string: "text"
	 (*temporary) = string: "attempt to concatenate a nil value"
    (4) tail call
    (5) main chunk of file 'D:\trunk_git\sources\stacktraceplus\test\test.lua' at line 15
    (6)  C function 'function: 002CA480'

## Usage #

StackTracePlus can be used as a replacement for `debug.traceback`, as an `xpcall` error handler or even from C code. Note that
only the Lua 5.1 interpreter allows the traceback function to be replaced "on the fly". LuaJIT and Lua 5.2 always calls luaL_traceback internally so there is no easy way to override that.

```lua
local STP = require "StackTracePlus"

debug.traceback = STP.stacktrace
function test()
	local s = "this is a string"
	local n = 42
	local t = { foo = "bar" }
	local co = coroutine
	local cr = coroutine.create

	error("an error")
end
test()
```

That script will output (only with Lua 5.1):

    lua5.1: example.lua:11: an error
    Stack Traceback
    ===============
    (2)  C function 'function: 006B5758'
    (3) global C function 'error'
    (4) Lua global 'test' at file 'example.lua:11'
            Local variables:
             s = string: "this is a string"
             n = number: 42
             t = table: 006E5220  {foo:bar}
             co = coroutine table
             cr = C function: 003C7080
    (5) main chunk of file 'example.lua' at line 14
    (6)  C function 'function: 00637B30'

**StackTracePlus** is aware of the usual Lua libraries, like *coroutine*, *table*, *string*, *io*, etc and functions like
*print*, *pcall*, *assert*, and so on.

You can also make STP aware of your own tables and functions by calling *add_known_function* and *add_known_table*.

```lua
local STP = require "StackTracePlus"

debug.traceback = STP.stacktrace
local my_table = {
	f = function() end
}
function my_function()
end

function test(data, func)
	local s = "this is a string"

	error("an error")
end

STP.add_known_table(my_table, "A description for my_table")
STP.add_known_function(my_function, "A description for my_function")

test( my_table, my_function )
```

Will output:

    lua5.1: ..\test\example2.lua:13: an error
    Stack Traceback
    ===============
    (2)  C function 'function: 0073AAA8'
    (3) global C function 'error'
    (4) Lua global 'test' at file '..\test\example2.lua:13'
            Local variables:
             data = A description for my_table
             func = Lua function 'A description for my_function' (defined at line 7 of chunk ..\test\example2.lua)
             s = string: "this is a string"
    (5) main chunk of file '..\test\example2.lua' at line 19
    (6)  C function 'function: 00317B30'


## Installation #
The easiest way to install is with [LuaRocks][3].

  - luarocks install stacktraceplus

If you don't want to use LuaRocks, just copy StackTracePlus.lua to Lua's path.

## License #
**StackTracePlus** is available under the MIT license.

[1]: http://www.lua.org/
[2]: http://luajit.org/
[3]: http://luarocks.org/
