SET @CGUID := 74976;
SET @OGUID := 7087;

DELETE FROM `creature` WHERE (`guid` BETWEEN @CGUID+0 AND @CGUID+23) OR (`id` IN (34929, 34935)) OR (`map` IN (641, 642));
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- Goblin Engineering Crew
(@CGUID+0, 36162, 642, 3, 1, 0, -22.16258, 11.19428, 35.09622, 3.961897, 7200, 0, 0),
(@CGUID+1, 36162, 642, 3, 1, 0, -18.38382, -11.11724, 34.91919, 3.089233, 7200, 0, 0), 

-- Kor'kron Reaver
(@CGUID+2, 36164, 642, 3, 1, 0, 28.44413, 18.95949, 35.95979, 2.234021, 7200, 0, 0),
(@CGUID+3, 36164, 642, 3, 1, 0, 37.40386, -8.937434, 30.1788, 6.265732, 7200, 0, 0),
(@CGUID+4, 36164, 642, 3, 1, 0, 6.56619, 7.988725, 34.4726, 3.07178, 7200, 0, 0),
(@CGUID+5, 36164, 642, 3, 1, 0, 37.47043, 8.731059, 30.17881, 6.003932, 7200, 0, 0),
(@CGUID+6, 36164, 642, 3, 1, 0, 28.40881, -19.30474, 35.98264, 4.153883, 7200, 0, 0),
(@CGUID+7, 36164, 642, 3, 1, 0, 17.52033, -14.02618, 35.07203, 3.07178, 7200, 0, 0),
(@CGUID+8, 36164, 642, 3, 1, 0, 6.645779, -8.052721, 34.47524, 3.07178, 7200, 0, 0),
(@CGUID+9, 36164, 642, 3, 1, 0, 16.94911, 14.93277, 35.08105, 3.071779, 7200, 0, 0),
(@CGUID+10, 36164, 642, 3, 1, 0, -31.12894, -19.48676, 34.24918, 4.153883, 7200, 0, 0),
(@CGUID+11, 36164, 642, 3, 1, 0, -30.18002, 17.94827, 34.34239, 2.234021, 7200, 0, 0),

-- 7th Legion Marine
(@CGUID+12, 36166, 641, 3, 1, 0, -53.55445, 2.977596, 23.44318, 0.3316126, 7200, 0, 0),
(@CGUID+13, 36166, 641, 3, 1, 0, 17.0807, -7.109451, 20.5052, 3.124139, 7200, 0, 0),
(@CGUID+14, 36166, 641, 3, 1, 0, 49.93306, -7.458596, 40.16777, 3.979351, 7200, 0, 0),
(@CGUID+15, 36166, 641, 3, 1, 0, 50.20697, 8.003532, 40.16655, 2.530727, 7200, 0, 0),
(@CGUID+16, 36166, 641, 3, 1, 0, 39.78789, -38.58735, 25.11459, 3.979351, 7200, 0, 0),
(@CGUID+17, 36166, 641, 3, 1, 0, -17.57936, 4.24393, 20.84544, 3.12414, 7200, 0, 0),
(@CGUID+18, 36166, 641, 3, 1, 0, 16.84876, 6.618541, 20.51171, 3.12414, 7200, 0, 0),
(@CGUID+19, 36166, 641, 3, 1, 0, -61.94096, 0.089971, 23.56898, 3.124139, 7200, 0, 0),
(@CGUID+20, 36166, 641, 3, 1, 0, -17.59357, -4.383727, 20.84574, 3.12414, 7200, 0, 0),
(@CGUID+21, 36166, 641, 3, 1, 0, -53.6908, -3.682069, 23.44308, 6.056293, 7200, 0, 0),

-- 7th Legion Deckhand
(@CGUID+22, 36165, 641, 3, 1, 0, -35.88269, 3.162697, 20.53507, 1.658063, 7200, 0, 0),
(@CGUID+23, 36165, 641, 3, 1, 0, -36.38501, -7.325379, 20.44885, 1.653776, 7200, 0, 0),

-- Horde Gunship Cannon
(@CGUID+24, 34935, 642, 3, 1, 0, -21.40090, -31.34303, 34.25633, 4.677482, 7200, 0, 0),
(@CGUID+25, 34935, 642, 3, 1, 0, -12.10641, -31.96964, 34.46390, 4.625123, 7200, 0, 0),
(@CGUID+26, 34935, 642, 3, 1, 0, -2.487608, -31.98854, 34.92170, 4.834562, 7200, 0, 0),
(@CGUID+27, 34935, 642, 3, 1, 0, 19.463670, -30.79399, 36.30841, 4.852015, 7200, 0, 0),
(@CGUID+28, 34935, 642, 3, 1, 0, 10.266400, -32.07130, 35.81895, 4.852015, 7200, 0, 0),

-- Alliance Gunship Cannon
(@CGUID+29, 34929, 641, 3, 1, 0, -12.47339, 25.72650, 21.67813, 1.742887, 7200, 0, 0),
(@CGUID+30, 34929, 641, 3, 1, 0, -41.71228, 22.90814, 22.60103, 1.902409, 7200, 0, 0),
(@CGUID+31, 34929, 641, 3, 1, 0, -2.811304, 25.78116, 21.69148, 1.658063, 7200, 0, 0),
(@CGUID+32, 34929, 641, 3, 1, 0, -21.44925, 25.39890, 21.66956, 1.658063, 7200, 0, 0),
(@CGUID+33, 34929, 641, 3, 1, 0, -31.03540, 24.86197, 21.70274, 1.658063, 7200, 0, 0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 195705, 641, 3, 1, 16.48109, -0.00539, 20.41618, 3.036838, 0, 0, 0, 1, 7200, 255, 0),
(@OGUID+1, 195371, 641, 3, 1, 16.47634, 0.018369, 20.41617, 3.036838, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+2, 195706, 642, 3, 1, 12.28939, 0.081029, 34.6497, 3.159062, 0, 0, 0, 1, 7200, 255, 0),
(@OGUID+3, 196413, 642, 3, 1, 12.31993, 0.096332, 34.65082, 3.159062, 0, 0, 0, 1, 7200, 255, 1);

-- Template Updates
-- Teleporter
UPDATE `gameobject_template` SET `flags`=48 WHERE `entry` IN (195313, 195314);

-- Horde Gunship Cannon
UPDATE `creature_template` SET `difficulty_entry_1`=35427 WHERE `entry`=34935;
UPDATE `creature_template` SET `spell1`=66529, `unit_flags`=33570816 WHERE `entry`=35427;

-- Alliance Gunship Cannon
UPDATE `creature_template` SET `spell1`=66518, `unit_flags`=33570816 WHERE `entry`=35410;

-- Goblin Engineering Crew
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction`=1978 WHERE `entry`=36162;

-- 7th Legion Deckhand
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction`=1973 WHERE `entry`=36165;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (36162, 36165);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36162, 0, 0, 0x0, 0x101, 0, ''),
(36165, 0, 0, 0x0, 0x101, 0, '');

-- Spell Target Positions
DELETE FROM `spell_target_position` WHERE `id`=66899;
INSERT INTO `spell_target_position` VALUES
(66899,0, 628, 747, -1075, 135, 0, 18414);

-- Spell linked spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66899;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(66899, -66656, 0, 'On cast 66899 (Gunship Portal Click (to Hangar)) - Remove 66656 (Parachute)');

-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND (`SourceEntry`=66637 OR `SourceEntry`=66630) AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=34984 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 66630, 31, 3, 34984),
(13, 1, 66637, 31, 3, 34984);

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (35003, 34960);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(35003, 0, 0, 'All aboard the gunship! Man the guns!', 14, 0, 100, 0, 0, 0, 35241, 'Horde Gunship Captain'),
(34960, 0, 0, 'All aboard the gunship! Man the guns!', 14, 0, 100, 0, 0, 0, 35228, 'Alliance Gunship Captain');

-- Scripts
UPDATE `creature_template` SET `ScriptName`='npc_ioc_gunship_captain' WHERE `entry` IN (35003, 34960);
