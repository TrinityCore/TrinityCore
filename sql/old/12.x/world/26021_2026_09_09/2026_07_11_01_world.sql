--
SET @CGUID := 147461; -- 5
SET @SPAWN_GROUP_ID := 360; -- 5

-- The Maker
UPDATE `creature` SET `position_x` = 328.87615966796875, `position_y` = 129.2959747314453125, `position_z` = 9.618954658508300781, `orientation` = 0.343603879213333129, `wander_distance` = 5, `MovementType` = 1 WHERE `id` = 17381;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17416 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17416,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Orc Captive - On AI Initialize - Set Reactstate Passive");

UPDATE `creature_template` SET `unit_flags` = 33587200, `AIName` = 'SmartAI' WHERE `entry` = 17416;
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 33587200 WHERE `entry` = 18613;
UPDATE `creature_template_difficulty` SET `PickPocketLootID` = 0 WHERE `Entry` = 17416;

DELETE FROM `pickpocketing_loot_template` WHERE `Entry` = 17416;
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` = 17416;

-- Keli'dan the Breaker
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 32768 WHERE `entry` IN (17377,18607);

UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 18620;

DELETE FROM `creature_text` WHERE `CreatureID` = 17653 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17653,1,0,"We are the true Horde!",12,0,100,0,0,0,16697,0,"Shadowmoon Channeler"),
(17653,1,1,"For Kargath!  For Victory!",12,0,100,0,0,0,16698,0,"Shadowmoon Channeler"),
(17653,1,2,"Gakarah ma!",12,0,100,0,0,0,16699,0,"Shadowmoon Channeler"),
(17653,1,3,"The blood is our power! ",12,0,100,0,0,0,16700,0,"Shadowmoon Channeler"),
(17653,1,4,"Lok'tar Illadari!\n",12,0,100,0,0,0,16701,0,"Shadowmoon Channeler"),
(17653,1,5,"This world is OURS!",12,0,100,0,0,0,16702,0,"Shadowmoon Channeler"),
(17653,1,6,"Lok narash!",12,0,100,0,0,0,16703,0,"Shadowmoon Channeler");

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curHealthPct`,`MovementType`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
-- 0xF1300044F5025739 > 0xF1300044F502573B KelidansShadowmoonChanneler1 > KelidansShadowmoonChanneler4
(@CGUID+0,17653,542,0,0,'1,2',0,0,0,301.98758,-86.74652,-24.451654,0.157079637050628662,43200,0,0,100,0,'','KelidansShadowmoonChanneler1',11159),
-- 0xF1300044F502573D > 0xF1300044F502573A KelidansShadowmoonChanneler2 > KelidansShadowmoonChanneler3
(@CGUID+1,17653,542,0,0,'1,2',0,0,0,316.27365,-108.8766,-24.60271,1.256637096405029296,43200,0,0,100,0,'','KelidansShadowmoonChanneler2',11159),
-- 0xF1300044F502573A > 0xF1300044F502573C KelidansShadowmoonChanneler3 > KelidansShadowmoonChanneler5
(@CGUID+2,17653,542,0,0,'1,2',0,0,0,320.75,-63.61208,-24.636091,4.886921882629394531,43200,0,0,100,0,'','KelidansShadowmoonChanneler3',11159),
-- 0xF1300044F502573B > 0xF1300044F502573D KelidansShadowmoonChanneler4 > KelidansShadowmoonChanneler2
(@CGUID+3,17653,542,0,0,'1,2',0,0,0,345.84842,-74.45591,-24.640242,3.59537816047668457,43200,0,0,100,0,'','KelidansShadowmoonChanneler4',11159),
-- 0xF1300044F502573C > 0xF1300044F5025739 KelidansShadowmoonChanneler5 > KelidansShadowmoonChanneler1
(@CGUID+4,17653,542,0,0,'1,2',0,0,0,343.58386,-103.63059,-24.568823,2.356194496154785156,43200,0,0,100,0,'','KelidansShadowmoonChanneler5',11159);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+4 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,@CGUID+0),
(@SPAWN_GROUP_ID+1,0,@CGUID+1),
(@SPAWN_GROUP_ID+2,0,@CGUID+2),
(@SPAWN_GROUP_ID+3,0,@CGUID+3),
(@SPAWN_GROUP_ID+4,0,@CGUID+4);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+4;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Blood Furnace - Shadowmoon Channeler 000",4),
(@SPAWN_GROUP_ID+1,"Blood Furnace - Shadowmoon Channeler 001",4),
(@SPAWN_GROUP_ID+2,"Blood Furnace - Shadowmoon Channeler 002",4),
(@SPAWN_GROUP_ID+3,"Blood Furnace - Shadowmoon Channeler 003",4),
(@SPAWN_GROUP_ID+4,"Blood Furnace - Shadowmoon Channeler 004",4);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+0;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+0,@CGUID+0,0,0,3,0,0),
(@CGUID+0,@CGUID+1,0,0,3,0,0),
(@CGUID+0,@CGUID+2,0,0,3,0,0),
(@CGUID+0,@CGUID+3,0,0,3,0,0),
(@CGUID+0,@CGUID+4,0,0,3,0,0);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_kelidan_the_breaker_burning_nova';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30940, 'spell_kelidan_the_breaker_burning_nova');
