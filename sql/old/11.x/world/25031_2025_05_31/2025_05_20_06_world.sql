SET @CGUID := 10006612;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 242126, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2607.99658203125, -2498.35595703125, 224.11517333984375, 4.175334930419921875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822); -- Flame's Radiance Recruiter (Area: Dornogal - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 483, 0, 0, 0, 0, ''); -- Flame's Radiance Recruiter

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 242126;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(242126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 242126 (Flame's Radiance Recruiter)

-- Template
UPDATE `creature_template` SET `faction`=3500, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=242126; -- Flame's Radiance Recruiter

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27961;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27961, 76795, 0, 60822);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27961 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27961, 103895, 0, 234774, 124582, 0, 0, 60822);

DELETE FROM `conversation_line_template` WHERE `Id`=76795;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(76795, 1061, 0, 0, 0, 60822);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=85005;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85005, 66, 0, 0, 0, 0, 0, 0, 0, 60822); -- A Radiant Call

DELETE FROM `creature_queststarter` WHERE (`id`=242126 AND `quest`=85005);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(242126, 85005, 60822); -- A Radiant Call offered by Flame's Radiance Recruiter

-- A Radiant Call
SET @ENTRY := 85005;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 27961, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation (27961) Actors<Mylton Wyldbraun (103895)> (first line 76795)', '');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` = 242126);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(242126, 1, 232795, 0, 0, 232795, 0, 0, 0, 0, 0, 60822); -- Flame's Radiance Recruiter

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (242126,234774));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(242126, 0, 10, 12, 1, 321412, 0x0, 0), -- Flame's Radiance Recruiter
(234774, 0, 10, 1, 1, 313478, 0x0, 0); -- Mylton Wyldbraun

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3031, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=242126 AND `DifficultyID`=0); -- 242126 (Flame's Radiance Recruiter) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (111719, 127822, 100693, 128002);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(111719, 0.678318619728088378, 0, 0, 60822),
(127822, 1.582851648330688476, 0, 0, 60822),
(100693, 2.162711143493652343, 0.9375, 0, 60822),
(128002, 0.208000004291534423, 1.5, 0, 60822);

UPDATE `creature_model_info` SET `VerifiedBuild`=60822 WHERE `DisplayID` IN (117357, 111139, 118385, 64062, 77407, 120956, 120954, 77405, 120957, 115037, 115038, 118411, 121052, 117338, 108778, 27019, 77406, 57067, 120606, 120627, 117238, 118386, 117689, 117415, 110229, 118461, 105546, 63716, 120630, 117424, 119305, 121975, 104042, 122492, 117412, 108870, 117649, 120641, 117428, 117198, 120981, 16925, 117695, 120607, 117200, 28282, 28111, 117806, 108867, 5448, 121053, 120628, 117757, 27823, 120621, 115505, 104041, 118319, 119120, 118182, 108813, 117356, 117696, 22003, 121065, 120619, 121148, 115036, 117336, 120617, 120629, 117417, 117427, 110227, 120639, 117650, 11686, 114500, 125926, 117690, 120914, 117342, 114796, 117409, 118376, 115035, 88423, 23767, 117429, 88792, 117651, 111138, 122671, 106697, 118073, 122774, 122773, 117653, 42722, 117199, 42720, 38804, 122675, 117426, 107560, 117697, 122301, 122995, 104040, 112806, 119050, 120611, 27959, 117344);
UPDATE `creature_model_info` SET `BoundingRadius`=0.415409952402114868, `VerifiedBuild`=60822 WHERE `DisplayID`=111028;
UPDATE `creature_model_info` SET `BoundingRadius`=0.937144756317138671, `VerifiedBuild`=60822 WHERE `DisplayID`=117725;
