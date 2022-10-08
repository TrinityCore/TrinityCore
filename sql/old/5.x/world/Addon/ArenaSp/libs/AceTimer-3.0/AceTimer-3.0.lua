--- **AceTimer-3.0** provides a central facility for registering timers.
-- AceTimer supports one-shot timers and repeating timers. All timers are stored in an efficient
-- data structure that allows easy dispatching and fast rescheduling. Timers can be registered
-- or canceled at any time, even from within a running timer, without conflict or large overhead.\\
-- AceTimer is currently limited to firing timers at a frequency of 0.01s. This constant may change
-- in the future, but for now it's required as animations with lower frequencies are buggy.
--
-- All `:Schedule` functions will return a handle to the current timer, which you will need to store if you
-- need to cancel the timer you just registered.
--
-- **AceTimer-3.0** can be embeded into your addon, either explicitly by calling AceTimer:Embed(MyAddon) or by
-- specifying it as an embeded library in your AceAddon. All functions will be available on your addon object
-- and can be accessed directly, without having to explicitly call AceTimer itself.\\
-- It is recommended to embed AceTimer, otherwise you'll have to specify a custom `self` on all calls you
-- make into AceTimer.
-- @class file
-- @name AceTimer-3.0
-- @release $Id: AceTimer-3.0.lua 1079 2013-02-17 19:56:06Z funkydude $

local MAJOR, MINOR = "AceTimer-3.0", 16 -- Bump minor on changes
local AceTimer, oldminor = LibStub:NewLibrary(MAJOR, MINOR)

if not AceTimer then return end -- No upgrade needed

AceTimer.frame = AceTimer.frame or CreateFrame("Frame", "AceTimer30Frame") -- Animation parent
AceTimer.inactiveTimers = AceTimer.inactiveTimers or {}                    -- Timer recycling storage
AceTimer.activeTimers = AceTimer.activeTimers or {}                        -- Active timer list

-- Lua APIs
local type, unpack, next, error, pairs, tostring, select = type, unpack, next, error, pairs, tostring, select

-- Upvalue our private data
local inactiveTimers = AceTimer.inactiveTimers
local activeTimers = AceTimer.activeTimers

local function OnFinished(self)
	local id = self.id
	if type(self.func) == "string" then
		-- We manually set the unpack count to prevent issues with an arg set that contains nil and ends with nil
		-- e.g. local t = {1, 2, nil, 3, nil} print(#t) will result in 2, instead of 5. This fixes said issue.
		self.object[self.func](self.object, unpack(self.args, 1, self.argsCount))
	else
		self.func(unpack(self.args, 1, self.argsCount))
	end

	-- If the id is different it means that the timer was already cancelled
	-- and has been used to create a new timer during the OnFinished callback.
	if not self.looping and id == self.id then
		activeTimers[self.id] = nil
		self.args = nil
		inactiveTimers[self] = true
	end
end

local function new(self, loop, func, delay, ...)
	local timer = next(inactiveTimers)
	if timer then
		inactiveTimers[timer] = nil
	else
		local anim = AceTimer.frame:CreateAnimationGroup()
		timer = anim:CreateAnimation()
		timer:SetScript("OnFinished", OnFinished)
	end

	-- Very low delays cause the animations to fail randomly.
	-- A limited resolution of 0.01 seems reasonable.
	if delay < 0.01 then
		delay = 0.01
	end

	timer.object = self
	timer.func = func
	timer.looping = loop
	timer.args = {...}
	timer.argsCount = select("#", ...)

	local anim = timer:GetParent()
	if loop then
		anim:SetLooping("REPEAT")
	else
		anim:SetLooping("NONE")
	end
	timer:SetDuration(delay)

	local id = tostring(timer.args)
	timer.id = id
	activeTimers[id] = timer

	anim:Play()
	return id
end

--- Schedule a new one-shot timer.
-- The timer will fire once in `delay` seconds, unless canceled before.
-- @param callback Callback function for the timer pulse (funcref or method name).
-- @param delay Delay for the timer, in seconds.
-- @param ... An optional, unlimited amount of arguments to pass to the callback function.
-- @usage
-- MyAddOn = LibStub("AceAddon-3.0"):NewAddon("MyAddOn", "AceTimer-3.0")
--
-- function MyAddOn:OnEnable()
--   self:ScheduleTimer("TimerFeedback", 5)
-- end
--
-- function MyAddOn:TimerFeedback()
--   print("5 seconds passed")
-- end
function AceTimer:ScheduleTimer(func, delay, ...)
	if not func or not delay then
		error(MAJOR..": ScheduleTimer(callback, delay, args...): 'callback' and 'delay' must have set values.", 2)
	end
	if type(func) == "string" then
		if type(self) ~= "table" then
			error(MAJOR..": ScheduleTimer(callback, delay, args...): 'self' - must be a table.", 2)
		elseif not self[func] then
			error(MAJOR..": ScheduleTimer(callback, delay, args...): Tried to register '"..func.."' as the callback, but it doesn't exist in the module.", 2)
		end
	end
	return new(self, nil, func, delay, ...)
end

--- Schedule a repeating timer.
-- The timer will fire every `delay` seconds, until canceled.
-- @param callback Callback function for the timer pulse (funcref or method name).
-- @param delay Delay for the timer, in seconds.
-- @param ... An optional, unlimited amount of arguments to pass to the callback function.
-- @usage
-- MyAddOn = LibStub("AceAddon-3.0"):NewAddon("MyAddOn", "AceTimer-3.0")
--
-- function MyAddOn:OnEnable()
--   self.timerCount = 0
--   self.testTimer = self:ScheduleRepeatingTimer("TimerFeedback", 5)
-- end
--
-- function MyAddOn:TimerFeedback()
--   self.timerCount = self.timerCount + 1
--   print(("%d seconds passed"):format(5 * self.timerCount))
--   -- run 30 seconds in total
--   if self.timerCount == 6 then
--     self:CancelTimer(self.testTimer)
--   end
-- end
function AceTimer:ScheduleRepeatingTimer(func, delay, ...)
	if not func or not delay then
		error(MAJOR..": ScheduleRepeatingTimer(callback, delay, args...): 'callback' and 'delay' must have set values.", 2)
	end
	if type(func) == "string" then
		if type(self) ~= "table" then
			error(MAJOR..": ScheduleRepeatingTimer(callback, delay, args...): 'self' - must be a table.", 2)
		elseif not self[func] then
			error(MAJOR..": ScheduleRepeatingTimer(callback, delay, args...): Tried to register '"..func.."' as the callback, but it doesn't exist in the module.", 2)
		end
	end
	return new(self, true, func, delay, ...)
end

--- Cancels a timer with the given id, registered by the same addon object as used for `:ScheduleTimer`
-- Both one-shot and repeating timers can be canceled with this function, as long as the `id` is valid
-- and the timer has not fired yet or was canceled before.
-- @param id The id of the timer, as returned by `:ScheduleTimer` or `:ScheduleRepeatingTimer`
function AceTimer:CancelTimer(id)
	local timer = activeTimers[id]
	if not timer then return false end

	local anim = timer:GetParent()
	anim:Stop()

	activeTimers[id] = nil
	timer.args = nil
	inactiveTimers[timer] = true
	return true
end

--- Cancels all timers registered to the current addon object ('self')
function AceTimer:CancelAllTimers()
	for k,v in pairs(activeTimers) do
		if v.object == self then
			AceTimer.CancelTimer(self, k)
		end
	end
end

--- Returns the time left for a timer with the given id, registered by the current addon object ('self').
-- This function will return 0 when the id is invalid.
-- @param id The id of the timer, as returned by `:ScheduleTimer` or `:ScheduleRepeatingTimer`
-- @return The time left on the timer.
function AceTimer:TimeLeft(id)
	local timer = activeTimers[id]
	if not timer then return 0 end
	return timer:GetDuration() - timer:GetElapsed()
end


-- ---------------------------------------------------------------------
-- Upgrading

-- Upgrade from old hash-bucket based timers to animation timers
if oldminor and oldminor < 10 then
	-- disable old timer logic
	AceTimer.frame:SetScript("OnUpdate", nil)
	AceTimer.frame:SetScript("OnEvent", nil)
	AceTimer.frame:UnregisterAllEvents()
	-- convert timers
	for object,timers in pairs(AceTimer.selfs) do
		for handle,timer in pairs(timers) do
			if type(timer) == "table" and timer.callback then
				local id
				if timer.delay then
					id = AceTimer.ScheduleRepeatingTimer(timer.object, timer.callback, timer.delay, timer.arg)
				else
					id = AceTimer.ScheduleTimer(timer.object, timer.callback, timer.when - GetTime(), timer.arg)
				end
				-- change id to the old handle
				local t = activeTimers[id]
				activeTimers[id] = nil
				activeTimers[handle] = t
				t.id = handle
			end
		end
	end
	AceTimer.selfs = nil
	AceTimer.hash = nil
	AceTimer.debug = nil
elseif oldminor and oldminor < 13 then
	for handle, id in pairs(AceTimer.hashCompatTable) do
		local t = activeTimers[id]
		if t then
			activeTimers[id] = nil
			activeTimers[handle] = t
			t.id = handle
		end
	end
	AceTimer.hashCompatTable = nil
end

-- upgrade existing timers to the latest OnFinished
for timer in pairs(inactiveTimers) do
	timer:SetScript("OnFinished", OnFinished)
end

for _,timer in pairs(activeTimers) do
	timer:SetScript("OnFinished", OnFinished)
end

-- ---------------------------------------------------------------------
-- Embed handling

AceTimer.embeds = AceTimer.embeds or {}

local mixins = {
	"ScheduleTimer", "ScheduleRepeatingTimer",
	"CancelTimer", "CancelAllTimers",
	"TimeLeft"
}

function AceTimer:Embed(target)
	AceTimer.embeds[target] = true
	for _,v in pairs(mixins) do
		target[v] = AceTimer[v]
	end
	return target
end

-- AceTimer:OnEmbedDisable(target)
-- target (object) - target object that AceTimer is embedded in.
--
-- cancel all timers registered for the object
function AceTimer:OnEmbedDisable(target)
	target:CancelAllTimers()
end

for addon in pairs(AceTimer.embeds) do
	AceTimer:Embed(addon)
end
