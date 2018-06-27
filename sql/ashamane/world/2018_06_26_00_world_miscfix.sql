SET @CGUID := 210120000;

DELETE FROM `creature_queststarter` WHERE `id` = '63258' AND `quest` = '31142'; 

UPDATE `creature_template` SET `dynamicflags` = 35 WHERE `entry` = 66457;

UPDATE `creature_template` SET `faction` = 189, `unit_flags` = 262656 WHERE `entry` = 66339;


UPDATE `creature_template` SET `KillCredit1` = 66383, `KillCredit2` = 66384 WHERE `entry` = 66396;

SET @ENTRY := 66396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,130624,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Demonic Circle: Teleport on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,130624,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Demonic Circle: Teleport on Evade');


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('65910','0','0','Iam from Allience','0','1','1','29416');

SET @ENTRY := 65910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,65910,0,0,0,33,65910,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");




UPDATE `creature_template` SET `npcflag` = 1, `type_flags` = 0 WHERE `entry` = 66567;
UPDATE `creature_template` SET `gossip_menu_id` = 66567, `npcflag` = 1, `type_flags` = 0 WHERE `entry` = 66567;
UPDATE `creature_template` SET `gossip_menu_id` = 66564, `npcflag` = 1, `type_flags` = 0 WHERE `entry` = 66564;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('66567','0','0','You saved now!','0','1','1','29416');
UPDATE `creature_template` SET `KillCredit1` = 64354 WHERE `entry` = 59979;
SET @ENTRY := 66567;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,66567,0,0,0,33,54929,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



DELETE FROM `creature_template_addon` WHERE (`entry`=66564);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (66564, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 66564;


UPDATE `creature_template` SET `gossip_menu_id` = 66564, `npcflag` = 1, `type_flags` = 0 WHERE `entry` = 66564;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('66564','0','0','You saved now!','0','1','1','29416');
UPDATE `creature_template` SET `KillCredit1` = 64354 WHERE `entry` = 59979;
SET @ENTRY := 66564;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,66564,0,0,0,33,54929,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



DELETE FROM `creature_template_addon` WHERE (`entry`=66564);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (66564, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 66564;

UPDATE `creature_template` SET `gossip_menu_id` = 61492, `npcflag` = 1, `type_flags` = 0 WHERE `entry` = 61492;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('61492','0','0','You saved now!','0','1','1','29416');
UPDATE `creature_template` SET `KillCredit1` = 64354 WHERE `entry` = 59979;
SET @ENTRY := 61492;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,61492,0,0,0,33,54929,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



DELETE FROM `creature_template_addon` WHERE (`entry`=61492);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (61492, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 61492;

DELETE FROM `creature_template_addon` WHERE (`entry`=59979);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (59979, 0, 0, 0, 1, 234, '');

REPLACE INTO `creature_equip_template` (`CreatureID`, `ItemID1`) VALUES ('59979', '1905'); 

UPDATE `creature_template` SET `KillCredit1` = 66301, `faction` = 189 WHERE `entry` = 12922;

DELETE FROM `creature_template_addon` WHERE (`entry`=11260);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (11260, 0, 0, 0, 1, 234, '');

UPDATE `creature_template` SET `unit_flags` = 131588, `unit_flags2` = 2048 WHERE `entry` = 66279;
UPDATE `creature_template` SET `KillCredit1` = 66366, `KillCredit2` = 66366 WHERE `entry` = 66367;

UPDATE `creature_template` SET `KillCredit1` = 66304, `unit_flags` = 131588, `unit_flags2` = 2048,`faction` = 189 WHERE `entry` = 66279;


UPDATE `creature_template` SET `KillCredit1` = 66302, `KillCredit2` = 66303 WHERE `entry` = 66277;

UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26657'; 
UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26750'; 
UPDATE `quest_template_addon` SET `NextQuestID` = '0' WHERE `ID` = '26584'; 
DELETE FROM `creature` WHERE `id`=54014;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+0, 54014, 861, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1452.01, 340.643, 51.4103, 0.867748, 300, 0, 0, 18387, 8908, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 53926 WHERE `entry` = 53928;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('12943','0','0','I am prepared. Let us go to the Firelands and finish this.','0','1','1','29416');
UPDATE `creature_template` SET `KillCredit1` = 66302, `KillCredit2` = 66303, `unit_flags` = 163840 WHERE `entry` = 66277;
SET @ENTRY := 53738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12943,0,0,0,62,861,0,0,0,0,0,7,0,0,0,1453.81,354.121,55.5129,0.608567,"Teleport"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,53738,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 66277;


UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 66277;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('67067','0','0','Lets Go!','0','1','1','29416');




UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (45303,43036,44768,45364,44289,43170,43952,42900,43101,45305,44078,43388);
DELETE FROM `creature_template_addon` WHERE (`entry`=54623);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (54623, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 54623;
DELETE FROM `creature_template_addon` WHERE (`entry`=59022);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (59022, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 59022;


UPDATE `creature_template` SET `gossip_menu_id` = 55490 WHERE `entry` = 55490;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('55490','0','0','You saved now!','0','1','1','29416');

SET @ENTRY := 55490;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,55490,0,0,0,33,55201,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");


UPDATE `creature_template` SET `gossip_menu_id` = 55201 WHERE `entry` = 55201;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('55201','0','0','You saved now!','0','1','1','29416');

SET @ENTRY := 55201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,55201,0,0,0,33,55201,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");

UPDATE `creature_template` SET `modelid1` = 15880, `modelid2` = 0 WHERE `entry` = 59169;


UPDATE `creature_template` SET `gossip_menu_id` = 56222 WHERE `entry` = 56222;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('56222','0','0','I can beat you!','0','1','1','29416');

SET @ENTRY := 56222;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,56222,0,0,0,33,59572,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

UPDATE `creature_template` SET `gossip_menu_id` = 59348 WHERE `entry` = 59348;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('59348','0','0','I can help you!','0','1','1','29416');

SET @ENTRY := 59348;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,59348,0,0,0,33,59609,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");


UPDATE `creature_template` SET `gossip_menu_id` = 59572 WHERE `entry` = 59572;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('59572','0','0','I can beat you!','0','1','1','29416');

SET @ENTRY := 59572;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,59572,0,0,0,33,59572,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature_template_addon` WHERE (`entry`=56693);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56693, 0, 0, 0, 1, 233, '');


UPDATE `creature_template` SET `gossip_menu_id` = 64475 WHERE `entry` = 64475;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('64475','0','0','Give him relic...','0','1','1','29416');

SET @ENTRY := 64475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,64475,0,0,0,33,59415,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");
UPDATE `creature_template` SET `KillCredit1` = 64269 WHERE `entry` = 59462;

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 56233;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (56233);
DELETE FROM `creature_template_addon` WHERE (`entry`=56233);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56233, 0, 0, 7, 1, 0, 29266);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 56233;


DELETE FROM `creature_template_addon` WHERE (`entry`=64491);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (64491, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 64491;

UPDATE `creature_template` SET `gossip_menu_id` = 64491 WHERE `entry` = 64491;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 64491;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('64491','0','0','You saved!','0','1','1','29416');

SET @ENTRY := 64491;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,64491,0,0,0,33,64491,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature` WHERE `id`=64491;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+1, 64491, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 762.757, -1880.39, 61.6085, 6.27687, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);


-- Miska
DELETE FROM `creature_template_addon` WHERE (`entry`=64493);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (64493, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 64493;

UPDATE `creature_template` SET `gossip_menu_id` = 64493 WHERE `entry` = 64493;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 64493;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('64493','0','0','You saved!','0','1','1','29416');

SET @ENTRY := 64493;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,64493,0,0,0,33,64493,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature` WHERE `id`=64493;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+2, 64493, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 779.958, -1789.53, 56.5243, 0.660485, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Salli
DELETE FROM `creature_template_addon` WHERE (`entry`=64494);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (64494, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 64494;

UPDATE `creature_template` SET `gossip_menu_id` = 64494 WHERE `entry` = 64494;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 64494;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('64494','0','0','You saved!','0','1','1','29416');

SET @ENTRY := 64494;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,64494,0,0,0,33,64494,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature` WHERE `id`=64494;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+3, 64494, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 898.725, -1876.75, 60.5162, 1.21655, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature_template` SET `gossip_menu_id` = 59899 WHERE `entry` = 59899;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('59899','0','0','I am ready to go!','0','1','1','29416');

SET @ENTRY := 59899;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,59899,0,0,0,33,59692,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



DELETE FROM `creature_template_addon` WHERE (`entry`=56768);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56768, 0, 0, 0, 1, 415, '');
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '253525'; 

UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 60970;


REPLACE INTO `creature_queststarter` (`id`, `quest`) VALUES ('60970', '29901'); 


UPDATE `creature_template` SET `gossip_menu_id` = 56737 WHERE `entry` = 56737;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('56737','1','0','I want to travel!','0','1','1','29416'),('56737','0','2','I want to travel fast','0','4','8192','29416');

SET @ENTRY := 56737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,56737,1,0,0,33,56737,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



DELETE FROM `creature_template_addon` WHERE (`entry`=55333);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55333, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 55333;

UPDATE `quest_template_addon` SET `NextQuestID` = '29894' WHERE `ID` = '29887'; 
UPDATE `quest_template_addon` SET `PrevQuestID` = '29887' WHERE `ID` = '29894'; 

UPDATE `creature_template` SET `gossip_menu_id` = 54894 WHERE `entry` = 54894;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54894','0','0','Lets begin!','0','1','1','29416');

SET @ENTRY := 54894;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,54894,0,0,0,33,56398,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,1,0,0,33,54894,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


UPDATE `creature_template` SET `gossip_menu_id` = 55333 WHERE `entry` = 55333;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('55333','0','0','Tell me everything!','0','1','1','29416');

SET @ENTRY := 55333;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,55333,0,0,0,33,67152,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



DELETE FROM `quest_objectives` WHERE `ID` = '264487'; 
DELETE FROM `quest_objectives` WHERE `ID` = '264488'; 
DELETE FROM `quest_objectives` WHERE `ID` = '264489'; 
DELETE FROM `quest_objectives` WHERE `ID` = '264490'; 

DELETE FROM `quest_objectives` WHERE `ID` = '264491'; 
DELETE FROM `quest_objectives` WHERE `ID` = '264492'; 
DELETE FROM `quest_objectives` WHERE `ID` = '264493'; 
DELETE FROM `quest_objectives` WHERE `ID` = '264494'; 



UPDATE `creature_template` SET `gossip_menu_id` = 55283 WHERE `entry` = 55283;

UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '252936';

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('55283','0','0','Tell me everything!','0','1','1','29416');

SET @ENTRY := 55283;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,55283,0,0,0,33,55408,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `quest_objectives` WHERE `ID` = '268149'; 
DELETE FROM `quest_objectives` WHERE `ID` = '268150'; 
DELETE FROM `quest_objectives` WHERE `ID` = '268151'; 



UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '252925'; 
UPDATE `creature_template` SET `KillCredit1` = 56457, `KillCredit2` = 56458 WHERE `entry` = 56444;
DELETE FROM `quest_objectives` WHERE `ID` = '253314'; 
DELETE FROM `quest_objectives` WHERE `ID` = '253315'; 

DELETE FROM `creature` WHERE `id`=56786;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+4, 56786, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 859.857, -2474.89, 176.303, 0.797591, 300, 0, 0, 24154, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=57232;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+5, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 839.192, -2458.68, 174.959, 2.47991, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+6, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 815.966, -2462.07, 176.301, 2.96922, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+7, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 810.741, -2497.23, 176.303, 4.87067, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+8, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 804.646, -2492.39, 176.302, 0.785025, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+9, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 854.998, -2509.26, 176.302, 4.5675, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+10, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 860.942, -2487.03, 176.302, 1.33873, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+11, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 850.557, -2458.51, 174.96, 1.58299, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+12, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 860.348, -2439.3, 176.303, 0.689992, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+13, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 850.158, -2433.93, 176.303, 2.99985, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+14, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 876.112, -2441.18, 176.303, 5.90582, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+15, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 862.791, -2486.71, 192.546, 4.38215, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+16, 57232, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 856.748, -2508.12, 192.551, 5.44244, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature_questender` WHERE `id` = '56774' AND `quest` = '32018'; 


DELETE FROM `creature_template_addon` WHERE (`entry`=56774);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56774, 0, 0, 0, 1, 415, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=56775);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56775, 0, 0, 0, 1, 415, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=56062);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56062, 0, 0, 0, 1, 415, '');


DELETE FROM `gameobject` WHERE `id`=217846;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013479, 217846, 870, 0, 0, 1, 0, 0, 0, -1, 1462.35, -1843.71, 224.357, 3.45718, 0, 0, -0.987576, 0.157139, 300, 255, 1, 0, '', 0);




DELETE FROM `creature_template_addon` WHERE (`entry`=56064);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (56064, 0, 0, 0, 1, 415, '');

UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 56206;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 56209;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 56210;


REPLACE INTO `creature_equip_template` (`CreatureID`, `ItemID1`) VALUES ('54702', '1909'); 
REPLACE INTO `creature_equip_template` (`CreatureID`, `ItemID1`) VALUES ('54989', '1909'); 
UPDATE `creature_template` SET `gossip_menu_id` = 54763 WHERE `entry` = 54763;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54763','0','0','You must go!','0','1','1','29416');

SET @ENTRY := 54763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,54763,0,0,0,33,54872,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");


DELETE FROM `creature_template_addon` WHERE (`entry`=54763);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (54763, 0, 0, 0, 1, 0, 84063);
UPDATE `creature_template` SET `unit_flags2` = 34816 WHERE `entry` = 54763;
UPDATE `creature_template` SET `KillCredit1` = 54789 WHERE `entry` = 54702;
UPDATE `creature_template` SET `KillCredit1` = 54789 WHERE `entry` = 54703;



DELETE FROM `creature_template_addon` WHERE (`entry`=55081);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55081, 0, 0, 1, 4097, 0, '');




UPDATE `creature_template` SET `gossip_menu_id` = 55009 WHERE `entry` = 55009;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('55009','0','0','We found it!','0','1','1','29416');

SET @ENTRY := 55009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,55009,0,0,0,33,54999,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


UPDATE `creature_template` SET `gossip_menu_id` = 54990 WHERE `entry` = 54990;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54990','0','0','You are free now!','0','1','1','29416');

SET @ENTRY := 54990;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,54990,0,0,0,33,54996,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


DELETE FROM `creature_template_addon` WHERE (`entry`=54990);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (54990, 0, 0, 1, 4097, 0, '');


UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 58220;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 58244;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 58243;

UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '263846'; 
UPDATE `creature_template` SET `KillCredit1` = 58246 WHERE `entry` = 58244;
UPDATE `creature_template` SET `KillCredit1` = 58246 WHERE `entry` = 58243;
UPDATE `creature_template` SET `KillCredit1` = 58246 WHERE `entry` = 58220;


UPDATE `creature_template` SET `gossip_menu_id` = 54914 WHERE `entry` = 54914;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54914','0','0','I found it!','0','1','1','29416');

SET @ENTRY := 54914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,54914,0,0,0,33,55057,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


DELETE FROM `creature_template_addon` WHERE (`entry`=54926);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (54926, 0, 0, 65537, 1, 0, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=55028);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55028, 0, 0, 0, 1, 415, ''); 
DELETE FROM `creature_template_addon` WHERE (`entry`=55029);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55029, 0, 0, 0, 1, 415, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=55030);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (55030, 0, 0, 0, 1, 415, '');



UPDATE `creature_template` SET `gossip_menu_id` = 54944 WHERE `entry` = 54944;
-- Tian Pupil SAI
SET @ENTRY := 54944;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,115761,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Chi Blast"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,115680,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Dragon Punch"),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,115744,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Drunken Brawl at 40% HP"),
(@ENTRY,0,3,0,9,0,100,0,0,8,15000,25000,11,115754,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Hurricane Kick on Close"),
(@ENTRY,0,4,0,62,0,100,0,54944,0,0,0,2,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Gossip - Change Faction"),
(@ENTRY,0,5,6,2,0,100,1,0,20,0,0,2,35,2,0,0,0,0,1,0,0,0,0,0,0,0,'Change Faction at 20% HP'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,33,54944,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Faction Change - Kill Credit");


DELETE FROM `creature_template_addon` WHERE (`entry`=54944);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (54944, 0, 0, 65537, 1, 0, '');



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54944','0','0','Let\'s get started!','0','1','1','29416');


-- Husshun SAI
SET @ENTRY := 54925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,116725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Lightning Crash"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,115153,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Water Dance on Aggro"),
(@ENTRY,0,3,0,62,0,100,0,54925,0,0,0,2,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Gossip - Change Faction"),
(@ENTRY,0,4,5,2,0,100,1,0,20,0,0,2,35,2,0,0,0,0,1,0,0,0,0,0,0,0,'Change Faction at 20% HP'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,33,54925,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Faction Change - Kill Credit");

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54925','0','0','Let\'s get started!','0','1','1','29416');

UPDATE `creature_template` SET `gossip_menu_id` = 54925 WHERE `entry` = 54925;

-- Zhi-Zhi SAI
SET @ENTRY := 54924;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,116715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Flurry"),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,116710,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Nimble at 40% HP"),
(@ENTRY,0,2,0,62,0,100,0,54924,0,0,0,2,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Gossip - Change Faction"),
(@ENTRY,0,3,4,2,0,100,1,0,20,0,0,2,35,2,0,0,0,0,1,0,0,0,0,0,0,0,'Change Faction at 20% HP'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,33,54924,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Faction Change - Kill Credit");


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54924','0','0','Let\'s get started!','0','1','1','29416');

UPDATE `creature_template` SET `gossip_menu_id` = 54924 WHERE `entry` = 54924;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('54926','0','0','Let\'s get started!','0','1','1','29416');

UPDATE `creature_template` SET `gossip_menu_id` = 54926 WHERE `entry` = 54926;

UPDATE `creature_template` SET `type_flags` = 2147483648 WHERE `entry` = 54926;
SET @ENTRY := 54926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,117830,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Brew'),
(@ENTRY,0,1,0,0,0,100,0,10000,12000,10000,20000,11,102998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Rice'),
(@ENTRY,0,2,0,62,0,100,0,54926,0,0,0,2,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Gossip - Change Faction"),
(@ENTRY,0,3,4,2,0,100,1,0,20,0,0,2,35,2,0,0,0,0,1,0,0,0,0,0,0,0,'Change Faction at 20% HP'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,33,54926,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Faction Change - Kill Credit");

UPDATE `creature_template` SET `KillCredit1` = 54918, `faction` = 189, `unit_flags` = 32768 WHERE `entry` = 55139;

UPDATE `creature_template` SET `KillCredit2` = 54970 WHERE `entry` = 55184;

UPDATE `creature_template` SET `KillCredit1` = 55086, `KillCredit2` = 55105 WHERE `entry` = 54987;

UPDATE `creature_template` SET `unit_flags` = 131072 WHERE `entry` = 55183;
UPDATE `creature_template` SET `unit_flags` = 131072 WHERE `entry` = 55184;
UPDATE `creature_template` SET `KillCredit1` = 55480 WHERE `entry` = 55489;

UPDATE `creature_template` SET `KillCredit1` = 55289 WHERE `entry` = 55279;
DELETE FROM `gameobject` WHERE `id`=209629;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+17, 209629, 870, 0, 0, 1, 0, 0, 0, -1, 2958.44, -1650.33, 252.833, 3.18636, 0, 0, -0.99975, 0.0223835, 300, 255, 1, 0, '', 0);

DELETE FROM `creature` WHERE `id`=55614;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+18, 55614, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2958.99, -1648.31, 252.832, 3.28689, 300, 0, 0, 19260, 0, 0, 0, 0, 0, 0, 0, '', 0);

SET @ENTRY := 55290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,104596,0,0,0,33,61290,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");

REPLACE INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('209825', '75214', '1'); 


UPDATE `creature_template` SET `KillCredit1` = 55462 WHERE `entry` = 56198;

UPDATE `creature_template` SET `KillCredit1` = 55964, `faction` = 189 WHERE `entry` = 56181;

DELETE FROM `creature` WHERE `id`=56596;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID+19, 56596, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3176.74, -1512.28, 201.389, 3.52724, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `creature` WHERE `id`=65794;

UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE `id` IN (66282,55238,55290,56198,55489,55279,55291,54988,54703,12922,54989,56070,54558,56304,54702,66290,54627,56201,57232,55195,56650);


UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (11260);
