--[[
Author : Jafferwaffer
Core : Trinity Core with Eluna 3.3.5a (Latest Rev)
Script name : GroupCmds
Huge thanks to the Emu Devs, especially Rochet2 for great support!
Please ask if you wish to repost by PM on emudevs.com
Also PM with any bugs.
Thank you, enjoy!
]]

local GroupSummon = "gsummon" -- .gsummon
local GroupAppear = "gappear" -- .gappear
local GroupHelp = "ghelp" -- .ghelp

--Getting position
local function getMapDetails(player)
	return player:GetLocation();
end
local function getZoneId(player)
	return player:GetZoneId();
end
local function getMapId(player)
	return player:GetMapId();
end

--Checking if player and target are in the same group
--Returns true if they are false otherwise.
local function checkForGroup(player,target)
	if(player:IsInGroup()) then
			local group = player:GetGroup();
			local tarGUID = target:GetGUID();
		if	(group:IsMember(tarGUID)) then
			return true;
		else
			return false;
		end	
	else
		return false;
	end	
end

--Handle .gappear command
local function CmdAppear(player, target)
	if (target:IsAlive()) then
		local x, y, z, o = getMapDetails(target);
		player:Teleport(getMapId(target), x, y, z, o);
		player:SendBroadcastMessage("Appearing at "..target:GetName().."'s location.");
	else
		player:SendBroadcastMessage("Your target must be alive to appear them");
	end
end

--Handle .gsummon command
local function CmdSummon(player, target)
	local x, y, z, o = getMapDetails(player);
	player:SummonPlayer(target, getMapId(player), x, y, z, getZoneId(player));
	player:SendBroadcastMessage("Summoning "..target:GetName().." to your location.");
end

--Handle .gsummon all command
local function CmdSummon_all(player)
	if(player:IsInGroup()) then
		--Get map details for the summoning player
		local x, y, z, o = getMapDetails(player);
		local plrMapId = getMapId(player);
		local plrZoneId = getZoneId(player);
		--Get the group & each member in group of the player
		local playerGroup = player:GetGroup();
		local groupPlayers = playerGroup:GetMembers();
		player:SendBroadcastMessage("Summoning group to your location");
		for i,v in ipairs(groupPlayers) do
			if(v ~= player) then
				player:SummonPlayer(v, plrMapId, x, y, z, plrZoneId);
			end
		end
	else
		player:SendBroadcastMessage("You must be in a group.");
	end	
end
--Handle #help command
local function CmdHelp(player)
	player:SendBroadcastMessage("The following commands are available to you when you're in a group : ");
	player:SendBroadcastMessage(".gappear ~ Syntax : .gappear [Player Name] ~ appear at target location");
	player:SendBroadcastMessage(".gsummon ~ Syntax : .gsummon [Player Name] ~ summon target to your location");
	player:SendBroadcastMessage(".gsummon all ~ Will summon all group members to your location.");
	player:SendBroadcastMessage(".ghelp ~ Show this help text");
end

--Gets the player's target: Either their selection or through text.
--Selection has priority over text.
local function GetTarget(player, msg, lang)
	if (player:GetSelection() ~= nil) then
		local target = player:GetSelection();
		return target;
	elseif (string.len(msg) > 8) then
		local playerName = string.match(msg,"%s(.-)%s*$"); --Match with any text after fisrt space, and trim first space.
		if (playerName == "all") then
			return playerName
		else	
			local target = GetPlayerByName(playerName);
			--print(playerName); Used for Debug
			--print(target);
			return target;
		end	
	else
		player:SendBroadcastMessage("You must have a target");
		--print("Fail"); --Debug
		return nil;
	end	
end	

--Handles player event.
local function CmdAction(event, player, msg, lang)
	if	(msg:find(GroupSummon) == 1) then --If typed .gsummon
		local target = GetTarget(player, msg, lang); --Returns Player Obj or string "all"
		if(target == "all") then
			CmdSummon_all(player);
			return false;
		else	
			if(target ~= nil) then --Check for target
				if (checkForGroup(player, target)) then --Check for group
					CmdSummon(player, target);
					return false;
				else
					player:SendBroadcastMessage("The target must be in your group!");
					return false;
				end
			else
				return false;
			end
		end	
	elseif(msg:find(GroupAppear) == 1) then --If typed .gappear
		local target = GetTarget(player, msg, lang); --Returns Player Obj
		if(target ~= nil) then --Check for target
			if (checkForGroup(player, target)) then
				CmdAppear(player, target);
				return false;
			else
				player:SendBroadcastMessage("The target must be in your group!");
				return false;
			end
		else
			return false;
		end	
	elseif(msg:find(GroupHelp) == 1) then
		CmdHelp(player);
		return false;
	end		

end

RegisterPlayerEvent(42, CmdAction) --Upon player use command check for prefix