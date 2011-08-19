UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry` IN (SELECT `npc_entry` FROM `npc_spellclick_spells`); 

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (32640,32633,31861,31862,25743,27661,27258,27755,27756,27692,40725,32286,29929,29602,29709,27626,28851,
34120,30403,26813,26523,27496,27714,27996,28605,28606,28607,28833,30066,32930,28312,32627,33060,33067,33062,33109,34994,30234,27629,27924,28061,28192,28669,
28670,28817,28864,2914,29460,29679,29918,30468,30470,35064,30585,30645,33217,33319,33321,33519,33844,33845,39714);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(32640,61424,0,0,0,1,0,0,0),  -- Traveler's Tundra Mammoth
(32633,61424,0,0,0,1,0,0,0),  -- Traveler's Tundra Mammoth
(31861,61466,0,0,0,1,0,0,0),  -- Grand Black War Mammoth
(31862,61466,0,0,0,1,0,0,0),  -- Grand Black War Mammoth
(25743,46260,0,0,0,1,0,0,0),  -- Wooly Mammoth Bull
(27661,48365,0,0,0,1,0,0,0),  -- Wintergarde Gryphon
(27258,48365,0,0,0,1,0,0,0),  -- Wintergarde Gryphoworldn
(27755,49460,0,0,0,1,0,0,0),  -- Amber Drake
(27756,49464,0,0,0,1,0,0,0),  -- Ruby Drake
(27692,49346,0,0,0,1,0,0,0),  -- Emerald Drake
(40725,75953,0,0,0,1,0,0,0),  -- X-53 Touring Rocket
(32286,61666,0,0,0,1,0,0,0),  -- Mekgineer's Chopper
(29929,58961,0,0,0,1,0,0,0),  -- Mechano-hog
(29602,54908,0,0,0,1,0,0,0),  -- Icefang
(29709,55029,0,0,0,1,0,0,0),  -- Freed Proto-Drake
(27626,49138,0,0,0,1,0,0,0),  -- Tatjana's Horse
(28851,52600,0,0,0,1,0,0,0),  -- Enraged Mammoth
(34120,55089,0,0,0,1,0,0,0),  -- Brann's Flying Machine
(30403,56699,0,0,0,1,0,0,0),  -- Nergeld
(26813,47424,0,0,0,1,0,0,0),  -- Kor'kron War Rider
(26523,48296,0,0,0,1,0,0,0),  -- Forsaken Blight Spreader
(27496,48881,0,0,0,1,0,0,0),  -- Refurbished Shredder
(27714,49584,0,0,0,1,0,0,0),  -- 7th Legion Chain Gun
(27996,50343,0,0,0,1,0,0,0),  -- Wyrmrest Vanquisher
(28605,52263,0,0,0,1,0,0,0),  -- Havenshire Stallion
(28606,52263,0,0,0,1,0,0,0),  -- Havenshire Mare
(28607,52263,0,0,0,1,0,0,0),  -- Havenshire Colt
(28833,52447,0,0,0,1,0,0,0),  -- Scarlet Cannon
(30066,56678,0,0,0,1,0,0,0),  -- Argent Skytalon
(28312,60968,0,0,0,1,0,0,0),  -- Wintergrasp Siege Engine
(32627,60968,0,0,0,1,0,0,0),  -- Wintergrasp Siege Engine
(33060,65031,0,0,0,1,0,0,0),  -- Salvaged Siege Engine
(33067,65031,0,0,0,1,0,0,0),  -- Salvaged Siege Turret
(33062,65030,0,0,0,1,0,0,0),  -- Salvaged Chopper
(33109,62309,0,0,0,1,0,0,0),  -- Salvaged Demolisher
(34944,68458,0,0,0,1,0,0,0),  -- Keep Cannon
-- These use a 'proxy' cast. They summon a similar creature with SummonProperties.category = 4
(30234,56378,0,0,0,1,0,0,0),  -- Hover Disk
(27629,49207,0,0,0,1,0,0,0),  -- Wyrmrest Defender
(27924,50007,0,0,0,1,0,0,0),  -- Dragonflayer Harpoon
(28061,50557,0,0,0,1,0,0,0),  -- Wintergarde Gryphon
(28192,50860,0,0,0,1,0,0,0),  -- Archmage Pentarus' Flying Machine
(28669,52190,0,0,0,1,0,0,0),  -- Flying Fiend
(28670,53173,0,0,0,1,0,0,0),  -- Frostblood Vanquisher
(28817,52462,0,0,0,1,0,0,0),  -- Mine Car
(28864,52589,0,0,0,1,0,0,0),  -- Scourge Gryphon
(29414,18277,0,0,0,1,0,0,0),  -- Bone Gryphon
(29460,54513,0,0,0,1,0,0,0),  -- Frigit Proto-Drake
(29679,54952,0,0,0,1,0,0,0),  -- Hyldsmeet Proto-Drake
(29918,54301,0,0,0,1,0,0,0),  -- Warbear Matriarch
(30468,56795,0,0,0,1,0,0,0),  -- Harnessed Icemaw Matriarch
(30470,56839,0,0,0,1,0,0,0),  -- Skybreaker Cloudbuster
(30564,57401,0,0,0,1,0,0,0),  -- Njorndar Proto-Drake
(30585,57418,0,0,0,1,0,0,0),  -- Hammerhead
(30645,57612,0,0,0,1,0,0,0),  -- Water Terror
(33217,62774,0,0,0,1,0,0,0),  -- Stormwind Steed
(33319,62782,0,0,0,1,0,0,0),  -- Darnassian Nightsaber
(33321,62784,0,0,0,1,0,0,0),  -- Darkspear Raptor
(33519,63163,0,0,0,1,0,0,0),  -- Black Knight's Gryphon
(33844,63791,0,0,0,1,0,0,0),  -- Sunreaver Hawkstrider
(33845,63792,0,0,0,1,0,0,0),  -- Quel'dorei Steed
(39714,74205,0,0,0,1,0,0,0);  -- Shooting Mechano-Tank
