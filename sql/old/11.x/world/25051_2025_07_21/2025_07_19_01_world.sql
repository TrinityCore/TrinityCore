SET @CGUID := 6005771;
SET @SPAWNGROUP := 1267;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 115487, 1651, 8443, 8443, '23,2,8', '0', 0, 0, 0, -10849.6005859375, -2104.29345703125, 93.1811065673828125, 2.555080890655517578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Medivh (Area: Karazhan - Difficulty: Mythic) CreateObject2 (Auras: 229594 - Vision)
(@CGUID+1, 115490, 1651, 8443, 8443, '23,2,8', '0', 0, 0, 0, -10906.9287109375, -2056.18408203125, 92.2552490234375, 4.700648307800292968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Prince Llane Wrynn (Area: Karazhan - Difficulty: Mythic) CreateObject2 (Auras: 229485 - Vision)
(@CGUID+2, 115489, 1651, 8443, 8443, '23,2,8', '0', 0, 0, 1, -10909.794921875, -2057.83154296875, 92.2552490234375, 4.800294876098632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Anduin Lothar (Area: Karazhan - Difficulty: Mythic) CreateObject2 (Auras: 229485 - Vision)

DELETE FROM `spawn_group` WHERE `groupId`=@SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+0),
(@SPAWNGROUP, 0, @CGUID+1),
(@SPAWNGROUP, 0, @CGUID+2);

DELETE FROM `spawn_group_template` WHERE `groupId`=@SPAWNGROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP, 'Karazhan - Maiden of Virtue outro', 4);

UPDATE `creature_template` SET `ScriptName`='boss_maiden_of_virtue_rtk' WHERE `entry`=113971;
UPDATE `creature_template` SET `unit_flags2`=0x800, `AIName`= 'SmartAI' WHERE `entry`=115489; -- Anduin Lothar
UPDATE `creature_template` SET `unit_flags2`=0x800, `AIName`= 'SmartAI' WHERE `entry`=115490; -- Prince Llane Wrynn
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x40000000, `AIName`= 'SmartAI' WHERE `entry`=115487; -- Medivh

UPDATE `creature_template_addon` SET `StandState`=3, `VisFlags`=0, `auras`='229594' WHERE `entry`=115487; -- 115487 (Medivh) - Vision

DELETE FROM `creature_template_addon` WHERE `entry` = 115490;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(115490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, '229485'); -- 115490 (Prince Llane Wrynn) - Vision

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_maiden_of_virtue_rtk_sacred_ground', 'spell_maiden_of_virtue_rtk_holy_bulwark');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(227793, 'spell_maiden_of_virtue_rtk_sacred_ground'),
(227817, 'spell_maiden_of_virtue_rtk_holy_bulwark');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 8812);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(8812, 0, 12880, 0, 2, 0, 2537, 0, 0, -1, 0, 86, 0, 180000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_maiden_of_virtue_rtk_sacred_ground', 61609); -- Spell: 227789 (Sacred Ground)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 12880);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(12880, 0, 0, 61609);

DELETE FROM `creature_text` WHERE `CreatureID` = 113971;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(113971, 0, 0, 'And so begins your purification!', 14, 0, 100, 0, 0, 77786, 123837, 0, 'Maiden of Virtue'),
(113971, 0, 1, 'The stench of corruption is upon you!', 14, 0, 100, 0, 0, 77787, 123840, 0, 'Maiden of Virtue'),
(113971, 1, 0, 'The lesson is complete.', 14, 0, 100, 0, 0, 77788, 123843, 0, 'Maiden of Virtue'),
(113971, 1, 1, 'A pure mind is an orderly mind.', 14, 0, 100, 0, 0, 77789, 123844, 0, 'Maiden of Virtue'),
(113971, 2, 0, 'Purified!', 14, 0, 100, 0, 0, 77784, 123827, 0, 'Maiden of Virtue'),
(113971, 2, 1, 'A teachable moment.', 14, 0, 100, 0, 0, 77785, 123830, 0, 'Maiden of Virtue'),
(113971, 3, 0, 'All shall be sanctified!', 14, 0, 100, 0, 0, 77775, 123772, 0, 'Maiden of Virtue'),
(113971, 4, 0, '|TInterface\\Icons\\Spell_Holy_InnerFire:20|t%s is casting |cFFFF0000|Hspell:227789|h[Sacred Ground]|h|r at you!', 42, 0, 100, 0, 0, 0, 123100, 0, 'Maiden of Virtue'),
(113971, 5, 0, 'The righteous have nothing to fear!', 14, 0, 100, 0, 0, 77778, 123775, 0, 'Maiden of Virtue'),
(113971, 5, 1, 'Step into the light, mortals!', 14, 0, 100, 0, 0, 77779, 123807, 0, 'Maiden of Virtue'),
(113971, 6, 0, 'By fire be cleansed!', 14, 0, 100, 0, 0, 77777, 123774, 0, 'Maiden of Virtue'),
(113971, 7, 0, '|TInterface\\Icons\\Spell_Holy_PrayerOfHealing:20|t%s is casting |cFFFF0000|Hspell:227508|h[Mass Repentance]|h|r!', 41, 0, 100, 0, 0, 0, 123101, 0, 'Maiden of Virtue'),
(113971, 8, 0, 'Hold, mortals! Open your hearts to virtue!', 14, 0, 100, 0, 0, 77780, 123808, 0, 'Maiden of Virtue'),
(113971, 9, 0, 'Renounce your greed and perversion!', 14, 0, 100, 0, 0, 77781, 123811, 0, 'Maiden of Virtue'),
(113971, 10, 0, 'Repent... or DIE!', 14, 0, 100, 0, 0, 77782, 123814, 0, 'Maiden of Virtue'),
(113971, 11, 0, 'I will... never... relent...', 14, 0, 100, 0, 0, 77790, 123845, 0, 'Maiden of Virtue'),
(113971, 11, 1, 'You are all... as corrupt... as the Guardian...', 14, 0, 100, 0, 0, 77791, 123846, 0, 'Maiden of Virtue');

DELETE FROM `instance_template` WHERE `map`=1651;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1651, 0, 'instance_return_to_karazhan');

DELETE FROM `scene_template` WHERE `SceneId`=1538;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `ScriptName`) VALUES
(1538, 27, 1778, 'scene_maiden_of_virtue_outro');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (232516));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 232516, 0, 0, 8, 0, 45394, 0, 0, '', 1, 'Potential target of the spell has not quest Tracking Quest (45394) rewarded');

DELETE FROM `conversation_actors` WHERE (`ConversationId`=4052 AND `Idx` IN (2,1,0)) OR (`ConversationId`=4034 AND `Idx` IN (2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(4052, 56316, @CGUID+1, 2, 0, 0, 0, 0, 61609), -- Full: 0x203AE8CE6070C880002D63000069211A Creature/0 R3770/S11619 Map: 1651 (Return to Karazhan) Entry: 115490 (Prince Llane Wrynn) Low: 6889754
(4052, 56317, @CGUID+2, 1, 0, 0, 0, 0, 61609), -- Full: 0x203AE8CE6070C840002D63000069211A Creature/0 R3770/S11619 Map: 1651 (Return to Karazhan) Entry: 115489 (Anduin Lothar) Low: 6889754
(4052, 0, 0, 0, 0, 0, 0, 1, 61609), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(4034, 0, @CGUID+1, 2, 0, 0, 0, 0, 61609), -- Full: 0x203AE8CE6070C880002D63000069211A Creature/0 R3770/S11619 Map: 1651 (Return to Karazhan) Entry: 115490 (Prince Llane Wrynn) Low: 6889754
(4034, 56317, @CGUID+2, 1, 0, 0, 0, 0, 61609), -- Full: 0x203AE8CE6070C840002D63000069211A Creature/0 R3770/S11619 Map: 1651 (Return to Karazhan) Entry: 115489 (Anduin Lothar) Low: 6889754
(4034, 0, 0, 0, 0, 0, 0, 1, 61609); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

DELETE FROM `conversation_line_template` WHERE `Id` IN (9287, 9286, 9285, 9201, 9200, 9199);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(9287, 0, 2, 0, 0, 61609),
(9286, 0, 1, 0, 0, 61609),
(9285, 0, 0, 0, 0, 61609),
(9201, 0, 2, 0, 0, 61609),
(9200, 0, 1, 0, 0, 61609),
(9199, 0, 0, 0, 0, 61609);

DELETE FROM `conversation_template` WHERE `Id` IN (4052, 4034);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(4052, 9285, 0, 61609),
(4034, 9199, 0, 61609);

DELETE FROM `smart_scripts` WHERE `entryorguid`=115489 AND `source_type`=0 OR `entryorguid` = (115489 * 100) AND `source_type`= 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(115489, 0, 0, 1, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 231195, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Anduin Lothar - On Just Summoned - Cast self spell 231195'),
(115489, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 59, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Anduin Lothar - On Just Summoned - Set Run 0'),
(115489, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, (115489 * 100), 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Anduin Lothar - On Just Summoned - Start Waypoint'),
(115489, 0, 3, 0, '', 34, 0, 100, 0, 2, 24, 0, 0, 0, '', 80, (115489 * 100), 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Anduin Lothar - OnMovementInform PointID 24  - Set Action List'),
((115489 * 100), 9, 0, 0, '', 0, 0, 100, 0, 1500, 1500, 1500, 1500, 0, '', 90, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Anduin Lothar - On Action List - Set StandState 8');

DELETE FROM `smart_scripts` WHERE `entryorguid`=115490 AND `source_type`=0 OR `entryorguid` = (115490 * 100) AND `source_type`= 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(115490, 0, 0, 1, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 59, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Prince Llane Wrynn  - On Just Summoned - Set Run 0'),
(115490, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, (115490 * 100), 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Prince Llane Wrynn - On Just Summoned - Start Waypoint'),
(115490, 0, 2, 0, '', 34, 0, 100, 0, 2, 19, 0, 0, 0, '', 80, (115490 * 100), 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Prince Llane Wrynn - OnMovementInform PathID 19 - Set Action List'),
((115490 * 100), 9, 0, 0, '', 0, 0, 100, 0, 3000, 3000, 3000, 3000, 0, '', 128, 12154, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Prince Llane Wrynn - On Action List - Set AnimKitId 12154'),
((115490 * 100), 9, 1, 0, '', 0, 0, 100, 0, 500, 500, 500, 500, 0, '', 85, 231496, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Prince Llane Wrynn - On Action List - Cast self spell 231496');

DELETE FROM `smart_scripts` WHERE `entryorguid`=115487 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(115487, 0, 0, 1, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 229596, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Medivh - On Just Summoned - Cast self spell 229596'),
(115487, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 132, 1267, 60000, 60000, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Medivh - On Link - Despawn Spawngroup 1267 after 1 minute');

SET @ENTRY := 115489;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Karazhan - Anduin Lothar - Maiden of Virtue outro');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10909.542, -2060.7014, 92.17191, NULL, 0),
(@PATH, 1, -10909.096, -2062.2812, 92.17191, NULL, 0),
(@PATH, 2, -10908.129, -2063.606, 92.17191, NULL, 0),
(@PATH, 3, -10906.058, -2065.2188, 92.17191, NULL, 0),
(@PATH, 4, -10903.913, -2066.6355, 92.171906, NULL, 0),
(@PATH, 5, -10900.842, -2068.7551, 92.171906, NULL, 0),
(@PATH, 6, -10897.505, -2071.0852, 92.171906, NULL, 0),
(@PATH, 7, -10893.802, -2073.6875, 92.16955, NULL, 0),
(@PATH, 8, -10890.863, -2076.0088, 92.16715, NULL, 0),
(@PATH, 9, -10888.442, -2077.7239, 92.16448, NULL, 0),
(@PATH, 10, -10885.089, -2080.283, 92.162384, NULL, 0),
(@PATH, 11, -10882.96, -2082.0051, 91.32905, NULL, 0),
(@PATH, 12, -10880.573, -2083.9739, 90.49572, NULL, 0),
(@PATH, 13, -10877.556, -2086.5557, 90.49572, NULL, 0),
(@PATH, 14, -10873.426, -2089.9844, 90.49572, NULL, 0),
(@PATH, 15, -10870.205, -2092.757, 90.49572, NULL, 0),
(@PATH, 16, -10866.513, -2095.9915, 90.49572, NULL, 0),
(@PATH, 17, -10863.714, -2098.3508, 90.49572, NULL, 0),
(@PATH, 18, -10861.826, -2100.1042, 90.912384, NULL, 0),
(@PATH, 19, -10859.951, -2101.8784, 91.74572, NULL, 0),
(@PATH, 20, -10858.319, -2103.6372, 92.162384, NULL, 0),
(@PATH, 21, -10856.013, -2105.9446, 92.162384, NULL, 0),
(@PATH, 22, -10854.221, -2107.3872, 92.162384, NULL, 0),
(@PATH, 23, -10853.004, -2107.2188, 92.162384, NULL, 0),
(@PATH, 24, -10851.825, -2106.8645, 92.162384, 1.274090, 0);

SET @ENTRY := 115490;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Karazhan - Prince Llane Wrynn - Maiden of Virtue outro');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10906.981, -2060.6753, 92.17191, NULL, 0),
(@PATH, 1, -10906.064, -2062.5208, 92.171906, NULL, 0),
(@PATH, 2, -10904.356, -2063.8489, 92.171906, NULL, 0),
(@PATH, 3, -10902.306, -2065.2917, 92.171906, NULL, 0),
(@PATH, 4, -10900.413, -2066.5886, 92.171906, NULL, 0),
(@PATH, 5, -10897.408, -2068.6562, 92.171906, NULL, 0),
(@PATH, 6, -10892.786, -2071.894, 92.16967, NULL, 0),
(@PATH, 7, -10888.556, -2074.861, 92.16335, NULL, 0),
(@PATH, 8, -10883.692, -2078.2083, 92.162384, NULL, 0),
(@PATH, 9, -10880.353, -2080.9844, 90.91239, NULL, 0),
(@PATH, 10, -10877.156, -2083.6597, 90.49572, NULL, 0),
(@PATH, 11, -10872.153, -2087.514, 90.49572, NULL, 0),
(@PATH, 12, -10868.427, -2090.533, 90.49572, NULL, 0),
(@PATH, 13, -10862.846, -2094.8733, 90.49572, NULL, 0),
(@PATH, 14, -10860.377, -2097.2534, 90.91239, NULL, 0),
(@PATH, 15, -10858.328, -2099.3403, 91.74572, NULL, 0),
(@PATH, 16, -10857.167, -2100.8176, 92.162384, NULL, 0),
(@PATH, 17, -10855.716, -2103.2083, 92.162384, NULL, 0),
(@PATH, 18, -10854.236, -2105.1633, 92.162384, NULL, 0),
(@PATH, 19, -10853.092, -2106.3176, 92.162384, 0.837758, 0);
