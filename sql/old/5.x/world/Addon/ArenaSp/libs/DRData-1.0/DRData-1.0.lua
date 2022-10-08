local major = "DRData-1.0"
local minor = 1028
assert(LibStub, string.format("%s requires LibStub.", major))

local Data = LibStub:NewLibrary(major, minor)
if( not Data ) then return end

local L = {
	["Roots"] = "Roots",
	["Stuns"] = "Stuns",
	["Cyclone"] = "Cyclone",
	["Disarms"] = "Disarms",
	["Mesmerizes"] = "Mesmerizes",
	["Mesmerizes (short)"] = "Mesmerizes (short)",
	["Fears"] = "Fears",
	["Horrors"] = "Horrors",
	["Mind Control"] = "Mind Control",
	["Stuns (short)"] = "Stuns (short)",
	["Silences"] = "Silences",
	["Taunts"] = "Taunts",
	["Roots (short)"] = "Roots (short)",
	["Knockbacks"] = "Knockbacks",
}

local locale = GetLocale()
if locale == "deDE" then
	
elseif locale == "esES" then
	L["Cyclone"] = "Ciclón"
L["Disarms"] = "Desarmes"
L["Fears"] = "Miedos"
L["Horrors"] = "Horrores"
L["Knockbacks"] = "Derribos"
L["Mesmerizes"] = "Hipnotizaciones"
L["Mesmerizes (short)"] = "Hipnotizaciones (cortas)"
L["Mind Control"] = "Control Mental"
L["Roots"] = "Raíces"
L["Roots (short)"] = "Raíces (cortas)"
L["Silences"] = "SIlencios"
L["Stuns"] = "Aturdimientos"
L["Stuns (short)"] = "Aturdimientos (cortos)"
L["Taunts"] = "Provocaciones"

elseif locale == "esMX" then
	L["Cyclone"] = "Ciclón"
L["Disarms"] = "Desarmes"
L["Fears"] = "Miedos"
L["Horrors"] = "Horrores"
L["Knockbacks"] = "Derribos"
L["Mesmerizes"] = "Hipnotizaciones"
L["Mesmerizes (short)"] = "Hipnotizaciones (cortas)"
L["Mind Control"] = "Control Mental"
L["Roots"] = "Raíces"
L["Roots (short)"] = "Raíces (cortas)"
L["Silences"] = "SIlencios"
L["Stuns"] = "Aturdimientos"
L["Stuns (short)"] = "Aturdimientos (cortos)"
L["Taunts"] = "Provocaciones"

elseif locale == "frFR" then
	L["Cyclone"] = "Cyclone"
L["Disarms"] = "Désarmements"
L["Fears"] = "Peurs"
L["Horrors"] = "Horreurs"
L["Knockbacks"] = "Projections"
L["Mesmerizes"] = "Désorientations"
L["Mesmerizes (short)"] = "Désorientations (courtes)"
L["Mind Control"] = "Contrôle mental"
L["Roots"] = "Immobilisations"
L["Roots (short)"] = "Immobilisations (courtes)"
L["Silences"] = "Silences"
L["Stuns"] = "Etourdissements"
L["Stuns (short)"] = "Etourdissements (courts)"
L["Taunts"] = "Provocations"

elseif locale == "itIT" then
	
elseif locale == "koKR" then
	
elseif locale == "ptBR" then
	
elseif locale == "ruRU" then
	
elseif locale == "zhCN" then
	
elseif locale == "zhTW" then
	L["Cyclone"] = "颶風術"
L["Disarms"] = "繳械"
L["Fears"] = "恐懼"
L["Horrors"] = "恐慌"
L["Knockbacks"] = "擊退"
L["Mesmerizes"] = "迷惑"
L["Mesmerizes (short)"] = "迷惑(短)"
L["Mind Control"] = "心靈控制"
L["Roots"] = "定身"
L["Roots (short)"] = "定身(短)"
L["Silences"] = "沉默"
L["Stuns"] = "昏迷"
L["Stuns (short)"] = "昏迷(短)"
L["Taunts"] = "嘲諷"

end

-- How long before DR resets
-- While everyone will tell you it's 15 seconds, it's actually 16 - 20 seconds with 18 being a decent enough average
Data.RESET_TIME = 15

-- List of spellID -> DR category
Data.spells = {
	--[[ TAUNT ]]--
	-- Death Knight
	[ 56222] = "taunt", -- Dark Command
	[ 57603] = "taunt", -- Death Grip
	-- I have also seen these two spellIDs used for the Death Grip debuff in MoP.
	-- I have not seen the first one here in any of my MoP testing, but it may still be valid.
	[ 49560] = "taunt", -- Death Grip
	[ 51399] = "taunt", -- Death Grip
	-- Druid
	[  6795] = "taunt", -- Growl
	-- Hunter
	[ 20736] = "taunt", -- Distracting Shot
	-- Monk
	[116189] = "taunt", -- Provoke
	-- Paladin
	[ 62124] = "taunt", -- Reckoning
	-- Warlock
	[ 17735] = "taunt", -- Suffering (Voidwalker)
	-- Warrior
	[   355] = "taunt", -- Taunt
	-- Shaman
	[ 36213] = "taunt", -- Angered Earth (Earth Elemental)

	--[[ MESMERIZES ]]--
	-- Note: reuse the previously-used "disorient" category to avoid breaking addons
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#4

	-- Druid
	[  2637] = "disorient", -- Hibernate
	-- Hunter
	[  3355] = "disorient", -- Freezing Trap
	[ 19386] = "disorient", -- Wyvern Sting
	-- Mage
	[   118] = "disorient", -- Polymorph
	[ 28272] = "disorient", -- Polymorph (pig)
	[ 28271] = "disorient", -- Polymorph (turtle)
	[ 61305] = "disorient", -- Polymorph (black cat)
	[ 61025] = "disorient", -- Polymorph (serpent) -- FIXME: gone ?
	[ 61721] = "disorient", -- Polymorph (rabbit)
	[ 61780] = "disorient", -- Polymorph (turkey)
	[ 82691] = "disorient", -- Ring of Frost
	-- Monk
	[115078] = "disorient", -- Paralysis
	-- Paladin
	[ 20066] = "disorient", -- Repentance
	-- Priest
	[  9484] = "disorient", -- Shackle Undead
	-- Rogue
	[  1776] = "disorient", -- Gouge
	[  6770] = "disorient", -- Sap
	-- Shaman
	[ 76780] = "disorient", -- Bind Elemental
	[ 51514] = "disorient", -- Hex
	-- Warlock
	[   710] = "disorient", -- Banish
	-- Pandaren
	[107079] = "disorient", -- Quaking Palm

	--[[ SHORT MESMERIZES ]]--
	-- Note: this category does not share diminishing returns with the above Mesmerize category.
	-- Called "Mesmerize". http://us.battle.net/wow/en/forum/topic/10195910192#4

	-- Druid
	[    99] = "shortdisorient", -- Disorienting Roar (talent)
	-- Hunter
	[ 19503] = "shortdisorient", -- Scatter Shot
	-- Mage
	[ 31661] = "shortdisorient", -- Dragon's Breath
	-- Monk
	[123394] = "shortdisorient", -- Breath of Fire (Glyphed) -- ID NEED CONFIRMATION
	-- Priest
	[ 88625] = "shortdisorient", -- Holy Word: Chastise

	--[[ SILENCES ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#6

	-- Death Knight
	[108194] = "silence", -- Asphyxiate (if target is immune to stun)
	[ 47476] = "silence", -- Strangulate
	-- Druid
	[114237] = "silence", -- Glyph of Fae Silence
	-- Hunter
	[ 34490] = "silence", -- Silencing Shot
	-- Mage
	[102051] = "silence", -- Frostjaw
	[ 55021] = "silence", -- Counterspell
	-- Monk
	[137460] = "silence", -- Ring of Peace (Silence effect)
	[116709] = "silence", -- Spear Hand Strike
	-- Paladin
	[ 31935] = "silence", -- Avenger's Shield
	-- Priest
	[ 15487] = "silence", -- Silence
	-- Rogue
	[  1330] = "silence", -- Garrote
	-- Warlock
	[ 24259] = "silence", -- Spell Lock (Fel Hunter)
	[115782] = "silence", -- Optical Blast (Observer)
	-- Blood Elf
	[ 25046] = "silence", -- Arcane Torrent (Energy version)
	[ 28730] = "silence", -- Arcane Torrent (Mana version)
	[ 50613] = "silence", -- Arcane Torrent (Runic power version)
	[ 69179] = "silence", -- Arcane Torrent (Rage version)
	[ 80483] = "silence", -- Arcane Torrent (Focus version)

	--[[ DISARMS ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#7

	-- Hunter
	[ 50541] = "disarm", -- Clench (Scorpid pet)
	[ 91644] = "disarm", -- Snatch (Bird of Prey pet)
	-- Monk
	[117368] = "disarm", -- Grapple Weapon
	[126458] = "disarm", -- Grapple Weapon (Symbiosis)
	[137461] = "disarm", -- Ring of Peace (Disarm effect)
	-- Priest
	[ 64058] = "disarm", -- Psychic Horror (Disarm effect)
	-- Rogue
	[ 51722] = "disarm", -- Dismantle
	-- Warlock
	[118093] = "disarm", -- Disarm (Voidwalker/Voidlord)
	-- Warrior
	[   676] = "disarm", -- Disarm

	--[[ FEARS ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#5

	-- Druid
	[113004] = "fear", -- Intimidating Roar (Symbiosis)
	[113056] = "fear", -- Intimidating Roar (Symbiosis)
	-- Hunter
	[  1513] = "fear", -- Scare Beast
	-- Paladin
	[105421] = "fear", -- Blinding Light
	[ 10326] = "fear", -- Turn Evil
	[145067] = "fear", -- Turn Evil (Evil is a Point of View)
	-- Priest
	[  8122] = "fear", -- Psychic Scream
	[113792] = "fear", -- Psychic Terror (Psyfiend)
	-- Rogue
	[  2094] = "fear", -- Blind
	-- Warlock
	[  5782] = "fear", -- Fear
	[118699] = "fear", -- Fear -- new SpellID in MoP, Blood Fear uses same ID
	[  5484] = "fear", -- Howl of Terror
	[115268] = "fear", -- Mesmerize (Shivarra)
	[  6358] = "fear", -- Seduction (Succubus)
--	[104045] = "fear", -- Sleep (Metamorphosis) -- FIXME: verify this is the correct category
	-- Warrior
	[  5246] = "fear", -- Intimidating Shout (main target)
	[ 20511] = "fear", -- Intimidating Shout (secondary targets)

	--[[ STUNS ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#3

	-- Death Knight
	[108194] = "ctrlstun", -- Asphyxiate
	[ 91800] = "ctrlstun", -- Gnaw (Ghoul)
	[ 91797] = "ctrlstun", -- Monstrous Blow (Dark Transformation Ghoul)
	[115001] = "ctrlstun", -- Remorseless Winter
	-- Druid
	[102795] = "ctrlstun", -- Bear Hug
	[ 22570] = "ctrlstun", -- Maim
	[  5211] = "ctrlstun", -- Mighty Bash
	[  9005] = "ctrlstun", -- Pounce
	[102546] = "ctrlstun", -- Pounce (Incarnation)
	[113801] = "ctrlstun", -- Bash (treants in feral spec) (Bugged by blizzard - it instantly applies all 3 levels of DR right now, making any target instantly immune to ctrlstuns)
	-- Hunter
	[117526] = "ctrlstun", -- Binding Shot
	[ 24394] = "ctrlstun", -- Intimidation
	[ 90337] = "ctrlstun", -- Bad Manner (Monkey pet)
	[126246] = "ctrlstun", -- Lullaby (Crane pet) -- ID NEED CONFIRMATION
	[126423] = "ctrlstun", -- Petrifying Gaze (Basilisk pet) -- ID NEED CONFIRMATION
	[126355] = "ctrlstun", -- Quill (Porcupine pet) -- ID NEED CONFIRMATION
	[ 56626] = "ctrlstun", -- Sting (Wasp pet)
	[ 50519] = "ctrlstun", -- Sonic Blast (Bat pet)
	[ 96201] = "ctrlstun", -- Web Wrap (Shale Spider pet)
	-- Mage
	[118271] = "ctrlstun", -- Combustion
	[ 44572] = "ctrlstun", -- Deep Freeze
	-- Monk
	[119392] = "ctrlstun", -- Charging Ox Wave
	[122242] = "ctrlstun", -- Clash
	[120086] = "ctrlstun", -- Fists of Fury
	[119381] = "ctrlstun", -- Leg Sweep
	-- Paladin
	[115752] = "ctrlstun", -- Blinding Light (Glyphed)
	[   853] = "ctrlstun", -- Hammer of Justice
	[110698] = "ctrlstun", -- Hammer of Justice (Symbiosis)
	[119072] = "ctrlstun", -- Holy Wrath
	[105593] = "ctrlstun", -- Fist of Justice
	-- Rogue
	[  1833] = "ctrlstun", -- Cheap Shot
	[   408] = "ctrlstun", -- Kidney Shot
	-- Shaman
	[118345] = "ctrlstun", -- Pulverize (Primal Earth Elemental)
	[118905] = "ctrlstun", -- Static Charge (Capacitor Totem)
	-- Warlock
	[ 89766] = "ctrlstun", -- Axe Toss (Felguard)
	[ 30283] = "ctrlstun", -- Shadowfury
	[ 22703] = "ctrlstun", -- Summon Infernal
	-- Warrior
	[132168] = "ctrlstun", -- Shockwave
	[107570] = "ctrlstun", -- Storm Bolt
	-- Tauren
	[ 20549] = "ctrlstun", -- War Stomp

	--[[ SHORT STUNS ]]--
	-- cf.  http://us.battle.net/wow/en/forum/topic/10195910192#3
	-- Notes: 1. this category does not share diminishing returns with the above Stuns category.
	-- 2. Reuse the previously-used "rndstun" category to avoid breaking addons.

	-- Rogue
	[113953] = "rndstun", -- Paralysis (stun effect of Paralytic Poison)
	-- Warrior
	[118895] = "rndstun", -- Dragon Roar (talent)
	-- Shaman
	[ 77505] = "rndstun", -- Earthquake
	-- Warrior
	[   100] = "rndstun", -- Charge
	[118000] = "rndstun", -- Dragon Roar

	--[[ ROOTS ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#2

	-- Death Knight
	[ 96294] = "ctrlroot", -- Chains of Ice (Chilblains Root)
	-- Druid
	[   339] = "ctrlroot", -- Entangling Roots
	[113275] = "ctrlroot", -- Entangling Roots (Symbiosis)
	[ 19975] = "ctrlroot", -- Nature's Grasp (Uses different spellIDs than Entangling Roots for the same spell)
	[102359] = "ctrlroot", -- Mass Entanglement (talent)
	-- Hunter
	[ 53148] = "ctrlroot", -- Charge (Tenacity pet)
	[ 50245] = "ctrlroot", -- Pin (Crab)
	[  4167] = "ctrlroot", -- Web (Spider)
	[ 54706] = "ctrlroot", -- Venom Web Spray (Silithid)
	[ 90327] = "ctrlroot", -- Lock Jaw (Dog)
	[128405] = "ctrlroot", -- Narrow Escape (talent)
	-- Mage
	[   122] = "ctrlroot", -- Frost Nova
	[110693] = "ctrlroot", -- Frost Nova (Symbiosis)
	[ 33395] = "ctrlroot", -- Freeze (Water Elemental)
	-- Monk
	[116706] = "ctrlroot", -- Disable
	-- Priest
	[ 87194] = "ctrlroot", -- Glyph of Mind Blast
	[114404] = "ctrlroot", -- Void Tendrils
	-- Rogue
	[115197] = "ctrlroot", -- Partial Paralysis (Shiv effect with Paralytic Poison)
	-- Shaman
	[ 63685] = "ctrlroot", -- Freeze (Frozen Power talent)
	-- Warrior
	[107566] = "ctrlroot", -- Staggering Shout (talent)

	--[[ SHORT ROOTS ]]--
	-- Note: this category does not share diminishing returns with the above Roots category.
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#2

	-- Hunter
	[ 64803] = "shortroot", -- Entrapment
	-- Mage
	[111264] = "shortroot", -- Ice Ward -- ID NEED CONFIRMATION
	-- Monk
	[115073] = "shortroot", -- Spinning Fire Blossom -- ID NEED CONFIRMATION
	-- Shaman
	[ 64695] = "shortroot", -- Earthgrab Totem

	--[[ HORROR ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#5
	-- Priest
	[ 64044] = "horror", -- Psychic Horror (Horror effect)
	-- Warlock
	[111397] = "horror", -- Blood Horror
	[  6789] = "horror", -- Mortal Coil

	--[[ MISC ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#9
	-- Druid
	[ 33786] = "cyclone",       -- Cyclone
	[113506] = "cyclone",       -- Cyclone (Symbiosis)
	-- Priest
	[   605] = "mc",            -- Dominate Mind

	--[[ KNOCKBACK ]]--
	-- cf. http://us.battle.net/wow/en/forum/topic/10195910192#8

	-- Death Knight
	[108199] = "knockback", -- Gorefiend's Grasp
	-- Druid
	[102793] = "knockback", -- Ursol's Vortex
	[132469] = "knockback", -- Typhoon
	-- Hunter
	[119403] = "knockback", -- Glyph of Explosive Trap
	-- Shaman
	[ 51490] = "knockback", -- Thunderstormo
	-- Warlock
	[  6360] = "knockback", -- Whiplash
	[115770] = "knockback", -- Fellash

}

-- DR Category names
Data.categoryNames = {
	["ctrlroot"] = L["Roots"],
	["shortroot"] = L["Roots (short)"],
	["ctrlstun"] = L["Stuns"],
	["cyclone"] = L["Cyclone"],
	["disarm"] = L["Disarms"],
	["disorient"] = L["Mesmerizes"],
	["shortdisorient"] = L["Mesmerizes (short)"],
	["fear"] = L["Fears"],
	["horror"] = L["Horrors"],
	["mc"] = L["Mind Control"],
	["rndstun"] = L["Stuns (short)"],
	["silence"] = L["Silences"],
	["taunt"] = L["Taunts"],
	["knockback"] = L["Knockbacks"], -- NEEDS PROPER TESTING WITH DEPENDENT ADDONS
}

-- Categories that have DR in PvE as well as PvP
Data.pveDR = {
	["ctrlstun"] = true,
	["rndstun"] = true,
	["taunt"] = true,
	["cyclone"] = true,
	-- ["bindelemental"] = true, -- Why was this added to pveDR? Just tested and it definitely does not have PvE DR.
}

-- Public APIs
-- Category name in something usable
function Data:GetCategoryName(cat)
	return cat and Data.categoryNames[cat] or nil
end

-- Spell list
function Data:GetSpells()
	return Data.spells
end

-- Seconds before DR resets
function Data:GetResetTime()
	return Data.RESET_TIME
end

-- Get the category of the spellID
function Data:GetSpellCategory(spellID)
	return spellID and Data.spells[spellID] or nil
end

-- Does this category DR in PvE?
function Data:IsPVE(cat)
	return cat and Data.pveDR[cat] or nil
end

-- List of categories
function Data:GetCategories()
	return Data.categoryNames
end

-- Next DR, if it's 1.0, next is 0.50, if it's 0.[50] = "ctrlroot",next is 0.[25] = "ctrlroot",and such
function Data:NextDR(diminished)
	if( diminished == 1 ) then
		return 0.50
	elseif( diminished == 0.50 ) then
		return 0.25
	end

	return 0
end

--[[ EXAMPLES ]]--
-- This is how you would track DR easily, you're welcome to do whatever you want with the below functions

--[[
local trackedPlayers = {}
local function debuffGained(spellID, destName, destGUID, isEnemy, isPlayer)
	-- Not a player, and this category isn't diminished in PVE, as well as make sure we want to track NPCs
	local drCat = DRData:GetSpellCategory(spellID)
	if( not isPlayer and not DRData:IsPVE(drCat) ) then
		return
	end

	if( not trackedPlayers[destGUID] ) then
		trackedPlayers[destGUID] = {}
	end

	-- See if we should reset it back to undiminished
	local tracked = trackedPlayers[destGUID][drCat]
	if( tracked and tracked.reset <= GetTime() ) then
		tracked.diminished = 1.0
	end
end

local function debuffFaded(spellID, destName, destGUID, isEnemy, isPlayer)
	local drCat = DRData:GetSpellCategory(spellID)
	if( not isPlayer and not DRData:IsPVE(drCat) ) then
		return
	end

	if( not trackedPlayers[destGUID] ) then
		trackedPlayers[destGUID] = {}
	end

	if( not trackedPlayers[destGUID][drCat] ) then
		trackedPlayers[destGUID][drCat] = { reset = 0, diminished = 1.0 }
	end

	local time = GetTime()
	local tracked = trackedPlayers[destGUID][drCat]

	tracked.reset = time + DRData:GetResetTime()
	tracked.diminished = DRData:NextDR(tracked.diminished)

	-- Diminishing returns changed, now you can do an update
end

local function resetDR(destGUID)
	-- Reset the tracked DRs for this person
	if( trackedPlayers[destGUID] ) then
		for cat in pairs(trackedPlayers[destGUID]) do
			trackedPlayers[destGUID][cat].reset = 0
			trackedPlayers[destGUID][cat].diminished = 1.0
		end
	end
end

local COMBATLOG_OBJECT_TYPE_PLAYER = COMBATLOG_OBJECT_TYPE_PLAYER
local COMBATLOG_OBJECT_REACTION_HOSTILE = COMBATLOG_OBJECT_REACTION_HOSTILE
local COMBATLOG_OBJECT_CONTROL_PLAYER = COMBATLOG_OBJECT_CONTROL_PLAYER

local eventRegistered = {["SPELL_AURA_APPLIED"] = true, ["SPELL_AURA_REFRESH"] = true, ["SPELL_AURA_REMOVED"] = true, ["PARTY_KILL"] = true, ["UNIT_DIED"] = true}
local function COMBAT_LOG_EVENT_UNFILTERED(self, event, timestamp, eventType, sourceGUID, sourceName, sourceFlags, destGUID, destName, destFlags, spellID, spellName, spellSchool, auraType)
	if( not eventRegistered[eventType] ) then
		return
	end

	-- Enemy gained a debuff
	if( eventType == "SPELL_AURA_APPLIED" ) then
		if( auraType == "DEBUFF" and DRData:GetSpellCategory(spellID) ) then
			local isPlayer = ( bit.band(destFlags, COMBATLOG_OBJECT_TYPE_PLAYER) == COMBATLOG_OBJECT_TYPE_PLAYER or bit.band(destFlags, COMBATLOG_OBJECT_CONTROL_PLAYER) == COMBATLOG_OBJECT_CONTROL_PLAYER )
			debuffGained(spellID, destName, destGUID, (bit.band(destFlags, COMBATLOG_OBJECT_REACTION_HOSTILE) == COMBATLOG_OBJECT_REACTION_HOSTILE), isPlayer)
		end

	-- Enemy had a debuff refreshed before it faded, so fade + gain it quickly
	elseif( eventType == "SPELL_AURA_REFRESH" ) then
		if( auraType == "DEBUFF" and DRData:GetSpellCategory(spellID) ) then
			local isPlayer = ( bit.band(destFlags, COMBATLOG_OBJECT_TYPE_PLAYER) == COMBATLOG_OBJECT_TYPE_PLAYER or bit.band(destFlags, COMBATLOG_OBJECT_CONTROL_PLAYER) == COMBATLOG_OBJECT_CONTROL_PLAYER )
			local isHostile = (bit.band(destFlags, COMBATLOG_OBJECT_REACTION_HOSTILE) == COMBATLOG_OBJECT_REACTION_HOSTILE)
			debuffFaded(spellID, destName, destGUID, isHostile, isPlayer)
			debuffGained(spellID, destName, destGUID, isHostile, isPlayer)
		end

	-- Buff or debuff faded from an enemy
	elseif( eventType == "SPELL_AURA_REMOVED" ) then
		if( auraType == "DEBUFF" and DRData:GetSpellCategory(spellID) ) then
			local isPlayer = ( bit.band(destFlags, COMBATLOG_OBJECT_TYPE_PLAYER) == COMBATLOG_OBJECT_TYPE_PLAYER or bit.band(destFlags, COMBATLOG_OBJECT_CONTROL_PLAYER) == COMBATLOG_OBJECT_CONTROL_PLAYER )
			debuffFaded(spellID, destName, destGUID, (bit.band(destFlags, COMBATLOG_OBJECT_REACTION_HOSTILE) == COMBATLOG_OBJECT_REACTION_HOSTILE), isPlayer)
		end

	-- Don't use UNIT_DIED inside arenas due to accuracy issues, outside of arenas we don't care too much
	elseif( ( eventType == "UNIT_DIED" and select(2, IsInInstance()) ~= "arena" ) or eventType == "PARTY_KILL" ) then
		resetDR(destGUID)
	end
end]]
