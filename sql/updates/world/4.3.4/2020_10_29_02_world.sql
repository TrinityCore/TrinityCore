SET @CGUID := 396548;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Cathedral
(@CGUID+0, 44751, 189, 796, 0, 1, 169, 0, 0, 0, 905.70697021484375, 1399.7099609375, 18.10663414001464843, 0, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+1, 44751, 189, 796, 0, 1, 169, 0, 0, 0, 906.67901611328125, 1380.9599609375, 18.09603309631347656, 0, 7200, 10, 0, 7662, 0, 1, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0) (Auras: 79877 - Bloodthirst) (possible waypoints or random movement)
(@CGUID+2, 44751, 189, 796, 0, 1, 169, 0, 0, 0, 908.3204345703125, 1422.6181640625, 18.00206184387207031, 5.426711559295654296, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+3, 44751, 189, 796, 0, 1, 169, 0, 0, 0, 942.49102783203125, 1375.47998046875, 18.10823440551757812, 0, 7200, 10, 0, 7662, 0, 1, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0) (Auras: 79877 - Bloodthirst) (possible waypoints or random movement)
(@CGUID+4, 44751, 189, 796, 0, 1, 169, 0, 0, 0, 946.8837890625, 1426.01708984375, 18.02327156066894531, 6.092455387115478515, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+5, 44805, 189, 796, 0, 1, 169, 0, 0, 0, 971.72198486328125, 1399.3599853515625, 27.21953392028808593, 6.2657318115234375, 7200, 0, 0, 14937, 0, 0, 0, 0, 0, 15595), -- Dominic (Area: 0 - Difficulty: 0)
(@CGUID+6, 53488, 189, 796, 0, 1, 169, 0, 0, 0, 857.8836669921875, 1321.94970703125, 18.7582244873046875, 0, 7200, 0, 0, 12600, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: 0 - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+7, 53488, 189, 796, 0, 1, 169, 0, 0, 0, 871.34375, 1321.19970703125, 18.08933639526367187, 0, 7200, 0, 0, 12600, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: 0 - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+8, 44746, 189, 796, 0, 1, 169, 0, 2461, 0, 933.87701416015625, 1400.6700439453125, 18.42433357238769531, 3.124139308929443359, 7200, 0, 0, 8754, 0, 0, 0, 0, 0, 15595), -- Joseph the Insane (Area: 0 - Difficulty: 0)
-- Graveyard
(@CGUID+9, 44728, 189, 76, 0, 1, 169, 0, 2461, 0, 1695.14, 1098.05, 6.9033337, 0, 7200, 0, 0, 5730, 0, 0, 0, 0, 0, 15595), -- Joseph the Awakened (Area: 0 - Difficulty: 0)
(@CGUID+10, 44736, 189, 796, 0, 1, 169, 0, 0, 0, 1697.94, 1095.16, 6.9033237, 6.195918560028076171, 7200, 0, 0, 3200, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0)
(@CGUID+11, 44736, 189, 796, 0, 1, 169, 0, 0, 0, 1697.99, 1101.1, 6.9033237, 6.24827861785888671, 7200, 0, 0, 3200, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0)
-- Armory
(@CGUID+12, 44741, 189, 796, 0, 1, 169, 0, 2461, 0, 1624.6, -338.045, 18.090734, 0.03490658476948738, 7200, 0, 0, 7662, 0, 0, 0, 0, 0, 15595), -- Joseph the Crazed (Area: 0 - Difficulty: 0)
(@CGUID+13, 44742, 189, 796, 0, 1, 169, 0, 0, 0, 1626.1, -342.448, 18.090734, 0.750491559505462646, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0)
(@CGUID+14, 44742, 189, 796, 0, 1, 169, 0, 0, 0, 1626.19, -333.069, 18.090834, 5.567600250244140625, 7200, 0, 0, 4440, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0)
(@CGUID+15, 44804, 189, 796, 0, 1, 169, 0, 0, 0, 1667.1, -359.752, 18.106634, 3.106686115264892578, 7200, 0, 0, 9156, 0, 0, 0, 0, 0, 15595), -- Dominic (Area: 0 - Difficulty: 0)
-- Library
(@CGUID+16, 44800, 189, 796, 0, 1, 169, 0, 0, 0, 161.776, -306.748, 18.612635, 0.01745329238474369, 7200, 0, 0, 9156, 0, 0, 0, 0, 0, 15595), -- Dominic (Area: 0 - Difficulty: 0)
(@CGUID+17, 44738, 189, 76, 0, 1, 169, 0, 2461, 0, 275.241, -228.068, 18.614035, 3.159045934677124023, 7200, 0, 0, 6660, 0, 0, 0, 0, 0, 15595), -- Joseph the Awakened (Area: 0 - Difficulty: 0)
(@CGUID+18, 44739, 189, 796, 0, 1, 169, 0, 0, 0, 278.085, -228.148, 18.614035, 3.263765573501586914, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0)
(@CGUID+19, 44739, 189, 796, 0, 1, 169, 0, 0, 0, 275.082, -231.155, 18.614035, 3.263765573501586914, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15595), -- Scarlet Renegade (Area: 0 - Difficulty: 0)
(@CGUID+20, 44739, 189, 796, 0, 1, 169, 0, 0, 0, 275.135, -225.168, 18.614035, 3.263765573501586914, 7200, 0, 0, 3820, 0, 0, 0, 0, 0, 15595); -- Scarlet Renegade (Area: 0 - Difficulty: 0)


UPDATE `creature_template` SET `faction`=14 WHERE `entry`=4300; -- Scarlet Wizard
UPDATE `creature_template` SET `faction`=14 WHERE `entry`=4301; -- Scarlet Centurion
UPDATE `creature_template` SET `faction`=14 WHERE `entry`=4298; -- Scarlet Defender
UPDATE `creature_template` SET `faction`=14 WHERE `entry`=4295; -- Scarlet Myrmidon
UPDATE `creature_template` SET `faction`=14 WHERE `entry`=4294; -- Scarlet Sorcerer
UPDATE `creature_template` SET `exp`= 0 WHERE `entry` IN (44751, 44805, 44746, 51659, 51660, 44728, 44736, 44741, 44742, 44800, 44804, 44738, 44739);

INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+8, 0, 0, 0, 1, 10, ''), -- Joseph the Insane
(@CGUID+10, 0, 0, 8, 1, 0, ''), -- Scarlet Renegade
(@CGUID+11, 0, 0, 8, 1, 0, ''), -- Scarlet Renegade
(@CGUID+12, 0, 0, 0, 1, 375, ''), -- Joseph the Crazed
(@CGUID+13, 0, 0, 0, 1, 333, ''), -- Scarlet Renegade
(@CGUID+14, 0, 0, 0, 1, 333, ''), -- Scarlet Renegade
(@CGUID+15, 0, 0, 0, 1, 0, '58506'), -- Dominic
(@CGUID+16, 0, 0, 0, 1, 0, '58506'), -- Dominic
(@CGUID+18, 0, 0, 1, 1, 0, ''), -- Scarlet Renegade
(@CGUID+19, 0, 0, 1, 1, 0, ''), -- Scarlet Renegade
(@CGUID+20, 0, 0, 1, 1, 0, ''); -- Scarlet Renegade

UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE `CreatureID` IN (44805, 44804, 44800) AND `ID`=1; -- Dominic

DELETE FROM `creature_sparring_template` WHERE `CreatureID` IN (44751, 4301, 4298, 4295, 4294, 4300);
INSERT INTO `creature_sparring_template` (`CreatureID`, `HealthLimitPct`) VALUES
(44751, 100),
(4301, 100),
(4298, 100),
(4295, 100),
(4294, 100),
(4300, 100);

SET @ENTRY := -40131;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

SET @ENTRY := -40126;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

SET @ENTRY := -39945;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

SET @ENTRY := -39955;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

SET @ENTRY := -39952;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

SET @ENTRY := -39950;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

SET @ENTRY := -39948;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Kill self (Self) // ");

UPDATE `creature` SET `MovementType`= 0, `spawndist`= 0 WHERE `guid` IN (27438, 27439);
DELETE FROM `creature` WHERE `guid` IN (40071, 40072);
