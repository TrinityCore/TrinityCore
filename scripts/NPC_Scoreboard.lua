--[[

¦¦¦¦-=¬¦-=¬¦¦¦-=======T==¬-==¬
¦¦¦¦¦ ¦¦¦ ¦¦¦¦¦ -¬ -¬ ¦¬ L- --
¦¦¦¦¦ L=- ¦===+=¦¦ ¦L=-L¬  --
¦¦¦¦¦ -=¬ ¦¦ =+=¦¦ ¦¦¦¦--  L¬
¦¦¦¦¦ ¦¦¦ ¦¦ =¦ ¦¦ ¦¦¦-- -¬ L¬
¦¦¦¦L=-¦L=¦===¦=-L=-¦¦L==-L==-
¦¦¦¦¦¦¦¦¦¦¦¦¦-===¬¦¦¦¦¦¦¦¦¦-¬
¦¦¦¦¦¦¦¦¦¦¦¦¦¦-=¬¦¦¦¦¦¦¦¦¦--L¬
¦¦¦¦¦¦¦¦¦¦¦¦¦¦L==T==T=TT==+¬-+==¬
¦¦¦¦¦¦¦¦¦¦¦¦¦L==¬¦-=¦-+¦-¬¦¦¦¦==¦
¦¦¦¦¦¦¦¦¦¦¦¦¦¦L=-¦L=¦¦¦¦L-¦¦L+==¦
¦¦¦¦¦¦¦¦¦¦¦¦¦L===¦==¦-L¦-=-L=¦==-
¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦
¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦L-
		Scripts by Heitx may be edited,
			but all credits must be provided.

-==========================================T==========================================¬
¦            Script Information            ¦              Script Feature              ¦
¦==========================================+==========================================¦
¦- Written by: Heitx.                      ¦+ Lot of Customization,                   ¦
¦- Contributor(s): Rochet2.                ¦+ Disable any menu you want!              ¦
¦- Completion: 85 %                        ¦+ Unlimited amount of colors!             ¦
¦- Script Name: Scoreboard                 ¦+ Different sorting systems(not finished) ¦
¦- Description: Shows the top x players.   ¦+ Supports names with space(not confirmed)¦
¦ Also have the options to use my stats    ¦+ Different refresh methods!              ¦
¦ or a search filter.                      ¦                                          ¦
L==========================================¦==========================================-
--]]

--[[
-==========================================T==========================================¬
¦            Config Description            ¦             Config Variables             ¦
¦==========================================+==========================================¦
¦ -entryID: NPC / object entryID           ¦ Number -> 29093                          ¦
¦ -listAmount: The amount on the board     ¦ Number -> 5 (MAX 29/30)                  ¦
¦ -isObject: Object or NPC, your destiny!  ¦ Boolean -> (True or false)               ¦
¦ -reloadMessage: When reload menu clicked ¦ String -> 'Message'                      ¦
¦ -refresh: if manual or automatic         ¦ Boolean -> True automatic, false manual  ¦
¦ -titleIcons: Enables PvP Title icons     ¦ Boolean -> (True or false)               ¦
¦ -invalidSearch: if character dosn't exist¦ String -> 'Character was not found.'     ¦
¦ -orderList: Changes the toplist          ¦ String -> 'totalKills'                   ¦
L==========================================¦==========================================-
--]]

--[[
-==========================================¬
¦            [Message Features]            ¦
¦==========================================¦
¦ <C1> ...  : Colors!                      ¦
L==========================================-
--]]

local scriptActive 	= true

local entryID 		= 190051
local listAmount 	= 7

local isObject 		= false

local reloadMessage	= '<C1>Scoreboard Reloaded.'
local refresh  		= false
local refreshDelay	= 6000 -- In milliseconds (600 000 = 10 minutes)

local titleIcons	= true
local invaildSearch = '<C1>Character was not found.'

local orderList		= 'totalKills'

--[[ [1] = {String before the toplist (1. 2. 3.), color the names} : The rest makes sense. ]]
local mainmenu = {
	[1] = {'<C1>', '<C2>'},
	[2] = '<C3>My Stats',
	[3] = '<C3>Search Player',
	[4] = '<C6>Refresh Scoreboard' -- This can only be seen by GMs (.gm on)
}

--[[ To disable a menu comment it out : example below ]]
local menu = {
	--[1] 	= '<C4>Name: <C5>',
	[1] 	= '<C4>Name: <C5>',
	[2] 	= '<C4>Race: <C5>',
	[3] 	= '<C4>Class: <C5>',
	[4] 	= '<C4>Total Kills: <C5>',
	[5] 	= '<C4>PvP Rank: <C5>',
	[6] 	= '<C4>Guild: <C5>',
	[7] 	= '<C4>Rank: <C5>',
	[8] 	= '<C4>A-Team (2v2): <C5>',
	[9] 	= '<C4>A-Team (3v3): <C5>',
	[10] 	= '<C4>A-Team (5v5): <C5>',
	[11] 	= '<C4>A-Rating (2v2): <C5>',
	[12] 	= '<C4>A-Rating (3v3): <C5>',
	[13] 	= '<C4>A-Rating (5v5): <C5>',
	[14] 	= '<C4>Honor Points: <C5>',
	[15] 	= '<C4>Arena Points: <C5>',
	[16] 	= '<C4>Back'
}

--[[ 'HEXCODE' ]]
local colors = {
	'FFE0CC', -- C1
	'662900', -- C2
	'4D1F00',
	'413100',
	'555500',
	'3333FF'
}

--[[ { icon path, hk kills, alliance title, horde title } ]]
local titles = {
	{"|TInterface\\PvPRankBadges\\PvPRank01.png:20|t", 100, "Private", "Scout"},
	{"|TInterface\\PvPRankBadges\\PvPRank02.png:20|t", 300, "Corporal", "Grunt"},
	{"|TInterface\\PvPRankBadges\\PvPRank03.png:20|t", 1500, "Sergeant", "Sergeant"},
	{"|TInterface\\PvPRankBadges\\PvPRank04.png:20|t", 2000, "Master Sergeant", "Senior Sergeant"},
	{"|TInterface\\PvPRankBadges\\PvPRank05.png:20|t", 3000, "Sergeant Major", "First Sergeant"},
	{"|TInterface\\PvPRankBadges\\PvPRank06.png:20|t", 4000, "Knight", "Stone Guard"},
	{"|TInterface\\PvPRankBadges\\PvPRank07.png:20|t", 5000, "Knight-Lieutenant", "Blood Guard"},
	{"|TInterface\\PvPRankBadges\\PvPRank08.png:20|t", 6000, "Knight-Captain", "Legionnaire"},
	{"|TInterface\\PvPRankBadges\\PvPRank09.png:20|t", 7000, "Knight-Champion", "Centurion"},
	{"|TInterface\\PvPRankBadges\\PvPRank10.png:20|t", 8000, "Lieutenant Commander", "Champion"},
	{"|TInterface\\PvPRankBadges\\PvPRank11.png:20|t", 9000, "Commander", "Lieutenant General"},
	{"|TInterface\\PvPRankBadges\\PvPRank12.png:20|t", 10000, "Marshal", "General"},
	{"|TInterface\\PvPRankBadges\\PvPRank13.png:20|t", 11000, "Field Marshal", "Warlord"},
	{"|TInterface\\PvPRankBadges\\PvPRank14.png:20|t", 12000, "Grand Marshal", "High Warlord"}
}

local raceGroup = {
	[1] = 'Human',
	[2] = 'Orc',
	[3] = 'Dwarf',
	[4] = 'Night Elf',
	[5] = 'Undead',
	[6] = 'Tauren',
	[7] = 'Gnome',
	[8] = 'Troll',
	[9] = 'UNKNOWN SPECIE!',
	[10] = 'Blood Elf',
	[11] = 'Draenei',
}

local classGroup = {
	[1] = 'Warrior',
	[2] = 'Paladin',
	[3] = 'Hunter',
	[4] = 'Rogue',
	[5] = 'Priest',
	[6] = 'Death Knight',
	[7] = 'Shaman',
	[8] = 'Mage',
	[9] = 'Warlock',
	[10] = 'Monk', -- Released in MOP (Mist of Pandaria Expansion).
	[11] = 'Druid',
}

--[[ The section beneath this line is untouchable, 
		unless you know what you're doing! --]]

local sqlData = {}
local search = {}
local totalToplist = 0

local cf = {} -- custom function

local function Gossip_onTalk(event, player, gossip)
	if (search[player:GetGUIDLow()] == true) then search[player:GetGUIDLow()] = false end


	for i = 1, totalToplist do
		player:GossipMenuAddItem(9, cf.MessageFeatures(mainmenu[1][1]) .. i ..'. |r'.. cf.MessageFeatures(mainmenu[1][2]) .. sqlData[i]['NAME'] ..'|r', i, sqlData[i]['GUID'])
	end
	--]]

	
	player:GossipMenuAddItem(4, cf.MessageFeatures(mainmenu[2]), 0, 0)
	player:GossipMenuAddItem(4, cf.MessageFeatures(mainmenu[3]), 0, 0, 1) 
	if (player:IsGM()) then player:GossipMenuAddItem(4, cf.MessageFeatures(mainmenu[4]), 1, 0) end

	player:GossipSendMenu(1, gossip)
end

local function Gossip_onSelect(event, player, gossip, sender, intid, code)
	if (intid == 0) then
		if (search[player:GetGUIDLow()] == nil) then
			search[player:GetGUIDLow()] = false
		end

		if (sender == 0) then
			if (search[player:GetGUIDLow()] == false) then
				if not (cf.GetPlayerInformation( tostring(player:GetName()))) then player:SendBroadcastMessage(invaildSearch) return false end
			end

			if (code ~= nil) and (search[player:GetGUIDLow()] == false) then
				code = code:gsub("(%a)([%w_']*)", cf.TitleCase)
				if not (cf.GetPlayerInformation(code)) then player:SendAreaTriggerMessage(cf.MessageFeatures(invaildSearch)) return false end
				search[player:GetGUIDLow()] = true
			end
		elseif (sender == 1) then
			cf.ReloadScoreboard()
			Gossip_onTalk(event, player, gossip)
			player:SendAreaTriggerMessage(cf.MessageFeatures(reloadMessage))
			return false
		elseif (sender == 100) then
			Gossip_onTalk(event, player, gossip)
			return false
		end
	end

	---[[
	if (menu[1] ~= nil) then player:GossipMenuAddItem(0, cf.MessageFeatures(menu[1]) .. sqlData[sender]['NAME'] ..'|r', sender, intid) end
	if (menu[2] ~= nil) then player:GossipMenuAddItem(0, cf.MessageFeatures(menu[2]) .. cf.GetRaceAsStringById(sqlData[sender]['RACE']) ..'|r', sender, intid) end
	if (menu[3] ~= nil) then player:GossipMenuAddItem(0, cf.MessageFeatures(menu[3]) .. cf.GetClassAsStringById(sqlData[sender]['CLASS']) ..'|r', sender, intid) end
	if (menu[4] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[4]) .. sqlData[sender]['TKills'] ..'|r', sender, intid) end
	
	if (menu[5] ~= nil) then 
		local icon = ''
		for i, v in ipairs( titles ) do
			if ( sqlData[sender]['TKills'] >= v[2] ) then
				local pRace = sqlData[sender]['RACE']
				if (pRace == 1) or (pRace == 3) or (pRace == 4) or (pRace == 7) or (pRace == 11) then
					sqlData[sender]['PTitle'] = v[3]
				else
					sqlData[sender]['PTitle'] = v[4]
				end

				icon = v[1]
			end
		end

		if (titleIcons) then
			player:GossipMenuAddItem(9, icon .. cf.MessageFeatures(menu[5]) .. sqlData[sender]['PTitle'] ..'|r', sender, intid)
		else
			player:GossipMenuAddItem(9, cf.MessageFeatures(menu[5]) .. sqlData[sender]['PTitle'] ..'|r', sender, intid)
		end
	end

	if (menu[6] ~= nil) then player:GossipMenuAddItem(8, cf.MessageFeatures(menu[6]) .. sqlData[sender]['GName'] ..'|r', sender, intid) end
	if (menu[7] ~= nil) then player:GossipMenuAddItem(8, cf.MessageFeatures(menu[7]) .. sqlData[sender]['GRName'] ..'|r', sender, intid) end
	if (menu[8] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[8]) .. sqlData[sender]['ATEAM2'] ..'|r', sender, intid) end
	if (menu[9] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[9]) .. sqlData[sender]['ATEAM3'] ..'|r', sender, intid) end
	if (menu[10] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[10]) .. sqlData[sender]['ATEAM5'] ..'|r', sender, intid) end
	if (menu[11] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[11]) .. sqlData[sender]['ARATING2'] ..'|r', sender, intid) end
	if (menu[12] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[12]) .. sqlData[sender]['ARATING3'] ..'|r', sender, intid) end
	if (menu[13] ~= nil) then player:GossipMenuAddItem(9, cf.MessageFeatures(menu[13]) .. sqlData[sender]['ARATING5'] ..'|r', sender, intid) end
	if (menu[14] ~= nil) then player:GossipMenuAddItem(6, cf.MessageFeatures(menu[14]) .. sqlData[sender]['HPoints'] ..'|r', sender, intid) end
	if (menu[15] ~= nil) then player:GossipMenuAddItem(6, cf.MessageFeatures(menu[15]) .. sqlData[sender]['APoints'] ..'|r', sender, intid) end
	if (menu[16] ~= nil) then player:GossipMenuAddItem(5, cf.MessageFeatures(menu[16]) ..'|r', 100, 0) end
	--]]

	player:GossipSendMenu(1, gossip)
end

function cf.MessageFeatures(message)
	for i, v in ipairs(colors) do
		message = message:gsub("<C" .. i .. ">", '|cff' .. v)
	end

	return message
end

--[[ This function is found on 
		http://lua-users.org/wiki/StringRecipes ]]
function cf.TitleCase(first, rest)
	return first:upper() .. rest:lower()
end

function cf.GetRaceAsStringById(id)
	return raceGroup[id]
end

function cf.GetClassAsStringById(id)
	return classGroup[id]
end

function cf.ReloadScoreboard()
	-- [[ Character Database]]
	local sqlChar = 'SELECT guid, name, race, class, arenaPoints, totalHonorPoints, totalKills FROM characters ORDER BY '.. orderList ..' DESC LIMIT '.. listAmount 
	local sqlCharQuery = CharDBQuery(sqlChar)

	totalToplist = sqlCharQuery:GetRowCount()

	for i = 1, totalToplist do

		--[[ This is the default setting, if the 'stat' are not found
				This is for the toplist. The 'My Search' and 'Player Search' are on ~350 (line)
		]]
		if (sqlCharQuery) then
			sqlData[i] = {
				['GUID'] 		= sqlCharQuery:GetUInt32(0),
				['NAME'] 		= sqlCharQuery:GetString(1),
				['RACE'] 		= sqlCharQuery:GetUInt8(2),
				['CLASS'] 		= sqlCharQuery:GetUInt8(3),
				['APoints'] 	= sqlCharQuery:GetUInt32(4),
				['HPoints'] 	= sqlCharQuery:GetUInt32(5),
				['TKills'] 		= sqlCharQuery:GetUInt32(6),
				['PTitle'] 		= 'No Title',
				['GName'] 		= 'No Guild',
				['GRName'] 		= 'No Guild Rank',
				['ATEAM2'] 		= 'No Team',
				['ATEAM3'] 		= 'No Team',
				['ATEAM5'] 		= 'No Team',
				['ARATING2'] 	= 0,
				['ARATING3'] 	= 0,
				['ARATING5'] 	= 0,
			}

			--[[ Guild Databases ]]
			
			-- Guild Members -> Players guildid & rank
			local sqlGM = 'SELECT guildid, rank FROM guild_member WHERE guid = '.. sqlCharQuery:GetUInt32(0)
			local sqlGMQuery = CharDBQuery(sqlGM)

			if (sqlGMQuery) then
				-- Guild -> Guild name
				local sqlG = 'SELECT name FROM guild where guildid = '.. sqlGMQuery:GetUInt32(0)
				local sqlGQuery = CharDBQuery(sqlG)

				if (sqlGQuery) then

					sqlData[i]['GName'] = sqlGQuery:GetString(0)

					-- Guild Rank -> Rank Name
					local sqlGR = 'SELECT rname FROM guild_rank where guildid = '.. sqlGMQuery:GetUInt32(0) ..' AND rid = '.. sqlGMQuery:GetUInt8(1)
					local sqlGRQuery = CharDBQuery(sqlGR)

					if (sqlGRQuery) then
						sqlData[i]['GRName'] = sqlGRQuery:GetString(0)
					end
				end
			end

			--[[ Arena Databases ]]

			if (sqlCharQuery) then
				--Arena Team Member
				local sqlATM = 'SELECT arenaTeamId FROM arena_team_member WHERE guid = '.. sqlCharQuery:GetUInt32(0)
				local sqlATMQuery = CharDBQuery(sqlATM)

				if (sqlATMQuery) then
					for row = 1, sqlATMQuery:GetRowCount() do
						local sqlAT = 'SELECT name, type, rating TYPE FROM arena_team WHERE arenaTeamId = '.. sqlATMQuery:GetUInt32(0)
						local sqlATQuery = CharDBQuery(sqlAT)

						if (sqlATQuery) then
							sqlData[i]['ATEAM' .. sqlATQuery:GetUInt8(1)] = sqlATQuery:GetString(0)
						end

						if (sqlATQuery) then
							sqlData[i]['ARATING' .. sqlATQuery:GetUInt8(1)] = sqlATQuery:GetString(2)
						end
						
						if not ( sqlATMQuery:NextRow() ) then break end
					end
				end
			end

			if not ( sqlCharQuery:NextRow() ) then break end
		end
	end

	return true
end

function cf.GetPlayerInformation(playername)
	local sqlChar = 'SELECT guid, name, race, class, arenaPoints, totalHonorPoints, totalKills FROM characters WHERE name = "'.. playername ..'"'
	local sqlCharQuery = CharDBQuery(sqlChar)

	--[[ This is the default setting, if the 'stat' are not found
			This is for 'My Stats' & 'Player Search'.
	]]
	if (sqlCharQuery) then
		sqlData[0] = {
			['GUID'] = sqlCharQuery:GetUInt32(0),
			['NAME'] = sqlCharQuery:GetString(1),
			['RACE'] = sqlCharQuery:GetUInt8(2),
			['CLASS'] = sqlCharQuery:GetUInt8(3),
			['APoints'] = sqlCharQuery:GetUInt32(4),
			['HPoints'] = sqlCharQuery:GetUInt32(5),
			['TKills'] = sqlCharQuery:GetUInt32(6),
			['PTitle'] 		= 'No Title',
			['GName'] 		= 'No Guild',
			['GRName'] 		= 'No Guild Rank',
			['ATEAM2'] 		= 'No Team',
			['ATEAM3'] 		= 'No Team',
			['ATEAM5'] 		= 'No Team',
			['ARATING2'] 	= 0,
			['ARATING3'] 	= 0,
			['ARATING5'] 	= 0,
		}

		--[[ Guild Databases ]]
		
		-- Guild Members -> Players guildid & rank
		local sqlGM = 'SELECT guildid, rank FROM guild_member WHERE guid = '.. sqlCharQuery:GetUInt32(0)
		local sqlGMQuery = CharDBQuery(sqlGM)

		if (sqlGMQuery) then
			-- Guild -> Guild name
			local sqlG = 'SELECT name FROM guild where guildid = '.. sqlGMQuery:GetUInt32(0)
			local sqlGQuery = CharDBQuery(sqlG)

			if (sqlGQuery) then

				sqlData[0]['GName'] = sqlGQuery:GetString(0)

				-- Guild Rank -> Rank Name
				local sqlGR = 'SELECT rname FROM guild_rank where guildid = '.. sqlGMQuery:GetUInt32(0) ..' AND rid = '.. sqlGMQuery:GetUInt8(1)
				local sqlGRQuery = CharDBQuery(sqlGR)

				if (sqlGRQuery) then
					sqlData[0]['GRName'] = sqlGRQuery:GetString(0)
				end
			end
		end

		--[[ Arena Databases ]]

		if (sqlCharQuery) then
			--Arena Team Member
			local sqlATM = 'SELECT arenaTeamId FROM arena_team_member WHERE guid = '.. sqlCharQuery:GetUInt32(0)
			local sqlATMQuery = CharDBQuery(sqlATM)

			if (sqlATMQuery) then
				for row = 1, sqlATMQuery:GetRowCount() do
					local sqlAT = 'SELECT name, type, rating TYPE FROM arena_team WHERE arenaTeamId = '.. sqlATMQuery:GetUInt32(0)
					local sqlATQuery = CharDBQuery(sqlAT)

					if (sqlATQuery) then
						sqlData[0]['ATEAM' .. sqlATQuery:GetUInt8(1)] = sqlATQuery:GetString(0)
					end

					if (sqlATQuery) then
						sqlData[0]['ARATING' .. sqlATQuery:GetUInt8(1)] = sqlATQuery:GetString(2)
					end
					
					if not ( sqlATMQuery:NextRow() ) then break end
				end
			end
		end
	else
		return false
	end

	return true
end

cf.ReloadScoreboard()

if (scriptActive) then
	if (isObject) then
		RegisterGameObjectGossipEvent(entryID, 1, Gossip_onTalk)
		RegisterGameObjectGossipEvent(entryID, 2, Gossip_onSelect)
	else
		RegisterCreatureGossipEvent(entryID, 1, Gossip_onTalk)
		RegisterCreatureGossipEvent(entryID, 2, Gossip_onSelect)
	end

	if (refresh) then RegisterEvent( cf.ReloadScoreboard, refreshTimer, 0 ) end
end