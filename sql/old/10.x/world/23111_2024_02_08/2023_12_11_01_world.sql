SET @CGUID := 7000254;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 142612, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1036.9617919921875, -652.14410400390625, 6.598229885101318359, 0.779740512371063232, 120, 0, 0, 88105, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Kate Banks (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+1, 123244, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1091.3785400390625, -637.41839599609375, 17.63118362426757812, 6.198451042175292968, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Boralus Sailor (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+2, 123244, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1052.00390625, -637.6102294921875, 12.06749343872070312, 1.972442388534545898, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Boralus Sailor (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+3, 123244, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1055.2396240234375, -586.435791015625, 9.822752952575683593, 1.704782605171203613, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Boralus Sailor (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 266042 - Sitting + Fishing)
(@CGUID+4, 123244, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1050.0606689453125, -614.9515380859375, 9.864444732666015625, 1.655904173851013183, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Boralus Sailor (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 244867 - 8.0 Carry Sack New Anim)
(@CGUID+5, 123244, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1150.3316650390625, -596.07989501953125, 1.55257582664489746, 0.473284214735031127, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Boralus Sailor (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+6, 142176, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1077.6041259765625, -640.5242919921875, 17.66778373718261718, 0.707500696182250976, 120, 0, 0, 88105, 2434, 0, NULL, NULL, NULL, NULL, 52393), -- Hauke Hartford (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+7, 123633, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1071.23095703125, -612.8992919921875, 17.66778564453125, 5.962944507598876953, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Akua (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+8, 133282, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1092.888916015625, -639.2100830078125, 17.62747573852539062, 0.951356232166290283, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Stormsong Trader (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+9, 133282, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1114.2535400390625, -616.96875, 17.7873382568359375, 4.090414047241210937, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Stormsong Trader (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+10, 133325, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1112.8125, -618.4617919921875, 17.61635780334472656, 0.790181756019592285, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Drustvar Trader (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+11, 143259, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1093.3004150390625, -633.85589599609375, 17.6335601806640625, 0.144091933965682983, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Kayleigh Calder (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 271334 - Cosmetic - Taking Notes)
(@CGUID+12, 143242, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1090.3125, -637.1944580078125, 17.63259696960449218, 0.000001065264427779, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Lewis Villamar (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+13, 143248, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1092.60595703125, -632.685791015625, 17.63421821594238281, 4.814082622528076171, 120, 0, 0, 35242, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Rebecca Lin (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+14, 142180, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1135.453125, -621.59375, 17.63018608093261718, 3.204835176467895507, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Tradewinds Laborer (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+15, 144148, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1131.8697509765625, -629.10589599609375, 17.84760665893554687, 1.651254177093505859, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Joey Cash (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+16, 124720, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1123.625, -629.935791015625, 17.84524917602539062, 1.813216447830200195, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Wixler Brass (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+17, 144147, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1115.6353759765625, -631.20660400390625, 17.842681884765625, 1.61823892593383789, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Miranda Moyer (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+18, 140313, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1100.4715576171875, -640.92913818359375, 17.55722427368164062, 1.626905083656311035, 120, 0, 0, 88105, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Harbor Guard Cadet (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+19, 135230, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1094.71875, -636.9461669921875, 17.62909698486328125, 3.645733356475830078, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Boralus Inspector (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 271317 - Cosmetic - Teaching from a Book)
(@CGUID+20, 139375, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1058.8975830078125, -622.69964599609375, 0.700501561164855957, 3.165131807327270507, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Franklin The Drunk (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 159510 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+21, 135064, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1036.8646240234375, -597.04864501953125, 1.47470247745513916, 6.261766910552978515, 120, 0, 0, 2822975, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Will Melborne (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+22, 124695, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1034.0850830078125, -596.09893798828125, 1.491493105888366699, 3.064343929290771484, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Sally Melborne (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+23, 143254, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1085.79345703125, -544.85418701171875, 0.46216440200805664, 5.469362258911132812, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Andy Houghtelin (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+24, 142166, 1643, 8717, 8717, '0', 0, 0, 0, 0, 1096.0416259765625, -562.68231201171875, 1.207972168922424316, 3.78096771240234375, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393), -- Tradewinds Dockworker (Area: Boralus Harbor - Difficulty: 0) CreateObject1 (Auras: 244874 - 8.0 Carry Crate New Anim)
(@CGUID+25, 142166, 1643, 8717, 8717, '0', 0, 0, 0, 0, 1154.549560546875, -572.19122314453125, 1.601259112358093261, 5.425114631652832031, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52393); -- Tradewinds Dockworker (Area: Boralus Harbor - Difficulty: 0) CreateObject1 (Auras: 244863 - 8.0 Carry Barrel New Anim)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 757, 0, 0, 0, 0, ''), -- Boralus Sailor
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Boralus Sailor - 266042 - Sitting + Fishing
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Boralus Sailor
(@CGUID+14, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0, 0, ''), -- Tradewinds Laborer
(@CGUID+19, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '271317'), -- Boralus Inspector - 271317 - Cosmetic - Teaching from a Book
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''); -- Andy Houghtelin

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (142612, 144148, 143248, 124720, 144147, 139375);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(142612, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 142612 (Kate Banks)
(144148, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 144148 (Joey Cash)
(143248, 0, 0, 0, 0, 0, 0, 0, 0, 13903, 0, 0, 0, ''), -- 143248 (Rebecca Lin)
(124720, 0, 0, 0, 0, 0, 1, 1, 0, 16302, 0, 0, 0, ''), -- 124720 (Wixler Brass)
(144147, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 144147 (Miranda Moyer)
(139375, 0, 0, 0, 0, 0, 1, 0, 0, 12617, 0, 0, 0, '159510'); -- 139375 (Franklin The Drunk) - Cosmetic - Sleep Zzz Breakable

-- Gossip data
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=142612 AND `MenuID`=23169) OR (`CreatureID`=135064 AND `MenuID`=21990) OR (`CreatureID`=139375 AND `MenuID`=22723);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(142612, 23169, 52393), -- Kate Banks
(135064, 21990, 52393), -- Will Melborne
(139375, 22723, 52393); -- Franklin The Drunk

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=123633 AND `item`=161373 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=159920 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=163076 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=163075 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=161383 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=159919 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=162559 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123633 AND `item`=163077 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142176 AND `item`=159869 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142176 AND `item`=160554 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142176 AND `item`=159871 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142176 AND `item`=159898 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(123633, 8, 161373, 0, 0, 1, 0, 0, 52393), -- Seared Simmerfin
(123633, 7, 159920, 0, 0, 1, 0, 0, 52393), -- Fermented Greatshark
(123633, 6, 163076, 0, 0, 1, 0, 0, 52393), -- Murkfathom Herring
(123633, 5, 163075, 0, 0, 1, 0, 0, 52393), -- Stormshore Haddock
(123633, 4, 161383, 0, 0, 1, 0, 0, 52393), -- Jancunda Nigiri
(123633, 3, 159919, 0, 0, 1, 0, 0, 52393), -- Salted Tideway Cod
(123633, 2, 162559, 0, 0, 1, 0, 0, 52393), -- Hearty Swamp Gumbo
(123633, 1, 163077, 0, 0, 1, 0, 0, 52393), -- Glacier Bay Halibut
(142176, 4, 159869, 0, 0, 1, 0, 0, 52393), -- Goldfield Sweet Yams
(142176, 3, 160554, 0, 0, 1, 0, 0, 52393), -- Stormsong Sourdough
(142176, 2, 159871, 0, 0, 1, 0, 0, 52393), -- Buttered Turnip Porridge
(142176, 1, 159898, 0, 0, 1, 0, 0, 52393); -- Sour Stormberries

-- Creature 143259 smart ai
SET @ENTRY := 143259;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 3000, 16000, 22000, 80, 14325900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 16 - 22 seconds (1 - 3s initially) (OOC) - Self: Start timed action list id #14325900 (update out of combat)');

-- Timed list 14325900 smart ai
SET @ENTRY := 14325900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 85, 271334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 271334 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 12000, 12000, 0, 0, 92, 0, 271334, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 12 seconds - Self: Interrupt casted spell  271334');

-- smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (123244, 133325, 133282, 140313, 142166);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+4), -(@CGUID+3), -(@CGUID+9), -(@CGUID+10), -(@CGUID+18), -(@CGUID+25), -(@CGUID+24));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+4), 0, 0, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 80, 12324400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #12324400 (update out of combat)'),
(-(@CGUID+4), 0, 1, 0, '', 34, 0, 100, 0, 2, 8, 0, 0, 80, 12324401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Start timed action list id #12324401 (update out of combat)'),
(-(@CGUID+3), 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 3000, 6000, 85, 266042, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 6 seconds (0 - 0s initially) (OOC) - Self: Cast spell 266042 on self'),
(-(@CGUID+9), 0, 0, 0, '', 1, 0, 100, 0, 1000, 6000, 8000, 11000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 8 - 11 seconds (1 - 6s initially) (OOC) - Self: Play emote 1'),
(-(@CGUID+10), 0, 0, 0, '', 1, 0, 100, 0, 1000, 6000, 8000, 11000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 8 - 11 seconds (1 - 6s initially) (OOC) - Self: Play emote 1'),
(-(@CGUID+18), 0, 0, 0, '', 34, 0, 100, 0, 2, 8, 0, 0, 80, 14031300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Start timed action list id #14031300 (update out of combat)'),
(-(@CGUID+18), 0, 1, 0, '', 34, 0, 100, 0, 2, 10, 0, 0, 80, 14031300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Start timed action list id #14031300 (update out of combat)'),
(-(@CGUID+18), 0, 2, 0, '', 34, 0, 100, 0, 2, 16, 0, 0, 80, 14031300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 16 - Self: Start timed action list id #14031300 (update out of combat)'),
(-(@CGUID+25), 0, 0, 0, '', 34, 0, 100, 0, 2, 10, 0, 0, 80, 14216600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Start timed action list id #14216600 (update out of combat)'),
(-(@CGUID+25), 0, 1, 0, '', 34, 0, 100, 0, 2, 20, 0, 0, 80, 14216601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 20 - Self: Start timed action list id #14216601 (update out of combat)'),
(-(@CGUID+24), 0, 0, 0, '', 34, 0, 100, 0, 2, 5, 0, 0, 80, 14216602, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #14216600 (update out of combat)'),
(-(@CGUID+24), 0, 1, 0, '', 34, 0, 100, 0, 2, 12, 0, 0, 80, 14216603, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 12 - Self: Start timed action list id #14216601 (update out of combat)');

-- Timed list 12324400 smart ai
SET @ENTRY := 12324400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 244867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  244867'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 12000, 12000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 12 seconds - Self: Set emote state to 0');

-- Timed list 12324401 smart ai
SET @ENTRY := 12324401;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 11000, 11000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Set emote state to 0'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 244867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 244867 on self');

-- Timed list 14031300 smart ai
SET @ENTRY := 14031300;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 271334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 271334 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 92, 0, 271334, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Interrupt casted spell  271334');

-- Timed list 14216600 smart ai
SET @ENTRY := 14216600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 244863, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  244863'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Set emote state to 0');

-- Timed list 14216601 smart ai
SET @ENTRY := 14216601;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 18000, 18000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 18 seconds - Self: Set emote state to 0'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 85, 244863, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244863 on self');

-- Timed list 14216602 smart ai
SET @ENTRY := 14216602;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 244874, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  244874'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 15000, 15000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Remove stand state KNEEL');

-- Timed list 14216603 smart ai
SET @ENTRY := 14216603;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 16000, 16000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 16 seconds - Self: Remove stand state KNEEL'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 85, 244874, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244874 on self');

-- Waypoints for CGUID+4
SET @ENTRY := 123244;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1050.976, -625.6771, 9.854939, NULL, 0),
(@PATH, 1, 1050.009, -614.342, 9.864368, NULL, 0),
(@PATH, 2, 1049.526, -604.3611, 9.864368, NULL, 0),
(@PATH, 3, 1049.868, -598.6198, 9.864368, NULL, 14182),
(@PATH, 4, 1050.804, -606.2205, 9.864368, NULL, 0),
(@PATH, 5, 1051.135, -621.2465, 9.907785, NULL, 0),
(@PATH, 6, 1051.411, -628.6163, 9.864367, NULL, 0),
(@PATH, 7, 1051.502, -631.6788, 10.0267, NULL, 0),
(@PATH, 8, 1050.564, -635.7743, 10.06749, NULL, 14165);

UPDATE `creature` SET `position_x`= 1050.976, `position_y`= -625.6771, `position_z`= 9.854939, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+4;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+4, @PATH, 1, '244867');

-- Waypoints for CGUID+18
SET @ENTRY := 140313;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1095.262, -616.2083, 17.55722, NULL, 0),
(@PATH, 1, 1094.01, -623.5417, 17.55722, NULL, 0),
(@PATH, 2, 1095.7, -631.1649, 17.62504, NULL, 0),
(@PATH, 3, 1098.8, -628.0121, 17.55722, NULL, 0),
(@PATH, 4, 1100.681, -631.9375, 17.55722, NULL, 0),
(@PATH, 5, 1100.419, -635.9603, 17.55722, NULL, 0),
(@PATH, 6, 1099.602, -642.092, 17.55722, NULL, 0),
(@PATH, 7, 1097.828, -643.2708, 17.76242, NULL, 0),
(@PATH, 8, 1097.042, -643.7478, 17.55536, NULL, 6134),
(@PATH, 9, 1100.943, -643.2726, 17.55722, NULL, 0),
(@PATH, 10, 1101.023, -645.7621, 17.63676, NULL, 6498),
(@PATH, 11, 1100.245, -636.8906, 17.55722, NULL, 0),
(@PATH, 12, 1100.023, -629.7344, 17.55722, NULL, 0),
(@PATH, 13, 1100.217, -624.2761, 17.55722, NULL, 0),
(@PATH, 14, 1099.781, -613.4583, 17.55722, NULL, 0),
(@PATH, 15, 1103.352, -609.1424, 17.55722, NULL, 0),
(@PATH, 16, 1109.002, -609.3038, 17.55722, NULL, 6632),
(@PATH, 17, 1103.476, -607.6667, 17.55722, NULL, 0);

UPDATE `creature` SET `position_x`= 1095.262, `position_y`= -616.2083, `position_z`= 17.55722, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+18, @PATH, 0);

-- Waypoints for CGUID+25
SET @ENTRY := 142166;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1138.75, -568.1511, 1.458825, NULL, 0),
(@PATH, 1, 1125.58, -567.6111, 1.123634, NULL, 0),
(@PATH, 2, 1113.467, -565.4479, 1.150974, NULL, 0),
(@PATH, 3, 1103.929, -563.5868, 1.143212, NULL, 0),
(@PATH, 4, 1096.053, -556.415, 1.275148, NULL, 0),
(@PATH, 5, 1094.948, -548.967, 1.283033, NULL, 0),
(@PATH, 6, 1097.866, -540.5278, 1.573031, NULL, 0),
(@PATH, 7, 1100.799, -533.4653, 1.557224, NULL, 0),
(@PATH, 8, 1105.67, -521.0347, 1.582158, NULL, 0),
(@PATH, 9, 1108.406, -517.592, 2.097578, NULL, 0),
(@PATH, 10, 1111.439, -517.25, 2.097578, NULL, 17626),
(@PATH, 11, 1102.38, -526.5208, 1.559935, NULL, 0),
(@PATH, 12, 1098.293, -536.6302, 1.661453, NULL, 0),
(@PATH, 13, 1094.84, -548.368, 1.27983, NULL, 0),
(@PATH, 14, 1096.283, -557.1302, 1.195516, NULL, 0),
(@PATH, 15, 1103.361, -563.7813, 1.157632, NULL, 0),
(@PATH, 16, 1108.649, -564.6702, 1.150974, NULL, 0),
(@PATH, 17, 1123.47, -567.2656, 1.070253, NULL, 0),
(@PATH, 18, 1140.866, -570.2552, 1.410846, NULL, 0),
(@PATH, 19, 1153.349, -571.9184, 1.557224, NULL, 0),
(@PATH, 20, 1154.55, -572.1912, 1.601259, NULL, 21918),
(@PATH, 21, 1138.75, -568.1511, 1.458825, NULL, 0);

UPDATE `creature` SET `position_x`= 1138.75, `position_y`= -568.1511, `position_z`= 1.458825, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+25;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+25;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+25, @PATH, 1, '244863');

-- Waypoints for CGUID+24
SET @ENTRY := 142166;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1100.819, -564.9254, 1.228367, NULL, 0),
(@PATH, 1, 1105.227, -566.8195, 1.297468, NULL, 0),
(@PATH, 2, 1114.231, -568.7188, 1.178932, NULL, 0),
(@PATH, 3, 1122.918, -569.3108, 1.069284, NULL, 0),
(@PATH, 4, 1132.535, -570.8802, 1.69014, NULL, 0),
(@PATH, 5, 1144.376, -577.9048, 1.354099, NULL, 17018),
(@PATH, 6, 1134.877, -571.6337, 1.733448, NULL, 0),
(@PATH, 7, 1122.72, -569.9393, 1.069336, NULL, 0),
(@PATH, 8, 1117.792, -568.9323, 1.134102, NULL, 0),
(@PATH, 9, 1104.129, -566.243, 1.199659, NULL, 0),
(@PATH, 10, 1101.073, -564.6476, 1.217619, NULL, 0),
(@PATH, 11, 1097.578, -562.3507, 1.121207, NULL, 0),
(@PATH, 12, 1096.042, -562.6823, 1.207972, NULL, 18010);

UPDATE `creature` SET `position_x`= 1100.819, `position_y`= -564.9254, `position_z`= 1.228367, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+24;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+24, @PATH, 1, '244874');
