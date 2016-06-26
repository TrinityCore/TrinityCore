--[[
For Trinity Core2 Eluna
by slp13at420 of EmuDevs
Gives new characters (class based) gear on first time login.
just edit the entries with real item id's. add more ore take some away .. its dynamic .. it WILL adapt.
]]--
local StartGear = {
		[1] = {20558, 456, 789, 147, 258, 369}, -- Warrior
		[2] = {123, 456, 789, 147, 258, 369}, -- Paladin
		[3] = {123, 456, 789, 147, 258, 369}, -- Hunter
		[4] = {123, 456, 789, 147, 258, 369}, -- Rogue
		[5] = {123, 456, 789, 147, 258, 369}, -- Priest
		[6] = {123, 456, 789, 147, 258, 369}, -- Death Knight
		[7] = {123, 456, 789, 147, 258, 369}, -- Shaman
		[8] = {123, 456, 789, 147, 258, 369}, -- Mage
		[9] = {123, 456, 789, 147, 258, 369}, -- Warlock
		[10] = {}, -- class 10 is nil non-existing
		[11] = {123, 456, 789, 147, 258, 369}; -- Druid
					};

function Class_Gear(event, player)
	for _, v in ipairs(StartGear[player:GetClass()]) do
		if((player:GetItemCount(v)) == (0 or nil))then
			player:AddItem(v, 1)
		end
	end
end
		
RegisterPlayerEvent(30, Class_Gear) -- event 30 == on first login.