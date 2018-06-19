DELETE FROM `creature_template_addon` WHERE (`entry`=25521);
UPDATE `creature` SET `PhaseId`=170 WHERE `map`=571 and `zoneId`=3537 and `areaId`=4269;
UPDATE `gameobject` SET `PhaseId`=170 WHERE `map`=571 and `zoneId`=3537 and `areaId`=4269;
UPDATE `creature` SET `PhaseId`=170 WHERE `map`=571 and `zoneId`=3537 and `areaId`=4029;
UPDATE `gameobject` SET `PhaseId`=170 WHERE `map`=571 and `zoneId`=3537 and `areaId`=4029;
UPDATE `creature` SET `PhaseId`=170 WHERE `map`=571 and `zoneId`=3537 and `areaId`=4028;
UPDATE `gameobject` SET `PhaseId`=170 WHERE `map`=571 and `zoneId`=3537 and `areaId`=4028;
DELETE FROM `creature_template_addon` WHERE (`entry`=25249);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25249, 0, 0, 0, 1, 415, '');
UPDATE `creature` SET `PhaseId`=170 WHERE `id`=25521;
DELETE FROM `creature_template_addon` WHERE (`entry`=25302);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25302, 0, 0, 0, 1, 415, '');

-- http://ru.wowhead.com/quest=11913

-- Farshire Grain Credit
SET @ENTRY := 26161;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,8,0,100,1,46574,0,100,120,33,26161,0,0,0,0,0,7,0,0,0,0,0,0,0,"Farshire Grain Credit - On SpellHit - Give Kill Credit");
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=13 AND `SourceEntry`=46574 AND `SourceGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13, 1, 46574, 0, 0, 31, 0, 3, 26161, 0, 0, 0, 0, '', 'Target entry 26161');
-- tempfix
UPDATE `creature_template` SET `KillCredit1` = 26161 WHERE `entry` = 25650;


UPDATE `creature_template` SET `unit_flags` = 536871680, `unit_flags2` = 2049 WHERE `entry` = 25385;
DELETE FROM `creature_template_addon` WHERE (`entry`=25385);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25385, 0, 0, 7, 0, 0, '');

DELETE FROM `creature` WHERE `id`=26558;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116650, 26558, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 783.642, -2816.82, 4.6915, 4.48214, 300, 0, 0, 12803, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = '0' WHERE `MenuId` = '9733' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = '0' WHERE `MenuId` = '9733' AND `OptionIndex` = '2'; 

UPDATE `creature_template` SET `npcflag` = 0, `unit_flags` = 512 WHERE `entry` = 26073;

DELETE FROM `creature_template_addon` WHERE (`entry`=32601);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (32601, 0, 0, 33554432, 0, 0, '');


UPDATE `creature_template` SET `faction` = 22 WHERE `entry` = 26073;


DELETE FROM `creature` WHERE `id`=26170;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116653, 26170, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 3691.78, 3576.57, 473.322, 0.0534072, 300, 0, 0, 11990, 0, 0, 0, 0, 0, 0, 0, '', 0),
(117219, 26170, 571, 3537, 4126, 1, 0, 0, 0, -1, 0, 0, 3295.89, 3682.26, 32.4681, 1.62269, 30, 0, 0, 67270, 0, 0, 0, 0, 0, 0, 0, '', 0);

SET @ENTRY := 25590;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,11708,0,0,0,15,11708,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');
-- http://ru.wowhead.com/quest=11796/8-2-4
SET @ENTRY := 25847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,46171,0,0,0,33,25847,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 25846;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,46171,0,0,0,33,25846,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 25845;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,46171,0,0,0,33,25845,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '25660' AND `Item` = '34957'; 
UPDATE `creature_template` SET `HoverHeight` = 10 WHERE `entry` = 26807;

SET @ENTRY := 25654;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,45835,0,0,0,33,25654,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");


UPDATE `creature_template` SET `KillCredit1` = 25505 WHERE `entry` = 25434;


UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24613' AND `Item` = '34977'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24614' AND `Item` = '34977'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '25743' AND `Item` = '34977'; 

DELETE FROM `gameobject` WHERE `id`=187577;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(44374, 187577, 571, 3537, 4127, 1, 0, 0, 0, -1, 4006.15, 5753.61, 65.6007, 1.65964, 0, 0, 0.73781, 0.675009, 120, 100, 1, 0, '', 0),
(51013374, 187577, 571, 0, 0, 1, 0, 0, 0, -1, 3879.58, 5720.73, 66.6114, 5.47177, 0, 0, -0.39467, 0.918823, 300, 255, 1, 0, '', 0);

UPDATE `creature_template` SET `gossip_menu_id` = 25794 WHERE `entry` = 25794;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('25794','0','0','Power ON!','0','1','1','29416');

SET @ENTRY := 25794;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,25794,0,0,0,33,25794,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature` WHERE `id`=25629;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116656, 25629, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3491.5, 4462.65, -12.9943, 0.921179, 300, 0, 0, 14430, 0, 0, 0, 0, 0, 0, 0, '', 0);


UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 187373;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25201;
UPDATE `creature_template` SET `HoverHeight` = 10 WHERE `entry` = 25364;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (187373, 25201, 2520100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(187373, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(187373, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 25201, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(187373, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 25201, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(25201, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2520100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (4141000)'),
(2520100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 25201, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (25201)'),
(2520100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(2520100, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');

UPDATE `creature_template` SET `gossip_menu_id` = 25318 WHERE `entry` = 25318;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('25318','0','0','Lets Go!','0','1','1','29416');

SET @ENTRY := 25318;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,25318,0,0,0,33,25318,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

UPDATE `creature_template` SET `npcflag` = 1,`gossip_menu_id` = 11741 WHERE `entry` = 43505;
DELETE FROM `quest_objectives` WHERE `ID` = '255547'; 
DELETE FROM `quest_objectives` WHERE `ID` = '256625'; 
DELETE FROM `quest_objectives` WHERE `ID` = '263305'; 
DELETE FROM `quest_objectives` WHERE `ID` = '262818'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '25585' AND `Item` = '34688'; 
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` IN (24614,25204,25585,25316,25718,25719,25713);
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `npcflag` = 2, `unit_flags` = 2 WHERE `entry` = 53098;
DELETE FROM `creature` WHERE `id`=25584;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116659, 25584, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3393.02, 6161.21, 79.8322, 4.31227, 300, 0, 0, 11544, 3231, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 25584;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 25584;
replace INTO `creature_queststarter` (`id`, `quest`) VALUES ('53098', '29194'); 
DELETE FROM `creature` WHERE `id`=53098;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116662, 53098, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3976.19, 6783.21, 157.388, 3.38496, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `creature` WHERE `id`=26232;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116663, 26232, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 4033.64, 7327.45, 635.971, 3.92836, 300, 0, 0, 12803, 3387, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '25719' AND `Item` = '35648'; 
DELETE FROM `creature` WHERE `id`=24770;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(103654, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3742.05, 6771.02, 192.427, 1.4974, 300, 30, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103655, 24770, 571, 3537, 4120, 1, 0, 0, 0, -1, 24140, 0, 3716.15, 7006.79, 237.372, 2.00512, 300, 0, 0, 81900, 0, 0, 0, 0, 0, 0, 0, '', 0),
(103656, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3829.31, 6751.31, 251.85, 5.96319, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103657, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3698.18, 6690.69, 434.16, 2.05968, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103658, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3740.16, 6858.15, 510.464, 5.68394, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103846, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3733.61, 6621.66, 200.761, 5.79578, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103847, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3932.99, 6767.08, 201.231, 1.41523, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103848, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3915.82, 6592.47, 294.229, 0.720408, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103849, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3682.68, 7081.58, 232.58, 5.20665, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0),
(103853, 24770, 571, 3537, 4024, 1, 0, 0, 0, -1, 24140, 0, 3597.87, 7196.34, 394.915, 3.54135, 300, 3, 0, 81900, 0, 1, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `quest_objectives` WHERE `ID` = '262478'; 

DELETE FROM `creature` WHERE `id`=26206;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116664, 26206, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3583.64, 6651.49, 195.63, 3.10997, 300, 0, 0, 25916, 31952, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `quest_objectives` WHERE `ID` = '262328'; 

DELETE FROM `creature` WHERE `id`=26716;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(79904, 26716, 576, 4265, 4265, 6, 0, 0, 0, -1, 0, 0, 380.754, 17.3949, -16.6367, 2.35331, 7200, 0, 0, 76880, 33090, 0, 0, 0, 0, 0, 0, '', 0),
(95809, 26716, 576, 4265, 4265, 6, 0, 0, 0, -1, 0, 0, 223.713, -28.3189, -16.6367, 5.45957, 7200, 0, 0, 76880, 33090, 0, 0, 0, 0, 0, 0, '', 0),
(95808, 26716, 576, 4265, 4265, 6, 0, 0, 0, -1, 0, 0, 278.802, 73.2719, -16.6366, 3.9359, 7200, 0, 0, 76880, 33090, 0, 0, 0, 0, 0, 0, '', 0),
(95773, 26716, 576, 4265, 4265, 6, 0, 0, 0, -1, 0, 0, 325.855, -83.1483, -16.6367, 0.719704, 7200, 0, 0, 76880, 33090, 0, 0, 0, 0, 0, 0, '', 0),
(78950, 26716, 576, 4265, 4265, 6, 0, 0, 0, -1, 0, 0, 316.657, 8.38005, -16.524, 0.94352, 7200, 0, 0, 76880, 33090, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=25850;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(94405, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3805.78, 5502.35, 41.4085, 1.46126, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116667, 25850, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3417.97, 5463.3, 64.1571, 0.0627542, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116668, 25850, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3419.63, 5386.33, 48.2405, 4.40444, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116669, 25850, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3325.82, 5376.77, 42.9815, 3.33237, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(85973, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3715.11, 5450.06, 40.587, 5.51651, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(94599, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 4057, 5525.65, 35.653, 1.75839, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(94409, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 4037.89, 5415.51, 31.1961, 5.04529, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(94408, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3926.44, 5384.85, 26.7329, 5.42621, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(94407, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3824.33, 5360.42, 26.7441, 5.94458, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118151, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3443, 5312, 40, 6.27969, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118153, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3426, 5249, 34.9959, 5.07062, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118154, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3689.98, 5152.41, 29.4468, 4.83064, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118155, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3333, 5265, 35, 5.10203, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118156, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3553.23, 5324.84, 31.3481, 4.66486, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118157, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3636.38, 5253.8, 34.0268, 5.10467, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(118158, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3610, 5186, 28, 5.61996, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(94406, 25850, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3758.66, 5252.33, 32.1614, 2.22179, 600, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116670, 25850, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3333.38, 5264.56, 35.4964, 4.59136, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116671, 25850, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3250.39, 5391.88, 48.7101, 2.86741, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116672, 25850, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3157.04, 5430.92, 56.8964, 3.90806, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=25968;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(118160, 25968, 571, 3537, 3537, 1, 0, 0, 0, -1, 0, 0, 3159.81, 5921.27, 94.9736, 4.85843, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116673, 25968, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 3363.12, 5765.58, 67.1089, 3.13917, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE `id` IN (25844,25355,25321);
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '25355' AND `Item` = '34711'; 
DELETE FROM `creature_template_addon` WHERE (`entry`=25449);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25449, 0, 0, 0, 1, 233, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=25321);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25321, 0, 0, 0, 1, 233, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=25322);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25322, 0, 0, 65537, 1, 0, ''); 

UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (25321);
DELETE FROM `creature_template_addon` WHERE (`entry`=25321);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25321, 0, 0, 0, 1, 69, '');