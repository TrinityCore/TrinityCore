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
¦- Contributors: Rochet2.                  ¦+ Easy message features                   ¦
¦- Completion: 100%                        ¦+ Account or Character save methods       ¦
¦- Script Names: Chat System               ¦+ Message based on the selected language  ¦
¦- Description: Sends a message to every   ¦+ Enable or disable chats                 ¦
¦  player, which has the chat enabled.     ¦+ Three different chats (global, pvp, pve)¦
¦                                          ¦+ Language support (BETA)                 ¦
L==========================================¦==========================================-
-==========================================T==========================================¬
¦            Config Description            ¦             Config Variables             ¦
¦==========================================+==========================================¦
¦ -showLogin: Show status on login         ¦ "[PvP Announcer]" <- "Heitx is ..."      ¦
¦ -saveMethod: Save either for acc or char ¦ acc > char : true = enable the method    ¦
¦ -defaultSettings: Default settings..     ¦ true = enable the chat, false to disable ¦
¦ -activeLanguages: Lang players can select¦ {'', ''} seperate each lang with a comma ¦
¦ -commands: contains every command        ¦ ['LANG'] = {'every command in a string'} ¦
¦ -messages: contains every message        ¦ every "message" has 'to be' in a string  ¦
¦ -colors: contains colors hexcode for use ¦ seperate each color with a comma         ¦
¦ -ranks: contains player ranks            ¦ based on the common.h file               ¦
¦ -classColors: every class color in hex   ¦ change strings, if you want custom color ¦
L==========================================¦==========================================-
-==========================================¬
¦            [Message Features]            ¦
¦==========================================¦
¦ |P| 		: Player's Name                ¦ 1 = Warrior, 2 = Paladin, 3 = Hunter, 4 = Rogue,
¦ |PC| 		: Player's Class ID            ¦ 5 = Priest, 6 = Death Knight, 7 = Shaman,
¦ |PCN| 	: Player's Class Name          ¦ 8 = Mage, 9 = Warlock, 10 = Monk, 11 = Druid
¦ |PCC| 	: Player's Class Color         ¦
¦ |PT| 		: Player's Team (A / H)        ¦
¦ |PTC| 	: Player's Team Color          ¦
¦ |PTP| 	: Player's Team Picture        ¦
¦ |PGMR| 	: Player's GM Rank             ¦
¦ |PGMR| 	: Player's GM Rank             ¦
¦ |PGMC| 	: Player's GM Color            ¦
¦ |C1| ..  	: Colors!                      ¦
L==========================================-
-==========================================¬
¦       Accounts SQL - Auth Database       ¦
L==========================================-
CREATE TABLE `chatsystem_account` (
  `account_id` int(10) unsigned NOT NULL COMMENT 'Account ID',
  `language` varchar(32) NOT NULL DEFAULT 'EN' COMMENT 'LANGUAGE',
  `chat_global` tinyint(1) unsigned NOT NULL DEFAULT '1' COMMENT 'CHAT GLOBAL',
  `chat_pvp` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVP',
  `chat_pve` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVE',
  PRIMARY KEY (`account_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8
-==========================================¬
¦      Characters SQL - Auth Database      ¦
L==========================================-
CREATE TABLE `chatsystem_character` (
  `character_id` int(10) unsigned NOT NULL COMMENT 'Character ID (GUIDLOW)',
  `language` varchar(32) NOT NULL DEFAULT 'EN' COMMENT 'LANGUAGE',
  `chat_global` tinyint(1) unsigned NOT NULL DEFAULT '1' COMMENT 'CHAT GLOBAL',
  `chat_pvp` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVP',
  `chat_pve` tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT 'CHAT PVE',
  PRIMARY KEY (`character_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8

----------------------------------------------------------]]

--[[ System Configs ]]

local scriptActive 		= true

local showLogin			= true -- Sort of a debug setting (Shows status on login)
local saveMethod 		= {account = true, character = false} -- if both true, account has highest priority
local defaultSettings 	= {'EN', true, true, true} -- {language, global, pvp, pve}
local activeLanguages	= {'EN'} -- The code only know CAPITAL LETTERS, Sorry..

local cgPrefix 	= '#w' -- global / world
local cppPrefix = '#pvp' -- pvp
local cpePrefix = '#pve' -- pve
local maxLength	= 125

local commands = {
	['EN'] = {
		'ct',
		'ct s',
		'ct g',
		'ct pvp',
		'ct pve',
		'ct lang',
		'ct setlang',
		'ct help'
	},
	['DK'] = {
		'ct',
		'ct s',
		'ct g',
		'ct pvp',
		'ct pve',
		'ct sprog',
		'ct setsprog',
		'ct hjalp'
	}
}

local messages = { -- All the messages in a language needs a string.
	['EN'] = {
		chat = 'Chat Commands',
		status = {
			'-- Chat Settings --',
			'G-Chat: ',
			'PvP-Chat: ',
			'PvE-Chat: '
		},
		lang = 'Language(s) available: ',
		setlang = {'The selected language is not available.', 'Your language is now: '},
		help = {'|PTC|The Chats are categorised into three chats: Global, PvP & PvE.',
				'|PTC|You can enable or disable whenever you want.',
				'|PTC|if chat is true, you are allowed to receive & send messages.',
				'|PTC|if chat is false, you are not allowed...'
				},
		globalchat = { 
			channel = '|PTP||PTC|[G]|PGMC|[|PGMR|]|PCC|[|P|]|PTC| says: ', -- |PTC|[|PT|] -> [A]
			disabled = 'Global Chat has to be enabled to connect.'
		},
		pvpchat = { 
			channel = '|PTP||PTC|[PVP]|PGMC|[|PGMR|]|PCC|[|P|]|PTC| says: ', -- |PTC|[|PT|] -> [A]
			disabled = 'PvP Chat has to be enabled to connect.'
		},
		pvechat = { 
			channel = '|PTP||PTC|[PVE]|PGMC|[|PGMR|]|PCC|[|P|]|PTC| says: ', -- |PTC|[|PT|] -> [A]
			disabled = 'PvE Chat has to be enabled to connect.'
		}
	},
	['DK'] = {
		chat = 'Chat Kommandoer',
		status = {
			'-- Status --',
			'G-Chat: ',
			'PvP-Chat: ',
			'PvE-Chat: '
		},
		lang = 'Sprog muligheder: ',
		setlang = {' ', 'Dit sprog er nu: '},
		help = {'|PTC|Chattene er opdelt i tre chatrum: Global, PvP og PvE.',
				'|PTC|Du kan sla dem til og fra nar du har lyst.',
				'|PTC|Hvis den valgte chat er slaet til, kan du sende og modtage bedskeder.',
				'|PTC|Hvis den valgte chat er slaet fra, det modsatte...'
				},
		globalchat = { 
			channel = '|PTP||PTC|[G]|PGMC|[|PGMR|]|PCC|[|P|]|PTC| siger: ',
			disabled = 'Global chatten skal vare slaet til.'
		},
		pvpchat = { 
			channel = '|PTP||PTC|[PVP]|PGMC|[|PGMR|]|PCC|[|P|]|PTC| siger: ',
			disabled = 'PvP chatten skal vare slaet til.'
		},
		pvechat = { 
			channel = '|PTP||PTC|[PVE]|PGMC|[|PGMR|]|PCC|[|P|]|PTC| siger: ',
			disabled = 'PvE chatten skal vare slaet til.'
		}
	}
}

local colors = { -- No HASHTAG or |cff required.
	"00AABB", -- |C1|
	"", -- |C2|
	"" -- |C3|
}

local ranks = {
	{"7DFF00", "PLAYER"}, -- GMRANK 0 : PLAYER
	{"7DFF00", "MOD"}, -- GMRANK 1 : MOD
	{"E7A200", "GM"}, -- GMRANK 2 : Game Master
	{"FF6600", "ADMIN"}, -- GMRANK 3 : Admin
	{"FF6600", "CONSOLE"} -- GMRANK 4 : Console
}

local classColors = {
	"C79C6E", -- Warrior
	"F58CBA", -- Paladin
	"ABD473", -- Hunter
	"FFF569", -- Rogue
	"FFFFFF", -- Priest
	"C41F3B", -- Death Knight
	"0070DE", -- Shaman
	"69CCF0", -- Mage
	"9482C9", -- Warlock
	"FF7D0A" -- Druid
}

--[[ The section beneath this line is untouchable, 
		unless you know what you're doing! --]]

local storeSettings = {}
local f = {}

local selectedLanguage 	= nil
local selectedMethod 	= nil
local selectedDatabase 	= nil

local function Command_onChat(event, player, command)
	f.CheckLanguage(player)
	f.CheckMethod(player)

	if ( command == commands[selectedLanguage][1] ) then --[[ CHAT COMMAND ]]
		player:SendBroadcastMessage( messages[selectedLanguage]['chat'] )
		for i, v in pairs( commands[selectedLanguage] ) do
			player:SendBroadcastMessage( '+ ' .. tostring(v) )
		end
		return false
	elseif ( command == commands[selectedLanguage][2] ) then --[[ STATUS COMMAND ]]
		for i, v in pairs( storeSettings[selectedMethod] ) do
			if (i == 1) then
				player:SendBroadcastMessage( messages[selectedLanguage]['status'][i] )
			else
				player:SendBroadcastMessage( messages[selectedLanguage]['status'][i] .. tostring(v) )
			end
		end
		return false
	elseif ( command == commands[selectedLanguage][3] ) then --[[ GLOBAL COMMAND ]]
		storeSettings[selectedMethod][2] = f.ChangeStatus(storeSettings[selectedMethod][2])
		player:SendAreaTriggerMessage( messages[selectedLanguage]['status'][2] .. tostring(storeSettings[selectedMethod][2]) )
		return false
	elseif ( command == commands[selectedLanguage][4] ) then --[[ PVP COMMAND ]]
		storeSettings[selectedMethod][3] = f.ChangeStatus(storeSettings[selectedMethod][3])
		player:SendAreaTriggerMessage( messages[selectedLanguage]['status'][3] .. tostring(storeSettings[selectedMethod][3]) )
		return false
	elseif ( command == commands[selectedLanguage][5] ) then --[[ PVE COMMAND ]]
		storeSettings[selectedMethod][4] = f.ChangeStatus(storeSettings[selectedMethod][4])
		player:SendAreaTriggerMessage( messages[selectedLanguage]['status'][4] .. tostring(storeSettings[selectedMethod][4]) )
		return false
	elseif ( command == commands[selectedLanguage][6] ) then --[[ LANGUAGE COMMAND ]]
		player:SendBroadcastMessage( messages[selectedLanguage]['lang']..string.upper(table.concat(activeLanguages, ", ")) )
		return false
	elseif ( string.find(command, commands[selectedLanguage][7]) == 1 ) then --[[ SETLANG COMMAND ]]
		command = string.sub(command, string.len(commands[selectedLanguage][7])+2 )
		
		player:SendBroadcastMessage(command)

		if (command  ~= nil) or (command ~= '') then -- if command is NOT nil
			command = string.upper( string.match(command, "%a+") )

			if ( f.CheckActiveLanguage(command) ) then
				storeSettings[selectedMethod][1] = command
				player:SendBroadcastMessage( messages[selectedLanguage]['setlang'][2] .. storeSettings[selectedMethod][1])
			else
				player:SendBroadcastMessage( messages[selectedLanguage]['setlang'][1])	
			end
		else
			player:SendBroadcastMessage( messages[selectedLanguage]['setlang'][1])
		end

		return false
	elseif ( command == commands[selectedLanguage][8] ) then --[[ HELP COMMAND ]]
		for i, v in ipairs(messages[selectedLanguage]['help']) do
			player:SendBroadcastMessage( f.TextMessage(player, v) .. '|r' )
		end

		return false
	end
end

--[[ GLOBAL, PVP, PVE -CHAT! ]]

local function PlayerChat_onMessage(event, player, message, type, language)
	if ( string.find(message, cgPrefix .. '%s') == 1 ) then -- [#w ] 
		message = string.sub(message, string.len(cgPrefix) + 2) -- [#w BOOM
			
		--player:SendBroadcastMessage(string.len(message) )
		if ( f.CheckMessage(message, maxLength) == false ) then
			message = nil
		end

		f.CheckMethod(player)
		f.CheckLanguage(player)

		if ( f.CheckPlayerChat(player, 'globalchat', 2, selectedLanguage) ) then
			f.MessageGlobalBroadcast(player, message, 'globalchat', 2, selectedLanguage)
		end

		return false
	elseif ( string.find(message, cppPrefix .. ' ') == 1 ) then
		message = string.sub(message, string.len(cppPrefix) + 1) -- #w BOOM

		if ( f.CheckMessage(message, maxLength) == false ) then
			message = nil
		end

		f.CheckMethod(player)
		f.CheckLanguage(player)

		if ( f.CheckPlayerChat(player, 'pvpchat', 3, selectedLanguage) ) then
			f.MessageGlobalBroadcast(player, message, 'pvpchat', 3, selectedLanguage)
		end

		return false
	elseif ( string.find(message, cpePrefix .. ' ') == 1 ) then
		message = string.sub(message, string.len(cpePrefix) + 1) -- #w BOOM

		if ( f.CheckMessage(message, maxLength) == false ) then
			message = nil
		end

		f.CheckMethod(player)
		f.CheckLanguage(player)

		if ( f.CheckPlayerChat(player, 'pvechat', 4, selectedLanguage) ) then
			f.MessageGlobalBroadcast(player, message, 'pvechat', 4, selectedLanguage)
		end

		return false
	end
end

local function Player_onLogin(event, player)
	if ( saveMethod['account'] == true ) then
		selectedMethod = player:GetAccountId()
		selectedDatabase = {'chatsystem_account', 'account_id'}
	else
		selectedMethod = player:GetGUIDLow()
		selectedDatabase = {'chatsystem_character', 'character_id'}
	end

	if ( saveMethod['account'] ~= false) or ( saveMethod['character'] ~= false) then
		local sql = "SELECT * FROM " .. selectedDatabase[1] .. " WHERE " .. selectedDatabase[2] .. " = " .. selectedMethod
		local result = AuthDBQuery(sql)

		if (result == nil) then
			local createData = "INSERT INTO "..selectedDatabase[1].." ("..selectedDatabase[2]..", LANGUAGE, chat_global, chat_pvp, chat_pve) VALUES ("..selectedMethod..", '"..defaultSettings[1].."', "..tostring(defaultSettings[2])..", "..tostring(defaultSettings[3])..", "..tostring(defaultSettings[4])..")"
			result = AuthDBQuery(createData)
			result = AuthDBQuery(sql)
		end

		if (result) then

			storeSettings[selectedMethod] = {result:GetString(1)}

			for i = 1, 3, 1 do
				storeSettings[selectedMethod][i + 1] = result:GetBool(i + 1)
			end
		end
	else
		storeSettings[selectedMethod] = f.GetTableValues( defaultSettings )
	end

	if ( f.CheckActiveLanguage(storeSettings[selectedMethod][1]) ~= true ) then
		storeSettings[selectedMethod][1] = defaultSettings[1]
	end

	if (showLogin) then
		local loginStatus = {}
		for i, v in pairs( storeSettings[selectedMethod] ) do
			loginStatus[i] = v
		end
		player:SendBroadcastMessage( tostring(loginStatus[1]).. ', ' ..tostring(loginStatus[2]).. ', ' ..tostring(loginStatus[3]).. ', ' ..tostring(loginStatus[4]) )
	end
end

local function Player_onLogout(event, player)
	f.CheckMethod(player)

	if ( saveMethod['account'] ~= false) or ( saveMethod['character'] ~= false) then
		f.SaveOptions('language', storeSettings[selectedMethod][1]) -- database, setting
		f.SaveOptions('chat_global', storeSettings[selectedMethod][2]) -- database, setting
		f.SaveOptions('chat_pvp', storeSettings[selectedMethod][3]) -- database, setting
		f.SaveOptions('chat_pve', storeSettings[selectedMethod][4]) -- database, setting		
	else
		storeSettings[selectedMethod] = nil 
	end
end

--[[ CUSTOM FUNCTIONS : START ]]

--[[ checks if language is nil, if yes set it to default ]]
function f.CheckLanguage(player) -- check if language exist in the command table
	if ( type( commands[storeSettings[selectedMethod][1] ] ) ~= 'table' ) and ( type( messages[storeSettings[selectedMethod][1] ] ) ~= 'table' ) then
		storeSettings[selectedMethod][1] = defaultSettings[1]
	end

	selectedLanguage = storeSettings[selectedMethod][1]
end

function f.CheckActiveLanguage(language)
	for i, v in pairs( activeLanguages ) do
		if (v == language) then
			return true
		end
	end

	return false
end

function f.CheckMethod(player)
	if ( saveMethod['account'] == true ) then
		selectedMethod = player:GetAccountId()
	else
		selectedMethod = player:GetGUIDLow()
	end

	return selectedMethod
end

--[[ function to copy the default settings ]]
function f.GetTableValues(table)
	local newTable = {}

	if (type(table) == 'table') then
		for i, v in pairs(table) do
			newTable[i] = tostring(v)
		end
	end

	return newTable
end

--[[ change status of a chat ]]
function f.ChangeStatus(boolean)
	if (boolean == true) then
		boolean = false
	else
		boolean = true
	end

	return boolean
end

function f.CheckMessage(message, maxLength)
	if ( string.len(message) <= maxLength ) and ( string.len(message) ~= 0 ) then

	else
		return false
	end

	return true
end

function f.CheckPlayerChat(player, chatname, chatindex, language)
	if ( storeSettings[selectedMethod][chatindex] == true ) then
		return true
	else
		player:SendBroadcastMessage( messages[language][chatname]['disabled'] )
		return false
	end
end

--[[ Checks if player has chat enabled, if chat is active, send the message to everyone --]]
function f.MessageGlobalBroadcast(player, message, chatname, chatindex, language)
	for i, v in pairs( GetPlayersInWorld() ) do
		if (message ~= nil) and (storeSettings[f.CheckMethod(v)][chatindex] == true) then
			v:SendBroadcastMessage( f.TextMessage( player, messages[language][chatname]['channel'] ) .. message .. '|r')
		end
	end
end

--[[ Adds functionality to 'message feature' is described ]]
function f.TextMessage(player, message)
	if ( player:GetTeam() == 0) then -- Alliance
		message = message:gsub("|PT|", "A")
		message = message:gsub("|PTC|", "|cff" .. "8f8fff") -- 144587
		message = message:gsub("|PTP|", "|TInterface\\PvPRankBadges\\PvPRankAlliance.png:18|t") -- Icon
	else -- Horde
		message = message:gsub("|PT|", "H")
		message = message:gsub("|PTC|", "|cff" .. "B20000")
		message = message:gsub("|PTP|", "|TInterface\\PvPRankBadges\\PvPRankHorde.png:18|t") -- Icon
	end
	
	message = message:gsub("|P|", player:GetName()) -- playerName
	message = message:gsub("|PC|", player:GetClass()) -- playerClass eg. 1
	message = message:gsub("|PCN|", player:GetClassAsString()) -- playerClass eg. Warrior
	message = message:gsub("|PGMC|", '|cff' .. ranks[player:GetGMRank() + 1][1]) -- playerRankColor
	message = message:gsub("|PGMR|", ranks[player:GetGMRank() + 1][2]) -- playerRankRank

	message = message:gsub("|PCC|", '|cff'..classColors[player:GetClass()] )

	for i, v in pairs(colors) do -- Colors
		message = message:gsub("|C" .. i .. "|", '|cff' .. v)
	end

	return message
end

function f.SaveOptions(column, data)
	if ( type(data) == 'boolean' ) then
		AuthDBExecute('UPDATE ' .. selectedDatabase[1] .. ' SET ' .. column .. ' = ' .. tostring(data) .. ' WHERE '.. selectedDatabase[2] ..' = ' .. selectedMethod)
	else
		AuthDBExecute('UPDATE ' .. selectedDatabase[1] .. ' SET ' .. column .. ' = "' .. tostring(data) .. '" WHERE '.. selectedDatabase[2] ..' = ' .. selectedMethod)
	end
end

--[[ CUSTOM FUNCTIONS : END ]]

if (scriptActive) then
	RegisterPlayerEvent(42, Command_onChat)
	RegisterPlayerEvent(18, PlayerChat_onMessage)
	RegisterPlayerEvent(3, Player_onLogin)
	RegisterPlayerEvent(4, Player_onLogout)
end