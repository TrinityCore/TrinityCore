UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = '0' WHERE `MenuId` = '9873' AND `OptionIndex` = '0'; 

DELETE FROM `creature` WHERE `id`=28070;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(115440, 28070, 599, 4264, 4264, 6, 0, 0, 0, -1, 26353, 0, 1077.41, 474.16, 207.903, 2.70526, 7200, 0, 0, 32052, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116676, 28070, 599, 0, 0, 2, 0, 0, 0, -1, 0, 0, 1310.03, 653.62, 189.608, 2.20305, 300, 0, 0, 12958, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '27975' AND `Item` = '74830'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '427975' AND `Item` = '74830'; 
DELETE FROM `creature` WHERE `id`=29399;
DELETE FROM `creature_template_addon` WHERE (`entry`=29433);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29433, 0, 0, 0, 1, 415, '');
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('30490', '49554'); 
REPLACE INTO `creature_questender` (`id`, `quest`) VALUES ('30490', '49536'); 
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = '0' WHERE `MenuId` = '9857' AND `OptionIndex` = '0'; 

UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE `id` IN (29402,29404,29619,29377);
DELETE FROM `creature_template_addon` WHERE (`entry`=30035);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (30035, 0, 0, 0, 1, 0, 84063);

DELETE FROM `creature` WHERE `id`=29518;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(75231, 29518, 571, 67, 4425, 1, 0, 0, 0, -1, 0, 0, 6832.86, -1372.32, 819.187, 2.45546, 600, 0, 0, 12175, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116679, 29518, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 7031.74, -1310.57, 818.991, 3.01992, 300, 0, 0, 14929, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `gossip_menu_option` WHERE `MenuId` = '9874' AND `OptionIndex` = '0'; 
UPDATE `creature_template` SET `gossip_menu_id` = 30154 WHERE `entry` = 30154;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('30154','0','0','Skip the warmup, sister... or are you too scared to face someone your own size?','0','1','1','29416');
DELETE FROM `quest_objectives` WHERE `ID` = '263621'; 
UPDATE `creature_template` SET `HoverHeight` = 10 WHERE `entry` = 29708;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 30154;
UPDATE `quest_template_addon` SET `PrevQuestID` = '0' WHERE `ID` = '12823'; 
DELETE FROM `creature` WHERE `id`=29432;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(75228, 29432, 571, 67, 4461, 1, 0, 0, 0, -1, 0, 0, 6318.39, -1761.81, 457.21, 1.74884, 600, 0, 0, 12600, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 29432;

REPLACE INTO `creature_queststarter` (`id`, `quest`) VALUES ('29428', '12832'); 
SET @ENTRY := 29428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12832,0,0,0,15,12832,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add'),
(@ENTRY,0,1,0,19,0,100,0,12821,0,0,0,15,12821,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');

UPDATE `quest_template_addon` SET `PrevQuestID` = '0' WHERE `ID` = '12832'; 
DELETE FROM `creature` WHERE `id`=29794;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(104483, 29794, 571, 67, 67, 1, 0, 0, 0, -1, 25805, 0, 7096.85, 142.771, 1049.14, 2.78341, 300, 0, 0, 126000, 39940, 0, 0, 0, 0, 0, 0, '', 0),
(210116683, 29794, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7033.02, 64.9671, 1017.12, 2.69241, 300, 0, 0, 21597, 19970, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 29811;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (29811);
DELETE FROM `creature_template_addon` WHERE (`entry`=29811);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29811, 0, 0, 7, 1, 0, 29266);
DELETE FROM `creature` WHERE `id`=29579;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116682, 29579, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 7322.03, -1606.87, 944.787, 3.36863, 300, 0, 0, 12958, 0, 0, 16777219, 0, 0, 0, 0, '', 0),
(372355, 29579, 571, 67, 4428, 1, 0, 0, 0, -1, 0, 0, 6662.74, -254.222, 962.059, 4.96311, 120, 0, 0, 11600, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `modelid1` = 15880, `modelid2` = 0 WHERE `entry` = 29752;
UPDATE `creature_template` SET `KillCredit1` = 29816 WHERE `entry` = 29469;
UPDATE `creature_template` SET `KillCredit1` = 29816 WHERE `entry` = 30445;

SET @ENTRY := 29727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12864,0,0,0,15,12864,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');
DELETE FROM `quest_objectives` WHERE `ID` = '263296'; 
DELETE FROM `quest_objectives` WHERE `ID` = '263297'; 
DELETE FROM `quest_objectives` WHERE `ID` = '263298'; 
DELETE FROM `quest_objectives` WHERE `ID` = '263299'; 
UPDATE `quest_template_addon` SET `PrevQuestID` = '12875' WHERE `ID` = '12877'; 
UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 29751;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (29751);
DELETE FROM `creature_template_addon` WHERE (`entry`=29751);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29751, 0, 0, 7, 1, 0, 29266);

SET @ENTRY := 30382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12973,0,0,0,15,12973,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');


DELETE FROM `creature` WHERE `id`=30401;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116685, 30401, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 6648.83, -311.505, 989.51, 1.19547, 300, 0, 0, 10798, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 29377;

DELETE FROM `creature_template_addon` WHERE (`entry`=29384);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29384, 0, 0, 0, 1, 233, '');

UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '29380' AND `Item` = '42203'; 
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('29384','0','0','I\'m not a laborer. I\'m here to free you from servitude in the mines.','0','1','1','29416');
UPDATE `creature_template` SET `gossip_menu_id` = 29384 WHERE `entry` = 29384;
SET @ENTRY := 29384;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,29384,0,0,0,33,51933,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 29708;
UPDATE `creature_template` SET `KillCredit1` = 29595 WHERE `entry` = 29358;
SET @ENTRY := 30209;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,56275,0,0,0,33,30209,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");
UPDATE `creature_template` SET `KillCredit1` = 29709, `InhabitType` = 1 WHERE `entry` = 29708;
SET @ENTRY := 30211;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,56275,0,0,0,33,30211,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");
DELETE FROM `creature` WHERE `id`=30275;
SET @ENTRY := 30212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,56275,0,0,0,33,30212,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '29875' AND `Item` = '41424'; 
UPDATE `creature_template` SET `InhabitType` = 5, `HoverHeight` = 10 WHERE `entry` = 29458;
DELETE FROM `creature_template_addon` WHERE (`entry`=29458);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29458, 0, 26739, 33554432, 1, 0, '');

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 29570;


UPDATE `creature_template` SET `InhabitType` = 4, `HoverHeight` = 2 WHERE `entry` = 29570;

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 29458;

UPDATE `creature_template` SET `KillCredit1` = 30221 WHERE `entry` = 29352;
DELETE FROM `creature` WHERE `id`=29352;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116694, 29352, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 6985.34, -1772.5, 821.243, 0.391729, 300, 0, 0, 6479, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 29625;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 29352;
DELETE FROM `creature` WHERE `id`=29694;
DELETE FROM `creature` WHERE `id`=29625;
DELETE FROM `creature_template_addon` WHERE (`entry`=29625);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29625, 0, 0, 33554432, 1, 0, '');


DELETE FROM `creature` WHERE `id`=29625;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116716, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7341.94, -604.618, 1902.16, 5.48586, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116715, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7318.99, -565.726, 1908.28, 5.03504, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116714, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7317.73, -521.205, 1907.55, 4.51903, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116713, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7332.15, -482.325, 1906.36, 4.31169, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116712, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7364.69, -445.09, 1905.23, 3.97004, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116711, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7403.24, -424.866, 1908.77, 3.43283, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116710, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7446.34, -420.72, 1904.86, 3.1383, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116709, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7476.03, -428.203, 1908.54, 3.04327, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116708, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7503.89, -446.251, 1906.36, 2.54847, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116707, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7525.2, -466.322, 1906.67, 2.36233, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116706, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7543.82, -497.851, 1908.69, 1.97827, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116705, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7549.06, -536.912, 1902.5, 1.70259, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116704, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7540.97, -575.024, 1901.79, 1.23607, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116703, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7524.28, -600.518, 1902.61, 1.01223, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116702, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7504.24, -620.493, 1902.06, 0.573977, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116701, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7477.83, -633.742, 1902.55, 0.394906, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116700, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7448.65, -642.865, 1903.83, 0.284165, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116699, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7424.48, -646.369, 1901.96, 6.10475, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116698, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7396.48, -637.496, 1902.13, 5.84557, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116697, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7377.59, -628.655, 1903.46, 5.84557, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116718, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7509.84, -557.081, 1908.26, 3.08568, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116717, 29625, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7500.31, -571.303, 1895.66, 2.59873, 300, 0, 0, 15117, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=29558;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 32571;

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 30163;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (30163);
DELETE FROM `creature_template_addon` WHERE (`entry`=30163);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (30163, 0, 0, 7, 1, 0, 29266);
DELETE FROM `gameobject` WHERE `id`=192127;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013395, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7178.51, -3584.41, 826.631, 1.65873, 0, 0, -0.737502, -0.675345, 300, 255, 1, 0, '', 0),
(51013392, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7209.72, -3614.48, 823.083, 2.05614, 0, 0, -0.856304, -0.516473, 300, 255, 1, 0, '', 0),
(51013394, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7189.7, -3588.94, 826.723, 1.65873, 0, 0, -0.737502, -0.675345, 300, 255, 1, 0, '', 0),
(51013390, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7224.93, -3614.73, 823.373, 3.43373, 0, 0, -0.989351, 0.145549, 300, 255, 1, 0, '', 0),
(51013391, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7214.55, -3623.36, 823.318, 3.23659, 0, 0, -0.998872, 0.0474826, 300, 255, 1, 0, '', 0),
(51013393, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7190.05, -3608.44, 826.177, 2.24071, 0, 0, -0.900255, -0.435364, 300, 255, 1, 0, '', 0),
(51013396, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7195.72, -3577.2, 826.369, 1.35635, 0, 0, -0.627373, -0.778719, 300, 255, 1, 0, '', 0),
(51013397, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7209.49, -3552.49, 827.795, 1.51421, 0, 0, -0.686822, -0.726826, 300, 255, 1, 0, '', 0),
(51013398, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7214.75, -3536.11, 827.242, 1.51421, 0, 0, -0.686822, -0.726826, 300, 255, 1, 0, '', 0),
(51013399, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7203.71, -3521.53, 827.834, 2.24464, 0, 0, -0.901108, -0.433595, 300, 255, 1, 0, '', 0),
(51013400, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7199.94, -3509.77, 828.356, 1.70271, 0, 0, -0.752174, -0.658964, 300, 255, 1, 0, '', 0),
(51013401, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7196.46, -3497.05, 831.019, 1.39641, 0, 0, -0.642842, -0.765999, 300, 255, 1, 0, '', 0),
(51013402, 192127, 571, 0, 0, 1, 0, 0, 0, -1, 7207.56, -3490.5, 832.35, 1.39641, 0, 0, -0.642842, -0.765999, 300, 255, 1, 0, '', 0);

UPDATE `creature_template` SET `unit_flags2` = 1 WHERE `entry` = 30163;
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=30099; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=30099; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=30099; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=30099);

DELETE FROM `creature` WHERE `id`=30127;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116721, 30127, 571, 0, 0, 1, 0, 171, 0, -1, 0, 1, 7352.19, -2811.57, 798.529, 1.74828, 300, 0, 0, 8638, 0, 0, 0, 0, 0, 0, 0, '', 0);

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('30127','0','0','Take this Iron!','0','1','1','29416');

DELETE FROM `quest_objectives` WHERE `ID` = '263027'; 
SET @ENTRY := 30127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,30127,0,0,0,33,30126,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

UPDATE `creature_template` SET `gossip_menu_id` = 30127 WHERE `entry` = 30127;

DELETE FROM `creature` WHERE `id`=30461;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116724, 30461, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 7091.4, -913.518, 1067.86, 4.82406, 300, 0, 0, 107985, 0, 0, 16777216, 0, 0, 0, 0, '', 0);
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '30260' AND `Item` = '42542'; 
UPDATE `creature_template` SET `unit_flags` = 32768, `InhabitType` = 1, `HoverHeight` = 0 WHERE `entry` = 30461;
DELETE FROM `quest_objectives` WHERE `ID` = '263503'; 
DELETE FROM `quest_objectives` WHERE `ID` = '263504'; 
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE `id` IN (29402,29404,29504,29619,29375,29377,29382,29624,30322,29458,30422,29458,30260);

DELETE FROM `creature` WHERE `id`=30390;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116728, 30390, 571, 0, 0, 1, 0, 171, 0, -1, 0, 0, 7327.37, -2810.42, 798.983, 0.788988, 300, 0, 0, 2311, 0, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `creature` WHERE `id`=30252;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116731, 30252, 571, 0, 0, 1, 0, 171, 0, -1, 0, 1, 7375.39, -2811.28, 797.641, 2.25221, 300, 0, 0, 8638, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=30105;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116732, 30105, 571, 0, 0, 1, 0, 171, 0, -1, 0, 1, 7336.93, -2817.21, 798.137, 1.78804, 300, 0, 0, 8638, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `gameobject` WHERE `id`=192071;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(42337, 192071, 571, 67, 4438, 1, 0, 171, 0, -1, 7213.2, -2649.97, 809.769, 3.09472, 0, 0, 0.999725, 0.0234342, 360, 0, 1, 0, '', 0);
DELETE FROM `creature` WHERE `id`=30390;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(88419, 30390, 571, 67, 4440, 1, 0, 0, 0, -1, 0, 0, 7882.51, -3236.7, 849.411, 4.42864, 300, 0, 0, 13481, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=30127;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(86277, 30127, 571, 67, 4438, 1, 0, 171, 0, -1, 0, 0, 7190.66, -2661.51, 813.128, 5.86858, 300, 0, 0, 21844, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 29571;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 30105;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 30252;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 32594;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 29809;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 32540;
UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 29571;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (29571);
DELETE FROM `creature_template_addon` WHERE (`entry`=29571);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (29571, 0, 0, 7, 1, 0, 29266);
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 29571;
UPDATE `creature_template` SET `unit_flags2` = 1 WHERE `entry` = 29571;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 193997;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192189;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192192;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192190;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192191;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192187;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192524;
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 30260;
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 29809;
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 32594;
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 30262;
UPDATE `creature` SET `PhaseId` = 171 WHERE `id` = 32571;
UPDATE `creature` SET `PhaseId` = 0 WHERE `id` = 29605;
UPDATE `creature` SET `PhaseId` = 0 WHERE `id` = 32540;
DELETE FROM `quest_objectives` WHERE `ID` = '264129'; 
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `id` = 192079;
UPDATE `creature_template` SET `KillCredit1` = 30296 WHERE `entry` = 29984;
UPDATE `creature_template` SET `KillCredit1` = 30297 WHERE `entry` = 29978;
UPDATE `creature_template` SET `KillCredit1` = 30297 WHERE `entry` = 29979;
SET @ENTRY := 30295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,13047,0,0,0,15,13047,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');
UPDATE `creature` SET `PhaseId` = 171 WHERE `map`=571 AND `zoneId`=67 AND `areaId`=4495;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `map`=571 AND `zoneId`=67 AND `areaId`=4495;
UPDATE `creature` SET `PhaseId` = 171 WHERE `map`=571 AND `zoneId`=67 AND `areaId`=4440;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `map`=571 AND `zoneId`=67 AND `areaId`=4440;
UPDATE `creature` SET `PhaseId` = 171 WHERE `map`=571 AND `zoneId`=67 AND `areaId`=4439;
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `map`=571 AND `zoneId`=67 AND `areaId`=4439;