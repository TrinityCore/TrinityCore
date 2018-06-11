UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '260718'; 
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '267528'; 
DELETE FROM `gameobject` WHERE `id`=207416;
UPDATE `spell_target_position` SET `MapID` = '730' , `PositionX` = '852.306' , `PositionY` = '1038.92' , `PositionZ` = '-5.3136' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 
UPDATE `spell_target_position` SET `PositionX` = '854' , `PositionY` = '1075' , `PositionZ` = '-11.392230' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 


DELETE FROM `creature` WHERE `id`=43818;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116797, 43818, 646, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1027.85, 516.63, -49.3336, 2.61803, 300, 0, 0, 38640, 8726, 0, 0, 0, 0, 0, 0, '', 0);
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
(210116804, 44148, 646, 0, 0, 1, 0, 0, 0, -1, 0, 0, -104.591, 451.166, 164.988, 0.674749, 300, 0, 0, 6958, 0, 0, 0, 0, 0, 0, 0, '', 0);
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

UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (45303,43036,44768,45364,44289,43170,43952);






































