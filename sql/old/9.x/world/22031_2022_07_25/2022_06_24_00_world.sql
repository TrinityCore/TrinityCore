SET @CGUID := 459965;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 77184, 1116, 6719, 6796, '0', 2501, 0, 0, 1, 1510.826416015625, 312.03472900390625, 66.77489471435546875, 6.21453094482421875, 7200, 0, 0, 2365200, 797750, 0, 0, 0, 0, 44127), -- Archmage Khadgar (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 80799, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1523.7413330078125, 332.76214599609375, 67.5020751953125, 5.167719841003417968, 7200, 0, 0, 46797, 100, 0, 0, 0, 0, 44127), -- Drelanim Whisperwind (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1511.5103759765625, 319.486114501953125, 66.80474853515625, 2.58581709861755371, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+3, 72628, 1116, 6719, 6796, '0', 3585, 0, 0, 0, 1563.842041015625, 291.795135498046875, 63.74415206909179687, 1.917170643806457519, 7200, 0, 0, 44334, 0, 0, 0, 0, 0, 44127), -- Snowclaw (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1530.8819580078125, 368.52777099609375, 67.9892578125, 2.205457448959350585, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+5, 80798, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1566.1146240234375, 300.119781494140625, 64.10956573486328125, 3.557532310485839843, 7200, 0, 0, 49260, 100, 0, 0, 0, 0, 44127), -- Sira Moonwarden (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 73548, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1530.014404296875, 290.311370849609375, 66.6193695068359375, 1.33189702033996582, 7200, 0, 0, 49260, 100, 0, 0, 0, 0, 44127), -- Shalis Darkhunter (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1569.7083740234375, 373.963531494140625, 66.160430908203125, 2.238344907760620117, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+8, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1555.4010009765625, 365.098968505859375, 65.31674957275390625, 1.397846341133117675, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+9, 73546, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1492.5885009765625, 294.083343505859375, 67.91909027099609375, 3.441568613052368164, 7200, 0, 0, 51723, 100, 0, 0, 0, 0, 44127), -- Marin Bladewing (Area: -Unknown- - Difficulty: 0) (Auras: 114943 - Stealth)
(@CGUID+10, 73701, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1512.9444580078125, 299.364593505859375, 66.88919830322265625, 4.508240222930908203, 7200, 0, 0, 34482, 0, 0, 0, 0, 0, 44127), -- Rory MacDuff (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1524.536865234375, 262.70098876953125, 67.57732391357421875, 4.157748699188232421, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+12, 80801, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1509.6614990234375, 262.479156494140625, 71.99546051025390625, 4.573689460754394531, 7200, 0, 0, 49260, 100, 0, 0, 0, 0, 44127), -- Mirana Starlight (Area: -Unknown- - Difficulty: 0) (Auras: 114943 - Stealth)
(@CGUID+13, 77689, 1116, 6719, 6796, '0', 3585, 0, 0, 0, 1562.875, 309.651031494140625, 64.38874053955078125, 2.496130228042602539, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44127), -- Shadowmoon Talbuk (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1540.439208984375, 261.51214599609375, 71.60223388671875, 3.750279426574707031, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+15, 72785, 1116, 6719, 6796, '0', 3585, 0, 0, 0, 1511.79150390625, 657.379638671875, 73.6518707275390625, 5.154206275939941406, 7200, 10, 0, 24630, 12830, 1, 0, 0, 0, 44127), -- Twisted Ancient (Area: -Unknown- - Difficulty: 0) (Auras: 146164 - Fel-Cursed) (possible waypoints or random movement)
(@CGUID+16, 72785, 1116, 6719, 6796, '0', 3585, 0, 0, 0, 1867.3946533203125, 530.2218017578125, 36.95386123657226562, 1.558101654052734375, 7200, 0, 0, 24630, 12830, 0, 0, 0, 0, 44127), -- Twisted Ancient (Area: -Unknown- - Difficulty: 0) (Auras: 146164 - Fel-Cursed)
(@CGUID+17, 77689, 1116, 6719, 6796, '0', 3585, 0, 0, 0, 1536.0260009765625, 271.59375, 66.837677001953125, 3.223199367523193359, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44127), -- Shadowmoon Talbuk (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1526.4033203125, 228.8125, 69.30730438232421875, 4.865586757659912109, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+19, 23837, 1116, 6719, 6796, '0', 3585, 0, 0, 0, 1573.2742919921875, 290.526031494140625, 64.40491485595703125, 2.609932899475097656, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 44127), -- ELM General Purpose Bunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 72623, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1564.9288330078125, 293.666656494140625, 63.74415206909179687, 5.772980213165283203, 7200, 0, 0, 34482, 12830, 0, 0, 0, 0, 44127), -- Delas Moonfang (Area: -Unknown- - Difficulty: 0) (Auras: 148466 - Holy Channeling)
(@CGUID+21, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1517.5416259765625, 352.526031494140625, 65.28403472900390625, 2.301348209381103515, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+22, 73324, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1547.9169921875, 366.666015625, 65.10569000244140625, 1.551447868347167968, 7200, 0, 0, 36945, 0, 0, 0, 0, 0, 44127), -- Starfall Sentinel (Area: -Unknown- - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+23, 80800, 1116, 6719, 6796, '0', 3585, 0, 0, 1, 1606.0364990234375, 383.196197509765625, 69.6206817626953125, 0.666959941387176513, 7200, 0, 0, 54186, 100, 0, 0, 0, 0, 44127); -- Malace Shade (Area: -Unknown- - Difficulty: 0) (Auras: 114943 - Stealth)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 258, 0, 5452, 0, 0, 0, '18950'), -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection
(@CGUID+7, 0, 0, 0, 258, 0, 5452, 0, 0, 0, '18950'), -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection
(@CGUID+8, 0, 0, 0, 258, 0, 5452, 0, 0, 0, '18950'), -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection
(@CGUID+11, 0, 0, 0, 258, 376, 0, 0, 0, 0, '18950'), -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection
(@CGUID+14, 0, 0, 0, 258, 376, 0, 0, 0, 0, '18950'), -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection
(@CGUID+21, 0, 0, 0, 258, 376, 0, 0, 0, 0, '18950'), -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection
(@CGUID+22, 0, 0, 0, 258, 376, 0, 0, 0, 0, '18950'); -- Starfall Sentinel - 18950 - Invisibility and Stealth Detection

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN ( 80800 /*80800 (Malace Shade) - Stealth*/, 72623 /*72623 (Delas Moonfang) - Holy Channeling*/, 80801 /*80801 (Mirana Starlight) - Stealth*/, 73546 /*73546 (Marin Bladewing) - Stealth*/, 73548 /*73548 (Shalis Darkhunter)*/, 72628 /*72628 (Snowclaw)*/, 73324 /*73324 (Starfall Sentinel) - Invisibility and Stealth Detection*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(80800, 0, 0, 8, 1, 0, 0, 0, 0, 0, '114943'), -- 80800 (Malace Shade) - Stealth
(72623, 0, 0, 0, 258, 0, 0, 0, 0, 0, '148466'), -- 72623 (Delas Moonfang) - Holy Channeling
(80801, 0, 0, 0, 1, 0, 0, 0, 0, 0, '114943'), -- 80801 (Mirana Starlight) - Stealth
(73546, 0, 0, 0, 1, 0, 0, 0, 0, 0, '114943'), -- 73546 (Marin Bladewing) - Stealth
(73548, 0, 14330, 0, 1, 0, 0, 0, 0, 0, ''), -- 73548 (Shalis Darkhunter)
(72628, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 72628 (Snowclaw)
(73324, 0, 0, 0, 256, 0, 0, 0, 0, 0, '18950'); -- 73324 (Starfall Sentinel) - Invisibility and Stealth Detection

UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=59113; -- 59113 (Generic Bunny)

-- Creature Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (82354,82378));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(82354, 0, 0, 0, 63, 44127),
(82378, 0, 0, 0, 63, 44127);

-- Template Data
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80800; -- Malace Shade
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=59113; -- Generic Bunny
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `unit_flags3`=1048576 WHERE `entry`=72623; -- Delas Moonfang
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=23837; -- ELM General Purpose Bunny
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=77689; -- Shadowmoon Talbuk
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80801; -- Mirana Starlight
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=73546; -- Marin Bladewing
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=73548; -- Shalis Darkhunter
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80798; -- Sira Moonwarden
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=72628; -- Snowclaw
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `unit_flags3`=8388608 WHERE `entry`=73324; -- Starfall Sentinel
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80799; -- Drelanim Whisperwind
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=77184; -- Archmage Khadgar

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 6796 AND `PhaseId` = 2501) OR (`AreaId` = 6796 AND `PhaseId` = 3585);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(6796, 2501, 'Cosmetic - Shadowmoon Valley 6.0 - Starfall Outpost - Archmage Khadgar (ELM)'),
(6796, 3585, 'Cosmetic - Shadowmoon Valley 6.0 - Starfall Outpost - Alliance (ELM)');

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=73701 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73701 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73701 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73701 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73701 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73701 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73701 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(73701, 7, 3857, 0, 0, 1, 0, 0, 44232), -- Coal
(73701, 6, 18567, 0, 0, 1, 0, 0, 44232), -- Elemental Flux
(73701, 5, 3466, 0, 0, 1, 0, 0, 44232), -- Strong Flux
(73701, 4, 2880, 0, 0, 1, 0, 0, 44232), -- Weak Flux
(73701, 3, 180733, 0, 0, 1, 0, 0, 44232), -- -Unknown-
(73701, 2, 5956, 0, 0, 1, 0, 0, 44232), -- Blacksmith Hammer
(73701, 1, 2901, 0, 0, 1, 0, 0, 44232); -- Mining Pick

-- SmartScripts
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (72623, 73701);

DELETE FROM `smart_scripts` WHERE `source_type` = (0 AND `entryOrGuid` = 72623) OR (0 AND `entryOrGuid` = 73701) OR (9 AND `entryOrGuid` = 7370100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(72623, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 148466, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnRespawn - Cast spell "Holy Channeling" - to self'),
(73701, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 7370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 1 - run ActionList - to self'),
(73701, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 7370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 3 - run ActionList - to self'),
(73701, 0, 2, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 7370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 6 - run ActionList - to self'),
(73701, 0, 3, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 7370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 7 - run ActionList - to self'),
(73701, 0, 4, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, 7370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 8 - run ActionList - to self'),
(73701, 0, 5, 0, 34, 0, 100, 0, 2, 9, 0, 0, 80, 7370100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 9 - run ActionList - to self'),
(7370100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 3000, 3000, 128, 1320, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3s - play AnimKit 1320 - to self'),
(7370100, 9, 1, 0, 0, 0, 100, 0, 35000, 35000, 35000, 35000, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 35s - play AnimKit 0 - to self');

-- Waypoints for CGUID+6
SET @PATH := @CGUID+6 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1537.01, 320.8976, 66.31802, NULL, 0),
(@PATH, 1, 1541.231, 331.3229, 66.49771, NULL, 0),
(@PATH, 2, 1547.76, 346.8646, 65.91929, NULL, 0),
(@PATH, 3, 1549.543, 352.6337, 65.60215, NULL, 0),
(@PATH, 4, 1550.158, 356.8195, 65.60557, NULL, 0),
(@PATH, 5, 1550.72, 362.9462, 65.3646, NULL, 20543),
(@PATH, 6, 1550.158, 356.8195, 65.60557, NULL, 0),
(@PATH, 7, 1549.543, 352.6337, 65.60215, NULL, 0),
(@PATH, 8, 1547.76, 346.8646, 65.91929, NULL, 0),
(@PATH, 9, 1541.231, 331.3229, 66.49771, NULL, 0),
(@PATH, 10, 1537.01, 320.8976, 66.31802, NULL, 0),
(@PATH, 11, 1534.024, 306.7743, 66.24771, NULL, 0),
(@PATH, 12, 1529.245, 287.151, 66.75504, NULL, 0),
(@PATH, 13, 1526.439, 276.0226, 67.00504, NULL, 0),
(@PATH, 14, 1523.057, 267.1129, 67.38004, NULL, 19255),
(@PATH, 15, 1526.439, 276.0226, 67.00504, NULL, 0),
(@PATH, 16, 1529.245, 287.151, 66.75504, NULL, 0),
(@PATH, 17, 1534.024, 306.7743, 66.24771, NULL, 0);

UPDATE `creature` SET `position_x`= 1537.01, `position_y`= 320.8976, `position_z`= 66.31802, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+6;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `mount`, `path_id`, `bytes2`) VALUES
(@CGUID+6, 14330, @PATH, 1);

-- Waypoints for CGUID+10
SET @PATH := @CGUID+10 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 1, 1513.879, 293.6649, 66.85575, 4.127272, 39732),
(@PATH, 2, 1514.036, 298.6806, 66.71915, NULL, 0),
(@PATH, 3, 1512.944, 299.3646, 66.8892, 4.500334, 45636),
(@PATH, 4, 1512.516, 326.4774, 66.72821, NULL, 40451),
(@PATH, 5, 1513.637, 301.2448, 66.68182, NULL, 0),
(@PATH, 6, 1512.944, 299.3646, 66.8892, NULL, 55984),
(@PATH, 7, 1508.476, 293.1129, 67.15226, 1.358739, 41571),
(@PATH, 8, 1514.066, 298.8646, 66.71355, NULL, 0),
(@PATH, 9, 1512.944, 299.3646, 66.8892, 4.500332, 46474);

UPDATE `creature` SET `position_x`= 1513.879, `position_y`= 293.6649, `position_z`= 66.85575, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+10;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+10, @PATH, 1);
