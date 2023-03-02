debugstack = debug.traceback
strmatch = string.match

loadfile("../LibStub.lua")()

for major, library in LibStub:IterateLibraries() do
	-- check that MyLib doesn't exist yet, by iterating through all the libraries
	assert(major ~= "MyLib")
end

assert(not LibStub:GetLibrary("MyLib", true)) -- check that MyLib doesn't exist yet by direct checking
assert(not pcall(LibStub.GetLibrary, LibStub, "MyLib")) -- don't silently fail, thus it should raise an error.
local lib = LibStub:NewLibrary("MyLib", 1) -- create the lib
assert(lib) -- check it exists
assert(rawequal(LibStub:GetLibrary("MyLib"), lib)) -- verify that :GetLibrary("MyLib") properly equals the lib reference

assert(LibStub:NewLibrary("MyLib", 2))	-- create a new version

local count=0
for major, library in LibStub:IterateLibraries() do
	-- check that MyLib exists somewhere in the libraries, by iterating through all the libraries
	if major == "MyLib" then -- we found it!
		count = count +1
		assert(rawequal(library, lib)) -- verify that the references are equal
	end
end
assert(count == 1) -- verify that we actually found it, and only once
