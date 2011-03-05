DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(28781,27894,32627,32629,28366,28312,28319,28094,27881);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(28781,60683,0,0,0,1,0,0,0),  -- Battleground Demolisher
(27894,60682,0,0,0,1,0,0,0),  -- Antipersonnel Cannon
(32627,60968,0,0,0,1,0,0,0),  -- Wintergrasp Siege Engine
(32629,46598,0,0,0,1,0,0,0),  -- Wintergrasp Siege Turret
(28366,60962,0,0,0,1,0,0,0),  -- Wintergrasp Tower Cannon
(28312,46598,0,0,0,1,0,0,0),  -- Wintergrasp Siege Engine
(28319,46598,0,0,0,1,0,0,0),  -- Wintergrasp Siege Turret
(28094,60968,0,0,0,1,0,0,0),  -- Wintergrasp Demolisher
(27881,60968,0,0,0,1,0,0,0);  -- Wintergrasp Catapult
