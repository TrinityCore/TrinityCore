SET @MOP_CGUID := 4000790;
SET @CATA_CGUID := 3000068;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @MOP_CGUID+0 AND @MOP_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@MOP_CGUID+0, 68993, 654, 4755, 4757, '0', 170, 0, 0, 1, -1675.2916259765625, 1312.404541015625, 20.376007080078125, 0.63726353645324707, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796); -- Fenegan Cobbler (Area: Military District - Difficulty: 0) CreateObject1

DELETE FROM `creature` WHERE `guid` BETWEEN @CATA_CGUID+0 AND @CATA_CGUID+29;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CATA_CGUID+0, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1653.6458740234375, 1379.4913330078125, 15.60750007629394531, 3.405575275421142578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+1, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1658.25, 1382.9478759765625, 15.21820068359375, 4.449835777282714843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+2, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1659.5555419921875, 1387.951416015625, 15.21820068359375, 4.100589752197265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+3, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1679.9791259765625, 1336.9896240234375, 15.21820354461669921, 3.671442985534667968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+4, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1654.607666015625, 1385.7379150390625, 16.42245864868164062, 1.855664014816284179, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CATA_CGUID+5, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1662.30908203125, 1343.8992919921875, 15.21820259094238281, 1.463005423545837402, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CATA_CGUID+6, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1672.0972900390625, 1372.9114990234375, 15.43614006042480468, 1.944400906562805175, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CATA_CGUID+7, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1763.907958984375, 1398.4913330078125, 20.0507965087890625, 1.792035937309265136, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+8, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1767.8211669921875, 1449.888916015625, 20.2497406005859375, 4.300688743591308593, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+9, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1723.076416015625, 1354.2396240234375, 19.91219329833984375, 3.135169744491577148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+10, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1715.032958984375, 1413.7396240234375, 21.75195884704589843, 2.210048675537109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+11, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1729.30908203125, 1399.4791259765625, 21.75195693969726562, 0.919301509857177734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+12, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1768.876708984375, 1434.01220703125, 20.09717369079589843, 1.566175460815429687, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CATA_CGUID+13, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1683.6510009765625, 1401.7379150390625, 21.75196075439453125, 4.967428207397460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+14, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1700.71533203125, 1377.5225830078125, 23.0797576904296875, 1.344216823577880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+15, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1704.798583984375, 1425.265625, 21.75196075439453125, 2.501429557800292968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+16, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1682.0416259765625, 1414.9617919921875, 21.75196075439453125, 2.252556800842285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+17, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1711.1353759765625, 1439.43408203125, 21.75196075439453125, 0.680921733379364013, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+18, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1742.90625, 1420.7552490234375, 23.06669235229492187, 5.402272224426269531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+19, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1693.439208984375, 1387.392333984375, 21.75196075439453125, 5.662716388702392578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+20, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1729.30908203125, 1399.4791259765625, 21.75195693969726562, 4.472270011901855468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+21, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1742.90625, 1420.7552490234375, 23.06669235229492187, 5.424035072326660156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+22, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1749.1788330078125, 1429.0555419921875, 52.82616424560546875, 2.156510591506958007, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+23, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1685.201416015625, 1381.6129150390625, 52.37047195434570312, 5.026099205017089843, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63796), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+24, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1696.24658203125, 1370.3941650390625, 23.10253334045410156, 3.737882375717163085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63834), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+25, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1721.2725830078125, 1391.6788330078125, 21.75195693969726562, 5.906992912292480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63834), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+26, 35118, 654, 4755, 4757, '0', 170, 0, 0, 0, -1723.5347900390625, 1395.2117919921875, 21.75195693969726562, 6.067309856414794921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63834), -- Bloodfang Worgen (Area: Military District - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+27, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1733.3021240234375, 1417.5521240234375, 21.75196266174316406, 0.410463958978652954, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63906), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+28, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1747.2379150390625, 1489.732666015625, 56.73279953002929687, 4.787479400634765625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63906), -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)
(@CATA_CGUID+29, 35118, 654, 4755, 4762, '0', 170, 0, 0, 0, -1795.4896240234375, 1465.704833984375, 56.32892608642578125, 0.044075191020965576, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63906); -- Bloodfang Worgen (Area: Stoneward Prison - Difficulty: 0) CreateObject2 (Auras: 83470 - Arcane Missiles Trainer)

-- Delete old spawns
DELETE FROM `creature` WHERE `guid` IN (376486,376487,376488,376496,376499,376500,376502,376504,376510,376514,376515,376517,376518,376519,376521,376526,376528,376532,376560,376561,376563,376564,376574,376575,376577,376580,376584,376585,376587,376591,376592,376593,376645,376646,376653,376654,376655,376656,376657,376658,376659,376660,376661);
DELETE FROM `creature_addon` WHERE `guid` IN (376486,376487,376488,376496,376499,376500,376502,376504,376510,376514,376515,376517,376518,376519,376521,376526,376528,376532,376560,376561,376563,376564,376574,376575,376577,376580,376584,376585,376587,376591,376592,376593,376645,376646,376653,376654,376655,376656,376657,376658,376659,376660,376661);

-- Template
UPDATE `creature_template` SET `npcflag`=4194433, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=68993; -- Fenegan Cobbler
UPDATE `creature_template` SET `npcflag`=0, `unit_flags3`=0x10 WHERE `entry`=35118; -- Bloodfang Worgen

-- Update _addon
UPDATE `creature_addon` SET `emote` = 214 WHERE `guid` = 376492;
UPDATE `creature_addon` SET `VisFlags` = 2, `emote` = 433 WHERE `guid` = 376506;
UPDATE `creature_addon` SET `emote` = 333 WHERE `guid` IN (376512, 376558, 376512, 376524, 376516, 376566, 376571, 376567, 376520, 376522, 376570, 376529, 376539);

-- Sparring
DELETE FROM `creature_template_sparring` WHERE `Entry` IN (35118,35839,35872,35232);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(35118, 85),
(35839, 85),
(35872, 85),
(35232, 85);

-- Update phaseId
UPDATE `gameobject` SET `PhaseId` = 171 WHERE `guid` = 235509;

-- Update Questchain condition for Mages
UPDATE `conditions` SET `ConditionValue1` = 128 WHERE `SourceTypeOrReferenceId` = 19 AND `SourceEntry` = 14277 AND `ConditionTypeOrReference` = 15; -- Mage

-- Update Royal Guards with createobject2 data
UPDATE `creature` SET `position_x` = -1715.4427, `position_y` = 1359.4774, `position_z` = 19.753815, `orientation` = 5.218534469 WHERE `guid` = 376512;
UPDATE `creature` SET `position_x` = -1719.9257, `position_y` = 1403.4231, `position_z` = 21.668627, `orientation` = 1.466076612 WHERE `guid` = 376539;
UPDATE `creature` SET `position_x` = -1698.9045, `position_y` = 1425.8473, `position_z` = 21.668627, `orientation` = 3.211405754 WHERE `guid` = 376567;
UPDATE `creature` SET `position_x` = -1702.8055, `position_y` = 1386.316, `position_z` = 21.668623, `orientation` = 4.86946868 WHERE `guid` = 376516;

UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (376512,376539,376567,376516);

-- Update Rat with createobject2 data
UPDATE `creature` SET `position_x` = -1698.23095703125, `position_y` = 1403.454833984375, `position_z` = 21.75196075439453125, `orientation` = 3.777878046035766601 WHERE `guid` = 376537;
UPDATE `creature` SET `position_x` = -1747.8975830078125, `position_y` = 1377.548583984375, `position_z` = 19.90350151062011718, `orientation` = 5.314441680908203125 WHERE `guid` = 376534;
UPDATE `creature` SET `position_x` = -1634.842041015625, `position_y` = 1316.5069580078125, `position_z` = 19.82200050354003906, `orientation` = 1.665708661079406738 WHERE `guid` = 376479;
UPDATE `creature` SET `position_x` = -1684.80908203125, `position_y` = 1351.671875, `position_z` = 15.21820354461669921, `orientation` = 2.51299428939819335 WHERE `guid` = 376489;
UPDATE `creature` SET `position_x` = -1641.1441650390625, `position_y` = 1304.8072509765625, `position_z` = 19.74629592895507812, `orientation` = 3.118392229080200195 WHERE `guid` = 376485;
UPDATE `creature` SET `position_x` = -1777.170166015625, `position_y` = 1335.984375, `position_z` = 19.99603271484375, `orientation` = 0.870490133762359619 WHERE `guid` = 376556;
UPDATE `creature` SET `position_x` = -1728.592041015625, `position_y` = 1464.94970703125, `position_z` = 24.6467132568359375, `orientation` = 2.457567691802978515 WHERE `guid` = 376594;
UPDATE `creature` SET `position_x` = -1768.6910400390625, `position_y` = 1411.1927490234375, `position_z` = 19.8656463623046875, `orientation` = 1.719511151313781738 WHERE `guid` = 376590;

UPDATE `creature` SET `wander_distance` = 4, `MovementType` = 1 WHERE `guid` IN (376537,376534,376489);

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35115 AND `DifficultyID`=0); -- 35115 (Lord Godfrey) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35112 AND `DifficultyID`=0); -- 35112 (King Genn Greymane) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=38853 AND `DifficultyID`=0); -- 38853 (Marie Allen) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35872 AND `DifficultyID`=0); -- 35872 (Myriam Spellwaker) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35232 AND `DifficultyID`=0); -- 35232 (Gilnean Royal Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35233 AND `DifficultyID`=0); -- 35233 (Gilnean Survivor) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35912 AND `DifficultyID`=0); -- 35912 (Injured Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35870 AND `DifficultyID`=0); -- 35870 (Sister Almyra) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35871 AND `DifficultyID`=0); -- 35871 (Loren the Fence) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=47091 AND `DifficultyID`=0); -- 47091 (Wounded Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35118 AND `DifficultyID`=0); -- 35118 (Bloodfang Worgen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=68993 AND `DifficultyID`=0); -- 68993 (Fenegan Cobbler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=35873 AND `DifficultyID`=0); -- 35873 (Celestine of the Harvest) - CanSwim - CannotTurn

UPDATE `creature_model_info` SET `VerifiedBuild`=63796 WHERE `DisplayID` IN (30214, 36777, 29290, 30217, 29675, 29613, 1418, 36743, 30289, 30215, 30218, 29467, 29935, 29958, 23960, 29957, 29466, 36770, 29959, 29960, 36772, 36771, 47022, 1141, 29956, 29961);
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `VerifiedBuild`=63796 WHERE `DisplayID`=30213;

-- Vitus Darkwalker smart ai
SET @ENTRY := 35869;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 45104, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 45104 on self', '');

-- Celestine of the Harvest smart ai
SET @ENTRY := 35873;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 13236, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 13236 on self', '');

-- Myriam Spellwaker smart ai
SET @ENTRY := 35872;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 0, 0, 3000, 3000, 0, 11, 11538, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 3 seconds (0s initially) - Self: Cast spell  11538 on Victim', '');

-- Bloodfang Worgen smart ai
SET @ENTRY := 35118;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-30%% (once) - Self: Cast spell  8599 on Self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-30%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 19, 35839, 100, 0, 0, 0, 0, 0, 'On reset - Self: Attack Closest alive creature Sergeant Cleese (35839) in 100 yards', ''),
(@ENTRY, 0, 3, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1721.98, 1449.98, 52.2871, 0, 'On reset - Self: Jump to pos (-1721.98, 1449.98, 52.2871) with speed XY 14, speed Z 0 and gravity 0', ''),
(@ENTRY, 0, 4, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, 97, 14, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -1744.8444, 1429.2228, 52.747917, 0, 'On reset - Self: Jump to pos (-1744.8444, 1429.2228, 52.747917) with speed XY 14, speed Z 0 and gravity 0', '');

UPDATE `creature` SET `StringId` = 'CosmeticAttackTrainer' WHERE `guid` IN (@CATA_CGUID+3, @CATA_CGUID+2, @CATA_CGUID+1, @CATA_CGUID+0);
UPDATE `creature` SET `StringId` = 'Jump1' WHERE `guid` = @CATA_CGUID+29;
UPDATE `creature` SET `StringId` = 'Jump2' WHERE `guid` = @CATA_CGUID+28;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 35118 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 3, 35118, 0, 0, 58, 1, 0, 0, 0, 'CosmeticAttackTrainer', 0, 'Object has StringID CosmeticAttackTrainer'),
(22, 4, 35118, 0, 0, 58, 1, 0, 0, 0, 'Jump1', 0, 'Object has StringID Jump1'),
(22, 5, 35118, 0, 0, 58, 1, 0, 0, 0, 'Jump2', 0, 'Object has StringID Jump2');

-- Path for Rat
SET @MOVERGUID := 376479;
SET @ENTRY := 4075;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1653.3385, 1337.4653, 15.13487, NULL, 0),
(@PATH, 1, -1660.6615, 1347.5052, 15.13487, NULL, 0),
(@PATH, 2, -1664.0677, 1363.9392, 15.134865, NULL, 0),
(@PATH, 3, -1662.3733, 1381.9202, 15.134868, NULL, 0),
(@PATH, 4, -1647.8577, 1395.3021, 19.662964, NULL, 0),
(@PATH, 5, -1636.1621, 1398.0088, 20.211407, NULL, 0),
(@PATH, 6, -1633.2466, 1389.9688, 20.196787, NULL, 0),
(@PATH, 7, -1632.9514, 1370.4479, 20.0677, NULL, 0),
(@PATH, 8, -1633.1216, 1352.3368, 20.12424, NULL, 0),
(@PATH, 9, -1632.9514, 1370.4479, 20.0677, NULL, 0),
(@PATH, 10, -1633.2466, 1389.9688, 20.196787, NULL, 0),
(@PATH, 11, -1636.0243, 1398.0365, 20.18629, NULL, 0),
(@PATH, 12, -1647.8577, 1395.3021, 19.662964, NULL, 0),
(@PATH, 13, -1662.3733, 1381.9202, 15.134868, NULL, 0),
(@PATH, 14, -1664.0677, 1363.9392, 15.134865, NULL, 0),
(@PATH, 15, -1660.6615, 1347.5052, 15.13487, NULL, 0),
(@PATH, 16, -1653.3385, 1337.4653, 15.13487, NULL, 0),
(@PATH, 17, -1636.8663, 1337.7709, 19.738026, NULL, 0),
(@PATH, 18, -1635.0173, 1317.0035, 19.727987, NULL, 0),
(@PATH, 19, -1636.8663, 1337.7709, 19.738026, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Rat
SET @MOVERGUID := 376485;
SET @ENTRY := 4075;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1666.6442, 1304.9288, 19.782318, NULL, 0),
(@PATH, 1, -1680.301, 1301.131, 20.282387, NULL, 0),
(@PATH, 2, -1688.9618, 1302.083, 19.782318, NULL, 0),
(@PATH, 3, -1697.5414, 1303.2736, 20.282387, NULL, 0),
(@PATH, 4, -1715.3473, 1310.007, 19.782318, NULL, 0),
(@PATH, 5, -1730.007, 1319.6198, 19.782326, NULL, 0),
(@PATH, 6, -1731.3923, 1326.2223, 20.282742, NULL, 0),
(@PATH, 7, -1728.9791, 1333.6805, 20.282824, NULL, 0),
(@PATH, 8, -1730.007, 1319.6198, 19.782326, NULL, 0),
(@PATH, 9, -1715.3473, 1310.007, 19.782318, NULL, 0),
(@PATH, 10, -1697.5414, 1303.2736, 20.282387, NULL, 0),
(@PATH, 11, -1688.9618, 1302.083, 19.782318, NULL, 0),
(@PATH, 12, -1680.301, 1301.131, 20.282387, NULL, 0),
(@PATH, 13, -1666.6442, 1304.9288, 19.782318, NULL, 0),
(@PATH, 14, -1652.6702, 1305.0747, 19.782318, NULL, 0),
(@PATH, 15, -1641.6771, 1305.0035, 19.662964, NULL, 0),
(@PATH, 16, -1652.6702, 1305.0747, 19.782318, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Rat
SET @MOVERGUID := 376556;
SET @ENTRY := 4075;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1774.8716, 1358.2483, 19.74731, NULL, 0),
(@PATH, 1, -1785.6719, 1372.0938, 19.825752, NULL, 0),
(@PATH, 2, -1796.901, 1389.9323, 19.895927, NULL, 0),
(@PATH, 3, -1802.4028, 1406.1771, 19.836369, NULL, 0),
(@PATH, 4, -1805.7604, 1429.4045, 19.66714, NULL, 0),
(@PATH, 5, -1806.3455, 1446.8108, 19.048237, NULL, 0),
(@PATH, 6, -1805.7604, 1429.4045, 19.66714, NULL, 0),
(@PATH, 7, -1802.4028, 1406.1771, 19.836369, NULL, 0),
(@PATH, 8, -1796.901, 1389.9323, 19.895927, NULL, 0),
(@PATH, 9, -1785.6719, 1372.0938, 19.825752, NULL, 0),
(@PATH, 10, -1774.8716, 1358.2483, 19.74731, NULL, 0),
(@PATH, 11, -1770.0209, 1344.467, 19.853123, NULL, 0),
(@PATH, 12, -1776.5938, 1336.3594, 19.931509, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Rat
SET @MOVERGUID := 376594;
SET @ENTRY := 4075;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1731.474, 1501.7692, 26.049221, NULL, 0),
(@PATH, 1, -1734.3733, 1510.316, 26.222946, NULL, 0),
(@PATH, 2, -1739.1805, 1511.401, 26.222946, NULL, 0),
(@PATH, 3, -1768.8212, 1509.8993, 26.2533, NULL, 0),
(@PATH, 4, -1800.8351, 1513.0226, 19.78232, NULL, 0),
(@PATH, 5, -1791.6702, 1534.0122, 21.063742, NULL, 0),
(@PATH, 6, -1800.8351, 1513.0226, 19.78232, NULL, 0),
(@PATH, 7, -1768.8212, 1509.8993, 26.2533, NULL, 0),
(@PATH, 8, -1739.1805, 1511.401, 26.222946, NULL, 0),
(@PATH, 9, -1731.474, 1501.7692, 26.049221, NULL, 0),
(@PATH, 10, -1731.0747, 1477.1632, 24.336224, NULL, 0),
(@PATH, 11, -1728.125, 1465.9567, 23.649427, NULL, 0),
(@PATH, 12, -1731.0747, 1477.1632, 24.336224, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Rat
SET @MOVERGUID := 376590;
SET @ENTRY := 4075;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1770.599, 1443.0209, 19.809189, NULL, 0),
(@PATH, 1, -1772.316, 1451.8004, 19.59817, NULL, 0),
(@PATH, 2, -1780.5504, 1453.4323, 19.359102, NULL, 0),
(@PATH, 3, -1804.6129, 1453.6771, 18.92142, NULL, 0),
(@PATH, 4, -1806.3611, 1464.2848, 18.921152, NULL, 0),
(@PATH, 5, -1807.3334, 1480.75, 19.374025, NULL, 0),
(@PATH, 6, -1801.0642, 1485.382, 19.738972, NULL, 0),
(@PATH, 7, -1796.9271, 1485.2448, 19.852367, NULL, 0),
(@PATH, 8, -1782.1198, 1482.1598, 20.76269, NULL, 0),
(@PATH, 9, -1796.9271, 1485.2448, 19.852367, NULL, 0),
(@PATH, 10, -1801.0642, 1485.382, 19.738972, NULL, 0),
(@PATH, 11, -1807.3334, 1480.75, 19.374025, NULL, 0),
(@PATH, 12, -1806.3611, 1464.2848, 18.921152, NULL, 0),
(@PATH, 13, -1804.6129, 1453.6771, 18.92142, NULL, 0),
(@PATH, 14, -1780.5504, 1453.4323, 19.359102, NULL, 0),
(@PATH, 15, -1772.316, 1451.8004, 19.59817, NULL, 0),
(@PATH, 16, -1770.599, 1443.0209, 19.809189, NULL, 0),
(@PATH, 17, -1771.0817, 1427.1493, 19.80547, NULL, 0),
(@PATH, 18, -1769.3611, 1412.6493, 19.782312, NULL, 0),
(@PATH, 19, -1771.0817, 1427.1493, 19.80547, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
