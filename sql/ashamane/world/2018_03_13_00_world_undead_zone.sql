DELETE FROM `creature` WHERE `guid` IN (193850, 193854, 193855, 193857, 372910, 372908, 372913);
UPDATE `creature_template` SET `ScriptName`="" WHERE `entry`=49044;
UPDATE `creature_template` SET `gossip_menu_id`=12487 WHERE `entry`=49231;
DELETE FROM `gameobject` WHERE guid IN (162715, 162716);
UPDATE `gameobject` SET `guid`=20375604 WHERE `guid`=162714;
UPDATE `gameobject` SET `spawnMask`='1', `PhaseId`='0', `PhaseGroup`='0', `position_x`='1669.96', `position_y`='1692.84', `position_z`='120.719', `orientation`='3.89209', `rotation0`='0', `rotation1`='0', `rotation2`='0.930417', `rotation3`='-0.366504', `spawntimesecs`='120', `animprogress`='255', `state`='1', `ScriptName`='', `VerifiedBuild`='0' WHERE (`guid`=20375604);
UPDATE `gameobject` SET `spawnMask`='1', `PhaseId`='0', `PhaseGroup`='0', `position_x`='1669.49', `position_y`='1692.53', `position_z`='121.907', `orientation`='3.49067', `rotation0`='0', `rotation1`='0', `rotation2`='0.984807', `rotation3`='-0.173654', `spawntimesecs`='120', `animprogress`='255', `state`='1', `ScriptName`='', `VerifiedBuild`='0' WHERE (`guid`=20375605);
UPDATE `gameobject` SET `spawnMask`='1', `PhaseId`='0', `PhaseGroup`='0', `position_x`='1668.57', `position_y`='1693.53', `position_z`='121.916', `orientation`='1.88495', `rotation0`='0', `rotation1`='0', `rotation2`='0.809015', `rotation3`='0.587788', `spawntimesecs`='120', `animprogress`='255', `state`='1', `ScriptName`='', `VerifiedBuild`='0' WHERE (`guid`=20375606);
UPDATE `creature_template` SET `difficulty_entry_1`='0', `difficulty_entry_2`='0', `difficulty_entry_3`='0', `KillCredit1`='0', `KillCredit2`='0', `modelid1`='2467', `modelid2`='2403', `modelid3`='0', `modelid4`='0', `name`='Scarlet Corpse', `femaleName`='', `subname`='', `TitleAlt`=NULL, `IconName`='questinteract', `gossip_menu_id`='0', `minlevel`='3', `maxlevel`='4', `HealthScalingExpansion`='0', `RequiredExpansion`='0', `VignetteID`='0', `faction`='7', `npcflag`='2', `speed_walk`='1', `speed_run`='0.857143', `scale`='1', `rank`='0', `dmgschool`='0', `BaseAttackTime`='2000', `RangeAttackTime`='2000', `BaseVariance`='1', `RangeVariance`='1', `unit_class`='8', `unit_flags`='537166592', `unit_flags2`='2049', `unit_flags3`='0', `dynamicflags`='0', `family`='0', `trainer_class`='0', `type`='7', `type_flags`='0', `type_flags2`='0', `lootid`='0', `pickpocketloot`='0', `skinloot`='0', `resistance1`='0', `resistance2`='0', `resistance3`='0', `resistance4`='0', `resistance5`='0', `resistance6`='0', `spell1`='0', `spell2`='0', `spell3`='0', `spell4`='0', `spell5`='0', `spell6`='0', `spell7`='0', `spell8`='0', `VehicleId`='0', `mingold`='0', `maxgold`='0', `AIName`='SmartAI', `MovementType`='0', `InhabitType`='3', `HoverHeight`='1', `HealthModifier`='1', `HealthModifierExtra`='1', `ManaModifier`='1', `ManaModifierExtra`='1', `ArmorModifier`='1', `DamageModifier`='1', `ExperienceModifier`='1', `RacialLeader`='0', `movementId`='100', `RegenHealth`='1', `mechanic_immune_mask`='0', `flags_extra`='0', `ScriptName`='', `VerifiedBuild`='25549' WHERE (`entry`='49340');

-- Agatha SAI
SET @ENTRY := 49044;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,24959,0,0,0,11,73524,0,0,0,0,0,7,0,0,0,0,0,0,0,"Agatha - On quest 24959 - cast spell"),
(@ENTRY,0,1,0,61,0,100,512,0,0,0,0,28,73523,0,0,0,0,0,7,0,0,0,0,0,0,0,"Agatha - Remove aura from the player");

-- Aradne SAI
SET @ENTRY := 50372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,512,0,0,0,0,53,0,50372,1,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,512,2,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,512,4,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,512,18,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 18 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,512,25,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 25 Reached - Run Script"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Script - Pause Waypoint"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,11,93446,0,0,0,0,0,19,50373,5,0,0,0,0,0,"Aradne - On Script - Cast 'Raise Undead'"),
(@ENTRY*100+00,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Script - Say Line 0"),
(@ENTRY*100+00,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,50373,10,0,0,0,0,0,"Aradne - On Script - Set Data 1 1");

-- Waypoints for Aradne
DELETE FROM `waypoints` WHERE `entry`=50372;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
('50372', '1', '1698.53', '1687.82', '134.825', 'Aradne'),
('50372', '2', '1696.9', '1688.16', '135.093', 'Aradne'),
('50372', '3', '1696.82', '1680.22', '134.648', 'Aradne'),
('50372', '4', '1695.54', '1680.51', '134.857', 'Aradne'),
('50372', '5', '1694.45', '1675.17', '134.582', 'Aradne'),
('50372', '6', '1691.49', '1672.14', '134.725', 'Aradne'),
('50372', '7', '1686.68', '1671.13', '135.499', 'Aradne'),
('50372', '8', '1683.32', '1672.1', '136.382', 'Aradne'),
('50372', '9', '1676.21', '1673.95', '137.504', 'Aradne'),
('50372', '10', '1672.78', '1674.63', '138.265', 'Aradne'),
('50372', '11', '1671.65', '1680.4', '139.247', 'Aradne'),
('50372', '12', '1672.95', '1685.73', '139.639', 'Aradne'),
('50372', '13', '1673.6', '1688.58', '139.695', 'Aradne'),
('50372', '14', '1675.72', '1697.68', '140.331', 'Aradne'),
('50372', '15', '1682.36', '1695.94', '138.045', 'Aradne'),
('50372', '16', '1688.03', '1692.28', '137.092', 'Aradne'),
('50372', '17', '1686.76', '1686.93', '137.07', 'Aradne'),
('50372', '18', '1683.31', '1686.49', '137.777', 'Aradne'),
('50372', '19', '1688.84', '1685.97', '136.565', 'Aradne'),
('50372', '20', '1701.76', '1685.93', '134.241', 'Aradne'),
('50372', '21', '1701.76', '1685.93', '134.241', 'Aradne'),
('50372', '22', '1708.09', '1692.04', '133.826', 'Aradne'),
('50372', '23', '1707.34', '1696.12', '133.928', 'Aradne'),
('50372', '24', '1704.29', '1699.33', '134.399', 'Aradne'),
('50372', '25', '1707.4', '1700.54', '134.079', 'Aradne');

-- Deathknell Grave Target SAI
SET @ENTRY := 50373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,512,1,1,0,0,11,93447,2,0,0,0,0,1,0,0,0,0,0,0,0,"Deathknell Grave Target - On Data Set 1 1 - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,25,0,100,512,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathknell Grave Target - On Reset - Set Visibility Off");

-- Risen Dead SAI
SET @ENTRY := 50374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Just Summoned - Run Random Script"),
(@ENTRY*100+00,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 0"),
(@ENTRY*100+00,9,1,0,0,0,100,0,4000,4000,0,0,3,1501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Morph To Creature Mindless Zombie"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 5"),
(@ENTRY*100+00,9,3,0,0,0,100,0,0,0,0,0,75,44427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Add Aura 'Enrage'"),
(@ENTRY*100+00,9,4,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*100+00,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Start Waypoint"),
(@ENTRY*100+00,9,5,0,0,0,100,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Despawn In 9000 ms"),
(@ENTRY*100+01,9,0,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 1"),
(@ENTRY*100+01,9,1,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 2"),
(@ENTRY*100+01,9,2,0,0,0,100,0,2000,2000,0,0,53,0,@ENTRY*100+01,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Start Waypoint"),
(@ENTRY*100+01,9,3,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 7"),
(@ENTRY*100+01,9,4,0,0,0,100,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Despawn In 9000 ms"),
(@ENTRY*100+02,9,0,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 3"),
(@ENTRY*100+02,9,1,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 4"),
(@ENTRY*100+02,9,2,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 6"),
(@ENTRY*100+02,9,3,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Kill Self");

-- Caretaker Caice SAI
SET @ENTRY := 2307;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,512,24960,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caice - On quest accpet - Actionlist"),
(@ENTRY,0,1,0,19,0,100,0,25089,0,0,0,85,91938,0,0,0,0,0,7,0,0,0,0,0,0,0,"Caice - On Quest Accept - Cast Spell To Summon"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,12,49231,3,120000,0,0,0,8,0,0,0,1740.36,1704.34,128.765,1.55296,"Caice - Actionlist - cast spell"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,12,38895,3,120000,0,0,0,8,0,0,0,1757.48,1666.03,121.208,0.02929,"Caice - Actionlist - Cast spell"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,12,49230,3,120000,0,0,0,8,0,0,0,1753.89,1640.63,117.495,0,"Caice - Actionlist - Cast spell");

-- Marshal Redpath SAI
SET @ENTRY := 49230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,512,12486,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal - On Gossip Select - Actionlist"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Marshal - Actionlist - Close gossip"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,85,91873,0,0,0,0,0,7,0,0,0,0,0,0,0,"Marshal - Actionlist - Cast summon Marshal"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal - Actionlist - despawn");

-- Marshal Redpath SAI
SET @ENTRY := 66167;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal - On Gossip Select - Actionlist"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal - Actionlist - Talk1"),
(@ENTRY*100+00,9,1,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,1753.04,1613.1,113.051,2.0146,"Marshal - Action list - Go to point"),
(@ENTRY*100+00,9,2,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal - Actionlist - Despawn");

-- Lilian Voss SAI
SET @ENTRY := 38895;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,512,12484,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian - On Gossip Select - Actionlist"),
(@ENTRY,0,1,0,54,0,100,512,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian - On spawn - set emote state"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian - Actionlist - Close gossip"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,85,91874,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian - Actionlist - Cast summon Lilian"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian - Actionlist - despawn");

-- Lilian Voss SAI
SET @ENTRY := 66166;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian - On Gossip Select - Actionlist"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian - Actionlist - Talk1"),
(@ENTRY*100+00,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,1727.87,1629.11,118.862,5.49784,"Lilian - Action list - Go to point"),
(@ENTRY*100+00,9,2,0,0,0,100,0,6000,6000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian - Actionlist - Despawn");

-- Valdred Moray SAI
SET @ENTRY := 49231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,512,12489,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - On Gossip Select - Actionlist"),
(@ENTRY,0,1,0,54,0,100,512,0,0,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - On Just summoned - add aura state kneels"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Valdred - Actionlist - Close gossip"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,85,91876,0,0,0,0,0,7,0,0,0,0,0,0,0,"Valdred - Actionlist - Cast summon Valdred"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - Actionlist - despawn");

-- Valdred Moray SAI
SET @ENTRY := 66168;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - On Gossip Select - Actionlist"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - Actionlist - Talk1"),
(@ENTRY*100+00,9,1,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,1689.71,1674.79,135.675,0.349066,"Valdred - Action list - Go to point"),
(@ENTRY*100+00,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - Actionlist - Talk2"),
(@ENTRY*100+00,9,3,0,0,0,100,0,5000,5000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred - Actionlist - Despawn");

-- Undertaker Mordo SAI
SET @ENTRY := 1568;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,28608,0,0,0,85,91576,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mordo - On Quest Accept - Cast Spell To Summon");

-- Darnell SAI
SET @ENTRY := 49141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03,@ENTRY*100+04) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Just Summoned - Run Script"),
(@ENTRY,0,1,0,40,0,100,512,4,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,512,8,0,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,512,9,0,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 9 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,512,10,0,0,0,80,@ENTRY*100+04,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 10 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,13,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 13 Reached - Say Line 10"),
(@ENTRY,0,6,0,40,0,100,512,17,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Waypoint 17 Reached - Despawn Instant"),
(@ENTRY,0,7,0,54,0,100,512,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Just Summoned - Set Reactstate Passive"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 0"),
(@ENTRY*100+00,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 1"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,53,1,49141,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Start Waypoint"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 2"),
(@ENTRY*100+02,9,0,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Pause Waypoint"),
(@ENTRY*100+02,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 3"),
(@ENTRY*100+03,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Pause Waypoint"),
(@ENTRY*100+03,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 4"),
(@ENTRY*100+03,9,2,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 5"),
(@ENTRY*100+03,9,3,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 6"),
(@ENTRY*100+03,9,4,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 7"),
(@ENTRY*100+04,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Pause Waypoint"),
(@ENTRY*100+04,9,1,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 8"),
(@ENTRY*100+04,9,2,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On Script - Say Line 9");

-- Darnell SAI
SET @ENTRY := 49337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Action list"),
(@ENTRY,0,1,0,40,0,100,512,5,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1"),
(@ENTRY,0,2,0,40,0,100,512,7,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1"),
(@ENTRY,0,3,0,54,0,100,512,0,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Action list"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - set ReactState passif"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1"),
(@ENTRY*100+00,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1"),
(@ENTRY*100+00,9,3,0,0,0,100,0,0,0,0,0,53,1,49337,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - Action list - Start wp"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - set ReactState passif"),
(@ENTRY*100+01,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1"),
(@ENTRY*100+01,9,2,0,0,0,100,0,6000,6000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1");

-- Deathguard Saltain SAI
SET @ENTRY := 1740;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+01,@ENTRY*100+00) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,512,26800,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltain - On Quest accept- action list"),
(@ENTRY,0,1,0,20,0,100,512,26800,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltain - On Quest rewarded- action list"),
(@ENTRY,0,2,0,20,0,100,512,25089,0,0,0,41,0,0,0,0,0,0,19,49337,20,0,0,0,0,0,"Saltain - On Quest rewarded - despawn"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,49337,20,0,0,0,0,0,"Saltain - action list - Despawn"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,49340,20,0,0,0,0,0,"Saltain - action list - Despawn"),
(@ENTRY*100+01,9,0,0,0,0,100,0,3000,3000,0,0,85,91938,0,0,0,0,0,7,0,0,0,0,0,0,0,"Saltain - Action list - Cast Spell To Summon");

-- Deathguard Randolph SAI
SET @ENTRY := 1736;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,512,1000,2000,2000,3000,11,95826,66,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Randolph - In Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,25,0,100,512,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Randolph - On Reset - Set Reactstate Aggressive");

-- Rattlecage Skeleton SAI
SET @ENTRY := 1890;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,15000,15000,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"1890 - IC - CAST");

-- Scarlet Corpse SAI
SET @ENTRY := 49340;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,75,0,100,513,0,49337,3,0,86,91945,2,19,49337,20,0,1,0,0,0,0,0,0,0,"Corpse - On DISTANCE_CREATURE - cross cast"),
(@ENTRY,0,1,0,61,0,100,512,0,0,0,0,11,46598,2,0,0,0,0,19,49337,20,0,0,0,0,0,"Corpse - On DISTANCE_CREATURE - cast");

-- Lilian Voss SAI
SET @ENTRY := 38910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+00,@ENTRY*100+01) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,1,100,512,11133,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 1)"),
(@ENTRY,0,1,8,61,1,100,512,11133,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 1)"),
(@ENTRY,0,2,3,62,2,100,512,11133,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 2)"),
(@ENTRY,0,3,9,61,2,100,512,11133,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 2)"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Reset - Set Emote State 431"),
(@ENTRY,0,5,0,25,0,100,512,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Reset - Set Event Phase 1"),
(@ENTRY,0,6,0,40,0,100,0,11,@ENTRY*100+00,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Waypoint 11 Reached - Set Emote State 431"),
(@ENTRY,0,7,0,40,0,100,0,11,@ENTRY*100+01,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Waypoint 11 Reached - Set Emote State 431"),
(@ENTRY,0,8,0,61,0,100,512,11133,0,0,0,85,73210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)"),
(@ENTRY,0,9,0,61,0,100,512,11133,0,0,0,85,73210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY*100+00,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY*100+00,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY*100+00,9,3,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*100+00,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Start Waypoint"),
(@ENTRY*100+00,9,4,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 2"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY*100+01,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY*100+01,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY*100+01,9,3,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*100+01,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Start Waypoint"),
(@ENTRY*100+01,9,4,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 1");

UPDATE `gossip_menu_option` SET `MenuId`='11132', `OptionIndex`='0', `OptionIcon`='0', `OptionText`='You\'re not hideous, Lilian... you\'re one of us.  Here, look in this mirror, see for yourself.', `OptionBroadcastTextId`='0', `OptionType`='0', `OptionNpcFlag`='0', `VerifiedBuild`='0' WHERE (`MenuId`='11132') AND (`OptionIndex`='0');
-- Table `creature_template`
UPDATE `creature_template` SET `gossip_menu_id` = 11133 WHERE (entry = 38910);
DELETE FROM `creature_queststarter` WHERE id=1569 AND quest IN (3095, 3096, 3097, 3098, 3099, 28651, 31146);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES 
('1569', '28651');
DELETE FROM `creature_queststarter` WHERE id=2124 AND quest IN (24965, 28651);
DELETE FROM `creature_queststarter` WHERE id=38911 AND quest IN (24962, 24964, 28651);
DELETE FROM `creature_template_addon` WHERE entry=49425 AND auras=49415;

-- Young Night Web Spider SAI
SET @ENTRY := 1504;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,3000,7000,11,6751,32,0,0,0,0,2,0,0,0,0,0,0,0,"Young Night Web Spider - In Combat - Cast 'Weak Poison'");

-- Night Web Spider SAI
SET @ENTRY := 1505;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,15000,15000,11,6751,0,0,0,0,0,2,0,0,0,0,0,0,0,"1505 - IC - CAST");
