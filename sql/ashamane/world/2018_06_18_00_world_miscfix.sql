SET @CGUID := 210119000;

UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '260718';
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '267528'; 
DELETE FROM `gameobject` WHERE `id`=207416;
UPDATE `spell_target_position` SET `MapID` = '730' , `PositionX` = '852.306' , `PositionY` = '1038.92' , `PositionZ` = '-5.3136' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 
UPDATE `spell_target_position` SET `PositionX` = '854' , `PositionY` = '1075' , `PositionZ` = '-11.392230' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 


DELETE FROM `creature` WHERE `id`=43818;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+0, 43818, 646, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1027.85, 516.63, -49.3336, 2.61803, 300, 0, 0, 38640, 8726, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 44839 WHERE `entry` = 44855;
-- Twilight Armsman SAI
SET @ENTRY := 44847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Cleave"),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,79878,2,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Bloodlust at 40% HP");
-- Rockslice Flayer SAI
SET @ENTRY := 42606;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86734,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Flayer Flurry");

DELETE FROM `creature_template_addon` WHERE (`entry`=43032);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (43032, 0, 0, 7, 1, 0, 29266);
DELETE FROM `creature_template_addon` WHERE (`entry`=43048);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (43048, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 44887;
UPDATE `creature_equip_template` SET `ItemID1` = '52840' WHERE `CreatureID` = '44847' AND `ID` = '1'; 

UPDATE `creature_template` SET `gossip_menu_id` = 43036 WHERE `entry` = 43036;


SET @ENTRY := 43036;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,80413,0,0,0,33,43036,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit"),
(@ENTRY,0,1,0,62,0,100,0,43036,0,0,0,33,44207,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature_template_addon` WHERE (`entry`=43036);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (43036, 0, 0, 7, 1, 0, 29266);
UPDATE `creature_template` SET `type_flags` = 0 WHERE `entry` = 43036;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('43036','0','0','Lets Go!','0','1','1','29416');
DELETE FROM `quest_objectives` WHERE `ID` = '267609'; 

DELETE FROM `creature_template_addon` WHERE (`entry`=44768);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44768, 0, 0, 0, 1, 233, '');

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('44768','0','0','You free now!','0','1','1','29416');

SET @ENTRY := 44768;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,44768,0,0,0,33,44772,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
UPDATE `creature_template` SET `gossip_menu_id` = 44768 WHERE `entry` = 44768;

UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 44768;

UPDATE `creature_template` SET `KillCredit1` = 44938 WHERE `entry` = 44936;
DELETE FROM `quest_objectives` WHERE `ID` = '267510'; 

UPDATE `gossip_menu_option` SET `OptionType` = '3' , `OptionNpcFlag` = '128' WHERE `MenuId` = '12014' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' , `OptionNpcFlag` = '128' WHERE `MenuId` = '12014' AND `OptionIndex` = '1'; 


UPDATE `creature_template` SET `npcflag` = 4225 WHERE `entry` = 45363;

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 45364;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (45364);
DELETE FROM `creature_template_addon` WHERE (`entry`=45364);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45364, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags2` = 1 WHERE `entry` = 45364;
DELETE FROM `creature` WHERE `id`=44148;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(298877, 44148, 646, 5042, 5357, 1, 0, 0, 0, -1, 33404, 0, -249.83, 540.993, 266.737, 0, 300, 3, 0, 134037, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+1, 44148, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, -104.591, 451.166, 164.988, 0.674749, 300, 0, 0, 6958, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 44289;

UPDATE `creature_template` SET `KillCredit1` = 44290 WHERE `entry` = 44372;



-- Earthen Geomancer SAI
SET @ENTRY := 43170;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,34828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Water  Shield on Spawn"),
(@ENTRY,0,1,0,16,0,100,0,34828,1,15000,30000,11,34828,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Water  Shield on Repeat"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,79890,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Flame Shock"),
(@ENTRY,0,3,0,62,0,100,0,43170,0,0,0,33,43164,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,4,0,62,0,100,0,43170,1,0,0,33,43165,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,5,0,62,0,100,0,43170,2,0,0,33,43166,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,6,0,62,0,100,0,43170,3,0,0,33,43167,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('43170','0','0','Destroy Entrance!!','0','1','1','29416'),('43170','1','0','Destroy Entrance!!','0','1','1','29416'),('43170','2','0','Destroy Entrance!!','0','1','1','29416'),('43170','3','0','Destroy Entrance!!','0','1','1','29416');
UPDATE `creature_template` SET `KillCredit2` = 43649 WHERE `entry` = 43234;
DELETE FROM `creature` WHERE `id`=43641;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+2, 43641, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1951.39, 1395.02, 181.824, 2.38907, 300, 0, 0, 17835, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature_template` SET `gossip_menu_id` = 43170, `npcflag` = 1, `unit_flags` = 512 WHERE `entry` = 43170;

DELETE FROM `creature` WHERE `id`=43170;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(226614, 43170, 646, 5042, 5350, 1, 0, 0, 0, -1, 26093, 0, 1281.63, 1647.76, 173.181, 0.698132, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226616, 43170, 646, 5042, 5350, 1, 0, 0, 0, -1, 26093, 0, 1282.74, 1643.09, 172.946, 0.802851, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226622, 43170, 646, 5042, 5350, 1, 0, 0, 0, -1, 26093, 0, 1277.67, 1650, 174.123, 0.680678, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226638, 43170, 646, 5042, 5330, 1, 0, 0, 0, -1, 26093, 0, 420.792, 1718.1, 349.576, 0.312717, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226639, 43170, 646, 5042, 5330, 1, 0, 0, 0, -1, 26093, 0, 491.014, 1659.59, 348.37, 1.61631, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226640, 43170, 646, 5042, 5330, 1, 0, 0, 0, -1, 26093, 0, 457.47, 1727.42, 348.597, 5.16318, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226641, 43170, 646, 5042, 5330, 1, 0, 0, 0, -1, 26093, 0, 411.33, 1659.2, 348.967, 6.07376, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226769, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1039.48, 1874.63, 306.479, 5.61024, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226832, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1038.88, 1900.12, 306.753, 5.11106, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226836, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1039.13, 1877.83, 306.772, 5.41091, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226837, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1040.92, 1916.89, 305.724, 6.22446, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226838, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1040.46, 1846.27, 305.001, 0.261689, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226840, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1042.07, 1861.78, 304.83, 1.01538, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226890, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1040.19, 1937.06, 305.263, 0.438878, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226891, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1039.38, 1903.3, 306.538, 0.886676, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226929, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1039.49, 1843.2, 305.274, 3.95058, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(226930, 43170, 646, 5042, 5349, 1, 0, 0, 0, -1, 26093, 0, 1032.05, 1889.63, 307.56, 6.19592, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 43978 WHERE `entry` = 43954;
DELETE FROM `quest_objectives` WHERE `ID` = '251934'; 
UPDATE `creature_template` SET `KillCredit1` = 44126 WHERE `entry` = 44035;

DELETE FROM `creature` WHERE `id`=44352;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+3, 44352, 646, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1483.58, 584.057, -60.2142, 1.43167, 300, 0, 0, 15760, 53448, 0, 0, 0, 0, 0, 0, '', 0),
(315904, 44352, 646, 5042, 5291, 1, 0, 0, 0, -1, 33048, 0, 1392.42, 782.094, -60.0816, 0.546001, 300, 3, 0, 464940, 53448, 1, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 42731 WHERE `entry` = 44352;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 225469;
UPDATE `creature_template` SET `KillCredit2` = 44282 WHERE `entry` = 44259;
UPDATE `creature_template` SET `KillCredit1` = 43038 WHERE `entry` = 42917;


UPDATE `creature_template` SET `gossip_menu_id` = 42468, `faction` = 35, `npcflag` = 3 WHERE `entry` = 42468;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('42468','0','0','Here you Are!','0','1','1','29416');
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42469;
SET @ENTRY := 42468;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,42468,0,0,0,33,44281,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,44282,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Kill Credit");


DELETE FROM `creature` WHERE `id`=42468;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(224189, 42468, 646, 5042, 5292, 1, 0, 0, 0, -1, 19332, 0, 1721.23, 413.283, -84.7024, 5.93412, 300, 0, 0, 2684050, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+4, 42468, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1945.73, 107.015, -155.442, 2.90433, 300, 0, 0, 127395, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=43339;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(228435, 43339, 646, 5042, 5294, 1, 0, 0, 0, -1, 33631, 0, 1904.9, 582.045, 74.311, 2.88074, 300, 3, 0, 134202, 0, 1, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 43172 WHERE `entry` = 42524;
UPDATE `creature_template` SET `KillCredit2` = 43172 WHERE `entry` = 43171;
DELETE FROM `creature` WHERE `id`=43116;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+5, 43116, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1894.5, 723.539, 79.6791, 3.55209, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(373760, 43116, 646, 5042, 5297, 1, 0, 0, 0, -1, 0, 0, 2066.91, -213.324, 54.4594, 2.25011, 600, 5, 0, 53681, 0, 1, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=43116;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+6, 43116, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1894.5, 723.539, 79.6791, 3.55209, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+7, 43116, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1195.09, 1485.95, 38.9893, 2.92299, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(373760, 43116, 646, 5042, 5297, 1, 0, 0, 0, -1, 0, 0, 2066.91, -213.324, 54.4594, 2.25011, 600, 5, 0, 53681, 0, 1, 0, 0, 0, 0, 0, '', 0);   
UPDATE `creature_template` SET `gossip_menu_id` = 42465 WHERE `entry` = 42465;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42465;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 43804;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42467;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42899;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42470;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 43805;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 43806;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 44080;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 44945;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 45408;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 45407;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42472;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 43442;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 44973;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 44025;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42614;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 44124;
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '267436'; 
DELETE FROM `creature` WHERE `id`=43442;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(224181, 43442, 646, 5042, 5300, 1, 0, 0, 0, -1, 33329, 0, 1899.87, -439.658, 174.787, 3.63029, 300, 0, 0, 107362, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+8, 43442, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 981.955, -618.37, 279.519, 5.54416, 300, 0, 0, 35670, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 53744 WHERE `entry` = 53739;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('42465','0','0','I am listening!','0','1','1','29416');
UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 44189;
SET @ENTRY := 3679;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,42465,0,0,0,33,44051,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");
UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 44077;
UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 42824;

DELETE FROM `creature` WHERE `id`=42914;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(316384, 42914, 646, 5042, 5298, 1, 0, 0, 0, -1, 33121, 0, 1715.11, -131.955, 51.7145, 3.35103, 300, 3, 0, 161043, 0, 1, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=44135;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(372968, 44135, 646, 5042, 5298, 1, 0, 0, 0, -1, 0, 0, 1498, -165.312, 55.994, 6.08084, 600, 5, 0, 241564, 0, 1, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=53738;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(293005, 53738, 646, 5042, 5296, 1, 0, 0, 0, -1, 35825, 0, 2370.97, 169.542, 182.12, 0.925025, 300, 0, 0, 77490, 8908, 0, 0, 0, 0, 0, 0, '', 0),
(293011, 53738, 646, 5042, 5797, 1, 0, 0, 0, -1, 35825, 0, 1228.66, -214.576, 21.2041, 3.24631, 300, 0, 0, 77490, 8908, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+9, 53738, 646, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1214.72, -194.834, 19.3491, 4.3342, 300, 0, 0, 18387, 8908, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 43837;
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '43158' AND `Item` = '60816'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '44936' AND `Item` = '60816'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '44988' AND `Item` = '60816'; 
DELETE FROM `creature` WHERE `id`=44080;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+10, 44080, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 966.003, -655.243, 280.095, 0.960591, 300, 0, 0, 127395, 0, 0, 0, 0, 0, 0, 0, '', 0),
(315890, 44080, 646, 5042, 5297, 1, 0, 0, 0, -1, 33482, 0, 1879.44, -142.627, 24.1361, 3.82227, 300, 0, 0, 2684050, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=53736;

-- Mercurial Ooze
SET @ENTRY := 43158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,22000,11,86785,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Seeping Quicksilver'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,86766,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mercurial Absorption at 40% HP');

DELETE FROM `creature` WHERE `id`=43158;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(224872, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 561.896, -771.293, 147.31, 5.49836, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225136, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 492.172, -342.815, 46.7705, 0.531423, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225431, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 388.402, -546.7, 42.3829, 0.554107, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225432, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 444.991, -340.293, 45.2871, 1.49878, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225485, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 476.469, -779.1, 146.076, 0.664097, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225670, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 420.739, -521.15, 43.2145, 5.60416, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225764, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 442.789, -440.529, 44.4369, 2.6282, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225769, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 380.477, -442.582, 41.9291, 3.06736, 300, 0, 0, 37187, 0, 0, 0, 0, 0, 0, 0, '', 0),
(225771, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 447.165, -396.442, 42.1417, 5.01008, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225783, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 422.311, -474.526, 43.8917, 4.47753, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225839, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 550.405, -544.361, 160.329, 4.75509, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225854, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 544.956, -584.058, 158.135, 0.436033, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225867, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 631.803, -697.58, 149.135, 1.36207, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225868, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 544.929, -637.301, 154.731, 5.4977, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225869, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 578.275, -571.875, 155.793, 0.249993, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(225879, 43158, 646, 5042, 5329, 1, 0, 0, 0, -1, 33009, 0, 413.517, -372.249, 42.8762, 5.4164, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226449, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 635.348, -707.968, 149.051, 5.6924, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226453, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 550, -544.058, 160.454, 6.06262, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226465, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 546.46, -583.718, 158.197, 0.958598, 300, 0, 0, 37187, 0, 0, 0, 0, 0, 0, 0, '', 0),
(226468, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 631.407, -699.54, 149.107, 4.43642, 300, 0, 0, 37187, 0, 0, 0, 0, 0, 0, 0, '', 0),
(226470, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 545.555, -636.443, 154.606, 4.89566, 300, 0, 0, 37187, 0, 0, 0, 0, 0, 0, 0, '', 0),
(226471, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 577.775, -572.213, 155.918, 6.24012, 300, 0, 0, 37187, 0, 0, 0, 0, 0, 0, 0, '', 0),
(226473, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 726.131, -724.923, 146.428, 5.54283, 300, 0, 0, 37187, 0, 0, 0, 0, 0, 0, 0, '', 0),
(226495, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 660.406, -546.408, 150.465, 2.70147, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226496, 43158, 646, 5042, 5042, 1, 0, 0, 0, -1, 33009, 0, 788.25, -477.777, 151.689, 5.38286, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226497, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 662.104, -587.558, 148.373, 3.01237, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226501, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 813.941, -515.488, 146.892, 1.08361, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226502, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 771.246, -552.755, 148.167, 3.80158, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226510, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 819.863, -644.271, 146.585, 0, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(226511, 43158, 646, 5042, 5328, 1, 0, 0, 0, -1, 33009, 0, 758.769, -520.464, 147.8, 2.35925, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+11, 43158, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 654.626, -625.381, 146.506, 2.08324, 300, 0, 0, 15327, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+12, 43158, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 583.448, -609.006, 150.813, 6.20187, 300, 0, 0, 16235, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+13, 43158, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 643.781, -600.606, 143.582, 0.766914, 300, 0, 0, 15327, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Maziel <Mercury Ascendant>
SET @ENTRY := 44967;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,22000,11,86810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mercury Rain'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,86766,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mercurial Absorption at 40% HP');
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE `entry` = 42467;
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE `entry` = 42899;

UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42467;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 42899;

DELETE FROM `creature` WHERE `id`=44967;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(226513, 44967, 646, 5042, 5329, 1, 0, 0, 0, -1, 36435, 0, 690.528, -664.16, 9.56898, 2.09439, 300, 3, 0, 89358, 0, 1, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=43442;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+14, 43442, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 981.955, -618.37, 279.519, 5.54416, 300, 0, 0, 35670, 0, 0, 0, 0, 0, 0, 0, '', 0),
(224181, 43442, 646, 5042, 5300, 1, 0, 0, 0, -1, 33329, 0, 1899.87, -439.658, 174.787, 3.63029, 300, 0, 0, 107362, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 44080;
UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26658'; 
UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26659'; 
DELETE FROM `creature` WHERE `id`=44080;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(315890, 44080, 646, 5042, 5297, 1, 0, 0, 0, -1, 33482, 0, 1879.44, -142.627, 24.1361, 3.82227, 300, 0, 0, 2684050, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+15, 44080, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, 966.003, -655.243, 280.095, 0.960591, 300, 0, 0, 127395, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26657'; 
UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26750'; 
UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26584'; 
DELETE FROM `creature` WHERE `id`=54014;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+16, 54014, 861, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1452.01, 340.643, 51.4103, 0.867748, 300, 0, 0, 18387, 8908, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 53926 WHERE `entry` = 53928;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('12943','0','0','I am prepared. Let us go to the Firelands and finish this.','0','1','1','29416');

SET @ENTRY := 53738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12943,0,0,0,62,861,0,0,0,0,0,7,0,0,0,1453.81,354.121,55.5129,0.608567,"Teleport"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,53738,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Despawn");

UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (45303,43036,44768,45364,44289,43170,43952,42900,43101,45305,44078,43388);