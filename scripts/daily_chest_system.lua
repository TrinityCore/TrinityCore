-- Name: 	Daily Chest System
-- Details:	Limits the amount of time between the same chest being opened by the same player.
-- Usage:	Modify the configuration below to suit your needs.
-- Website: https://github.com/RStijn

-- Init
local CHEST = {} 

-- Config
-- set chest gameobject ID's at bottom
local HOURS = 24 			-- How many hours before a player can loot again 
local ACCOUNTLIMIT = true 	-- TRUE: Limits entire account. FALSE: Limits only this character
-- Message to show when player already looted a chest recently
local ALREADYLOOTED = "You already looted this chest. Please check back within 24 hours."
-- GameObject ID's you want to limit per player.
CHEST[1] = 500000
CHEST[2] = 500001
CHEST[3] = 500002


-- Functions
local function registerNewLoot(pid, goGuid)
	CharDBQuery("INSERT INTO `looted_chests` (`player`, `objectGuid`, `lootTime`) VALUES ('".. pid .. "', '" .. goGuid .. "', UNIX_TIMESTAMP());")
end

local function canLoot(pid, goGuid)
	local q = CharDBQuery("SELECT `id`, `lootTime` FROM `looted_chests` WHERE `player` = " .. pid .. " AND `objectGuid` = " .. goGuid .. ";")
	local now = tonumber(CharDBQuery("SELECT UNIX_TIMESTAMP()"):GetRow(1)["UNIX_TIMESTAMP()"])
	
	-- if possible
	if q == nil then
		return true
	elseif tonumber(q:GetRow(1)["lootTime"]) + (HOURS * 3600) < now then
		CharDBQuery("DELETE FROM `looted_chests` WHERE `id` = "..q:GetRow(1)["id"])
		return true
	else
		return false
	end
end

local function blockLoot(player, go)
	go:SetLootState(3)
	player:SendBroadcastMessage(ALREADYLOOTED);
end

local function handleLoot(player, go)
	-- Get ID's
	local pid = 0
	if ACCOUNTLIMIT then
		pid = player:GetAccountId()
	else
		pid = player:GetPlayerGUID()
	end	
	local goGuid = go:GetGUIDLow()
	
	-- Handle loot
	if canLoot(pid, goGuid) then
		registerNewLoot(pid, goGuid)
	else
		blockLoot(player, go)
	end
end

local function onLootStateChanged(event, go, state)
	if state == 2 then
		player = go:GetLootRecipient()
		handleLoot(player, go)
	end

end

-- Register chests
local i = 1
while CHEST[i] do
  RegisterGameObjectEvent(CHEST[i], 9, onLootStateChanged)
  i = i + 1
end

-- Create sql table if needed
CharDBQuery("CREATE TABLE IF NOT EXISTS `looted_chests` (`id` int(11) NOT NULL AUTO_INCREMENT, `player` int(11) NOT NULL, `objectGuid` int(11) NOT NULL, `lootTime` int(11) NOT NULL, PRIMARY KEY (`id`)) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;")
