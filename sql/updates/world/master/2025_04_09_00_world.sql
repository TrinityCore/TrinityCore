SET @ATSPAWNID := 199;
SET @ATID := 105;
SET @ATPROPERTIESID := 100;

-- Creatures
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=144306 AND `DifficultyID`=23); -- 144306 (Bloodsworn Defiler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=138740 AND `DifficultyID`=23); -- 138740 (Musashitake) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=131383 AND `DifficultyID`=23); -- 131383 (Sporecaller Zancha) - CanSwim

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (139127,131597));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(139127, 23, 0, 0, 502, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 58911), -- 139127 (Volatile Pod) - Sessile, Floating
(131597, 23, 0, 0, 502, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 58911); -- 131597 (Spore Pod) - Sessile, Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=145910 WHERE `Entry`=139127; -- Volatile Pod
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=137515, `StaticFlags1`=0x20000100 WHERE `Entry`=131597; -- Spore Pod

UPDATE `creature_template` SET `unit_flags3`=0x41000001, `AIName`='SmartAI' WHERE `entry`=139127; -- Volatile Pod
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x800, `unit_flags3`=0x41080001, `AIName`='SmartAI' WHERE `entry`=131597; -- Spore Pod
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=144306; -- Bloodsworn Defiler
UPDATE `creature_template` SET `ScriptName`='boss_sporecaller_zancha' WHERE `entry`=131383;
UPDATE `creature_template` SET `ScriptName`='npc_sporecaller_zancha_musashitake' WHERE `entry`=138740;

DELETE FROM `creature_template_addon` WHERE `entry` IN (131597);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(131597, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '259727'); -- 131597 (Spore Pod) - Boundless Rot

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (272104, 259720, 272511, 272457, 259732);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 272104, 0, 0, 51, 0, 5, 131383, 0, '', 0, 0, 0, '', 'Spell \'Infusion\' can only hit \'Sporecaller Zancha\''),
(13, 4, 259720, 0, 0, 51, 0, 5, 131597, 0, '', 0, 0, 0, '', 'Spell \'Upheaval\' can only hit \'Spore Pod\''),
(13, 4, 259720, 0, 1, 51, 0, 5, 138740, 0, '', 0, 0, 0, '', 'Spell \'Upheaval\' can only hit \'Musashitake\''),
(13, 1, 272511, 0, 0, 51, 0, 5, 131383, 0, '', 0, 0, 0, '', 'Spell \'Upheaval\' can only hit \'Sporecaller Zancha\''),
(13, 2, 272457, 0, 0, 51, 0, 5, 131597, 0, '', 0, 0, 0, '', 'Spell \'Shockwave\' can only hit \'Spore Pod\''),
(13, 2, 272457, 0, 1, 51, 0, 5, 138740, 0, '', 0, 0, 0, '', 'Spell \'Shockwave\' can only hit \'Musashitake\''),
(13, 1, 259732, 0, 0, 51, 0, 5, 131597, 0, '', 0, 0, 0, '', 'Spell \'Festering Harvest\' can only hit \'Spore Pod\'');

-- Areatriggers
-- INTRO
DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID, @ATPROPERTIESID, 1, 1841, '1,2,8,23', 1032.939941, 1058.290039, 33.330898, 4.695440, 0, 0, 0, '', 'The Underrot - Sporecaller Zancha Intro', 56647);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATPROPERTIESID AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 25, 25, 0, 0, 0, 0, 0, 0, 'at_sporecaller_zancha_intro', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, 0, 0);

-- SPELLS
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (18227, 16966));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(18227, 0, 0, 0x0800, 58911),
(16966, 0, 0, 0, 49343);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (12266, 13726));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(13726, 0, 18227, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 10000, 7.500002384185791015, 4, 2, 2, 10, 10, 3, 3, 0, 0, 'at_sporecaller_zancha_volatile_pod', 58911), -- Spell: 273300 (Volatile Pods)
(12266, 0, 16966, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 4, 1, 1, 3, 3, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_sporecaller_zancha_boundless_rot', 49343); -- Spell: 259727 (Boundless Rot)

-- Conversation
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (9671, 8358));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(9671, 51642, 0, 119889, 26353, 0, 0, 58911),
(8358, 64741, 0, 138740, 83603, 0, 0, 49343); -- Full: 0x204250E620877D0000613D000050E907 Creature/0 R4244/S24893 Map: 1841 (The Underrot) Entry: 138740 (Musashitake) Low: 5302535

DELETE FROM `conversation_line_template` WHERE `Id` IN (22107, 18916);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(22107, 90, 0, 0, 0, 58911),
(18916, 0, 0, 0, 0, 49343);

DELETE FROM `conversation_template` WHERE `Id` IN (9671, 8358);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(9671, 22107, 0, 58911),
(8358, 18916, 0, 49343);

-- Summon groups
DELETE FROM `creature` WHERE `guid` IN (850863, 850860, 850857, 850855, 850842);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=131383;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(131383, 0, 0, 144306, 1041.1, 1051.63, 33.536, 2.44391, 8, 0, 'Sporecaller Zancha - Group 0 - Bloodsworn Defiler'),
(131383, 0, 0, 144306, 1040.15, 1066.87, 33.4068, 3.99352, 8, 0, 'Sporecaller Zancha - Group 0 - Bloodsworn Defiler'),
(131383, 0, 0, 144306, 1024.94, 1050.99, 33.4707, 0.8341, 8, 0, 'Sporecaller Zancha - Group 0 - Bloodsworn Defiler'),
(131383, 0, 0, 144306, 1025.44, 1066.86, 33.3309, 5.471, 8, 0, 'Sporecaller Zancha - Group 0 - Bloodsworn Defiler'),
(131383, 0, 1, 138740, 987.078, 1089.9, 33.2575, 2.76614, 8, 0, 'Sporecaller Zancha - Group 1 - Musashitake'),
(131383, 0, 2, 139127, 1029.8716, 1034.783, 33.64273, 1.443644, 8, 0, 'Sporecaller Zancha - Group 2 - Volatile Pods'),
(131383, 0, 2, 139127, 1013.9844, 1074.3785, 33.120163, 5.567163, 8, 0, 'Sporecaller Zancha - Group 2 - Volatile Pods'),
(131383, 0, 2, 139127, 1007.908, 1051.2622, 32.986603, 0.226441, 8, 0, 'Sporecaller Zancha - Group 2 - Volatile Pods'),
(131383, 0, 2, 139127, 1052.5226, 1072.8438, 32.91686, 3.785604, 8, 0, 'Sporecaller Zancha - Group 2 - Volatile Pods'),
(131383, 0, 2, 139127, 1049.1493, 1043.3004, 33.95835, 2.441261, 8, 0, 'Sporecaller Zancha - Group 2 - Volatile Pods'),
(131383, 0, 2, 139127, 1035.6615, 1082.0781, 32.738506, 4.595758, 8, 0, 'Sporecaller Zancha - Group 2 - Volatile Pods');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=144306 AND  `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(144306, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 272104, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Bloodsworn Defiler - On Created - Cast Self: Infusion');

DELETE FROM `smart_scripts` WHERE `entryorguid`=131597 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(131597, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Spore Pod - On Just Created - Set ReactState Passive'),
(131597, 0, 1, 4, '', 8, 0, 100, 0, 272457, 0, 0, 0, 0, '', 85, 259862, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Spore Pod - On Spellhit - Cast \'Spore Pod hit by Boss Ability\''),
(131597, 0, 2, 4, '', 8, 0, 100, 0, 259720, 0, 0, 0, 0, '', 85, 259862, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Spore Pod - On Spellhit - Cast \'Spore Pod hit by Boss Ability\''),
(131597, 0, 3, 4, '', 8, 0, 100, 0, 259732, 0, 0, 0, 0, '', 85, 259958, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Spore Pod - On Spellhit - Cast \'BIG Spore Pod Detonation\''),
(131597, 0, 4, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 41, 100, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Spore Pod - On Linked Event - Despawn');

 -- Volatile Pod smart ai
SET @ENTRY := 139127;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (13912700);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 80, 13912700, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Start timed action list id #Volatile Pod #0 (13912700) (update always) // -inline', ''),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set react state to Passive', ''),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 128, 7687, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 7687', ''),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 85, 273285, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell 273285 on self', ''),
(@ENTRY * 100, 9, 3, 0, 0, 0, 100, 0, 100, 100, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Despawn instantly', '');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (131383, 138740);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(131383, 0, 0, 'Rot must spread!', 14, 0, 50, 0, 0, 109964, 143938, 0, 'Sporecaller Zancha'),
(131383, 0, 1, 'Harvest!', 14, 0, 50, 0, 0, 109965, 143939, 0, 'Sporecaller Zancha'),
(131383, 1, 0, '|TInterface\\Icons\\ABILITY_EARTHEN_PILLAR.BLP:20|t %s targets you with |cFFFF0000|Hspell:259720|h[Upheaval]|h|r!', 42, 0, 100, 0, 0, 0, 161956, 0, 'Sporecaller Zancha'),
(131383, 2, 0, 'Grow!', 14, 0, 50, 0, 0, 109960, 143951, 0, 'Sporecaller Zancha'), -- BroadcastTextID: 86442 - 143951
(131383, 2, 1, 'Corruption blooms!', 14, 0, 50, 0, 0, 109962, 143953, 0, 'Sporecaller Zancha'),
(131383, 3, 0, 'Such fertile soil.', 14, 0, 100, 0, 0, 109969, 143948, 0, 'Sporecaller Zancha'),
(131383, 4, 0, 'Must feed!', 14, 0, 100, 0, 0, 109968, 143955, 0, 'Sporecaller Zancha'),
(131383, 5, 0, 'Everything... decays...', 14, 0, 100, 0, 0, 109966, 143960, 0, 'Sporecaller Zancha'),
(138740, 0, 0, 'Nothing personal.', 12, 0, 100, 0, 0, 0, 157014, 0, 'Musashitake to Player'); -- BroadcastTextID: 31808 - 157014

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (273285, 273271, 272511, 259888, 259845, 259732, 259718, 273226, 259717, 272786, 272787);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(273285, 'spell_sporecaller_zancha_volatile_pods_explosion'),
(273271, 'spell_sporecaller_zancha_volatile_pods'),
(272511, 'spell_sporecaller_zancha_upheaval_script_effect'),
(259888, 'spell_sporecaller_zancha_festering_harvest'),
(259845, 'spell_sporecaller_zancha_boundless_rot'),
(259732, 'spell_sporecaller_zancha_festering_harvest_pods_selector'),
(259718, 'spell_sporecaller_zancha_upheaval_marker'),
(259717, 'spell_sporecaller_zancha_upheaval_selector'),
(272786, 'spell_sporecaller_zancha_musashitake_teleport_selector'),
(272787, 'spell_sporecaller_zancha_musashitake_teleport');

DELETE FROM `creature_template_addon` WHERE `entry`=139127;
INSERT INTO `creature_template_addon` (`entry`, `AnimTier`) VALUES
(139127, 0);
