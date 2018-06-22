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
(210119050, 54014, 861, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1452.01, 340.643, 51.4103, 0.867748, 300, 0, 0, 18387, 8908, 0, 0, 0, 0, 0, 0, '', 0);
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

DELETE FROM `creature_template_addon` WHERE (`entry`=59022);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (59022, 0, 0, 0, 1, 0, 84063);



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



DELETE FROM `creature_template_addon` WHERE (`entry`=64491);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (64491, 0, 0, 0, 1, 0, 84063);


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
(210119051, 64491, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 762.757, -1880.39, 61.6085, 6.27687, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);


-- Miska
DELETE FROM `creature_template_addon` WHERE (`entry`=64493);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (64493, 0, 0, 0, 1, 0, 84063);


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
(210119052, 64493, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 779.958, -1789.53, 56.5243, 0.660485, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Salli
DELETE FROM `creature_template_addon` WHERE (`entry`=64494);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (64494, 0, 0, 0, 1, 0, 84063);


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
(210119053, 64494, 870, 0, 0, 1, 0, 0, 0, -1, 0, 0, 898.725, -1876.75, 60.5162, 1.21655, 300, 0, 0, 18387, 0, 0, 0, 0, 0, 0, 0, '', 0);


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



UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE `id` IN (66282,12922,66290,54627,55195,56650);


UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (11260);






















































