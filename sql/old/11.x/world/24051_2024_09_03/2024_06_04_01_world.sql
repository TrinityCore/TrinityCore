DELETE FROM `creature_template_addon` WHERE `entry` IN (139250 /*139250 (Abyssal Spawn) - Void Form*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(139250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '266301'); -- 139250 (Abyssal Spawn) - Void Form

UPDATE `creature_template_difficulty` SET `ContentTuningID`=188, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=139250 AND `DifficultyID`=0); -- 139250 (Abyssal Spawn) - CanSwim

UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=139250; -- Abyssal Spawn

-- Umbral Hulk smart ai
SET @ENTRY := 148913;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 0, 0, 100, 0, 12700, 12700, 14600, 14600, 11, 262739, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 14.6 seconds (12.7s initially) (IC) - Self: Cast spell 262739 on Victim'),
(@ENTRY, 0, 1, 0, '', 0, 0, 100, 0, 16300, 16300, 14600, 14600, 11, 262719, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 14.6 seconds (16.3s initially) (IC) - Self: Cast spell 262719 on Self');

-- Drowned Harbinger smart ai
SET @ENTRY := 148912;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY AND `id` BETWEEN 2 AND 6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 2, 0, '', 4, 0, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Talk 0 to invoker'),
(@ENTRY, 0, 3, 0, '', 6, 0, 10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On death - Self: Talk 1 to invoker'),
(@ENTRY, 0, 4, 0, '', 0, 0, 100, 0, 14000, 14000, 17000, 25000, 11, 273544, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 17 - 25 seconds (14 - 14s initially) (IC) - Self: Cast spell  273544 on Self'),
(@ENTRY, 0, 5, 0, '', 0, 0, 100, 0, 22500, 22500, 18300, 23100, 11, 273467, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 18.3 - 23.1 seconds (22.5 - 22.5s initially) (IC) - Self: Cast spell  273467 on Victim'),
(@ENTRY, 0, 6, 0, '', 0, 0, 100, 0, 7900, 7900, 23100, 32800, 11, 264892, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 23.1 - 32.8 seconds (7.9 - 7.9s initially) (IC) - Self: Cast spell  264892 on Victim');

-- Drowned Convert smart ai
SET @ENTRY := 148911;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 4, 0, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Talk 0 to invoker'),
(@ENTRY, 0, 1, 0, '', 6, 0, 10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On death - Self: Talk 1 to invoker'),
(@ENTRY, 0, 2, 0, '', 0, 0, 100, 0, 6000, 8500, 6000, 8500, 11, 274061, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 8.5 seconds (IC) - Self: Cast spell  274061 on Victim');

-- Corrupted Waters smart ai
SET @ENTRY := 148915;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 6, 0, 100, 0, 0, 0, 0, 0, 11, 294503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On death - Self: Cast spell  294503 on Self');

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (18235,18242,20893));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(18235, 0, 0, 54762),
(18242, 0, 0, 54762),
(20893, 0, 0, 54762);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (13734,13744,16494));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(13734, 0, 18235, 0, 0, 0, 0, 0, 0, -1, 0, 0, 5038, 15000, 4, 2, 2, 10, 10, 0, 0, 0, 0, 54762), -- Spell: 273467 (Void Orb)
(13744, 0, 18242, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 4000, 0, 1, 1, 0, 0, 0, 0, 0, 0, 54762), -- Spell: 273544 (Abyssal Portal)
(16494, 0, 20893, 0, 0, 0, 0, 0, 0, -1, 0, 228, 0, 10000, 0, 2, 2, 0, 0, 0, 0, 0, 0, 54762); -- Spell: 294503 (Pooled Corruption)

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId`=20893 AND `IsCustom`=0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(20893, 0, 1, 294504, 2); -- Spell: 294503 (Pooled Corruption)

UPDATE `areatrigger_create_properties` SET `ScriptName`='at_void_orb_harbinger' WHERE `Id`=13734 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `ScriptName`='at_abyssal_portal_harbinger' WHERE `Id`=13744 AND `IsCustom`=0;

DELETE FROM `creature_text` WHERE `CreatureID` IN(148911, 148912);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(148911, 0, 0, 'Sleep eternal in Ny''alotha.', 12, 178, 100, 1, 0, 103716, 149632, 0, 'Drowned Convert to Player'),
(148911, 0, 1, 'Gaze upon the shadow of your demise.', 12, 0, 100, 1, 0, 103714, 149629, 0, 'Drowned Convert to Player'),
(148911, 0, 2, 'Light dies in the endless fathoms.', 12, 0, 100, 1, 0, 103715, 149631, 0, 'Drowned Convert to Player'),
(148911, 0, 3, 'The stars fear our ascension.', 12, 0, 100, 1, 0, 103718, 149635, 0, 'Drowned Convert to Player'),
(148911, 0, 4, 'Your soul will know only hunger.', 12, 0, 100, 0, 0, 103716, 149636, 0, 'Drowned Convert to Player'),
(148911, 0, 5, 'Drown in the blood of the infinite.', 12, 0, 100, 1, 0, 103720, 149643, 0, 'Drowned Convert to Player'),
(148911, 1, 0, 'The seed... takes root...', 12, 0, 100, 1, 0, 103726, 149675, 0, 'Drowned Convert to Frothing Pustule'),
(148911, 1, 1, 'Even death... may... die...', 12, 0, 100, 1, 0, 103723, 149672, 0, 'Drowned Convert to Frothing Pustule'),
(148911, 1, 2, 'The endless shadow... embraces me...', 12, 0, 100, 1, 0, 103728, 149678, 0, 'Drowned Convert to Player'),
(148911, 1, 3, 'The cycle... continues...', 12, 0, 100, 0, 0, 103729, 149673, 0, 'Drowned Convert to Player'), -- BroadcastTextID: 90884 - 149673
(148911, 1, 4, 'I am but one... of many...', 12, 0, 100, 0, 0, 103725, 149674, 0, 'Drowned Convert to Player'),
(148911, 1, 5, 'I sleep... only to wake...', 12, 0, 100, 0, 0, 103729, 149680, 0, 'Drowned Convert to Player'),
-- 
(148912, 0, 0, 'Sleep eternal in Ny''alotha.', 12, 178, 100, 0, 0, 103716, 149632, 0, 'Drowned Harbinger to Player'),
(148912, 0, 1, 'Gaze upon the shadow of your demise.', 12, 0, 100, 0, 0, 103714, 149629, 0, 'Drowned Harbinger to Player'),
(148912, 0, 2, 'The currents wash you into the abyss.', 12, 0, 100, 0, 0, 103721, 149668, 0, 'Drowned Harbinger to Player'),
(148912, 0, 3, 'Light dies in the endless fathoms.', 12, 0, 100, 0, 0, 103715, 149631, 0, 'Drowned Harbinger to Player'),
(148912, 0, 4, 'Know the embrace of true nothingness.', 12, 0, 100, 0, 0, 103717, 149633, 0, 'Drowned Harbinger to Player'),
(148912, 0, 5, 'Your soul will know only hunger.', 12, 0, 100, 0, 0, 103716, 149636, 0, 'Drowned Harbinger to Player'),
(148912, 0, 6, 'Drown in the blood of the infinite.', 12, 0, 100, 1, 0, 103720, 149643, 0, 'Drowned Harbinger to Player'),
(148912, 1, 0, 'The seed... takes root...', 12, 0, 100, 0, 0, 103726, 149675, 0, 'Drowned Harbinger to Player'),
(148912, 1, 1, 'In the end... you will know the truth...', 12, 0, 100, 0, 0, 103722, 149671, 0, 'Drowned Harbinger to Player'),
(148912, 1, 2, 'The cycle... continues...', 12, 0, 100, 0, 0, 103724, 149673, 0, 'Drowned Harbinger to Frothing Pustule'), -- BroadcastTextID: 90884 - 149673
(148912, 1, 3, 'Your hope... wanes...', 12, 0, 100, 0, 0, 103727, 149677, 0, 'Drowned Harbinger to Player'),
(148912, 1, 4, 'I am but one... of many...', 12, 0, 100, 0, 0, 103725, 149674, 0, 'Drowned Harbinger to Player'),
(148912, 1, 5, 'Even death... may... die...', 12, 0, 100, 1, 0, 103723, 149672, 0, 'Drowned Harbinger to Frothing Pustule'),
(148912, 1, 6, 'The endless shadow... embraces me...', 12, 0, 100, 1, 0, 103728, 149678, 0, 'Drowned Harbinger to Player');
