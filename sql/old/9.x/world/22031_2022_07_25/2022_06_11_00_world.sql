SET @CGUID := 459918;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 79216, 1116, 6719, 7760, '0', 3329, 0, 0, 1, 2298.3369140625, 455.197906494140625, 8.322916030883789062, 1.759095668792724609, 7200, 0, 0, 2956500, 9573, 0, 0, 0, 0, 43345), -- Archmage Khadgar (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 79218, 1116, 6719, 7760, '0', 3329, 0, 0, 1, 2305.87841796875, 461.453125, 7.347811698913574218, 3.198977947235107421, 7200, 0, 0, 9852, 1283, 0, 0, 0, 0, 43345), -- Vindicator Maraad (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 79206, 1116, 6719, 7760, '0', 3329, 0, 0, 1, 2298.302001953125, 461.836822509765625, 8.595907211303710937, 5.018345355987548828, 7200, 0, 0, 2955600, 19245, 0, 0, 0, 0, 43345), -- Prophet Velen (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 79219, 1116, 6719, 7760, '0', 3329, 0, 0, 1, 2306.1181640625, 457.555572509765625, 6.897937774658203125, 2.746419906616210937, 7200, 0, 0, 2463, 1283, 0, 0, 0, 0, 43345), -- Yrel (Area: -Unknown- - Difficulty: 0) (Auras: 73299 - Crazy Mana Regen, 150626 - Righteous Fury)
(@CGUID+4, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2301.1181640625, 454.12847900390625, 7.579861164093017578, 1.409421563148498535, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2308.392333984375, 463.763885498046875, 7.228860855102539062, 3.489587783813476562, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2292.59375, 453.407989501953125, 9.572916030883789062, 0.546439111232757568, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2233.12841796875, 482.508697509765625, 17.38198280334472656, 5.795809745788574218, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2233.2587890625, 479.994781494140625, 17.94329261779785156, 0.374391436576843261, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 79799, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2308.5556640625, 433.78125, 2.410714149475097656, 1.049137353897094726, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2275.751708984375, 441.869781494140625, 33.62289810180664062, 1.249678730964660644, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 79847, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2243.779873046875, 448.729510498046875, 26.7721784423828125, 1.634770750999450683, 7200, 4, 0, 2463, 0, 1, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2306.369873046875, 436.02777099609375, 3.30381941795349121, 5.676034450531005859, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2273.373291015625, 441.19964599609375, 34.0842132568359375, 1.07367098331451416, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 79799, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2225.40966796875, 448.901031494140625, 14.94743633270263671, 5.981957435607910156, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 79796, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2271.59716796875, 443.776031494140625, 34.77920913696289062, 0.638519823551177978, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 81636, 1116, 6719, 7760, '0', 3353, 0, 0, 1, 2301.50341796875, 470.161468505859375, 8.430490493774414062, 4.949246883392333984, 7200, 0, 0, 7389, 0, 0, 0, 0, 0, 43345), -- Karabor Peacekeeper (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 81636, 1116, 6719, 7760, '0', 3353, 0, 0, 1, 2290.335205078125, 461.539947509765625, 9.950311660766601562, 5.871581554412841796, 7200, 0, 0, 7389, 0, 0, 0, 0, 0, 43345), -- Karabor Peacekeeper (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 79798, 1116, 6719, 7760, '0', 3353, 0, 0, 0, 2304.927490234375, 476.631378173828125, 8.346276283264160156, 3.7650604248046875, 7200, 0, 0, 65, 0, 0, 0, 0, 0, 43345), -- Luuka (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 79704, 1116, 6719, 7760, '0', 3329, 0, 0, 1, 2318.104248046875, 481.508697509765625, 8.034609794616699218, 3.379798650741577148, 7200, 0, 0, 14778, 100, 0, 0, 0, 0, 43345), -- Cordana Felsong (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2394.96533203125, 582.8975830078125, 6.23564004898071289, 4.515751838684082031, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+21, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2381.1806640625, 568.5555419921875, 4.899065494537353515, 0.004098604898899793, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+22, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2397.548583984375, 584.092041015625, 6.237489700317382812, 0.905708074569702148, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+23, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2383.302001953125, 568.66839599609375, 5.591848373413085937, 3.437636613845825195, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2394.213623046875, 596.28302001953125, 8.115118026733398437, 2.690195322036743164, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2384.47216796875, 587.4913330078125, 6.237749576568603515, 0.905708074569702148, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 79796, 1116, 6719, 7173, '0', 3353, 0, 0, 0, 2387.328125, 588.66668701171875, 6.232531070709228515, 0.257286936044692993, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345); -- Draenei Refugee (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 8, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+7, 0, 0, 0, 257, 10, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+8, 0, 0, 0, 257, 10, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+9, 0, 0, 1, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+11, 0, 0, 0, 257, 431, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+12, 0, 0, 8, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+20, 0, 0, 3, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+22, 0, 0, 3, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+24, 0, 0, 3, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+23, 0, 0, 0, 257, 455, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+25, 0, 0, 3, 257, 0, 0, 0, 0, 0, ''), -- Draenei Refugee
(@CGUID+26, 0, 0, 3, 257, 0, 0, 0, 0, 0, ''); -- Draenei Refugee

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (79219 /*79219 (Yrel) - Crazy Mana Regen, Righteous Fury*/, 79796 /*(Draenei Refugee)*/, 81636 /*(Karabor Peacekeeper)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(79219, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73299 150626'), -- 79219 (Yrel) - Crazy Mana Regen, Righteous Fury
(79796, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 79796 (Draenei Refugee)
(81636, 0, 59341, 0, 257, 0, 0, 0, 0, 0, ''); -- 81636 (Karabor Peacekeeper)

UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=79206; -- Prophet Velen
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=79218; -- Vindicator Maraad
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=79219; -- Yrel
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry` IN (79847, 79799, 79796); -- Draenei Refugee
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=81636; -- Karabor Peacekeeper
UPDATE `creature_template` SET `minlevel`=6, `maxlevel`=6 WHERE `entry`=79798; -- Luuka
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=79704; -- Cordana Felsong

UPDATE `creature_model_info` SET `BoundingRadius`=0.528982520103454589, `CombatReach`=0.75, `VerifiedBuild`=43345 WHERE `DisplayID`=55810;

UPDATE `creature_queststarter` SET `VerifiedBuild`=43345 WHERE (`id`=79206 AND `quest`=34582);

-- Phase
DELETE FROM `phase_area` WHERE (`AreaId` = 6719 AND `PhaseId` = 3329) OR (`AreaId` = 6719 AND `PhaseId` = 3353);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(6719, 3329, 'Cosmetic - Follow Velen Complete'),
(6719, 3353, 'Cosmetic - Snip Scene (Draenei Boat Landing)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3329 AND `SourceEntry` = 6719);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3329, 6719, 0, 0, 9, 0, 34582, 0, 0, 1, 'Allow Phase 3329 if Quest (34582) IS NOT taken'),
(26, 3329, 6719, 0, 0, 47, 0, 34582, 66, 0, 1, 'Allow Phase 3329 if Quest (34582) IS NOT complete/rewarded');

-- SAI Scripts
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (79847, 79799, 79796 /*Draenei Refugee*/);

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+4), -(@CGUID+6), -(@CGUID+11), -(@CGUID+14));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+4), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat after 5s - play emote 71 - to self'),
(-(@CGUID+6), 0, 0, 0, 1, 0, 100, 0, 3000, 3000, 5000, 5000, 5, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat after 5s - play emote 71 - to self'),
(-(@CGUID+11), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 30000, 40000, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat after 30s - 40s - play emote 1 - to self'),
(-(@CGUID+14), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 7000, 9000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat after 7s - 9s - play emote 1 - to self');

-- Waypoints for CGUID+18 Luuka
SET @PATH := @CGUID+18 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 2317.445, 524.8906, 7.33372, 0, 0, 2),
(@PATH, 1, 2310.313, 513.0851, 7.932475, 0, 0, 2),
(@PATH, 2, 2306.304, 505.3403, 8.371317, 0, 0, 2),
(@PATH, 3, 2306.66, 491.7483, 7.97527, 0, 0, 2),
(@PATH, 4, 2306.519, 477.776, 8.202687, 0, 0, 2),
(@PATH, 5, 2301.353, 474.0625, 8.572682, 0, 0, 2),
(@PATH, 6, 2298.26, 468.7361, 8.727423, 0, 0, 2),
(@PATH, 7, 2305.391, 474.8056, 8.377248, 0, 0, 2),
(@PATH, 8, 2299.28, 477.8646, 8.794195, 0, 0, 2),
(@PATH, 9, 2295.938, 470.2292, 8.945318, 0, 0, 2),
(@PATH, 10, 2285.712, 477.1858, 9.672369, 0, 0, 2),
(@PATH, 11, 2287.023, 495.0121, 10.72889, 0, 0, 2),
(@PATH, 12, 2294.458, 498.7743, 10.28809, 0, 0, 2),
(@PATH, 13, 2293.181, 483.7101, 9.145269, 0, 0, 2),
(@PATH, 14, 2287.484, 479.125, 9.4596, 0, 0, 2),
(@PATH, 15, 2283.988, 472.7899, 10.08191, 0, 0, 2),
(@PATH, 16, 2283.875, 465.934, 10.74073, 0, 0, 2),
(@PATH, 17, 2282.151, 466.283, 11.03321, 0, 3715, 2),
(@PATH, 18, 2287.484, 479.125, 9.4596, 0, 0, 2),
(@PATH, 19, 2294.458, 498.7743, 10.28809, 0, 0, 2),
(@PATH, 20, 2287.023, 495.0121, 10.72889, 0, 0, 2),
(@PATH, 21, 2285.712, 477.1858, 9.672369, 0, 0, 2),
(@PATH, 22, 2288.873, 469.5, 9.542974, 0, 0, 2),
(@PATH, 23, 2299.28, 477.8646, 8.794195, 0, 0, 2),
(@PATH, 24, 2305.391, 474.8056, 8.377248, 0, 0, 2),
(@PATH, 25, 2302.774, 468.0486, 8.15215, 0, 0, 2),
(@PATH, 26, 2301.353, 474.0625, 8.572682, 0, 0, 2),
(@PATH, 27, 2306.519, 477.776, 8.202687, 0, 0, 2),
(@PATH, 28, 2306.66, 491.7483, 7.97527, 0, 0, 2),
(@PATH, 29, 2306.304, 505.3403, 8.371317, 0, 0, 2),
(@PATH, 30, 2310.313, 513.0851, 7.932475, 0, 0, 2),
(@PATH, 31, 2317.445, 524.8906, 7.33372, 0, 0, 2),
(@PATH, 32, 2325.38, 532.8577, 6.565287, 0, 0, 2),
(@PATH, 33, 2337.092, 544.3906, 5.330037, 0, 0, 2),
(@PATH, 34, 2350.458, 557.4705, 5.080037, 0, 0, 2),
(@PATH, 35, 2356.118, 568.2031, 4.940732, 0, 0, 2),
(@PATH, 36, 2353.575, 575.033, 4.940732, 0, 2901, 2),
(@PATH, 37, 2350.458, 557.4705, 5.080037, 0, 0, 2),
(@PATH, 38, 2343.009, 549.2205, 4.955037, 0, 0, 2),
(@PATH, 39, 2337.092, 544.3906, 5.330037, 0, 0, 2),
(@PATH, 40, 2325.38, 532.8577, 6.565287, 0, 0, 2);

UPDATE `creature` SET `position_x`= 2317.445, `position_y`= 524.8906, `position_z`= 7.33372, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+18, @PATH, 1);
