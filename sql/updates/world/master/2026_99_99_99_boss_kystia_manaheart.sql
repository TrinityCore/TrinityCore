SET @CGUID := 757575775;
SET @OGUID := 757575775;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 234648, 2813, 16091, 16091, '1,2,8,23,205', '0', 0, 0, 0, 8858.5732421875, -4841.0869140625, -6.9904031753540039, 4.624201774597167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66220), -- Kystia Manaheart (Area: Murder Row - Difficulty: 0) CreateObject1 (Auras: 474365 - Fel Crazed, 422356 - Bot AI Follow Advert, 1217989 - Felshield, 1217464 - Illicit Infusion) (possible waypoints or random movement)
(@CGUID+1, 234660, 2813, 16091, 16091, '1,2,8,23,205', '0', 0, 0, 0, 8858.5732421875, -4850.85400390625, -6.9904031753540039, 1.564232110977172851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66220); -- Nibbles (Area: Murder Row - Difficulty: 0) CreateObject1 (Auras: 1230289 - Illicit Infusion)

DELETE FROM `creature_template_addon` WHERE `entry` IN (234648, 255050, 234660);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(234648, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '422356'), -- 234648 (Kystia Manaheart) - Bot AI Follow Advert
(255050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1264103'), -- 255050 (Kystia Manaheart) - VFX
(234660, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '1230289'); -- 234660 (Nibbles) - Illicit Infusion

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (234648, 234660, 255050));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(255050, 1, 11, 10, 1, 335959, 0x1000000, 128, 0), -- Kystia Manaheart
(234648, 1, 11, 30, 1, 286375, 0x200068, 4224, 0), -- Kystia Manaheart
(234660, 1, 11, 12, 1, 286387, 0x200068, 128, 0); -- Nibbles

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=3233, `StaticFlags1`=0x10000000, `VerifiedBuild`=66220 WHERE (`Entry`=234660 AND `DifficultyID`=1); -- 234660 (Nibbles) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=3233, `StaticFlags1`=0x10000000, `VerifiedBuild`=66220 WHERE (`Entry`=234648 AND `DifficultyID`=1); -- 234648 (Kystia Manaheart) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=3233, `VerifiedBuild`=66220 WHERE (`Entry`=255050 AND `DifficultyID`=1); -- 255050 (Kystia Manaheart) - 

UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x40, `ScriptName`='boss_kystia_manaheart' WHERE `entry`=234648; -- Kystia Manaheart
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2400, `unit_flags`=0x000, `unit_flags3`=0x800001, `ScriptName`='boss_kystia_manaheart_nibbles' WHERE `entry`=234660; -- Nibbles
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `AIName`= 'SmartAI' WHERE `entry`=255050; -- Kystia Manaheart

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (234648));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(234648, 1, 208225, 0, 0, 0, 0, 0, 0, 0, 0, 66220); -- Kystia Manaheart

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (126199, 124578, 138932);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(124578, 0.765999972820281982, 3, 0, 66220),
(138932, 0.765999972820281982, 3, 0, 66220),
(126199, 2.475043296813964843, 4, 0, 66220);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=234660;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(234660, 1, 0, 0, NULL);

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(@OGUID+0, 618401, 2813, 16091, 16091, '1,2,8,23,205', '0', 0, 8817.5693359375, -4840.35400390625, -9.61550140380859375, 3.132858037948608398, 0, 0, 0.999990463256835937, 0.004367320332676172, 7200, 255, 0, 66220); -- Fel Door (Area: Murder Row - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template` WHERE `entry` = 618401;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(618401, 0, 118294,'Fel Door', '', '', 1.800000429153442382, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66220); -- Fel Door

DELETE FROM `gameobject_template_addon` WHERE `entry` = 618401;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(618401, 0, 0x30, 0, 0); -- Fel Door

-- Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (36175,36260,36030,36393,2329,39934,36242,36356,36048,39560,36081,39834,26730,23866,2442,32530,30795,41463,41462));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(39560, 0, 41022, 0, 2, 0, 0, 0, 0, -1, 0, 0, NULL, 5000, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 'at_kystia_manaheart_fel_spray', 66220); -- Spell: 1253811 (Fel Spray)

DELETE FROM `areatrigger_create_properties_polygon_vertex` WHERE (`AreaTriggerCreatePropertiesId`=39560 AND `IsCustom`=0 AND `Idx`=0) OR (`AreaTriggerCreatePropertiesId`=39560 AND `IsCustom`=0 AND `Idx`=1) OR (`AreaTriggerCreatePropertiesId`=39560 AND `IsCustom`=0 AND `Idx`=2) OR (`AreaTriggerCreatePropertiesId`=39560 AND `IsCustom`=0 AND `Idx`=3);
INSERT INTO `areatrigger_create_properties_polygon_vertex` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(39560, 0, 0, 0, 1, NULL, NULL, 66220), -- Spell: 1253811 (Fel Spray)
(39560, 0, 1, 0, -1, NULL, NULL, 66220), -- Spell: 1253811 (Fel Spray)
(39560, 0, 2, 60, -45, NULL, NULL, 66220), -- Spell: 1253811 (Fel Spray)
(39560, 0, 3, 60, 45, NULL, NULL, 66220); -- Spell: 1253811 (Fel Spray)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (41022));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(41022, 0, 66220);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=2 AND `SourceEntry`=1217464;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 1217464, 0, 0, 51, 0, 5, 234660, 0, '', 0, 0, 0, '', 'Spell \'Illicit Infusion\' can only hit \'Nibbles\'');

-- Instance
DELETE FROM `instance_template` WHERE `map`=2813;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2813, 0, 'instance_murder_row');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 255050 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(255050, 0, 0, 0, '', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 1264106, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kystia Manaheart (copy) - On Respawn - Cast \'Felstorm\'');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_kystia_manaheart_destabilized', 'spell_kystia_manaheart_mirror_images', 'spell_kystia_manaheart_mirror_image', 'spell_kystia_manaheart_light_infusion', 'spell_kystia_manaheart_fel_crazed', 'spell_kystia_manaheart_fel_nova_selector', 'spell_kystia_manaheart_blink');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1264095, 'spell_kystia_manaheart_mirror_images'),
(1264098, 'spell_kystia_manaheart_mirror_image'),
(1230304, 'spell_kystia_manaheart_light_infusion'),
(474365, 'spell_kystia_manaheart_fel_crazed'),
(474240, 'spell_kystia_manaheart_fel_nova_selector'),
(1265412, 'spell_kystia_manaheart_destabilized'),
(474183, 'spell_kystia_manaheart_blink');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (234648, 234660);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(234648, 0, 0, 'Let\'s make an example of you.', 14, 0, 100, 0, 0, 306490, 281368, 0, 'Kystia Manaheart'),
(234648, 1, 0, 'Flee the flame!', 14, 0, 50, 0, 0, 299094, 297213, 0, 'Kystia Manaheart'),
(234648, 1, 1, 'Fear the fel!', 14, 0, 50, 0, 0, 299095, 297214, 0, 'Kystia Manaheart'),
(234648, 2, 0, 'Learn your place!', 14, 0, 50, 0, 0, 299093, 297210, 0, 'Kystia Manaheart'),
(234648, 2, 1, 'Back, you mongrels!', 14, 0, 50, 0, 0, 299092, 297209, 0, 'Kystia Manaheart'),
(234648, 3, 0, 'Naughty little Nibbles!', 14, 0, 50, 0, 0, 299096, 297215, 0, 'Kystia Manaheart to Nibbles'),
(234648, 3, 1, 'Nibbles! Drop it!', 14, 0, 50, 0, 0, 299097, 297216, 0, 'Kystia Manaheart to Nibbles'),
(234648, 4, 0, 'Ahh, just what I needed.', 14, 0, 50, 0, 0, 299091, 297208, 0, 'Kystia Manaheart'),
(234648, 4, 1, 'Nibbles, give mother a taste!', 14, 0, 50, 0, 0, 299090, 297206, 0, 'Kystia Manaheart'),
(234648, 5, 0, 'Fel conquers all.', 14, 0, 100, 0, 0, 299087, 297199, 0, 'Kystia Manaheart'),
(234648, 6, 0, 'But... my... magic...', 14, 0, 100, 0, 0, 299088, 297202, 0, 'Kystia Manaheart to Player'),
(234660, 0, 0, '|TInterface\\ICONS\\Spell_Fire_FelFlameBreath.blp:20|t %s begins casting |cFFFF0000|Hspell:1253811|h[Fel Spray]|h|r!', 68, 0, 100, 0, 0, 0, 0, 0, 'Nibbles to Player'),
(234660, 1, 0, '|TInterface\\ICONS\\Spell_Paladin_Lightofdawn.blp:20|t %s casts |cFFFF0000|Hspell:1230304|h[Light Infusion]|h|r at Kystia!', 68, 0, 100, 0, 0, 0, 0, 0, 'Nibbles to Kystia Manaheart'),
(234660, 2, 0, '%s makes her escape.', 68, 0, 100, 0, 0, 299088, 280475, 0, 'Nibbles to Nibbles');
