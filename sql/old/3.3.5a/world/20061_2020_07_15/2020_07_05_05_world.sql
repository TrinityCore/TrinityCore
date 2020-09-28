-- 
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 64793;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(64793,64793,64941,0,0);

-- Boomer XP-500
UPDATE `creature_addon` SET `auras` = "63767" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 34192); -- Bomb Bot

-- Superheated Winds
UPDATE `creature_template_addon` SET `auras` = "64724" WHERE `entry` = 34194; -- Superheated Winds

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (34190,34193,34194,34196,34197,34198,34199,34203,34223);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34190,34193,34194,34196,34197,34198,34199,34203,34223) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Hardened Iron Golem
-- 1 17:45:18.000
-- 1 17:45:21.000 17:45:39.000 17:46:04.000 17:46:21.000 17:46:32.000
(34190,0,0,0,0,0,100,2,3000,3000,11000,25000,0,11,64874,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Hardened Iron Golem - In Combat - Cast 'Rune Punch' (Normal Dungeon)"),
(34190,0,1,0,0,0,100,4,3000,3000,11000,25000,0,11,64967,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Hardened Iron Golem - In Combat - Cast 'Rune Punch' (Heroic Dungeon)"),
-- 1 17:45:27.000 17:45:52.000 17:46:17.000 17:46:44.000
(34190,0,2,0,0,0,100,0,9000,9000,25000,25000,0,11,64877,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hardened Iron Golem - In Combat - Cast 'Harden Fists'"),

-- Clockwork Sapper
(34193,0,0,0,0,0,100,0,5000,9000,10000,15000,0,11,64740,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Clockwork Sapper - In Combat - Cast 'Energy Sap'"),
(34193,0,1,0,0,0,100,0,15000,20000,25000,30000,0,11,64873,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Clockwork Sapper - In Combat - Cast 'Sapper Explosion'"),

-- Superheated Winds
(34194,0,0,0,54,0,100,0,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Superheated Winds - On Just Summoned - Stop Attacking"),

-- Rune Etched Sentry
(34196,0,0,0,0,0,100,2,10000,13000,20000,25000,0,11,64847,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rune Etched Sentry - In Combat - Cast 'Runed Flame Jets' (Normal Dungeon)"),
(34196,0,1,0,0,0,100,4,10000,13000,20000,25000,0,11,64988,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Rune Etched Sentry - In Combat - Cast 'Runed Flame Jets' (Heroic Dungeon)"),
(34196,0,2,0,0,0,100,2,5000,8000,8000,11000,0,11,64870,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Rune Etched Sentry - In Combat - Cast 'Lava Burst' (Normal Dungeon)"),
(34196,0,3,0,0,0,100,4,5000,8000,8000,11000,0,11,64991,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Rune Etched Sentry - In Combat - Cast 'Lava Burst' (Heroic Dungeon)"),
(34196,0,4,0,0,0,100,0,4000,7000,10000,13000,0,11,64852,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Rune Etched Sentry - In Combat - Cast 'Flaming Rune'"),

-- Chamber Overseer
-- 1 17:51:10.000
-- 1 17:51:21.000 17:51:40.000 17:51:57.000 17:52:13.000 17:52:32.000
(34197,0,0,0,0,0,100,2,10000,10000,16000,19000,0,11,64820,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Chamber Overseer - In Combat - Cast 'Devastating Leap' (Normal Dungeon)"),
(34197,0,1,0,0,0,100,4,10000,10000,16000,19000,0,11,64943,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Chamber Overseer - In Combat - Cast 'Devastating Leap' (Heroic Dungeon)"),
-- 1 17:51:19.000 17:51:34.000 17:51:52.000 17:52:10.000 17:52:28.000
(34197,0,2,0,0,0,100,2,9000,9000,15000,22000,0,11,64825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Chamber Overseer - In Combat - Cast 'Stagering Roar' (Normal Dungeon)"),
(34197,0,3,0,0,0,100,4,9000,9000,15000,22000,0,11,64944,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Chamber Overseer - In Combat - Cast 'Stagering Roar' (Heroic Dungeon)"),
-- 1 17:51:25.000 17:51:41.000 17:52:02.000 17:52:22.000
(34197,0,4,0,0,0,100,0,15000,15000,16000,21000,0,11,64783,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Chamber Overseer - In Combat - Cast 'Displacement Device'"),

-- Iron Mender
(34198,0,0,0,1,0,100,2,10000,20000,34000,34000,0,11,64768,0,0,0,0,0,19,34190,20,0,0,0,0,0,0,"Iron Mender - Out of Combat - Cast 'Lightning Channel' (Normal Dungeon)"),
(34198,0,1,0,0,0,100,2,5000,8000,8000,12000,0,11,64918,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Iron Mender - In Combat - Cast 'Electro Shock' (Normal Dungeon)"),
(34198,0,2,0,0,0,100,4,5000,8000,8000,12000,0,11,64971,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Iron Mender - In Combat - Cast 'Electro Shock' (Heroic Dungeon)"),
(34198,0,3,0,0,0,100,2,7000,12000,15000,20000,0,11,64903,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Iron Mender - In Combat - Cast 'Fuse Lightning' (Normal Dungeon)"),
(34198,0,4,0,0,0,100,4,7000,12000,15000,20000,0,11,64970,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Iron Mender - In Combat - Cast 'Fuse Lightning' (Heroic Dungeon)"),
-- Probably used on friends with low HP
(34198,0,5,0,0,0,100,2,10000,15000,20000,30000,0,11,64897,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Mender - In Combat - Cast 'Fuse Metal' (Normal Dungeon)"),
(34198,0,6,0,0,0,100,4,10000,15000,20000,30000,0,11,64968,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Mender - In Combat - Cast 'Fuse Metal' (Heroic Dungeon)"),

-- Lightning Charged Iron Dwarf
(34199,0,0,0,0,0,100,2,8000,12000,60000,65000,0,11,64889,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lightning Charged Iron Dwarf - In Combat - Cast 'Lightning Charged' (Normal Dungeon)"),
(34199,0,1,0,0,0,100,4,8000,12000,30000,35000,0,11,64975,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lightning Charged Iron Dwarf - In Combat - Cast 'Lightning Charged' (Heroic Dungeon)"),

-- Displacement Device
-- Seems like they're supposed to add threat to random targets but in sniffs every time they adds threat to one target
-- More info https://www.youtube.com/watch?v=5lqHdMwXHKM&feature=youtu.be&t=97
(34203,0,0,1,54,0,100,0,0,0,0,0,0,11,64785,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Displacement Device - On Just Summoned - Cast 'Random Lightning Visual'"),
(34203,0,1,2,61,0,100,0,0,0,0,0,0,11,64793,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Displacement Device - On Link - Cast 'Displacement'"),
(34203,0,2,0,61,0,100,0,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Displacement Device - On Link - Stop Attacking"),

-- Sapper Explosion
(34223,0,0,0,54,0,100,0,0,0,0,0,0,11,64875,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sapper Explosion - On Just Summoned - Cast 'Sapper Explosion'"),
(34223,0,1,0,54,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sapper Explosion - On Just Summoned - Set Reactstate Passive"),
(34223,0,2,0,60,0,100,1,5500,5500,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sapper Explosion - On Update - Despawn (5500)");
