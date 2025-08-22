SET @CGUID := 5000557;
SET @SPAWNGROUP := 1264;

UPDATE `creature` SET `StringId`='npc_auchenai_defender_intro' WHERE `guid`= 5000442; -- Auchenai Defender

UPDATE `creature_template` SET `ScriptName` = 'npc_auchindoun_soulbinder_tuulani' WHERE `entry`=79248; -- Soulbinder Tuulani
UPDATE `creature_template` SET `ScriptName` = 'npc_auchindoun_auchenai_defender' WHERE `entry`=77693; -- Auchenai Defender

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (77693, 79248);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(77693, 0, 0, 'Nyami awaits you in the western ritual chamber, champions.', 12, 0, 100, 0, 0, 0, 83111, 0, 'Auchenai Defender to Player'),
(79248, 0, 0, 'Good! We must have arrived before Teron\'gor and Gul\'dan!', 12, 0, 100, 3, 0, 44644, 81528, 0, 'Soulbinder Tuulani to Player'),
(79248, 1, 0, 'Nyami is working to bolster the defenses against their assault - follow me, we will report to her.', 12, 0, 100, 1, 0, 44654, 81529, 0, 'Soulbinder Tuulani to Player'),
(79248, 2, 0, 'Beautiful, isn\'t it? Just think - you\'re one of the first outsiders to see inside Auchindoun.', 12, 0, 100, 6, 0, 44655, 81530, 0, 'Soulbinder Tuulani to Player'),
(79248, 3, 0, 'Strange... why is the door sealed? No matter...', 12, 0, 100, 6, 0, 44656, 81531, 0, 'Soulbinder Tuulani to Player'),
(79248, 4, 0, 'Let us proceed.', 12, 0, 100, 25, 0, 44657, 81532, 0, 'Soulbinder Tuulani'),
(79248, 5, 0, 'The Vindicators and Exarchs of the past. Heroes all - their souls still remain with us here.', 12, 0, 100, 25, 0, 44658, 81533, 0, 'Soulbinder Tuulani');

-- Waypoints
SET @ENTRY := 79248;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Soulbinder Tuulani path to holy barrier');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1581.05, 2953.418, 35.2387, NULL, 0),
(@PATH, 1, 1599.741, 2952.971, 35.23116, NULL, 0),
(@PATH, 2, 1617.514, 2953.21, 35.22284, NULL, 6486),
(@PATH, 3, 1649.21, 2953.6, 34.80952, NULL, 0),
(@PATH, 4, 1654.767, 2960.552, 34.27824, NULL, 0),
(@PATH, 5, 1658.876, 2968.664, 35.31583, NULL, 0),
(@PATH, 6, 1660.462, 2981.102, 34.7626, NULL, 0),
(@PATH, 7, 1663.101, 2997.4, 34.76278, NULL, 0),
(@PATH, 8, 1664.323, 3002.953, 34.89674, NULL, 0);

SET @ENTRY := 79248;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Soulbinder Tuulani path to first boss');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1666.299, 3032.361, 35.15017, NULL, 0),
(@PATH, 1, 1677.693, 3045.896, 35.1377, NULL, 0),
(@PATH, 2, 1681.016, 3064.814, 35.13763, NULL, 0),
(@PATH, 3, 1683.851, 3078.6, 35.13764, NULL, 0),
(@PATH, 4, 1694.418, 3081.378, 35.13764, NULL, 0),
(@PATH, 5, 1697.734, 3086.925, 35.13764, NULL, 7960),
(@PATH, 6, 1718.639, 3116.199, 35.13764, NULL, 0),
(@PATH, 7, 1728.587, 3128.338, 35.13763, NULL, 0),
(@PATH, 8, 1747.014, 3144.337, 35.13762, NULL, 0),
(@PATH, 9, 1775.142, 3162.625, 35.13763, NULL, 0),
(@PATH, 10, 1789.036, 3174.038, 35.13765, NULL, 0),
(@PATH, 11, 1798.358, 3179.212, 35.13763, NULL, 0),
(@PATH, 12, 1806.295, 3182.313, 35.11731, 3.70009, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` = 160415;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 160415, 0, 2, 51, 0, 5, 79417, 0, '', 0, 0, 0, '', 'Spell \'Tuulani Unlock Visual\' can only hit \'Invisible Stalker\'');

-- Spells
UPDATE `spell_target_position` SET `PositionX`=1855.673583984375, `PositionY`=3198.618896484375, `VerifiedBuild`=54988 WHERE (`ID`=178799 AND `EffectIndex`=0); -- Spell: 178799 (Grimrail Depot) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `spell_script_names` WHERE `spell_id` IN (157762, 178800);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(157762, 'spell_auchindoun_halo'),
(178800, 'spell_auchindoun_grimrail_depot_scene_selector');

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (9973, 10072, 9974, 10280);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(9973, 'at_auchindoun_entrance'),
(10072, 'at_auchindoun_auchenai_defender_intro'),
(9974, 'at_auchindoun_barrier'),
(10280, 'at_auchindoun_soulbinder_nyami_scene');

UPDATE `areatrigger_create_properties` SET `ScriptName`= 'at_auchindoun_npc_reaction' WHERE `Id` = 1725;

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=913;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`, `ScriptName`) VALUES
(913, 17, 1365, 0, 'scene_auchindoun_soulbinder_nyami');

-- Phase
DELETE FROM `phase_name` WHERE `ID`=4346;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4346, 'Auchindoun Instance Scene');

DELETE FROM `phase_area` WHERE `AreaId`=6912 AND `PhaseId`=4346;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(6912, 4346, 'Auchindoun Instance See Scene');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=4346;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 4346, 0, 0, 0, 56, 0, 31506, 0, 0, '', 0, 0, 0, '', 'Apply Phase 4346 if PlayerCondition 31506 is satisfied');

-- Spawngroup
DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID, 79248, 1182, 6912, 6912, '1,2,8,23', 0, 0, 0, 1, 1859.0208740234375, 3197.3203125, 29.50753593444824218, 0.019564647227525711, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904); -- Soulbinder Tuulani (Area: Auchindoun - Difficulty: Normal) CreateObject1 (Auras: 154840 - Void Stasis)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '154840'); -- Soulbinder Tuulani - 154840 - Void Stasis -

DELETE FROM `spawn_group` WHERE `groupId`=@SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID);

DELETE FROM `spawn_group_template` WHERE `groupId`=@SPAWNGROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP, 'Auchindoun - Soulbinder Tuulani Imprisoned', 4);

DELETE FROM `instance_template` WHERE `map`=1182;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1182, 0, 'instance_auchindoun');
