local NPC_ID = NPCID

local T = 
	{
		-- Horde Cities
	
		{1, 1503, -4415.5, 22, 0},		-- Orgrimmar		intid 1
		{0, 1831, 238.5, 61.6, 0},		-- Undercity		intid 2
		{1, -1278, 122, 132, 0},		-- Thunderbluff		intid 3
		{530, 9484, -7294, 15, 0},		-- Silvermoon		intid 4

		-- Ally Cities

		{0, -8905, 560, 94, 0.62},		-- Stormwind		intid 5
		{0, -4795, -1117, 499, 0},		-- Ironforge		intid 6
		{1, 9952, 2280.5, 1342, 1.6},		-- Darnassus		intid 7
		{530, -3863, -11736, -106, 2},		-- The Exodar		intid 8
		
		-- Outlands Locations
		
		{530, 1481, 6829, 107, 6},		-- Blade's Edge		intid 9
		{530, -249, 947, 85, 2},		-- Hellfire		intid 10
		{530, -1769, 7150, -9, 2},		-- Nagrand		intid 11
		{530, 3043, 3645, 143, 2},		-- Netherstorm		intid 12
		{530, -3034, 2937, 87, 5},		-- Shadowmoon		intid 13
		{530, -1942, 4689, -2, 5},		-- Terokkar		intid 14
		{530, -217, 5488, 23, 2},		-- Zangarmarsh		intid 15
		{530, -1822, 5417, 1, 3},		-- Shattrath		intid 16
		
		-- Northrend Locations
		
		{571, 3230, 5279, 47, 3},		-- Borean Tundra	intid 17
		{571, 5732, 1016, 175, 3.6},		-- Crystalsong		intid 18
		{571, 3547, 274, 46, 1.6},		-- Dragonblight		intid 19
		{571, 3759, -2672, 177, 3},		-- Grizzly Hills	intid 20
		{571, 772, -2905, 7, 5},		-- Howling Fjord	intid 21
		{571, 8517, 676, 559, 4.7},		-- Icecrown		intid 22
		{571, 5571, 5739, -75, 2},		-- Sholazar		intid 23
		{571, 6121, -1025, 409, 4.7},		-- Storm Peaks		intid 24
		{571, 5135, 2840, 408, 3},		-- Wintergrasp		intid 25
		{571, 5761, -3547, 387, 5},		-- Zul'Drak		intid 26
		{571, 5826, 470, 659, 1.4},		-- Dalaran		intid 27
		
		-- PvP Locations
		
		{0, -13229, 226, 33, 1},		-- Gurubashi		intid 28
		{1, -3669, 1094, 160, 3},		-- Dire Maul		intid 29
		{530, -1983, 6562, 12, 2},		-- Nagrand		intid 30
		{530, 2910, 5976, 2, 4},		-- Blade's Edge		intid 31
	}

function Teleporter_Gossip(event, plr, unit)
	plr:GossipMenuAddItem(0, "Main Cities", 0, 1001, 0)
	plr:GossipMenuAddItem(0, "Outlands Locations", 0, 1002, 0)
	plr:GossipMenuAddItem(0, "Northrend Locations", 0, 1003, 0)
	plr:GossipMenuAddItem(0, "PvP Locations", 0, 1004, 0)
	plr:GossipSendMenu(1, unit)
end

function Teleporter_Event(event, plr, unit, arg2, intid)
	if(intid >= 1) and (intid <= 100) then
		plr:Teleport(T[intid][1], T[intid][2], T[intid][3], T[intid][4], T[intid][5])
	elseif(intid == 1000) then
		Teleporter_Gossip(event, plr, unit)
	elseif(intid >= 1001) and (intid <= 1004) then
		if(intid == 1001) then
			if(plr:GetTeam() == 1) then
				plr:GossipMenuAddItem(2, "Orgrimmar", 0, 1)
				plr:GossipMenuAddItem(2, "Undercity", 0, 2)
				plr:GossipMenuAddItem(2, "Thunderbluff", 0, 3)
				plr:GossipMenuAddItem(2, "Silvermoon", 0, 4)
			else
				plr:GossipMenuAddItem(2, "Stormwind", 0, 5)
				plr:GossipMenuAddItem(2, "Ironforge", 0, 6)
				plr:GossipMenuAddItem(2, "Darnassus", 0, 7)
				plr:GossipMenuAddItem(2, "The Exodar", 0, 8)
			end
		elseif(intid == 1002) then
			plr:GossipMenuAddItem(2, "Blade's Edge Mountains", 0, 9)
			plr:GossipMenuAddItem(2, "Hellfire Peninsula", 0, 10)
			plr:GossipMenuAddItem(2, "Nagrand", 0, 11)
			plr:GossipMenuAddItem(2, "Netherstorm", 0, 12)
			plr:GossipMenuAddItem(2, "Shadowmoon Valley", 0, 13)
			plr:GossipMenuAddItem(2, "Terokkar Forest", 0, 14)
			plr:GossipMenuAddItem(2, "Zangramarsh", 0, 15)
			plr:GossipMenuAddItem(2, "Shattrath", 0, 16)
		elseif(intid == 1003) then
			plr:GossipMenuAddItem(2, "Borean Tundra", 0, 17)
			plr:GossipMenuAddItem(2, "Crystalsong Forest", 0, 18)
			plr:GossipMenuAddItem(2, "Dragonblight", 0, 19)
			plr:GossipMenuAddItem(2, "Grizzly Hills", 0, 20)
			plr:GossipMenuAddItem(2, "Howling Fjords", 0, 21)
			plr:GossipMenuAddItem(2, "Icecrown Glaicer", 0, 22)
			plr:GossipMenuAddItem(2, "Sholazar Basin", 0, 23)
			plr:GossipMenuAddItem(2, "Storm Peaks", 0, 24)
			plr:GossipMenuAddItem(2, "Wintergrasp", 0, 25)
			plr:GossipMenuAddItem(2, "Zul'Drak", 0, 26)
			plr:GossipMenuAddItem(2, "Dalaran", 0, 27)
		elseif(intid == 1004) then
			plr:GossipMenuAddItem(9, "Gurubashi Arena", 0, 28)
			plr:GossipMenuAddItem(9, "Dire Maul Arena", 0, 29)
			plr:GossipMenuAddItem(9, "Nagrand Arena", 0, 30)
			plr:GossipMenuAddItem(9, "Blade's Edge Arena", 0, 31)
		end
		plr:GossipMenuAddItem(0, "Back", 0, 1000)
		plr:GossipSendMenu(1, unit)
	end
end

RegisterCreatureGossipEvent(NPC_ID, 1, Teleporter_Gossip)
RegisterCreatureGossipEvent(NPC_ID, 2, Teleporter_Event)