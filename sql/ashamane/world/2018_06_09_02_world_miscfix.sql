SET @CGUID := 210118235;

UPDATE `creature_template` SET `gossip_menu_id` = 1750, `npcflag` = 3 WHERE `entry` = 1750;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('1750','0','0','I am ready to GO!','0','1','1','29416');

SET @ENTRY := 1750;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,1750,0,0,0,33,55567,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


DELETE FROM `creature` WHERE `id`=66292;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(10645862, 66292, 870, 5785, 6516, 1, 0, 0, 0, -1, 0, 0, -463.317, -1904.94, 53.5756, 1.26051, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '', 0),
(10646285, 66292, 870, 5785, 5853, 1, 0, 0, 0, -1, 0, 0, -664.501, -1485.42, 0.272252, 4.44604, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+1, 66292, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -8454.1, 1375.32, 139.892, 0.197222, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `gossip_menu_id` = 66292, `npcflag` = 3 WHERE `entry` = 66292;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('66292','0','0','I am ready to GO!','0','1','1','29416');

SET @ENTRY := 66292;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,66292,0,0,0,33,66292,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,20,0,100,0,29548,0,0,0,62,870,0,0,0,0,0,7,0,0,0,-464.317,-1904.94,54.5756,1.26051,'Teleport on Quest End');
DELETE FROM `quest_objectives` WHERE `ID` = '269363'; 


DELETE FROM `quest_objectives` WHERE `ID` = '269137'; 
DELETE FROM `quest_objectives` WHERE `ID` = '269138'; 
UPDATE `quest_objectives` SET `Amount` = '10' WHERE `ID` = '269135'; 
UPDATE `creature_template` SET `KillCredit1` = 66398 WHERE `entry` = 66282;
UPDATE `creature_template` SET `KillCredit1` = 66398 WHERE `entry` = 66290;


DELETE FROM `creature` WHERE `id`=15187;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20548900, 15187, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -8335.77, 290.446, 156.832, 4.77213, 300, 0, 0, 5534, 3994, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+2, 15187, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -8317.97, 292.232, 156.834, 3.86346, 300, 0, 0, 15117, 3994, 0, 0, 0, 0, 0, 0, '', 0);

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('15187','0','0','Could you, please, send me to Moonglade, Emissary?','0','1','1','29416');
UPDATE `creature_template` SET `gossip_menu_id` = 15187 WHERE `entry` = 15187;
SET @ENTRY := 15187;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,15187,0,0,0,62,1,0,0,0,0,0,7,0,0,0,7802.04,-2430.96,488.675,0.296706,"Teleport"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,15,27726,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Teleport");


UPDATE `creature_template` SET `gossip_menu_id` = 15187, `npcflag` = 3 WHERE `entry` = 39865;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('39865','0','0','Could you, please, send me to Hyjal?','0','1','1','29416');
UPDATE `creature_template` SET `gossip_menu_id` = 39865 WHERE `entry` = 39865;
SET @ENTRY := 39865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,39865,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5491.67,-3563.56,1570.33,2.11185,"Teleport");



-- Baron Geddon SAI
SET @ENTRY := 40147;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15800,18300,11,74813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Inferno on Close"),
(@ENTRY,0,1,1,8,0,100,0,75192,0,0,0,33,40147,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");
DELETE FROM `creature` WHERE `id`=50070;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(293666, 50070, 1, 616, 4990, 1, 0, 0, 0, -1, 33386, 0, 4881.49, -2804.94, 1437.75, 5.51524, 300, 0, 0, 37187, 8162, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `quest_objectives` WHERE `ID` = '266276';
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 38917;
DELETE FROM `quest_objectives` WHERE `ID` = '265937'; 
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=38917; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=38917; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=38917; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=38917);



UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=41006; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=41006; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=41006; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=41006);


DELETE FROM `creature_template_addon` WHERE (`entry`=41006);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (41006, 0, 0, 0, 257, 426, '');



-- Crucible of Earth SAI
SET @ENTRY := 39737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,512,0,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"On gossip hello close gossip - Quest 25303"),
(@ENTRY,0,1,2,64,0,100,512,0,0,0,0,11,74288,2,18,35,0,0,1,0,0,0,0,0,0,0,"On gossip hello give credit - Quest 25303"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,33,39741,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

-- Crucible of Water SAI
SET @ENTRY := 39738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,512,0,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"On gossip hello close gossip - Quest 25303"),
(@ENTRY,0,1,2,64,0,100,512,0,0,0,0,11,74292,2,18,35,0,0,1,0,0,0,0,0,0,0,"On gossip hello give credit - Quest 25303"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,33,39740,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

-- Crucible of Fire SAI
SET @ENTRY := 39730;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,512,0,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"On gossip hello close gossip - Quest 25303"),
(@ENTRY,0,1,2,64,0,100,512,0,0,0,0,11,74287,2,18,35,0,0,1,0,0,0,0,0,0,0,"On gossip hello give credit - Quest 25303"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,33,39727,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

-- Crucible of Air SAI
SET @ENTRY := 39736;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,512,0,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"On gossip hello close gossip - Quest 25303"),
(@ENTRY,0,1,2,64,0,100,512,0,0,0,0,11,74290,2,18,35,0,0,1,0,0,0,0,0,0,0,"On gossip hello give credit - Quest 25303"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,33,39739,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,3,0,64,0,100,0,0,0,0,0,12,39756,6,180000,0,0,0,8,0,0,0,5007.78,-2030.27,1270.89,0.4474,"On gossip hello summon creature - Quest 25303"),
(@ENTRY,0,4,0,64,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,9,39756,1,30,0,0,0,0,"");


UPDATE `creature_template` SET `npcflag` = 3, `rank` = 0, `type` = 1 WHERE `entry` = 39622;
DELETE FROM `creature` WHERE `id`=39622;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+3, 39622, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 5130.97, -2306.4, 1280.83, 0.181265, 300, 0, 0, 2626, 0, 0, 16777218, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=39627;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+4, 39627, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 5165.56, -2270.54, 1278.79, 6.08669, 300, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 39622;
UPDATE `creature_template` SET `VehicleId` = 0 WHERE `entry` = 39622;
replace INTO `creature_queststarter` (`id`,`quest`) VALUES ('39432','25279'),('39432','25617'),('41504','25843'); 
replace INTO `creature_questender` (`id`,`quest`) VALUES ('39432','25272'),('39432','25355'); 



SET @ENTRY := 39622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25617,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5009.08,-2044.73,1149.06,5,'Teleport on Quest Add');


SET @ENTRY := 39627;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25618,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5009.08,-2044.73,1149.06,5,'Teleport on Quest Add');

SET @ENTRY := 39433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25623,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5009.08,-2044.73,1149.06,5,'Teleport on Quest Add');


SET @ENTRY := 39432;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25624,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5009.08,-2044.73,1149.06,5,'Teleport on Quest Add');



SET @ENTRY := 40834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25611,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5309.59,-2208.87,1263.78,2.28638,'Teleport on Quest Add'),
(@ENTRY,0,1,0,19,0,100,0,25612,0,0,0,62,1,0,0,0,0,0,7,0,0,0,5297.53,-2210.84,1263.78,1.32645,'Teleport on Quest Add');

DELETE FROM `creature` WHERE `id`=39640;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(10656189, 39640, 1, 616, 4988, 1, 0, 0, 0, -1, 0, 0, 5044.72, -2082.93, 1274.31, 3.58247, 300, 0, 0, 5534, 0, 0, 0, 0, 0, 0, 0, '', 0),
(10656540, 39640, 1, 616, 4988, 1, 0, 0, 0, -1, 0, 0, 5044.74, -2083.5, 1274.35, 4.23408, 300, 0, 0, 5534, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+5, 39640, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 5040.31, -2018.62, 1271.13, 3.64905, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=39640; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=39640; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=39640; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=39640);
DELETE FROM `creature_template_addon` WHERE (`entry`=39640);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (39640, 0, 0, 1, 4097, 0, '');


UPDATE `creature_template` SET `KillCredit1` = 39808 WHERE `entry` = 39642;
UPDATE `creature_template` SET `KillCredit2` = 39808 WHERE `entry` = 39643;
DELETE FROM `creature` WHERE `id`=39858;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(284439, 39858, 1, 616, 5019, 1, 0, 0, 0, -1, 31605, 0, 4422.33, -2080.43, 1211.12, 5.65487, 300, 0, 0, 115954, 9470, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+6, 39858, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 5147.7, -1757.21, 1334.97, 0.53594, 300, 0, 0, 3926, 9470, 0, 0, 0, 0, 0, 0, '', 0),
(10613680, 39858, 1, 616, 4989, 1, 0, 0, 0, -1, 0, 0, 5125.25, -1758.53, 1334.55, 3.42085, 300, 0, 0, 13735, 9470, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=39858; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=39858; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=39858; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=39858);

UPDATE `creature_template` SET `gossip_menu_id` = 40056, `npcflag` = 3 WHERE `entry` = 40056;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('40056','0','0','Please help us!','0','1','1','29416');
DELETE FROM `creature` WHERE `id`=40056;
SET @ENTRY := 40056;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,40056,0,0,0,33,40056,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=39933; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=39933; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=39933; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=39933);

DELETE FROM `quest_objectives` WHERE `ID` = '252751'; 
UPDATE `creature_template` SET `KillCredit1` = 40099 WHERE `entry` = 39974;
SET @ENTRY := 39933;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,11316,0,0,0,33,40056,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,62,0,100,512,11316,0,0,0,11,74722,0,0,0,0,0,7,0,0,0,0,0,0,0,""),
(@ENTRY,0,2,0,62,0,100,0,11316,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"");


UPDATE `creature_template` SET `gossip_menu_id` = 39999, `npcflag` = 1 WHERE `entry` = 39999;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('39999','0','0','Save Him!','0','1','1','29416');

SET @ENTRY := 39999;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,39999,0,0,0,33,40031,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

-- Flame Terror
SET @ENTRY := 52219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77508,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');
replace INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('40340', '54745', '1'); 
-- Core Hound
SET @ENTRY := 46910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,87356,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Breath');
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 52176;
-- Brimstone Destroyer
SET @ENTRY := 52794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,1,0,9,0,100,0,0,45,15000,25000,11,75024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rush of Flame on Close');
DELETE FROM `creature` WHERE `id`=52557;
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '46910' AND `Item` = '54609'; 
UPDATE `creature_template` SET `KillCredit1` = 40544, `KillCredit2` = 40545 WHERE `entry` = 40551;
UPDATE `creature_template` SET `KillCredit1` = 40461, `KillCredit2` = 40462 WHERE `entry` = 46925;

DELETE FROM `creature` WHERE `id`=41003;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+23, 41003, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 4435.19, -2081.94, 1205.95, 5.85987, 300, 0, 0, 16235, 4169, 0, 0, 0, 0, 0, 0, '', 0),
(285696, 41003, 1, 616, 4990, 1, 0, 0, 0, -1, 32251, 0, 4895.39, -2803.11, 1437.76, 2.61799, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `quest_objectives` WHERE `ID` = '254075'; 
SET @ENTRY := 41003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25810,0,0,0,62,1,0,0,0,0,0,7,0,0,0,4605.25,-2510.36,828.833,3.94444,'Teleport on Quest Add');


UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 39835;

UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` in (39835);

DELETE FROM `creature` WHERE `id`=39835;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+7, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4549.79, -2540.49, 826.03, 6.22524, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+8, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4543.92, -2554.92, 828.165, 6.22524, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+9, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4557.98, -2566.8, 828.748, 1.05654, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+10, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4561.24, -2581.06, 829.648, 0.797354, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+11, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4574.83, -2577.24, 829.64, 1.54427, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+12, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4591.36, -2567.1, 826.869, 3.16533, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+13, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4592.9, -2588.28, 828.198, 1.80816, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+14, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4604.03, -2593.17, 827.667, 2.10504, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+15, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4612.7, -2583.81, 826.406, 3.01532, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+16, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4619.23, -2594.16, 826.478, 1.97388, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@CGUID+17, 39835, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 4622.49, -2592.26, 825.729, 2.0642, 300, 3, 0, 15327, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299495, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4614.61, -2446.05, 746.808, 3.96968, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299501, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4593.14, -2386.43, 804.154, 0.458206, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299503, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4625.12, -2416.68, 812.276, 1.41607, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299505, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4660.38, -2365.65, 769.855, 3.24437, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299543, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4743.86, -2523.7, 681.62, 2.64682, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299617, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4707.02, -2498.42, 838.618, 1.86034, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299622, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4682.69, -2451.38, 703.391, 6.24548, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299624, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4717.31, -2440.71, 729.093, 4.92607, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299627, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4641.96, -2434.1, 780.159, 0.305067, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299629, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4730.79, -2381.3, 756.567, 4.46338, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299632, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4711.08, -2407.69, 814.326, 1.28471, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299634, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4719.84, -2397.11, 706.612, 3.99618, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299636, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4709.36, -2498.12, 745.621, 4.1822, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299638, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4653.7, -2523.16, 793.214, 1.54523, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299640, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4744.31, -2486.23, 745.621, 2.81037, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299642, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4662.97, -2502.79, 703.391, 2.45251, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299645, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4691.92, -2350.07, 706.612, 0.0692019, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299647, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4719.13, -2350.19, 756.567, 5.54955, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299649, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4667.39, -2364.04, 769.855, 3.4831, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299651, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4624.81, -2418.29, 812.276, 1.37194, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299653, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4639.39, -2433.97, 780.159, 0.377156, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299655, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4696.45, -2408.11, 706.612, 3.11717, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299657, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4666.99, -2364.19, 769.855, 3.4653, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299659, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4709.46, -2497.95, 745.621, 4.17592, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299661, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4657.34, -2539.03, 793.214, 2.03379, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299665, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4669.86, -2476.95, 838.618, 3.45647, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299667, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4617.29, -2429.95, 780.159, 5.72586, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0),
(299669, 39835, 1, 616, 5050, 1, 0, 0, 0, -1, 31966, 0, 4773.48, -2445.9, 729.093, 1.22928, 300, 3, 0, 37187, 0, 1, 0, 0, 0, 0, 0, '', 0);
UPDATE `quest_objectives` SET `ObjectID` = '39835' , `Amount` = '10' WHERE `ID` = '266244'; 
UPDATE `creature_template` SET `KillCredit1` = 40660 WHERE `entry` = 39835;

SET @ENTRY := 40578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25832,0,0,0,62,1,0,0,0,0,0,7,0,0,0,4837.35,-2812.55,1444.61,0,'Teleport on Quest Add');

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=41308; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=41308; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=41308; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=41308);
DELETE FROM `creature` WHERE `id`=41006;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(285642, 41006, 1, 616, 4990, 1, 0, 0, 0, -1, 32254, 0, 4909.09, -2719.22, 1438.96, 0.235444, 300, 0, 0, 44679, 8338, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+18, 41006, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 4195.98, -2323.49, 1149.13, 3.07319, 300, 0, 0, 16235, 4169, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature` SET `phaseId`=0 WHERE `id`=41300; 
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=41300; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=41300; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=41300; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=41300);
DELETE FROM `creature` WHERE `id`=52300;
SET @ENTRY := 41300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,77394,0,0,0,33,41310,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");



UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 52300;
UPDATE `creature_template` SET `minlevel` = 5, `maxlevel` = 5, `rank` = 0, `unit_flags` = 32768, `dynamicflags` = 1 WHERE `entry` = 52300;

SET @ENTRY := 52300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,96693,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Fireball'),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,10000,22000,11,15616,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');

DELETE FROM `creature` WHERE `id`=52300;

DELETE FROM `creature` WHERE `id`=41224;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+19, 41224, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3962.28, -2240.37, 1135.59, 0.501004, 300, 0, 0, 3546, 0, 0, 16777216, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `spell1` = 0, `spell2` = 0 WHERE `entry` = 52300;
DELETE FROM `creature` WHERE `id`=41261;
-- Twilight Juggernaut SAI
SET @ENTRY := 41031;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,77224,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Armor Plating on Spawn"),
(@ENTRY,0,1,1,8,0,100,0,77231,0,0,0,28,77224,0,0,0,0,0,0,0,0,0,0,0,0,0,"on Spell Hit - Remove Aura");
UPDATE `creature_template` SET `KillCredit1` = 41218 WHERE `entry` = 41226;
UPDATE `creature_template` SET `KillCredit1` = 41031 WHERE `entry` = 41029;

DELETE FROM `creature` WHERE `id`=52300;

DELETE FROM `creature` WHERE `id`=50080;

SET @ENTRY := 41255;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78129,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,78143,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Breath'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,78160,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Fissure');

DELETE FROM `quest_objectives` WHERE `ID` = '266474'; 


DELETE FROM `creature_template_addon` WHERE (`entry`=41499);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (41499, 0, 0, 0, 1, 0, 84063); 


SET @ENTRY := 41499;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,11524,0,0,0,33,41510,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");

UPDATE `creature_template` SET `gossip_menu_id` = 11524 WHERE `entry` = 41499;

DELETE FROM `creature` WHERE `id`=39858;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+24, 39858, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 5147.7, -1757.21, 1334.97, 0.53594, 300, 0, 0, 3926, 9470, 0, 0, 0, 0, 0, 0, '', 0),
(284439, 39858, 1, 616, 5019, 1, 0, 0, 0, -1, 31605, 0, 4422.33, -2080.43, 1211.12, 5.65487, 300, 0, 0, 115954, 9470, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `unit_flags` = 33280 WHERE `entry` = 41504;



SET @ENTRY := 41504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25906,0,0,0,62,1,0,0,0,0,0,7,0,0,0,4678.29,-3658.86,696.786,5.53269,'Teleport on Quest Add');

SET @ENTRY := 41504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25906,0,0,0,62,1,0,0,0,0,0,7,0,0,0,4678.29,-3658.86,696.786,5.53269,'Teleport on Quest Add');

SET @ENTRY := 41498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25928,0,0,0,62,1,0,0,0,0,0,7,0,0,0,4475.76,-2707.74,1101.39,4.5204,'Teleport on Quest Add');

UPDATE `creature_template` SET `KillCredit1` = 41602 WHERE `entry` = 41565;

DELETE FROM `creature_template_addon` WHERE (`entry`=39453);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (39453, 0, 0, 0, 1, 0, 84063);

DELETE FROM `creature` WHERE `id`=40575;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 40434;
UPDATE `creature_template` SET `KillCredit1` = 39673 WHERE `entry` = 39658;
DELETE FROM `gameobject` WHERE `id`=202952;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013418, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4697.09, -4362, 899.002, 2.96108, 0, 0, -0.99593, -0.0901347, 300, 255, 1, 0, '', 0),
(178918, 202952, 1, 616, 4991, 1, 0, 0, 0, -1, 4408.25, -4033.29, 961.206, 0, 0, 0, 0, 1, 300, 255, 1, 0, '', 0),
(178919, 202952, 1, 616, 4991, 1, 0, 0, 0, -1, 4366.48, -4243.95, 919.674, 0, 0, 0, 0, 1, 300, 255, 1, 0, '', 0),
(178975, 202952, 1, 616, 4991, 1, 0, 0, 0, -1, 4406.88, -4102.88, 949.371, 0, 0, 0, 0, 1, 300, 255, 1, 0, '', 0),
(51013419, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4727.24, -4362.98, 898.027, 0.219252, 0, 0, -0.109407, -0.993997, 300, 255, 1, 0, '', 0),
(51013420, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4751.51, -4346.46, 900.513, 0.978732, 0, 0, -0.470067, -0.882631, 300, 255, 1, 0, '', 0),
(51013421, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4726.64, -4302.57, 895.591, 3.12444, 0, 0, -0.999963, -0.00857553, 300, 255, 1, 0, '', 0),
(51013422, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4690.11, -4302.63, 900.879, 3.84465, 0, 0, -0.938847, 0.344334, 300, 255, 1, 0, '', 0),
(51013423, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4654.38, -4297.58, 901.963, 2.37439, 0, 0, -0.927322, -0.374264, 300, 255, 1, 0, '', 0),
(51013424, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4628.63, -4281.85, 902.954, 2.86212, 0, 0, -0.990253, -0.139283, 300, 255, 1, 0, '', 0),
(51013425, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4570.25, -4307.64, 906.508, 2.79379, 0, 0, -0.984917, -0.173027, 300, 255, 1, 0, '', 0),
(51013426, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4521.93, -4331.95, 905.492, 3.77711, 0, 0, -0.949939, 0.312437, 300, 255, 1, 0, '', 0),
(51013427, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4491.19, -4338.1, 902.879, 4.07949, 0, 0, -0.892045, 0.451947, 300, 255, 1, 0, '', 0),
(51013428, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4444.62, -4368.38, 902.899, 4.24207, 0, 0, -0.852401, 0.522889, 300, 255, 1, 0, '', 0),
(51013429, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4509, -4463.17, 889.468, 6.11524, 0, 0, -0.0838731, 0.996476, 300, 255, 1, 0, '', 0),
(51013430, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4559.05, -4466.41, 885.134, 0.168992, 0, 0, -0.0843958, -0.996432, 300, 255, 1, 0, '', 0),
(51013431, 202952, 1, 0, 0, 1, 0, 0, 0, -1, 4583.96, -4521.86, 887.162, 4.71095, 0, 0, -0.707616, 0.706597, 300, 255, 1, 0, '', 0);
UPDATE `quest_template_addon` SET `PrevQuestID` = '25608' WHERE `ID` = '25548'; 
UPDATE `creature_template` SET `KillCredit1` = 40440, `minlevel` = 1, `maxlevel` = 1 WHERE `entry` = 40434;
UPDATE `creature_template` SET `KillCredit1` = 39724 WHERE `entry` = 48725;
-- High Cultist Azennios
SET @ENTRY := 40491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');
DELETE FROM `quest_objectives` WHERE `ID` = '266297'; 
SET @ENTRY := 40409;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,11382,0,0,0,2,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Gossip - Change Faction");
UPDATE `creature_template` SET `InhabitType` = 4, `HoverHeight` = 5 WHERE `entry` = 48725;
UPDATE `quest_template_addon` SET `NextQuestID` = '25548' WHERE `ID` = '25608'; 
UPDATE `quest_template_addon` SET `PrevQuestID` = '25531' WHERE `ID` = '25608'; 
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (39453,40536,41634);

DELETE FROM `creature` WHERE `id`=39867;

SET @ENTRY := 40713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestep');
DELETE FROM `creature` WHERE `id`=40974;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+20, 40974, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3758.62, -3231.32, 975.855, 4.67291, 300, 0, 0, 6958, 4169, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=41634;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(305560, 41634, 1, 616, 5040, 1, 0, 0, 0, -1, 31188, 0, 4027.45, -3054.09, 569.141, 1.97222, 300, 0, 0, 22339500, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=40805;
UPDATE `creature_template` SET `unit_flags` = 32768, `type_flags` = 0 WHERE `entry` = 40974;
UPDATE `creature_template` SET `unit_flags` = 32768, `type_flags` = 4, `AIName` = '' WHERE `entry` = 41634;
UPDATE `creature_template` SET `unit_flags` = 32768, `type_flags` = 2147483652, `AIName` = '' WHERE `entry` = 41634;
UPDATE `creature_template` SET `KillCredit1` = 40793, `AIName` = '' WHERE `entry` = 41634;
SET @ENTRY := 41634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,84402,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wrath of Ragnaros');
DELETE FROM `creature` WHERE `id`=40804;
DELETE FROM `creature` WHERE `id`=41632;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+21, 41632, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3937.07, -2823.61, 618.747, 5.08702, 300, 0, 0, 581620, 4735000, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=41630;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+22, 41630, 1, 0, 0, 1, 0, 0, 0, -1, 0, 1, 3961.6, -2817.7, 618.747, 5.05639, 300, 0, 0, 1740, 60, 0, 0, 0, 0, 0, 0, '', 0);
