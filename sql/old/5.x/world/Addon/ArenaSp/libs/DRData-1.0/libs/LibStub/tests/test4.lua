debugstack = debug.traceback
strmatch = string.match

loadfile("../LibStub.lua")()


-- Pretend like loaded libstub is old and doesn't have :IterateLibraries
assert(LibStub.minor)
LibStub.minor = LibStub.minor - 0.0001
LibStub.IterateLibraries = nil

loadfile("../LibStub.lua")()

assert(type(LibStub.IterateLibraries)=="function")


-- Now pretend that we're the same version -- :IterateLibraries should NOT be re-created
LibStub.IterateLibraries = 123

loadfile("../LibStub.lua")()

assert(LibStub.IterateLibraries == 123)


-- Now pretend that a newer version is loaded -- :IterateLibraries should NOT be re-created
LibStub.minor = LibStub.minor + 0.0001

loadfile("../LibStub.lua")()

assert(LibStub.IterateLibraries == 123)


-- Again with a huge number
LibStub.minor = LibStub.minor + 1234567890

loadfile("../LibStub.lua")()

assert(LibStub.IterateLibraries == 123)


print("OK")