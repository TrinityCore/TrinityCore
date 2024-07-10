-- Creature
UPDATE `creature_template_difficulty` SET `ContentTuningID`=80, `StaticFlags1`=268435456, `VerifiedBuild`=53877 WHERE (`Entry`=59652 AND `DifficultyID`=0); -- Aysa Cloudsinger
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=59649 AND `DifficultyID`=0); -- Tushui Monk
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=61801 AND `DifficultyID`=0); -- Amberleaf Troublemaker
UPDATE `creature_template_difficulty` SET `ContentTuningID`=80, `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=54856 AND `DifficultyID`=0); -- Master Li Fei
UPDATE `creature_template_difficulty` SET `ContentTuningID`=80, `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=59637 AND `DifficultyID`=0); -- Amberleaf Troublemaker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=59642 AND `DifficultyID`=0); -- Aysa Cloudsinger

UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `ScriptName`='npc_aysa_cloudsinger_summon' WHERE `entry`=59652; -- Aysa Cloudsinger
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `ScriptName`='npc_master_li_fei_summon' WHERE `entry`=54856; -- Master Li Fei
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=59637; -- Amberleaf Troublemaker
UPDATE `creature_template` SET `ScriptName`='npc_aysa_cloudsinger_cave_of_meditation', `StringId`='npc_aysa_quest_29414' WHERE `entry`=59642;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 61801;

UPDATE `creature` SET `StringId`='npc_aysa_after_quest_29414' WHERE `guid`=450379;

DELETE FROM `creature_addon` WHERE `guid` = 450379;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450379, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, '85096'); -- Aysa Cloudsinger - 85096 - Generic Quest Invisibility 7

DELETE FROM `creature_template_addon` WHERE `entry` = 54856;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(54856, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '22650'); -- 54856 (Master Li Fei) - Ghost Visual

DELETE FROM `creature` WHERE `guid` IN (450358, 450361); -- These npcs were wrong spawned
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(450358, 61801, 860, 5736, 5848, '0', 838, 0, 0, 0, 1187.0625, 3439.999267578125, 102.6911392211914062, 3.016042709350585937, 20, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53913), -- Amberleaf Troublemaker (Area: Cave of Meditation - Difficulty: 0)
(450361, 61801, 860, 5736, 5848, '0', 838, 0, 0, 0, 1185.7725830078125, 3448.739501953125, 102.5142288208007812, 3.500391721725463867, 20, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53913); -- Amberleaf Troublemaker (Area: Cave of Meditation - Difficulty: 0)

DELETE FROM `creature_text` WHERE `CreatureID` IN (54567, 59642, 59652, 54856);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54567, 0, 0, 'A challenge in compassion and humility. By helping Merchant Lorvo, it would seem you\'ve passed, $c. Master Shang would be pleased.', 12, 0, 100, 2, 0, 27404, 60599, 0, 'Aysa Cloudsinger to Player'),
(54567, 1, 0, 'And so our path lays before us. Speak to Master Shang Xi, he will tell you what comes next.', 12, 0, 100, 0, 0, 27399, 60046, 0, 'Aysa Cloudsinger to Player'),
(59642, 0, 0, 'Keep those creatures at bay while I meditate. We\'ll soon have the answers we seek.', 12, 0, 100, 0, 0, 27398, 59161, 0, 'Aysa Cloudsinger to Player'),
(59652, 0, 0, 'Meet me up in the cave if you would, friend.', 12, 0, 100, 396, 0, 27397, 59147, 0, 'Aysa Cloudsinger to Player'),
(54856, 0, 0, 'Master Li Fei\'s voice echoes, \"The way of the Tushui... enlightenment through patience and meditation... the principled life.\"', 16, 0, 100, 6, 0, 0, 53129, 0, 'Master Li Fei to Player'),
(54856, 1, 0, 'Master Li Fei\'s voice echoes, \"It is good to see you again, Aysa. You\'ve come with respect, and so I shall give you the answers you seek.\"', 16, 0, 100, 1, 0, 0, 53845, 0, 'Master Li Fei to Player'),
(54856, 2, 0, 'Master Li Fei\'s voice echoes, \"Huo, the spirit of fire, is known for his hunger. He wants for tinder to eat. He needs the caress of the wind to rouse him.\"', 16, 0, 100, 1, 0, 0, 53841, 0, 'Master Li Fei to Player'),
(54856, 3, 0, 'Master Li Fei\'s voice echoes, \"If you find these things and bring them to his cave, on the far side of Wu-Song Village, you will face a challenge within.\"', 16, 0, 100, 1, 0, 0, 53842, 0, 'Master Li Fei to Player'),
(54856, 4, 0, 'Master Li Fei\'s voice echoes, \"Overcome that challenge, and you shall be graced by Huo\'s presence. Rekindle his flame, and if your spirit is pure, he shall follow you.\"', 16, 0, 100, 1, 0, 0, 53843, 0, 'Master Li Fei to Player'),
(54856, 5, 0, 'Master Li Fei\'s voice echoes, \"Go, children. We shall meet again very soon.\"', 16, 0, 100, 2, 0, 0, 53844, 0, 'Master Li Fei to Player'),
(54856, 6, 0, 'Master Li Fei fades away.', 16, 0, 100, 0, 0, 0, 53130, 0, 'Master Li Fei to Player');

-- Gameobject
UPDATE `gameobject` SET `phaseUseFlags`=1 WHERE `guid` IN (300018, 300098);

-- Smart Scripts
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -450358;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)  VALUES 
(-450358, 0, 0, 0, '', 1, 0, 100, 0, 5000, 10000, 0, 0, 0, '', 69, 0, 0, 0, 0, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, 1143.3512, 3437.6262, 104.967064, 0, 'Amberleaf Troublemaker - OOC - Move To Position');

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -450361;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-450361, 0, 0, 0, '', 1, 0, 100, 0, 5000, 10000, 0, 0, 0, '', 69, 0, 0, 0, 0, 0, 0, 0, NULL, 8, 0, 0, 0, 0, NULL, 1145.1484, 3432.8604, 105.24505, 0, 'Amberleaf Troublemaker - OOC - Move To Position');

-- Areatrigger
DELETE FROM `smart_scripts` WHERE `entryorguid`=7748 AND `source_type`=2 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7748, 2, 1, 0, 46, 0, 100, 0, 7748, 0, 0, 0, 0, '', 86, 116219, 2, 10, 450351, 54567, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Area Trigger Dummy Timer Aura A');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 54567 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(54567, 0, 0, 0, 31, 0, 100, 0, 116219, 0, 1000, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Aysa Cloudsinger - On Spellhit Target - Talk'),
(54567, 0, 1, 0, 19, 0, 100, 0, 29414, 0, 0, 0, 0, 85, 114728, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Aysa Cloudsinger - On Quest Accepted - Invoker cast \'Summon Aysa\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=7748;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7748, 2, 0, 1, 0, 116221, 0, 0, 1, 0, 0, '', 'Areatrigger 7748 only triggers when player has not aura 116221'),
(22, 1, 7748, 2, 0, 47, 0, 29410, 2, 0, 0, 0, 0, '', 'Areatrigger 7748 only triggers when player has completed quest 29410');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=2 AND `SourceEntry`=7748;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 2, 7748, 2, 1, 1, 0, 116219, 0, 0, 1, 0, 0, '', 'Areatrigger 7748 only triggers when player has not aura 116219'),
(22, 2, 7748, 2, 1, 47, 0, 29419, 2, 0, 0, 0, 0, '', 'Areatrigger 7748 only triggers when player has completed quest 29419'),
(22, 2, 7748, 2, 1, 47, 0, 29424, 2, 0, 0, 0, 0, '', 'Areatrigger 7748 only triggers when player has completed quest 29424');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (7756, 7645);
INSERT INTO `areatrigger_scripts` VALUES
(7756, 'at_cave_of_meditation'),
(7645, 'at_inside_of_cave_of_meditation');

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id`=116421 AND `ScriptName`='spell_meditation_timer_bar';
INSERT INTO `spell_script_names` VALUES
(116421, 'spell_meditation_timer_bar');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=114728;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 114728, 0, 0, 51, 0, 5, 54567, 0, 0, 0, 0, '', 'Spell Summon Aysa can only hit Aysa Cloudsinger');

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 5848 AND `PhaseId` = 838;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5848, 838, 'See Cave of Scrolls Attack');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=838 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 838, 0, 0, 0, 9, 0, 29414, 0, 0, 0, 0, 0, '', 'Apply Phase 838 if Quest 29414 is taken');

-- Waypoint
SET @ENTRY := 59652;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Aysa Cloudsinger - The Way of the Tushui Path (Run)');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1176.191, 3444.874, 103.3529, NULL, 0),
(@PATH, 1, 1149.949, 3437.170, 104.9670, NULL, 0);

SET @ENTRY := 54856;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Master Li Fen - The Way of the Tushui Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1126.932, 3428.669, 105.8901, NULL, 6464),
(@PATH, 1, 1131.328, 3437.516, 105.4583, NULL, 18697),
(@PATH, 2, 1131.889, 3428.207, 105.5141, NULL, 0),
(@PATH, 3, 1130.528, 3425.503, 105.8864, NULL, 29017),
(@PATH, 4, 1129.774, 3433.302, 105.5313, NULL, 0),
(@PATH, 5, 1130.557, 3436.087, 105.4839, NULL, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`=114698;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(114698, 'spell_summon_amberleaf_troublemaker');

SET @ENTRY := 59637;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 11, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 9, 59642, 0, 50, 0, 0, 0, 0, 'On respawn - Self: Attack Creature Aysa Cloudsinger (59642) in 0 - 50 yards');
