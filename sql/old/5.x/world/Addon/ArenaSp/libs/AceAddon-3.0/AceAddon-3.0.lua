--- **AceAddon-3.0** provides a template for creating addon objects.
-- It'll provide you with a set of callback functions that allow you to simplify the loading
-- process of your addon.\\
-- Callbacks provided are:\\
-- * **OnInitialize**, which is called directly after the addon is fully loaded.
-- * **OnEnable** which gets called during the PLAYER_LOGIN event, when most of the data provided by the game is already present.
-- * **OnDisable**, which is only called when your addon is manually being disabled.
-- @usage
-- -- A small (but complete) addon, that doesn't do anything, 
-- -- but shows usage of the callbacks.
-- local MyAddon = LibStub("AceAddon-3.0"):NewAddon("MyAddon")
-- 
-- function MyAddon:OnInitialize()
--   -- do init tasks here, like loading the Saved Variables, 
--   -- or setting up slash commands.
-- end
-- 
-- function MyAddon:OnEnable()
--   -- Do more initialization here, that really enables the use of your addon.
--   -- Register Events, Hook functions, Create Frames, Get information from 
--   -- the game that wasn't available in OnInitialize
-- end
--
-- function MyAddon:OnDisable()
--   -- Unhook, Unregister Events, Hide frames that you created.
--   -- You would probably only use an OnDisable if you want to 
--   -- build a "standby" mode, or be able to toggle modules on/off.
-- end
-- @class file
-- @name AceAddon-3.0.lua
-- @release $Id: AceAddon-3.0.lua 1084 2013-04-27 20:14:11Z nevcairiel $

local MAJOR, MINOR = "AceAddon-3.0", 12
local AceAddon, oldminor = LibStub:NewLibrary(MAJOR, MINOR)

if not AceAddon then return end -- No Upgrade needed.

AceAddon.frame = AceAddon.frame or CreateFrame("Frame", "AceAddon30Frame") -- Our very own frame
AceAddon.addons = AceAddon.addons or {} -- addons in general
AceAddon.statuses = AceAddon.statuses or {} -- statuses of addon.
AceAddon.initializequeue = AceAddon.initializequeue or {} -- addons that are new and not initialized
AceAddon.enablequeue = AceAddon.enablequeue or {} -- addons that are initialized and waiting to be enabled
AceAddon.embeds = AceAddon.embeds or setmetatable({}, {__index = function(tbl, key) tbl[key] = {} return tbl[key] end }) -- contains a list of libraries embedded in an addon

-- Lua APIs
local tinsert, tconcat, tremove = table.insert, table.concat, table.remove
local fmt, tostring = string.format, tostring
local select, pairs, next, type, unpack = select, pairs, next, type, unpack
local loadstring, assert, error = loadstring, assert, error
local setmetatable, getmetatable, rawset, rawget = setmetatable, getmetatable, rawset, rawget

-- Global vars/functions that we don't upvalue since they might get hooked, or upgraded
-- List them here for Mikk's FindGlobals script
-- GLOBALS: LibStub, IsLoggedIn, geterrorhandler

--[[
	 xpcall safecall implementation
]]
local xpcall = xpcall

local function errorhandler(err)
	return geterrorhandler()(err)
end

local function CreateDispatcher(argCount)
	local code = [[
		local xpcall, eh = ...
		local method, ARGS
		local function call() return method(ARGS) end
	
		local function dispatch(func, ...)
			 method = func
			 if not method then return end
			 ARGS = ...
			 return xpcall(call, eh)
		end
	
		return dispatch
	]]
	
	local ARGS = {}
	for i = 1, argCount do ARGS[i] = "arg"..i end
	code = code:gsub("ARGS", tconcat(ARGS, ", "))
	return assert(loadstring(code, "safecall Dispatcher["..argCount.."]"))(xpcall, errorhandler)
end

local Dispatchers = setmetatable({}, {__index=function(self, argCount)
	local dispatcher = CreateDispatcher(argCount)
	rawset(self, argCount, dispatcher)
	return dispatcher
end})
Dispatchers[0] = function(func)
	return xpcall(func, errorhandler)
end

local function safecall(func, ...)
	-- we check to see if the func is passed is actually a function here and don't error when it isn't
	-- this safecall is used for optional functions like OnInitialize OnEnable etc. When they are not
	-- present execution should continue without hinderance
	if type(func) == "function" then
		return Dispatchers[select('#', ...)](func, ...)
	end
end

-- local functions that will be implemented further down
local Enable, Disable, EnableModule, DisableModule, Embed, NewModule, GetModule, GetName, SetDefaultModuleState, SetDefaultModuleLibraries, SetEnabledState, SetDefaultModulePrototype

-- used in the addon metatable
local function addontostring( self ) return self.name end 

-- Check if the addon is queued for initialization
local function queuedForInitialization(addon)
	for i = 1, #AceAddon.initializequeue do
		if AceAddon.initializequeue[i] == addon then
			return true
		end
	end
	return false
end

--- Create a new AceAddon-3.0 addon.
-- Any libraries you specified will be embeded, and the addon will be scheduled for 
-- its OnInitialize and OnEnable callbacks.
-- The final addon object, with all libraries embeded, will be returned.
-- @paramsig [object ,]name[, lib, ...]
-- @param object Table to use as a base for the addon (optional)
-- @param name Name of the addon object to create
-- @param lib List of libraries to embed into the addon
-- @usage 
-- -- Create a simple addon object
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("MyAddon", "AceEvent-3.0")
--
-- -- Create a Addon object based on the table of a frame
-- local MyFrame = CreateFrame("Frame")
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon(MyFrame, "MyAddon", "AceEvent-3.0")
function AceAddon:NewAddon(objectorname, ...)
	local object,name
	local i=1
	if type(objectorname)=="table" then
		object=objectorname
		name=...
		i=2
	else
		name=objectorname
	end
	if type(name)~="string" then
		error(("Usage: NewAddon([object,] name, [lib, lib, lib, ...]): 'name' - string expected got '%s'."):format(type(name)), 2)
	end
	if self.addons[name] then 
		error(("Usage: NewAddon([object,] name, [lib, lib, lib, ...]): 'name' - Addon '%s' already exists."):format(name), 2)
	end
	
	object = object or {}
	object.name = name

	local addonmeta = {}
	local oldmeta = getmetatable(object)
	if oldmeta then
		for k, v in pairs(oldmeta) do addonmeta[k] = v end
	end
	addonmeta.__tostring = addontostring
	
	setmetatable( object, addonmeta )
	self.addons[name] = object
	object.modules = {}
	object.orderedModules = {}
	object.defaultModuleLibraries = {}
	Embed( object ) -- embed NewModule, GetModule methods
	self:EmbedLibraries(object, select(i,...))
	
	-- add to queue of addons to be initialized upon ADDON_LOADED
	tinsert(self.initializequeue, object)
	return object
end


--- Get the addon object by its name from the internal AceAddon registry.
-- Throws an error if the addon object cannot be found (except if silent is set).
-- @param name unique name of the addon object
-- @param silent if true, the addon is optional, silently return nil if its not found
-- @usage 
-- -- Get the Addon
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
function AceAddon:GetAddon(name, silent)
	if not silent and not self.addons[name] then
		error(("Usage: GetAddon(name): 'name' - Cannot find an AceAddon '%s'."):format(tostring(name)), 2)
	end
	return self.addons[name]
end

-- - Embed a list of libraries into the specified addon.
-- This function will try to embed all of the listed libraries into the addon
-- and error if a single one fails.
--
-- **Note:** This function is for internal use by :NewAddon/:NewModule
-- @paramsig addon, [lib, ...]
-- @param addon addon object to embed the libs in
-- @param lib List of libraries to embed into the addon
function AceAddon:EmbedLibraries(addon, ...)
	for i=1,select("#", ... ) do
		local libname = select(i, ...)
		self:EmbedLibrary(addon, libname, false, 4)
	end
end

-- - Embed a library into the addon object.
-- This function will check if the specified library is registered with LibStub
-- and if it has a :Embed function to call. It'll error if any of those conditions
-- fails.
--
-- **Note:** This function is for internal use by :EmbedLibraries
-- @paramsig addon, libname[, silent[, offset]]
-- @param addon addon object to embed the library in
-- @param libname name of the library to embed
-- @param silent marks an embed to fail silently if the library doesn't exist (optional)
-- @param offset will push the error messages back to said offset, defaults to 2 (optional)
function AceAddon:EmbedLibrary(addon, libname, silent, offset)
	local lib = LibStub:GetLibrary(libname, true)
	if not lib and not silent then
		error(("Usage: EmbedLibrary(addon, libname, silent, offset): 'libname' - Cannot find a library instance of %q."):format(tostring(libname)), offset or 2)
	elseif lib and type(lib.Embed) == "function" then
		lib:Embed(addon)
		tinsert(self.embeds[addon], libname)
		return true
	elseif lib then
		error(("Usage: EmbedLibrary(addon, libname, silent, offset): 'libname' - Library '%s' is not Embed capable"):format(libname), offset or 2)
	end
end

--- Return the specified module from an addon object.
-- Throws an error if the addon object cannot be found (except if silent is set)
-- @name //addon//:GetModule
-- @paramsig name[, silent]
-- @param name unique name of the module
-- @param silent if true, the module is optional, silently return nil if its not found (optional)
-- @usage 
-- -- Get the Addon
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- -- Get the Module
-- MyModule = MyAddon:GetModule("MyModule")
function GetModule(self, name, silent)
	if not self.modules[name] and not silent then
		error(("Usage: GetModule(name, silent): 'name' - Cannot find module '%s'."):format(tostring(name)), 2)
	end
	return self.modules[name]
end

local function IsModuleTrue(self) return true end

--- Create a new module for the addon.
-- The new module can have its own embeded libraries and/or use a module prototype to be mixed into the module.\\
-- A module has the same functionality as a real addon, it can have modules of its own, and has the same API as
-- an addon object.
-- @name //addon//:NewModule
-- @paramsig name[, prototype|lib[, lib, ...]]
-- @param name unique name of the module
-- @param prototype object to derive this module from, methods and values from this table will be mixed into the module (optional)
-- @param lib List of libraries to embed into the addon
-- @usage 
-- -- Create a module with some embeded libraries
-- MyModule = MyAddon:NewModule("MyModule", "AceEvent-3.0", "AceHook-3.0")
-- 
-- -- Create a module with a prototype
-- local prototype = { OnEnable = function(self) print("OnEnable called!") end }
-- MyModule = MyAddon:NewModule("MyModule", prototype, "AceEvent-3.0", "AceHook-3.0")
function NewModule(self, name, prototype, ...)
	if type(name) ~= "string" then error(("Usage: NewModule(name, [prototype, [lib, lib, lib, ...]): 'name' - string expected got '%s'."):format(type(name)), 2) end
	if type(prototype) ~= "string" and type(prototype) ~= "table" and type(prototype) ~= "nil" then error(("Usage: NewModule(name, [prototype, [lib, lib, lib, ...]): 'prototype' - table (prototype), string (lib) or nil expected got '%s'."):format(type(prototype)), 2) end
	
	if self.modules[name] then error(("Usage: NewModule(name, [prototype, [lib, lib, lib, ...]): 'name' - Module '%s' already exists."):format(name), 2) end
	
	-- modules are basically addons. We treat them as such. They will be added to the initializequeue properly as well.
	-- NewModule can only be called after the parent addon is present thus the modules will be initialized after their parent is.
	local module = AceAddon:NewAddon(fmt("%s_%s", self.name or tostring(self), name))
	
	module.IsModule = IsModuleTrue
	module:SetEnabledState(self.defaultModuleState)
	module.moduleName = name

	if type(prototype) == "string" then
		AceAddon:EmbedLibraries(module, prototype, ...)
	else
		AceAddon:EmbedLibraries(module, ...)
	end
	AceAddon:EmbedLibraries(module, unpack(self.defaultModuleLibraries))

	if not prototype or type(prototype) == "string" then
		prototype = self.defaultModulePrototype or nil
	end
	
	if type(prototype) == "table" then
		local mt = getmetatable(module)
		mt.__index = prototype
		setmetatable(module, mt)  -- More of a Base class type feel.
	end
	
	safecall(self.OnModuleCreated, self, module) -- Was in Ace2 and I think it could be a cool thing to have handy.
	self.modules[name] = module
	tinsert(self.orderedModules, module)
	
	return module
end

--- Returns the real name of the addon or module, without any prefix.
-- @name //addon//:GetName
-- @paramsig 
-- @usage 
-- print(MyAddon:GetName())
-- -- prints "MyAddon"
function GetName(self)
	return self.moduleName or self.name
end

--- Enables the Addon, if possible, return true or false depending on success.
-- This internally calls AceAddon:EnableAddon(), thus dispatching a OnEnable callback
-- and enabling all modules of the addon (unless explicitly disabled).\\
-- :Enable() also sets the internal `enableState` variable to true
-- @name //addon//:Enable
-- @paramsig 
-- @usage 
-- -- Enable MyModule
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- MyModule = MyAddon:GetModule("MyModule")
-- MyModule:Enable()
function Enable(self)
	self:SetEnabledState(true)

	-- nevcairiel 2013-04-27: don't enable an addon/module if its queued for init still
	-- it'll be enabled after the init process
	if not queuedForInitialization(self) then
		return AceAddon:EnableAddon(self)
	end
end

--- Disables the Addon, if possible, return true or false depending on success.
-- This internally calls AceAddon:DisableAddon(), thus dispatching a OnDisable callback
-- and disabling all modules of the addon.\\
-- :Disable() also sets the internal `enableState` variable to false
-- @name //addon//:Disable
-- @paramsig 
-- @usage 
-- -- Disable MyAddon
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- MyAddon:Disable()
function Disable(self)
	self:SetEnabledState(false)
	return AceAddon:DisableAddon(self)
end

--- Enables the Module, if possible, return true or false depending on success.
-- Short-hand function that retrieves the module via `:GetModule` and calls `:Enable` on the module object.
-- @name //addon//:EnableModule
-- @paramsig name
-- @usage 
-- -- Enable MyModule using :GetModule
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- MyModule = MyAddon:GetModule("MyModule")
-- MyModule:Enable()
--
-- -- Enable MyModule using the short-hand
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- MyAddon:EnableModule("MyModule")
function EnableModule(self, name)
	local module = self:GetModule( name )
	return module:Enable()
end

--- Disables the Module, if possible, return true or false depending on success.
-- Short-hand function that retrieves the module via `:GetModule` and calls `:Disable` on the module object.
-- @name //addon//:DisableModule
-- @paramsig name
-- @usage 
-- -- Disable MyModule using :GetModule
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- MyModule = MyAddon:GetModule("MyModule")
-- MyModule:Disable()
--
-- -- Disable MyModule using the short-hand
-- MyAddon = LibStub("AceAddon-3.0"):GetAddon("MyAddon")
-- MyAddon:DisableModule("MyModule")
function DisableModule(self, name)
	local module = self:GetModule( name )
	return module:Disable()
end

--- Set the default libraries to be mixed into all modules created by this object.
-- Note that you can only change the default module libraries before any module is created.
-- @name //addon//:SetDefaultModuleLibraries
-- @paramsig lib[, lib, ...]
-- @param lib List of libraries to embed into the addon
-- @usage 
-- -- Create the addon object
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("MyAddon")
-- -- Configure default libraries for modules (all modules need AceEvent-3.0)
-- MyAddon:SetDefaultModuleLibraries("AceEvent-3.0")
-- -- Create a module
-- MyModule = MyAddon:NewModule("MyModule")
function SetDefaultModuleLibraries(self, ...)
	if next(self.modules) then
		error("Usage: SetDefaultModuleLibraries(...): cannot change the module defaults after a module has been registered.", 2)
	end
	self.defaultModuleLibraries = {...}
end

--- Set the default state in which new modules are being created.
-- Note that you can only change the default state before any module is created.
-- @name //addon//:SetDefaultModuleState
-- @paramsig state
-- @param state Default state for new modules, true for enabled, false for disabled
-- @usage 
-- -- Create the addon object
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("MyAddon")
-- -- Set the default state to "disabled"
-- MyAddon:SetDefaultModuleState(false)
-- -- Create a module and explicilty enable it
-- MyModule = MyAddon:NewModule("MyModule")
-- MyModule:Enable()
function SetDefaultModuleState(self, state)
	if next(self.modules) then
		error("Usage: SetDefaultModuleState(state): cannot change the module defaults after a module has been registered.", 2)
	end
	self.defaultModuleState = state
end

--- Set the default prototype to use for new modules on creation.
-- Note that you can only change the default prototype before any module is created.
-- @name //addon//:SetDefaultModulePrototype
-- @paramsig prototype
-- @param prototype Default prototype for the new modules (table)
-- @usage 
-- -- Define a prototype
-- local prototype = { OnEnable = function(self) print("OnEnable called!") end }
-- -- Set the default prototype
-- MyAddon:SetDefaultModulePrototype(prototype)
-- -- Create a module and explicitly Enable it
-- MyModule = MyAddon:NewModule("MyModule")
-- MyModule:Enable()
-- -- should print "OnEnable called!" now
-- @see NewModule
function SetDefaultModulePrototype(self, prototype)
	if next(self.modules) then
		error("Usage: SetDefaultModulePrototype(prototype): cannot change the module defaults after a module has been registered.", 2)
	end
	if type(prototype) ~= "table" then
		error(("Usage: SetDefaultModulePrototype(prototype): 'prototype' - table expected got '%s'."):format(type(prototype)), 2)
	end
	self.defaultModulePrototype = prototype
end

--- Set the state of an addon or module
-- This should only be called before any enabling actually happend, e.g. in/before OnInitialize.
-- @name //addon//:SetEnabledState
-- @paramsig state
-- @param state the state of an addon or module  (enabled=true, disabled=false)
function SetEnabledState(self, state)
	self.enabledState = state
end


--- Return an iterator of all modules associated to the addon.
-- @name //addon//:IterateModules
-- @paramsig 
-- @usage 
-- -- Enable all modules
-- for name, module in MyAddon:IterateModules() do
--    module:Enable()
-- end
local function IterateModules(self) return pairs(self.modules) end

-- Returns an iterator of all embeds in the addon
-- @name //addon//:IterateEmbeds
-- @paramsig 
local function IterateEmbeds(self) return pairs(AceAddon.embeds[self]) end

--- Query the enabledState of an addon.
-- @name //addon//:IsEnabled
-- @paramsig 
-- @usage 
-- if MyAddon:IsEnabled() then
--     MyAddon:Disable()
-- end
local function IsEnabled(self) return self.enabledState end
local mixins = {
	NewModule = NewModule,
	GetModule = GetModule,
	Enable = Enable,
	Disable = Disable,
	EnableModule = EnableModule,
	DisableModule = DisableModule,
	IsEnabled = IsEnabled,
	SetDefaultModuleLibraries = SetDefaultModuleLibraries,
	SetDefaultModuleState = SetDefaultModuleState,
	SetDefaultModulePrototype = SetDefaultModulePrototype,
	SetEnabledState = SetEnabledState,
	IterateModules = IterateModules,
	IterateEmbeds = IterateEmbeds,
	GetName = GetName,
}
local function IsModule(self) return false end
local pmixins = {
	defaultModuleState = true,
	enabledState = true,
	IsModule = IsModule,
}
-- Embed( target )
-- target (object) - target object to embed aceaddon in
--
-- this is a local function specifically since it's meant to be only called internally
function Embed(target, skipPMixins)
	for k, v in pairs(mixins) do
		target[k] = v
	end
	if not skipPMixins then
		for k, v in pairs(pmixins) do
			target[k] = target[k] or v
		end
	end
end


-- - Initialize the addon after creation.
-- This function is only used internally during the ADDON_LOADED event
-- It will call the **OnInitialize** function on the addon object (if present), 
-- and the **OnEmbedInitialize** function on all embeded libraries.
-- 
-- **Note:** Do not call this function manually, unless you're absolutely sure that you know what you are doing.
-- @param addon addon object to intialize
function AceAddon:InitializeAddon(addon)
	safecall(addon.OnInitialize, addon)
	
	local embeds = self.embeds[addon]
	for i = 1, #embeds do
		local lib = LibStub:GetLibrary(embeds[i], true)
		if lib then safecall(lib.OnEmbedInitialize, lib, addon) end
	end
	
	-- we don't call InitializeAddon on modules specifically, this is handled
	-- from the event handler and only done _once_
end

-- - Enable the addon after creation.
-- Note: This function is only used internally during the PLAYER_LOGIN event, or during ADDON_LOADED,
-- if IsLoggedIn() already returns true at that point, e.g. for LoD Addons.
-- It will call the **OnEnable** function on the addon object (if present), 
-- and the **OnEmbedEnable** function on all embeded libraries.\\
-- This function does not toggle the enable state of the addon itself, and will return early if the addon is disabled.
--
-- **Note:** Do not call this function manually, unless you're absolutely sure that you know what you are doing.
-- Use :Enable on the addon itself instead.
-- @param addon addon object to enable
function AceAddon:EnableAddon(addon)
	if type(addon) == "string" then addon = AceAddon:GetAddon(addon) end
	if self.statuses[addon.name] or not addon.enabledState then return false end
	
	-- set the statuses first, before calling the OnEnable. this allows for Disabling of the addon in OnEnable.
	self.statuses[addon.name] = true
	
	safecall(addon.OnEnable, addon)
	
	-- make sure we're still enabled before continueing
	if self.statuses[addon.name] then
		local embeds = self.embeds[addon]
		for i = 1, #embeds do
			local lib = LibStub:GetLibrary(embeds[i], true)
			if lib then safecall(lib.OnEmbedEnable, lib, addon) end
		end
	
		-- enable possible modules.
		local modules = addon.orderedModules
		for i = 1, #modules do
			self:EnableAddon(modules[i])
		end
	end
	return self.statuses[addon.name] -- return true if we're disabled
end

-- - Disable the addon
-- Note: This function is only used internally.
-- It will call the **OnDisable** function on the addon object (if present), 
-- and the **OnEmbedDisable** function on all embeded libraries.\\
-- This function does not toggle the enable state of the addon itself, and will return early if the addon is still enabled.
--
-- **Note:** Do not call this function manually, unless you're absolutely sure that you know what you are doing. 
-- Use :Disable on the addon itself instead.
-- @param addon addon object to enable
function AceAddon:DisableAddon(addon)
	if type(addon) == "string" then addon = AceAddon:GetAddon(addon) end
	if not self.statuses[addon.name] then return false end
	
	-- set statuses first before calling OnDisable, this allows for aborting the disable in OnDisable.
	self.statuses[addon.name] = false
	
	safecall( addon.OnDisable, addon )
	
	-- make sure we're still disabling...
	if not self.statuses[addon.name] then 
		local embeds = self.embeds[addon]
		for i = 1, #embeds do
			local lib = LibStub:GetLibrary(embeds[i], true)
			if lib then safecall(lib.OnEmbedDisable, lib, addon) end
		end
		-- disable possible modules.
		local modules = addon.orderedModules
		for i = 1, #modules do
			self:DisableAddon(modules[i])
		end
	end
	
	return not self.statuses[addon.name] -- return true if we're disabled
end

--- Get an iterator over all registered addons.
-- @usage 
-- -- Print a list of all installed AceAddon's
-- for name, addon in AceAddon:IterateAddons() do
--   print("Addon: " .. name)
-- end
function AceAddon:IterateAddons() return pairs(self.addons) end

--- Get an iterator over the internal status registry.
-- @usage 
-- -- Print a list of all enabled addons
-- for name, status in AceAddon:IterateAddonStatus() do
--   if status then
--     print("EnabledAddon: " .. name)
--   end
-- end
function AceAddon:IterateAddonStatus() return pairs(self.statuses) end

-- Following Iterators are deprecated, and their addon specific versions should be used
-- e.g. addon:IterateEmbeds() instead of :IterateEmbedsOnAddon(addon)
function AceAddon:IterateEmbedsOnAddon(addon) return pairs(self.embeds[addon]) end
function AceAddon:IterateModulesOfAddon(addon) return pairs(addon.modules) end

-- Event Handling
local function onEvent(this, event, arg1)
	-- 2011-08-17 nevcairiel - ignore the load event of Blizzard_DebugTools, so a potential startup error isn't swallowed up
	if (event == "ADDON_LOADED"  and arg1 ~= "Blizzard_DebugTools") or event == "PLAYER_LOGIN" then
		-- if a addon loads another addon, recursion could happen here, so we need to validate the table on every iteration
		while(#AceAddon.initializequeue > 0) do
			local addon = tremove(AceAddon.initializequeue, 1)
			-- this might be an issue with recursion - TODO: validate
			if event == "ADDON_LOADED" then addon.baseName = arg1 end
			AceAddon:InitializeAddon(addon)
			tinsert(AceAddon.enablequeue, addon)
		end
		
		if IsLoggedIn() then
			while(#AceAddon.enablequeue > 0) do
				local addon = tremove(AceAddon.enablequeue, 1)
				AceAddon:EnableAddon(addon)
			end
		end
	end
end

AceAddon.frame:RegisterEvent("ADDON_LOADED")
AceAddon.frame:RegisterEvent("PLAYER_LOGIN")
AceAddon.frame:SetScript("OnEvent", onEvent)

-- upgrade embeded
for name, addon in pairs(AceAddon.addons) do
	Embed(addon, true)
end

-- 2010-10-27 nevcairiel - add new "orderedModules" table
if oldminor and oldminor < 10 then
	for name, addon in pairs(AceAddon.addons) do
		addon.orderedModules = {}
		for module_name, module in pairs(addon.modules) do
			tinsert(addon.orderedModules, module)
		end
	end
end
