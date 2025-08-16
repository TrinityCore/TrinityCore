--
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 3439;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3439 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 343900 AND 343903 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3439,0,0,0,19,0,100,0,863,0,0,0,0,80,343900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Quest 'The Escape' Taken - Run Script"),

(343900,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Store Targetlist"),
(343900,9,1,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Set Faction 113"),
(343900,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Remove NPC Flag Questgiver"),
(343900,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 0"),
(343900,9,4,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 1"),
(343900,9,5,0,0,0,100,0,0,0,0,0,0,53,1,343900,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Start Waypoint"),

(3439,0,1,0,58,0,100,0,0,343900,0,0,0,80,343901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Waypoint Finished - Run Script"),

(343901,9,0,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 2"),
(343901,9,1,0,0,0,100,0,0,0,0,0,0,53,0,343901,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Start Waypoint"),

(3439,0,2,0,58,0,100,0,0,343901,0,0,0,80,343902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Waypoint Finished - Run Script"),

(343902,9,0,0,0,0,100,0,5000,5000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Summon Group 0"),
-- Our ugly hack
(343902,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,3282,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 0 (Venture Co. Mercenary)"),
-- Not entirely correct, more like when both summons are killed
(343902,9,2,0,0,0,100,0,8000,8000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 3"),
(343902,9,3,0,0,0,100,0,3000,3000,0,0,0,53,1,343902,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Start Waypoint"),

(3439,0,3,0,58,0,100,0,0,343902,0,0,0,80,343903,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Waypoint Finished - Run Script"),

(343903,9,0,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 4"),
(343903,9,1,0,0,0,100,0,4000,4000,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 5"),
(343903,9,2,0,0,0,100,0,2000,2000,0,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Say Line 6"),
(343903,9,4,0,0,0,100,0,6000,6000,0,0,0,15,863,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Quest Credit 'The Escape'"),
(343903,9,5,0,0,0,100,0,0,0,0,0,0,11,5162,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Cast 'Self Explosion'"),
-- Summon should be handled by GameEvent from the spell above but it doesn't work
(343903,9,6,0,0,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Summon Group 1"),
(343903,9,7,0,0,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Script - Despawn"),

(3439,0,4,0,6,0,100,0,0,0,0,0,0,6,863,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wizzlecrank's Shredder - On Death - Fail Quest 'The Escape'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3451 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 345100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3451,0,0,0,11,0,100,0,0,0,0,0,0,80,345100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pilot Wizzlecrank - On Spawn - Run Script"),

(345100,9,0,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,1011.5695,-2948.5574,94.42255,0,"Pilot Wizzlecrank - On Script - Move To Position"),
(345100,9,1,0,0,0,100,0,1500,1500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pilot Wizzlecrank - On Script - Say Line 0"),
(345100,9,2,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pilot Wizzlecrank - On Script - Say Line 1"),
-- Guessed
(345100,9,3,0,0,0,100,0,20000,20000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pilot Wizzlecrank - On Script - Despawn");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 3439 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(3439,0,0,3282,1075.1216,-2983.9827,92.90724,5.811946392059326171,4,60000,"Wizzlecrank's Shredder - Group 0 - Venture Co. Mercenary"),
(3439,0,0,3282,1119.6910,-2970.8733,97.15814,4.014257431030273437,4,60000,"Wizzlecrank's Shredder - Group 0 - Venture Co. Mercenary"),

(3439,0,1,3451,1014.9248,-2945.6086,94.50288,2.114160060882568359,8,0,"Wizzlecrank's Shredder - Group 1 - Pilot Wizzlecrank");

DELETE FROM `script_waypoint` WHERE `entry` = 3439;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 343900 AND 343902;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
-- There only 4 waypoints at start but without adding all points we get too short path
(343900,1,1107.5569,-3102.9243,82.8109,"Wizzlecrank's Shredder"),
(343900,2,1106.3069,-3105.4243,83.0609,"Wizzlecrank's Shredder"),
(343900,3,1109.0569,-3106.9243,82.8109,"Wizzlecrank's Shredder"),
(343900,4,1110.8069,-3104.6743,82.5609,"Wizzlecrank's Shredder"),
(343900,5,1108.4622,-3101.7402,82.21095,"Wizzlecrank's Shredder"), --
(343900,6,1111.0613,-3104.9868,82.52319,"Wizzlecrank's Shredder"),
(343900,7,1108.8113,-3101.7368,82.52319,"Wizzlecrank's Shredder"),
(343900,8,1105.0613,-3102.9868,83.02319,"Wizzlecrank's Shredder"),
(343900,9,1104.5613,-3103.2368,83.02319,"Wizzlecrank's Shredder"),
(343900,10,1109.3113,-3103.7368,82.52319,"Wizzlecrank's Shredder"),
(343900,11,1113.4314,-3104.049,82.46095,"Wizzlecrank's Shredder"), --
(343900,12,1104.9719,-3103.0159,83.22392,"Wizzlecrank's Shredder"),
(343900,13,1104.4719,-3103.2659,83.22392,"Wizzlecrank's Shredder"),
(343900,14,1109.2219,-3103.7659,82.72392,"Wizzlecrank's Shredder"),
(343900,15,1113.4719,-3104.0159,82.97392,"Wizzlecrank's Shredder"),
(343900,16,1113.4719,-3107.0159,82.97392,"Wizzlecrank's Shredder"),
(343900,17,1106.7219,-3108.2659,83.22392,"Wizzlecrank's Shredder"),
(343900,18,1106.2535,-3108.632,83.08595,"Wizzlecrank's Shredder"), --
(343900,19,1113.3845,-3104.1714,82.82361,"Wizzlecrank's Shredder"),
(343900,20,1113.3845,-3106.9214,82.82361,"Wizzlecrank's Shredder"),
(343900,21,1106.8845,-3108.4214,83.32361,"Wizzlecrank's Shredder"),
(343900,22,1106.3845,-3108.4214,83.32361,"Wizzlecrank's Shredder"),
(343900,23,1101.6771,-3104.3665,83.21095,"Wizzlecrank's Shredder"), --

(343901,1,1101.3541,-3096.9792,83.0092,"Wizzlecrank's Shredder"),
(343901,2,1098.4445,-3060.212,82.08001,"Wizzlecrank's Shredder"),
(343901,3,1090.5764,-3034.908,82.70501,"Wizzlecrank's Shredder"),
(343901,4,1103.0762,-3013.2773,85.65292,"Wizzlecrank's Shredder"),
(343901,5,1100.8525,-3002.5137,89.65292,"Wizzlecrank's Shredder"),
(343901,6,1093.6041,-2977.8281,92.21579,"Wizzlecrank's Shredder"),

(343902,1,1068.5104,-2980.486,93.59079,"Wizzlecrank's Shredder"),
(343902,2,1070.0381,-2957.5312,93.54168,"Wizzlecrank's Shredder"),
(343902,3,1042.0365,-2964.448,93.29168,"Wizzlecrank's Shredder"),
(343902,4,1037.1163,-2938.5747,91.91668,"Wizzlecrank's Shredder"),
(343902,5,1014.908,-2943.962,94.54755,"Wizzlecrank's Shredder");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3282 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3282,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Venture Co. Mercenary - On Just Summoned - Start Attack");
