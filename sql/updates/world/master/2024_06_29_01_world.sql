SET @CGUID := 7001350;
SET @SPAWNGROUPID := 1255;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 134157, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1084.296875, 2623.63623046875, 810.16400146484375, 5.601494789123535156, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Warrior (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+1, 133943, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1069.2552490234375, 2659.318603515625, 811.0338134765625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Minion of Zul (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: 269935 - Bound by Shadow)
(@CGUID+2, 134157, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1077.2100830078125, 2627.87158203125, 810.1683349609375, 5.369873523712158203, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Warrior (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+3, 134174, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1082.3853759765625, 2656.47216796875, 810.1707763671875, 5.919741153717041015, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Witch Doctor (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+4, 133943, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1070.8541259765625, 2661.4306640625, 810.9376220703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Minion of Zul (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: 269935 - Bound by Shadow)
(@CGUID+5, 133943, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1070.96533203125, 2658.845458984375, 811.05706787109375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Minion of Zul (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: 269935 - Bound by Shadow)
(@CGUID+6, 133943, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1073.2569580078125, 2661.0244140625, 810.9376220703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Minion of Zul (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: 269935 - Bound by Shadow)
(@CGUID+7, 134158, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1040.140625, 2637.28564453125, 810.1707763671875, 4.446186065673828125, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Champion (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+8, 134157, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1080.8350830078125, 2669.678955078125, 810.1707763671875, 5.609979629516601562, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Warrior (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+9, 134174, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1055.0989990234375, 2663.8134765625, 810.1707763671875, 4.17470407485961914, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Witch Doctor (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+10, 134157, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1060.3385009765625, 2666.329833984375, 810.1707763671875, 4.488315582275390625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Warrior (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+11, 133943, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1072.842041015625, 2659.14404296875, 810.9376220703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Minion of Zul (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: 269935 - Bound by Shadow)
(@CGUID+12, 134158, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1082.53125, 2662.041748046875, 810.1707763671875, 6.203471660614013671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Champion (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+13, 134157, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1086.7742919921875, 2650.109375, 810.1707763671875, 5.949019432067871093, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Warrior (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+14, 134157, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1049.03125, 2660.283935546875, 810.1707763671875, 3.988105535507202148, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Shadow-Borne Warrior (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+15, 133943, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1068.4930419921875, 2661.75341796875, 810.9376220703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988), -- Minion of Zul (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: 269935 - Bound by Shadow)
(@CGUID+16, 134174, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1046.3211669921875, 2635.2509765625, 810.1707763671875, 4.599164962768554687, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54988); -- Shadow-Borne Witch Doctor (Area: Kings' Rest - Difficulty: Mythic) CreateObject2 (Auras: )

-- Update
UPDATE `gameobject_template` SET `AIName` = '', `ScriptName` = 'go_kings_rest_serpentine_seal' WHERE `entry` = 288466;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kings_rest_shadow_of_zul' WHERE `entry` = 137020;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kings_rest_shadow_borne_warrior' WHERE `entry` = 134157;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kings_rest_shadow_borne_witch_doctor' WHERE `entry` = 134174;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kings_rest_shadow_borne_champion' WHERE `entry` = 134158;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kings_rest_minion_of_zul' WHERE `entry` = 133943;

UPDATE `creature` SET `StringId` = 'DontForceRespawn' WHERE `guid` IN (7000965, 7000970, 7000972, 7000976, 7000969, 7000967, 7000968, 7000981, 7000975, 7000966, 7000971, 7000982, 7000978, 7000979, 7000983, 7000973, 7000977, 7000980, 7000974, 7000993, 7001001, 7000997, 7000990, 7001002, 7000989, 7000998, 7000985);
UPDATE `creature` SET `StringId` = 'TempleEvent' WHERE `guid` IN (@CGUID+1, @CGUID+4, @CGUID+5, @CGUID+6, @CGUID+11, @CGUID+15);

-- Delete SAI Script (converted to C++)
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = 133943;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 137020 AND `GroupID` = 0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(137020, 0, 0, 'Dis temple is under G\'huun\'s power!', 14, 0, 100, 0, 0, 106154, 151859, 0, 'Shadow of Zul to Player');

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=17933 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17933, 0, 0, 55165);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=13339 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(13339, 0, 17933, 0, 1040, 0, 0, 0, 0, -1, 0, 0, 6283, 30000, 4, 1.5, 1.5, 5, 5, 1, 1, 0, 0, 55165); -- Spell: 269931 (Gust Slash)

DELETE FROM `areatrigger_create_properties_orbit` WHERE (`AreaTriggerCreatePropertiesId`=13339 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties_orbit` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `StartDelay`, `CircleRadius`, `BlendFromRadius`, `InitialAngle`, `ZOffset`, `CounterClockwise`, `CanLoop`, `VerifiedBuild`) VALUES
(13339, 0, 0, 5, 0, 0, 0, 0, 1, 55165); -- Spell: 269931 (Gust Slash)

UPDATE `areatrigger_create_properties` SET `ScriptName` = 'at_kings_rest_gust_slash' WHERE (`Id`=13339 AND `IsCustom`=0);

-- Spawngroups
DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWNGROUPID;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUPID, 'Kings Rest - Zul activates temple spawns', 0x04);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWNGROUPID AND `spawnType`= 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUPID, 0, @CGUID+0),
(@SPAWNGROUPID, 0, @CGUID+1),
(@SPAWNGROUPID, 0, @CGUID+2),
(@SPAWNGROUPID, 0, @CGUID+3),
(@SPAWNGROUPID, 0, @CGUID+4),
(@SPAWNGROUPID, 0, @CGUID+5),
(@SPAWNGROUPID, 0, @CGUID+6),
(@SPAWNGROUPID, 0, @CGUID+7),
(@SPAWNGROUPID, 0, @CGUID+8),
(@SPAWNGROUPID, 0, @CGUID+9),
(@SPAWNGROUPID, 0, @CGUID+10),
(@SPAWNGROUPID, 0, @CGUID+11),
(@SPAWNGROUPID, 0, @CGUID+12),
(@SPAWNGROUPID, 0, @CGUID+13),
(@SPAWNGROUPID, 0, @CGUID+14),
(@SPAWNGROUPID, 0, @CGUID+15),
(@SPAWNGROUPID, 0, @CGUID+16);

-- Condition (Targets)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (270692));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 270692, 0, 0, 31, 0, 3, 137652, 0, '', 0, 'Potential target of the spell is creature, entry is Untainted Guard Spirit (137652)'),
(13, 1, 270692, 0, 0, 58, 0, 0, 0, 0, 'DontForceRespawn', 1, 'Potential target of the spell is not DontForceRespawn'),
(13, 1, 270692, 0, 1, 31, 0, 3, 137650, 0, '', 0, 'Potential target of the spell is creature, entry is Untainted Spirit (137650)'),
(13, 1, 270692, 0, 1, 58, 0, 0, 0, 0, 'DontForceRespawn', 1, 'Potential target of the spell is not DontForceRespawn'),
(13, 1, 270692, 0, 2, 31, 0, 3, 137651, 0, '', 0, 'Potential target of the spell is creature, entry is Untainted Priest Spirit (137651)'),
(13, 1, 270692, 0, 2, 58, 0, 0, 0, 0, 'DontForceRespawn', 1, 'Potential target of the spell is not DontForceRespawn');

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (137652, 137650, 137651);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (137652, 137650, 137651);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(137652, 0, 0, 0, '', 8, 0, 100, 0, 270692, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  270692 hit - Self: Despawn in 3 s'),
(137650, 0, 0, 0, '', 8, 0, 100, 0, 270692, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  270692 hit - Self: Despawn in 3 s'),
(137651, 0, 0, 0, '', 8, 0, 100, 0, 270692, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  270692 hit - Self: Despawn in 3 s');
