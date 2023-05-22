SET @CGUID := 9003450;

SET @NPCTEXTID := 590047;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 194613, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3475.859375, 2394.748291015625, 381.086181640625, 2.453157424926757812, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Unkimi (Area: The Azure Span - Difficulty: 0)
(@CGUID+1, 193100, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3466.880126953125, 2372.13720703125, 384.630859375, 0.119845442473888397, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Tuskarr Worker (Area: The Azure Span - Difficulty: 0) 256136 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+2, 194058, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3390.391357421875, 2333.989013671875, 382.02508544921875, 0.042390976101160049, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Tuskarr Fisher (Area: The Azure Span - Difficulty: 0) (Auras: 375006 - [DNT] Hold Fish Bag)
(@CGUID+3, 194058, 2444, 13646, 13646, '0', 0, 0, 0, 1, -3426.09375, 2298.7119140625, 382.245635986328125, 1.100107312202453613, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Tuskarr Fisher (Area: The Azure Span - Difficulty: 0) (Auras: 384458 - Standing + Fishing)
(@CGUID+4, 194047, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3448.697998046875, 2374.803955078125, 384.479156494140625, 3.675567150115966796, 120, 0, 0, 79043, 0, 0, 0, 0, 0, 48317), -- Tame Bakar (Area: The Azure Span - Difficulty: 0)
(@CGUID+5, 193100, 2444, 13646, 13646, '0', 0, 0, 0, 1, -3458.557373046875, 2335.78125, 382.464630126953125, 0.076045498251914978, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Tuskarr Worker (Area: The Azure Span - Difficulty: 0)
(@CGUID+6, 193100, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3467.65966796875, 2378.026123046875, 384.736328125, 2.453157424926757812, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Tuskarr Worker (Area: The Azure Span - Difficulty: 0)
(@CGUID+7, 194044, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3469.092041015625, 2338.8837890625, 384.601318359375, 4.971851348876953125, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48317), -- Tuskarr Child (Area: The Azure Span - Difficulty: 0)
(@CGUID+8, 194044, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3464.29345703125, 2370.798583984375, 384.69940185546875, 2.676327705383300781, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48317), -- Tuskarr Child (Area: The Azure Span - Difficulty: 0)
(@CGUID+9, 194058, 2444, 13646, 13646, '0', 0, 0, 0, 1, -3396.6494140625, 2330.87841796875, 381.66375732421875, 4.258931636810302734, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Tuskarr Fisher (Area: The Azure Span - Difficulty: 0) (Auras: 384458 - Standing + Fishing)
(@CGUID+10, 194047, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3392.71533203125, 2330.46533203125, 381.842864990234375, 3.827915906906127929, 120, 0, 0, 79043, 0, 0, 0, 0, 0, 48317), -- Tame Bakar (Area: The Azure Span - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+11, 194047, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3459.28466796875, 2376.694580078125, 384.878509521484375, 3.827915906906127929, 120, 0, 0, 79043, 0, 0, 0, 0, 0, 48317), -- Tame Bakar (Area: The Azure Span - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+12, 193100, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3462.71826171875, 2347.29296875, 384.46923828125, 4.717760086059570312, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317); -- Tuskarr Worker (Area: The Azure Span - Difficulty: 0) (Auras: 370802 - [DNT] Hold Logs)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Tuskarr Worker
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '375006'), -- Tuskarr Fisher - 375006 - [DNT] Hold Fish Bag
(@CGUID+4, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Tame Bakar
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 568, 0, 0, 0, 0, ''), -- Tuskarr Worker
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Tuskarr Worker
(@CGUID+7, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Tuskarr Child
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Tame Bakar - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Tame Bakar - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370802'); -- Tuskarr Worker - 370802 - [DNT] Hold Logs

-- Creature Template
UPDATE `creature_template` SET `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=194044; -- Tuskarr Child
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=2633, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194047; -- Tame Bakar
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=194058; -- Tuskarr Fisher
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=193100; -- Tuskarr Worker
UPDATE `creature_template` SET `gossip_menu_id`=28957, `minlevel`=70, `maxlevel`=70, `faction`=3273, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=194613; -- Unkimi

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (193100,194058,190136));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(193100, 1, 109579, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- Tuskarr Worker
(194058, 1, 34784, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- Tuskarr Fisher
(190136, 1, 34784, 0, 0, 0, 0, 0, 0, 0, 0, 48317); -- Tuskarr Fisherman

-- Quets stuff
DELETE FROM `quest_details` WHERE `ID`=71233;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(71233, 1, 0, 0, 0, 0, 0, 0, 0, 48317); -- Falling Water

DELETE FROM `creature_queststarter` WHERE (`id`=194613 AND `quest`=71233);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(194613, 71233, 48317); -- Falling Water offered Unkimi

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 226731, 0, 0, 0, 0, 0, 0, 0, 48317); -- 194613 (Unkimi)

DELETE FROM `gossip_menu` WHERE (`MenuID`=28957 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(28957, @NPCTEXTID+0, 48317); -- 194613 (Unkimi)

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (194058);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+3), -(@CGUID+9));
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = 19405800;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+3), 0, 0, 0, 1, 0, 100, 0, 2000, 8000, 18000, 22000, 80, 19405800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2-8s and repeat 18-22s - start ActionList - to self'),
(-(@CGUID+9), 0, 0, 0, 1, 0, 100, 0, 2000, 8000, 18000, 22000, 80, 19405800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2-8s and repeat 18-22s - start ActionList - to self'),
(19405800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 384458, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Standing + Fishing - to self'),
(19405800, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 92, 0, 384458, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'after 8s - interrupt spell Standing + Fishing - to self');

-- Waypoints for CGUID+2
SET @PATH := (@CGUID+2) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3380.898, 2338.613, 382.4063, NULL, 0),
(@PATH, 1, -3379.335, 2343.036, 382.6854, NULL, 0),
(@PATH, 2, -3378.497, 2349.248, 383.1645, NULL, 0),
(@PATH, 3, -3379.25, 2354.861, 383.532, NULL, 7453),
(@PATH, 4, -3378.497, 2349.248, 383.1645, NULL, 0),
(@PATH, 5, -3379.335, 2343.036, 382.6854, NULL, 0),
(@PATH, 6, -3380.898, 2338.613, 382.4063, NULL, 0),
(@PATH, 7, -3383.945, 2335.41, 382.3353, NULL, 0),
(@PATH, 8, -3388.045, 2334.089, 382.0853, NULL, 0),
(@PATH, 9, -3392.753, 2333.889, 381.9644, NULL, 0),
(@PATH, 10, -3397.09, 2334.689, 381.9355, NULL, 0),
(@PATH, 11, -3401.155, 2336.945, 381.9266, NULL, 0),
(@PATH, 12, -3404.517, 2336.995, 382.0597, NULL, 5943),
(@PATH, 13, -3397.09, 2334.689, 381.9355, NULL, 0),
(@PATH, 14, -3392.753, 2333.889, 381.9644, NULL, 0),
(@PATH, 15, -3388.045, 2334.089, 382.0853, NULL, 0),
(@PATH, 16, -3383.945, 2335.41, 382.3353, NULL, 0);

UPDATE `creature` SET `position_x`= -3380.898, `position_y`= 2338.613, `position_z`= 382.4063, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+2;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+2, @PATH, 1, '375006');

-- Waypoints for CGUID+12
SET @PATH := (@CGUID+12) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3462.313, 2337.3, 382.6117, NULL, 395),
(@PATH, 1, -3462.699, 2343.356, 383.6982, NULL, 0),
(@PATH, 2, -3461.925, 2355.358, 384.5795, NULL, 0),
(@PATH, 3, -3463.948, 2361.177, 384.5732, NULL, 0),
(@PATH, 4, -3468.198, 2363.028, 384.5754, NULL, 5810),
(@PATH, 5, -3463.948, 2361.177, 384.5732, NULL, 0),
(@PATH, 6, -3461.925, 2355.358, 384.5795, NULL, 0),
(@PATH, 7, -3462.728, 2349.031, 384.6093, NULL, 0),
(@PATH, 8, -3462.696, 2343.257, 383.6659, NULL, 0);

UPDATE `creature` SET `position_x`= -3462.313, `position_y`= 2337.3, `position_z`= 382.6117, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+12, @PATH, 1, '370802');
