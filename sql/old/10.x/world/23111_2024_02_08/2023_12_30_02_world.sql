SET @ATID := 55;
SEt @ATCP := 44;
SET @ATIDSPAWN := 55;

-- Update Template
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=139645; -- Vision of Sailor's Memory
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_jaina_proudmoore_tides_of_war' WHERE `entry` = 120590; -- Jaina Proudmoore
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=120788; -- Genn Greymane

-- Serverside AT
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID+0 AND `IsCustom` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 20, 20, 12, 20, 20, 12, 0, 0, 'at_stormwind_keep_tides_of_war', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 0, '0', -8390.378, 319.124, 147.014, 0.653896, 0, 8480, 0, NULL, '', 'Stormwind Keep Tides of War', 0);

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 120590;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(120590, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 120590 (Lady Jaina Proudmoore)

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` = 284807;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(284807, 'spell_despawn_sailor_memory');

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 139645;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(139645, 0, 0, 1, 1, 0, 0, NULL);

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 139645;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(139645, 274244, 3, 0);

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (139645,139636,120597,120756,139642,209790));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(139645, 0, 0, 0, 186, 7, 1, 1, 146480, 1610612752, 6, 52393), -- Vision of Sailor's Memory
(139636, 0, 0, 0, 186, 7, 20, 1, 146471, 0, 0, 52393), -- Master Mathias Shaw
(120597, 0, 0, 0, 494, 7, 15, 1, 124911, 0, 0, 52393), -- Commander Lorna Crowley
(120756, 0, 0, 0, 794, 7, 1200, 1, 125102, 76, 32768, 52393), -- Anduin Wrynn
(139642, 0, 0, 0, 189, 7, 1, 1, 146477, 0, 0, 52393), -- 7th Legion Sailor
(209790, 0, 0, 0, 2715, 9, 5, 10, 240103, 0, 50331648, 52393); -- Virtos

-- Model data
DELETE FROM `creature_model_info` WHERE `DisplayID`=107886;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(107886, 0.305999994277954101, 1.5, 0, 52393);

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (8709, 4857, 4818);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(8709, 19487, 0, 52393),
(4857, 19476, 0, 52393),
(4818, 10748, 0, 52393);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_start_council_tides_of_war' WHERE `Id` = 4857;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=4818 AND `Idx`=0) OR (`ConversationId`=8709 AND `Idx` IN (0,1,2)) OR (`ConversationId`=4857 AND `Idx` IN (3,1,2,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(4818, 53220, 0, 0, 107574, 82047, 0, 0, 52393),
(8709, 53220, 850679, 0, 0, 0, 0, 0, 52393), -- Full: 0x203ADC000075ED000033AF0000742AB5 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 120756 (Anduin Wrynn) Low: 7613109
(8709, 467, 850678, 1, 0, 0, 0, 0, 52393), -- Full: 0x203ADC000075C3800033AF0000742AB5 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 120590 (Lady Jaina Proudmoore) Low: 7613109
(8709, 64275, 850675, 2, 0, 0, 0, 0, 52393), -- Full: 0x203ADC000075F5000033AF0000742AB5 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 120788 (Genn Greymane) Low: 7613109
(4857, 467, 0, 3, 0, 0, 0, 0, 52393), -- Full: 0x203ADC000075C3800033AF00007494D0 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 120590 (Lady Jaina Proudmoore) Low: 7640272
(4857, 64989, 850677, 1, 0, 0, 0, 0, 52393), -- Full: 0x203ADC0000885D000033AF0000742AB5 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 139636 (Master Mathias Shaw) Low: 7613109
(4857, 64275, 850675, 2, 0, 0, 0, 0, 52393), -- Full: 0x203ADC000075F5000033AF0000742AB5 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 120788 (Genn Greymane) Low: 7613109
(4857, 53220, 850679, 0, 0, 0, 0, 0, 52393); -- Full: 0x203ADC000075ED000033AF0000742AB5 Creature/0 R3767/S13231 Map: 0 (Eastern Kingdoms) Entry: 120756 (Anduin Wrynn) Low: 7613109

DELETE FROM `conversation_line_template` WHERE `Id` IN (10748, 19496, 19495, 19494, 19493, 19492, 19491, 19490, 19489, 19488, 19487, 19486, 19485, 19484, 19483, 19482, 19481, 19480, 19479, 19478, 19477, 19476);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(10748, 82, 0, 0, 0, 52393),
(19496, 0, 0, 0, 0, 52393),
(19495, 0, 1, 0, 0, 52393),
(19494, 0, 0, 0, 0, 52393),
(19493, 0, 0, 0, 0, 52393),
(19492, 0, 1, 0, 0, 52393),
(19491, 0, 2, 0, 0, 52393),
(19490, 0, 1, 0, 0, 52393),
(19489, 0, 1, 0, 0, 52393),
(19488, 0, 1, 0, 0, 52393),
(19487, 0, 0, 0, 0, 52393),
(19486, 0, 3, 0, 0, 52393),
(19485, 0, 3, 0, 0, 52393),
(19484, 0, 1, 0, 0, 52393),
(19483, 0, 2, 0, 0, 52393),
(19482, 0, 1, 0, 0, 52393),
(19481, 0, 1, 0, 0, 52393),
(19480, 0, 1, 0, 0, 52393),
(19479, 0, 0, 0, 0, 52393),
(19478, 0, 1, 0, 0, 52393),
(19477, 0, 1, 0, 0, 52393),
(19476, 0, 0, 0, 0, 52393);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup` = 1 AND `SourceEntry` = 284807);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 284807, 0, 0, 31, 0, 3, 139645, 0, 0, 0, 0, '', 'Spell: Despawn - can only hit "Vision of Sailors Memory"');

 -- Creature 49748 smart ai
SET @ENTRY := 49748;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 19, 0, 100, 0, 46727, 0, 0, 0, 143, 4818, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 46727 - Player who accepted quest: Start conversation 4818');

-- Path for Jaina
SET @ENTRY := 120590;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8383.272, 329.5139, 147.0765, NULL, 0),
(@PATH, 1, -8383.877, 328.8299, 147.0882, NULL, 0),
(@PATH, 2, -8384.636, 325.9323, 147.1476, NULL, 0);

SET @ENTRY := 120590;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8384.636, 325.9323, 147.1476, NULL, 0),
(@PATH, 1, -8383.877, 328.8299, 147.0882, NULL, 0),
(@PATH, 2, -8383.272, 329.5139, 147.0765, NULL, 0);

DELETE FROM `creature_questender` WHERE (`id`=120756 AND `quest`=46727);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(120756, 46727, 52649); -- Battle for Azeroth: Tides of War ended by Anduin Wrynn
