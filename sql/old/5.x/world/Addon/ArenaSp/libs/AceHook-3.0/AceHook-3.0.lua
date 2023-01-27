--- **AceHook-3.0** offers safe Hooking/Unhooking of functions, methods and frame scripts.
-- Using AceHook-3.0 is recommended when you need to unhook your hooks again, so the hook chain isn't broken
-- when you manually restore the original function.
--
-- **AceHook-3.0** can be embeded into your addon, either explicitly by calling AceHook:Embed(MyAddon) or by 
-- specifying it as an embeded library in your AceAddon. All functions will be available on your addon object
-- and can be accessed directly, without having to explicitly call AceHook itself.\\
-- It is recommended to embed AceHook, otherwise you'll have to specify a custom `self` on all calls you
-- make into AceHook.
-- @class file
-- @name AceHook-3.0
-- @release $Id: AceHook-3.0.lua 1118 2014-10-12 08:21:54Z nevcairiel $
local ACEHOOK_MAJOR, ACEHOOK_MINOR = "AceHook-3.0", 8
local AceHook, oldminor = LibStub:NewLibrary(ACEHOOK_MAJOR, ACEHOOK_MINOR)

if not AceHook then return end -- No upgrade needed

AceHook.embeded = AceHook.embeded or {}
AceHook.registry = AceHook.registry or setmetatable({}, {__index = function(tbl, key) tbl[key] = {} return tbl[key] end })
AceHook.handlers = AceHook.handlers or {}
AceHook.actives = AceHook.actives or {}
AceHook.scripts = AceHook.scripts or {}
AceHook.onceSecure = AceHook.onceSecure or {}
AceHook.hooks = AceHook.hooks or {}

-- local upvalues
local registry = AceHook.registry
local handlers = AceHook.handlers
local actives = AceHook.actives
local scripts = AceHook.scripts
local onceSecure = AceHook.onceSecure

-- Lua APIs
local pairs, next, type = pairs, next, type
local format = string.format
local assert, error = assert, error

-- WoW APIs
local issecurevariable, hooksecurefunc = issecurevariable, hooksecurefunc
local _G = _G

-- functions for later definition
local donothing, createHook, hook

local protectedScripts = {
	OnClick = true,
}

-- upgrading of embeded is done at the bottom of the file

local mixins = {
	"Hook", "SecureHook",
	"HookScript", "SecureHookScript",
	"Unhook", "UnhookAll",
	"IsHooked",
	"RawHook", "RawHookScript"
}

-- AceHook:Embed( target )
-- target (object) - target object to embed AceHook in
--
-- Embeds AceEevent into the target object making the functions from the mixins list available on target:..
function AceHook:Embed( target )
	for k, v in pairs( mixins ) do
		target[v] = self[v]
	end
	self.embeded[target] = true
	-- inject the hooks table safely
	target.hooks = target.hooks or {}
	return target
end

-- AceHook:OnEmbedDisable( target )
-- target (object) - target object that is being disabled
--
-- Unhooks all hooks when the target disables.
-- this method should be called by the target manually or by an addon framework
function AceHook:OnEmbedDisable( target )
	target:UnhookAll()
end

function createHook(self, handler, orig, secure, failsafe)
	local uid
	local method = type(handler) == "string"
	if failsafe and not secure then
		-- failsafe hook creation
		uid = function(...)
			if actives[uid] then
				if method then
					self[handler](self, ...)
				else
					handler(...)
				end
			end
			return orig(...)
		end
		-- /failsafe hook
	else
		-- all other hooks
		uid = function(...)
			if actives[uid] then
				if method then
					return self[handler](self, ...)
				else
					return handler(...)
				end
			elseif not secure then -- backup on non secure
				return orig(...)
			end
		end
		-- /hook
	end
	return uid
end

function donothing() end

function hook(self, obj, method, handler, script, secure, raw, forceSecure, usage)
	if not handler then handler = method end
	
	-- These asserts make sure AceHooks's devs play by the rules.
	assert(not script or type(script) == "boolean")
	assert(not secure or type(secure) == "boolean")
	assert(not raw or type(raw) == "boolean")
	assert(not forceSecure or type(forceSecure) == "boolean")
	assert(usage)
	
	-- Error checking Battery!
	if obj and type(obj) ~= "table" then
		error(format("%s: 'object' - nil or table expected got %s", usage, type(obj)), 3)
	end
	if type(method) ~= "string" then
		error(format("%s: 'method' - string expected got %s", usage, type(method)), 3)
	end
	if type(handler) ~= "string" and type(handler) ~= "function" then
		error(format("%s: 'handler' - nil, string, or function expected got %s", usage, type(handler)), 3)
	end
	if type(handler) == "string" and type(self[handler]) ~= "function" then
		error(format("%s: 'handler' - Handler specified does not exist at self[handler]", usage), 3)
	end
	if script then
		if not obj or not obj.GetScript or not obj:HasScript(method) then
			error(format("%s: You can only hook a script on a frame object", usage), 3)
		end
		if not secure and obj.IsProtected and obj:IsProtected() and protectedScripts[method] then
			error(format("Cannot hook secure script %q; Use SecureHookScript(obj, method, [handler]) instead.", method), 3)
		end
	else
		local issecure 
		if obj then 
			issecure = onceSecure[obj] and onceSecure[obj][method] or issecurevariable(obj, method)
		else
			issecure = onceSecure[method] or issecurevariable(method)
		end
		if issecure then
			if forceSecure then
				if obj then
					onceSecure[obj] = onceSecure[obj] or {}
					onceSecure[obj][method] = true
				else
					onceSecure[method] = true
				end
			elseif not secure then
				error(format("%s: Attempt to hook secure function %s. Use `SecureHook' or add `true' to the argument list to override.", usage, method), 3)
			end
		end
	end
	
	local uid
	if obj then
		uid = registry[self][obj] and registry[self][obj][method]
	else
		uid = registry[self][method]
	end
	
	if uid then
		if actives[uid] then
			-- Only two sane choices exist here.  We either a) error 100% of the time or b) always unhook and then hook
			-- choice b would likely lead to odd debuging conditions or other mysteries so we're going with a.
			error(format("Attempting to rehook already active hook %s.", method))
		end
		
		if handlers[uid] == handler then -- turn on a decative hook, note enclosures break this ability, small memory leak
			actives[uid] = true
			return
		elseif obj then -- is there any reason not to call unhook instead of doing the following several lines?
			if self.hooks and self.hooks[obj] then
				self.hooks[obj][method] = nil
			end
			registry[self][obj][method] = nil
		else
			if self.hooks then
				self.hooks[method] = nil
			end
			registry[self][method] = nil
		end
		handlers[uid], actives[uid], scripts[uid] = nil, nil, nil
		uid = nil
	end
	
	local orig
	if script then
		orig = obj:GetScript(method) or donothing
	elseif obj then
		orig = obj[method]
	else
		orig = _G[method]
	end
	
	if not orig then
		error(format("%s: Attempting to hook a non existing target", usage), 3)
	end
	
	uid = createHook(self, handler, orig, secure, not (raw or secure))
	
	if obj then
		self.hooks[obj] = self.hooks[obj] or {}
		registry[self][obj] = registry[self][obj] or {}
		registry[self][obj][method] = uid

		if not secure then
			self.hooks[obj][method] = orig
		end
		
		if script then
			if not secure then
				obj:SetScript(method, uid)
			else
				obj:HookScript(method, uid)
			end
		else
			if not secure then
				obj[method] = uid
			else
				hooksecurefunc(obj, method, uid)
			end
		end
	else
		registry[self][method] = uid
		
		if not secure then
			_G[method] = uid
			self.hooks[method] = orig
		else
			hooksecurefunc(method, uid)
		end
	end
	
	actives[uid], handlers[uid], scripts[uid] = true, handler, script and true or nil	
end

--- Hook a function or a method on an object.
-- The hook created will be a "safe hook", that means that your handler will be called
-- before the hooked function ("Pre-Hook"), and you don't have to call the original function yourself,
-- however you cannot stop the execution of the function, or modify any of the arguments/return values.\\
-- This type of hook is typically used if you need to know if some function got called, and don't want to modify it.
-- @paramsig [object], method, [handler], [hookSecure]
-- @param object The object to hook a method from
-- @param method If object was specified, the name of the method, or the name of the function to hook.
-- @param handler The handler for the hook, a funcref or a method name. (Defaults to the name of the hooked function)
-- @param hookSecure If true, AceHook will allow hooking of secure functions.
-- @usage
-- -- create an addon with AceHook embeded
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("HookDemo", "AceHook-3.0")
-- 
-- function MyAddon:OnEnable()
--   -- Hook ActionButton_UpdateHotkeys, overwriting the secure status
--   self:Hook("ActionButton_UpdateHotkeys", true)
-- end
--
-- function MyAddon:ActionButton_UpdateHotkeys(button, type)
--   print(button:GetName() .. " is updating its HotKey")
-- end
function AceHook:Hook(object, method, handler, hookSecure)
	if type(object) == "string" then
		method, handler, hookSecure, object = object, method, handler, nil
	end
	
	if handler == true then
		handler, hookSecure = nil, true
	end

	hook(self, object, method, handler, false, false, false, hookSecure or false, "Usage: Hook([object], method, [handler], [hookSecure])")	
end

--- RawHook a function or a method on an object.
-- The hook created will be a "raw hook", that means that your handler will completly replace
-- the original function, and your handler has to call the original function (or not, depending on your intentions).\\
-- The original function will be stored in `self.hooks[object][method]` or `self.hooks[functionName]` respectively.\\
-- This type of hook can be used for all purposes, and is usually the most common case when you need to modify arguments
-- or want to control execution of the original function.
-- @paramsig [object], method, [handler], [hookSecure]
-- @param object The object to hook a method from
-- @param method If object was specified, the name of the method, or the name of the function to hook.
-- @param handler The handler for the hook, a funcref or a method name. (Defaults to the name of the hooked function)
-- @param hookSecure If true, AceHook will allow hooking of secure functions.
-- @usage
-- -- create an addon with AceHook embeded
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("HookDemo", "AceHook-3.0")
-- 
-- function MyAddon:OnEnable()
--   -- Hook ActionButton_UpdateHotkeys, overwriting the secure status
--   self:RawHook("ActionButton_UpdateHotkeys", true)
-- end
--
-- function MyAddon:ActionButton_UpdateHotkeys(button, type)
--   if button:GetName() == "MyButton" then
--     -- do stuff here
--   else
--     self.hooks.ActionButton_UpdateHotkeys(button, type)
--   end
-- end
function AceHook:RawHook(object, method, handler, hookSecure)
	if type(object) == "string" then
		method, handler, hookSecure, object = object, method, handler, nil
	end
	
	if handler == true then
		handler, hookSecure = nil, true
	end
	
	hook(self, object, method, handler, false, false, true, hookSecure or false,  "Usage: RawHook([object], method, [handler], [hookSecure])")
end

--- SecureHook a function or a method on an object.
-- This function is a wrapper around the `hooksecurefunc` function in the WoW API. Using AceHook
-- extends the functionality of secure hooks, and adds the ability to unhook once the hook isn't
-- required anymore, or the addon is being disabled.\\
-- Secure Hooks should be used if the secure-status of the function is vital to its function,
-- and taint would block execution. Secure Hooks are always called after the original function was called
-- ("Post Hook"), and you cannot modify the arguments, return values or control the execution.
-- @paramsig [object], method, [handler]
-- @param object The object to hook a method from
-- @param method If object was specified, the name of the method, or the name of the function to hook.
-- @param handler The handler for the hook, a funcref or a method name. (Defaults to the name of the hooked function)
function AceHook:SecureHook(object, method, handler)
	if type(object) == "string" then
		method, handler, object = object, method, nil
	end
	
	hook(self, object, method, handler, false, true, false, false,  "Usage: SecureHook([object], method, [handler])")
end

--- Hook a script handler on a frame.
-- The hook created will be a "safe hook", that means that your handler will be called
-- before the hooked script ("Pre-Hook"), and you don't have to call the original function yourself,
-- however you cannot stop the execution of the function, or modify any of the arguments/return values.\\
-- This is the frame script equivalent of the :Hook safe-hook. It would typically be used to be notified
-- when a certain event happens to a frame.
-- @paramsig frame, script, [handler]
-- @param frame The Frame to hook the script on
-- @param script The script to hook
-- @param handler The handler for the hook, a funcref or a method name. (Defaults to the name of the hooked script)
-- @usage
-- -- create an addon with AceHook embeded
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("HookDemo", "AceHook-3.0")
-- 
-- function MyAddon:OnEnable()
--   -- Hook the OnShow of FriendsFrame 
--   self:HookScript(FriendsFrame, "OnShow", "FriendsFrameOnShow")
-- end
--
-- function MyAddon:FriendsFrameOnShow(frame)
--   print("The FriendsFrame was shown!")
-- end
function AceHook:HookScript(frame, script, handler)
	hook(self, frame, script, handler, true, false, false, false,  "Usage: HookScript(object, method, [handler])")
end

--- RawHook a script handler on a frame.
-- The hook created will be a "raw hook", that means that your handler will completly replace
-- the original script, and your handler has to call the original script (or not, depending on your intentions).\\
-- The original script will be stored in `self.hooks[frame][script]`.\\
-- This type of hook can be used for all purposes, and is usually the most common case when you need to modify arguments
-- or want to control execution of the original script.
-- @paramsig frame, script, [handler]
-- @param frame The Frame to hook the script on
-- @param script The script to hook
-- @param handler The handler for the hook, a funcref or a method name. (Defaults to the name of the hooked script)
-- @usage
-- -- create an addon with AceHook embeded
-- MyAddon = LibStub("AceAddon-3.0"):NewAddon("HookDemo", "AceHook-3.0")
-- 
-- function MyAddon:OnEnable()
--   -- Hook the OnShow of FriendsFrame 
--   self:RawHookScript(FriendsFrame, "OnShow", "FriendsFrameOnShow")
-- end
--
-- function MyAddon:FriendsFrameOnShow(frame)
--   -- Call the original function
--   self.hooks[frame].OnShow(frame)
--   -- Do our processing
--   -- .. stuff
-- end
function AceHook:RawHookScript(frame, script, handler)
	hook(self, frame, script, handler, true, false, true, false, "Usage: RawHookScript(object, method, [handler])")
end

--- SecureHook a script handler on a frame.
-- This function is a wrapper around the `frame:HookScript` function in the WoW API. Using AceHook
-- extends the functionality of secure hooks, and adds the ability to unhook once the hook isn't
-- required anymore, or the addon is being disabled.\\
-- Secure Hooks should be used if the secure-status of the function is vital to its function,
-- and taint would block execution. Secure Hooks are always called after the original function was called
-- ("Post Hook"), and you cannot modify the arguments, return values or control the execution.
-- @paramsig frame, script, [handler]
-- @param frame The Frame to hook the script on
-- @param script The script to hook
-- @param handler The handler for the hook, a funcref or a method name. (Defaults to the name of the hooked script)
function AceHook:SecureHookScript(frame, script, handler)
	hook(self, frame, script, handler, true, true, false, false, "Usage: SecureHookScript(object, method, [handler])")
end

--- Unhook from the specified function, method or script.
-- @paramsig [obj], method
-- @param obj The object or frame to unhook from
-- @param method The name of the method, function or script to unhook from.
function AceHook:Unhook(obj, method)
	local usage = "Usage: Unhook([obj], method)"
	if type(obj) == "string" then
		method, obj = obj, nil
	end
		
	if obj and type(obj) ~= "table" then
		error(format("%s: 'obj' - expecting nil or table got %s", usage, type(obj)), 2)
	end
	if type(method) ~= "string" then
		error(format("%s: 'method' - expeting string got %s", usage, type(method)), 2)
	end
	
	local uid
	if obj then
		uid = registry[self][obj] and registry[self][obj][method]
	else
		uid = registry[self][method]
	end
	
	if not uid or not actives[uid] then
		-- Declining to error on an unneeded unhook since the end effect is the same and this would just be annoying.
		return false
	end
	
	actives[uid], handlers[uid] = nil, nil
	
	if obj then
		registry[self][obj][method] = nil
		registry[self][obj] = next(registry[self][obj]) and registry[self][obj] or nil
		
		-- if the hook reference doesnt exist, then its a secure hook, just bail out and dont do any unhooking
		if not self.hooks[obj] or not self.hooks[obj][method] then return true end
		
		if scripts[uid] and obj:GetScript(method) == uid then  -- unhooks scripts
			obj:SetScript(method, self.hooks[obj][method] ~= donothing and self.hooks[obj][method] or nil)	
			scripts[uid] = nil
		elseif obj and self.hooks[obj] and self.hooks[obj][method] and obj[method] == uid then -- unhooks methods
			obj[method] = self.hooks[obj][method]
		end
		
		self.hooks[obj][method] = nil
		self.hooks[obj] = next(self.hooks[obj]) and self.hooks[obj] or nil
	else
		registry[self][method] = nil
		
		-- if self.hooks[method] doesn't exist, then this is a SecureHook, just bail out
		if not self.hooks[method] then return true end
		
		if self.hooks[method] and _G[method] == uid then -- unhooks functions
			_G[method] = self.hooks[method]
		end
		
		self.hooks[method] = nil
	end
	return true
end

--- Unhook all existing hooks for this addon.
function AceHook:UnhookAll()
	for key, value in pairs(registry[self]) do
		if type(key) == "table" then
			for method in pairs(value) do
				self:Unhook(key, method)
			end
		else
			self:Unhook(key)
		end
	end
end

--- Check if the specific function, method or script is already hooked.
-- @paramsig [obj], method
-- @param obj The object or frame to unhook from
-- @param method The name of the method, function or script to unhook from.
function AceHook:IsHooked(obj, method)
	-- we don't check if registry[self] exists, this is done by evil magicks in the metatable
	if type(obj) == "string" then
		if registry[self][obj] and actives[registry[self][obj]] then
			return true, handlers[registry[self][obj]]
		end
	else
		if registry[self][obj] and registry[self][obj][method] and actives[registry[self][obj][method]] then
			return true, handlers[registry[self][obj][method]]
		end
	end
	
	return false, nil
end

--- Upgrade our old embeded
for target, v in pairs( AceHook.embeded ) do
	AceHook:Embed( target )
end
