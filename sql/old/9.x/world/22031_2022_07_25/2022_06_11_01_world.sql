SET @CGUID := 459945;
SET @OGUID := 395473;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2387.310791015625, 527.72052001953125, 0.482012271881103515, 4.012835025787353515, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 81829, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2372.364501953125, 556.6163330078125, 4.830037117004394531, 5.257065773010253906, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Aeedrei (Area: -Unknown- - Difficulty: 0) (Auras: 163424 - Holding Watering Can)
(@CGUID+2, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2389.270751953125, 549.08856201171875, 5.681584835052490234, 5.160698890686035156, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2392.705078125, 494.255035400390625, -0.58154040575027465, 5.52473306655883789, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2408.052001953125, 560.3367919921875, 4.899065494537353515, 1.69204103946685791, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 81214, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2353.88427734375, 562.8382568359375, 4.954914093017578125, 0.709281384944915771, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Pack Talbuk (Area: -Unknown- - Difficulty: 0) (Auras: 163872 - Pack Talbuk Aura [INTERNAL ONLY])
(@CGUID+6, 81825, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2429.138916015625, 581.83160400390625, 6.31963968276977539, 4.77155303955078125, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Prelate Zlaak (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 81830, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2348.49658203125, 582.857666015625, 4.899065494537353515, 0.673182129859924316, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Dakaari (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 84516, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2362.265625, 463.263885498046875, 0.420138895511627197, 2.349697351455688476, 7200, 0, 0, 1232, 0, 0, 0, 0, 0, 43345), -- Seehmo (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2363.224609375, 571.5272216796875, 4.940732002258300781, 6.070362567901611328, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2400.729248046875, 524.81427001953125, 0.230919629335403442, 3.89049530029296875, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 81828, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2361.729248046875, 584.73785400390625, 4.940732002258300781, 5.96089792251586914, 7200, 0, 0, 1970, 0, 0, 0, 0, 0, 43345), -- Eventide Elekk (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2403.8525390625, 560.30035400390625, 4.899065494537353515, 0.805382013320922851, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 81314, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2434.427001953125, 553.67364501953125, 4.87183380126953125, 3.986423015594482421, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 43345), -- Moro (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2372.001708984375, 455.81597900390625, 0.597895503044128417, 3.876770257949829101, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 84372, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2363.45654296875, 461.760406494140625, 0.321222215890884399, 4.249135971069335937, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Madari (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 81828, 1116, 6719, 7173, '0', 0, 0, 0, 0, 2354.744873046875, 583.10589599609375, 4.899065494537353515, 5.744721889495849609, 7200, 0, 0, 1970, 0, 0, 0, 0, 0, 43345), -- Eventide Elekk (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2409.4931640625, 565.76214599609375, 4.932583332061767578, 4.016982078552246093, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2376.585205078125, 450.645843505859375, 0.200428128242492675, 4.76392984390258789, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345), -- Eventide Villager (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 81824, 1116, 6719, 7173, '0', 0, 0, 0, 1, 2315.720458984375, 485.00347900390625, 8.054332733154296875, 3.87677001953125, 7200, 0, 0, 1971, 3191, 0, 0, 0, 0, 43345); -- Eventide Villager (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 5939, 0, 0, 0, ''), -- Eventide Villager
(@CGUID+2, 0, 0, 1, 257, 0, 0, 0, 0, 0, ''), -- Eventide Villager
(@CGUID+9, (@CGUID+9 * 10), 0, 0, 257, 0, 6351, 0, 0, 0, ''), -- Eventide Villager
(@CGUID+10, 0, 0, 1, 257, 0, 0, 0, 0, 0, ''), -- Eventide Villager
(@CGUID+14, 0, 0, 1, 257, 0, 0, 0, 0, 0, ''), -- Eventide Villager
(@CGUID+18, 0, 0, 0, 257, 0, 5939, 0, 0, 0, ''), -- Eventide Villager
(@CGUID+19, 0, 0, 1, 257, 0, 0, 0, 0, 0, ''); -- Eventide Villager

-- Creature Addon Template
DELETE FROM `creature_template_addon` WHERE `entry` IN (84372 /*84372 (Madari)*/, 84516 /*84516 (Seehmo)*/, 81214 /*81214 (Pack Talbuk) - Pack Talbuk Aura [INTERNAL ONLY]*/, 81829 /*81829 (Aeedrei) - Holding Watering Can*/, 81824 /*81824 (Eventide Villager)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(84372, 0, 0, 0, 1, 0, 5939, 0, 0, 0, ''), -- 84372 (Madari)
(84516, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 84516 (Seehmo)
(81214, 0, 0, 0, 1, 0, 0, 0, 0, 0, '163872'), -- 81214 (Pack Talbuk) - Pack Talbuk Aura [INTERNAL ONLY]
(81829, 0, 0, 0, 1, 0, 0, 0, 0, 0, '163424'), -- 81829 (Aeedrei) - Holding Watering Can
(81824, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 81824 (Eventide Villager)

-- Creature Equip Template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (81314,81827));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(81314, 1, 12792, 0, 0, 0, 0, 0, 0, 0, 0, 43971), -- Moro
(81827, 1, 28678, 0, 0, 0, 0, 0, 0, 0, 0, 43971); -- Qiana Moonshadow

UPDATE `creature_equip_template` SET `VerifiedBuild`=43971 WHERE (`ID`=1 AND `CreatureID` IN (79216,81636,81824,79219,79218,79206,79704,84372));

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+17;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 238042, 1116, 6719, 7173, '0', 0, 0, 2432.72216796875, 552.1180419921875, 4.784487247467041015, 2.539454221725463867, 0, 0, 0.955019950866699218, 0.296541541814804077, 7200, 255, 1, 43345), -- Anvil (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 238043, 1116, 6719, 7173, '0', 0, 0, 2436.61279296875, 550.87847900390625, 4.815732479095458984, 3.272519350051879882, 0, 0, -0.99785804748535156, 0.065416477620601654, 7200, 255, 1, 43345), -- Forge (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 235961, 1116, 6719, 7173, '0', 0, 0, 2431.62451171875, 581.8037109375, 5.985088348388671875, 3.132858037948608398, 0, 0, 0.999990463256835937, 0.004367320332676172, 7200, 255, 1, 43345), -- Brazier (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 237979, 1116, 6719, 7173, '0', 0, 0, 2430.065673828125, 579.03594970703125, 5.9212646484375, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 7200, 255, 1, 43345), -- Cookpot (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 235963, 1116, 6719, 7173, '0', 0, 0, 2382.20947265625, 584.99468994140625, 6.113583564758300781, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 7200, 255, 1, 43345), -- Brazier (Area: -Unknown- - Difficulty: 0)
(@OGUID+5, 243388, 1116, 6719, 7173, '0', 0, 0, 2365.411376953125, 465.088531494140625, 0.810314595699310302, 1.361356139183044433, -0.01339340209960937, -0.05173778533935546, 0.62735748291015625, 0.776895344257354736, 7200, 255, 1, 43345), -- Campfire (Area: -Unknown- - Difficulty: 0)
(@OGUID+6, 239022, 1116, 6719, 7173, '0', 0, 0, 2414.725830078125, 564.31427001953125, 4.815972328186035156, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 7200, 255, 1, 43345), -- Mailbox (Area: -Unknown- - Difficulty: 0)
(@OGUID+7, 238044, 1116, 6719, 7173, '0', 0, 0, 2317.72216796875, 489.119781494140625, 7.973917484283447265, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 7200, 255, 1, 43345), -- Chair (Area: -Unknown- - Difficulty: 0)
(@OGUID+8, 238043, 1116, 6719, 7173, '0', 0, 0, 2436.61279296875, 550.87847900390625, 4.815732479095458984, 3.272519350051879882, 0, 0, -0.99785804748535156, 0.065416477620601654, 7200, 255, 1, 43345), -- Forge (Area: -Unknown- - Difficulty: 0)
(@OGUID+9, 231991, 1116, 6719, 7173, '0', 0, 0, 2413.09033203125, 581.92706298828125, 6.017306327819824218, 6.222386837005615234, 0, 0, -0.03039455413818359, 0.999538004398345947, 7200, 255, 1, 43345), -- Draenei Bookshelf (Area: -Unknown- - Difficulty: 0)
(@OGUID+10, 235963, 1116, 6719, 7173, '0', 0, 0, 2382.20947265625, 584.99468994140625, 6.113583564758300781, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 7200, 255, 1, 43345), -- Brazier (Area: -Unknown- - Difficulty: 0)
(@OGUID+11, 243388, 1116, 6719, 7173, '0', 0, 0, 2365.411376953125, 465.088531494140625, 0.810314595699310302, 1.361356139183044433, -0.01339340209960937, -0.05173778533935546, 0.62735748291015625, 0.776895344257354736, 7200, 255, 1, 43345), -- Campfire (Area: -Unknown- - Difficulty: 0)
(@OGUID+12, 237979, 1116, 6719, 7173, '0', 0, 0, 2430.065673828125, 579.03594970703125, 5.9212646484375, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 7200, 255, 1, 43345), -- Cookpot (Area: -Unknown- - Difficulty: 0)
(@OGUID+13, 235961, 1116, 6719, 7173, '0', 0, 0, 2431.62451171875, 581.8037109375, 5.985088348388671875, 3.132858037948608398, 0, 0, 0.999990463256835937, 0.004367320332676172, 7200, 255, 1, 43345), -- Brazier (Area: -Unknown- - Difficulty: 0)
(@OGUID+14, 238044, 1116, 6719, 7173, '0', 0, 0, 2317.72216796875, 489.119781494140625, 7.973917484283447265, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 7200, 255, 1, 43345), -- Chair (Area: -Unknown- - Difficulty: 0)
(@OGUID+15, 231992, 1116, 6719, 7173, '0', 0, 0, 2430.942626953125, 581.86285400390625, 6.018474578857421875, 3.097225189208984375, 0, 0, 0.999753952026367187, 0.022181892767548561, 7200, 255, 1, 43345), -- Draenei Bookshelf 002 (Area: -Unknown- - Difficulty: 0)
(@OGUID+16, 238042, 1116, 6719, 7173, '0', 0, 0, 2432.72216796875, 552.1180419921875, 4.784487247467041015, 2.539454221725463867, 0, 0, 0.955019950866699218, 0.296541541814804077, 7200, 255, 1, 43345), -- Anvil (Area: -Unknown- - Difficulty: 0)
(@OGUID+17, 238045, 1116, 6719, 7173, '0', 0, 0, 2318.614501953125, 483.86285400390625, 7.975247859954833984, 4.319690704345703125, 0, 0, -0.83146953582763671, 0.555570363998413085, 7200, 255, 1, 43345); -- Chair (Area: -Unknown- - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+17;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+2, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0), -- Brazier
(@OGUID+3, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0), -- Cookpot
(@OGUID+4, 0, 0, -0.78801071643829345, 0.615661501884460449, 0, 0), -- Brazier
(@OGUID+10, 0, 0, -0.78801071643829345, 0.615661501884460449, 0, 0), -- Brazier
(@OGUID+12, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0), -- Cookpot
(@OGUID+13, 0, 0, -0.71018534898757934, 0.704014718532562255, 0, 0); -- Brazier

-- Creature Template
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=42 WHERE `entry`=81406; -- Bahameye
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1732, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81314; -- Moro
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=84516; -- Seehmo
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=81830; -- Dakaari
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1733, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81214; -- Pack Talbuk

-- Creature Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (81314,81827));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(81314, 0, 0, 0, 63, 43345),
(81827, 0, 0, 0, 302, 43345);

UPDATE `creature_model_info` SET `BoundingRadius`=1.20290541648864746, `CombatReach`=1.571428537368774414, `VerifiedBuild`=43345 WHERE `DisplayID`=56803;

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=81314 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81314 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81314 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81314 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81314 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81314 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=81314 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(81314, 7, 3857, 0, 0, 1, 0, 0, 43971), -- Coal
(81314, 6, 18567, 0, 0, 1, 0, 0, 43971), -- Elemental Flux
(81314, 5, 3466, 0, 0, 1, 0, 0, 43971), -- Strong Flux
(81314, 4, 2880, 0, 0, 1, 0, 0, 43971), -- Weak Flux
(81314, 3, 180733, 0, 0, 1, 0, 0, 43971), -- Luminous Flux
(81314, 2, 5956, 0, 0, 1, 0, 0, 43971), -- Blacksmith Hammer
(81314, 1, 2901, 0, 0, 1, 0, 0, 43971); -- Mining Pick

-- SAI Scripts
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (81314 /*Moro*/, 81824 /*Eventide Villager*/, 81829 /*Aeedrei*/);

DELETE FROM `smart_scripts` WHERE `source_type` IN (0, 9) AND `entryOrGuid` IN (-(@CGUID+13), ((@CGUID+13) * 100), -(@CGUID+9), -(@CGUID+12), -(@CGUID+4), -(@CGUID+17), -(@CGUID+1), ((@CGUID+1) * 100));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+13), 0, 0, 0, 34, 0, 100, 0, 2, 0, 0, 0, 5, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 0 - Play Emote 233 - to self'),
(-(@CGUID+13), 0, 1, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, ((@CGUID+13) * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 1 - start Actionlist - to self'),
(((@CGUID+13) * 100), 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2sec - Play Emote 69 - to self'),
(((@CGUID+13) * 100), 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 6000, 6000, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6sec - Play Emote 0 - to self'),
(-(@CGUID+9), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 163875, 3, 0, 0, 0, 0, 10, (@CGUID+5), 81214, 0, 0, 0, 0, 0, 'OnRespawn - cast spell "163875" - to GUID/Entry'),
(-(@CGUID+12), 0, 0, 0, 1, 0, 100, 0, 1000, 8000, 2000, 8000, 10, 71, 153, 21, 23, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC after 1s to 8s and repeat every 2s to 8s - Play rnd Emote - to self'),
(-(@CGUID+4), 0, 0, 0, 1, 0, 100, 0, 1000, 8000, 2000, 8000, 10, 71, 153, 21, 23, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC after 1s to 8s and repeat every 2s to 8s - Play rnd Emote - to self'),
(-(@CGUID+17), 0, 0, 0, 1, 0, 100, 0, 1000, 8000, 2000, 8000, 10, 71, 153, 21, 23, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC after 1s to 8s and repeat every 2s to 8s - Play rnd Emote - to self'),
(-(@CGUID+1), 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 128, 6289, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 1 - Play OneShotAnimKit 6289 - to self'),
(-(@CGUID+1), 0, 1, 0, 34, 0, 100, 0, 2, 8, 0, 0, 128, 6289, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 8 - Play OneShotAnimKit 6289 - to self'),
(-(@CGUID+1), 0, 2, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, ((@CGUID+1) * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 4 - start Actionlist - to self'),
(-(@CGUID+1), 0, 3, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, ((@CGUID+1) * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 7 - start Actionlist - to self'),
(((@CGUID+1) * 100), 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 128, 6289, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1sec - Play OneShotAnimKit 6289 - to self'),
(((@CGUID+1) * 100), 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 128, 6289, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3sec - Play OneShotAnimKit 6289 - to self');

-- Waypoints for CGUID+3
SET @PATH := @CGUID+3 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 2402.76, 491.0139, 0.3933626, 0, 0),
(@PATH, 1, 2403.887, 492.1441, 0.5177523, 0, 14005),
(@PATH, 2, 2402.748, 501.3924, -0.9333104, 0, 0),
(@PATH, 3, 2401.196, 513.8646, -1.389975, 0, 0),
(@PATH, 4, 2398.646, 524.2413, -0.4281565, 0, 0),
(@PATH, 5, 2395.832, 506.6823, -1.5917, 0, 0),
(@PATH, 6, 2389.056, 497.7135, -0.8733275, 0, 0),
(@PATH, 7, 2396.181, 490.9531, 0.1647584, 0, 0);

UPDATE `creature` SET `position_x`= 2402.76, `position_y`= 491.0139, `position_z`= 0.3933626, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+3, @PATH, 1);

-- Waypoints for CGUID+1
SET @PATH := @CGUID+1 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 1, 2369.764, 552.7257, 4.830037, 0, 2411),
(@PATH, 2, 2371.04, 559.3299, 4.830037, 0, 0),
(@PATH, 3, 2370.267, 560.0781, 4.830037, 0, 2994),
(@PATH, 4, 2372.365, 556.6163, 4.830037, 0, 9307),
(@PATH, 5, 2367.259, 553.0677, 4.830037, 0, 0),
(@PATH, 6, 2363.745, 549.1614, 4.830037, 0, 0),
(@PATH, 7, 2363.661, 553.3611, 4.830037, 0, 8020),
(@PATH, 8, 2367.976, 550.493, 4.830037, 0, 8544);

UPDATE `creature` SET `position_x`= 2369.764, `position_y`= 552.7257, `position_z`= 4.830037, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+1, @PATH, 1, '163424');

-- Waypoints for CGUID+11
SET @PATH := @CGUID+11 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 2361.729, 584.7379, 4.940732, 0, 28275),
(@PATH, 1, 2353.993, 587.3212, 4.940732, 0, 12533);

UPDATE `creature` SET `position_x`= 2361.729, `position_y`= 584.7379, `position_z`= 4.940732, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+11;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+11;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+11, @PATH, 1);

-- Waypoint for CGUID+13
SET @PATH := @CGUID+13 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 2434.427, 553.6736, 4.871834, 0, 54624),
(@PATH, 1, 2439.583, 556.8489, 4.871834, 0, 9572);

UPDATE `creature` SET `position_x`= 2439.583, `position_y`= 556.8489, `position_z`= 4.871834, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+13, @PATH, 1);

-- Waypoints for CGUID+9
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+9;
INSERT INTO `creature_formations`(`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+9, @CGUID+9, 0, 0, 515, 0, 0),
(@CGUID+9, @CGUID+5, 2, 300, 515, 0, 0);

SET @PATH := @CGUID+9 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 2308.03, 490.5469, 7.797536, 0, 0),
(@PATH, 1, 2305.635, 499.1146, 8.265065, 0, 0),
(@PATH, 2, 2309.764, 511.0052, 8.081156, 0, 0),
(@PATH, 3, 2318.642, 526.6702, 7.015727, 0, 0),
(@PATH, 4, 2327.056, 536.1371, 6.140273, 0, 0),
(@PATH, 5, 2350.101, 557.1667, 5.080037, 0, 0),
(@PATH, 6, 2362.25, 571.7379, 4.940732, 0, 0),
(@PATH, 7, 2370.878, 569.8733, 4.940732, 0, 0),
(@PATH, 8, 2376.873, 565.8524, 4.830037, 0, 0),
(@PATH, 9, 2389.747, 556.0764, 4.830037, 0, 0),
(@PATH, 10, 2395.906, 552.9305, 4.830037, 0, 0),
(@PATH, 11, 2414.618, 553.2292, 4.914803, 0, 0),
(@PATH, 12, 2420.75, 555.7864, 4.914803, 0, 0),
(@PATH, 13, 2428.063, 557.809, 4.914803, 0, 0),
(@PATH, 14, 2435.806, 560.5087, 4.871834, 0, 2433),
(@PATH, 15, 2428.063, 557.809, 4.914803, 0, 0),
(@PATH, 16, 2420.75, 555.7864, 4.914803, 0, 0),
(@PATH, 17, 2414.618, 553.2292, 4.914803, 0, 0),
(@PATH, 18, 2395.906, 552.9305, 4.830037, 0, 0),
(@PATH, 19, 2389.747, 556.0764, 4.830037, 0, 0),
(@PATH, 20, 2376.873, 565.8524, 4.830037, 0, 0),
(@PATH, 21, 2370.878, 569.8733, 4.940732, 0, 0),
(@PATH, 22, 2362.25, 571.7379, 4.940732, 0, 0),
(@PATH, 23, 2350.101, 557.1667, 5.080037, 0, 0),
(@PATH, 24, 2327.056, 536.1371, 6.140273, 0, 0),
(@PATH, 25, 2318.642, 526.6702, 7.015727, 0, 0),
(@PATH, 26, 2309.764, 511.0052, 8.081156, 0, 0),
(@PATH, 27, 2305.635, 499.1146, 8.265065, 0, 0),
(@PATH, 28, 2308.03, 490.5469, 7.797536, 0, 0),
(@PATH, 29, 2311.049, 486.1371, 7.941362, 0, 11473);

UPDATE `creature` SET `position_x`= 2308.03, `position_y`= 490.5469, `position_z`= 7.797536, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+9;
UPDATE `creature` SET `position_x`= 2308.73, `position_y`= 490.5469, `position_z`= 7.797536, `orientation`= 0, `wander_distance`= 0, `MovementType`= 0 WHERE `guid`= @CGUID+5;
