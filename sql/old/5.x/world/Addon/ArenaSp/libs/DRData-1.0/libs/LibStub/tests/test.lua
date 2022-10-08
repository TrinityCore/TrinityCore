debugstack = debug.traceback
strmatch = string.match

loadfile("../LibStub.lua")()

local lib, oldMinor = LibStub:NewLibrary("Pants", 1) -- make a new thingy
assert(lib) -- should return the library table
assert(not oldMinor) -- should not return the old minor, since it didn't exist

-- the following is to create data and then be able to check if the same data exists after the fact
function lib:MyMethod()
end
local MyMethod = lib.MyMethod
lib.MyTable = {}
local MyTable = lib.MyTable

local newLib, newOldMinor = LibStub:NewLibrary("Pants", 1) -- try to register a library with the same version, should silently fail
assert(not newLib) -- should not return since out of date

local newLib, newOldMinor = LibStub:NewLibrary("Pants", 0) -- try to register a library with a previous, should silently fail
assert(not newLib) -- should not return since out of date

local newLib, newOldMinor = LibStub:NewLibrary("Pants", 2) -- register a new version
assert(newLib) -- library table
assert(rawequal(newLib, lib)) -- should be the same reference as the previous
assert(newOldMinor == 1) -- should return the minor version of the previous version

assert(rawequal(lib.MyMethod, MyMethod)) -- verify that values were saved
assert(rawequal(lib.MyTable, MyTable)) -- verify that values were saved

local newLib, newOldMinor = LibStub:NewLibrary("Pants", "Blah 3 Blah") -- register a new version with a string minor version (instead of a number)
assert(newLib) -- library table
assert(newOldMinor == 2) -- previous version was 2

local newLib, newOldMinor = LibStub:NewLibrary("Pants", "Blah 4 and please ignore 15 Blah") -- register a new version with a string minor version (instead of a number)
assert(newLib)
assert(newOldMinor == 3) -- previous version was 3 (even though it gave a string)

local newLib, newOldMinor = LibStub:NewLibrary("Pants", 5) -- register a new library, using a normal number instead of a string
assert(newLib)
assert(newOldMinor == 4) -- previous version was 4 (even though it gave a string)