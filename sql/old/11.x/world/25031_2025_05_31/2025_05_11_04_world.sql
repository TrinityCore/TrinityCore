SET @CGUID := 7003069;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1080.2257080078125, 1784.0660400390625, 118.4322967529296875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1038.5833740234375, 1803.28125, 120.0498428344726562, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 128761, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1044.1944580078125, 1846.939208984375, 120.080322265625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Companion (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 128761, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1129.2603759765625, 1786.810791015625, 120.15301513671875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Companion (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 128761, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1146.189208984375, 1724.4739990234375, 121.1036224365234375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Companion (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+5, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1112.9461669921875, 1826.3697509765625, 122.4075393676757812, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+6, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1164.5, 1752.93408203125, 121.7482147216796875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+7, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1184.98095703125, 1805.701416015625, 121.93804931640625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+8, 128761, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1180.8697509765625, 1693.515625, 120.8573837280273437, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Companion (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1235.98095703125, 1719.8992919921875, 121.9675445556640625, 4.700719833374023437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+10, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1239.640625, 1774.9461669921875, 122.3618392944335937, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1254.96533203125, 1766.23095703125, 122.700103759765625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+12, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1270.954833984375, 1790.248291015625, 124.8896026611328125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+13, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1319.5538330078125, 1794.6788330078125, 140.6121978759765625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+14, 129082, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1238.140625, 1857.21533203125, 137.3107147216796875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Thornspeaker (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+15, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1348.7239990234375, 1815.8004150390625, 147.616485595703125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+16, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1298.62158203125, 1852.7847900390625, 150.816680908203125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+17, 128742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1364.1632080078125, 1770.02783203125, 135.7238311767578125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Injured Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+1, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+2, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Companion
(@CGUID+3, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Companion
(@CGUID+4, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Companion
(@CGUID+5, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+6, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+7, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+8, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Companion
(@CGUID+9, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+10, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+11, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+12, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+13, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+14, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Thornspeaker
(@CGUID+15, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+16, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+17, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Injured Ranger
(@CGUID+18, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Injured Ranger

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (140048,128761,128742,129082) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=60568 WHERE (`Entry`=140048 AND `DifficultyID`=0); -- 140048 (Arthur Tradewind) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=128761 AND `DifficultyID`=0); -- 128761 (Injured Companion) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=128742 AND `DifficultyID`=0); -- 128742 (Injured Ranger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=60568 WHERE (`Entry`=129082 AND `DifficultyID`=0); -- 129082 (Injured Thornspeaker) - CanSwim - AllowInteractionWhileInCombat

-- Sparring
DELETE FROM `creature_template_sparring` WHERE `Entry` = 126355;
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(126355, 85);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (128742,129082);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(128742, 0, 0, 'Thank you!', 12, 0, 100, 4, 0, 0, 138772, 0, 'Injured Ranger to Player'),
(128742, 0, 1, 'Thank you, stranger. I thought I was done for.', 12, 0, 100, 4, 0, 0, 138769, 0, 'Injured Ranger to Player'),
(128742, 0, 2, 'I\'ve never seen spirits like these before. I\'m out of here!', 12, 0, 100, 4, 0, 0, 138771, 0, 'Injured Ranger to Player'),
(128742, 0, 3, 'Thank you. Once I find my pet I\'m leaving this cursed place!', 12, 0, 100, 4, 0, 0, 138773, 0, 'Injured Ranger to Player'),
(129082, 0, 0, 'We didn\'t expect such power! Be careful, Mainlander.', 12, 0, 100, 4, 0, 0, 157360, 0, 'Injured Thornspeaker to Player'),
(129082, 0, 1, 'Thank you for saving me.', 12, 0, 100, 4, 0, 0, 138770, 0, 'Injured Thornspeaker to Player'),
(129082, 0, 2, 'We did not expect the dead to walk!', 12, 0, 100, 4, 0, 0, 157361, 0, 'Injured Thornspeaker to Player');

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (129082,128742,128761);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(129082, 255316, 1, 0),
(128742, 255316, 1, 0),
(128761, 255316, 1, 0);

-- Injured Thornspeaker smart ai
SET @ENTRY := 129082;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 255316, 0, 0, 0, 0, 80, 12908200, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  255316 hit - Self: Start timed action list id #Injured Thornspeaker #0 (12908200) (update out of combat)', '');

-- Injured Ranger smart ai
SET @ENTRY := 128742;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 255316, 0, 0, 0, 0, 80, 12908200, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  255316 hit - Self: Start timed action list id #Injured Thornspeaker #0 (12908200) (update out of combat)', '');

-- Injured Companion smart ai
SET @ENTRY := 128761;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 255316, 0, 0, 0, 0, 80, 12876100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  255316 hit - Self: Start timed action list id #Injured Companion #0 (12876100) (update out of combat)', '');

-- Timed list 12908200 smart ai
SET @ENTRY := 12908200;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 128742, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Injured Ranger (128742)', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 30, 0, 0, 'After 2 seconds - Self: Move forward by 0, left by 30, up by 0 yards', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Despawn instantly', '');

-- Timed list 12876100 smart ai
SET @ENTRY := 12876100;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 128742, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Injured Ranger (128742)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 30, 0, 0, 'After 2 seconds - Self: Move forward by 0, left by 30, up by 0 yards', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Despawn instantly', '');

-- Spawntracking
DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId` = 291638;
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1400984,291638,60568),
(1400993,291638,60568),
(1537955,291638,60568),
(1537756,291638,60568),
(1400994,291638,60568),
(1400983,291638,60568),
(1400985,291638,60568),
(1537956,291638,60568),
(1537958,291638,60568),
(1537957,291638,60568),
(1537959,291638,60568),
(1537759,291638,60568),
(1400958,291638,60568),
(1400989,291638,60568),
(1400982,291638,60568),
(1537757,291638,60568),
(1400991,291638,60568),
(1537755,291638,60568);

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (1400984 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400993 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537955 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537756 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400994 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400983 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400985 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537956 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537958 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537957 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537959 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537759 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400958 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400989 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400982 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537757 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1400991 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1537755 /*Map: 1643 (Kul Tiras) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1400984, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400993, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537955, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537756, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400994, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400983, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400985, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537956, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537958, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537957, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537959, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537759, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400958, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400989, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400982, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537757, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1400991, 1643, 0, 0, 0, 60568), -- Map: 1643 (Kul Tiras) - Phase: 0
(1537755, 1643, 0, 0, 0, 60568); -- Map: 1643 (Kul Tiras) - Phase: 0

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=0 AND `SpawnId` IN (@CGUID+0,@CGUID+1,@CGUID+2,@CGUID+3,@CGUID+4,@CGUID+5,@CGUID+6,@CGUID+7,@CGUID+8,@CGUID+9,@CGUID+10,@CGUID+11,@CGUID+12,@CGUID+13,@CGUID+14,@CGUID+15,@CGUID+16,@CGUID+17));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1400984, 0, @CGUID+0, 291638), -- Injured Thornspeaker
(1400993, 0, @CGUID+1, 291638), -- Injured Ranger
(1537955, 0, @CGUID+2, 291638), -- Injured Companion
(1537756, 0, @CGUID+3, 291638), -- Injured Companion
(1400994, 0, @CGUID+4, 291638), -- Injured Companion
(1400983, 0, @CGUID+5, 291638), -- Injured Thornspeaker
(1400985, 0, @CGUID+6, 291638), -- Injured Thornspeaker
(1537956, 0, @CGUID+7, 291638), -- Injured Thornspeaker
(1537958, 0, @CGUID+8, 291638), -- Injured Companion
(1537957, 0, @CGUID+9, 291638), -- Injured Ranger
(1537959, 0, @CGUID+10, 291638), -- Injured Thornspeaker
(1537759, 0, @CGUID+11, 291638), -- Injured Ranger
(1400958, 0, @CGUID+12, 291638), -- Injured Ranger
(1400989, 0, @CGUID+13, 291638), -- Injured Thornspeaker
(1400982, 0, @CGUID+14, 291638), -- Injured Thornspeaker
(1537757, 0, @CGUID+15, 291638), -- Injured Ranger
(1400991, 0, @CGUID+16, 291638), -- Injured Ranger
(1537755, 0, @CGUID+17, 291638); -- Injured Ranger

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=0 AND `SpawnId` IN (@CGUID+0,@CGUID+1,@CGUID+2,@CGUID+3,@CGUID+4,@CGUID+5,@CGUID+6,@CGUID+7,@CGUID+8,@CGUID+9,@CGUID+10,@CGUID+11,@CGUID+12,@CGUID+13,@CGUID+14,@CGUID+15,@CGUID+16,@CGUID+17));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(0, @CGUID+0, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+0, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+0, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+1, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+1, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+1, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+3, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+3, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+3, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+6, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+6, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+6, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+9, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+9, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+9, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+11, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+11, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+11, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+12, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+12, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+12, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+13, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+13, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+13, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+14, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+14, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+14, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+15, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+15, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+15, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+16, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+16, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+16, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+17, 0, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+17, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+17, 2, 0, NULL, NULL, NULL, NULL);
