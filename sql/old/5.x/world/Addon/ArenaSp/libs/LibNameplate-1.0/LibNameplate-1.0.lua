--[[
Name: LibNameplate-1.0
Author(s): Cyprias (cyprias@gmail.com)
Documentation: http://www.wowace.com/addons/libnameplate-1-0/pages/main/
SVN:  svn://svn.wowace.com/wow/libnameplate-1-0/mainline/trunk
Description: Alerts addons when a nameplate is shown or hidden. Has API to get info such as name, level, class, ect from the nameplate. LibNameplate tries to function with the default nameplates, Aloft, caelNamePlates and TidyPlates (buggy).
Dependencies: LibStub, CallbackHandler-1.0
License: GNU General Public License version 3 (GPLv3)
]]

local MAJOR, MINOR = "LibNameplate-1.0", 45
if not LibStub then error(MAJOR .. " requires LibStub.") return end

-- Create lib
local lib = LibStub:NewLibrary(MAJOR, MINOR)
if not lib then return end

-- Make sure CallbackHandler exists.
lib.callbacks = lib.callbacks or LibStub("CallbackHandler-1.0"):New(lib)
if not lib.callbacks then	error(MAJOR .. " CallbackHandler-1.0.") return end

local fastOnFinishThrottle = 0.25 -- check combat & threat every x seconds.
local slowOnFinishThrottle = 1 -- Check for lingering mouseover texture and for TidyPlates frame.

--[[ WoW 4.0.6
local regionOrder = {
	[1] = "threatTexture",
	[2] = "healthBorder",
	[3] = "castBorder",
	[4] = "castShieldIcon",
	[5] = "spellIcon",
	[6] = "highlightTexture",
	[7] = "nameText",
	[8] = "levelText",
	[9] = "skullIcon",
	[10] = "raidIcon",
	[11] = "eliteIcon",
}
]]

--[[ WoW 4.1
local regionOrder = {
	[1] = "threatTexture",
	[2] = "healthBorder",
	[3] = "highlightTexture",
	[4] = "nameText",
	[5] = "levelText",
	[6] = "skullIcon",
	[7] = "raidIcon",
	[8] = "eliteIcon",
}
]]

--  WoW 5.1
local regionOrder = {
	[1] = "threatTexture",
	[2] = "healthBorder",
	[3] = "highlightTexture",
	[4] = "levelText",
	[5] = "skullIcon",
	[6] = "raidIcon",
	[7] = "eliteIcon",
        --[7] = "nameText",
}

local childOrder = {
	[1] = "healthBar",
	[2] = "castBar",
}

-- Upvalue WoW API
local IsInRaid, IsInGroup, GetNumGroupMembers, GetNumSubgroupMembers, UnitName, UnitLevel, UnitGUID, UnitExists, UnitHealth, UnitHealthMax, UnitIsUnit, GetMouseFocus, GetRaidTargetIndex = 
			IsInRaid, IsInGroup, GetNumGroupMembers, GetNumSubgroupMembers, UnitName, UnitLevel, UnitGUID, UnitExists, UnitHealth, UnitHealthMax, UnitIsUnit, GetMouseFocus, GetRaidTargetIndex
			
-- Upvalue Lua API
local hooksecurefunc, ipairs, pairs, select, unpack, wipe, tostring, tonumber, print, math_floor, table_insert = 
			hooksecurefunc, ipairs, pairs, select, unpack, wipe, tostring, tonumber, print, math.floor, table.insert


local regionIndex = {}
local childIndex = {}

for i, name in ipairs(regionOrder) do 
	regionIndex[name] = i
end
for i, name in ipairs(childOrder) do 
	childIndex[name] = i
end

local callbackOnHide				= "LibNameplate_RecycleNameplate"
local callbackOnShow				= "LibNameplate_NewNameplate"
local callbackFoundGUID				= "LibNameplate_FoundGUID"
local callbackOnTarget				= "LibNameplate_TargetNameplate"
local callbackHealthChanged			= "LibNameplate_HealthChange"
local callbackCombatChanged 		= "LibNameplate_CombatChange"
local callbackThreatChanged			= "LibNameplate_ThreatChange"
local callbackMouseoverNameplate	= "LibNameplate_MouseoverNameplate"

--local NP = ElvUI[1].NamePlates.CreatedPlates


lib.nameplates		= lib.nameplates	or {}
lib.realPlate		= lib.realPlate		or {}
lib.fakePlate		= lib.fakePlate		or {}
lib.plateGUIDs		= lib.plateGUIDs	or {}
--lib.ElvPlate		= lib.ElvPlate		or {}

lib.isOnScreen		= lib.isOnScreen	or {} -- Helps me track broken OnShow/OnHide hooks.
-- ~ lib.isOnUpdating	= lib.isOnUpdating	or {}
lib.healthOnValueChangedHooks = lib.healthOnValueChangedHooks or {}
lib.combatStatus	= lib.combatStatus	or {}
lib.threatStatus	= lib.threatStatus	or {}

local debugPrint
do
	local DEBUG = false
	--[===[@debug@
	DEBUG = true
	--@end-debug@]===]
	
	local function CmdHandler()
		DEBUG = not DEBUG
	end
	_G.SlashCmdList["LIBNAMEPLATEDEBUG"] = CmdHandler
	_G.SLASH_LIBNAMEPLATEDEBUG1 = "/lnpbug"
	
	function debugPrint(...)
		if DEBUG then
			print(MAJOR,...)
		end
	end
end



local IsNamePlateFrame
do 
	--[[
		GetName() should return nil.
		GetID() should return 0
		GetObjectType should return "Frame"
		GetNumChildren = 2
		GetNumRegions = 11
	]]
	local wantedName = "NamePlate"
	local wantedID = 0
	local wantedObjectType = "Frame"
	local wantedNumChildren = 2
	local wantedNumRegions = 0
    local frameName
	
	function IsNamePlateFrame(frame)
-- ~ 		debugPrint("IsNamePlateFrame", "--------------------------------------")
		
--		print("IsNamePlateFrame step 1", frame:GetName())
		if frame.extended or frame.aloftData or frame.ElvUIPlate then

			-- Tidyplates = extended, Aloft = aloftData
			-- They sometimes remove & replace the children so this needs to be checked first.
			return true
		end
--		print("IsNamePlateFrame step 2", frame:GetName())
		if frame.done then -- caelNP
			return true
		end
--		print("IsNamePlateFrame step 3", frame:GetName())
        frameName = frame:GetName();
		
		if not frameName then return
			false
		end
		
		if frameName and frameName:sub(1,9) ~= wantedName then
			debugPrint("GetName", frame:GetName())
			return false
		end
		
--		print("IsNamePlateFrame step 4", frame:GetName())
		if frame:GetID() ~= wantedID then
			debugPrint("GetID", frame:GetID())
			return false
		end
	--	print("IsNamePlateFrame step 5", frame:GetName())
		if frame:GetObjectType() ~= wantedObjectType then
			debugPrint("GetObjectType", frame:GetObjectType())
			return false
		end
--		print("IsNamePlateFrame step 6", frame:GetName())
		if frame:GetNumChildren() ~= wantedNumChildren then
-- ~ 			debugPrint("GetNumChildren", frame:GetNumChildren())
			return false
		end
--		print("IsNamePlateFrame step 7", frame:GetName())
		if frame:GetNumRegions() ~= wantedNumRegions then
			debugPrint("GetNumRegions", frame:GetNumRegions())
			return false
		end
--		print("IsNamePlateFrame step 8", frame:GetName())
		return true
	end
end


local Round
do
	local zeros
	------------------------------------------------------------------ 
	function Round(num, zeros)									-- 
	-- zeroes is the number of decimal places. eg 1=*.*, 3=*.***	-- 
	------------------------------------------------------------------ 
		zeros = zeros or 0
		return math_floor( num * 10 ^ zeros + 0.5 ) / 10 ^ zeros
	end
end


local ScanWorldFrameChildren
do 
	function ScanWorldFrameChildren(frame, ...)
		if not frame then
			return
		end
		
		if frame:IsShown() and not lib.nameplates[frame] and IsNamePlateFrame(frame) then
			lib:NameplateFirstLoad(frame)
		end
		
		return ScanWorldFrameChildren(...)
	end
end

do
	local WorldFrame = WorldFrame
	local curChildren
	local prevChildren = 0
	local function onUpdate(this, elapsed)
		local curChildren = WorldFrame:GetNumChildren()
		if curChildren ~= prevChildren then
			prevChildren = curChildren
-- ~ 			debugPrint("WorldFrame Children", curChildren)
			ScanWorldFrameChildren( WorldFrame:GetChildren() )
		end
	end

	lib.scanForPlate = lib.scanForPlate or CreateFrame("frame")
	lib.scanForPlate:SetScript("OnUpdate", onUpdate)
end

local function FoundPlateGUID(frame, GUID, unitID)
	lib.plateGUIDs[frame] = GUID
	
--	assert(lib.realPlate[frame], "RealFrameNotFound "..frame:GetName())
--	print(GetTime(), "FoundPlateGUID", lib.realPlate[frame], ElvUI[1].NamePlates.CreatedPlates[frame], GUID, unitID)
-- ~ 	debugPrint("FoundPlateGUID", lib:GetName(frame), GUID)
	lib.callbacks:Fire(callbackFoundGUID, lib.fakePlate[frame] or frame, GUID, unitID)
end

do 
	local checkForGUID = {}
	local f = CreateFrame("Frame")
	f:Hide()
	f:SetScript("OnUpdate", function(this, elapsed) 
		for frame in pairs(checkForGUID) do 
			if not lib.plateGUIDs[frame] and lib:IsTarget(frame) then--((frame:GetAlpha() == 1) and UnitExists("target")) then
				lib.callbacks:Fire(callbackOnTarget, lib.fakePlate[frame] or frame)
				FoundPlateGUID(frame, UnitGUID("target"), "target")
			end
		end
		wipe(checkForGUID)
		this:Hide()
	end)
	
	function lib:CheckFrameForTargetGUID(frame)
		checkForGUID[frame] = true
		f:Show()
	end
end

--[[]]
do
	local plateName
	function lib:SetupNameplate(frame)
		self.isOnScreen[frame] = true
		
-- ~ 		for i, group in ipairs(self.onFinishedGroups[frame]) do
-- ~ 			group:Play()
-- ~ 		end
-- ~ 		
		if frame.extended and not self.fakePlate[frame] then
			self.fakePlate[frame] = frame.extended
			self.realPlate[frame.extended] = frame
			
			-- Without this was causing problems with PlateBuffs where it was never told the real plate was gone.
			self.callbacks:Fire(callbackOnHide, frame)
		end
		
	--	if ElvUI and ElvUI and ElvUI[1].NamePlates and ElvUI[1].NamePlates.enabledState and ElvUI[1].NamePlates.CreatedPlates[frame]  then---self.CreatedPlates[frame] = myPlate
		
	--		lib.ElvPlate[ElvUI[1].NamePlates.CreatedPlates[frame]] = frame
			
	--		print("DONE 1")
			
	--		self.fakePlate[frame] = ElvUI[1].NamePlates.CreatedPlates[frame]
	--		self.realPlate[ElvUI[1].NamePlates.CreatedPlates[frame]] = frame
			
		--	self.callbacks:Fire(callbackOnHide, frame)
			
	--	end

		self.callbacks:Fire(callbackOnShow, self.fakePlate[frame] or frame)

		self:CheckFrameForTargetGUID(frame)
	end
end

do
	function lib:NameplateOnShow(frame)
		
		if frame:GetName() == nil then return end
	--	print("OnShow frame", frame:GetName(), frame:IsShown(), frame,self.fakePlate[frame] )
		
		self:SetupNameplate(frame)
	end
end

do
	local fake
	function lib:RecycleNameplate(frame)
	
		if frame:GetName() == nil then return end
		
		
		self.plateGUIDs[frame] = nil
		
	--	print("Clear frame", frame:GetName(), frame:IsShown(), frame,self.fakePlate[frame] )
-- ~ 		debugPrint("RecycleNameplate",frame, self:GetName(frame))
		if self.fakePlate[frame] then
			self.callbacks:Fire(callbackOnHide, self.fakePlate[frame])
		end
		self.callbacks:Fire(callbackOnHide, frame)
		
		--[[
		fake = lib.fakePlate[frame]
		if fake then
			self.realPlate[fake] = false
		end
		self.fakePlate[frame] = false]]
	end
end

-- ~ lib.animationGroups = lib.animationGroups or {}
lib.plateAnimations = lib.plateAnimations or {}
do 
	function lib:NameplateOnHide(frame)
		self.isOnScreen[frame] = false
-- ~ 		self.isOnUpdating[frame] = false
		
-- ~ 		self.animationGroups[frame]:Stop()
		for i, group in ipairs(self.onFinishedGroups[frame]) do
			group:Play()
		end
		
		
		self:RecycleNameplate(frame)
	end
end

local FindGUIDByRaidIcon
do 
	local targetID
	local targetIndex
	local function CheckRaidIconOnUnit(unitID, frame, raidNum, from)
		targetID = unitID.."target"
		if UnitExists(targetID) and not UnitIsUnit("target", targetID) then
			targetIndex = GetRaidTargetIndex(targetID)
			if targetIndex and targetIndex == raidNum then
				debugPrint("FindGUIDByRaidIcon", from, "Icon:"..tostring(raidNum), "unitID:"..tostring(targetID), "GUID:"..tostring(UnitGUID(targetID)))
				FoundPlateGUID(frame, UnitGUID(targetID), targetID)
				return true
			end
		end
		return false
	end

	local group, num
	function FindGUIDByRaidIcon(frame, raidNum, from)
		
		if IsInRaid() then
			group, num = "raid", GetNumGroupMembers()
		elseif IsInGroup() then
			group, num = "party", GetNumSubgroupMembers()
		else
			return
		end
		
		local unitID
		for i = 1, num do
			unitID = group..i;
			if CheckRaidIconOnUnit(unitID, frame, raidNum, from) then 
				return
			end
			
			if UnitExists(unitID.."pet") and CheckRaidIconOnUnit(unitID.."pet", frame, raidNum, from) then
				return
			end
		end
	end
end

local GetMouseoverGUID
do
	local unitID = "mouseover"
	function GetMouseoverGUID(frame)
		if UnitExists(unitID) then
			FoundPlateGUID(frame, UnitGUID(unitID), unitID)
		end
	end
end

do
	local inCombat
	local function CheckCombatStatus(frame)
		inCombat = lib:IsInCombat(frame)
		if lib.combatStatus[frame] ~= inCombat then
			lib.combatStatus[frame] = inCombat
	-- ~ 			debugPrint("OnNameplateUpdate D", inCombat, "LibNameplate_CombatChange")
			lib.callbacks:Fire(callbackCombatChanged, lib.fakePlate[frame] or frame, inCombat)
		end
	end

	local threatSit
	local function CheckThreatStatus(frame)
		threatSit = lib:GetThreatSituation(frame)
		if lib.threatStatus[frame] ~= threatSit then
			lib.threatStatus[frame] = threatSit
	-- ~ 		debugPrint("CheckThreatStatus D", threatSit, "LibNameplate_ThreatChange")
			lib.callbacks:Fire(callbackThreatChanged, lib.fakePlate[frame] or frame, threatSit)
		end
	end

	
	function lib:NameplateFastAnimation(frame)
		CheckCombatStatus(frame)
		CheckThreatStatus(frame)
	end
end

do 
	local function CheckForFakePlate(frame)
		if frame.extended then
			lib.realPlate[frame.extended] = frame
			lib.fakePlate[frame] = frame.extended
		
		
-- ~ 			debugPrint("CheckForFakePlate", frame)
			lib.callbacks:Fire(callbackOnHide, frame)-- Hide real plate so addon unhook their stuff.
-- ~ 			lib.callbacks:Fire(callbackOnShow, lib.fakePlate[frame])
		end
		
	--	if ElvUI and ElvUI and ElvUI[1].NamePlates and ElvUI[1].NamePlates.enabledState and ElvUI[1].NamePlates.CreatedPlates[frame]  then---self.CreatedPlates[frame] = myPlate
		
	--		lib.ElvPlate[ElvUI[1].NamePlates.CreatedPlates[frame]] = frame
			
	--		print("DONE 1")
			
	--		self.fakePlate[frame] = ElvUI[1].NamePlates.CreatedPlates[frame]
	--		self.realPlate[ElvUI[1].NamePlates.CreatedPlates[frame]] = frame
			
		--	self.callbacks:Fire(callbackOnHide, frame)
			
	--	end
		
		
	end

	function lib:NameplateSlowAnimation(frame)
		if self:IsMouseover(frame) and not UnitExists("mouseover") then
			self:HideMouseoverRegion(frame)
		end
		if not self.fakePlate[frame] then
			CheckForFakePlate(frame)
		end
	end
end

--[[
function lib:NameplateOnUpdate(frame, elapsed)
	self.isOnUpdating[frame] = true 
end
]]

-- ~ function lib:NameplateSetAlpha(frame)
-- ~ 	debugPrint("NameplateSetAlpha", frame)
-- ~ end

do
	local health, maxHealth
	local function CheckUnitIDForMatchingHP(unitID, frameName, current, max)
		local targetID = unitID.."target"
		if UnitName(targetID) == frameName then
			health = UnitHealth(targetID)
			maxHealth = UnitHealthMax(targetID)
	
			if health == current and maxHealth == max then
				return true
			end
		end
		return false
	end
	
	local bar
	local _, max
-- ~ 	local current
	local possibleUnits = {}
	local frameName
	local unitID, targetID, targetIndex
	local group, num
	function lib:NewNameplateCheckHP(frame, current)
		bar = self.plateChildren[frame].healthBar
		if bar and bar.GetValue then -- bar.GetMinMaxValues then
			_, max = bar:GetMinMaxValues()
	-- ~ 		return tonumber(max or 0)
-- ~ 			current = bar:GetValue()
			
			
			if current > 0 and current ~= max then

				if IsInRaid() then
					group, num = "raid", GetNumGroupMembers()
				elseif IsInGroup() then
					group, num = "party", GetNumSubgroupMembers()
				else
					return
				end
			
				wipe(possibleUnits)
	
				frameName = self:GetName(frame)
				for i = 1, num do
					unitID = group..i;
					if CheckUnitIDForMatchingHP(unitID, frameName, current, max) then
						table_insert(possibleUnits, #possibleUnits+1, unitID.."target")
					end
					
					if UnitExists(unitID.."pet") then
						if CheckUnitIDForMatchingHP(unitID.."pet", frameName, current, max) then
							table_insert(possibleUnits, #possibleUnits+1, unitID.."pettarget")
						end
					end
					
				end
				
				if #possibleUnits == 1 then
	-- ~ 				debugPrint("OnNameplateShow","Found nameplate HP match", self:GetName(frame), UnitName(possibleUnits[1]))
					FoundPlateGUID(frame, UnitGUID(possibleUnits[1]), possibleUnits[1])
					return true
				end
			
			end
		end
	end

	lib.prevHealth = lib.prevHealth or {}
	
	local plate
	local currentHP
	local plateName
	-------------------------------------------------------------------------------------- 
	function lib:healthOnValueChanged(bar, ...)										-- 
	-- This fires before OnShow fires and the regions haven't been updated yet. 		-- 
	-- So I make sure lib.isOnScreen[plate] is true before working on the HP change.	-- 
	-------------------------------------------------------------------------------------- 
		plate = bar:GetParent()
		currentHP = ...
		
		-- strange, when a nameplate's not on screen, we still get HP changes. It's not relyable but might be of use somehow...
		if plate and self.isOnScreen[plate] and (not self.prevHealth[plate] or self.prevHealth[plate] ~= currentHP) then
-- ~ 			debugPrint("healthOnValueChanged",self:GetName(plate), currentHP)
			self.callbacks:Fire(callbackHealthChanged, plate, ...)
			if not self.plateGUIDs[plate] then
				self:NewNameplateCheckHP(plate, ...)
			end
			self.prevHealth[plate] = currentHP
		end
	end
end
	

	

do
	local function ourOnShow(...)	lib:NameplateOnShow(...)	end
-- ~ 	local function ourOnUpdate(...)	lib:NameplateOnUpdate(...)	end
	local function ourOnHide(...)	lib:NameplateOnHide(...) 	end
-- ~ 	local function ourSetAlpha(...)	lib:NameplateSetAlpha(...) 	end
	local function ourHealthOnValueChanged(...) return lib:healthOnValueChanged(...) end
	local function onFinishFastAnimation(animation) lib:NameplateFastAnimation(animation.frame) end
	local function onFinishSlowAnimation(animation) lib:NameplateSlowAnimation(animation.frame) end
	
	
	lib.onHideHooks = lib.onHideHooks or {}
	lib.onShowHooks = lib.onShowHooks or {}
-- ~ 	lib.onUpdateHooks = lib.onUpdateHooks or {}
-- ~ 	lib.setAlphaHooks = lib.setAlphaHooks or {}
	lib.healthOnValueChangedHooks = lib.healthOnValueChangedHooks or {}
	lib.onFinishedGroups = lib.onFinishedGroups or {}
	
	local healthBar
	local group, animation
	
	local aFrame = CreateFrame("Frame")
	
	function lib:HookNameplate(frame)
		if frame:HasScript("OnHide") and not self.onHideHooks[frame] then
			self.onHideHooks[frame] = true
			frame:HookScript("OnHide", ourOnHide)
		end
		
		if frame:HasScript("OnShow") and not self.onShowHooks[frame] then
			self.onShowHooks[frame] = true
			frame:HookScript("OnShow", ourOnShow)
		end
	
		--[[if frame:HasScript("OnUpdate") and not self.onUpdateHooks[frame] then
			self.onUpdateHooks[frame] = true
			frame:HookScript("OnUpdate", ourOnUpdate)
		end]]
		
		
		if not self.onFinishedGroups[frame] then
			self.onFinishedGroups[frame] = self.onFinishedGroups[frame] or {}
			--[[*********]]
			group = aFrame:CreateAnimationGroup()
			group:SetLooping("REPEAT")
			animation = group:CreateAnimation("Animation")
			animation:SetDuration( fastOnFinishThrottle )
			animation:SetScript( "OnFinished", onFinishFastAnimation)
			animation.frame = frame
			table_insert(self.onFinishedGroups[frame], group)

			group = aFrame:CreateAnimationGroup()
			group:SetLooping("REPEAT")
			animation = group:CreateAnimation("Animation")
			animation:SetDuration( slowOnFinishThrottle )
			animation:SetScript( "OnFinished", onFinishSlowAnimation)
			animation.frame = frame
			table_insert(self.onFinishedGroups[frame], group)
		end
		
		
-- ~ 		if not self.setAlphaHooks[frame] then
-- ~ 			self.setAlphaHooks[frame] = true
-- ~ 			hooksecurefunc(frame, "SetAlpha", ourSetAlpha)
-- ~ 		end

		healthBar = self.plateChildren[frame].healthBar -- self.health_bar[frame]
		if healthBar and not self.healthOnValueChangedHooks[frame] then
			self.healthOnValueChangedHooks[frame] = true
			healthBar:HookScript("OnValueChanged", ourHealthOnValueChanged)
		end
	end
end





do 
	local tested = false
	function lib:NameplateFirstLoad(frame)
-- ~ 		debugPrint("NameplateFirstLoad", self:GetName(frame), self:GetLevel(frame))
		if not self.nameplates[frame] then
-- ~ 			debugPrint("NameplateFirstLoad", "x")
			self.nameplates[frame] = true
			self:HookNameplate(frame)
			self:SetupNameplate(frame)
			
-- ~ 			for a, b in pairs(frame) do 
-- ~ 				debugPrint("NameplateFirstLoad", a ,b)
-- ~ 			end
			
-- ~ 			debugPrint("NameplateFirstLoad", "SetAlpha", frame.SetAlpha)
			
		end
	end
end

--[[-------------------------------------------------------------------- 
------------------------------------------------------------------------ 
------------------------- API helpers ---------------------------------- 
------------------------------------------------------------------------ 
---------------------------------------------------------------------- ]]
do -- Cache region locations.
	lib.plateRegions = lib.plateRegions or setmetatable({}, {__index = function(t,frame)
		t[frame] = {
			nameText = lib:GetNameRegion(frame),
			levelText = lib:GetLevelRegion(frame),
			bossIcon = lib:GetBossRegion(frame),
			eliteIcon = lib:GetEliteRegion(frame),
			threatTexture = lib:GetThreatRegion(frame),
			highlightTexture = lib:GetHightlightRegion(frame),
			raidIcon =  lib:GetRaidIconRegion(frame),
		}
		return t[frame]
	end})
	
	lib.plateChildren = lib.plateChildren or setmetatable({}, {__index = function(t,frame)
		t[frame] = {
			healthBar = lib:GetHealthBar(frame),
			castBar = lib:GetCastBar(frame),
		}
		return t[frame]
	end})
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
local noColorText, noColorNum
do
	local input, find, inputString
	noColorText = setmetatable({}, {__index = function(t,inputString)
		if inputString  then
			if inputString:find("|c") then
				input = inputString
				find = inputString:find("|c")
				inputString = inputString:sub(find+10)
				inputString = inputString:gsub("|r", "")
				t[input] = inputString
-- ~ 				debugPrint("noColorText", input, inputString)
				return inputString
			end
			t[inputString] = inputString
		end
		return inputString or "UNKNOWN"
	end})

	noColorNum = setmetatable({}, {__index = function(t,inputString)
		if inputString then
			if inputString:find("|c") then
				input = inputString
				find = inputString:find("|c")
				inputString = inputString:sub(find+10)
				inputString = inputString:gsub("|r", "")
				inputString = tonumber(inputString or 0)
				t[input] = inputString
-- ~ 				debugPrint("noColorNum", input, inputString)
				return inputString
			end
			t[inputString] = tonumber(inputString or 0)
		end
		return inputString or 0
	end})
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
local threatByColor
do
    local redCan, greenCan, blueCan, alphaCan
    function threatByColor( region )
        if not region:IsShown() then return "LOW" end
  --[[      redCan, greenCan, blueCan, alphaCan = region:GetVertexColor()
        if greenCan > .7 then return "MEDIUM" end
        if redCan > .7 then return "HIGH" end
		]]
		local red, green, blue = region:GetVertexColor()
		if red > 0 then
			if green > 0 then
				if blue > 0 then return "MEDIUM" end
				return "MEDIUM"
			end
			return "HIGH"
		end
		
    end
end

-------------------------------------------------------------------------------------------------------------------------------------------- 
local GetHealthBarColor
do
	local r, g, b
	local bar
	function GetHealthBarColor(frame)
		if frame.aloftData then
			return frame.aloftData.originalHealthBarR, frame.aloftData.originalHealthBarG, frame.aloftData.originalHealthBarB
		end
		
		if frame.originalR and frame.originalG and frame.originalB then
			 -- dNamePlates changes the color of the healthbar. r7 now saves the original colors. TY Dawn.
			return frame.originalR, frame.originalG, frame.originalB
		end
		
		bar = lib.plateChildren[frame].healthBar
		if bar and bar.GetStatusBarColor then
			return bar:GetStatusBarColor()
		end
		return nil
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 

local function reactionByColor(red, green, blue, a)
	if red < .01 then 	-- Friendly
		if blue < .01 and green > .99 then return "FRIENDLY", "NPC"
		elseif blue > .99 and green < .01 then return "FRIENDLY", "PLAYER"
		end
	elseif red > .99 then
		if blue < .01 and green > .99 then return "NEUTRAL", "NPC"
		elseif blue < .01 and green < .01 then return "HOSTILE", "NPC"
		end
	elseif red > .5 and red < .6 then
		if green > .5 and green < .6 and blue > .5 and blue < .6 then return "TAPPED", "NPC" end 	-- .533, .533, .99	-- Tapped Mob
	end
	return "HOSTILE", "PLAYER"
end



-------------------------------------------------------------------------------------------------------------------------------------------- 
local function combatByColor(r, g, b, a) 
	return (r > .5 and g < .5)
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do 
	local f = CreateFrame("Frame")
	f:Hide()
	f:RegisterEvent("PLAYER_TARGET_CHANGED") 
	f:RegisterEvent("UPDATE_MOUSEOVER_UNIT")
	f:RegisterEvent("RAID_TARGET_UPDATE")
	
	local i
	local mouseoverPlate
	local raidNum
	f:SetScript("OnEvent", function(this, event, ...)
		if event == "PLAYER_TARGET_CHANGED" then
			if UnitExists("target") then
				this:Show()
			end
		elseif event == "UPDATE_MOUSEOVER_UNIT" then
			if GetMouseFocus() and GetMouseFocus():GetName() == "WorldFrame" then
				i = 0
				for frame in pairs(lib.nameplates) do
					if frame:IsShown() and lib:IsMouseover(frame) then
						i = i + 1
						mouseoverPlate = frame
					end
				end
			
				if i == 1 then
					if not lib.plateGUIDs[mouseoverPlate] then
-- ~ 						GetMouseoverGUID(mouseoverPlate)
						FoundPlateGUID(mouseoverPlate, UnitGUID("mouseover"), "mouseover")
-- ~ 						debugPrint("mouseover",mouseoverPlate,lib:GetName(mouseoverPlate))
					end
					lib.callbacks:Fire(callbackMouseoverNameplate, lib.fakePlate[mouseoverPlate] or mouseoverPlate)
				elseif i > 1 then
					debugPrint(i.." mouseover frames")
				end
			end
		elseif event == "RAID_TARGET_UPDATE" then
-- ~ 			debugPrint(event, ...)
			for frame in pairs(lib.nameplates) do 
				if frame:IsShown() and not lib.plateGUIDs[frame] and lib:IsMarked(frame) then
					raidNum = lib:GetRaidIcon(frame)
					if raidNum and raidNum > 0 then
						FindGUIDByRaidIcon(frame, raidNum, event)
					end
				end
			end
		end
	end)
	local unitID = "target"
	f:SetScript("OnUpdate", function(this, elapsed)
-- ~ 		debugPrint("TargetChanged A")
		for frame in pairs(lib.nameplates) do
		--	print("Step A", frame:GetName(), frame:IsShown(), lib.ElvPlate[frame], ElvUI[1].NamePlates.CreatedPlates[frame])
			if frame:IsShown() and lib:IsTarget(frame) then
		--		print("Step B", frame:GetName(), frame:IsShown(), lib.ElvPlate[frame], ElvUI[1].NamePlates.CreatedPlates[frame])
				
				lib.callbacks:Fire(callbackOnTarget, lib.fakePlate[frame] or frame)
				if not lib.plateGUIDs[frame] then
		--			print("Step C", frame:GetName(), frame:IsShown(), lib.ElvPlate[frame], ElvUI[1].NamePlates.CreatedPlates[frame])
					FoundPlateGUID(frame, UnitGUID(unitID), unitID)
				end
				break
			end
		end
		
		this:Hide()
	end)
end

do 
	local throttle = 1 -- Fire our fix hooks every second.

	local function onFinished(animation)

		for frame, value in pairs(lib.isOnScreen) do 
-- ~ 			debugPrint("onFinished", frame, value, frame:IsShown())
			if (value == true and not frame:IsShown()) then -- OnHide fail
-- ~ 				debugPrint("OnHide fail", frame, value, frame:IsShown())
				lib.onHideHooks[frame] = false
				lib.isOnScreen[frame] = false
				lib:NameplateOnHide(frame)
				lib:HookNameplate(frame)
				
			elseif (value == false and frame:IsShown()) then -- OnShow fail
				debugPrint("OnShow fail", frame, value, frame:IsShown())
				lib.onShowHooks[frame] = false
				lib.isOnScreen[frame] = false
				lib:HookNameplate(frame)
				lib:SetupNameplate(frame, true)
				
			end
		end
		
		--[[
		for frame, value in pairs(lib.isOnUpdating) do 
			if value == false and frame:IsShown() then
				debugPrint("OnUpdate fail?")
				lib.onUpdateHooks[frame] = false
				lib:HookNameplate(frame)
			end
		end]]
	end

-- ~ 	local frame = CreateFrame( "Frame" );
	if not lib.fixHooks then
		lib.fixHooks = CreateFrame("Frame")
		lib.fixHooks.animGroup = lib.fixHooks:CreateAnimationGroup(  );--"TimerAnimGroup"
		lib.fixHooks.anim = lib.fixHooks.animGroup:CreateAnimation( "Animation" ); --, "TimerAnim"
		lib.fixHooks.anim:SetDuration( throttle );
		lib.fixHooks.anim:SetScript( "OnFinished", onFinished );
		lib.fixHooks.animGroup:SetLooping( "REPEAT" );
		lib.fixHooks.animGroup:Play();
	end
	

	

	
end

--[[-------------------------------------------------------------------- 
------------------------------------------------------------------------ 
------------------------- API ------------------------------------------ 
------------------------------------------------------------------------ 
---------------------------------------------------------------------- ]]

do -- Get plate regions
	local region
	
	function lib:GetNameRegion(frame)
		if frame.extended and frame.extended.regions and frame.extended.regions.name then -- TidyPlates
			return frame.extended.regions.name
		elseif frame.aloftData and frame.aloftData.nameTextRegion then -- Aloft
			return frame.aloftData.nameTextRegion
		elseif frame.oldname then -- dNameplates
			return frame.oldname
		elseif frame.name then -- Elv
			return frame.name
		end
		region = (select(2, frame:GetChildren())):GetRegions()
		return region
	end
	
	function lib:GetLevelRegion(frame)
		if frame.extended and frame.extended.regions and frame.extended.regions.level then-- TidyPlates
			return frame.extended.regions.level
		elseif frame.aloftData and frame.aloftData.levelTextRegion then -- Aloft
			return frame.aloftData.levelTextRegion
		elseif frame.level then -- dNameplates
			return frame.level
		end
		region = select(regionIndex.levelText, (frame:GetChildren()):GetRegions())
		return region
	end
	
	function lib:GetBossRegion(frame)
		if frame.extended and frame.extended.regions and frame.extended.regions.dangerskull then -- tidyPlates
			return frame.extended.regions.dangerskull
		elseif frame.aloftData and frame.aloftData.bossIconRegion then -- aloft
			return frame.aloftData.bossIconRegion
		elseif frame.boss then -- dNameplates
			return frame.boss
		elseif frame.bossIcon then -- Elv
			return frame.bossIcon
		end
		region = select(regionIndex.skullIcon, (frame:GetChildren()):GetRegions())
		return region
	end
	
	function lib:GetEliteRegion(frame)
		if frame.extended and frame.extended.regions and frame.extended.regions.eliteicon then -- tidyPlates
			return frame.extended.regions.eliteicon
		elseif frame.aloftData and frame.aloftData.stateIconRegion then -- aloft
			return frame.aloftData.stateIconRegion
		elseif frame.elite then -- dNameplates
			return frame.elite
		elseif frame.eliteIcon then -- Elv
			return frame.eliteIcon
		end
		return  select(regionIndex.eliteIcon, (frame:GetChildren()):GetRegions())
	end
	
	function lib:GetThreatRegion(frame)
		if frame.extended and frame.extended.regions and frame.extended.regions.threatGlow then
			return frame.extended.regions.threatGlow
		elseif frame.aloftData and frame.aloftData.nativeGlowRegion then
			return frame.aloftData.nativeGlowRegion
		elseif frame.oldglow then -- dNameplates
			return frame.oldglow
		elseif frame.threat then -- Elv
			return frame.threat
		end
		region = select(regionIndex.threatTexture, (frame:GetChildren()):GetRegions() )
		return region
	end
	
	function lib:GetHightlightRegion(frame)
		if frame.extended then
			if frame.extended.regions then
				if frame.extended.regions.highlight then
					return frame.extended.regions.highlight
				elseif frame.extended.regions.highlightTexture then -- old tidyplates
					return frame.extended.regions.highlightTexture
				end
			end
		elseif frame.aloftData and frame.aloftData.highlightRegion then
			return frame.aloftData.highlightRegion
		elseif frame.highlight then -- dNameplates
			return frame.highlight
		end
		region = select(regionIndex.highlightTexture, (frame:GetChildren()):GetRegions())
		return region
	end
	
	function lib:GetRaidIconRegion(frame)
		if frame.extended and frame.extended.regions and frame.extended.regions.raidicon then
			return frame.extended.regions.raidicon
		elseif frame.aloftData and frame.aloftData.raidIconRegion then
			return frame.aloftData.raidIconRegion
		elseif frame.raidIcon then
			return frame.raidIcon
		end
		region = select(regionIndex.raidIcon, (frame:GetChildren()):GetRegions())
		return region
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do
	function lib:IsTarget(frame)
		frame = self.realPlate[frame] or frame

		return frame:IsShown() and frame:GetAlpha() == 1 and UnitExists("target") or false
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- Get plate children
	local healthBar
	function lib:GetHealthBar(frame)
		if frame.extended and frame.extended.bars and frame.extended.bars.health then
			return frame.extended.bars.health
	-- ~ 	elseif frame.aloftData then
			-- Aloft changes the bar color. Our functions will have to use aloftData.originalHealthBarR
		elseif frame.healthOriginal then -- dNameplates
			return frame.healthOriginal
		elseif frame.healthBar then -- dNameplates
			return frame.healthBar			
		end
		healthBar = select(childIndex.healthBar, (frame:GetChildren()):GetChildren())
		return healthBar
	end

	local castBar
	function lib:GetCastBar(frame)
		if frame.extended and frame.extended.bars and frame.extended.bars.castbar then
			return frame.extended.bars.castbar
		elseif frame.aloftData and frame.aloftData.castBar then
			return frame.aloftData.castBar
		elseif frame.castBar then
			return frame.castBar
		end
		castBar = select(childIndex.castBar, (frame:GetChildren()):GetChildren())
		return castBar
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- nameText
	local frame, region
	function lib:GetName(frame)
		frame = self.realPlate[frame] or frame
		region = self.plateRegions[frame].nameText
		if region and region.GetText then
			return noColorText[ region:GetText() ]
		end
		return nil
	end
	
	function lib:IsInCombat(frame)
		frame = self.realPlate[frame] or frame
	
		region = self.plateRegions[frame].nameText -- self.name_region[frame] 
		if region and region.GetTextColor then
			return combatByColor( region:GetTextColor() ) and true or false
		end
		
		return nil
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- levelText
	local frame, region
	function lib:GetLevel(frame)
		frame = self.realPlate[frame] or frame
		region = self.plateRegions[frame].levelText
		if region and region.GetText then
			return noColorNum[ region:GetText() ]
		end
		return 0
	end
	
	local greenRange = 5 -- GetQuestGreenRange()
	local pLevel, levelDiff
	function lib:GetLevelDifficulty(frame)
		pLevel = self:GetLevel(frame)
		levelDiff = pLevel - UnitLevel("player")
		if ( levelDiff >= 5 ) then
			return "impossible"
		elseif ( levelDiff >= 3 ) then
			return "verydifficult"
		elseif ( levelDiff >= -2 ) then
			return "difficult"
		elseif ( -levelDiff <= greenRange ) then
			return "standard"
		else
			return "trivial"
		end
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- bossIcon
	local region

	function lib:IsBoss(frame)
		frame = self.realPlate[frame] or frame
		region = self.plateRegions[frame].bossIcon
		if region and region.IsShown then
			return region:IsShown() and true or false
		end
		return false
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do	-- eliteIcon
	local region

	function lib:IsElite(frame)
		frame = self.realPlate[frame] or frame
		region = self.plateRegions[frame].eliteIcon
		if region and region.IsShown then
			return region:IsShown() and true or false
		end
		return false
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do	-- threatTexture
	local region

	function lib:GetThreatSituation(frame)
		frame = self.realPlate[frame] or frame
	
		region = self.plateRegions[frame].threatTexture
		if region and region.GetVertexColor then
			return threatByColor(region)
		end
		return nil
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- highlightTexture
	local region

	function lib:IsMouseover(frame)
		frame = self.realPlate[frame] or frame
		region = self.plateRegions[frame].highlightTexture
		if region and region.IsShown then
			return region:IsShown() and true or false
		end
		return nil
	end
	
	------------------------------------------------------------------------------------------------------------------ 
	function lib:HideMouseoverRegion(frame)																		-- 
	-- If we move the camera angle while the mouse is over a plate, that plate won't hide the mouseover texture.	-- 
	-- So if we're mousing over someone's feet and a plate has the mouseover texture visible, 						-- 
	-- it fools our code into thinking we're mousing over that plate.												-- 
	-- This can be recreated by placing the mouse over a nameplate then holding rightclick and moving the camera.	-- 
	-- If our UpdateNameplateInfo sees the mouseover texture still visible when we have no mouseoverID, it'll call	-- 
	-- this function to hide the texture.																			-- 
	------------------------------------------------------------------------------------------------------------------ 
		region = self.plateRegions[frame].highlightTexture
		if region and region.Hide then
			region:Hide()
		end
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- raidIcon
-- ~ 	local select = select
	local region

	local raidIconTexCoord = {-- from GetTexCoord. input is ULx and ULy (first 2 values).
		[0]		= {
			[0]		= 1, -- star 
			[0.25]	= 5, -- moon
		},
		[0.25]	= {
			[0]		= 2, -- circle 
			[0.25]	= 6, -- square
		},
		[0.5]	= {
			[0]		= 3, -- star 
			[0.25]	= 7, -- cross
		},
		[0.75]	= {
			[0]		= 4, -- star 
			[0.25]	= 8, -- skull
		},
	}

	local ULx,ULy
	function lib:GetRaidIcon(frame)
		frame = self.realPlate[frame] or frame
	
		region = self.plateRegions[frame].raidIcon
		if region and region.IsShown and region:IsShown() and region.GetTexCoord then
			ULx,ULy = region:GetTexCoord() --,LLx,LLy,URx,URy,LRx,LRy
			
			if ULx and ULy then
				return raidIconTexCoord[ULx] and raidIconTexCoord[ULx][ULy] or 0
			end
		end
		
		return nil
	end
	
	function lib:IsMarked(frame)
		frame = self.realPlate[frame] or frame
	
		region = self.plateRegions[frame].raidIcon 
		if region and region.IsShown then
			return region:IsShown() and true or false
		end
	
		return nil
	end
end

-- self.plateChildren[frame].healthBar castBar
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- castBar
	local bar
	function lib:IsCasting(frame)
		frame = self.realPlate[frame] or frame
		bar = self.plateChildren[frame].castBar
		if bar and bar.IsShown then
			return bar:IsShown() and true or false
		end
		return nil
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- Health bar colors.
	local r, g, b
	function lib:GetType(frame)
		frame = self.realPlate[frame] or frame
		r,g,b = GetHealthBarColor(frame)
		if r then
			return select(2, reactionByColor( r, g, b ) )
		end
		return nil
	end

	function lib:GetReaction(frame)
		frame = self.realPlate[frame] or frame
		r,g,b = GetHealthBarColor(frame)
		if r then
			return reactionByColor(r, g, b )
		end
		return nil
	end
	
	local colorToClass = {}
	local function pctToInt(number) return math_floor((100*number) + 0.5) end
	for classname, color in pairs(RAID_CLASS_COLORS) do
		colorToClass["C"..pctToInt(color.r)+pctToInt(color.g)+pctToInt(color.b)] = classname
	end
	
	function lib:GetClass(frame)
		frame = self.realPlate[frame] or frame
		r, g, b = GetHealthBarColor(frame)
		if r then
			return colorToClass["C"..pctToInt(r)+pctToInt(g)+pctToInt(b)] or nil
		end
		return nil
	end
end
-------------------------------------------------------------------------------------------------------------------------------------------- 
do -- healthBar
	local bar
	function lib:GetHealthMax(frame)
		frame = self.realPlate[frame] or frame
	
		bar = self.plateChildren[frame].healthBar
		if bar and bar.GetMinMaxValues then
			local _, max = bar:GetMinMaxValues()
			return tonumber(max or 0)
		end
		return nil
	end
	
	function lib:GetHealth(frame)
		frame = self.realPlate[frame] or frame
	
		bar = self.plateChildren[frame].healthBar
		if bar and bar.GetValue then
			return bar:GetValue()
		end
		return nil
	end
end

-------------------------------------------------------------------------------------------------------------------------------------------- 
--------- GUID
-------------------------------------------------------------------------------------------------------------------------------------------- 

function lib:GetGUID(frame)
	frame = self.realPlate[frame] or frame
	return self.plateGUIDs[frame]
end

do
	function lib:GetTargetNameplate()
		if UnitExists("target") then
			for frame in pairs(self.nameplates) do 
				if frame:IsShown() and frame:GetAlpha() == 1 then
					return self.fakePlate[frame] or frame
				end
			end
		end
		return nil
	end
end

do
	function lib:GetNameplateByGUID(GUID)
		for frame, fGUID in pairs(self.plateGUIDs) do 
			if fGUID == GUID then
-- ~ 				return frame
				return self.fakePlate[frame] or frame
			end
		end
		return nil
	end
end

do 
	local _
	local bar, barMax
	function lib:GetNameplateByName(name, maxHp)
		for frame in pairs(self.nameplates) do 
			if frame:IsShown() then
				if name == lib:GetName(frame) or name == gsub(lib:GetName(frame), '%s%(%*%)','') then
				--	print(name, lib:GetName(frame), name == lib:GetName(frame), name == gsub(lib:GetName(frame), '%s%(%*%)',''))
					if not maxHp then
						return self.fakePlate[frame] or frame
					end
					bar = self.plateChildren[frame].healthBar
					if bar and bar.GetMinMaxValues then
						_, barMax = bar:GetMinMaxValues()
						if barMax == maxHp then
							return self.fakePlate[frame] or frame
						end
					end
				end
			end
		end
	end
end

do
	local GUID
	local health
	local maxHealth
	local frame
	function lib:GetNameplateByUnit(unitID)
		if UnitIsUnit(unitID, "target") then
			return self:GetTargetNameplate()
		end
		frame = self:GetNameplateByGUID(UnitGUID(unitID))
		if frame then
			return frame
		end
		return self:GetNameplateByName(UnitName(unitID), UnitHealthMax(unitID))
	end
end

do 
	local frames = {}
	function lib:GetAllNameplates()
		wipe(frames)
		for frame in pairs(self.nameplates) do 
			table_insert(frames, self.fakePlate[frame] or frame)
		end
		return unpack(frames)
	end
	
	function lib:IteratePlates()
		wipe(frames)
		for frame in pairs(self.nameplates) do 
			table_insert(frames, self.fakePlate[frame] or frame)
		end
		return pairs(frames)
	end
end

do 
	local possibleFrames = {}
	local bar, barMax, barCurrent,_
	function lib:GetNameplateByHealth(current, max)
		wipe(possibleFrames)
		
		for frame in pairs(self.nameplates) do 
			if frame:IsShown() then
				bar = self.plateChildren[frame].healthBar -- self.health_bar[frame]
	
				if bar and bar.GetMinMaxValues then
					_, barMax = bar:GetMinMaxValues()
					if barMax == max then
						if bar:GetValue() == current then
							table_insert(possibleFrames, #possibleFrames+1, frame)
						end
					end
				
				end
				
	-- ~ 			table_insert(frames, #frames+1, self.fakePlate[frame] or frame)
			end
		end

	-- ~ 	debugPrint("GetNameplateByHealth C", #possibleFrames)
		
		if #possibleFrames == 1 then
			return self.fakePlate[possibleFrames[1]] or possibleFrames[1] -- possibleFrames[1]
		end
		return nil
	end
end
