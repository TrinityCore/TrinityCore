-- Ragefire Chasm Quests and SAI for Scouts/Rangers and Misc
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (61644, 61528, 61780, 61800, 61669, 61463, 61601, 61408, 61705, 61666, 61795, 61790, 61788, 61680, 61672, 61413, 61412, 61678, 61630, 61560, 61659, 61658, 61823, 61825, 61822, 61821, 61657, 61716, 61404, 61724) AND `DifficultyID`=1);

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61644 AND `DifficultyID`=0); -- 61644 (Dark Shaman Researcher) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61528 AND `DifficultyID`=0); -- 61528 (Lava Guard Gordoth) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54717 WHERE (`Entry`=61780 AND `DifficultyID`=0); -- 61780 (Suspicious Rock) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805830912, `VerifiedBuild`=54717 WHERE (`Entry`=61800 AND `DifficultyID`=0); -- 61800 (Magnaw's Head) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61669 AND `DifficultyID`=0); -- 61669 (Oggleflint) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=805830912, `VerifiedBuild`=54717 WHERE (`Entry`=61463 AND `DifficultyID`=0); -- 61463 (Slagmaw) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=207, `StaticFlags1`=536870912, `VerifiedBuild`=54717 WHERE (`Entry`=61601 AND `DifficultyID`=0); -- 61601 (Lava) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61408 AND `DifficultyID`=0); -- 61408 (Adarogg) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61705 AND `DifficultyID`=0); -- 61705 (Corrupted Flamecaller) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61666 AND `DifficultyID`=0); -- 61666 (Corrupted Houndmaster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805830912, `VerifiedBuild`=54717 WHERE (`Entry`=61795 AND `DifficultyID`=0); -- 61795 (Dancing Flames) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54717 WHERE (`Entry`=61790 AND `DifficultyID`=0); -- 61790 (Inconspicuous Crate) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61788 AND `DifficultyID`=0); -- 61788 (SI:7 Ranger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61680 AND `DifficultyID`=0); -- 61788 (Kor'kron Scout) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61672 AND `DifficultyID`=0); -- 61672 (Dark Shaman Acolyte) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54717 WHERE (`Entry`=61413 AND `DifficultyID`=0); -- 61413 (Flame Visual) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61412 AND `DifficultyID`=0); -- 61412 (Dark Shaman Koranthal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61678 AND `DifficultyID`=0); -- 61678 (Corrupted Reaver) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=207, `StaticFlags1`=536871168, `VerifiedBuild`=54717 WHERE (`Entry`=61630 AND `DifficultyID`=0); -- 61630 (Ground Runes) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=207, `StaticFlags1`=536870912, `VerifiedBuild`=54717 WHERE (`Entry`=61560 AND `DifficultyID`=0); -- 61560 (Lava) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61659 AND `DifficultyID`=0); -- 61659 (Slain Trogg) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61658 AND `DifficultyID`=0); -- 61658 (Mature Flame Hound) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805830912, `StaticFlags3`=33554432, `VerifiedBuild`=54717 WHERE (`Entry`=61823 AND `DifficultyID`=0); -- 61823 (High Sorceress Aryna) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `VerifiedBuild`=54717 WHERE (`Entry`=61825 AND `DifficultyID`=0); -- 61825 (Stormwind Portal) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61822 AND `DifficultyID`=0); -- 61822 (SI:7 Field Commander Dirken) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61821 AND `DifficultyID`=0); -- 61821 (SI:7 Commando) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61657 AND `DifficultyID`=0); -- 61657 (Adolescent Flame Hound) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=805830912, `VerifiedBuild`=54717 WHERE (`Entry`=61716 AND `DifficultyID`=0); -- 61716 (Invoker Xorenth) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61404 AND `DifficultyID`=0); -- 61404 (Kor'kron Elite) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=207, `StaticFlags1`=268959744, `VerifiedBuild`=54717 WHERE (`Entry`=61724 AND `DifficultyID`=0); -- 61724 (Commander Bagran) - CanSwim

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (61680, 61788, 61658, 61666, 61678, 61672, 61705, 61780, 61790);
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry` IN (61560, 61601); -- Lava

UPDATE `creature` SET `StringId`='npc_adolescent_flame_hound_4' WHERE `guid`=4000020;
UPDATE `creature` SET `StringId`='npc_adolescent_flame_hound_3' WHERE `guid`=4000016;
UPDATE `creature` SET `StringId`='npc_adolescent_flame_hound_2' WHERE `guid`=4000012;
UPDATE `creature` SET `StringId`='npc_adolescent_flame_hound_1' WHERE `guid`=4000009;

UPDATE `creature` SET `StringId`='npc_rescued_cage_1' WHERE `guid` IN (4000108, 4000127);
UPDATE `creature` SET `StringId`='npc_rescued_cage_2' WHERE `guid` IN (4000109, 4000129);
UPDATE `creature` SET `StringId`='npc_rescued_cage_3' WHERE `guid` IN (4000112, 4000128);

UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry`=211885; -- Scout Cage

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (61788, 61680);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(61788, 0, 1, 'RUN!!', 12, 0, 20, 0, 0, 0, 61290, 0, 'SI:7 Ranger to Player'),
(61788, 0, 2, 'Thanks!', 12, 0, 20, 0, 0, 0, 61286, 0, 'SI:7 Ranger to Player'),
(61788, 0, 3, 'I didn\'t think anyone was coming for us.', 12, 0, 20, 0, 0, 0, 61287, 0, 'SI:7 Ranger to Player'),
(61788, 0, 4, 'I owe you an ale!', 12, 0, 20, 0, 0, 0, 61288, 0, 'SI:7 Ranger to Player'),
(61788, 0, 5, 'I thought I was going to die down here!', 12, 0, 20, 0, 0, 0, 61285, 0, 'SI:7 Ranger to Player'),
(61680, 0, 1, 'RUN!!', 12, 0, 20, 0, 0, 0, 61290, 0, 'Kor\'kron Scout to Player'),
(61680, 0, 2, 'Thanks!', 12, 0, 20, 0, 0, 0, 61286, 0, 'Kor\'kron Scout to Player'),
(61680, 0, 3, 'I didn\'t think anyone was coming for us.', 12, 0, 20, 0, 0, 0, 61287, 0, 'Kor\'kron Scout to Player'),
(61680, 0, 4, 'I owe you an ale!', 12, 0, 20, 0, 0, 0, 61288, 0, 'Kor\'kron Scout to Player'),
(61680, 0, 5, 'I thought I was going to die down here!', 12, 0, 20, 0, 0, 0, 61285, 0, 'Kor\'kron Scout to Player');

-- Missing cosmetic
DELETE FROM `creature_addon` WHERE `guid` IN (4000052, 4000039, 4000069);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(4000052, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, NULL),
(4000039, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, NULL),
(4000069, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, NULL);

-- Mature Flame Hound with the first quest npc has CREATURE_STATIC_FLAG_IGNORE_COMBAT
DELETE FROM `creature_static_flags_override` WHERE `SpawnId`=4000089 AND `DifficultyId`=0;
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(4000089, 0, 570425600, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Quest npcs hanging data
UPDATE `creature` SET `npcflag`=16777216 WHERE `guid` IN (4000042, 4000098, 4000122, 4000126);

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (4000042, 4000098, 4000122, 4000126) AND `DifficultyId`=0;
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(4000042, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4000098, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4000122, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4000126, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (61680, 61788);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 61680, 120327, 0, 0, 51, 1, 5, 0, 4000042, '', 0, 0, 0, '', 'Only npc with GUID 4000042 for spellclick 120327'),
(18, 61680, 120328, 0, 0, 51, 1, 5, 0, 4000098, '', 0, 0, 0, '', 'Only npc with GUID 4000098 for spellclick 120328'),
(18, 61788, 120327, 0, 0, 51, 1, 5, 0, 4000122, '', 0, 0, 0, '', 'Only npc with GUID 4000122 for spellclick 120327'),
(18, 61788, 120328, 0, 0, 51, 1, 5, 0, 4000126, '', 0, 0, 0, '', 'Only npc with GUID 4000126 for spellclick 120328');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (61680, 61788);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(61680, 120327, 3, 1),
(61680, 120328, 3, 1),
(61788, 120327, 3, 1),
(61788, 120328, 3, 1);

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry` = 7897;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7897, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = 7897;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7897, 2, 0, 0, 46, 0, 100, 0, 7897, 0, 0, 0, 0, 134, 119742, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Lava on Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` = 7897;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7897, 2, 0, 1, 0, 119742, 0, 0, 1, 0, 0, '', 'SAI only triggers when player has not aura');

DELETE FROM `areatrigger_scripts` WHERE `entry` = 7898;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7898, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = 7898;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7898, 2, 0, 0, 46, 0, 100, 0, 7898, 0, 0, 0, 0, 134, 119741, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Lava on Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` = 7898;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7898, 2, 0, 1, 0, 119741, 0, 0, 1, 0, 0, '', 'SAI only triggers when player has not aura');

DELETE FROM `areatrigger_scripts` WHERE `entry`=7966;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7966, 'at_rfc_cosmetic_intro');

-- Quest Related SAI
-- Spell 120327: Save Cliffhanger 1 SPELL_EFFECT_SEND_EVENT (Npcs #3)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=31986;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Ally
(22, 1, 31986, 3, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Send Event 31986 smart script 0 if you are Alliance Player'),
-- Horde
(22, 2, 31986, 3, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Send Event 31986 smart script 1 if you are Horde Player');

DELETE FROM `event_script_names` WHERE `Id`=31986;
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(31986, 'SmartEventTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=31986 AND `source_type`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31986, 3, 0, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 3, 0, 0, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent: 31986 - Set Data 0 3 to SI:7 Ranger'),
(31986, 3, 1, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 3, 0, 0, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent: 31986 - Set Data 0 3 to Kor\'kron Scout');

-- Spell 120328: Save Cliffhanger 2 SPELL_EFFECT_SEND_EVENT (Npcs #5)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=31989;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Ally
(22, 1, 31989, 3, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Send Event 31989 smart script 0 if you are Alliance Player'),
-- Horde
(22, 2, 31989, 3, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Send Event 31989 smart script 1 if you are Horde Player');

DELETE FROM `event_script_names` WHERE `Id`=31989;
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(31989, 'SmartEventTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=31989 AND `source_type`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31989, 3, 0, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 5, 0, 0, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent: 31989 - Set Data 0 5 to SI:7 Ranger'),
(31989, 3, 1, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 5, 0, 0, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent: 31989 - Set Data 0 5 to Kor\'kron Scout');

-- Scout Cage SAI
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`IN (211883, 211884, 211885); -- Scout Cage

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`IN (211883, 211884, 211885);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Ally
(22, 1, 211883, 1, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted gameobject does Smart Script if you are Alliance Player'),

-- Horde
(22, 3, 211883, 1, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted gameobject does Smart Script if you are Horde Player'),

-- Ally
(22, 1, 211884, 1, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted gameobject does Smart Script if you are Alliance Player'),

-- Horde
(22, 3, 211884, 1, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted gameobject does Smart Script if you are Horde Player'),

-- Ally
(22, 1, 211885, 1, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted gameobject does Smart Script if you are Alliance Player'),

-- Horde
(22, 3, 211885, 1, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted gameobject does Smart Script if you are Horde Player');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (211883, 211884, 211885) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(211883, 1, 0, 1, '', 70, 0, 100, 0, 2, 0, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast spell 120026 to player'),
(211883, 1, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 101163, 0, 19, 61788, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast Spell 101163 to SI:7 Ranger'),
(211883, 1, 2, 3, '', 70, 0, 100, 0, 2, 0, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast spell 120292 to player'),
(211883, 1, 3, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 101163, 0, 19, 61680, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast Spell 101163 to Kor\'kron Scout'),
(211884, 1, 0, 1, '', 70, 0, 100, 0, 2, 0, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast spell 120026 to player'),
(211884, 1, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 101163, 0, 19, 61788, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast Spell 101163 to SI:7 Ranger'),
(211884, 1, 2, 3, '', 70, 0, 100, 0, 2, 0, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast spell 120292 to player'),
(211884, 1, 3, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 101163, 0, 19, 61680, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast Spell 101163 to Kor\'kron Scout'),
(211885, 1, 0, 1, '', 70, 0, 100, 0, 2, 0, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed -  Cast spell 120026 to player'),
(211885, 1, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 101163, 0, 19, 61788, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast Spell 101163 to SI:7 Ranger'),
(211885, 1, 2, 3, '', 70, 0, 100, 0, 2, 0, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast spell 120292 to player'),
(211885, 1, 3, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 101163, 0, 19, 61680, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scout Cage - On State Changed - Cast Spell 101163 to Kor\'kron Scout');

-- Inconspicuous Crate
UPDATE `gossip_menu_option` SET `GossipOptionID`=37666, `VerifiedBuild`=54717 WHERE (`MenuID`=13815 AND `OptionID`=0);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=61790 AND `MenuID`=13815);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(61790, 13815, 54717); -- Inconspicuous Crate

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=61790;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Ally
(22, 1, 61790, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Alliance Player'),
-- Horde
(22, 2, 61790, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Horde Player');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61790 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6179000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61790, 0, 0, 2, '', 62, 0, 100, 0, 13815, 0, 0, 0, 0, '', 45, 0, 4, 0, 0, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inconspicuous Crate - On Gossip Select - Set Data 0 4 to SI:7 Ranger'),
(61790, 0, 1, 2, '', 62, 0, 100, 0, 13815, 0, 0, 0, 0, '', 45, 0, 4, 0, 0, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inconspicuous Crate - On Gossip Select - Set Data 0 4 to Kor\'kron Scout'),
(61790, 0, 2, 3, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (61790 * 100), 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inconspicuous Crate - On Gossip Select - Action List'),
(61790, 0, 3, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 83, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inconspicuous Crate - On Gossip Select - Remove Gossip flag'),
(61790, 0, 4, 0, '', 34, 0, 100, 0, 16, 1, 0, 0, 0, '', 41, 2000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inconspicuous Crate - On Reached Point 1 - Despawn'),

((61790 * 100), 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 103, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Set Root Off'),
((61790 * 100), 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 60, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Enable Gravity'),
((61790 * 100), 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 97, 14, 0, 57, 0, 1, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -87.7343, 57.2282, -18.1655, 0, 'Action list - Self: Jump To Pos');

-- Suspicious Rock
UPDATE `gossip_menu_option` SET `GossipOptionID`=37665, `VerifiedBuild`=54717 WHERE (`MenuID`=13814 AND `OptionID`=0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=61780;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Ally
(22, 5, 61780, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Alliance Player'),
-- Horde
(22, 6, 61780, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Horde Player');

DELETE FROM `creature_template_addon` WHERE `entry` = 61780;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(61780, 0, 0, 0, 0, 0, 1, 0, 0, 1443, 0, 0, 0, ''); -- 61780 (Suspicious Rock)

DELETE FROM `smart_scripts` WHERE `entryorguid`=61780 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6178000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61780, 0, 0, 1, '', 62, 0, 100, 0, 13814, 0, 0, 0, 0, '', 80, (61780 * 100), 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Suspicious Rock - On Gossip Select - Action List'),
(61780, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 83, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Suspicious Rock - On Gossip Select - Remove Gossip flag'),
(61780, 0, 2, 3, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 1443, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Suspicious Rock - On Reached Point 1 - SetAIAnimKitId to 1443'),
(61780, 0, 3, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 41, 2000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Suspicious Rock - On Reached Point 1 - Despawn'),
(61780, 0, 4, 0, '', 62, 0, 100, 0, 13814, 0, 0, 0, 0, '', 45, 0, 2, 0, 0, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'Suspicious Rock - On Gossip Select - Set Data 0 2 to SI:7 Ranger'),
(61780, 0, 5, 0, '', 62, 0, 100, 0, 13814, 0, 0, 0, 0, '', 45, 0, 2, 0, 0, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'Suspicious Rock - On Gossip Select - Set Data 0 2 to Kor\'kron Scout'),

((61780 * 100), 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61780 * 100), 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 60, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Enable Gravity'),
((61780 * 100), 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 103, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Set Root Off'),
((61780 * 100), 9, 3, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 97, 14, 0, 131, 0, 1, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -308.103, -15.2036, -56.5575, 0, 'Action list - Self: Jump To Pos');

-- SI:7 Ranger / Kor'kron Scout SAI
-- #1 With the Mature Flame Hound before first boss
-- #2 Inside Suspicious Rock
-- #3 Hanging before second boss
-- #4 Inside Inconspicuous Crate
-- #5 Hanging next to third boss
-- #6, #7, #8 Caged next to last boss

DELETE FROM `smart_scripts` WHERE `entryorguid`=61788 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6178800, 6178801, 6178802, 6178803, 6178804) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- #1
(61788, 0, 0, 0, '', 38, 0, 100, 0, 0, 1, 0, 0, 0, '', 80, (61788 * 100), 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On Data Set - Action List'),
(61788, 0, 1, 0, '', 40, 0, 100, 0, 0, 6178800, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),
((61788 * 100), 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61788 * 100), 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 1439, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - PlayOneShotAnimKitId 1439'),
((61788 * 100), 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61788 * 100), 9, 3, 0, '', 0, 0, 100, 0, 3400, 3400, 0, 0, 0, '', 53, 1, 6178800, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178800'),

-- #2
(61788, 0, 2, 0, '', 38, 0, 100, 0, 0, 2, 0, 0, 0, '', 80, (61788 * 100) + 1, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On Data Set - Action List'),
(61788, 0, 3, 0, '', 40, 0, 100, 0, 4, 6178801, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),
((61788 * 100) + 1, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 120296, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Cast spell 120296'),
((61788 * 100) + 1, 9, 1, 0, '', 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 8, 0, 0, 1, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -306.174, -23.1592, -59.0882, 0, 'Action list - Self: Jump To Pos'),
((61788 * 100) + 1, 9, 2, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120026'),
((61788 * 100) + 1, 9, 3, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61788 * 100) + 1, 9, 4, 0, '', 0, 0, 100, 0, 2200, 2200, 0, 0, 0, '', 53, 1, 6178801, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178801'),

-- #3
(61788, 0, 4, 0, '', 38, 0, 100, 0, 0, 3, 0, 0, 0, '', 80, (61788 * 100) + 2, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On Data Set - Action List'),
(61788, 0, 5, 0, '', 40, 0, 100, 0, 0, 6178802, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),
((61788 * 100) + 2, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120026'),
((61788 * 100) + 2, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61788 * 100) + 2, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 0, 3, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAnimTier to 0'),
((61788 * 100) + 2, 9, 3, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 60, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Enable Gravity'),
((61788 * 100) + 2, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 97, 8, 0, 35, 0, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -176.771, 12.8039, -31.5192, 0, 'Action list - Self: Jump To Pos'),
((61788 * 100) + 2, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 146, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Set Uninteractible'),
((61788 * 100) + 2, 9, 6, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61788 * 100) + 2, 9, 7, 0, '', 0, 0, 100, 0, 3500, 3500, 0, 0, 0, '', 53, 1, 6178802, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178802'),

-- #4
(61788, 0, 6, 0, '', 38, 0, 100, 0, 0, 4, 0, 0, 0, '', 80, (61788 * 100) + 3, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On Data Set - Action List'),
(61788, 0, 7, 0, '', 40, 0, 100, 0, 2, 6178803, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),
((61788 * 100) + 3, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 120296, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Cast spell 120296'),
((61788 * 100) + 3, 9, 1, 0, '', 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 8, 0, 0, 1, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -92.523, 65.7691, -18.6579, 0, 'Action list - Self: Jump To Pos'),
((61788 * 100) + 3, 9, 2, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120026'),
((61788 * 100) + 3, 9, 3, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61788 * 100) + 3, 9, 4, 0, '', 0, 0, 100, 0, 2200, 2200, 0, 0, 0, '', 53, 1, 6178803, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178803'),

-- #5
(61788, 0, 8, 0, '', 38, 0, 100, 0, 0, 5, 0, 0, 0, '', 80, (61788 * 100) + 4, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On Data Set - Action List'),
(61788, 0, 9, 0, '', 40, 0, 100, 0, 2, 6178804, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),
((61788 * 100) + 4, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 120026, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120026'),
((61788 * 100) + 4, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61788 * 100) + 4, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 0, 3, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAnimTier to 0'),
((61788 * 100) + 4, 9, 3, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 60, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Enable Gravity'),
((61788 * 100) + 4, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 97, 8, 0, 31, 0, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -295.687, 143.649, -25.0341, 0, 'Action list - Self: Jump To Pos'),
((61788 * 100) + 4, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 146, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Set Uninteractible'),
((61788 * 100) + 4, 9, 6, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61788 * 100) + 4, 9, 7, 0, '', 0, 0, 100, 0, 3500, 3500, 0, 0, 0, '', 53, 1, 6178804, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178802'),

-- #6
(61788, 0, 10, 0, '', 40, 0, 100, 0, 0, 6178805, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Talk'),
(61788, 0, 11, 0, '', 40, 0, 100, 0, 1, 6178805, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),

-- #7
(61788, 0, 12, 0, '', 40, 0, 100, 0, 0, 6178806, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Talk'),
(61788, 0, 13, 0, '', 40, 0, 100, 0, 1, 6178806, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn'),

-- #8
(61788, 0, 14, 0, '', 40, 0, 100, 0, 0, 6178807, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Talk'),
(61788, 0, 15, 0, '', 40, 0, 100, 0, 1, 6178807, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Ranger - On WP Reached - Despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61680 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6168000, 6168001, 6168002, 6168003, 6168004) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- #1
(61680, 0, 0, 0, '', 38, 0, 100, 0, 0, 1, 0, 0, 0, '', 80, (61680 * 100), 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scoutr - On Data Set - Action List'),
(61680, 0, 1, 0, '', 40, 0, 100, 0, 0, 6178800, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),
((61680 * 100), 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61680 * 100), 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 1439, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - PlayOneShotAnimKitId 1439'),
((61680 * 100), 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61680 * 100), 9, 3, 0, '', 0, 0, 100, 0, 3400, 3400, 0, 0, 0, '', 53, 1, 6178800, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178800'),

-- #2
(61680, 0, 2, 0, '', 38, 0, 100, 0, 0, 2, 0, 0, 0, '', 80, (61680 * 100) + 1, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scoutr - On Data Set - Action List'),
(61680, 0, 3, 0, '', 40, 0, 100, 0, 4, 6178801, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),
((61680 * 100) + 1, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 120296, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Cast spell 120296'),
((61680 * 100) + 1, 9, 1, 0, '', 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 8, 0, 0, 1, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -306.174, -23.1592, -59.0882, 0, 'Action list - Self: Jump To Pos'),
((61680 * 100) + 1, 9, 2, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120292'),
((61680 * 100) + 1, 9, 3, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61680 * 100) + 1, 9, 4, 0, '', 0, 0, 100, 0, 2200, 2200, 0, 0, 0, '', 53, 1, 6178801, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178801'),

-- #3
(61680, 0, 4, 0, '', 38, 0, 100, 0, 0, 3, 0, 0, 0, '', 80, (61680 * 100) + 2, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On Data Set - Action List'),
(61680, 0, 5, 0, '', 40, 0, 100, 0, 0, 6178802, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),
((61680 * 100) + 2, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120292'),
((61680 * 100) + 2, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61680 * 100) + 2, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 0, 3, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAnimTier to 0'),
((61680 * 100) + 2, 9, 3, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 60, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Enable Gravity'),
((61680 * 100) + 2, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 97, 8, 0, 35, 0, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -176.771, 12.8039, -31.5192, 0, 'Action list - Self: Jump To Pos'),
((61680 * 100) + 2, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 146, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Self: Set Uninteractible'),
((61680 * 100) + 2, 9, 6, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61680 * 100) + 2, 9, 7, 0, '', 0, 0, 100, 0, 3500, 3500, 0, 0, 0, '', 53, 1, 6178802, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178802'),

-- #4
(61680, 0, 6, 0, '', 38, 0, 100, 0, 0, 4, 0, 0, 0, '', 80, (61680 * 100) + 3, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On Data Set - Action List'),
(61680, 0, 7, 0, '', 40, 0, 100, 0, 2, 6178803, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),
((61680 * 100) + 3, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 120296, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Cast spell 120296'),
((61680 * 100) + 3, 9, 1, 0, '', 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 8, 0, 0, 1, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -92.523, 65.7691, -18.6579, 0, 'Action list - Self: Jump To Pos'),
((61680 * 100) + 3, 9, 2, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120292'),
((61680 * 100) + 3, 9, 3, 0, '', 0, 0, 100, 0, 1100, 1100, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61680 * 100) + 3, 9, 4, 0, '', 0, 0, 100, 0, 2200, 2200, 0, 0, 0, '', 53, 1, 6178803, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178803'),

-- #5
(61680, 0, 8, 0, '', 38, 0, 100, 0, 0, 5, 0, 0, 0, '', 80, (61680 * 100) + 4, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On Data Set - Action List'),
(61680, 0, 9, 0, '', 40, 0, 100, 0, 2, 6178804, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),
((61680 * 100) + 4, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 120292, 0, 21, 20, 0, 0, 0, NULL, 21, 20, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Cast spell 120292'),
((61680 * 100) + 4, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAIAnimKitId to 0'),
((61680 * 100) + 4, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 0, 3, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - SetAnimTier to 0'),
((61680 * 100) + 4, 9, 3, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 60, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Enable Gravity'),
((61680 * 100) + 4, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 97, 8, 0, 31, 0, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, -295.687, 143.649, -25.0341, 0, 'Action list - Self: Jump To Pos'),
((61680 * 100) + 4, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 146, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Self: Set Uninteractible'),
((61680 * 100) + 4, 9, 6, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Talk'),
((61680 * 100) + 4, 9, 7, 0, '', 0, 0, 100, 0, 3500, 3500, 0, 0, 0, '', 53, 1, 6178804, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Action list - Start WP 6178804'),

-- #6
(61680, 0, 10, 0, '', 40, 0, 100, 0, 0, 6178805, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Talk'),
(61680, 0, 11, 0, '', 40, 0, 100, 0, 1, 6178805, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),

-- #7
(61680, 0, 12, 0, '', 40, 0, 100, 0, 0, 6178806, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Talk'),
(61680, 0, 13, 0, '', 40, 0, 100, 0, 1, 6178806, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn'),

-- #8
(61680, 0, 14, 0, '', 40, 0, 100, 0, 0, 6178807, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Talk'),
(61680, 0, 15, 0, '', 40, 0, 100, 0, 1, 6178807, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Kor\'kron Scout - On WP Reached - Despawn');

-- Waypoints
-- #1
SET @ENTRY := 61788;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -218.402, -36.7901, -54.42816, NULL, 0);

-- #2
SET @ENTRY := 61788;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -297.9861, -41.88261, -60.91673, NULL, 0),
(@PATH, 1, -286.8949, -48.55449, -60.93217, NULL, 0),
(@PATH, 2, -276.6081, -47.31757, -60.93217, NULL, 0),
(@PATH, 3, -253.9539, -39.25582, -60.49646, NULL, 0),
(@PATH, 4, -225.0045, -37.12025, -55.7888, NULL, 0);

-- #3
SET @ENTRY := 61788;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued -  Path 3');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -234.865, 10.5354, -44.45418, NULL, 0);

-- #4
SET @ENTRY := 61788;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 4');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -108.3838, 23.41842, -18.44852, NULL, 0),
(@PATH, 1, -129.3571, 9.659675, -20.64646, NULL, 0),
(@PATH, 2, -143.5467, 8.586313, -21.6209, NULL, 0);

-- #5
SET @ENTRY := 61788;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 5');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -304.6536, 122.7313, -24.959, NULL, 0),
(@PATH, 1, -293.6286, 106.3134, -26.63246, NULL, 0),
(@PATH, 2, -280.1276, 93.78496, -25.02191, NULL, 0);

SET @ENTRY := 61788;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 6');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -371.5243, 183.7873, -22.14008, NULL, 178),
(@PATH, 1, -325.283, 223.744, -20.79574, NULL, 0);

SET @ENTRY := 61788;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 7');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -372.6608, 187.3729, -22.0765, NULL, 176),
(@PATH, 1, -325.283, 223.744, -20.79574, NULL, 0);

SET @ENTRY := 61788;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'SI:7 Ranger | Kor\'kron Scout rescued - Path 8');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -374.134, 190.649, -22.02528, NULL, 185),
(@PATH, 1, -325.283, 223.744, -20.79574, NULL, 0);

-- Instance Creatures SAI
-- Mature Flame Hound
UPDATE `creature` SET `StringId`='mature_flame_hound' WHERE `guid` = 4000025;
UPDATE `creature` SET `StringId`='mature_flame_hound_rescued_1' WHERE `guid` = 4000089;

 -- Only one Hound (cosmetic)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=61658;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 61658, 0, 0, 58, 1, 0, 0, 0, 'mature_flame_hound', 0, 0, 0, '', 'Scripted creature has StringId \'mature_flame_hound\'');

-- The Hound fighting with the rescued npc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=61658;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Ally
(22, 4, 61658, 0, 0, 58, 1, 0, 0, 0, 'mature_flame_hound_rescued_1', 0, 0, 0, '', 'Scripted creature has StringId \'mature_flame_hound_rescued_1\''),
(22, 4, 61658, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Alliance Player'),
-- Horde
(22, 6, 61658, 0, 0, 58, 1, 0, 0, 0, 'mature_flame_hound_rescued_1', 0, 0, 0, '', 'Scripted creature has StringId \'mature_flame_hound_rescued_1\''),
(22, 6, 61658, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Horde Player');

DELETE FROM `smart_scripts` WHERE `entryorguid`=61658 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Cosmetic / IC
(61658, 0, 0, 0, '', 1, 0, 100, 0, 2000, 8000, 2000, 8000, 0, '', 11, 120064, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound (OOC) - Self: Cast spell 120064 on Self'),
(61658, 0, 1, 0, '', 0, 0, 100, 0, 37000, 37000, 37000, 37000, 0, '', 11, 120076, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound (IC) - Cast spell 120076 on Victim'),
(61658, 0, 2, 0, '', 0, 0, 100, 0, 7300, 7300, 12100, 12100, 0, '', 11, 119999, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound (IC) - Cast spell 119999 on Victim'),

-- only the one with the quest npc
-- Alliance version
(61658, 0, 3, 4, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 1, 0, 0, 0, 0, 0, NULL, 19, 61788, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound - On Death - Set Data 0 1 to SI:7 Ranger'),
(61658, 0, 4, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 120026, 0, 0, 0, 0, 0, 0, NULL, 16, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound - On Death - Cast spell 120026 on Invoker Party'),

-- Horde version
(61658, 0, 5, 6, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 1, 0, 0, 0, 0, 0, NULL, 19, 61680, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound (IC) - Set Data 0 1 to Kor\'kron Scout'),
(61658, 0, 6, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 120292, 0, 0, 0, 0, 0, 0, NULL, 16, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Mature Flame Hound - On Death - Cast spell 120292 on Invoker Party');

-- Adolescent Flame Hound
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=61657;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 61657, 0, 0, 58, 1, 0, 0, 0, 'adolescent_flame_hound', 0, 0, 0, '', 'Scripted creature has StringId \'adolescent_flame_hound\''),
(22, 2, 61657, 0, 0, 58, 1, 0, 0, 0, 'adolescent_flame_hound', 0, 0, 0, '', 'Scripted creature has StringId \'adolescent_flame_hound\'');

UPDATE `creature` SET `StringId`='adolescent_flame_hound' WHERE `guid` IN (4000001, 4000003, 4000007, 4000033, 4000026);

DELETE FROM `smart_scripts` WHERE `entryorguid`=61657 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61657, 0, 0, 0, '', 1, 0, 100, 0, 2000, 8000, 2000, 8000, 0, '', 11, 120064, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Adolescent Flame Hound (OOC) - Self: Cast spell 120064 on Self'),
(61657, 0, 1, 0, '', 0, 0, 100, 0, 38200, 46700, 38200, 46700, 0, '', 11, 120069, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Adolescent Flame Hound (IC) - Cast spell 120069 on Victim');

-- Corrupted Houndmaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=61666 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61666, 0, 0, 0, '', 0, 0, 100, 0, 39400, 39400, 39400, 39400, 0, '', 11, 120096, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Corrupted Houndmaster (IC) - Cast spell 120096 on Victim');

-- Corrupted Reaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=61678 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61678, 0, 0, 0, '', 0, 0, 100, 0, 39700, 39700, 15700, 15700, 0, '', 11, 120166, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Corrupted Reaver (IC) - Cast spell 120166 on Victim');

-- Dark Shaman Acolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=61672 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61672, 0, 0, 0, '', 0, 0, 100, 0, 92200, 92200, 23000, 23000, 0, '', 11, 119902, 0, 0, 0, 0, 0, 0, NULL, 26, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Dark Shaman Acolyte (IC) - Cast spell 119902 on Closest Ally'),
(61672, 0, 1, 0, '', 0, 0, 100, 0, 83800, 83800, 18100, 18100, 0, '', 11, 119903, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Dark Shaman Acolyte (IC) - Cast spell 119903 on Victim');

-- Corrupted Flamecaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=61705 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61705, 0, 0, 0, '', 0, 0, 100, 0, 37300, 37300, 3600, 3600, 0, '', 11, 120112, 0, 0, 0, 0, 0, 0, NULL, 2, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Corrupted Flamecaller (IC) - Cast spell 120112 on Victim');

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id`=101163;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(101163, 'spell_ragefire_chasm_general_trigger_221_to_self');

DELETE FROM `serverside_spell` WHERE `Id` IN (120026, 120292) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(120026, 0, 0, 0, 0, 0x29800180, 0x420, 0x10484005, 0x10130200, 0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, -1, 0, 0, 0, 'Ranger Rescued Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(120292, 0, 0, 0, 0, 0x29800180, 0x420, 0x10484005, 0x10130200, 0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, -1, 0, 0, 0, 'Scout Rescued Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (120026, 120292) AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(120026, 0, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61788, 0, 0, 0, 0, 0, 0, 0, 25, 0),
(120292, 0, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61680, 0, 0, 0, 0, 0, 0, 0, 25, 0);

-- Quest
DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='esES' AND `ID` IN (30998,30996,30995));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(30998, 'esES', 'Buen trabajo, $n. Ahora podremos investigar qué están intentando ahí abajo.', 54358),
(30996, 'esES', 'Parece que los experimentos de los chamanes oscuros han enloquecido a Gordoth.$b$bEsperemos no volver a verlo, $n.', 54358),
(30995, 'esES', '¿Eso es todo lo que ha sobrevivido?$b$bLa Horda lo pagará con sangre.', 54358);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='esES' AND `ID` IN (30998,30996,30995));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(30998, 'esES', '¿Has recogido las insignias?', 54358),
(30996, 'esES', '¿Sí?', 54358),
(30995, 'esES', '¿Has encontrado a los forestales?', 54358);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='esES' AND `ID` IN (30984,30969,30983));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(30984, 'esES', '¿Has encontrado a los exploradores?', 54205),
(30969, 'esES', '¿Has recogido las insignias?', 54205),
(30983, 'esES', '¿Sí?', 54205);

DELETE FROM `quest_request_items` WHERE `ID` IN (30984 /*No Orc Left Behind*/, 30983 /*The Dark Shaman*/, 30969 /*A New Enemy*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `VerifiedBuild`) VALUES
(30984, 0, 0, 0, 0, 54205), -- No Orc Left Behind
(30983, 0, 0, 0, 0, 54205), -- The Dark Shaman
(30969, 0, 0, 0, 0, 54205); -- A New Enemy

UPDATE `quest_offer_reward` SET `VerifiedBuild`=54358 WHERE `ID` IN (30998, 30996, 30995);
UPDATE `quest_details` SET `VerifiedBuild`=54358 WHERE `ID` IN (30995, 30998, 30996);
UPDATE `quest_details` SET `VerifiedBuild`=54205 WHERE `ID` IN (30984, 30983, 30969);

DELETE FROM `quest_request_items` WHERE `ID` IN (30996 /*The Dark Shaman*/, 30995 /*No Man Left Behind*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `VerifiedBuild`) VALUES
(30996, 0, 0, 0, 0, 54358), -- The Dark Shaman
(30995, 0, 0, 0, 0, 54358); -- No Man Left Behind

UPDATE `creature_queststarter` SET `VerifiedBuild`=54205 WHERE (`id`=61724 AND `quest`=30984) OR (`id`=61716 AND `quest` IN (30983,30969));
UPDATE `creature_questender` SET `VerifiedBuild`=54205 WHERE (`id`=61724 AND `quest`=30984) OR (`id`=61716 AND `quest` IN (30969,30983));
UPDATE `quest_request_items` SET `VerifiedBuild`=54358 WHERE `ID`=30998;
UPDATE `creature_queststarter` SET `VerifiedBuild`=54358 WHERE (`id`=61822 AND `quest`=30995) OR (`id`=61823 AND `quest` IN (30998,30996));
UPDATE `creature_questender` SET `VerifiedBuild`=54358 WHERE (`id`=61823 AND `quest` IN (30998,30996)) OR (`id`=61822 AND `quest`=30995);

UPDATE `quest_template_locale` SET `LogTitle`='Ningún hombre se queda atrás', `LogDescription`='Rescata a 5 SI:7 exploradores en Sima Ígnea.', `QuestDescription`='He enviado una patrulla de reconocimiento hace más de una hora y no ha regresado nadie. Y ahora estos malditos canes no dejan de salir de la sima.$b$bNo sé qué está pasando ahí abajo pero yo no me pienso mover de aquí hasta recuperar a mis hombres.$b$b$n, quiero que vayas allí y los encuentres, preferiblemente con vida.', `VerifiedBuild`=54358 WHERE (`ID`=30995 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogDescription`='Recoge 5 insignias corruptas de cualquier cultor de Sima Ígnea.', `QuestDescription`='La Horda está utilizando magia negra ahí abajo para controlar bestias y corromper a sus hermanos, $n.$b$bMi intención es detenerlos, pero necesito saber a qué nos enfrentamos. Y ahí entras tú.$b$bÁbrete paso por las cuevas y recoge las insignias que llevan los cultores. Gracias a ellas podré estudiar el tipo de magia que utilizan.', `VerifiedBuild`=54358 WHERE (`ID`=30998 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='El Chamán oscuro', `LogDescription`='Derrota al chamán oscuro Koranthal y al guardia de lava Gordoth.', `QuestDescription`='Estos chamanes oscuros han estado ahí durante meses, criando bestias y realizando rituales oscuros.$b$bNo sé qué pretenden con todo esto, pero está claro que nos son amigos de la Alianza. Y te necesito para detenerlos, $n. $b$bÁbrete paso por la sima y acaba con el chamán oscuro Koranthal y el guardia de lava Gordoth.', `VerifiedBuild`=54358 WHERE (`ID`=30996 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='Ningún orco se queda atrás', `LogDescription`='Rescata 5 exploradores Kor\'kron en Sima Ígnea.', `QuestDescription`='Se suponía que esto era un barrido rutinario, $n. El plan era acabar con unos troggs, asegurarse de que la ciudad estaba a salvo y llegar a taberna a mediodía.$b$bEn vez de eso, me encuentro con un grupo de exploradores desaparecido, canes de llamas saliendo de la sima y a Xorenth balbuceando acerca del \"siguiente Martillo Crepuscular.\"$b$b<El comandante Bagran escupe>$b$bVe allí y rescata a mis exploradores para que podamos investigar qué está pasando.', `VerifiedBuild`=54205 WHERE (`ID`=30984 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='El Chamán oscuro', `LogDescription`='Derrota al chamán oscuro Koranthal y al guardia de lava Gordoth.', `QuestDescription`='Estos chamanes oscuros han estado ahí durante meses, criando bestias y realizando rituales oscuros.$b$bNo sé qué pretenden con todo esto, pero está claro que nos son amigos de la Horda. Y ahí es cuando entras tú, $n. $b$bÁbrete paso por la sima y acaba con el chamán oscuro Koranthal y el guardia de lava Gordoth.', `VerifiedBuild`=54205 WHERE (`ID`=30983 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogDescription`='Recoge 5 insignias corruptas de cualquier cultor de Sima Ígnea.', `QuestDescription`='El poder de estos chamanes oscuros ha atraído a muchos aliados, $n. Antiguos miembros de la Horda ahora trabajan en un propósito oscuro.$b$bDebemos hacer que sirva de ejemplo antes de que se conviertan en otro martillo crepuscular.$b$bAcaba con todos los cultores que te encuentres y tráeme sus insignias.', `VerifiedBuild`=54205 WHERE (`ID`=30969 AND `locale`='esES');

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (30982, 30997);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 30982, 0, '', '', 'Deprecated quest: Animal Control (Horde)'),
(1, 30997, 0, '', '', 'Deprecated quest: Animal Control (Alliance)');
