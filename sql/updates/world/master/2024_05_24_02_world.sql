
SET @CGUID := 7000533;

DELETE FROM `phase_name` WHERE `ID`=12624;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12624, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater and Lumberjacks in Algerson Lumberyard Office');

DELETE FROM `phase_area` WHERE `PhaseId`=12624;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9334, 12624, 'Cosmetic: Kul Tiran Unlock Questline - Dorian Atwater and Lumberjacks in Algerson Lumberyard Office');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12624));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12624, 0, 0, 0, 47, 0, 54726, 74, 0, '', 0, 'Player have Frame Work (54726) in state complete, incomplete, rewarded');

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (149019,149020,149021,149022));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(149019, 1, 109579, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- Algerson Lumberjack
(149020, 1, 109579, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- Algerson Lumberjack
(149021, 1, 109579, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- Algerson Lumberjack
(149022, 1, 109579, 0, 0, 0, 0, 0, 0, 0, 0, 54762); -- Algerson Lumberjack

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149019, 1643, 8567, 9334, '0', 12624, 0, 0, 1, 1291.76220703125, -132.538192749023437, 11.58151435852050781, 0.166917353868484497, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+1, 149020, 1643, 8567, 9334, '0', 12624, 0, 0, 1, 1303.2274169921875, -125.753471374511718, 11.46352577209472656, 3.386868715286254882, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+2, 149021, 1643, 8567, 9334, '0', 12624, 0, 0, 1, 1297.2603759765625, -130.052078247070312, 11.46352577209472656, 0.365938574075698852, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+3, 149022, 1643, 8567, 9334, '0', 12624, 0, 0, 1, 1298.8819580078125, -130.274307250976562, 11.46352577209472656, 2.196896314620971679, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1
(@CGUID+4, 148870, 1643, 8567, 9334, '0', 12624, 0, 0, 0, 1294.998291015625, -126.805557250976562, 11.46352577209472656, 2.681195974349975585, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Dorian Atwater (Area: Algerson Lumber Yard - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0, 0, ''), -- Algerson Lumberjack
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 731, 0, 0, 0, 0, ''); -- Algerson Lumberjack

DELETE FROM `creature_template_addon` WHERE `entry` IN (149019, 149021, 149022);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(149019, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 149019 (Algerson Lumberjack)
(149021, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 149021 (Algerson Lumberjack)
(149022, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 149022 (Algerson Lumberjack)

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149019 AND `DifficultyID`=0); -- 149019 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149020 AND `DifficultyID`=0); -- 149020 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149021 AND `DifficultyID`=0); -- 149021 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149022 AND `DifficultyID`=0); -- 149022 (Algerson Lumberjack) - CanSwim

UPDATE `creature_template` SET `faction`=2909, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry` IN (149020, 149019, 149021, 149022); -- Algerson Lumberjack

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (91494, 91495);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(91494, 0.6987152099609375, 1.5, 0, 54762),
(91495, 0.347222000360488891, 1.5, 0, 54762);

UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (78480, 80857, 33719, 32646, 707, 79015, 80750, 30256, 88594, 64814, 79804, 47165, 42744, 61206, 47166, 78835, 64329, 80777, 80754, 80753, 80854, 80752, 83295, 61205, 80746, 79871, 80751);

 -- Algerson Lumberjack smart ai
SET @ENTRY := 149021;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 5000, 6000, 5000, 6000, 10, 274, 273, 1, 6, 603, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (OOC) - Self: Play random emote: 274, 273, 1, 6, 603,');

 -- Algerson Lumberjack smart ai
SET @ENTRY := 149022;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 3000, 4000, 5000, 6000, 10, 274, 273, 1, 6, 603, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (OOC) - Self: Play random emote: 274, 273, 1, 6, 603,');
