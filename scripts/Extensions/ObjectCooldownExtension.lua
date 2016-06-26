local cooldowns = {};

function Player:SetLuaCooldown(seconds, opt_id)
	assert(type(self) == "userdata");
	seconds = assert(tonumber(seconds));
	opt_id = opt_id or 1;
	local guid, source = self:GetGUIDLow(), debug.getinfo(2, 'S').short_src;

	if (not cooldowns[guid]) then
		cooldowns[guid] = { [source] = {}; };
	end

	cooldowns[guid][source][opt_id] = os.clock() + seconds;
end

function Player:GetLuaCooldown(opt_id)
	assert(type(self) == "userdata");
	local guid, source = self:GetGUIDLow(), debug.getinfo(2, 'S').short_src;
	opt_id = opt_id or 1;

	if (not cooldowns[guid]) then
		cooldowns[guid] = { [source] = {}; };
	end

	local cd = cooldowns[guid][source][opt_id];
	if (not cd or cd < os.clock()) then
		cooldowns[guid][source][opt_id] = 0
		return 0;
	else
		return cooldowns[guid][source][opt_id] - os.clock();
	end
end

--[[ Example:
	if(player:GetLuaCooldown() == 0) then -- Check if cooldown is present
		player:SetLuaCooldown(30)
		print("Cooldown is set to 30 seconds")
	else
		print("There are still "..player:GetLuaCooldown().." seconds remaining of your cooldown!")
	end
]]