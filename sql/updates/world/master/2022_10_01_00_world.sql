 --
 --
 -- Silverpine Forest
 
SET @CGUID := 395633;

 -- Iterating Upon Success
UPDATE `quest_template_addon` SET `NextQuestID`= 0 WHERE `ID` = 26998;

 --
 -- Forsaken High Command
 
 -- Detect: Quest Invis Zone 1
DELETE FROM `spell_area` WHERE `spell`=83232 AND `area`=5369 AND `quest_start`=26965 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(83232, 5369, 26965, 27098, 0, 0, 2, 3, 64, 1);

 -- Detect: Quest Invis Zone 3
DELETE FROM `spell_area` WHERE `spell`=83989 AND `area`=5369 AND `quest_start`=26965 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83989, 5369, 26965, 27097, 0, 0, 2, 3, 64, 1);

DELETE FROM `spell_area` WHERE `spell`=83989 AND `area`=5369 AND `quest_start`=27099 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83989, 5369, 27099, 27098, 0, 0, 2, 3, 64, 1);

 -- Detect: Quest Invis Zone 20 (Ambermill Shield)
DELETE FROM `spell_area` WHERE `spell`=85406 AND `area`=130 AND `quest_start`=0 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(85406, 130, 0, 27518, 0, 0, 2, 3, 0, 8);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+39;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0, 44592, 0, 130, 5369, '0', 169, 0, 0, 0, 1378.1600341796875, 1031.7099609375, 51.37173080444335937, 0.767944872379302978, 1, 0, 0, 1604, 0, 0, 0, 0, 0, '', 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+1, 44593, 0, 130, 5369, '0', 169, 0, 0, 0, 1376, 1029.6099853515625, 50.93743133544921875, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, '', 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+2, 44592, 0, 130, 5369, '0', 169, 0, 0, 0, 1377.300048828125, 1035.9300537109375, 51.09613037109375, 3.141592741012573242, 1, 0, 0, 1604, 0, 0, 0, 0, 0, '', 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+3, 44593, 0, 130, 5369, '0', 169, 0, 0, 0, 1375.4200439453125, 1033.81005859375, 50.65223312377929687, 0.890117883682250976, 1, 0, 0, 1604, 0, 0, 0, 0, 0, '', 45338), -- Fallen Human (Area: Forsaken High Command - Difficulty: 0) (Auras: 80636 - Feigned)
(@CGUID+4, 44365, 0, 130, 5369, '0', 169, 0, 0, 1, 1381.3499755859375, 1040.72998046875, 54.40043258666992187, 3.909537553787231445, 120, 0, 0, 641600, 17040, 0, 3, 0, 0, 'npc_silverpine_sylvanas_windrunner_high_command', 45338), -- Lady Sylvanas Windrunner (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+5, 44610, 0, 130, 5369, '0', 169, 0, 0, 0, 1360.81005859375, 1030.5699462890625, 55.87403106689453125, 0.645771801471710205, 120, 0, 0, 48120, 17040, 0, 0, 0, 0, '', 45338), -- Arthura (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+6, 44609, 0, 130, 5369, '0', 169, 0, 0, 0, 1365.72998046875, 1024.97998046875, 56.02443313598632812, 1.029744267463684082, 120, 0, 0, 48120, 17040, 0, 0, 0, 0, '', 45338), -- Daschla (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+7, 44825, 0, 130, 5369, '0', 169, 0, 0, 1, 1422.9305419921875, 1017.77081298828125, 52.64933395385742187, 2.862339973449707031, 120, 0, 0, 11791, 0, 0, 0, 0, 0, '', 45338), -- Bat Handler Maggotbreath (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+8, 44632, 0, 130, 5369, '0', 169, 0, 0, 1, 1438.05, 1068.76, 60.7803, 5.5573577880859375, 120, 10, 0, 3208, 0, 2, 0, 0, 0, '', 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+9, 44632, 0, 130, 5369, '0', 169, 0, 0, 1, 1400.9300537109375, 1003.3800048828125, 53.03673171997070312, 2.094395160675048828, 120, 0, 0, 3208, 0, 0, 0, 0, 0, '', 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+10, 44632, 0, 130, 5369, '0', 169, 0, 0, 1, 1389.5400390625, 1047.81005859375, 53.04053115844726562, 3.577924966812133789, 120, 0, 0, 3208, 0, 0, 0, 0, 0, '', 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+11, 44632, 0, 130, 5369, '0', 169, 0, 0, 1, 1430.030029296875, 1022.59002685546875, 52.49113082885742187, 3.281219005584716796, 120, 0, 0, 3208, 0, 0, 0, 0, 0, '', 45338), -- Dark Ranger (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+12, 44640, 0, 130, 5369, '0', 169, 0, 0, 1, 1354.036, 1035.0999, 52.81333, 0.205820217728614807, 120, 0, 0, 8020, 0, 2, 0, 0, 0, '', 45338), -- High Warlord Cromush (Area: Forsaken High Command - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+13, 44789, 0, 130, 5369, '0', 169, 0, 0, 1, 1415.22998046875, 1010.1500244140625, 52.80423355102539062, 2.286381244659423828, 120, 0, 0, 8020, 100, 0, 0, 0, 0, '', 45338), -- Deathstalker Commander Belmont (Area: Forsaken High Command - Difficulty: 0) (Auras: 83231 - Apply Quest Invis Zone 1)
(@CGUID+14, 44790, 0, 130, 5369, '0', 169, 0, 0, 1, 1417.18994140625, 1009.780029296875, 52.70093154907226562, 2.268928050994873046, 120, 0, 0, 1604, 100, 0, 0, 0, 0, '', 45338), -- Deathstalker (Area: Forsaken High Command - Difficulty: 0) (Auras: 83231 - Apply Quest Invis Zone 1)
(@CGUID+15, 44790, 0, 130, 5369, '0', 169, 0, 0, 1, 1412.6300048828125, 1011.4000244140625, 52.9539337158203125, 5.777040004730224609, 120, 0, 0, 1604, 100, 0, 0, 0, 0, '', 45338), -- Deathstalker (Area: Forsaken High Command - Difficulty: 0) (Auras: 83231 - Apply Quest Invis Zone 1)
(@CGUID+16, 44790, 0, 130, 5369, '0', 169, 0, 0, 1, 1415.5, 1012.989990234375, 52.88033294677734375, 4.468042850494384765, 120, 0, 0, 1604, 100, 0, 0, 0, 0, '', 45338), -- Deathstalker (Area: Forsaken High Command - Difficulty: 0) (Auras: 83231 - Apply Quest Invis Zone 1)
(@CGUID+17, 44790, 0, 130, 5369, '0', 169, 0, 0, 1, 1415.050048828125, 1008.16998291015625, 52.752532958984375, 2.146754980087280273, 120, 0, 0, 1604, 100, 0, 0, 0, 0, '', 45338), -- Deathstalker (Area: Forsaken High Command - Difficulty: 0) (Auras: 83231 - Apply Quest Invis Zone 1)
(@CGUID+18, 44778, 0, 130, 5369, '0', 169, 0, 0, 1, 1409.3299560546875, 1065.8599853515625, 60.56173324584960937, 0.226892799139022827, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Witherbloom (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+19, 45489, 0, 130, 5369, '0', 169, 0, 0, 1, 1413.719970703125, 1104.02001953125, 60.56173324584960937, 2.757620096206665039, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Chase (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+20, 45490, 0, 130, 5369, '0', 169, 0, 0, 1, 1422.5699462890625, 1097.31005859375, 60.56173324584960937, 4.485496044158935546, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Marry (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+21, 45491, 0, 130, 5369, '0', 169, 0, 0, 1, 1445.27001953125, 1072.9000244140625, 60.54363250732421875, 1.2042771577835083, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Harrington (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+22, 44784, 0, 130, 5369, '0', 169, 0, 0, 1, 1431.47998046875, 1086.8599853515625, 60.56173324584960937, 3.752457857131958007, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- High Apothecary Shana T'veen (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+23, 43359, 0, 130, 5369, '0', 169, 0, 0, 0, 2298.788330078125, 280.118072509765625, 76.27024078369140625, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, '', 45338), -- ELM General Purpose Bunny Infinite Hide Body (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+24, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1425.0799560546875, 1083.22998046875, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+25, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1429.3299560546875, 1081.72998046875, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+26, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1423.3399658203125, 1085.75, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+27, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1426.300048828125, 1085.5, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+28, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1420.8399658203125, 1066.1700439453125, 60.56173324584960937, 5.288347721099853515, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+29, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1426.77001953125, 1081.06005859375, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+30, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1424.3399658203125, 1080.8599853515625, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+31, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1410.6300048828125, 1102.3299560546875, 60.56173324584960937, 1.500983119010925292, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+32, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1426.199951171875, 1078.5400390625, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+33, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1428.8599853515625, 1079.0899658203125, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+34, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1443.9200439453125, 1079.1199951171875, 60.56133270263671875, 0.92502450942993164, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+35, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1422.5899658203125, 1083.0699462890625, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+36, 44786, 0, 130, 5369, '0', 169, 0, 0, 0, 1427.6300048828125, 1083.510009765625, 60.56173324584960937, 0.855211317539215087, 120, 0, 0, 1604, 1704, 0, 0, 0, 0, '', 45338), -- Apothecary Initiate (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+37, 1412, 0, 130, 5369, '0', 169, 0, 0, 0, 1408.0518798828125, 954.0006103515625, 51.056793212890625, 0.975751638412475585, 120, 0, 0, 5, 0, 0, 0, 0, 0, '', 45338), -- Squirrel (Area: Forsaken High Command - Difficulty: 0)
(@CGUID+38, 61890, 0, 130, 5369, '0', 169, 0, 0, 0, 1348.890625, 1084.1163330078125, 52.849273681640625, 5.410439968109130859, 120, 10, 0, 5, 0, 1, 0, 0, 0, '', 45338), -- Blighted Squirrel (Area: Forsaken High Command - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+39, 44911, 0, 130, 130, '0', 169, 0, 0, 1, 1492.83, 637.973, 46.429, 5.14269, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 45338); -- Deathguard (Area: Silverpine Forest - Difficulty: 0)

-- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `gossip_menu_id`=11823 WHERE `entry`=44365; -- Lady Sylvanas Windrunner

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, '83231');

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` =44365);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44365, 0, 0, 0, 7, 45338);

DELETE FROM `gossip_menu` WHERE `MenuID`=11823 AND `TextID`=16575;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(11823, 16575, 45338);

-- Forsaken Warhorse
UPDATE `creature_template` SET `VehicleId`=1077 WHERE `entry`=73595;

DELETE FROM `creature_template_addon` WHERE `entry` =73595;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(73595, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, '');

DELETE FROM `serverside_spell` WHERE `Id`=148164 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES 
(148164, 0, 0, 0, 0, 142606592, 268697600, 1, 1048576, 4160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, '(Serverside/Non-DB2) Summon Forsaken Warhorse', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=147066 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES 
(147066, 0, 0, 6, 226, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- Agatha
UPDATE `creature` SET `position_x`=1364.0200195312, `position_y`=1028.5400390625, `position_z`=55.99143218994140625, `orientation`=0.855211317539215087 WHERE `guid`=322163;

DELETE FROM `creature_addon` WHERE `guid`=322163;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322163, 0, 0, 0, 50397184, 1, 0, 0, 0, 0, 3, '83988');

-- Arthura
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` =44610);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44610, 0, 0, 0, 7, 45338);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+5, 0, 0, 0, 50397184, 1, 0, 0, 0, 0, 3, '83231');

-- Daschla
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` =44609);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44609, 0, 0, 0, 7, 45338);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+6, 0, 0, 0, 50397184, 1, 0, 0, 0, 0, 3, '83231');

-- High Warlord Cromush 
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags2`=2099200 WHERE `entry`=44640; -- High Warlord Cromush

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` =44640);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44640, 0, 0, 0, 7, 45338);

SET @PATH := (@CGUID+12) * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1354.036, 1035.0999, 52.81333, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 1359.1589, 1022.6127, 52.732635, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 1366.1589, 1019.3627, 52.982635, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 1372.1357, 1016.7146, 53.057182, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 1376.1357, 1017.4646, 53.307182, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 1385.0673, 1019.3989, 53.502197, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 1389.9948, 1033.2056, 53.689217, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 1388.9948, 1035.9556, 53.689217, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 1388.2448, 1037.7056, 53.939217, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 1387.4948, 1039.4556, 54.189217, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 1386.3665, 1042.5286, 54.28894, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 1384.6165, 1043.5286, 54.53894, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 1382.3665, 1045.0286, 54.28894, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 1380.8665, 1046.2786, 54.03894, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 1378.9524, 1047.5721, 53.823082, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 1377.7024, 1048.3221, 53.823082, NULL, 0, 0, 0, 0, 0),
(@PATH, 17, 1368.2705, 1049.8816, 53.36094, NULL, 0, 0, 0, 0, 0),
(@PATH, 18, 1360.7705, 1049.1316, 53.11094, NULL, 0, 0, 0, 0, 0),
(@PATH, 19, 1356.5281, 1048.5553, 53.031837, NULL, 0, 0, 0, 0, 0),
(@PATH, 20, 1355.2781, 1042.5553, 52.781837, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+12, @PATH, 0, 0, 65536, 1, 0, 0, 0, 0, 3, '83231');

-- Dark Ranger
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=322179;

DELETE FROM `creature_addon` WHERE `guid`=322179;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322179, 3956090, 0, 0, 0, 258, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+8;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+8, 3956320, 0, 0, 0, 258, 0, 0, 0, 0, 0, '');

-- Worgen Renegade
UPDATE `creature` SET `MovementType`= 1, `wander_distance`= 5 WHERE `id` = 44793;

UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_worgen_renegade'  WHERE `entry` = 44793;

DELETE FROM `spell_script_names` WHERE `spell_id` = 80365 AND `ScriptName` = 'spell_silverpine_flurry_of_claws';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80365, 'spell_silverpine_flurry_of_claws');

-- Forsaken Trooper
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_forsaken_trooper'  WHERE `entry` = 44791;

DELETE FROM `creature_text` WHERE `CreatureID`= 44791;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44791, 0, 0, 'Thank you, hero!', 12, 1, 100, 71, 0, 0, 44839, 0, ''),
(44791, 0, 1, 'Thanks. That beast was a handful!', 12, 1, 100, 1, 0, 0, 44835, 0, ''),
(44791, 0, 2, 'That beast came from nowhere!', 12, 1, 100, 5, 0, 0, 44836, 0, ''),
(44791, 0, 3, 'They won\'t take our land without a fight!', 12, 1, 100, 15, 0, 0, 44838, 0, ''),
(44791, 0, 4, 'Worgen filth! I spit on your corpse!', 12, 1, 100, 14, 0, 0, 44837, 0, '');

-- Worg
UPDATE `creature` SET `MovementType`= 1, `wander_distance`= 10 WHERE `id` = 1765;

DELETE FROM `creature_loot_template` WHERE `Entry` = 1765 AND `Item` = 60742;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1765, 60742, 0, 40, 1, 1, 0, 1, 1, 'Item for questId 26995');

 -- Ferocious Grizzled Bear
UPDATE `creature` SET `MovementType`= 1, `wander_distance`= 10 WHERE `id` = 1778;

DELETE FROM `creature_loot_template` WHERE `Entry` = 1778 AND `Item` = 60742;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1778, 60742, 0, 49, 1, 1, 0, 1, 1, 'Item for questId 26995');

 -- Giant Rabid Bear
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 10 WHERE `id` = 1797;

DELETE FROM `creature_loot_template` WHERE `Entry` = 1797 AND `Item` = 60793;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1797, 60793, 0, 40, 1, 1, 0, 1, 1, 'Item for questId 26995');

 -- Rabid Dog
UPDATE `creature` SET `MovementType`= 1, `wander_distance`= 10 WHERE `id` = 1766;

DELETE FROM `creature_loot_template` WHERE `Entry` = 1766 AND `Item` = 60793;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1766, 60793, 0, 40, 1, 1, 0, 1, 1, 'Item for questId 26995');

-- Bat Handler Maggotbreath
UPDATE `creature_template` SET `gossip_menu_id`=11892, `AIName` = '', `ScriptName` = 'npc_silverpine_bat_handler_maggotbreath' WHERE `entry`=44825; -- Bat Handler Maggotbreath

DELETE FROM `gossip_menu` WHERE `MenuID`=11892 AND `TextID`=16683;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(11892, 16683, 45338);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=11892 AND `OptionID` IN (0, 1);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(11892, 0, 0, 'I need to take a bat to the Dawning Isles.', 44905, 0, 0, 0, 0, 0, 0, NULL, 0, 45338),
(11892, 1, 0, 'Show me where I can fly.', 12271, 0, 0, 0, 0, 0, 0, NULL, 0, 45338);

DELETE FROM `creature_text` WHERE `CreatureID`=44825 AND `GroupID`=0 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44825, 0, 0, 'You better bring that bat back in one piece, $n!', 12, 0, 100, 25, 0, 0, 0, 44906, 5, '');

 -- Forsaken Bat
UPDATE `creature_template` SET `VehicleId` = 1051, `ScriptName` = 'npc_silverpine_forsaken_bat'  WHERE `entry` = 44821;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 44821;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Random`, `InteractionPauseTimer`) VALUES 
(44821, 1, 0, 1, 0, 0, NULL);

DELETE FROM `creature_text` WHERE `CreatureID` = 44821;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44821, 0, 0, 'Eliminate all murlocs by using the Blight Concoction!$B$B|r|TInterface\\\\Icons\\\\INV_ALCHEMY_POTION_05.BLP:24|t', 42, 1, 100, 0, 0, 0, 0, 44902, 5, 'Forsaken Bat to Player'),
(44821, 1, 0, 'Returning to Forsaken High Command!$B$B|r|TInterface\\\\Icons\\\\ACHIEVEMENT_ZONE_SILVERPINE_01.BLP:24|t', 42, 1, 100, 0, 0, 0, 0, 44903, 5, 'Forsaken Bat to Player');

DELETE FROM `waypoint_data` WHERE `id` = 448210;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448210, 1, 1374.36, 1029.12, 67.8815, NULL, 0, 2, 0, 0, 0),
(448210, 2, 1289.08, 1013.22, 67.8815, NULL, 0, 2, 0, 0, 0),
(448210, 3, 1224, 997.236, 59.9371, NULL, 0, 2, 0, 0, 0),
(448210, 4, 1178.72, 957.238, 47.2426, NULL, 0, 2, 0, 0, 0),
(448210, 5, 1156.5, 852.318, 42.7704, NULL, 0, 2, 0, 0, 0),
(448210, 6, 1158.1, 725.983, 42.7704, NULL, 0, 2, 0, 0, 0),
(448210, 7, 1187.67, 575.212, 46.7704, NULL, 0, 2, 0, 0, 0),
(448210, 8, 1202.33, 472.97, 65.4648, NULL, 0, 2, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 448211;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448211, 1, 1214.8, 414.792, 61.0968, NULL, 0, 2, 0, 0, 0),
(448211, 2, 1221.35, 323.231, 61.0968, NULL, 0, 2, 0, 0, 0),
(448211, 3, 1189.93, 281.372, 61.0968, NULL, 0, 2, 0, 0, 0),
(448211, 4, 1100.24, 212.868, 61.0968, NULL, 0, 2, 0, 0, 0),
(448211, 5, 1015.84, 188.21, 63.0412, NULL, 0, 2, 0, 0, 0),
(448211, 6, 939.417, 163.743, 61.0968, NULL, 0, 2, 0, 0, 0),
(448211, 7, 874.302, 114.092, 61.0968, NULL, 0, 2, 0, 0, 0),
(448211, 8, 831.491, 59.3177, 56.5968, NULL, 0, 2, 0, 0, 0),
(448211, 9, 770.872, 70.7726, 56.5968, NULL, 0, 2, 0, 0, 0),
(448211, 10, 759.814, 109.738, 56.5968, NULL, 0, 2, 0, 0, 0),
(448211, 11, 803.745, 181.882, 56.5968, NULL, 0, 2, 0, 0, 0),
(448211, 12, 840.674, 202.097, 56.5968, NULL, 0, 2, 0, 0, 0),
(448211, 13, 846.651, 232.344, 56.5968, NULL, 0, 2, 0, 0, 0),
(448211, 14, 805.031, 261.606, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 15, 759.528, 265.283, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 16, 693.755, 282.512, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 17, 658.036, 357.233, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 18, 639.776, 433.974, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 19, 676.128, 470.752, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 20, 706.495, 454.023, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 21, 713.505, 380.88, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 22, 726.146, 352.188, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 23, 758.299, 321.101, 59.9579, NULL, 0, 2, 0, 0, 0),
(448211, 24, 797.684, 295.753, 58.1801, NULL, 0, 2, 0, 0, 0),
(448211, 25, 882.036, 252.597, 52.1245, NULL, 0, 2, 0, 0, 0),
(448211, 26, 929.667, 225.609, 52.1245, NULL, 0, 2, 0, 0, 0),
(448211, 27, 987.259, 219.582, 52.1245, NULL, 0, 2, 0, 0, 0),
(448211, 28, 1030.56, 276.193, 52.1245, NULL, 0, 2, 0, 0, 0),
(448211, 29, 1058.35, 308.229, 49.3745, NULL, 0, 2, 0, 0, 0),
(448211, 30, 1121.81, 372.755, 56.4579, NULL, 0, 2, 0, 0, 0),
(448211, 31, 1167.09, 438.865, 58.4857, NULL, 0, 2, 0, 0, 0),
(448211, 32, 1197.37, 451.757, 64.569, NULL, 0, 2, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 448212;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(448212, 1, 931.068, 352.101, 81.027, NULL, 0, 2, 0, 0, 0),
(448212, 2, 952.535, 571.493, 108.303, NULL, 0, 2, 0, 0, 0),
(448212, 3, 970.028, 664.392, 110.83, NULL, 0, 2, 0, 0, 0),
(448212, 4, 1031.97, 754.155, 111.441, NULL, 0, 2, 0, 0, 0),
(448212, 5, 1234.44, 880.16, 97.9414, NULL, 0, 2, 0, 0, 0),
(448212, 6, 1345.66, 970.281, 75.1914, NULL, 0, 2, 0, 0, 0),
(448212, 7, 1415.9, 1018.08, 55.3025, NULL, 0, 2, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83575 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=1908 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83575, 0, 1, 31, 0, 3, 1908, 0, 0, 0, 0, '', 'Blight Concoction - Target Vile Fin Oracle');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83575 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=1768 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83575, 0, 2, 31, 0, 3, 1768, 0, 0, 0, 0, '', 'Blight Concoction - Target Vile Fin Tidehunter');

-- Lake Frenzy
 UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 10 WHERE `id` = 6033;
 
-- Vile Fin Oracle
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 10 WHERE `id` = 1908;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 1908;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Random`, `InteractionPauseTimer`) VALUES 
(1908, 1, 1, 0, 0, 2, NULL);

-- Vile Fin Tidehunter
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 10 WHERE `id` = 1768;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 1768;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Random`, `InteractionPauseTimer`) VALUES 
(1768, 1, 1, 0, 0, 2, NULL);

-- Deathstalker Commander Belmont
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `ScriptName`='npc_silverpine_deathstalker' WHERE `entry`=44789; -- Deathstalker Commander Belmont

DELETE FROM `creature_template_addon` WHERE `entry` =44789;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(44789, 0, 0, 0, 65544, 1, 0, 0, 0, 0, 0, '83231');

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` =44789);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44789, 0, 0, 0, 7, 45338);

-- Deathstalker
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `ScriptName`='npc_silverpine_deathstalker' WHERE `entry`=44790; -- Deathstalker

DELETE FROM `creature_template_addon` WHERE `entry` =44790;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(44790, 0, 0, 0, 65544, 1, 0, 0, 0, 0, 0, '83231');

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` =44790);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44790, 0, 0, 0, 7, 45338);

-- Apothecary Witherbloom
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=44778; -- Apothecary Witherbloom

DELETE FROM `creature_template_addon` WHERE `entry` =44778;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44778, 0, 0, 0, 257, 133, 0, 0, 0, 0, ''); -- 44778 (Apothecary Witherbloom)

-- Apothecary Chase
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=45489; -- Apothecary Chase

DELETE FROM `creature_template_addon` WHERE `entry` =45489;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(45489, 0, 0, 0, 257, 133, 0, 0, 0, 0, ''); -- 45489 (Apothecary Chase)

-- Apothecary Marry
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=45490; -- Apothecary Marry

DELETE FROM `creature_template_addon` WHERE `entry` =45490;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(45490, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 45490 (Apothecary Marry)

DELETE FROM `npc_vendor` WHERE (`entry`=45489 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45489 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=45490 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(45489, 2, 183950, 0, 0, 1, 0, 0, 45338), -- Distilled Death Extract
(45489, 1, 3371, 0, 0, 1, 0, 0, 45338), -- Crystal Vial
(45490, 21, 20815, 0, 0, 1, 0, 0, 45338), -- Jeweler's Kit
(45490, 20, 39354, 0, 0, 1, 0, 0, 45338), -- Light Parchment
(45490, 19, 2324, 0, 0, 1, 0, 0, 45338), -- Bleach
(45490, 18, 2604, 0, 0, 1, 0, 0, 45338), -- Red Dye
(45490, 17, 6260, 0, 0, 1, 0, 0, 45338), -- Blue Dye
(45490, 16, 2605, 0, 0, 1, 0, 0, 45338), -- Green Dye
(45490, 15, 6530, 0, 0, 1, 0, 0, 45338), -- Nightcrawlers
(45490, 14, 6529, 0, 0, 1, 0, 0, 45338), -- Shiny Bauble
(45490, 13, 4289, 0, 0, 1, 0, 0, 45338), -- Salt
(45490, 12, 2880, 0, 0, 1, 0, 0, 45338), -- Weak Flux
(45490, 11, 2678, 0, 0, 1, 0, 0, 45338), -- Mild Spices
(45490, 10, 2321, 0, 0, 1, 0, 0, 45338), -- Fine Thread
(45490, 9, 2320, 0, 0, 1, 0, 0, 45338), -- Coarse Thread
(45490, 8, 3371, 0, 0, 1, 0, 0, 45338), -- Crystal Vial
(45490, 7, 6217, 0, 0, 1, 0, 0, 45338), -- Copper Rod
(45490, 6, 6256, 0, 0, 1, 0, 0, 45338), -- Fishing Pole
(45490, 5, 39505, 0, 0, 1, 0, 0, 45338), -- Virtuoso Inking Set
(45490, 4, 5956, 0, 0, 1, 0, 0, 45338), -- Blacksmith Hammer
(45490, 3, 2901, 0, 0, 1, 0, 0, 45338), -- Mining Pick
(45490, 2, 85663, 0, 0, 1, 0, 0, 45338), -- Herbalist's Spade
(45490, 1, 7005, 0, 0, 1, 0, 0, 45338); -- Skinning Knife

-- Apothecary Harrington
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=45491; -- Apothecary Harrington

DELETE FROM `creature_template_addon` WHERE `entry` =45491;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(45491, 0, 0, 0, 257, 133, 0, 0, 0, 0, ''); -- 45491 (Apothecary Harrington)

-- High Apothecary Shana T'veen
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=44784; -- High Apothecary Shana T'veen

DELETE FROM `creature_template_addon` WHERE `entry` =44784;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44784, 0, 0, 0, 257, 0, 0, 0, 0, 0, '');

-- Apothecary Initiate
DELETE FROM `creature_template_addon` WHERE `entry` =44786;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44786, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 44786 (Apothecary Initiate)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+28, @CGUID+31, @CGUID+34);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+28, 0, 0, 0, 0, 257, 133, 0, 0, 0, 0, ''),
(@CGUID+31, 0, 0, 0, 0, 257, 133, 0, 0, 0, 0, ''),
(@CGUID+34, 0, 0, 0, 0, 257, 133, 0, 0, 0, 0, '');
