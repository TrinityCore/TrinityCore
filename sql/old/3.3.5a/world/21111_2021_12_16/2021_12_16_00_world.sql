--
DELETE FROM `spell_script_names` WHERE `spell_id` = 35491 AND `ScriptName` = 'spell_gen_furious_rage';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(35491,'spell_gen_furious_rage');

-- Gor Grimgut
-- Revert change to WDB, 0 in 2011, 0 in sniff, otherwise despawns on its own and not like in sniff, breaks script.
-- It allows to summon him twice, yes
UPDATE `gameobject_template` SET `Data5` = 0 WHERE `entry` = 184729;

UPDATE `event_scripts` SET `delay` = 0, `Comment` = "Event (Object 'The Thunderspike' (184729)) - On Event - Summon Creature 'Gor Grimgut'" WHERE `id` = 13685;

UPDATE `creature_template` SET `unit_flags` = 256 WHERE `entry` = 21319;

DELETE FROM `creature_text` WHERE `CreatureID` = 21319;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21319,0,0,"Puny $r cannot lift spear.  Gor lift spear!",12,0,100,0,0,0,18980,0,"Gor Grimgut"),
(21319,1,0,"Hah!  The Thunderspike is mine.  Die!",12,0,100,0,0,0,18979,0,"Gor Grimgut");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 21319 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2131900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21319,0,0,0,11,0,100,0,0,0,0,0,0,80,2131900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gor Grimgut - On Spawn - Run Script"),
(21319,0,1,0,4,0,100,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Gor Grimgut - On Aggro - Say Line 1"),
(21319,0,2,0,0,0,100,0,10000,15000,15000,25000,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gor Grimgut - In Combat - Cast 'Furious Rage'"),

(2131900,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Gor Grimgut - On Script - Say Line 0"),
(2131900,9,1,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,20,184729,0,0,0,0,0,0,0,"Gor Grimgut - On Script - Set Orientation Closest Gameobject 'The Thunderspike'"),
(2131900,9,2,0,0,0,100,0,0,0,0,0,0,71,0,1,30440,0,0,0,1,0,0,0,0,0,0,0,0,"Gor Grimgut - On Script - Set Mainhand Item"),
(2131900,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,184729,0,0,0,0,0,0,0,"Gor Grimgut - On Script - Despawn Closest Gameobject 'The Thunderspike'"),
(2131900,9,4,0,0,0,100,0,1000,1000,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gor Grimgut - On Script - Set ImmunePC Off"),
(2131900,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Gor Grimgut - On Script - Start Attack Summoner");

-- Gurn Grubnosh
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 20116;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20116 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20116,0,0,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Gurn Grubnosh - On Aggro - Say Line 0"),
(20116,0,1,0,0,0,100,0,10000,15000,15000,25000,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gurn Grubnosh - In Combat - Cast 'Furious Rage'");

DELETE FROM `creature_text` WHERE `CreatureID` = 20116;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(20116,0,0,"I'll crush you!",12,0,100,0,0,0,1925,0,"Gurn Grubnosh"),
(20116,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gurn Grubnosh"),
(20116,0,2,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1927,0,"Gurn Grubnosh");

-- Captain Krosh
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18992;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18992 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18992,0,0,0,0,0,100,0,10000,15000,15000,25000,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Krosh - In Combat - Cast 'Furious Rage'");

-- Captain Bo'kar
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 20442;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20442 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20442,0,0,0,0,0,100,0,10000,15000,15000,25000,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Bo'kar - In Combat - Cast 'Furious Rage'");

-- Boulder'mok Chieftain
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21048;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21048 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21048,0,0,0,0,0,100,0,7000,10000,8000,14000,0,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Boulder'mok Chieftain - In Combat - Cast 'Thunderclap'"),
(21048,0,1,0,0,0,100,0,10000,15000,15000,25000,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Boulder'mok Chieftain - In Combat - Cast 'Furious Rage'");

-- Overseer Azarad
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 20685;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20685 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20685,0,0,0,0,0,100,0,5000,10000,15000,20000,0,11,33804,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Overseer Azarad - In Combat - Cast 'Flame Wave'"),
(20685,0,1,0,0,0,100,0,10000,15000,15000,25000,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Overseer Azarad - In Combat - Cast 'Furious Rage'");
